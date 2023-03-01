#include <nanogui/common.h>

#if NANOGUI_VULKAN_BACKEND
#if NANOGUI_SDL2_WINDOW

#include <nanogui/screen.h>
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>
#include <map>

#define NANOVG_VULKAN_IMPLEMENTATION
#include <nanogui/nanovg_vk.h>
#include "vulkan_util.h"

// #if defined(_WIN32)
// #  ifndef WIN32_LEAN_AND_MEAN
// #    define WIN32_LEAN_AND_MEAN
// #  endif
// #  include <windows.h>
// #  define GLFW_EXPOSE_NATIVE_WIN32
// #  include <GLFW/glfw3native.h>
// #endif

NAMESPACE_BEGIN(nanogui)

static Screen* screen;

namespace internal
{
  VkInstance instance;
  VkSurfaceKHR surface;
  VulkanDevice *device;
  FrameBuffers fb;
  VkDebugReportCallbackEXT debug_callback;
  VkQueue queue;
  VkCommandBuffer cmd_buffer;
}

//TODO: use unsigned char
bool isMouseButtonLeft(int button) { return button == SDL_BUTTON_LEFT; }
bool isMouseButtonLeftMod(int button) { return button == SDL_BUTTON_MIDDLE; }
bool isMouseButtonRight(int button) { return button == SDL_BUTTON_RIGHT; }
bool isMouseActionRelease(int action) { return action == SDL_RELEASED; }
bool isMouseActionPress(int action) { return action == SDL_PRESSED; }

#if defined(__APPLE__)
  extern void disable_saved_application_state_osx();
#endif

void init() {
#if !defined(_WIN32)
  /* Avoid locale-related number parsing issues */
  setlocale(LC_NUMERIC, "C");
#endif

#if defined(__APPLE__)
  disable_saved_application_state_osx();
#endif

  // glfwSetErrorCallback(
  //   [](int error, const char *descr) {
  //     if (error == GLFW_NOT_INITIALIZED)
  //       return; /* Ignore */
  //     std::cerr << "GLFW error " << error << ": " << descr << std::endl;
  //   }
  // );

  if(SDL_Init(SDL_INIT_VIDEO))
  {
    throw std::runtime_error("Could not initialize SDL2!");
  }
}

void shutdown() { SDL_Quit(); }
float getTimeFromStart() { return SDL_GetTicks() / 1000.f; }

bool sample::post_empty_event()
{
  SDL_Event event = {};
  event.type = SDL_USEREVENT;
  SDL_PushEvent(&event);
  return true;
}

/**
 * Process common desktop events
 * NOTE: will need a screen handle
 */
bool process_event(SDL_Event& currentEvent)
{
  switch(currentEvent.type)
  {
    case SDL_KEYDOWN:
    case SDL_KEYUP:
      if (screen && screen->canProcessEvents())
        screen->keyCallbackEvent(
          currentEvent.key.keysym.sym,
          currentEvent.key.keysym.scancode,
          currentEvent.key.state,
          SDL_GetModState()
        );
      break;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
      if (screen && screen->canProcessEvents())
        screen->mouseButtonCallbackEvent(
          currentEvent.button.button,
          currentEvent.button.state,
          SDL_GetModState()
        );
      break;
    case SDL_MOUSEWHEEL:
      if (screen && screen->canProcessEvents())
        screen->scrollCallbackEvent(
          currentEvent.wheel.x,
          currentEvent.wheel.y
        );
      break;
    case SDL_MOUSEMOTION:
      if(screen && screen->canProcessEvents())
        screen->cursorPosCallbackEvent(
          currentEvent.motion.x,
          currentEvent.motion.y
        );
      break;
    case SDL_DISPLAYEVENT:
      switch(currentEvent.display.event) {
        case SDL_DISPLAYEVENT_CONNECTED:
          break;
        case SDL_DISPLAYEVENT_DISCONNECTED:
          break;
        case SDL_DISPLAYEVENT_ORIENTATION:
          break;
      }
      break;
    case SDL_WINDOWEVENT:
      switch(currentEvent.window.event) {
        case SDL_WINDOWEVENT_SHOWN:
          break;
        case SDL_WINDOWEVENT_HIDDEN:
          break;
        case SDL_WINDOWEVENT_EXPOSED:
          break;
        case SDL_WINDOWEVENT_MOVED:
          break;
        case SDL_WINDOWEVENT_RESIZED:
          screen->resizeCallbackEvent(
            currentEvent.window.data1,
            currentEvent.window.data2
          );
          break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
          break;
        case SDL_WINDOWEVENT_MINIMIZED:
          break;
        case SDL_WINDOWEVENT_MAXIMIZED:
          break;
        case SDL_WINDOWEVENT_RESTORED:
          break;
        case SDL_WINDOWEVENT_ENTER:
          break;
        case SDL_WINDOWEVENT_LEAVE:
          break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
          if (screen)
            std::cout << "focused" << std::endl;
            screen->focusEvent(true);
          break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
          if (screen)
            std::cout << "unfocused" << std::endl;
            screen->focusEvent(false);
          break;
        case SDL_WINDOWEVENT_CLOSE:
          break;
        case SDL_WINDOWEVENT_TAKE_FOCUS:
          break;
      }
      break;
    case SDL_QUIT:
      sample::stop_frame_loop();
      return true;
  }
  return false;
}

bool sample::wait_events()
{
  SDL_Event currentEvent;
  while (SDL_WaitEventTimeout(&currentEvent, 1))
  {
    if(process_event(currentEvent))
    {
      break;
    }
  }
  return true;
}

bool sample::poll_events()
{
  SDL_Event currentEvent;
  while (SDL_PollEvent(&currentEvent))
  {
    process_event(currentEvent);
  }
  return true;
}

bool isKeyboardActionRelease(int action) { return action == SDL_RELEASED; }
bool isKeyboardModifierCtrl(int modifier) { return modifier & KMOD_CTRL; }
bool isKeyboardModifierShift(int modifier) { return modifier & KMOD_SHIFT; }
bool isKeyboardActionPress(int action) { return action == SDL_PRESSED; }
bool isKeyboardActionRepeat(int action) { return false; } // TODO: use event.key.repeat
bool isKeyboardKeyEscape(int key) { return key == SDLK_ESCAPE; }

uint32_t key2fourcc(int key)
{
  switch (key) {
#define RET_KEYCODE(k,c) case k: return FOURCC(c);
  RET_KEYCODE(SDLK_DELETE, "KDEL")
  RET_KEYCODE(SDLK_a, "KEYA")
  RET_KEYCODE(SDLK_x, "KEYX")
  RET_KEYCODE(SDLK_n, "KEYN")
  RET_KEYCODE(SDLK_b, "KEYB")
  RET_KEYCODE(SDLK_c, "KEYC")
  RET_KEYCODE(SDLK_r, "KEYR")
  RET_KEYCODE(SDLK_p, "KEYP")
  RET_KEYCODE(SDLK_v, "KEYV")
  RET_KEYCODE(SDLK_z, "KEYZ")
  RET_KEYCODE(SDLK_LEFT, "LEFT")
  RET_KEYCODE(SDLK_RIGHT, "RGHT")
  RET_KEYCODE(SDLK_DOWN, "DOWN")
  RET_KEYCODE(SDLK_UP, "KBUP")
  RET_KEYCODE(SDLK_HOME, "HOME")
  RET_KEYCODE(SDLK_END, "KEND")
  RET_KEYCODE(SDLK_BACKSPACE, "BACK")
  RET_KEYCODE(SDLK_RETURN, "ENTR")
  RET_KEYCODE(SDLK_SPACE, "SPCE")
  RET_KEYCODE(SDLK_ESCAPE, "ESCP")
#undef RET_KEYCODE
  default: return FOURCC("UNKN");
  }
}

void sample::clear_frame(const Color& background)
{
  VkResult res;

  // Get the index of the next available swapchain image:
  res = vkAcquireNextImageKHR(internal::device->device, internal::fb.swap_chain, UINT64_MAX,
    internal::fb.present_complete_semaphore,
    0,
    &internal::fb.current_buffer);
  assert(res == VK_SUCCESS);

  const VkCommandBufferBeginInfo cmd_buf_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
  res = vkBeginCommandBuffer(internal::cmd_buffer, &cmd_buf_info);
  assert(res == VK_SUCCESS);

  VkClearValue clear_values[2];
  clear_values[0].color.float32[0] = background.r();
  clear_values[0].color.float32[1] = background.g();
  clear_values[0].color.float32[2] = background.b();
  clear_values[0].color.float32[3] = background.a();
  clear_values[1].depthStencil.depth = 1.0f;
  clear_values[1].depthStencil.stencil = 0;

  VkRenderPassBeginInfo rp_begin;
  rp_begin.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
  rp_begin.pNext = NULL;
  rp_begin.renderPass = internal::fb.render_pass;
  rp_begin.framebuffer = internal::fb.framebuffers[internal::fb.current_buffer];
  rp_begin.renderArea.offset.x = 0;
  rp_begin.renderArea.offset.y = 0;
  rp_begin.renderArea.extent.width = internal::fb.buffer_size.width;
  rp_begin.renderArea.extent.height = internal::fb.buffer_size.height;
  rp_begin.clearValueCount = 2;
  rp_begin.pClearValues = clear_values;

  vkCmdBeginRenderPass(internal::cmd_buffer, &rp_begin, VK_SUBPASS_CONTENTS_INLINE);

  VkViewport viewport;
  viewport.width = internal::fb.buffer_size.width;
  viewport.height = internal::fb.buffer_size.height;
  viewport.minDepth = (float)0.0f;
  viewport.maxDepth = (float)1.0f;
  viewport.x = rp_begin.renderArea.offset.x;
  viewport.y = rp_begin.renderArea.offset.y;
  vkCmdSetViewport(internal::cmd_buffer, 0, 1, &viewport);

  VkRect2D scissor = rp_begin.renderArea;
  vkCmdSetScissor(internal::cmd_buffer, 0, 1, &scissor);
}

void sample::present_frame(void* window) 
{
  VkResult res;

  vkCmdEndRenderPass(internal::cmd_buffer);

  vkEndCommandBuffer(internal::cmd_buffer);

  VkPipelineStageFlags pipe_stage_flags = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;

  VkSubmitInfo submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
  submit_info.pNext = NULL;
  submit_info.waitSemaphoreCount = 1;
  submit_info.pWaitSemaphores = &internal::fb.present_complete_semaphore;
  submit_info.pWaitDstStageMask = &pipe_stage_flags;
  submit_info.commandBufferCount = 1;
  submit_info.pCommandBuffers = &internal::cmd_buffer;
  submit_info.signalSemaphoreCount = 1;
  submit_info.pSignalSemaphores = &internal::fb.render_complete_semaphore;

  /* Queue the command buffer for execution */
  res = vkQueueSubmit(internal::queue, 1, &submit_info, 0);
  assert(res == VK_SUCCESS);

  /* Now present the image in the window */

  VkPresentInfoKHR present = { VK_STRUCTURE_TYPE_PRESENT_INFO_KHR };
  present.pNext = NULL;
  present.swapchainCount = 1;
  present.pSwapchains = &internal::fb.swap_chain;
  present.pImageIndices = &internal::fb.current_buffer;
  present.waitSemaphoreCount = 1;
  present.pWaitSemaphores = &internal::fb.render_complete_semaphore;

  res = vkQueuePresentKHR(internal::queue, &present);
  assert(res == VK_SUCCESS);

  res = vkQueueWaitIdle(internal::queue);
}

static float get_pixel_ratio(SDL_Window *window)
{
// #if defined(_WIN32)
//   HWND hWnd = glfwGetWin32Window(window);
//   HMONITOR monitor = nullptr;
// #if defined(MONITOR_DEFAULTTONEAREST)
//   monitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
// #else
//   static HMONITOR(WINAPI *MonitorFromWindow_)(HWND, DWORD) = nullptr;
//   static bool MonitorFromWindow_tried = false;
//   if (!MonitorFromWindow_tried) {
//     auto user32 = LoadLibrary(TEXT("user32"));
//     if (user32)
//       MonitorFromWindow_ = (decltype(MonitorFromWindow_))GetProcAddress(user32, "MonitorFromWindow");
//     MonitorFromWindow_tried = true;
//   }
//   if (MonitorFromWindow_)
//     monitor = MonitorFromWindow_(hWnd, 2);
// #endif  // defined(MONITOR_DEFAULTTONEAREST)
//   /* The following function only exists on Windows 8.1+, but we don't want to make that a dependency */
//   static HRESULT(WINAPI *GetDpiForMonitor_)(HMONITOR, UINT, UINT*, UINT*) = nullptr;
//   static bool GetDpiForMonitor_tried = false;

//   if (!GetDpiForMonitor_tried) {
//     auto shcore = LoadLibrary(TEXT("shcore"));
//     if (shcore)
//       GetDpiForMonitor_ = (decltype(GetDpiForMonitor_))GetProcAddress(shcore, "GetDpiForMonitor");
//     GetDpiForMonitor_tried = true;
//   }

//   if (GetDpiForMonitor_ && monitor) {
//     uint32_t dpiX, dpiY;
//     if (GetDpiForMonitor_(monitor, 0 /* effective DPI */, &dpiX, &dpiY) == S_OK)
//       return dpiX / 96.0;
//   }
//   return 1.f;
// #elif defined(__linux__)
//   (void)window;

//   float ratio = 1.0f;
//   FILE *fp;
//   /* Try to read the pixel ratio from KDEs config */
//   auto currentDesktop = std::getenv("XDG_CURRENT_DESKTOP");
//   if (currentDesktop && currentDesktop == std::string("KDE")) {
//     fp = popen("kreadconfig5 --group KScreen --key ScaleFactor", "r");
//     if (!fp)
//       return 1;

//     if (fscanf(fp, "%f", &ratio) != 1)
//       return 1;
//   }
//   else {
//     /* Try to read the pixel ratio from GTK */
//     fp = popen("gsettings get org.gnome.desktop.interface scaling-factor", "r");
//     if (!fp)
//       return 1;

//     int ratioInt = 1;
//     if (fscanf(fp, "uint32 %i", &ratioInt) != 1)
//       return 1;
//     ratio = ratioInt;
//   }
//   if (pclose(fp) != 0)
//     return 1;
//   return ratio >= 1 ? ratio : 1;

// #else
//   Vector2i fbSize, size;
//   glfwGetFramebufferSize(window, &fbSize[0], &fbSize[1]);
//   glfwGetWindowSize(window, &size[0], &size[1]);
//   return (float)fbSize[0] / (float)size[0];
// #endif
  return 1.0;
}

void sample::setup_window_params(WindowHandle hw_window, Screen* s)
{
  /* Propagate GLFW events to the appropriate Screen instance */
  screen = s;
  // glfwSetCursorPosCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, double x, double y) {
  //   if (!screen || !screen->canProcessEvents())
  //     return;
  //   screen->cursorPosCallbackEvent(x, y);
  // });

  // glfwSetMouseButtonCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, int button, int action, int modifiers) {
  //   if (!screen || !screen->canProcessEvents())
  //     return;
  //   screen->mouseButtonCallbackEvent(button, action, modifiers);
  // });

  // glfwSetKeyCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, int key, int scancode, int action, int mods) {
  //   if (!screen || !screen->canProcessEvents())
  //     return;
  //   screen->keyCallbackEvent(key, scancode, action, mods);
  // });

  // glfwSetCharCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, unsigned int codepoint) {
  //   if (!screen || !screen->canProcessEvents())
  //     return;
  //   screen->charCallbackEvent(codepoint);
  // });

  // glfwSetDropCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, int count, const char **filenames) {
  //   if (!screen || !screen->canProcessEvents())
  //     return;
  //   screen->dropCallbackEvent(count, filenames);
  // });

  // glfwSetScrollCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, double x, double y) {
  //   if (!screen || !screen->canProcessEvents())
  //     return;
  //   screen->scrollCallbackEvent(x, y);
  // });

  // /* React to framebuffer size events -- includes window
  // size events and also catches things like dragging
  // a window from a Retina-capable screen to a normal
  // screen on Mac OS X */
  // glfwSetFramebufferSizeCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, int width, int height) {
  //   if (!screen || !screen->canProcessEvents())
  //     return;
  //   screen->resizeCallbackEvent(width, height);
  // });

  // // notify when the screen has lost focus (e.g. application switch)
  // glfwSetWindowFocusCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow *, int focused) {
  //   // focused: 0 when false, 1 when true
  //   if (!screen)
  //     screen->focusEvent(focused != 0);
  // });

  // glfwSetWindowCloseCallback((GLFWwindow*)hw_window,
  //   [](GLFWwindow*) {
  //     sample::stop_frame_loop();
  // });


  // screen->initClipboardSetHandler([hw_window](std::string text) {
  //   glfwSetClipboardString((GLFWwindow*)hw_window, text.c_str());
  // });
  // screen->initClipboardGetHandler([hw_window]() {
  //   return glfwGetClipboardString((GLFWwindow*)hw_window);
  // });

  //FIXME: make this handlers properly

  screen->setPrepareFrameHandler([hw_window](Screen* screen) {
   // Vector2i fbsize, size;
   // glfwGetFramebufferSize((GLFWwindow*)hw_window, &fbsize.x(), &fbsize.y());
   // glfwGetWindowSize((GLFWwindow*)hw_window, &size.x(), &size.y());
   // if (size.x() != screen->width() || size.y() != screen->height())
   // {
   //   destroyFrameBuffers(internal::device, &internal::fb);
   //   internal::fb = createFrameBuffers(internal::device, internal::surface, internal::queue, size.x(), size.y(), 0);
   //   screen->setSizeFBSize(size, fbsize);
   // }
  });

  screen->setResizeHwHandler([hw_window](Screen*, Vector2i& size, Vector2i& fbsize) {
    SDL_Vulkan_GetDrawableSize((SDL_Window*)hw_window, &fbsize.x(), &fbsize.y());
    SDL_GetWindowSize((SDL_Window*)hw_window, &size.x(), &size.y());
    if (size.x() != screen->width() || size.y() != screen->height())
    {
        destroyFrameBuffers(internal::device, &internal::fb);
        internal::fb = createFrameBuffers(internal::device, internal::surface, internal::queue, size.x(), size.y(), 0);
        screen->setSizeFBSize(size, fbsize);
    }
  });

  screen->initHwCursorSetter([hw_window](intptr_t cursor) {
    SDL_SetCursor((SDL_Cursor*)cursor);
  });
  screen->setPixelRatio(get_pixel_ratio((SDL_Window*)hw_window));
}

void errorcb(int error, const char *desc) { printf("GLFW error %d: %s\n", error, desc); }

void sample::set_window_topmost(WindowHandle w, bool top, bool always)
{
#ifdef _WIN32
  HWND realw = glfwGetWin32Window((GLFWwindow*)w);
  
  ShowWindow(realw, TRUE);
  SetForegroundWindow(realw);
  RECT rect;

  // get the current window size and position
  GetWindowRect(realw, &rect);

  // now change the size, position, and Z order
  // of the window.
  ::SetWindowPos(realw,       // handle to window
    (top && always) ? HWND_TOPMOST : (top ? HWND_TOP : HWND_BOTTOM),  // placement-order handle
    rect.left,     // horizontal position
    rect.top,      // vertical position
    rect.right - rect.left,  // width
    rect.bottom - rect.top, // height
    SWP_SHOWWINDOW);
#else

#endif
}

Vector2i sample::get_window_pos(WindowHandle w) 
{
  Vector2i pos;
  SDL_GetWindowPosition((SDL_Window*)w, &pos.x(), &pos.y());
  return pos;
}

Vector2i sample::get_cursor_pos()
{
  Vector2i pos;
  SDL_GetMouseState(&pos.x(), &pos.y());
  return pos;
}

void sample::set_window_pos(WindowHandle w, const Vector2i& pos)
{
  SDL_SetWindowPosition((SDL_Window*)w, pos.x(), pos.y());
}

sample::WindowHandle sample::create_window(int& w, int& h, const std::string& caption, bool resizable, bool fullscreen, bool header)
{
  WindowHandle hw_window = nullptr;
  //glfwSetErrorCallback(errorcb);
  //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  if (fullscreen) {
    SDL_DisplayMode mode;
    if(SDL_FALSE == SDL_GetCurrentDisplayMode(0, &mode)) {
      throw std::runtime_error("SDL_GetCurrentDisplayMode");
    }
    hw_window = SDL_CreateWindow(
      (caption + "(Vulkan)").c_str(),
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      mode.w, mode.h,
      SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN | SDL_WINDOW_FULLSCREEN
    );
  }
  else {
    hw_window = SDL_CreateWindow(
      (caption + "(Vulkan)").c_str(),
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      w, h,
      SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN
    );
    if(hw_window == nullptr)
    {
      throw std::runtime_error("SDL_CreateWindow");
    }
  }
  std::cout << "Created Window!" << std::endl;

  if (!header)
  {
#if _WIN32
    auto handle = glfwGetWin32Window((GLFWwindow*)hw_window);
    long Style = GetWindowLong(handle, GWL_STYLE);
    Style &= ~WS_MAXIMIZEBOX; //this makes it still work when WS_MAXIMIZEBOX is actually already toggled off
    Style &= ~WS_CAPTION;
    Style &= ~WS_SYSMENU;
    Style &= ~WS_BORDER;
    Style &= ~WS_SYSMENU;
    Style &= ~WS_THICKFRAME;
    //Style &= ~WS_GROUP;
    SetWindowLong(handle, GWL_STYLE, Style);
#endif
  }

  std::cout << "Creating Instance.." << std::endl;

  uint32_t extensions_count = 0;
  if(SDL_FALSE == SDL_Vulkan_GetInstanceExtensions((SDL_Window*)hw_window, &extensions_count, nullptr))
  {
    throw std::runtime_error("SDL_Vulkan_GetInstanceExtensions count");
  }
  std::vector<const char*> window_extensions;
  window_extensions.resize(extensions_count);
  if(SDL_FALSE == SDL_Vulkan_GetInstanceExtensions((SDL_Window*)hw_window, &extensions_count, window_extensions.data()))
  {
    throw std::runtime_error("SDL_Vulkan_GetInstanceExtensions data");
  }
  for (const char* e : window_extensions)
  {
    std::cout << e << std::endl;
  }

#ifndef NDEBUG
  constexpr bool debug = true;
#else
  constexpr bool debug = false;
#endif
  
  internal::instance = createVkInstance(debug, window_extensions);
  #ifndef NDEBUG
  internal::debug_callback = CreateDebugReport(internal::instance);
  #endif //NDEBUG
  if(SDL_FALSE == SDL_Vulkan_CreateSurface((SDL_Window*)hw_window, internal::instance, &internal::surface))
  {
    throw std::runtime_error("SDL_Vulkan_CreateSurface");
  }

  VkPhysicalDevice gpu;
  uint32_t gpu_count = 1;
  VkResult res = vkEnumeratePhysicalDevices(internal::instance, &gpu_count, &gpu);
  if (res != VK_SUCCESS && res != VK_INCOMPLETE) {
    printf("vkEnumeratePhysicalDevices failed %d \n", res);
    exit(-1);
  }
  internal::device = createVulkanDevice(gpu);

  float pixelRatio = get_pixel_ratio((SDL_Window*)hw_window);
#if defined(_WIN32) || defined(__linux__)
  if (pixelRatio != 1. && !fullscreen)
    SDL_SetWindowSize((SDL_Window*)hw_window, w * pixelRatio, h * pixelRatio);
#endif

  Vector2i size;
  SDL_GetWindowSize((SDL_Window*)hw_window, &size.x(), &size.y());

  vkGetDeviceQueue(internal::device->device, internal::device->graphicsQueueFamilyIndex, 0, &internal::queue);
  internal::fb = createFrameBuffers(internal::device, internal::surface, internal::queue, size.x(), size.y(), 0);
  internal::cmd_buffer = createCmdBuffer(internal::device->device, internal::device->commandPool);

  if (!header)
  {
#if _WIN32
    auto handle = glfwGetWin32Window((GLFWwindow*)hw_window);
    RECT crect; GetClientRect(handle, &crect);

    w = (crect.right - crect.left) / pixelRatio;
    h = (crect.bottom - crect.top) / pixelRatio;
#endif
  }

  return hw_window;
}

void sample::destroy_window(WindowHandle wnd)
{
  if (wnd)
    SDL_DestroyWindow((SDL_Window*)wnd);
}

void __nanogui_destroy_cursor(intptr_t cursor)
{
  SDL_FreeCursor((SDL_Cursor*)cursor);
}
intptr_t __nanogui_create_cursor(int shape)
{
  return (intptr_t)SDL_CreateSystemCursor((SDL_SystemCursor)shape);
}

void sample::frame_loop(std::function<void()> &f) {
  while (is_main_loop_active())
  {
    f();
  };
}

void sample::create_context()
{
  VKNVGCreateInfo create_info = { 0 };
  create_info.device = internal::device->device;
  create_info.gpu = internal::device->gpu;
  create_info.renderpass = internal::fb.render_pass;
  create_info.cmdBuffer = internal::cmd_buffer;
  create_info.graphicsQueue = internal::queue;
  create_info.cmdPool = internal::device->commandPool;

  int flags = 0;
#if !defined(NDEBUG)
  flags |= NVG_DEBUG;
#endif

  __nanogui_context = nvgCreateVk(create_info, NVG_ANTIALIAS | NVG_STENCIL_STROKES);
  if (__nanogui_context == nullptr)
    throw std::runtime_error("Could not initialize NanoVG!");
}

void destroy_context()
{
  if (__nanogui_context)
  {
    nvgDeleteVk(__nanogui_context);

    destroyFrameBuffers(internal::device, &internal::fb);
    destroyVulkanDevice(internal::device);

#ifndef NDEBUG
    _vkDestroyDebugReportCallbackEXT(internal::instance, internal::debug_callback, 0);
#endif
    vkDestroyInstance(internal::instance, NULL);
  }
}

NAMESPACE_END(nanogui)

#endif //NANOGUI_SDL2_WINDOW
#endif //NANOGUI_VULKAN_BACKEND