/*
     NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
     The widget drawing code is based on the NanoVG demo application
     by Mikko Mononen.

     All rights reserved. Use of this source code is governed by a
     BSD-style license that can be found in the LICENSE.txt file.
 */

/* Developer note: need to make a change to this file?
 * Please raise an Issue on GitHub describing what needs to change.  This file
 * was generated, so the scripts that generated it needs to update as well.
 */

/**
 * \file nanogui/entypo.h
 *
 * \brief This is a list of icon codes for the ``entypo.ttf`` font by Daniel Bruce.
 *
 * \rst
 *
 * This file defines the full listing of `Entypo <http://www.entypo.com/>`_
 * icons available in NanoGUI.  Please note that if viewing the documentation
 * on the web, your browser may display the icons differently than what they
 * look like in NanoGUI.  Run the one of the :ref:`nanogui_example_icons`
 * executables to see what they all look like in NanoGUI.
 *
 * .. note::
 *
 *    Constants you may have used in the past may no longer exist, e.g.
 *    the name may have changed slightly.  For example, ``ENTYPO_ICON_CIRCLED_HELP``
 *    is renamed to ``ENTYPO_ICON_HELP_WITH_CIRCLE``.
 *
 * .. warning::
 *
 *    Some icons have a "small" variant, e.g. ``ENTYPO_ICON_CHEVRON_SMALL_LEFT``
 *    is smaller than ``ENTYPO_ICON_CHEVRON_LEFT``.  While these "small" icons
 *    can be used, they may not be positioned correctly.  If you experience this
 *    you can, instead of using the "small" variant, use the "regular" icon and
 *    call the :func:`nanogui::Widget::setIconExtraScale` function with a value
 *    of **less than** ``1.0`` to scale the icon size down.
 *
 * .. tip::
 *
 *    In C++, ``#include <nanogui/entypo.h>`` to gain access to the ``#define``
 *    shown in these docs.  In Python, ``from nanogui import entypo``.  So in the
 *    below table, when you see ``ENTYPO_ICON_FLOW_TREE`` that is for C++, and
 *    when you see ``ICON_FLOW_TREE``, that is for Python, and you would access
 *    it using ``entypo.ICON_FLOW_TREE``.
 *
 */

#pragma once
#include <stdint.h>

/*
//converter from fontdrop.info
#include <iostream>
#include <cctype>
#include <algorithm>
#include <regex>

using namespace std;

int codes[] = { };
const char* names[] = { };

int main()
{
  int size = sizeof(codes) / 4;
  for (int i = 0; i <size; i++)
  {
    string s = names[i];
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return toupper(c); });

    s = regex_replace(s, regex("-"), "_");
    s = regex_replace(s, regex("-"), "_");
    s = regex_replace(s, regex("-"), "_");
    s = regex_replace(s, regex("-"), "_");
    s = regex_replace(s, regex("-"), "_");

    int len = 30;
    len -= s.size();
    string mspace;

    for (int y = 0; y < len; y++)
      mspace += " ";

    cout << "#define ENTYPO_ICON_" << s << mspace << "  0x0000" << hex << (0xe800 + codes[i] - 259) << endl;
  }

  return 0;
}
*/

namespace entypo
{
    inline constexpr int ICON_LEFT_OPEN                          = 0x2c2;  // ˂ MODIFIER LETTER LEFT ARROWHEAD
    inline constexpr int ICON_RIGHT_OPEN                         = 0x2c3;  // ˃ MODIFIER LETTER RIGHT ARROWHEAD
    inline constexpr int ICON_UP_OPEN                            = 0x2c4;  // ˄ MODIFIER LETTER UP ARROWHEAD
    inline constexpr int ICON_DOWN_OPEN                          = 0x2c5;  // ˅ MODIFIER LETTER DOWN ARROWHEAD
    inline constexpr int ICON_DOWN_OPEN_MINI                     = 0x2ef;  // ˯ MODIFIER LETTER LOW DOWN ARROWHEAD
    inline constexpr int ICON_UP_OPEN_MINI                       = 0x2f0;  // ˰ MODIFIER LETTER LOW UP ARROWHEAD
    inline constexpr int ICON_LEFT_OPEN_MINI                     = 0x2f1;  // ˱ MODIFIER LETTER LOW LEFT ARROWHEAD
    inline constexpr int ICON_RIGHT_OPEN_MINI                    = 0x2f2;  // ˲ MODIFIER LETTER LOW RIGHT ARROWHEAD
    inline constexpr int ICON_INFO                               = 0x2139;  // ℹ INFORMATION SOURCE
    inline constexpr int ICON_LEVEL_UP                           = 0x21b0;  // ↰ UPWARDS ARROW WITH TIP LEFTWARDS
    inline constexpr int ICON_LEVEL_DOWN                         = 0x21b3;  // ↳ DOWNWARDS ARROW WITH TIP RIGHTWARDS
    inline constexpr int ICON_SWITCH                             = 0x21c6;  // ⇆ LEFTWARDS ARROW OVER RIGHTWARDS ARROW
    inline constexpr int ICON_INFINITY                           = 0x221e;  // ∞ INFINITY
    inline constexpr int ICON_PLUS_CIRCLED                       = 0x2295;  // ⊕ CIRCLED PLUS
    inline constexpr int ICON_MINUS_CIRCLED                      = 0x2296;  // ⊖ CIRCLED MINUS
    inline constexpr int ICON_CC_ND                              = 0x229c;  // ⊜ CIRCLED EQUALS
    inline constexpr int ICON_PLUS_SQUARED                       = 0x229e;  // ⊞ SQUARED PLUS
    inline constexpr int ICON_MINUS_SQUARED                      = 0x229f;  // ⊟ SQUARED MINUS
    inline constexpr int ICON_HOME                               = 0x2302;  // ⌂ HOUSE
    inline constexpr int ICON_HOURGLASS                          = 0x231b;  // ⌛ HOURGLASS
    inline constexpr int ICON_KEYBOARD                           = 0x2328;  // ⌨ KEYBOARD
    inline constexpr int ICON_ERASE                              = 0x232b;  // ⌫ ERASE TO THE LEFT
    inline constexpr int ICON_FAST_FORWARD                       = 0x23e9;  // ⏩ BLACK RIGHT-POINTING DOUBLE TRIANGLE
    inline constexpr int ICON_FAST_BACKWARD                      = 0x23ea;  // ⏪ BLACK LEFT-POINTING DOUBLE TRIANGLE
    inline constexpr int ICON_TO_END                             = 0x23ed;  // ⏭ BLACK RIGHT-POINTING DOUBLE TRIANGLE WITH VERTICAL BAR
    inline constexpr int ICON_TO_START                           = 0x23ee;  // ⏮ BLACK LEFT-POINTING DOUBLE TRIANGLE WITH VERTICAL BAR
    inline constexpr int ICON_DOT                                = 0x23f4;  // ⏴ BLACK MEDIUM LEFT-POINTING TRIANGLE
    inline constexpr int ICON_DOT_2                              = 0x23f5;  // ⏵ BLACK MEDIUM RIGHT-POINTING TRIANGLE
    inline constexpr int ICON_DOT_3                              = 0x23f6;  // ⏶ BLACK MEDIUM UP-POINTING TRIANGLE
    inline constexpr int ICON_VOLUME                             = 0x23f7;  // ⏷ BLACK MEDIUM DOWN-POINTING TRIANGLE
    inline constexpr int ICON_PAUSE                              = 0x23f8;  // ⏸ DOUBLE VERTICAL BAR
    inline constexpr int ICON_STOP                               = 0x23f9;  // ⏹ BLACK SQUARE FOR STOP
    inline constexpr int ICON_RECORD                             = 0x23fa;  // ⏺ BLACK CIRCLE FOR RECORD
    inline constexpr int ICON_UP_DIR                             = 0x25b2;  // ▲ BLACK UP-POINTING TRIANGLE
    inline constexpr int ICON_RIGHT_DIR                          = 0x25b6;  // ▶ BLACK RIGHT-POINTING TRIANGLE
    inline constexpr int ICON_DOWN_DIR                           = 0x25bc;  // ▼ BLACK DOWN-POINTING TRIANGLE
    inline constexpr int ICON_LEFT_DIR                           = 0x25c0;  // ◀ BLACK LEFT-POINTING TRIANGLE
    inline constexpr int ICON_ADJUST                             = 0x25d1;  // ◑ CIRCLE WITH RIGHT HALF BLACK
    inline constexpr int ICON_CHART_PIE                          = 0x25f4;  // ◴ WHITE CIRCLE WITH UPPER LEFT QUADRANT
    inline constexpr int ICON_CLOUD                              = 0x2601;  // ☁ CLOUD
    inline constexpr int ICON_STAR                               = 0x2605;  // ★ BLACK STAR
    inline constexpr int ICON_STAR_EMPTY                         = 0x2606;  // ☆ WHITE STAR
    inline constexpr int ICON_CUP                                = 0x2615;  // ☕ HOT BEVERAGE
    inline constexpr int ICON_MENU                               = 0x2630;  // ☰ TRIGRAM FOR HEAVEN
    inline constexpr int ICON_MOON                               = 0x263d;  // ☽ FIRST QUARTER MOON
    inline constexpr int ICON_HEART_EMPTY                        = 0x2661;  // ♡ WHITE HEART SUIT
    inline constexpr int ICON_HEART                              = 0x2665;  // ♥ BLACK HEART SUIT
    inline constexpr int ICON_NOTE                               = 0x266a;  // ♪ EIGHTH NOTE
    inline constexpr int ICON_NOTE_BEAMED                        = 0x266b;  // ♫ BEAMED EIGHTH NOTES
    inline constexpr int ICON_LAYOUT                             = 0x268f;  // ⚏ DIGRAM FOR GREATER YIN
    inline constexpr int ICON_FLAG                               = 0x2691;  // ⚑ BLACK FLAG
    inline constexpr int ICON_TOOLS                              = 0x2692;  // ⚒ HAMMER AND PICK
    inline constexpr int ICON_COG                                = 0x2699;  // ⚙ GEAR
    inline constexpr int ICON_ATTENTION                          = 0x26a0;  // ⚠ WARNING SIGN
    inline constexpr int ICON_FLASH                              = 0x26a1;  // ⚡ HIGH VOLTAGE SIGN
    inline constexpr int ICON_CLOUD_THUNDER                      = 0x26c8;  // ⛈ THUNDER CLOUD AND RAIN
    inline constexpr int ICON_TAPE                               = 0x2707;  // ✇ TAPE DRIVE
    inline constexpr int ICON_FLIGHT                             = 0x2708;  // ✈ AIRPLANE
    inline constexpr int ICON_MAIL                               = 0x2709;  // ✉ ENVELOPE
    inline constexpr int ICON_PENCIL                             = 0x270f;  // ✏ PENCIL
    inline constexpr int ICON_CHECK                              = 0x2713;  // ✓ CHECK MARK
    inline constexpr int ICON_CANCEL_CIRCLED                     = 0x2716;  // ✖ HEAVY MULTIPLICATION X
    inline constexpr int ICON_CANCEL                             = 0x274c;  // ❌ CROSS MARK
    inline constexpr int ICON_CANCEL_SQUARED                     = 0x274e;  // ❎ NEGATIVE SQUARED CROSS MARK
    inline constexpr int ICON_HELP                               = 0x2753;  // ❓ BLACK QUESTION MARK ORNAMENT
    inline constexpr int ICON_HELP_CIRCLED                       = 0x2754;  // ❔ WHITE QUESTION MARK ORNAMENT
    inline constexpr int ICON_QUOTE                              = 0x275e;  // ❞ HEAVY DOUBLE COMMA QUOTATION MARK ORNAMENT
    inline constexpr int ICON_PLUS                               = 0x2795;  // ➕ HEAVY PLUS SIGN
    inline constexpr int ICON_MINUS                              = 0x2796;  // ➖ HEAVY MINUS SIGN
    inline constexpr int ICON_DIRECTION                          = 0x27a2;  // ➢ THREE-D TOP-LIGHTED RIGHTWARDS ARROWHEAD
    inline constexpr int ICON_CCW                                = 0x27f2;  // ⟲ ANTICLOCKWISE GAPPED CIRCLE ARROW
    inline constexpr int ICON_CW                                 = 0x27f3;  // ⟳ CLOCKWISE GAPPED CIRCLE ARROW
    inline constexpr int ICON_LEFT                               = 0x2b05;  // ⬅ LEFTWARDS BLACK ARROW
    inline constexpr int ICON_UP                                 = 0x2b06;  // ⬆ UPWARDS BLACK ARROW
    inline constexpr int ICON_DOWN                               = 0x2b07;  // ⬇ DOWNWARDS BLACK ARROW
    inline constexpr int ICON_LEFT_CIRCLED                       = 0x2b88;  // ⮈ LEFTWARDS BLACK CIRCLED WHITE ARROW
    inline constexpr int ICON_UP_CIRCLED                         = 0x2b89;  // ⮉ UPWARDS BLACK CIRCLED WHITE ARROW
    inline constexpr int ICON_RIGHT_CIRCLED                      = 0x2b8a;  // ⮊ RIGHTWARDS BLACK CIRCLED WHITE ARROW
    inline constexpr int ICON_DOWN_CIRCLED                       = 0x2b8b;  // ⮋ DOWNWARDS BLACK CIRCLED WHITE ARROW
    inline constexpr int ICON_RIGHT                              = 0x2b95;  // ⮕ RIGHTWARDS BLACK ARROW
    inline constexpr int ICON_LEFT_OPEN_BIG                      = 0x2b9c;  // ⮜ BLACK LEFTWARDS EQUILATERAL ARROWHEAD
    inline constexpr int ICON_UP_OPEN_BIG                        = 0x2b9d;  // ⮝ BLACK UPWARDS EQUILATERAL ARROWHEAD
    inline constexpr int ICON_RIGHT_OPEN_BIG                     = 0x2b9e;  // ⮞ BLACK RIGHTWARDS EQUILATERAL ARROWHEAD
    inline constexpr int ICON_DOWN_OPEN_BIG                      = 0x2b9f;  // ⮟ BLACK DOWNWARDS EQUILATERAL ARROWHEAD
    inline constexpr int ICON_REPLY                              = 0x2baa;  // ⮪ BLACK CURVED UPWARDS AND LEFTWARDS ARROW
    inline constexpr int ICON_FORWARD                            = 0x2bab;  // ⮫ BLACK CURVED UPWARDS AND RIGHTWARDS ARROW
    inline constexpr int ICON_USER_ADD                           = 0xe80f;  //  ????
    inline constexpr int ICON_UPLOAD_CLOUD                       = 0xe82f;  //  ????
    inline constexpr int ICON_REPLY_ALL                          = 0xe831;  //  ????
    inline constexpr int ICON_CODE                               = 0xe834;  //  ????
    inline constexpr int ICON_EXPORT                             = 0xe835;  //  ????
    inline constexpr int ICON_RETWEET                            = 0xe839;  //  ????
    inline constexpr int ICON_LIST_ADD                           = 0xe840;  //  ????
    inline constexpr int ICON_ADDRESS                            = 0xe841;  //  ????
    inline constexpr int ICON_MAP                                = 0xe843;  //  ????
    inline constexpr int ICON_DOC                                = 0xe848;  //  ????
    inline constexpr int ICON_DOCS                               = 0xe849;  //  ????
    inline constexpr int ICON_DOC_LANDSCAPE                      = 0xe84a;  //  ????
    inline constexpr int ICON_DOC_TEXT_INV                       = 0xe84c;  //  ????
    inline constexpr int ICON_RSS                                = 0xe853;  //  ????
    inline constexpr int ICON_SHARE                              = 0xe857;  //  ????
    inline constexpr int ICON_SHAREABLE                          = 0xe858;  //  ????
    inline constexpr int ICON_LOGIN                              = 0xe85c;  //  ????
    inline constexpr int ICON_LOGOUT                             = 0xe85d;  //  ????
    inline constexpr int ICON_LAMP                               = 0xe864;  //  ????
    inline constexpr int ICON_PUBLISH                            = 0xe86c;  //  ????
    inline constexpr int ICON_ARROW_COMBO                        = 0xe86e;  //  ????
    inline constexpr int ICON_ARROWS_CCW                         = 0xe88c;  //  ????
    inline constexpr int ICON_PROGRESS_0                         = 0xe89f;  //  ????
    inline constexpr int ICON_PROGRESS_1                         = 0xe8a0;  //  ????
    inline constexpr int ICON_PROGRESS_2                         = 0xe8a1;  //  ????
    inline constexpr int ICON_PROGRESS_3                         = 0xe8a2;  //  ????
    inline constexpr int ICON_LIST                               = 0xe8a5;  //  ????
    inline constexpr int ICON_BACK_IN_TIME                       = 0xe8aa;  //  ????
    inline constexpr int ICON_NETWORK                            = 0xe8ad;  //  ????
    inline constexpr int ICON_INSTALL                            = 0xe8b0;  //  ????
    inline constexpr int ICON_LIFEBUOY                           = 0xe8b9;  //  ????
    inline constexpr int ICON_TRAFFIC_CONE                       = 0xe8df;  //  ????
    inline constexpr int ICON_CC_NC_EU                           = 0xe8e3;  //  ????
    inline constexpr int ICON_CC_NC_JP                           = 0xe8e4;  //  ????
    inline constexpr int ICON_CC_REMIX                           = 0xe8ea;  //  ????
    inline constexpr int ICON_GITHUB                             = 0xf300;  //  ????
    inline constexpr int ICON_GITHUB_CIRCLED                     = 0xf301;  //  ????
    inline constexpr int ICON_FLICKR                             = 0xf303;  //  ????
    inline constexpr int ICON_FLICKR_CIRCLED                     = 0xf304;  //  ????
    inline constexpr int ICON_VIMEO                              = 0xf306;  //  ????
    inline constexpr int ICON_VIMEO_CIRCLED                      = 0xf307;  //  ????
    inline constexpr int ICON_TWITTER                            = 0xf309;  //  ????
    inline constexpr int ICON_TWITTER_CIRCLED                    = 0xf30a;  //  ????
    inline constexpr int ICON_FACEBOOK                           = 0xf30c;  //  ????
    inline constexpr int ICON_FACEBOOK_CIRCLED                   = 0xf30d;  //  ????
    inline constexpr int ICON_FACEBOOK_SQUARED                   = 0xf30e;  //  ????
    inline constexpr int ICON_GPLUS                              = 0xf30f;  //  ????
    inline constexpr int ICON_GPLUS_CIRCLED                      = 0xf310;  //  ????
    inline constexpr int ICON_PINTEREST                          = 0xf312;  //  ????
    inline constexpr int ICON_PINTEREST_CIRCLED                  = 0xf313;  //  ????
    inline constexpr int ICON_TUMBLR                             = 0xf315;  //  ????
    inline constexpr int ICON_TUMBLR_CIRCLED                     = 0xf316;  //  ????
    inline constexpr int ICON_LINKEDIN                           = 0xf318;  //  ????
    inline constexpr int ICON_LINKEDIN_CIRCLED                   = 0xf319;  //  ????
    inline constexpr int ICON_DRIBBBLE                           = 0xf31b;  //  ????
    inline constexpr int ICON_DRIBBBLE_CIRCLED                   = 0xf31c;  //  ????
    inline constexpr int ICON_STUMBLEUPON                        = 0xf31e;  //  ????
    inline constexpr int ICON_STUMBLEUPON_CIRCLED                = 0xf31f;  //  ????
    inline constexpr int ICON_LASTFM                             = 0xf321;  //  ????
    inline constexpr int ICON_LASTFM_CIRCLED                     = 0xf322;  //  ????
    inline constexpr int ICON_RDIO                               = 0xf324;  //  ????
    inline constexpr int ICON_RDIO_CIRCLED                       = 0xf325;  //  ????
    inline constexpr int ICON_SPOTIFY                            = 0xf327;  //  ????
    inline constexpr int ICON_SPOTIFY_CIRCLED                    = 0xf328;  //  ????
    inline constexpr int ICON_QQ                                 = 0xf32a;  //  ????
    inline constexpr int ICON_INSTAGRAM                          = 0xf32d;  //  ????
    inline constexpr int ICON_DROPBOX                            = 0xf330;  //  ????
    inline constexpr int ICON_EVERNOTE                           = 0xf333;  //  ????
    inline constexpr int ICON_FLATTR                             = 0xf336;  //  ????
    inline constexpr int ICON_SKYPE                              = 0xf339;  //  ????
    inline constexpr int ICON_SKYPE_CIRCLED                      = 0xf33a;  //  ????
    inline constexpr int ICON_RENREN                             = 0xf33c;  //  ????
    inline constexpr int ICON_SINA_WEIBO                         = 0xf33f;  //  ????
    inline constexpr int ICON_PAYPAL                             = 0xf342;  //  ????
    inline constexpr int ICON_PICASA                             = 0xf345;  //  ????
    inline constexpr int ICON_SOUNDCLOUD                         = 0xf348;  //  ????
    inline constexpr int ICON_MIXI                               = 0xf34b;  //  ????
    inline constexpr int ICON_BEHANCE                            = 0xf34e;  //  ????
    inline constexpr int ICON_GOOGLE_CIRCLES                     = 0xf351;  //  ????
    inline constexpr int ICON_VKONTAKTE                          = 0xf354;  //  ????
    inline constexpr int ICON_SMASHING                           = 0xf357;  //  ????
    inline constexpr int ICON_SWEDEN                             = 0xf601;  //  ????
    inline constexpr int ICON_CC_ZERO                            = 0x1f10d;  // 🄍 CIRCLED ZERO WITH SLASH
    inline constexpr int ICON_CC_SA                              = 0x1f10e;  // 🄎 CIRCLED ANTICLOCKWISE ARROW
    inline constexpr int ICON_CC_NC                              = 0x1f10f;  // 🄏 CIRCLED DOLLAR SIGN WITH OVERLAID BACKSLASH
    inline constexpr int ICON_CC                                 = 0x1f16d;  // 🅭 CIRCLED CC
    inline constexpr int ICON_CC_PD                              = 0x1f16e;  // 🅮 CIRCLED C WITH OVERLAID BACKSLASH
    inline constexpr int ICON_CC_BY                              = 0x1f16f;  // 🅯 CIRCLED HUMAN FIGURE
    inline constexpr int ICON_PICTURE                            = 0x1f304;  // 🌄 SUNRISE OVER MOUNTAINS
    inline constexpr int ICON_GLOBE                              = 0x1f30e;  // 🌎 EARTH GLOBE AMERICAS
    inline constexpr int ICON_THERMOMETER                        = 0x1f321;  // 🌡 THERMOMETER
    inline constexpr int ICON_LEAF                               = 0x1f342;  // 🍂 FALLEN LEAF
    inline constexpr int ICON_GRADUATION_CAP                     = 0x1f393;  // 🎓 GRADUATION CAP
    inline constexpr int ICON_LANGUAGE                           = 0x1f394;  // 🎔 HEART WITH TIP ON THE LEFT
    inline constexpr int ICON_MIC                                = 0x1f3a4;  // 🎤 MICROPHONE
    inline constexpr int ICON_PALETTE                            = 0x1f3a8;  // 🎨 ARTIST PALETTE
    inline constexpr int ICON_TICKET                             = 0x1f3ab;  // 🎫 TICKET
    inline constexpr int ICON_VIDEO                              = 0x1f3ac;  // 🎬 CLAPPER BOARD
    inline constexpr int ICON_TARGET                             = 0x1f3af;  // 🎯 DIRECT HIT
    inline constexpr int ICON_MUSIC                              = 0x1f3b5;  // 🎵 MUSICAL NOTE
    inline constexpr int ICON_TROPHY                             = 0x1f3c6;  // 🏆 TROPHY
    inline constexpr int ICON_TAG                                = 0x1f3f7;  // 🏷 LABEL
    inline constexpr int ICON_EYE                                = 0x1f441;  // 👁 EYE
    inline constexpr int ICON_THUMBS_UP                          = 0x1f44d;  // 👍 THUMBS UP SIGN
    inline constexpr int ICON_THUMBS_DOWN                        = 0x1f44e;  // 👎 THUMBS DOWN SIGN
    inline constexpr int ICON_BAG                                = 0x1f45c;  // 👜 HANDBAG
    inline constexpr int ICON_USER                               = 0x1f464;  // 👤 BUST IN SILHOUETTE
    inline constexpr int ICON_USERS                              = 0x1f465;  // 👥 BUSTS IN SILHOUETTE
    inline constexpr int ICON_ALERT                              = 0x1f4a5;  // 💥 COLLISION SYMBOL
    inline constexpr int ICON_WATER                              = 0x1f4a6;  // 💦 SPLASHING SWEAT SYMBOL
    inline constexpr int ICON_DROPLET                            = 0x1f4a7;  // 💧 DROPLET
    inline constexpr int ICON_AIR                                = 0x1f4a8;  // 💨 DASH SYMBOL
    inline constexpr int ICON_CREDIT_CARD                        = 0x1f4b3;  // 💳 CREDIT CARD
    inline constexpr int ICON_BRIEFCASE                          = 0x1f4bc;  // 💼 BRIEFCASE
    inline constexpr int ICON_FLOPPY                             = 0x1f4be;  // 💾 FLOPPY DISK
    inline constexpr int ICON_CD                                 = 0x1f4bf;  // 💿 OPTICAL DISC
    inline constexpr int ICON_FOLDER                             = 0x1f4c1;  // 📁 FILE FOLDER
    inline constexpr int ICON_DOC_TEXT                           = 0x1f4c4;  // 📄 PAGE FACING UP
    inline constexpr int ICON_CALENDAR                           = 0x1f4c5;  // 📅 CALENDAR
    inline constexpr int ICON_CHART_LINE                         = 0x1f4c8;  // 📈 CHART WITH UPWARDS TREND
    inline constexpr int ICON_CHART_BAR                          = 0x1f4ca;  // 📊 BAR CHART
    inline constexpr int ICON_CLIPBOARD                          = 0x1f4cb;  // 📋 CLIPBOARD
    inline constexpr int ICON_LOCATION                           = 0x1f4cd;  // 📍 ROUND PUSHPIN
    inline constexpr int ICON_ATTACH                             = 0x1f4ce;  // 📎 PAPERCLIP
    inline constexpr int ICON_BOOKMARKS                          = 0x1f4d1;  // 📑 BOOKMARK TABS
    inline constexpr int ICON_BOOK                               = 0x1f4d5;  // 📕 CLOSED BOOK
    inline constexpr int ICON_BOOK_OPEN                          = 0x1f4d6;  // 📖 OPEN BOOK
    inline constexpr int ICON_PHONE                              = 0x1f4de;  // 📞 TELEPHONE RECEIVER
    inline constexpr int ICON_INBOX                              = 0x1f4e3;  // 📣 CHEERING MEGAPHONE
    inline constexpr int ICON_UPLOAD                             = 0x1f4e4;  // 📤 OUTBOX TRAY
    inline constexpr int ICON_DOWNLOAD                           = 0x1f4e5;  // 📥 INBOX TRAY
    inline constexpr int ICON_BOX                                = 0x1f4e6;  // 📦 PACKAGE
    inline constexpr int ICON_NEWSPAPER                          = 0x1f4f0;  // 📰 NEWSPAPER
    inline constexpr int ICON_MOBILE                             = 0x1f4f1;  // 📱 MOBILE PHONE
    inline constexpr int ICON_SIGNAL                             = 0x1f4f6;  // 📶 ANTENNA WITH BARS
    inline constexpr int ICON_CAMERA                             = 0x1f4f7;  // 📷 CAMERA
    inline constexpr int ICON_SHUFFLE                            = 0x1f500;  // 🔀 TWISTED RIGHTWARDS ARROWS
    inline constexpr int ICON_LOOP                               = 0x1f501;  // 🔁 CLOCKWISE RIGHTWARDS AND LEFTWARDS OPEN CIRCLE ARROWS
    inline constexpr int ICON_LIGHT_DOWN                         = 0x1f505;  // 🔅 LOW BRIGHTNESS SYMBOL
    inline constexpr int ICON_LIGHT_UP                           = 0x1f506;  // 🔆 HIGH BRIGHTNESS SYMBOL
    inline constexpr int ICON_MUTE                               = 0x1f507;  // 🔇 SPEAKER WITH CANCELLATION STROKE
    inline constexpr int ICON_SOUND                              = 0x1f50a;  // 🔊 SPEAKER WITH THREE SOUND WAVES
    inline constexpr int ICON_BATTERY                            = 0x1f50b;  // 🔋 BATTERY
    inline constexpr int ICON_SEARCH                             = 0x1f50d;  // 🔍 LEFT-POINTING MAGNIFYING GLASS
    inline constexpr int ICON_KEY                                = 0x1f511;  // 🔑 KEY
    inline constexpr int ICON_LOCK                               = 0x1f512;  // 🔒 LOCK
    inline constexpr int ICON_LOCK_OPEN                          = 0x1f513;  // 🔓 OPEN LOCK
    inline constexpr int ICON_BELL                               = 0x1f514;  // 🔔 BELL
    inline constexpr int ICON_BOOKMARK                           = 0x1f516;  // 🔖 BOOKMARK
    inline constexpr int ICON_LINK                               = 0x1f517;  // 🔗 LINK SYMBOL
    inline constexpr int ICON_BACK                               = 0x1f519;  // 🔙 BACK WITH LEFTWARDS ARROW ABOVE
    inline constexpr int ICON_FLASHLIGHT                         = 0x1f526;  // 🔦 ELECTRIC TORCH
    inline constexpr int ICON_CHART_AREA                         = 0x1f53e;  // 🔾 LOWER RIGHT SHADOWED WHITE CIRCLE
    inline constexpr int ICON_PAPER_PLANE                        = 0x1f53f;  // 🔿 UPPER RIGHT SHADOWED WHITE CIRCLE
    inline constexpr int ICON_CC_SHARE                           = 0x1f54e;  // 🕎 MENORAH WITH NINE BRANCHES
    inline constexpr int ICON_CLOCK                              = 0x1f554;  // 🕔 CLOCK FACE FIVE OCLOCK
    inline constexpr int ICON_FLOW_CASCADE                       = 0x1f568;  // 🕨 RIGHT SPEAKER
    inline constexpr int ICON_FLOW_BRANCH                        = 0x1f569;  // 🕩 RIGHT SPEAKER WITH ONE SOUND WAVE
    inline constexpr int ICON_FLOW_TREE                          = 0x1f56a;  // 🕪 RIGHT SPEAKER WITH THREE SOUND WAVES
    inline constexpr int ICON_FLOW_LINE                          = 0x1f56b;  // 🕫 BULLHORN
    inline constexpr int ICON_FLOW_PARALLEL                      = 0x1f56c;  // 🕬 BULLHORN WITH SOUND WAVES
    inline constexpr int ICON_BRUSH                              = 0x1f58c;  // 🖌 LOWER LEFT PAINTBRUSH
    inline constexpr int ICON_MOUSE                              = 0x1f5b1;  // 🖱 THREE BUTTON MOUSE
    inline constexpr int ICON_DRIVE                              = 0x1f5b4;  // 🖴 HARD DISK
    inline constexpr int ICON_MONITOR                            = 0x1f5b5;  // 🖵 SCREEN
    inline constexpr int ICON_PRINT                              = 0x1f5b6;  // 🖶 PRINTER ICON
    inline constexpr int ICON_ARCHIVE                            = 0x1f5c3;  // 🗃 CARD FILE BOX
    inline constexpr int ICON_TRASH                              = 0x1f5d1;  // 🗑 WASTEBASKET
    inline constexpr int ICON_WINDOW                             = 0x1f5d4;  // 🗔 DESKTOP WINDOW
    inline constexpr int ICON_RESIZE_SMALL                       = 0x1f5d5;  // 🗕 MINIMIZE
    inline constexpr int ICON_RESIZE_FULL                        = 0x1f5d6;  // 🗖 MAXIMIZE
    inline constexpr int ICON_POPUP                              = 0x1f5d7;  // 🗗 OVERLAP
    inline constexpr int ICON_COMMENT                            = 0x1f5e8;  // 🗨 LEFT SPEECH BUBBLE
    inline constexpr int ICON_CHAT                               = 0x1f5ea;  // 🗪 TWO SPEECH BUBBLES
    inline constexpr int ICON_LOGO_DB                            = 0x1f5f9;  // 🗹 BALLOT BOX WITH BOLD CHECK
    inline constexpr int ICON_DB_SHAPE                           = 0x1f5fa;  // 🗺 WORLD MAP
    inline constexpr int ICON_ROCKET                             = 0x1f680;  // 🚀 ROCKET
    inline constexpr int ICON_BLOCK                              = 0x1f6ab;  // 🚫 NO ENTRY SIGN
    inline constexpr int ICON_SUITCASE                           = 0x1f6c6;  // 🛆 TRIANGLE WITH ROUNDED CORNERS
    inline constexpr int ICON_GAUGE                              = 0x1f6c7;  // 🛇 PROHIBITED SIGN
    inline constexpr int ICON_INFO_CIRCLED                       = 0x1f6c8;  // 🛈 CIRCLED INFORMATION SOURCE
    inline constexpr int ICON_BASKET                             = 0x1f6d2;  // 🛒 SHOPPING TROLLEY
    inline constexpr int ICON_DATABASE                           = 0x1f6e2;  // 🛢 OIL DRUM
    inline constexpr int ICON_LEFT_THIN                          = 0x1f800;  // 🠀 LEFTWARDS ARROW WITH SMALL TRIANGLE ARROWHEAD
    inline constexpr int ICON_UP_THIN                            = 0x1f801;  // 🠁 UPWARDS ARROW WITH SMALL TRIANGLE ARROWHEAD
    inline constexpr int ICON_RIGHT_THIN                         = 0x1f802;  // 🠂 RIGHTWARDS ARROW WITH SMALL TRIANGLE ARROWHEAD
    inline constexpr int ICON_DOWN_THIN                          = 0x1f803;  // 🠃 DOWNWARDS ARROW WITH SMALL TRIANGLE ARROWHEAD
    inline constexpr int ICON_LEFT_BOLD                          = 0x1f844;  // 🡄 LEFTWARDS HEAVY ARROW
    inline constexpr int ICON_UP_BOLD                            = 0x1f845;  // 🡅 UPWARDS HEAVY ARROW
    inline constexpr int ICON_RIGHT_BOLD                         = 0x1f846;  // 🡆 RIGHTWARDS HEAVY ARROW
    inline constexpr int ICON_DOWN_BOLD                          = 0x1f847;  // 🡇 DOWNWARDS HEAVY ARROW
    inline constexpr int ICON_COMPASS                            = 0x1f9ed;  // 🧭 COMPASS
    inline constexpr int ICON_MAGNET                             = 0x1f9f2;  // 🧲 MAGNET
    inline constexpr int ICON_BUCKET                             = 0x1faa3;  // 🪣 BUCKET
    inline constexpr int ICON_VCARD                              = 0x1faaa;  // 🪪 ????
    inline constexpr int ICON_FEATHER                            = 0x1fab6;  // 🪶 FEATHER
}

// prevent individual pages from being generated for all of these
#if !defined(DOXYGEN_SHOULD_SKIP_THIS)

#define ENTYPO_ICON_NONE                            0x0000e7ff
#define ENTYPO_ICON_GLASS                           0x0000e800
#define ENTYPO_ICON_MUSIC                           0x0000e801
#define ENTYPO_ICON_SEARCH                          0x0000e802
#define ENTYPO_ICON_MAIL                            0x0000e803
#define ENTYPO_ICON_HEART                           0x0000e804
#define ENTYPO_ICON_HEART_EMPTY                     0x0000e805
#define ENTYPO_ICON_STAR                            0x0000e806
#define ENTYPO_ICON_EMO_TONGUE                      0x0000e807
#define ENTYPO_ICON_STAR_EMPTY                      0x0000e808
#define ENTYPO_ICON_STAR_HALF                       0x0000e809
#define ENTYPO_ICON_USER                            0x0000e80a
#define ENTYPO_ICON_USERS                           0x0000e80b
#define ENTYPO_ICON_VIDEO                           0x0000e80c
#define ENTYPO_ICON_VIDEOCAM                        0x0000e80d
#define ENTYPO_ICON_PICTURE                         0x0000e80e
#define ENTYPO_ICON_CAMERA                          0x0000e80f
#define ENTYPO_ICON_CAMERA_ALT                      0x0000e810
#define ENTYPO_ICON_TH_LARGE                        0x0000e811
#define ENTYPO_ICON_TH                              0x0000e812
#define ENTYPO_ICON_TH_LIST                         0x0000e813
#define ENTYPO_ICON_OK                              0x0000e814
#define ENTYPO_ICON_OK_CIRCLED                      0x0000e815
#define ENTYPO_ICON_OK_CIRCLED2                     0x0000e816
#define ENTYPO_ICON_CANCEL                          0x0000e817
#define ENTYPO_ICON_CANCEL_CIRCLED                  0x0000e818
#define ENTYPO_ICON_CANCEL_CIRCLED2                 0x0000e819
#define ENTYPO_ICON_PLUS                            0x0000e81a
#define ENTYPO_ICON_PLUS_CIRCLED                    0x0000e81b
#define ENTYPO_ICON_MINUS                           0x0000e81c
#define ENTYPO_ICON_MINUS_CIRCLED                   0x0000e81d
#define ENTYPO_ICON_HELP_CIRCLED                    0x0000e81e
#define ENTYPO_ICON_INFO_CIRCLED                    0x0000e81f
#define ENTYPO_ICON_HOME                            0x0000e820
#define ENTYPO_ICON_LINK                            0x0000e821
#define ENTYPO_ICON_ATTACH                          0x0000e822
#define ENTYPO_ICON_LOCK                            0x0000e823
#define ENTYPO_ICON_LOCK_OPEN                       0x0000e824
#define ENTYPO_ICON_PIN                             0x0000e825
#define ENTYPO_ICON_EYE                             0x0000e826
#define ENTYPO_ICON_EYE_OFF                         0x0000e827
#define ENTYPO_ICON_TAG                             0x0000e828
#define ENTYPO_ICON_TAGS                            0x0000e829
#define ENTYPO_ICON_BOOKMARK                        0x0000e82a
#define ENTYPO_ICON_FLAG                            0x0000e82b
#define ENTYPO_ICON_THUMBS_UP                       0x0000e82c
#define ENTYPO_ICON_THUMBS_DOWN                     0x0000e82d
#define ENTYPO_ICON_DOWNLOAD                        0x0000e82e
#define ENTYPO_ICON_UPLOAD                          0x0000e82f
#define ENTYPO_ICON_FORWARD                         0x0000e830
#define ENTYPO_ICON_EXPORT                          0x0000e831
#define ENTYPO_ICON_PENCIL                          0x0000e832
#define ENTYPO_ICON_EDIT                            0x0000e833
#define ENTYPO_ICON_PRINT                           0x0000e834
#define ENTYPO_ICON_RETWEET                         0x0000e835
#define ENTYPO_ICON_COMMENT                         0x0000e836
#define ENTYPO_ICON_CHAT                            0x0000e837
#define ENTYPO_ICON_BELL                            0x0000e838
#define ENTYPO_ICON_ATTENTION                       0x0000e839
#define ENTYPO_ICON_ATTENTION_CIRCLED               0x0000e83a
#define ENTYPO_ICON_LOCATION                        0x0000e83b
#define ENTYPO_ICON_TRASH_EMPTY                     0x0000e83c
#define ENTYPO_ICON_DOC                             0x0000e83d
#define ENTYPO_ICON_FOLDER                          0x0000e83e
#define ENTYPO_ICON_FOLDER_OPEN                     0x0000e83f
#define ENTYPO_ICON_PHONE                           0x0000e840
#define ENTYPO_ICON_COG                             0x0000e841
#define ENTYPO_ICON_COG_ALT                         0x0000e842
#define ENTYPO_ICON_WRENCH                          0x0000e843
#define ENTYPO_ICON_BASKET                          0x0000e844
#define ENTYPO_ICON_CALENDAR                        0x0000e845
#define ENTYPO_ICON_LOGIN                           0x0000e846
#define ENTYPO_ICON_LOGOUT                          0x0000e847
#define ENTYPO_ICON_VOLUME_OFF                      0x0000e848
#define ENTYPO_ICON_VOLUME_DOWN                     0x0000e849
#define ENTYPO_ICON_VOLUME_UP                       0x0000e84a
#define ENTYPO_ICON_HEADPHONES                      0x0000e84b
#define ENTYPO_ICON_CLOCK                           0x0000e84c
#define ENTYPO_ICON_BLOCK                           0x0000e84d
#define ENTYPO_ICON_RESIZE_FULL                     0x0000e84e
#define ENTYPO_ICON_RESIZE_SMALL                    0x0000e84f
#define ENTYPO_ICON_RESIZE_VERTICAL                 0x0000e850
#define ENTYPO_ICON_RESIZE_HORIZONTAL               0x0000e851
#define ENTYPO_ICON_ZOOM_IN                         0x0000e852
#define ENTYPO_ICON_ZOOM_OUT                        0x0000e853
#define ENTYPO_ICON_DOWN_CIRCLED2                   0x0000e854
#define ENTYPO_ICON_UP_CIRCLED2                     0x0000e855
#define ENTYPO_ICON_DOWN_DIR                        0x0000e856
#define ENTYPO_ICON_UP_DIR                          0x0000e857
#define ENTYPO_ICON_LEFT_DIR                        0x0000e858
#define ENTYPO_ICON_RIGHT_DIR                       0x0000e859
#define ENTYPO_ICON_DOWN_OPEN                       0x0000e85a
#define ENTYPO_ICON_LEFT_OPEN                       0x0000e85b
#define ENTYPO_ICON_RIGHT_OPEN                      0x0000e85c
#define ENTYPO_ICON_UP_OPEN                         0x0000e85d
#define ENTYPO_ICON_DOWN_BIG                        0x0000e85e
#define ENTYPO_ICON_LEFT_BIG                        0x0000e85f
#define ENTYPO_ICON_RIGHT_BIG                       0x0000e860
#define ENTYPO_ICON_UP_BIG                          0x0000e861
#define ENTYPO_ICON_RIGHT_HAND                      0x0000e862
#define ENTYPO_ICON_LEFT_HAND                       0x0000e863
#define ENTYPO_ICON_UP_HAND                         0x0000e864
#define ENTYPO_ICON_DOWN_HAND                       0x0000e865
#define ENTYPO_ICON_CW                              0x0000e866
#define ENTYPO_ICON_CCW                             0x0000e867
#define ENTYPO_ICON_ARROWS_CW                       0x0000e868
#define ENTYPO_ICON_SHUFFLE                         0x0000e869
#define ENTYPO_ICON_PLAY                            0x0000e86a
#define ENTYPO_ICON_PLAY_CIRCLED2                   0x0000e86b
#define ENTYPO_ICON_STOP                            0x0000e86c
#define ENTYPO_ICON_PAUSE                           0x0000e86d
#define ENTYPO_ICON_TO_END                          0x0000e86e
#define ENTYPO_ICON_TO_END_ALT                      0x0000e86f
#define ENTYPO_ICON_TO_START                        0x0000e870
#define ENTYPO_ICON_TO_START_ALT                    0x0000e871
#define ENTYPO_ICON_FAST_FW                         0x0000e872
#define ENTYPO_ICON_FAST_BW                         0x0000e873
#define ENTYPO_ICON_EJECT                           0x0000e874
#define ENTYPO_ICON_TARGET                          0x0000e875
#define ENTYPO_ICON_SIGNAL                          0x0000e876
#define ENTYPO_ICON_AWARD                           0x0000e877
#define ENTYPO_ICON_INBOX                           0x0000e878
#define ENTYPO_ICON_GLOBE                           0x0000e879
#define ENTYPO_ICON_CLOUD                           0x0000e87a
#define ENTYPO_ICON_FLASH                           0x0000e87b
#define ENTYPO_ICON_UMBRELLA                        0x0000e87c
#define ENTYPO_ICON_FLIGHT                          0x0000e87d
#define ENTYPO_ICON_LEAF                            0x0000e87e
#define ENTYPO_ICON_FONT                            0x0000e87f
#define ENTYPO_ICON_BOLD                            0x0000e880
#define ENTYPO_ICON_ITALIC                          0x0000e881
#define ENTYPO_ICON_TEXT_HEIGHT                     0x0000e882
#define ENTYPO_ICON_TEXT_WIDTH                      0x0000e883
#define ENTYPO_ICON_ALIGN_LEFT                      0x0000e884
#define ENTYPO_ICON_ALIGN_CENTER                    0x0000e885
#define ENTYPO_ICON_ALIGN_RIGHT                     0x0000e886
#define ENTYPO_ICON_ALIGN_JUSTIFY                   0x0000e887
#define ENTYPO_ICON_LIST                            0x0000e888
#define ENTYPO_ICON_INDENT_LEFT                     0x0000e889
#define ENTYPO_ICON_INDENT_RIGHT                    0x0000e88a
#define ENTYPO_ICON_SCISSORS                        0x0000e88b
#define ENTYPO_ICON_BRIEFCASE                       0x0000e88c
#define ENTYPO_ICON_OFF                             0x0000e88d
#define ENTYPO_ICON_ROAD                            0x0000e88e
#define ENTYPO_ICON_LIST_ALT                        0x0000e88f
#define ENTYPO_ICON_QRCODE                          0x0000e890
#define ENTYPO_ICON_BARCODE                         0x0000e891
#define ENTYPO_ICON_BOOK                            0x0000e892
#define ENTYPO_ICON_ADJUST                          0x0000e893
#define ENTYPO_ICON_TINT                            0x0000e894
#define ENTYPO_ICON_CHECK                           0x0000e895
#define ENTYPO_ICON_ASTERISK                        0x0000e896
#define ENTYPO_ICON_GIFT                            0x0000e897
#define ENTYPO_ICON_FIRE                            0x0000e898
#define ENTYPO_ICON_MAGNET                          0x0000e899
#define ENTYPO_ICON_CHART_BAR                       0x0000e89a
#define ENTYPO_ICON_CREDIT_CARD                     0x0000e89b
#define ENTYPO_ICON_FLOPPY                          0x0000e89c
#define ENTYPO_ICON_MEGAPHONE                       0x0000e89d
#define ENTYPO_ICON_KEY                             0x0000e89e
#define ENTYPO_ICON_TRUCK                           0x0000e89f
#define ENTYPO_ICON_HAMMER                          0x0000e8a0
#define ENTYPO_ICON_LEMON                           0x0000e8a1
#define ENTYPO_ICON_NOTE                            0x0000e8a2
#define ENTYPO_ICON_NOTE_BEAMED                     0x0000e8a3
#define ENTYPO_ICON_MUSIC_1                         0x0000e8a4
#define ENTYPO_ICON_SEARCH_1                        0x0000e8a5
#define ENTYPO_ICON_FLASHLIGHT                      0x0000e8a6
#define ENTYPO_ICON_MAIL_1                          0x0000e8a7
#define ENTYPO_ICON_HEART_1                         0x0000e8a8
#define ENTYPO_ICON_HEART_EMPTY_1                   0x0000e8a9
#define ENTYPO_ICON_STAR_1                          0x0000e8aa
#define ENTYPO_ICON_STAR_EMPTY_1                    0x0000e8ab
#define ENTYPO_ICON_USER_1                          0x0000e8ac
#define ENTYPO_ICON_USERS_1                         0x0000e8ad
#define ENTYPO_ICON_USER_ADD                        0x0000e8ae
#define ENTYPO_ICON_VIDEO_1                         0x0000e8af
#define ENTYPO_ICON_PICTURE_1                       0x0000e8b0
#define ENTYPO_ICON_CAMERA_1                        0x0000e8b1
#define ENTYPO_ICON_LAYOUT                          0x0000e8b2
#define ENTYPO_ICON_MENU_1                          0x0000e8b3
#define ENTYPO_ICON_CHECK_1                         0x0000e8b4
#define ENTYPO_ICON_CANCEL_1                        0x0000e8b5
#define ENTYPO_ICON_CANCEL_CIRCLED_1                0x0000e8b6
#define ENTYPO_ICON_CANCEL_SQUARED                  0x0000e8b7
#define ENTYPO_ICON_PLUS_1                          0x0000e8b8
#define ENTYPO_ICON_PLUS_CIRCLED_1                  0x0000e8b9
#define ENTYPO_ICON_PLUS_SQUARED_1                  0x0000e8ba
#define ENTYPO_ICON_MINUS_1                         0x0000e8bb
#define ENTYPO_ICON_MINUS_CIRCLED_1                 0x0000e8bc
#define ENTYPO_ICON_MINUS_SQUARED_1                 0x0000e8bd
#define ENTYPO_ICON_HELP_1                          0x0000e8be
#define ENTYPO_ICON_HELP_CIRCLED_1                  0x0000e8bf
#define ENTYPO_ICON_INFO_1                          0x0000e8c0
#define ENTYPO_ICON_INFO_CIRCLED_1                  0x0000e8c1
#define ENTYPO_ICON_BACK                            0x0000e8c2
#define ENTYPO_ICON_HOME_1                          0x0000e8c3
#define ENTYPO_ICON_LINK_1                          0x0000e8c4
#define ENTYPO_ICON_ATTACH_1                        0x0000e8c5
#define ENTYPO_ICON_LOCK_1                          0x0000e8c6
#define ENTYPO_ICON_LOCK_OPEN_1                     0x0000e8c7
#define ENTYPO_ICON_EYE_1                           0x0000e8c8
#define ENTYPO_ICON_TAG_1                           0x0000e8c9
#define ENTYPO_ICON_BOOKMARK_1                      0x0000e8ca
#define ENTYPO_ICON_BOOKMARKS                       0x0000e8cb
#define ENTYPO_ICON_FLAG_1                          0x0000e8cc
#define ENTYPO_ICON_THUMBS_UP_1                     0x0000e8cd
#define ENTYPO_ICON_THUMBS_DOWN_1                   0x0000e8ce
#define ENTYPO_ICON_DOWNLOAD_1                      0x0000e8cf
#define ENTYPO_ICON_UPLOAD_1                        0x0000e8d0
#define ENTYPO_ICON_UPLOAD_CLOUD_1                  0x0000e8d1
#define ENTYPO_ICON_REPLY_1                         0x0000e8d2
#define ENTYPO_ICON_REPLY_ALL_1                     0x0000e8d3
#define ENTYPO_ICON_FORWARD_1                       0x0000e8d4
#define ENTYPO_ICON_QUOTE                           0x0000e8d5
#define ENTYPO_ICON_CODE_1                          0x0000e8d6
#define ENTYPO_ICON_EXPORT_1                        0x0000e8d7
#define ENTYPO_ICON_PENCIL_1                        0x0000e8d8
#define ENTYPO_ICON_FEATHER                         0x0000e8d9
#define ENTYPO_ICON_PRINT_1                         0x0000e8da
#define ENTYPO_ICON_RETWEET_1                       0x0000e8db
#define ENTYPO_ICON_KEYBOARD_1                      0x0000e8dc
#define ENTYPO_ICON_COMMENT_1                       0x0000e8dd
#define ENTYPO_ICON_CHAT_1                          0x0000e8de
#define ENTYPO_ICON_BELL_1                          0x0000e8df
#define ENTYPO_ICON_ATTENTION_1                     0x0000e8e0
#define ENTYPO_ICON_ALERT                           0x0000e8e1
#define ENTYPO_ICON_VCARD                           0x0000e8e2
#define ENTYPO_ICON_ADDRESS                         0x0000e8e3
#define ENTYPO_ICON_LOCATION_1                      0x0000e8e4
#define ENTYPO_ICON_MAP_1                           0x0000e8e5
#define ENTYPO_ICON_DIRECTION_1                     0x0000e8e6
#define ENTYPO_ICON_COMPASS_1                       0x0000e8e7
#define ENTYPO_ICON_CUP                             0x0000e8e8
#define ENTYPO_ICON_TRASH_1                         0x0000e8e9
#define ENTYPO_ICON_DOC_1                           0x0000e8ea
#define ENTYPO_ICON_DOCS_1                          0x0000e8eb
#define ENTYPO_ICON_DOC_LANDSCAPE                   0x0000e8ec
#define ENTYPO_ICON_DOC_TEXT_1                      0x0000e8ed
#define ENTYPO_ICON_DOC_TEXT_INV_1                  0x0000e8ee
#define ENTYPO_ICON_NEWSPAPER_1                     0x0000e8ef
#define ENTYPO_ICON_BOOK_OPEN                       0x0000e8f0
#define ENTYPO_ICON_BOOK_1                          0x0000e8f1
#define ENTYPO_ICON_FOLDER_1                        0x0000e8f2
#define ENTYPO_ICON_ARCHIVE                         0x0000e8f3
#define ENTYPO_ICON_BOX_1                           0x0000e8f4
#define ENTYPO_ICON_RSS_1                           0x0000e8f5
#define ENTYPO_ICON_PHONE_1                         0x0000e8f6
#define ENTYPO_ICON_COG_1                           0x0000e8f7
#define ENTYPO_ICON_TOOLS                           0x0000e8f8
#define ENTYPO_ICON_SHARE_1                         0x0000e8f9
#define ENTYPO_ICON_SHAREABLE                       0x0000e8fa
#define ENTYPO_ICON_BASKET_1                        0x0000e8fb
#define ENTYPO_ICON_BAG                             0x0000e8fc
#define ENTYPO_ICON_CALENDAR_1                      0x0000e8fd
#define ENTYPO_ICON_LOGIN_1                         0x0000e8fe
#define ENTYPO_ICON_LOGOUT_1                        0x0000e8ff
#define ENTYPO_ICON_MIC_1                           0x0000e900
#define ENTYPO_ICON_MUTE_1                          0x0000e901
#define ENTYPO_ICON_SOUND                           0x0000e902
#define ENTYPO_ICON_VOLUME                          0x0000e903
#define ENTYPO_ICON_CLOCK_1                         0x0000e904
#define ENTYPO_ICON_HOURGLASS_4                     0x0000e905
#define ENTYPO_ICON_LAMP                            0x0000e906
#define ENTYPO_ICON_LIGHT_DOWN                      0x0000e907
#define ENTYPO_ICON_LIGHT_UP                        0x0000e908
#define ENTYPO_ICON_ADJUST_1                        0x0000e909
#define ENTYPO_ICON_BLOCK_1                         0x0000e90a
#define ENTYPO_ICON_RESIZE_FULL_1                   0x0000e90b
#define ENTYPO_ICON_RESIZE_SMALL_1                  0x0000e90c
#define ENTYPO_ICON_POPUP                           0x0000e90d
#define ENTYPO_ICON_PUBLISH                         0x0000e90e
#define ENTYPO_ICON_WINDOW                          0x0000e90f
#define ENTYPO_ICON_ARROW_COMBO                     0x0000e910
#define ENTYPO_ICON_DOWN_CIRCLED_1                  0x0000e911
#define ENTYPO_ICON_LEFT_CIRCLED_1                  0x0000e912
#define ENTYPO_ICON_RIGHT_CIRCLED_1                 0x0000e913
#define ENTYPO_ICON_UP_CIRCLED_1                    0x0000e914
#define ENTYPO_ICON_DOWN_OPEN_1                     0x0000e915
#define ENTYPO_ICON_LEFT_OPEN_1                     0x0000e916
#define ENTYPO_ICON_RIGHT_OPEN_1                    0x0000e917
#define ENTYPO_ICON_UP_OPEN_1                       0x0000e918
#define ENTYPO_ICON_DOWN_OPEN_MINI                  0x0000e919
#define ENTYPO_ICON_LEFT_OPEN_MINI                  0x0000e91a
#define ENTYPO_ICON_RIGHT_OPEN_MINI                 0x0000e91b
#define ENTYPO_ICON_UP_OPEN_MINI                    0x0000e91c
#define ENTYPO_ICON_DOWN_OPEN_BIG                   0x0000e91d
#define ENTYPO_ICON_LEFT_OPEN_BIG                   0x0000e91e
#define ENTYPO_ICON_RIGHT_OPEN_BIG                  0x0000e91f
#define ENTYPO_ICON_UP_OPEN_BIG                     0x0000e920
#define ENTYPO_ICON_DOWN_1                          0x0000e921
#define ENTYPO_ICON_LEFT_1                          0x0000e922
#define ENTYPO_ICON_RIGHT_1                         0x0000e923
#define ENTYPO_ICON_UP_1                            0x0000e924
#define ENTYPO_ICON_DOWN_DIR_1                      0x0000e925
#define ENTYPO_ICON_LEFT_DIR_1                      0x0000e926
#define ENTYPO_ICON_RIGHT_DIR_1                     0x0000e927
#define ENTYPO_ICON_UP_DIR_1                        0x0000e928
#define ENTYPO_ICON_DOWN_BOLD                       0x0000e929
#define ENTYPO_ICON_LEFT_BOLD                       0x0000e92a
#define ENTYPO_ICON_RIGHT_BOLD                      0x0000e92b
#define ENTYPO_ICON_UP_BOLD                         0x0000e92c
#define ENTYPO_ICON_DOWN_THIN                       0x0000e92d
#define ENTYPO_ICON_LEFT_THIN                       0x0000e92e
#define ENTYPO_ICON_RIGHT_THIN                      0x0000e92f
#define ENTYPO_ICON_UP_THIN                         0x0000e930
#define ENTYPO_ICON_CCW_1                           0x0000e931
#define ENTYPO_ICON_CW_1                            0x0000e932
#define ENTYPO_ICON_ARROWS_CCW                      0x0000e933
#define ENTYPO_ICON_LEVEL_DOWN_1                    0x0000e934
#define ENTYPO_ICON_LEVEL_UP_1                      0x0000e935
#define ENTYPO_ICON_SHUFFLE_1                       0x0000e936
#define ENTYPO_ICON_LOOP                            0x0000e937
#define ENTYPO_ICON_SWITCH                          0x0000e938
#define ENTYPO_ICON_PLAY_1                          0x0000e939
#define ENTYPO_ICON_STOP_1                          0x0000e93a
#define ENTYPO_ICON_PAUSE_1                         0x0000e93b
#define ENTYPO_ICON_RECORD                          0x0000e93c
#define ENTYPO_ICON_TO_END_1                        0x0000e93d
#define ENTYPO_ICON_TO_START_1                      0x0000e93e
#define ENTYPO_ICON_FAST_FORWARD                    0x0000e93f
#define ENTYPO_ICON_FAST_BACKWARD                   0x0000e940
#define ENTYPO_ICON_PROGRESS_0                      0x0000e941
#define ENTYPO_ICON_PROGRESS_1                      0x0000e942
#define ENTYPO_ICON_PROGRESS_2                      0x0000e943
#define ENTYPO_ICON_PROGRESS_3                      0x0000e944
#define ENTYPO_ICON_TARGET_1                        0x0000e945
#define ENTYPO_ICON_PALETTE                         0x0000e946
#define ENTYPO_ICON_LIST_1                          0x0000e947
#define ENTYPO_ICON_LIST_ADD                        0x0000e948
#define ENTYPO_ICON_SIGNAL_1                        0x0000e949
#define ENTYPO_ICON_TROPHY                          0x0000e94a
#define ENTYPO_ICON_BATTERY                         0x0000e94b
#define ENTYPO_ICON_BACK_IN_TIME                    0x0000e94c
#define ENTYPO_ICON_MONITOR                         0x0000e94d
#define ENTYPO_ICON_MOBILE_1                        0x0000e94e
#define ENTYPO_ICON_NETWORK                         0x0000e94f
#define ENTYPO_ICON_CD                              0x0000e950
#define ENTYPO_ICON_INBOX_1                         0x0000e951
#define ENTYPO_ICON_INSTALL                         0x0000e952
#define ENTYPO_ICON_GLOBE_1                         0x0000e953
#define ENTYPO_ICON_CLOUD_1                         0x0000e954
#define ENTYPO_ICON_CLOUD_THUNDER                   0x0000e955
#define ENTYPO_ICON_FLASH_1                         0x0000e956
#define ENTYPO_ICON_MOON_1                          0x0000e957
#define ENTYPO_ICON_FLIGHT_1                        0x0000e958
#define ENTYPO_ICON_PAPER_PLANE_1                   0x0000e959
#define ENTYPO_ICON_LEAF_1                          0x0000e95a
#define ENTYPO_ICON_LIFEBUOY_1                      0x0000e95b
#define ENTYPO_ICON_MOUSE                           0x0000e95c
#define ENTYPO_ICON_BRIEFCASE_1                     0x0000e95d
#define ENTYPO_ICON_SUITCASE_1                      0x0000e95e
#define ENTYPO_ICON_DOT                             0x0000e95f
#define ENTYPO_ICON_DOT_2                           0x0000e960
#define ENTYPO_ICON_DOT_3                           0x0000e961
#define ENTYPO_ICON_BRUSH_1                         0x0000e962
#define ENTYPO_ICON_MAGNET_1                        0x0000e963
#define ENTYPO_ICON_INFINITY                        0x0000e964
#define ENTYPO_ICON_ERASE                           0x0000e965
#define ENTYPO_ICON_CHART_PIE_1                     0x0000e966
#define ENTYPO_ICON_CHART_LINE_1                    0x0000e967
#define ENTYPO_ICON_CHART_BAR_1                     0x0000e968
#define ENTYPO_ICON_CHART_AREA_1                    0x0000e969
#define ENTYPO_ICON_TAPE                            0x0000e96a
#define ENTYPO_ICON_GRADUATION_CAP_1                0x0000e96b
#define ENTYPO_ICON_LANGUAGE_1                      0x0000e96c
#define ENTYPO_ICON_TICKET_1                        0x0000e96d
#define ENTYPO_ICON_WATER                           0x0000e96e
#define ENTYPO_ICON_DROPLET                         0x0000e96f
#define ENTYPO_ICON_AIR                             0x0000e970
#define ENTYPO_ICON_CREDIT_CARD_1                   0x0000e971
#define ENTYPO_ICON_FLOPPY_1                        0x0000e972
#define ENTYPO_ICON_CLIPBOARD                       0x0000e973
#define ENTYPO_ICON_MEGAPHONE_1                     0x0000e974
#define ENTYPO_ICON_DATABASE_1                      0x0000e975
#define ENTYPO_ICON_DRIVE                           0x0000e976
#define ENTYPO_ICON_BUCKET                          0x0000e977
#define ENTYPO_ICON_THERMOMETER_1                   0x0000e978
#define ENTYPO_ICON_KEY_1                           0x0000e979
#define ENTYPO_ICON_FLOW_CASCADE                    0x0000e97a
#define ENTYPO_ICON_FLOW_BRANCH                     0x0000e97b
#define ENTYPO_ICON_FLOW_TREE                       0x0000e97c
#define ENTYPO_ICON_FLOW_LINE                       0x0000e97d
#define ENTYPO_ICON_FLOW_PARALLEL                   0x0000e97e
#define ENTYPO_ICON_ROCKET_1                        0x0000e97f
#define ENTYPO_ICON_GAUGE_1                         0x0000e980
#define ENTYPO_ICON_TRAFFIC_CONE                    0x0000e981
#define ENTYPO_ICON_CC_1                            0x0000e982
#define ENTYPO_ICON_CC_BY                           0x0000e983
#define ENTYPO_ICON_CC_NC                           0x0000e984
#define ENTYPO_ICON_CC_NC_EU                        0x0000e985
#define ENTYPO_ICON_CC_NC_JP                        0x0000e986
#define ENTYPO_ICON_CC_SA                           0x0000e987
#define ENTYPO_ICON_CC_ND                           0x0000e988
#define ENTYPO_ICON_CC_PD                           0x0000e989
#define ENTYPO_ICON_CC_ZERO                         0x0000e98a
#define ENTYPO_ICON_CC_SHARE                        0x0000e98b
#define ENTYPO_ICON_CC_REMIX                        0x0000e98c
#define ENTYPO_ICON_GITHUB_1                        0x0000e98d
#define ENTYPO_ICON_FLICKR_CIRCLED                  0x0000e98e
#define ENTYPO_ICON_FACEBOOK_1                      0x0000e98f
#define ENTYPO_ICON_MUSIC_OUTLINE                   0x0000e990
#define ENTYPO_ICON_MUSIC_2                         0x0000e991
#define ENTYPO_ICON_SEARCH_OUTLINE                  0x0000e992
#define ENTYPO_ICON_SEARCH_2                        0x0000e993
#define ENTYPO_ICON_MAIL_2                          0x0000e994
#define ENTYPO_ICON_HEART_2                         0x0000e995
#define ENTYPO_ICON_HEART_FILLED                    0x0000e996
#define ENTYPO_ICON_STAR_2                          0x0000e997
#define ENTYPO_ICON_STAR_FILLED                     0x0000e998
#define ENTYPO_ICON_USER_OUTLINE                    0x0000e999
#define ENTYPO_ICON_USER_2                          0x0000e99a
#define ENTYPO_ICON_USERS_OUTLINE                   0x0000e99b
#define ENTYPO_ICON_USERS_2                         0x0000e99c
#define ENTYPO_ICON_USER_ADD_OUTLINE                0x0000e99d
#define ENTYPO_ICON_USER_ADD_1                      0x0000e99e
#define ENTYPO_ICON_USER_DELETE_OUTLINE             0x0000e99f
#define ENTYPO_ICON_USER_DELETE                     0x0000e9a0
#define ENTYPO_ICON_VIDEO_2                         0x0000e9a1
#define ENTYPO_ICON_VIDEOCAM_OUTLINE                0x0000e9a2
#define ENTYPO_ICON_VIDEOCAM_1                      0x0000e9a3
#define ENTYPO_ICON_PICTURE_OUTLINE                 0x0000e9a4
#define ENTYPO_ICON_PICTURE_2                       0x0000e9a5
#define ENTYPO_ICON_CAMERA_OUTLINE                  0x0000e9a6
#define ENTYPO_ICON_CAMERA_2                        0x0000e9a7
#define ENTYPO_ICON_TH_OUTLINE                      0x0000e9a8
#define ENTYPO_ICON_TH_1                            0x0000e9a9
#define ENTYPO_ICON_TH_LARGE_OUTLINE                0x0000e9aa
#define ENTYPO_ICON_TH_LARGE_1                      0x0000e9ab
#define ENTYPO_ICON_TH_LIST_OUTLINE                 0x0000e9ac
#define ENTYPO_ICON_TH_LIST_1                       0x0000e9ad
#define ENTYPO_ICON_OK_OUTLINE                      0x0000e9ae
#define ENTYPO_ICON_OK_1                            0x0000e9af
#define ENTYPO_ICON_CANCEL_OUTLINE                  0x0000e9b0
#define ENTYPO_ICON_CANCEL_2                        0x0000e9b1
#define ENTYPO_ICON_CANCEL_ALT                      0x0000e9b2
#define ENTYPO_ICON_CANCEL_ALT_FILLED               0x0000e9b3
#define ENTYPO_ICON_CANCEL_CIRCLED_OUTLINE          0x0000e9b4
#define ENTYPO_ICON_CANCEL_CIRCLED_2                0x0000e9b5
#define ENTYPO_ICON_PLUS_OUTLINE                    0x0000e9b6
#define ENTYPO_ICON_PLUS_2                          0x0000e9b7
#define ENTYPO_ICON_MINUS_OUTLINE                   0x0000e9b8
#define ENTYPO_ICON_MINUS_2                         0x0000e9b9
#define ENTYPO_ICON_DIVIDE_OUTLINE                  0x0000e9ba
#define ENTYPO_ICON_DIVIDE                          0x0000e9bb
#define ENTYPO_ICON_EQ_OUTLINE                      0x0000e9bc
#define ENTYPO_ICON_EQ                              0x0000e9bd
#define ENTYPO_ICON_INFO_OUTLINE                    0x0000e9be
#define ENTYPO_ICON_INFO_2                          0x0000e9bf
#define ENTYPO_ICON_HOME_OUTLINE                    0x0000e9c0
#define ENTYPO_ICON_HOME_2                          0x0000e9c1
#define ENTYPO_ICON_LINK_OUTLINE                    0x0000e9c2
#define ENTYPO_ICON_LINK_2                          0x0000e9c3
#define ENTYPO_ICON_ATTACH_OUTLINE                  0x0000e9c4
#define ENTYPO_ICON_ATTACH_2                        0x0000e9c5
#define ENTYPO_ICON_LOCK_2                          0x0000e9c6
#define ENTYPO_ICON_LOCK_FILLED                     0x0000e9c7
#define ENTYPO_ICON_LOCK_OPEN_2                     0x0000e9c8
#define ENTYPO_ICON_LOCK_OPEN_FILLED                0x0000e9c9
#define ENTYPO_ICON_PIN_OUTLINE                     0x0000e9ca
#define ENTYPO_ICON_PIN_1                           0x0000e9cb
#define ENTYPO_ICON_EYE_OUTLINE                     0x0000e9cc
#define ENTYPO_ICON_EYE_2                           0x0000e9cd
#define ENTYPO_ICON_TAG_2                           0x0000e9ce
#define ENTYPO_ICON_TAGS_1                          0x0000e9cf
#define ENTYPO_ICON_BOOKMARK_2                      0x0000e9d0
#define ENTYPO_ICON_FLAG_2                          0x0000e9d1
#define ENTYPO_ICON_FLAG_FILLED                     0x0000e9d2
#define ENTYPO_ICON_THUMBS_UP_2                     0x0000e9d3
#define ENTYPO_ICON_THUMBS_DOWN_2                   0x0000e9d4
#define ENTYPO_ICON_DOWNLOAD_OUTLINE                0x0000e9d5
#define ENTYPO_ICON_DOWNLOAD_2                      0x0000e9d6
#define ENTYPO_ICON_UPLOAD_OUTLINE                  0x0000e9d7
#define ENTYPO_ICON_UPLOAD_2                        0x0000e9d8
#define ENTYPO_ICON_UPLOAD_CLOUD_OUTLINE            0x0000e9d9
#define ENTYPO_ICON_UPLOAD_CLOUD_2                  0x0000e9da
#define ENTYPO_ICON_REPLY_OUTLINE                   0x0000e9db
#define ENTYPO_ICON_REPLY_2                         0x0000e9dc
#define ENTYPO_ICON_FORWARD_OUTLINE                 0x0000e9dd
#define ENTYPO_ICON_FORWARD_2                       0x0000e9de
#define ENTYPO_ICON_CODE_OUTLINE                    0x0000e9df
#define ENTYPO_ICON_CODE_2                          0x0000e9e0
#define ENTYPO_ICON_EXPORT_OUTLINE                  0x0000e9e1
#define ENTYPO_ICON_EXPORT_2                        0x0000e9e2
#define ENTYPO_ICON_PENCIL_2                        0x0000e9e3
#define ENTYPO_ICON_PEN                             0x0000e9e4
#define ENTYPO_ICON_FEATHER_1                       0x0000e9e5
#define ENTYPO_ICON_EDIT_1                          0x0000e9e6
#define ENTYPO_ICON_PRINT_2                         0x0000e9e7
#define ENTYPO_ICON_COMMENT_2                       0x0000e9e8
#define ENTYPO_ICON_CHAT_2                          0x0000e9e9
#define ENTYPO_ICON_CHAT_ALT                        0x0000e9ea
#define ENTYPO_ICON_BELL_2                          0x0000e9eb
#define ENTYPO_ICON_ATTENTION_2                     0x0000e9ec
#define ENTYPO_ICON_ATTENTION_FILLED                0x0000e9ed
#define ENTYPO_ICON_WARNING_EMPTY                   0x0000e9ee
#define ENTYPO_ICON_WARNING                         0x0000e9ef
#define ENTYPO_ICON_CONTACTS                        0x0000e9f0
#define ENTYPO_ICON_VCARD_1                         0x0000e9f1
#define ENTYPO_ICON_ADDRESS_1                       0x0000e9f2
#define ENTYPO_ICON_LOCATION_OUTLINE                0x0000e9f3
#define ENTYPO_ICON_LOCATION_2                      0x0000e9f4
#define ENTYPO_ICON_MAP_2                           0x0000e9f5
#define ENTYPO_ICON_DIRECTION_OUTLINE               0x0000e9f6
#define ENTYPO_ICON_DIRECTION_2                     0x0000e9f7
#define ENTYPO_ICON_COMPASS_2                       0x0000e9f8
#define ENTYPO_ICON_TRASH_2                         0x0000e9f9
#define ENTYPO_ICON_DOC_2                           0x0000e9fa
#define ENTYPO_ICON_DOC_TEXT_2                      0x0000e9fb
#define ENTYPO_ICON_DOC_ADD                         0x0000e9fc
#define ENTYPO_ICON_DOC_REMOVE                      0x0000e9fd
#define ENTYPO_ICON_NEWS                            0x0000e9fe
#define ENTYPO_ICON_FOLDER_2                        0x0000e9ff
#define ENTYPO_ICON_FOLDER_ADD                      0x0000ea00
#define ENTYPO_ICON_FOLDER_DELETE                   0x0000ea01
#define ENTYPO_ICON_ARCHIVE_1                       0x0000ea02
#define ENTYPO_ICON_BOX_2                           0x0000ea03
#define ENTYPO_ICON_RSS_OUTLINE                     0x0000ea04
#define ENTYPO_ICON_RSS_2                           0x0000ea05
#define ENTYPO_ICON_PHONE_OUTLINE                   0x0000ea06
#define ENTYPO_ICON_PHONE_2                         0x0000ea07
#define ENTYPO_ICON_MENU_OUTLINE                    0x0000ea08
#define ENTYPO_ICON_MENU_2                          0x0000ea09
#define ENTYPO_ICON_COG_OUTLINE                     0x0000ea0a
#define ENTYPO_ICON_COG_2                           0x0000ea0b
#define ENTYPO_ICON_WRENCH_OUTLINE                  0x0000ea0c
#define ENTYPO_ICON_WRENCH_1                        0x0000ea0d
#define ENTYPO_ICON_BASKET_2                        0x0000ea0e
#define ENTYPO_ICON_CALENDAR_OUTLILNE               0x0000ea0f
#define ENTYPO_ICON_CALENDAR_2                      0x0000ea10
#define ENTYPO_ICON_MIC_OUTLINE                     0x0000ea11
#define ENTYPO_ICON_MIC_2                           0x0000ea12
#define ENTYPO_ICON_VOLUME_OFF_1                    0x0000ea13
#define ENTYPO_ICON_VOLUME_LOW                      0x0000ea14
#define ENTYPO_ICON_VOLUME_MIDDLE                   0x0000ea15
#define ENTYPO_ICON_VOLUME_HIGH                     0x0000ea16
#define ENTYPO_ICON_HEADPHONES_1                    0x0000ea17
#define ENTYPO_ICON_CLOCK_2                         0x0000ea18
#define ENTYPO_ICON_WRISTWATCH                      0x0000ea19
#define ENTYPO_ICON_STOPWATCH                       0x0000ea1a
#define ENTYPO_ICON_LIGHTBULB_1                     0x0000ea1b
#define ENTYPO_ICON_BLOCK_OUTLINE                   0x0000ea1c
#define ENTYPO_ICON_BLOCK_2                         0x0000ea1d
#define ENTYPO_ICON_RESIZE_FULL_OUTLINE             0x0000ea1e
#define ENTYPO_ICON_RESIZE_FULL_2                   0x0000ea1f
#define ENTYPO_ICON_RESIZE_NORMAL_OUTLINE           0x0000ea20
#define ENTYPO_ICON_RESIZE_NORMAL                   0x0000ea21
#define ENTYPO_ICON_MOVE_OUTLINE                    0x0000ea22
#define ENTYPO_ICON_MOVE_1                          0x0000ea23
#define ENTYPO_ICON_POPUP_1                         0x0000ea24
#define ENTYPO_ICON_ZOOM_IN_OUTLINE                 0x0000ea25
#define ENTYPO_ICON_ZOOM_IN_1                       0x0000ea26
#define ENTYPO_ICON_ZOOM_OUT_OUTLINE                0x0000ea27
#define ENTYPO_ICON_ZOOM_OUT_1                      0x0000ea28
#define ENTYPO_ICON_LEFT_OPEN_OUTLINE               0x0000ea29
#define ENTYPO_ICON_LEFT_OPEN_2                     0x0000ea2a
#define ENTYPO_ICON_RIGHT_OPEN_OUTLINE              0x0000ea2b
#define ENTYPO_ICON_RIGHT_OPEN_2                    0x0000ea2c
#define ENTYPO_ICON_DOWN_2                          0x0000ea2d
#define ENTYPO_ICON_LEFT_2                          0x0000ea2e
#define ENTYPO_ICON_RIGHT_2                         0x0000ea2f
#define ENTYPO_ICON_UP_2                            0x0000ea30
#define ENTYPO_ICON_DOWN_OUTLINE                    0x0000ea31
#define ENTYPO_ICON_LEFT_OUTLINE                    0x0000ea32
#define ENTYPO_ICON_RIGHT_OUTLINE                   0x0000ea33
#define ENTYPO_ICON_UP_OUTLINE                      0x0000ea34
#define ENTYPO_ICON_DOWN_SMALL                      0x0000ea35
#define ENTYPO_ICON_LEFT_SMALL                      0x0000ea36
#define ENTYPO_ICON_RIGHT_SMALL                     0x0000ea37
#define ENTYPO_ICON_UP_SMALL                        0x0000ea38
#define ENTYPO_ICON_CW_OUTLINE                      0x0000ea39
#define ENTYPO_ICON_CW_2                            0x0000ea3a
#define ENTYPO_ICON_ARROWS_CW_OUTLINE               0x0000ea3b
#define ENTYPO_ICON_ARROWS_CW_1                     0x0000ea3c
#define ENTYPO_ICON_LOOP_OUTLINE                    0x0000ea3d
#define ENTYPO_ICON_LOOP_1                          0x0000ea3e
#define ENTYPO_ICON_LOOP_ALT_OUTLINE                0x0000ea3f
#define ENTYPO_ICON_LOOP_ALT                        0x0000ea40
#define ENTYPO_ICON_SHUFFLE_2                       0x0000ea41
#define ENTYPO_ICON_PLAY_OUTLINE                    0x0000ea42
#define ENTYPO_ICON_PLAY_2                          0x0000ea43
#define ENTYPO_ICON_STOP_OUTLINE                    0x0000ea44
#define ENTYPO_ICON_STOP_2                          0x0000ea45
#define ENTYPO_ICON_PAUSE_OUTLINE                   0x0000ea46
#define ENTYPO_ICON_PAUSE_2                         0x0000ea47
#define ENTYPO_ICON_FAST_FW_OUTLINE                 0x0000ea48
#define ENTYPO_ICON_FAST_FW_1                       0x0000ea49
#define ENTYPO_ICON_REWIND_OUTLINE                  0x0000ea4a
#define ENTYPO_ICON_REWIND                          0x0000ea4b
#define ENTYPO_ICON_RECORD_OUTLINE                  0x0000ea4c
#define ENTYPO_ICON_RECORD_1                        0x0000ea4d
#define ENTYPO_ICON_EJECT_OUTLINE                   0x0000ea4e
#define ENTYPO_ICON_EJECT_1                         0x0000ea4f
#define ENTYPO_ICON_EJECT_ALT_OUTLINE               0x0000ea50
#define ENTYPO_ICON_EJECT_ALT                       0x0000ea51
#define ENTYPO_ICON_BAT1                            0x0000ea52
#define ENTYPO_ICON_BAT2                            0x0000ea53
#define ENTYPO_ICON_BAT3                            0x0000ea54
#define ENTYPO_ICON_BAT4                            0x0000ea55
#define ENTYPO_ICON_BAT_CHARGE                      0x0000ea56
#define ENTYPO_ICON_PLUG_1                          0x0000ea57
#define ENTYPO_ICON_TARGET_OUTLINE                  0x0000ea58
#define ENTYPO_ICON_TARGET_2                        0x0000ea59
#define ENTYPO_ICON_WIFI_OUTLINE                    0x0000ea5a
#define ENTYPO_ICON_WIFI_1                          0x0000ea5b
#define ENTYPO_ICON_DESKTOP_1                       0x0000ea5c
#define ENTYPO_ICON_LAPTOP_1                        0x0000ea5d
#define ENTYPO_ICON_TABLET_1                        0x0000ea5e
#define ENTYPO_ICON_MOBILE_2                        0x0000ea5f
#define ENTYPO_ICON_CONTRAST                        0x0000ea60
#define ENTYPO_ICON_GLOBE_OUTLINE                   0x0000ea61
#define ENTYPO_ICON_GLOBE_2                         0x0000ea62
#define ENTYPO_ICON_GLOBE_ALT_OUTLINE               0x0000ea63
#define ENTYPO_ICON_GLOBE_ALT                       0x0000ea64
#define ENTYPO_ICON_SUN_1                           0x0000ea65
#define ENTYPO_ICON_SUN_FILLED                      0x0000ea66
#define ENTYPO_ICON_CLOUD_2                         0x0000ea67
#define ENTYPO_ICON_FLASH_OUTLINE                   0x0000ea68
#define ENTYPO_ICON_FLASH_2                         0x0000ea69
#define ENTYPO_ICON_MOON_2                          0x0000ea6a
#define ENTYPO_ICON_WAVES_OUTLINE                   0x0000ea6b
#define ENTYPO_ICON_WAVES                           0x0000ea6c
#define ENTYPO_ICON_RAIN                            0x0000ea6d
#define ENTYPO_ICON_CLOUD_SUN                       0x0000ea6e
#define ENTYPO_ICON_DRIZZLE                         0x0000ea6f
#define ENTYPO_ICON_SNOW                            0x0000ea70
#define ENTYPO_ICON_CLOUD_FLASH                     0x0000ea71
#define ENTYPO_ICON_CLOUD_WIND                      0x0000ea72
#define ENTYPO_ICON_WIND                            0x0000ea73
#define ENTYPO_ICON_PLANE_OUTLINE                   0x0000ea74
#define ENTYPO_ICON_PLANE                           0x0000ea75
#define ENTYPO_ICON_LEAF_2                          0x0000ea76
#define ENTYPO_ICON_LIFEBUOY_2                      0x0000ea77
#define ENTYPO_ICON_BRIEFCASE_2                     0x0000ea78
#define ENTYPO_ICON_BRUSH_2                         0x0000ea79
#define ENTYPO_ICON_PIPETTE                         0x0000ea7a
#define ENTYPO_ICON_POWER_OUTLINE                   0x0000ea7b
#define ENTYPO_ICON_POWER                           0x0000ea7c
#define ENTYPO_ICON_CHECK_OUTLINE                   0x0000ea7d
#define ENTYPO_ICON_CHECK_2                         0x0000ea7e
#define ENTYPO_ICON_GIFT_1                          0x0000ea7f
#define ENTYPO_ICON_TEMPERATIRE                     0x0000ea80
#define ENTYPO_ICON_CHART_OUTLINE                   0x0000ea81
#define ENTYPO_ICON_CHART                           0x0000ea82
#define ENTYPO_ICON_CHART_ALT_OUTLINE               0x0000ea83
#define ENTYPO_ICON_CHART_ALT                       0x0000ea84
#define ENTYPO_ICON_CHART_BAR_OUTLINE               0x0000ea85
#define ENTYPO_ICON_CHART_BAR_2                     0x0000ea86
#define ENTYPO_ICON_CHART_PIE_OUTLINE               0x0000ea87
#define ENTYPO_ICON_CHART_PIE_2                     0x0000ea88
#define ENTYPO_ICON_TICKET_2                        0x0000ea89
#define ENTYPO_ICON_CREDIT_CARD_2                   0x0000ea8a
#define ENTYPO_ICON_CLIPBOARD_1                     0x0000ea8b
#define ENTYPO_ICON_DATABASE_2                      0x0000ea8c
#define ENTYPO_ICON_KEY_OUTLINE                     0x0000ea8d
#define ENTYPO_ICON_KEY_2                           0x0000ea8e
#define ENTYPO_ICON_FLOW_SPLIT                      0x0000ea8f
#define ENTYPO_ICON_FLOW_MERGE                      0x0000ea90
#define ENTYPO_ICON_FLOW_PARALLEL_1                 0x0000ea91
#define ENTYPO_ICON_FLOW_CROSS                      0x0000ea92
#define ENTYPO_ICON_CERTIFICATE_OUTLINE             0x0000ea93
#define ENTYPO_ICON_CERTIFICATE_1                   0x0000ea94
#define ENTYPO_ICON_SCISSORS_OUTLINE                0x0000ea95
#define ENTYPO_ICON_SCISSORS_1                      0x0000ea96
#define ENTYPO_ICON_FLASK                           0x0000ea97
#define ENTYPO_ICON_WINE                            0x0000ea98
#define ENTYPO_ICON_COFFEE_1                        0x0000ea99
#define ENTYPO_ICON_BEER_1                          0x0000ea9a
#define ENTYPO_ICON_ANCHOR_OUTLINE                  0x0000ea9b
#define ENTYPO_ICON_ANCHOR_1                        0x0000ea9c
#define ENTYPO_ICON_PUZZLE_OUTLINE                  0x0000ea9d
#define ENTYPO_ICON_PUZZLE_1                        0x0000ea9e
#define ENTYPO_ICON_TREE_1                          0x0000ea9f
#define ENTYPO_ICON_CALCULATOR                      0x0000eaa0
#define ENTYPO_ICON_INFINITY_OUTLINE                0x0000eaa1
#define ENTYPO_ICON_INFINITY_1                      0x0000eaa2
#define ENTYPO_ICON_PI_OUTLINE                      0x0000eaa3
#define ENTYPO_ICON_PI                              0x0000eaa4
#define ENTYPO_ICON_AT_1                            0x0000eaa5
#define ENTYPO_ICON_AT_CIRCLED                      0x0000eaa6
#define ENTYPO_ICON_LOOPED_SQUARE_OUTLINE           0x0000eaa7
#define ENTYPO_ICON_LOOPED_SQUARE_INTEREST          0x0000eaa8
#define ENTYPO_ICON_SORT_ALPHABET_OUTLINE           0x0000eaa9
#define ENTYPO_ICON_SORT_ALPHABET                   0x0000eaaa
#define ENTYPO_ICON_SORT_NUMERIC_OUTLINE            0x0000eaab
#define ENTYPO_ICON_SORT_NUMERIC                    0x0000eaac
#define ENTYPO_ICON_DRIBBBLE_CIRCLED_1              0x0000eaad
#define ENTYPO_ICON_DRIBBBLE_2                      0x0000eaae
#define ENTYPO_ICON_FACEBOOK_CIRCLED_1              0x0000eaaf
#define ENTYPO_ICON_FACEBOOK_2                      0x0000eab0
#define ENTYPO_ICON_FLICKR_CIRCLED_1                0x0000eab1
#define ENTYPO_ICON_FLICKR_2                        0x0000eab2
#define ENTYPO_ICON_GITHUB_CIRCLED_2                0x0000eab3
#define ENTYPO_ICON_GITHUB_2                        0x0000eab4
#define ENTYPO_ICON_LASTFM_CIRCLED_1                0x0000eab5
#define ENTYPO_ICON_LASTFM_2                        0x0000eab6
#define ENTYPO_ICON_LINKEDIN_CIRCLED_1              0x0000eab7
#define ENTYPO_ICON_LINKEDIN_2                      0x0000eab8
#define ENTYPO_ICON_PINTEREST_CIRCLED_2             0x0000eab9
#define ENTYPO_ICON_PINTEREST_2                     0x0000eaba
#define ENTYPO_ICON_SKYPE_OUTLINE                   0x0000eabb
#define ENTYPO_ICON_SKYPE_2                         0x0000eabc
#define ENTYPO_ICON_TUMBLER_CIRCLED                 0x0000eabd
#define ENTYPO_ICON_TUMBLER                         0x0000eabe
#define ENTYPO_ICON_TWITTER_CIRCLED_1               0x0000eabf
#define ENTYPO_ICON_TWITTER_2                       0x0000eac0
#define ENTYPO_ICON_VIMEO_CIRCLED_1                 0x0000eac1
#define ENTYPO_ICON_VIMEO_2                         0x0000eac2
#define ENTYPO_ICON_SEARCH_3                        0x0000eac3
#define ENTYPO_ICON_MAIL_3                          0x0000eac4
#define ENTYPO_ICON_HEART_3                         0x0000eac5
#define ENTYPO_ICON_HEART_EMPTY_2                   0x0000eac6
#define ENTYPO_ICON_STAR_3                          0x0000eac7
#define ENTYPO_ICON_USER_3                          0x0000eac8
#define ENTYPO_ICON_VIDEO_3                         0x0000eac9
#define ENTYPO_ICON_PICTURE_3                       0x0000eaca
#define ENTYPO_ICON_CAMERA_3                        0x0000eacb
#define ENTYPO_ICON_OK_2                            0x0000eacc
#define ENTYPO_ICON_OK_CIRCLE                       0x0000eacd
#define ENTYPO_ICON_CANCEL_3                        0x0000eace
#define ENTYPO_ICON_CANCEL_CIRCLE                   0x0000eacf
#define ENTYPO_ICON_PLUS_3                          0x0000ead0
#define ENTYPO_ICON_PLUS_CIRCLE                     0x0000ead1
#define ENTYPO_ICON_MINUS_3                         0x0000ead2
#define ENTYPO_ICON_MINUS_CIRCLE                    0x0000ead3
#define ENTYPO_ICON_HELP_2                          0x0000ead4
#define ENTYPO_ICON_INFO_3                          0x0000ead5
#define ENTYPO_ICON_HOME_3                          0x0000ead6
#define ENTYPO_ICON_LINK_3                          0x0000ead7
#define ENTYPO_ICON_ATTACH_3                        0x0000ead8
#define ENTYPO_ICON_LOCK_3                          0x0000ead9
#define ENTYPO_ICON_LOCK_EMPTY                      0x0000eada
#define ENTYPO_ICON_LOCK_OPEN_3                     0x0000eadb
#define ENTYPO_ICON_LOCK_OPEN_EMPTY                 0x0000eadc
#define ENTYPO_ICON_PIN_2                           0x0000eadd
#define ENTYPO_ICON_EYE_3                           0x0000eade
#define ENTYPO_ICON_TAG_3                           0x0000eadf
#define ENTYPO_ICON_TAG_EMPTY                       0x0000eae0
#define ENTYPO_ICON_DOWNLOAD_3                      0x0000eae1
#define ENTYPO_ICON_UPLOAD_3                        0x0000eae2
#define ENTYPO_ICON_DOWNLOAD_CLOUD_1                0x0000eae3
#define ENTYPO_ICON_UPLOAD_CLOUD_3                  0x0000eae4
#define ENTYPO_ICON_QUOTE_LEFT_1                    0x0000eae5
#define ENTYPO_ICON_QUOTE_RIGHT_1                   0x0000eae6
#define ENTYPO_ICON_QUOTE_LEFT_ALT                  0x0000eae7
#define ENTYPO_ICON_QUOTE_RIGHT_ALT                 0x0000eae8
#define ENTYPO_ICON_PENCIL_3                        0x0000eae9
#define ENTYPO_ICON_PENCIL_NEG                      0x0000eaea
#define ENTYPO_ICON_PENCIL_ALT                      0x0000eaeb
#define ENTYPO_ICON_UNDO                            0x0000eaec
#define ENTYPO_ICON_COMMENT_3                       0x0000eaed
#define ENTYPO_ICON_COMMENT_INV                     0x0000eaee
#define ENTYPO_ICON_COMMENT_ALT                     0x0000eaef
#define ENTYPO_ICON_COMMENT_INV_ALT                 0x0000eaf0
#define ENTYPO_ICON_COMMENT_ALT2                    0x0000eaf1
#define ENTYPO_ICON_COMMENT_INV_ALT2                0x0000eaf2
#define ENTYPO_ICON_CHAT_3                          0x0000eaf3
#define ENTYPO_ICON_CHAT_INV                        0x0000eaf4
#define ENTYPO_ICON_LOCATION_3                      0x0000eaf5
#define ENTYPO_ICON_LOCATION_INV                    0x0000eaf6
#define ENTYPO_ICON_LOCATION_ALT                    0x0000eaf7
#define ENTYPO_ICON_COMPASS_3                       0x0000eaf8
#define ENTYPO_ICON_TRASH_3                         0x0000eaf9
#define ENTYPO_ICON_TRASH_EMPTY_1                   0x0000eafa
#define ENTYPO_ICON_DOC_3                           0x0000eafb
#define ENTYPO_ICON_DOC_INV_1                       0x0000eafc
#define ENTYPO_ICON_DOC_ALT                         0x0000eafd
#define ENTYPO_ICON_DOC_INV_ALT                     0x0000eafe
#define ENTYPO_ICON_ARTICLE                         0x0000eaff
#define ENTYPO_ICON_ARTICLE_ALT                     0x0000eb00
#define ENTYPO_ICON_BOOK_OPEN_1                     0x0000eb01
#define ENTYPO_ICON_FOLDER_3                        0x0000eb02
#define ENTYPO_ICON_FOLDER_EMPTY_1                  0x0000eb03
#define ENTYPO_ICON_BOX_3                           0x0000eb04
#define ENTYPO_ICON_RSS_3                           0x0000eb05
#define ENTYPO_ICON_RSS_ALT                         0x0000eb06
#define ENTYPO_ICON_COG_3                           0x0000eb07
#define ENTYPO_ICON_WRENCH_2                        0x0000eb08
#define ENTYPO_ICON_SHARE_2                         0x0000eb09
#define ENTYPO_ICON_CALENDAR_3                      0x0000eb0a
#define ENTYPO_ICON_CALENDAR_INV                    0x0000eb0b
#define ENTYPO_ICON_CALENDAR_ALT                    0x0000eb0c
#define ENTYPO_ICON_MIC_3                           0x0000eb0d
#define ENTYPO_ICON_VOLUME_OFF_2                    0x0000eb0e
#define ENTYPO_ICON_VOLUME_UP_1                     0x0000eb0f
#define ENTYPO_ICON_HEADPHONES_2                    0x0000eb10
#define ENTYPO_ICON_CLOCK_3                         0x0000eb11
#define ENTYPO_ICON_LAMP_1                          0x0000eb12
#define ENTYPO_ICON_BLOCK_3                         0x0000eb13
#define ENTYPO_ICON_RESIZE_FULL_3                   0x0000eb14
#define ENTYPO_ICON_RESIZE_FULL_ALT_1               0x0000eb15
#define ENTYPO_ICON_RESIZE_SMALL_2                  0x0000eb16
#define ENTYPO_ICON_RESIZE_SMALL_ALT                0x0000eb17
#define ENTYPO_ICON_RESIZE_VERTICAL_1               0x0000eb18
#define ENTYPO_ICON_RESIZE_HORIZONTAL_1             0x0000eb19
#define ENTYPO_ICON_MOVE_2                          0x0000eb1a
#define ENTYPO_ICON_POPUP_3                         0x0000eb1b
#define ENTYPO_ICON_DOWN_3                          0x0000eb1c
#define ENTYPO_ICON_LEFT_3                          0x0000eb1d
#define ENTYPO_ICON_RIGHT_3                         0x0000eb1e
#define ENTYPO_ICON_UP_3                            0x0000eb1f
#define ENTYPO_ICON_DOWN_CIRCLE                     0x0000eb20
#define ENTYPO_ICON_LEFT_CIRCLE                     0x0000eb21
#define ENTYPO_ICON_RIGHT_CIRCLE                    0x0000eb22
#define ENTYPO_ICON_UP_CIRCLE                       0x0000eb23
#define ENTYPO_ICON_CW_3                            0x0000eb24
#define ENTYPO_ICON_LOOP_2                          0x0000eb25
#define ENTYPO_ICON_LOOP_ALT_1                      0x0000eb26
#define ENTYPO_ICON_EXCHANGE_1                      0x0000eb27
#define ENTYPO_ICON_SPLIT                           0x0000eb28
#define ENTYPO_ICON_ARROW_CURVED                    0x0000eb29
#define ENTYPO_ICON_PLAY_3                          0x0000eb2a
#define ENTYPO_ICON_PLAY_CIRCLE2                    0x0000eb2b
#define ENTYPO_ICON_STOP_3                          0x0000eb2c
#define ENTYPO_ICON_PAUSE_3                         0x0000eb2d
#define ENTYPO_ICON_TO_START_2                      0x0000eb2e
#define ENTYPO_ICON_TO_END_2                        0x0000eb2f
#define ENTYPO_ICON_EJECT_2                         0x0000eb30
#define ENTYPO_ICON_TARGET_3                        0x0000eb31
#define ENTYPO_ICON_SIGNAL_2                        0x0000eb32
#define ENTYPO_ICON_AWARD_1                         0x0000eb33
#define ENTYPO_ICON_AWARD_EMPTY                     0x0000eb34
#define ENTYPO_ICON_LIST_2                          0x0000eb35
#define ENTYPO_ICON_LIST_NESTED                     0x0000eb36
#define ENTYPO_ICON_BAT_EMPTY                       0x0000eb37
#define ENTYPO_ICON_BAT_HALF                        0x0000eb38
#define ENTYPO_ICON_BAT_FULL                        0x0000eb39
#define ENTYPO_ICON_BAT_CHARGE_1                    0x0000eb3a
#define ENTYPO_ICON_MOBILE_3                        0x0000eb3b
#define ENTYPO_ICON_CD_1                            0x0000eb3c
#define ENTYPO_ICON_EQUALIZER                       0x0000eb3d
#define ENTYPO_ICON_CURSOR                          0x0000eb3e
#define ENTYPO_ICON_APERTURE                        0x0000eb3f
#define ENTYPO_ICON_APERTURE_ALT                    0x0000eb40
#define ENTYPO_ICON_STEERING_WHEEL                  0x0000eb41
#define ENTYPO_ICON_BOOK_2                          0x0000eb42
#define ENTYPO_ICON_BOOK_ALT                        0x0000eb43
#define ENTYPO_ICON_BRUSH_3                         0x0000eb44
#define ENTYPO_ICON_BRUSH_ALT                       0x0000eb45
#define ENTYPO_ICON_EYEDROPPER_1                    0x0000eb46
#define ENTYPO_ICON_LAYERS                          0x0000eb47
#define ENTYPO_ICON_LAYERS_ALT                      0x0000eb48
#define ENTYPO_ICON_SUN_2                           0x0000eb49
#define ENTYPO_ICON_SUN_INV                         0x0000eb4a
#define ENTYPO_ICON_CLOUD_3                         0x0000eb4b
#define ENTYPO_ICON_RAIN_1                          0x0000eb4c
#define ENTYPO_ICON_FLASH_3                         0x0000eb4d
#define ENTYPO_ICON_MOON_3                          0x0000eb4e
#define ENTYPO_ICON_MOON_INV                        0x0000eb4f
#define ENTYPO_ICON_UMBRELLA_1                      0x0000eb50
#define ENTYPO_ICON_CHART_BAR_3                     0x0000eb51
#define ENTYPO_ICON_CHART_PIE_3                     0x0000eb52
#define ENTYPO_ICON_CHART_PIE_ALT                   0x0000eb53
#define ENTYPO_ICON_KEY_3                           0x0000eb54
#define ENTYPO_ICON_KEY_INV                         0x0000eb55
#define ENTYPO_ICON_HASH                            0x0000eb56
#define ENTYPO_ICON_AT_2                            0x0000eb57
#define ENTYPO_ICON_PILCROW                         0x0000eb58
#define ENTYPO_ICON_DIAL                            0x0000eb59
#define ENTYPO_ICON_SEARCH_4                        0x0000eb5a
#define ENTYPO_ICON_MAIL_4                          0x0000eb5b
#define ENTYPO_ICON_HEART_4                         0x0000eb5c
#define ENTYPO_ICON_STAR_4                          0x0000eb5d
#define ENTYPO_ICON_USER_4                          0x0000eb5e
#define ENTYPO_ICON_USER_WOMAN                      0x0000eb5f
#define ENTYPO_ICON_USER_PAIR                       0x0000eb60
#define ENTYPO_ICON_VIDEO_ALT                       0x0000eb61
#define ENTYPO_ICON_VIDEOCAM_2                      0x0000eb62
#define ENTYPO_ICON_VIDEOCAM_ALT                    0x0000eb63
#define ENTYPO_ICON_CAMERA_4                        0x0000eb64
#define ENTYPO_ICON_TH_2                            0x0000eb65
#define ENTYPO_ICON_TH_LIST_2                       0x0000eb66
#define ENTYPO_ICON_OK_3                            0x0000eb67
#define ENTYPO_ICON_CANCEL_4                        0x0000eb68
#define ENTYPO_ICON_CANCEL_CIRCLE_1                 0x0000eb69
#define ENTYPO_ICON_PLUS_4                          0x0000eb6a
#define ENTYPO_ICON_HOME_4                          0x0000eb6b
#define ENTYPO_ICON_LOCK_4                          0x0000eb6c
#define ENTYPO_ICON_LOCK_OPEN_4                     0x0000eb6d
#define ENTYPO_ICON_EYE_4                           0x0000eb6e
#define ENTYPO_ICON_TAG_4                           0x0000eb6f
#define ENTYPO_ICON_THUMBS_UP_3                     0x0000eb70
#define ENTYPO_ICON_THUMBS_DOWN_3                   0x0000eb71
#define ENTYPO_ICON_DOWNLOAD_4                      0x0000eb72
#define ENTYPO_ICON_EXPORT_3                        0x0000eb73
#define ENTYPO_ICON_PENCIL_4                        0x0000eb74
#define ENTYPO_ICON_PENCIL_ALT_1                    0x0000eb75
#define ENTYPO_ICON_EDIT_2                          0x0000eb76
#define ENTYPO_ICON_CHAT_4                          0x0000eb77
#define ENTYPO_ICON_PRINT_3                         0x0000eb78
#define ENTYPO_ICON_BELL_3                          0x0000eb79
#define ENTYPO_ICON_ATTENTION_3                     0x0000eb7a
#define ENTYPO_ICON_INFO_4                          0x0000eb7b
#define ENTYPO_ICON_QUESTION                        0x0000eb7c
#define ENTYPO_ICON_LOCATION_4                      0x0000eb7d
#define ENTYPO_ICON_TRASH_4                         0x0000eb7e
#define ENTYPO_ICON_DOC_4                           0x0000eb7f
#define ENTYPO_ICON_ARTICLE_1                       0x0000eb80
#define ENTYPO_ICON_ARTICLE_ALT_1                   0x0000eb81
#define ENTYPO_ICON_RSS_4                           0x0000eb82
#define ENTYPO_ICON_WRENCH_3                        0x0000eb83
#define ENTYPO_ICON_BASKET_3                        0x0000eb84
#define ENTYPO_ICON_BASKET_ALT                      0x0000eb85
#define ENTYPO_ICON_CALENDAR_4                      0x0000eb86
#define ENTYPO_ICON_CALENDAR_ALT_1                  0x0000eb87
#define ENTYPO_ICON_VOLUME_OFF_3                    0x0000eb88
#define ENTYPO_ICON_VOLUME_DOWN_1                   0x0000eb89
#define ENTYPO_ICON_VOLUME_UP_2                     0x0000eb8a
#define ENTYPO_ICON_BULLHORN                        0x0000eb8b
#define ENTYPO_ICON_CLOCK_4                         0x0000eb8c
#define ENTYPO_ICON_CLOCK_ALT                       0x0000eb8d
#define ENTYPO_ICON_STOP_4                          0x0000eb8e
#define ENTYPO_ICON_RESIZE_FULL_4                   0x0000eb8f
#define ENTYPO_ICON_RESIZE_SMALL_3                  0x0000eb90
#define ENTYPO_ICON_ZOOM_IN_2                       0x0000eb91
#define ENTYPO_ICON_ZOOM_OUT_2                      0x0000eb92
#define ENTYPO_ICON_POPUP_4                         0x0000eb93
#define ENTYPO_ICON_DOWN_DIR_2                      0x0000eb94
#define ENTYPO_ICON_LEFT_DIR_2                      0x0000eb95
#define ENTYPO_ICON_RIGHT_DIR_2                     0x0000eb96
#define ENTYPO_ICON_UP_DIR_2                        0x0000eb97
#define ENTYPO_ICON_DOWN_4                          0x0000eb98
#define ENTYPO_ICON_UP_4                            0x0000eb99
#define ENTYPO_ICON_CW_4                            0x0000eb9a
#define ENTYPO_ICON_SIGNAL_3                        0x0000eb9b
#define ENTYPO_ICON_AWARD_2                         0x0000eb9c
#define ENTYPO_ICON_MOBILE_4                        0x0000eb9d
#define ENTYPO_ICON_MOBILE_ALT                      0x0000eb9e
#define ENTYPO_ICON_TABLET_2                        0x0000eb9f
#define ENTYPO_ICON_IPOD                            0x0000eba0
#define ENTYPO_ICON_CD_2                            0x0000eba1
#define ENTYPO_ICON_GRID                            0x0000eba2
#define ENTYPO_ICON_BOOK_3                          0x0000eba3
#define ENTYPO_ICON_EASEL                           0x0000eba4
#define ENTYPO_ICON_GLOBE_3                         0x0000eba5
#define ENTYPO_ICON_CHART_1                         0x0000eba6
#define ENTYPO_ICON_CHART_BAR_4                     0x0000eba7
#define ENTYPO_ICON_CHART_PIE_4                     0x0000eba8
#define ENTYPO_ICON_DOLLAR_1                        0x0000eba9
#define ENTYPO_ICON_AT_3                            0x0000ebaa
#define ENTYPO_ICON_COLON                           0x0000ebab
#define ENTYPO_ICON_SEMICOLON                       0x0000ebac
#define ENTYPO_ICON_MONEY_1                         0x0000ebad
#define ENTYPO_ICON_FACEBOOK_3                      0x0000ebae
#define ENTYPO_ICON_FACEBOOK_RECT                   0x0000ebaf
#define ENTYPO_ICON_TWITTER_BIRD                    0x0000ebb0
#define ENTYPO_ICON_YOUTUBE_1                       0x0000ebb1
#define ENTYPO_ICON_WINDY_RAIN_INV                  0x0000ebb2
#define ENTYPO_ICON_SNOW_INV                        0x0000ebb3
#define ENTYPO_ICON_SNOW_HEAVY_INV                  0x0000ebb4
#define ENTYPO_ICON_HAIL_INV                        0x0000ebb5
#define ENTYPO_ICON_CLOUDS_INV                      0x0000ebb6
#define ENTYPO_ICON_CLOUDS_FLASH_INV                0x0000ebb7
#define ENTYPO_ICON_TEMPERATURE                     0x0000ebb8
#define ENTYPO_ICON_COMPASS_4                       0x0000ebb9
#define ENTYPO_ICON_NA                              0x0000ebba
#define ENTYPO_ICON_CELCIUS                         0x0000ebbb
#define ENTYPO_ICON_FAHRENHEIT                      0x0000ebbc
#define ENTYPO_ICON_CLOUDS_FLASH_ALT                0x0000ebbd
#define ENTYPO_ICON_SUN_INV_1                       0x0000ebbe
#define ENTYPO_ICON_MOON_INV_1                      0x0000ebbf
#define ENTYPO_ICON_CLOUD_SUN_INV                   0x0000ebc0
#define ENTYPO_ICON_CLOUD_MOON_INV                  0x0000ebc1
#define ENTYPO_ICON_CLOUD_INV                       0x0000ebc2
#define ENTYPO_ICON_CLOUD_FLASH_INV                 0x0000ebc3
#define ENTYPO_ICON_DRIZZLE_INV                     0x0000ebc4
#define ENTYPO_ICON_RAIN_INV                        0x0000ebc5
#define ENTYPO_ICON_WINDY_INV                       0x0000ebc6
#define ENTYPO_ICON_SUNRISE                         0x0000ebc7
#define ENTYPO_ICON_SUN_3                           0x0000ebc8
#define ENTYPO_ICON_MOON_4                          0x0000ebc9
#define ENTYPO_ICON_ECLIPSE                         0x0000ebca
#define ENTYPO_ICON_MIST                            0x0000ebcb
#define ENTYPO_ICON_WIND_1                          0x0000ebcc
#define ENTYPO_ICON_SNOWFLAKE                       0x0000ebcd
#define ENTYPO_ICON_CLOUD_SUN_1                     0x0000ebce
#define ENTYPO_ICON_CLOUD_MOON                      0x0000ebcf
#define ENTYPO_ICON_FOG_SUN                         0x0000ebd0
#define ENTYPO_ICON_FOG_MOON                        0x0000ebd1
#define ENTYPO_ICON_FOG_CLOUD                       0x0000ebd2
#define ENTYPO_ICON_FOG                             0x0000ebd3
#define ENTYPO_ICON_CLOUD_4                         0x0000ebd4
#define ENTYPO_ICON_CLOUD_FLASH_1                   0x0000ebd5
#define ENTYPO_ICON_CLOUD_FLASH_ALT                 0x0000ebd6
#define ENTYPO_ICON_DRIZZLE_1                       0x0000ebd7
#define ENTYPO_ICON_RAIN_2                          0x0000ebd8
#define ENTYPO_ICON_WINDY                           0x0000ebd9
#define ENTYPO_ICON_WINDY_RAIN                      0x0000ebda
#define ENTYPO_ICON_SNOW_1                          0x0000ebdb
#define ENTYPO_ICON_SNOW_ALT                        0x0000ebdc
#define ENTYPO_ICON_SNOW_HEAVY                      0x0000ebdd
#define ENTYPO_ICON_HAIL                            0x0000ebde
#define ENTYPO_ICON_CLOUDS                          0x0000ebdf
#define ENTYPO_ICON_CLOUDS_FLASH                    0x0000ebe0
#define ENTYPO_ICON_MAIL_5                          0x0000ebe1
#define ENTYPO_ICON_HEART_5                         0x0000ebe2
#define ENTYPO_ICON_STAR_5                          0x0000ebe3
#define ENTYPO_ICON_STAR_EMPTY_2                    0x0000ebe4
#define ENTYPO_ICON_OK_4                            0x0000ebe5
#define ENTYPO_ICON_CANCEL_5                        0x0000ebe6
#define ENTYPO_ICON_PLUS_5                          0x0000ebe7
#define ENTYPO_ICON_HELP_CIRCLED_2                  0x0000ebe8
#define ENTYPO_ICON_HELP_CIRCLED_ALT                0x0000ebe9
#define ENTYPO_ICON_HOME_5                          0x0000ebea
#define ENTYPO_ICON_PENCIL_5                        0x0000ebeb
#define ENTYPO_ICON_ATTENTION_4                     0x0000ebec
#define ENTYPO_ICON_ATTENTION_ALT_1                 0x0000ebed
#define ENTYPO_ICON_COG_4                           0x0000ebee
#define ENTYPO_ICON_MIC_OFF                         0x0000ebef
#define ENTYPO_ICON_CLOCK_5                         0x0000ebf0
#define ENTYPO_ICON_STOPWATCH_1                     0x0000ebf1
#define ENTYPO_ICON_HOURGLASS_5                     0x0000ebf2
#define ENTYPO_ICON_DOWN_5                          0x0000ebf3
#define ENTYPO_ICON_LEFT_4                          0x0000ebf4
#define ENTYPO_ICON_RIGHT_4                         0x0000ebf5
#define ENTYPO_ICON_UP_5                            0x0000ebf6
#define ENTYPO_ICON_DOWN_BOLD_1                     0x0000ebf7
#define ENTYPO_ICON_LEFT_BOLD_1                     0x0000ebf8
#define ENTYPO_ICON_RIGHT_BOLD_1                    0x0000ebf9
#define ENTYPO_ICON_UP_BOLD_1                       0x0000ebfa
#define ENTYPO_ICON_DOWN_FAT                        0x0000ebfb
#define ENTYPO_ICON_LEFT_FAT                        0x0000ebfc
#define ENTYPO_ICON_RIGHT_FAT                       0x0000ebfd
#define ENTYPO_ICON_UP_FAT                          0x0000ebfe
#define ENTYPO_ICON_FLASH_4                         0x0000ebff
#define ENTYPO_ICON_CLOUD_5                         0x0000ec00
#define ENTYPO_ICON_VECTOR_PENCIL                   0x0000ec01
#define ENTYPO_ICON_AT_4                            0x0000ec02
#define ENTYPO_ICON_FEMALE_1                        0x0000ec03
#define ENTYPO_ICON_MALE_1                          0x0000ec04
#define ENTYPO_ICON_KING                            0x0000ec05
#define ENTYPO_ICON_ANCHOR_2                        0x0000ec06
#define ENTYPO_ICON_ABOVEGROUND_RAIL                0x0000ec07
#define ENTYPO_ICON_AIRFIELD                        0x0000ec08
#define ENTYPO_ICON_AIRPORT                         0x0000ec09
#define ENTYPO_ICON_ART_GALLERY                     0x0000ec0a
#define ENTYPO_ICON_BAR                             0x0000ec0b
#define ENTYPO_ICON_BASEBALL                        0x0000ec0c
#define ENTYPO_ICON_BASKETBALL                      0x0000ec0d
#define ENTYPO_ICON_BEER_2                          0x0000ec0e
#define ENTYPO_ICON_BELOWGROUND_RAIL                0x0000ec0f
#define ENTYPO_ICON_BICYCLE_1                       0x0000ec10
#define ENTYPO_ICON_BUS_1                           0x0000ec11
#define ENTYPO_ICON_CAFE                            0x0000ec12
#define ENTYPO_ICON_CAMPSITE                        0x0000ec13
#define ENTYPO_ICON_CEMETERY                        0x0000ec14
#define ENTYPO_ICON_CINEMA                          0x0000ec15
#define ENTYPO_ICON_COLLEGE                         0x0000ec16
#define ENTYPO_ICON_COMMERICAL_BUILDING             0x0000ec17
#define ENTYPO_ICON_CREDIT_CARD_3                   0x0000ec18
#define ENTYPO_ICON_CRICKET                         0x0000ec19
#define ENTYPO_ICON_EMBASSY                         0x0000ec1a
#define ENTYPO_ICON_FAST_FOOD                       0x0000ec1b
#define ENTYPO_ICON_FERRY                           0x0000ec1c
#define ENTYPO_ICON_FIRE_STATION                    0x0000ec1d
#define ENTYPO_ICON_FOOTBALL                        0x0000ec1e
#define ENTYPO_ICON_FUEL                            0x0000ec1f
#define ENTYPO_ICON_GARDEN                          0x0000ec20
#define ENTYPO_ICON_GIRAFFE                         0x0000ec21
#define ENTYPO_ICON_GOLF                            0x0000ec22
#define ENTYPO_ICON_GROCERY_STORE                   0x0000ec23
#define ENTYPO_ICON_HARBOR                          0x0000ec24
#define ENTYPO_ICON_HELIPORT                        0x0000ec25
#define ENTYPO_ICON_HOSPITAL_1                      0x0000ec26
#define ENTYPO_ICON_INDUSTRIAL_BUILDING             0x0000ec27
#define ENTYPO_ICON_LIBRARY                         0x0000ec28
#define ENTYPO_ICON_LODGING                         0x0000ec29
#define ENTYPO_ICON_LONDON_UNDERGROUND              0x0000ec2a
#define ENTYPO_ICON_MINEFIELD                       0x0000ec2b
#define ENTYPO_ICON_MONUMENT                        0x0000ec2c
#define ENTYPO_ICON_MUSEUM                          0x0000ec2d
#define ENTYPO_ICON_PHARMACY                        0x0000ec2e
#define ENTYPO_ICON_PITCH                           0x0000ec2f
#define ENTYPO_ICON_POLICE                          0x0000ec30
#define ENTYPO_ICON_POST                            0x0000ec31
#define ENTYPO_ICON_PRISON                          0x0000ec32
#define ENTYPO_ICON_RAIL                            0x0000ec33
#define ENTYPO_ICON_RELIGIOUS_CHRISTIAN             0x0000ec34
#define ENTYPO_ICON_RELIGIOUS_ISLAM                 0x0000ec35
#define ENTYPO_ICON_RELIGIOUS_JEWISH                0x0000ec36
#define ENTYPO_ICON_RESTAURANT                      0x0000ec37
#define ENTYPO_ICON_ROADBLOCK                       0x0000ec38
#define ENTYPO_ICON_SCHOOL                          0x0000ec39
#define ENTYPO_ICON_SHOP                            0x0000ec3a
#define ENTYPO_ICON_SKIING                          0x0000ec3b
#define ENTYPO_ICON_SOCCER                          0x0000ec3c
#define ENTYPO_ICON_SWIMMING                        0x0000ec3d
#define ENTYPO_ICON_TENNIS                          0x0000ec3e
#define ENTYPO_ICON_THEATRE                         0x0000ec3f
#define ENTYPO_ICON_TOILET                          0x0000ec40
#define ENTYPO_ICON_TOWN_HALL                       0x0000ec41
#define ENTYPO_ICON_TRASH_6                         0x0000ec42
#define ENTYPO_ICON_TREE_2                          0x0000ec43
#define ENTYPO_ICON_TREE_3                          0x0000ec44
#define ENTYPO_ICON_WAREHOUSE                       0x0000ec45
#define ENTYPO_ICON_DUCKDUCKGO                      0x0000ec46
#define ENTYPO_ICON_AIM                             0x0000ec47
#define ENTYPO_ICON_DELICIOUS_1                     0x0000ec48
#define ENTYPO_ICON_PAYPAL_2                        0x0000ec49
#define ENTYPO_ICON_FLATTR_1                        0x0000ec4a
#define ENTYPO_ICON_ANDROID_1                       0x0000ec4b
#define ENTYPO_ICON_EVENTFUL                        0x0000ec4c
#define ENTYPO_ICON_SMASHMAG                        0x0000ec4d
#define ENTYPO_ICON_GPLUS_3                         0x0000ec4e
#define ENTYPO_ICON_WIKIPEDIA                       0x0000ec4f
#define ENTYPO_ICON_LANYRD                          0x0000ec50
#define ENTYPO_ICON_CALENDAR_6                      0x0000ec51
#define ENTYPO_ICON_STUMBLEUPON_2                   0x0000ec52
#define ENTYPO_ICON_FIVEHUNDREDPX                   0x0000ec53
#define ENTYPO_ICON_PINTEREST_3                     0x0000ec54
#define ENTYPO_ICON_BITCOIN_1                       0x0000ec55
#define ENTYPO_ICON_W3C                             0x0000ec56
#define ENTYPO_ICON_FOURSQUARE_1                    0x0000ec57
#define ENTYPO_ICON_HTML5_1                         0x0000ec58
#define ENTYPO_ICON_IE                              0x0000ec59
#define ENTYPO_ICON_CALL                            0x0000ec5a
#define ENTYPO_ICON_GROOVESHARK                     0x0000ec5b
#define ENTYPO_ICON_NINETYNINEDESIGNS               0x0000ec5c
#define ENTYPO_ICON_FORRST                          0x0000ec5d
#define ENTYPO_ICON_DIGG_1                          0x0000ec5e
#define ENTYPO_ICON_SPOTIFY_2                       0x0000ec5f
#define ENTYPO_ICON_REDDIT_1                        0x0000ec60
#define ENTYPO_ICON_GUEST                           0x0000ec61
#define ENTYPO_ICON_GOWALLA                         0x0000ec62
#define ENTYPO_ICON_APPSTORE                        0x0000ec63
#define ENTYPO_ICON_BLOGGER                         0x0000ec64
#define ENTYPO_ICON_CC_2                            0x0000ec65
#define ENTYPO_ICON_DRIBBBLE_4                      0x0000ec66
#define ENTYPO_ICON_EVERNOTE_1                      0x0000ec67
#define ENTYPO_ICON_FLICKR_3                        0x0000ec68
#define ENTYPO_ICON_GOOGLE_1                        0x0000ec69
#define ENTYPO_ICON_VIADEO_1                        0x0000ec6a
#define ENTYPO_ICON_INSTAPAPER                      0x0000ec6b
#define ENTYPO_ICON_WEIBO_1                         0x0000ec6c
#define ENTYPO_ICON_KLOUT                           0x0000ec6d
#define ENTYPO_ICON_LINKEDIN_4                      0x0000ec6e
#define ENTYPO_ICON_MEETUP_1                        0x0000ec6f
#define ENTYPO_ICON_VK                              0x0000ec70
#define ENTYPO_ICON_PLANCAST                        0x0000ec71
#define ENTYPO_ICON_DISQUS                          0x0000ec72
#define ENTYPO_ICON_RSS_5                           0x0000ec73
#define ENTYPO_ICON_SKYPE_3                         0x0000ec74
#define ENTYPO_ICON_TWITTER_5                       0x0000ec75
#define ENTYPO_ICON_YOUTUBE_2                       0x0000ec76
#define ENTYPO_ICON_VIMEO_3                         0x0000ec77
#define ENTYPO_ICON_WINDOWS_1                       0x0000ec78
#define ENTYPO_ICON_XING_1                          0x0000ec79
#define ENTYPO_ICON_YAHOO_1                         0x0000ec7a
#define ENTYPO_ICON_CHROME_1                        0x0000ec7b
#define ENTYPO_ICON_EMAIL                           0x0000ec7c
#define ENTYPO_ICON_MACSTORE                        0x0000ec7d
#define ENTYPO_ICON_MYSPACE                         0x0000ec7e
#define ENTYPO_ICON_PODCAST_1                       0x0000ec7f
#define ENTYPO_ICON_AMAZON_1                        0x0000ec80
#define ENTYPO_ICON_STEAM_1                         0x0000ec81
#define ENTYPO_ICON_CLOUDAPP                        0x0000ec82
#define ENTYPO_ICON_DROPBOX_2                       0x0000ec83
#define ENTYPO_ICON_EBAY                            0x0000ec84
#define ENTYPO_ICON_FACEBOOK_5                      0x0000ec85
#define ENTYPO_ICON_GITHUB_4                        0x0000ec86
#define ENTYPO_ICON_GITHUB_CIRCLED_4                0x0000ec87
#define ENTYPO_ICON_GOOGLEPLAY                      0x0000ec88
#define ENTYPO_ICON_ITUNES                          0x0000ec89
#define ENTYPO_ICON_PLURK                           0x0000ec8a
#define ENTYPO_ICON_SONGKICK                        0x0000ec8b
#define ENTYPO_ICON_LASTFM_3                        0x0000ec8c
#define ENTYPO_ICON_GMAIL                           0x0000ec8d
#define ENTYPO_ICON_PINBOARD                        0x0000ec8e
#define ENTYPO_ICON_OPENID_1                        0x0000ec8f
#define ENTYPO_ICON_QUORA_1                         0x0000ec90
#define ENTYPO_ICON_SOUNDCLOUD_3                    0x0000ec91
#define ENTYPO_ICON_TUMBLR_2                        0x0000ec92
#define ENTYPO_ICON_EVENTASAURUS                    0x0000ec93
#define ENTYPO_ICON_WORDPRESS_1                     0x0000ec94
#define ENTYPO_ICON_YELP_1                          0x0000ec95
#define ENTYPO_ICON_INTENSEDEBATE                   0x0000ec96
#define ENTYPO_ICON_EVENTBRITE                      0x0000ec97
#define ENTYPO_ICON_SCRIBD_1                        0x0000ec98
#define ENTYPO_ICON_POSTEROUS                       0x0000ec99
#define ENTYPO_ICON_STRIPE                          0x0000ec9a
#define ENTYPO_ICON_OPENTABLE                       0x0000ec9b
#define ENTYPO_ICON_CART                            0x0000ec9c
#define ENTYPO_ICON_PRINT_5                         0x0000ec9d
#define ENTYPO_ICON_ANGELLIST_1                     0x0000ec9e
#define ENTYPO_ICON_INSTAGRAM_3                     0x0000ec9f
#define ENTYPO_ICON_DWOLLA                          0x0000eca0
#define ENTYPO_ICON_APPNET                          0x0000eca1
#define ENTYPO_ICON_STATUSNET                       0x0000eca2
#define ENTYPO_ICON_ACROBAT                         0x0000eca3
#define ENTYPO_ICON_DRUPAL_1                        0x0000eca4
#define ENTYPO_ICON_BUFFER                          0x0000eca5
#define ENTYPO_ICON_POCKET                          0x0000eca6
#define ENTYPO_ICON_BITBUCKET_1                     0x0000eca7
#define ENTYPO_ICON_LEGO                            0x0000eca8
#define ENTYPO_ICON_LOGIN_3                         0x0000eca9
#define ENTYPO_ICON_STACKOVERFLOW_1                 0x0000ecaa
#define ENTYPO_ICON_HACKERNEWS                      0x0000ecab
#define ENTYPO_ICON_LKDTO                           0x0000ecac
#define ENTYPO_ICON_FACEBOOK_6                      0x0000ecad
#define ENTYPO_ICON_FACEBOOK_RECT_1                 0x0000ecae
#define ENTYPO_ICON_TWITTER_6                       0x0000ecaf
#define ENTYPO_ICON_TWITTER_BIRD_1                  0x0000ecb0
#define ENTYPO_ICON_VIMEO_4                         0x0000ecb1
#define ENTYPO_ICON_VIMEO_RECT                      0x0000ecb2
#define ENTYPO_ICON_TUMBLR_RECT                     0x0000ecb3
#define ENTYPO_ICON_GOOGLEPLUS_RECT                 0x0000ecb4
#define ENTYPO_ICON_GITHUB_TEXT                     0x0000ecb5
#define ENTYPO_ICON_GITHUB_5                        0x0000ecb6
#define ENTYPO_ICON_ICQ                             0x0000ecb7
#define ENTYPO_ICON_YANDEX_RECT                     0x0000ecb8
#define ENTYPO_ICON_VKONTAKTE_RECT                  0x0000ecb9
#define ENTYPO_ICON_ODNOKLASSNIKI_1                 0x0000ecba
#define ENTYPO_ICON_ODNOKLASSNIKI_RECT              0x0000ecbb
#define ENTYPO_ICON_FRIENDFEED                      0x0000ecbc
#define ENTYPO_ICON_FRIENDFEED_RECT                 0x0000ecbd
#define ENTYPO_ICON_BLOGGER_1                       0x0000ecbe
#define ENTYPO_ICON_BLOGGER_RECT                    0x0000ecbf
#define ENTYPO_ICON_DEVIANTART_1                    0x0000ecc0
#define ENTYPO_ICON_LASTFM_4                        0x0000ecc1
#define ENTYPO_ICON_LASTFM_RECT                     0x0000ecc2
#define ENTYPO_ICON_LINKEDIN_RECT                   0x0000ecc3
#define ENTYPO_ICON_PICASA_1                        0x0000ecc4
#define ENTYPO_ICON_INSTAGRAM_4                     0x0000ecc5
#define ENTYPO_ICON_INSTAGRAM_FILLED                0x0000ecc6
#define ENTYPO_ICON_BOX_4                           0x0000ecc7
#define ENTYPO_ICON_BOX_RECT                        0x0000ecc8
#define ENTYPO_ICON_YOUKU                           0x0000ecc9
#define ENTYPO_ICON_WIN8                            0x0000ecca
#define ENTYPO_ICON_DISCOVER                        0x0000eccb
#define ENTYPO_ICON_VISA                            0x0000eccc
#define ENTYPO_ICON_HOUZZ_1                         0x0000eccd
#define ENTYPO_ICON_GLASS_1                         0x0000ecce
#define ENTYPO_ICON_MUSIC_3                         0x0000eccf
#define ENTYPO_ICON_SEARCH_6                        0x0000ecd0
#define ENTYPO_ICON_SEARCH_CIRCLED                  0x0000ecd1
#define ENTYPO_ICON_MAIL_6                          0x0000ecd2
#define ENTYPO_ICON_MAIL_CIRCLED                    0x0000ecd3
#define ENTYPO_ICON_HEART_6                         0x0000ecd4
#define ENTYPO_ICON_HEART_CIRCLED                   0x0000ecd5
#define ENTYPO_ICON_HEART_EMPTY_3                   0x0000ecd6
#define ENTYPO_ICON_STAR_6                          0x0000ecd7
#define ENTYPO_ICON_STAR_CIRCLED                    0x0000ecd8
#define ENTYPO_ICON_STAR_EMPTY_3                    0x0000ecd9
#define ENTYPO_ICON_USER_6                          0x0000ecda
#define ENTYPO_ICON_GROUP                           0x0000ecdb
#define ENTYPO_ICON_GROUP_CIRCLED                   0x0000ecdc
#define ENTYPO_ICON_TORSO                           0x0000ecdd
#define ENTYPO_ICON_VIDEO_4                         0x0000ecde
#define ENTYPO_ICON_VIDEO_CIRCLED                   0x0000ecdf
#define ENTYPO_ICON_VIDEO_ALT_1                     0x0000ece0
#define ENTYPO_ICON_VIDEOCAM_4                      0x0000ece1
#define ENTYPO_ICON_VIDEO_CHAT                      0x0000ece2
#define ENTYPO_ICON_PICTURE_4                       0x0000ece3
#define ENTYPO_ICON_CAMERA_6                        0x0000ece4
#define ENTYPO_ICON_PHOTO                           0x0000ece5
#define ENTYPO_ICON_PHOTO_CIRCLED                   0x0000ece6
#define ENTYPO_ICON_TH_LARGE_2                      0x0000ece7
#define ENTYPO_ICON_TH_3                            0x0000ece8
#define ENTYPO_ICON_TH_LIST_4                       0x0000ece9
#define ENTYPO_ICON_VIEW_MODE                       0x0000ecea
#define ENTYPO_ICON_OK_5                            0x0000eceb
#define ENTYPO_ICON_OK_CIRCLED_2                    0x0000ecec
#define ENTYPO_ICON_OK_CIRCLED2_1                   0x0000eced
#define ENTYPO_ICON_CANCEL_6                        0x0000ecee
#define ENTYPO_ICON_CANCEL_CIRCLED_4                0x0000ecef
#define ENTYPO_ICON_CANCEL_CIRCLED2_1               0x0000ecf0
#define ENTYPO_ICON_PLUS_6                          0x0000ecf1
#define ENTYPO_ICON_PLUS_CIRCLED_2                  0x0000ecf2
#define ENTYPO_ICON_MINUS_4                         0x0000ecf3
#define ENTYPO_ICON_MINUS_CIRCLED_2                 0x0000ecf4
#define ENTYPO_ICON_HELP_3                          0x0000ecf5
#define ENTYPO_ICON_HELP_CIRCLED_3                  0x0000ecf6
#define ENTYPO_ICON_INFO_CIRCLED_3                  0x0000ecf7
#define ENTYPO_ICON_HOME_6                          0x0000ecf8
#define ENTYPO_ICON_HOME_CIRCLED                    0x0000ecf9
#define ENTYPO_ICON_WEBSITE                         0x0000ecfa
#define ENTYPO_ICON_WEBSITE_CIRCLED                 0x0000ecfb
#define ENTYPO_ICON_ATTACH_5                        0x0000ecfc
#define ENTYPO_ICON_ATTACH_CIRCLED                  0x0000ecfd
#define ENTYPO_ICON_LOCK_6                          0x0000ecfe
#define ENTYPO_ICON_LOCK_CIRCLED                    0x0000ecff
#define ENTYPO_ICON_LOCK_OPEN_6                     0x0000ed00
#define ENTYPO_ICON_LOCK_OPEN_ALT_2                 0x0000ed01
#define ENTYPO_ICON_EYE_6                           0x0000ed02
#define ENTYPO_ICON_EYE_OFF_1                       0x0000ed03
#define ENTYPO_ICON_TAG_5                           0x0000ed04
#define ENTYPO_ICON_TAGS_2                          0x0000ed05
#define ENTYPO_ICON_BOOKMARK_3                      0x0000ed06
#define ENTYPO_ICON_BOOKMARK_EMPTY_1                0x0000ed07
#define ENTYPO_ICON_FLAG_3                          0x0000ed08
#define ENTYPO_ICON_FLAG_CIRCLED                    0x0000ed09
#define ENTYPO_ICON_THUMBS_UP_4                     0x0000ed0a
#define ENTYPO_ICON_THUMBS_DOWN_4                   0x0000ed0b
#define ENTYPO_ICON_DOWNLOAD_6                      0x0000ed0c
#define ENTYPO_ICON_DOWNLOAD_ALT                    0x0000ed0d
#define ENTYPO_ICON_UPLOAD_5                        0x0000ed0e
#define ENTYPO_ICON_SHARE_3                         0x0000ed0f
#define ENTYPO_ICON_QUOTE_1                         0x0000ed10
#define ENTYPO_ICON_QUOTE_CIRCLED                   0x0000ed11
#define ENTYPO_ICON_EXPORT_5                        0x0000ed12
#define ENTYPO_ICON_PENCIL_6                        0x0000ed13
#define ENTYPO_ICON_PENCIL_CIRCLED                  0x0000ed14
#define ENTYPO_ICON_EDIT_3                          0x0000ed15
#define ENTYPO_ICON_EDIT_CIRCLED                    0x0000ed16
#define ENTYPO_ICON_EDIT_ALT                        0x0000ed17
#define ENTYPO_ICON_PRINT_6                         0x0000ed18
#define ENTYPO_ICON_RETWEET_3                       0x0000ed19
#define ENTYPO_ICON_COMMENT_5                       0x0000ed1a
#define ENTYPO_ICON_COMMENT_ALT_1                   0x0000ed1b
#define ENTYPO_ICON_BELL_5                          0x0000ed1c
#define ENTYPO_ICON_WARNING_1                       0x0000ed1d
#define ENTYPO_ICON_EXCLAMATION                     0x0000ed1e
#define ENTYPO_ICON_ERROR                           0x0000ed1f
#define ENTYPO_ICON_ERROR_ALT                       0x0000ed20
#define ENTYPO_ICON_LOCATION_6                      0x0000ed21
#define ENTYPO_ICON_LOCATION_CIRCLED                0x0000ed22
#define ENTYPO_ICON_COMPASS_5                       0x0000ed23
#define ENTYPO_ICON_COMPASS_CIRCLED                 0x0000ed24
#define ENTYPO_ICON_TRASH_7                         0x0000ed25
#define ENTYPO_ICON_TRASH_CIRCLED                   0x0000ed26
#define ENTYPO_ICON_DOC_6                           0x0000ed27
#define ENTYPO_ICON_DOC_CIRCLED                     0x0000ed28
#define ENTYPO_ICON_DOC_NEW                         0x0000ed29
#define ENTYPO_ICON_DOC_NEW_CIRCLED                 0x0000ed2a
#define ENTYPO_ICON_FOLDER_5                        0x0000ed2b
#define ENTYPO_ICON_FOLDER_CIRCLED                  0x0000ed2c
#define ENTYPO_ICON_FOLDER_CLOSE                    0x0000ed2d
#define ENTYPO_ICON_FOLDER_OPEN_2                   0x0000ed2e
#define ENTYPO_ICON_RSS_6                           0x0000ed2f
#define ENTYPO_ICON_PHONE_3                         0x0000ed30
#define ENTYPO_ICON_PHONE_CIRCLED                   0x0000ed31
#define ENTYPO_ICON_COG_5                           0x0000ed32
#define ENTYPO_ICON_COG_CIRCLED                     0x0000ed33
#define ENTYPO_ICON_COGS                            0x0000ed34
#define ENTYPO_ICON_WRENCH_4                        0x0000ed35
#define ENTYPO_ICON_WRENCH_CIRCLED                  0x0000ed36
#define ENTYPO_ICON_BASKET_4                        0x0000ed37
#define ENTYPO_ICON_BASKET_CIRCLED                  0x0000ed38
#define ENTYPO_ICON_CALENDAR_7                      0x0000ed39
#define ENTYPO_ICON_CALENDAR_CIRCLED                0x0000ed3a
#define ENTYPO_ICON_MIC_5                           0x0000ed3b
#define ENTYPO_ICON_MIC_CIRCLED                     0x0000ed3c
#define ENTYPO_ICON_VOLUME_OFF_4                    0x0000ed3d
#define ENTYPO_ICON_VOLUME_DOWN_2                   0x0000ed3e
#define ENTYPO_ICON_VOLUME_1                        0x0000ed3f
#define ENTYPO_ICON_VOLUME_UP_3                     0x0000ed40
#define ENTYPO_ICON_HEADPHONES_3                    0x0000ed41
#define ENTYPO_ICON_CLOCK_6                         0x0000ed42
#define ENTYPO_ICON_CLOCK_CIRCLED                   0x0000ed43
#define ENTYPO_ICON_LIGHTBULB_2                     0x0000ed44
#define ENTYPO_ICON_LIGHTBULB_ALT                   0x0000ed45
#define ENTYPO_ICON_BLOCK_4                         0x0000ed46
#define ENTYPO_ICON_RESIZE_FULL_5                   0x0000ed47
#define ENTYPO_ICON_RESIZE_FULL_ALT_2               0x0000ed48
#define ENTYPO_ICON_RESIZE_SMALL_4                  0x0000ed49
#define ENTYPO_ICON_RESIZE_VERTICAL_2               0x0000ed4a
#define ENTYPO_ICON_RESIZE_HORIZONTAL_2             0x0000ed4b
#define ENTYPO_ICON_MOVE_3                          0x0000ed4c
#define ENTYPO_ICON_ZOOM_IN_4                       0x0000ed4d
#define ENTYPO_ICON_ZOOM_OUT_4                      0x0000ed4e
#define ENTYPO_ICON_DOWN_OPEN_3                     0x0000ed4f
#define ENTYPO_ICON_LEFT_OPEN_4                     0x0000ed50
#define ENTYPO_ICON_RIGHT_OPEN_4                    0x0000ed51
#define ENTYPO_ICON_UP_OPEN_3                       0x0000ed52
#define ENTYPO_ICON_DOWN_6                          0x0000ed53
#define ENTYPO_ICON_LEFT_5                          0x0000ed54
#define ENTYPO_ICON_RIGHT_5                         0x0000ed55
#define ENTYPO_ICON_UP_6                            0x0000ed56
#define ENTYPO_ICON_DOWN_CIRCLED_2                  0x0000ed57
#define ENTYPO_ICON_LEFT_CIRCLED_2                  0x0000ed58
#define ENTYPO_ICON_RIGHT_CIRCLED_2                 0x0000ed59
#define ENTYPO_ICON_UP_CIRCLED_2                    0x0000ed5a
#define ENTYPO_ICON_DOWN_HAND_1                     0x0000ed5b
#define ENTYPO_ICON_LEFT_HAND_1                     0x0000ed5c
#define ENTYPO_ICON_RIGHT_HAND_1                    0x0000ed5d
#define ENTYPO_ICON_UP_HAND_1                       0x0000ed5e
#define ENTYPO_ICON_CW_5                            0x0000ed5f
#define ENTYPO_ICON_CW_CIRCLED                      0x0000ed60
#define ENTYPO_ICON_ARROWS_CW_2                     0x0000ed61
#define ENTYPO_ICON_SHUFFLE_4                       0x0000ed62
#define ENTYPO_ICON_PLAY_5                          0x0000ed63
#define ENTYPO_ICON_PLAY_CIRCLED_1                  0x0000ed64
#define ENTYPO_ICON_PLAY_CIRCLED2_1                 0x0000ed65
#define ENTYPO_ICON_STOP_6                          0x0000ed66
#define ENTYPO_ICON_STOP_CIRCLED                    0x0000ed67
#define ENTYPO_ICON_PAUSE_5                         0x0000ed68
#define ENTYPO_ICON_PAUSE_CIRCLED                   0x0000ed69
#define ENTYPO_ICON_RECORD_2                        0x0000ed6a
#define ENTYPO_ICON_EJECT_3                         0x0000ed6b
#define ENTYPO_ICON_BACKWARD                        0x0000ed6c
#define ENTYPO_ICON_BACKWARD_CIRCLED                0x0000ed6d
#define ENTYPO_ICON_FAST_BACKWARD_2                 0x0000ed6e
#define ENTYPO_ICON_FAST_FORWARD_2                  0x0000ed6f
#define ENTYPO_ICON_FORWARD_3                       0x0000ed70
#define ENTYPO_ICON_FORWARD_CIRCLED                 0x0000ed71
#define ENTYPO_ICON_STEP_BACKWARD                   0x0000ed72
#define ENTYPO_ICON_STEP_FORWARD                    0x0000ed73
#define ENTYPO_ICON_TARGET_4                        0x0000ed74
#define ENTYPO_ICON_SIGNAL_4                        0x0000ed75
#define ENTYPO_ICON_DESKTOP_2                       0x0000ed76
#define ENTYPO_ICON_DESKTOP_CIRCLED                 0x0000ed77
#define ENTYPO_ICON_LAPTOP_2                        0x0000ed78
#define ENTYPO_ICON_LAPTOP_CIRCLED                  0x0000ed79
#define ENTYPO_ICON_NETWORK_1                       0x0000ed7a
#define ENTYPO_ICON_INBOX_3                         0x0000ed7b
#define ENTYPO_ICON_INBOX_CIRCLED                   0x0000ed7c
#define ENTYPO_ICON_INBOX_ALT                       0x0000ed7d
#define ENTYPO_ICON_GLOBE_5                         0x0000ed7e
#define ENTYPO_ICON_GLOBE_ALT_1                     0x0000ed7f
#define ENTYPO_ICON_CLOUD_6                         0x0000ed80
#define ENTYPO_ICON_CLOUD_CIRCLED                   0x0000ed81
#define ENTYPO_ICON_FLIGHT_2                        0x0000ed82
#define ENTYPO_ICON_LEAF_3                          0x0000ed83
#define ENTYPO_ICON_FONT_1                          0x0000ed84
#define ENTYPO_ICON_FONTSIZE_1                      0x0000ed85
#define ENTYPO_ICON_BOLD_1                          0x0000ed86
#define ENTYPO_ICON_ITALIC_1                        0x0000ed87
#define ENTYPO_ICON_TEXT_HEIGHT_1                   0x0000ed88
#define ENTYPO_ICON_TEXT_WIDTH_1                    0x0000ed89
#define ENTYPO_ICON_ALIGN_LEFT_1                    0x0000ed8a
#define ENTYPO_ICON_ALIGN_CENTER_1                  0x0000ed8b
#define ENTYPO_ICON_ALIGN_RIGHT_1                   0x0000ed8c
#define ENTYPO_ICON_ALIGN_JUSTIFY_1                 0x0000ed8d
#define ENTYPO_ICON_LIST_3                          0x0000ed8e
#define ENTYPO_ICON_INDENT_LEFT_1                   0x0000ed8f
#define ENTYPO_ICON_INDENT_RIGHT_1                  0x0000ed90
#define ENTYPO_ICON_BRIEFCASE_3                     0x0000ed91
#define ENTYPO_ICON_OFF_1                           0x0000ed92
#define ENTYPO_ICON_ROAD_1                          0x0000ed93
#define ENTYPO_ICON_QRCODE_1                        0x0000ed94
#define ENTYPO_ICON_BARCODE_1                       0x0000ed95
#define ENTYPO_ICON_BRAILLE_1                       0x0000ed96
#define ENTYPO_ICON_BOOK_4                          0x0000ed97
#define ENTYPO_ICON_ADJUST_2                        0x0000ed98
#define ENTYPO_ICON_TINT_1                          0x0000ed99
#define ENTYPO_ICON_CHECK_3                         0x0000ed9a
#define ENTYPO_ICON_CHECK_EMPTY_1                   0x0000ed9b
#define ENTYPO_ICON_ASTERISK_1                      0x0000ed9c
#define ENTYPO_ICON_GIFT_2                          0x0000ed9d
#define ENTYPO_ICON_FIRE_2                          0x0000ed9e
#define ENTYPO_ICON_MAGNET_2                        0x0000ed9f
#define ENTYPO_ICON_CHART_2                         0x0000eda0
#define ENTYPO_ICON_CHART_CIRCLED                   0x0000eda1
#define ENTYPO_ICON_CREDIT_CARD_4                   0x0000eda2
#define ENTYPO_ICON_MEGAPHONE_2                     0x0000eda3
#define ENTYPO_ICON_CLIPBOARD_2                     0x0000eda4
#define ENTYPO_ICON_HDD_2                           0x0000eda5
#define ENTYPO_ICON_KEY_4                           0x0000eda6
#define ENTYPO_ICON_CERTIFICATE_2                   0x0000eda7
#define ENTYPO_ICON_TASKS_1                         0x0000eda8
#define ENTYPO_ICON_FILTER_1                        0x0000eda9
#define ENTYPO_ICON_GAUGE_2                         0x0000edaa
#define ENTYPO_ICON_SMILEY                          0x0000edab
#define ENTYPO_ICON_SMILEY_CIRCLED                  0x0000edac
#define ENTYPO_ICON_ADDRESS_BOOK_1                  0x0000edad
#define ENTYPO_ICON_ADDRESS_BOOK_ALT                0x0000edae
#define ENTYPO_ICON_ASL                             0x0000edaf
#define ENTYPO_ICON_GLASSES                         0x0000edb0
#define ENTYPO_ICON_HEARING_IMPAIRED                0x0000edb1
#define ENTYPO_ICON_IPHONE_HOME                     0x0000edb2
#define ENTYPO_ICON_PERSON                          0x0000edb3
#define ENTYPO_ICON_ADULT                           0x0000edb4
#define ENTYPO_ICON_CHILD_1                         0x0000edb5
#define ENTYPO_ICON_BLIND_1                         0x0000edb6
#define ENTYPO_ICON_GUIDEDOG                        0x0000edb7
#define ENTYPO_ICON_ACCESSIBILITY                   0x0000edb8
#define ENTYPO_ICON_UNIVERSAL_ACCESS_1              0x0000edb9
#define ENTYPO_ICON_MALE_2                          0x0000edba
#define ENTYPO_ICON_FEMALE_2                        0x0000edbb
#define ENTYPO_ICON_BEHANCE_2                       0x0000edbc
#define ENTYPO_ICON_BLOGGER_2                       0x0000edbd
#define ENTYPO_ICON_CC_3                            0x0000edbe
#define ENTYPO_ICON_CSS                             0x0000edbf
#define ENTYPO_ICON_DELICIOUS_2                     0x0000edc0
#define ENTYPO_ICON_DEVIANTART_2                    0x0000edc1
#define ENTYPO_ICON_DIGG_2                          0x0000edc2
#define ENTYPO_ICON_DRIBBBLE_5                      0x0000edc3
#define ENTYPO_ICON_FACEBOOK_7                      0x0000edc4
#define ENTYPO_ICON_FLICKR_4                        0x0000edc5
#define ENTYPO_ICON_FOURSQUARE_2                    0x0000edc6
#define ENTYPO_ICON_FRIENDFEED_1                    0x0000edc7
#define ENTYPO_ICON_FRIENDFEED_RECT_1               0x0000edc8
#define ENTYPO_ICON_GITHUB_6                        0x0000edc9
#define ENTYPO_ICON_GITHUB_TEXT_1                   0x0000edca
#define ENTYPO_ICON_GOOGLEPLUS                      0x0000edcb
#define ENTYPO_ICON_INSTAGRAM_5                     0x0000edcc
#define ENTYPO_ICON_LINKEDIN_6                      0x0000edcd
#define ENTYPO_ICON_PATH                            0x0000edce
#define ENTYPO_ICON_PICASA_2                        0x0000edcf
#define ENTYPO_ICON_PINTEREST_4                     0x0000edd0
#define ENTYPO_ICON_REDDIT_2                        0x0000edd1
#define ENTYPO_ICON_SKYPE_5                         0x0000edd2
#define ENTYPO_ICON_SLIDESHARE_1                    0x0000edd3
#define ENTYPO_ICON_STACKOVERFLOW_2                 0x0000edd4
#define ENTYPO_ICON_STUMBLEUPON_3                   0x0000edd5
#define ENTYPO_ICON_TWITTER_7                       0x0000edd6
#define ENTYPO_ICON_TUMBLR_4                        0x0000edd7
#define ENTYPO_ICON_VIMEO_5                         0x0000edd8
#define ENTYPO_ICON_VKONTAKTE_2                     0x0000edd9
#define ENTYPO_ICON_W3C_1                           0x0000edda
#define ENTYPO_ICON_WORDPRESS_3                     0x0000eddb
#define ENTYPO_ICON_YOUTUBE_3                       0x0000eddc
#define ENTYPO_ICON_MUSIC_4                         0x0000eddd
#define ENTYPO_ICON_SEARCH_7                        0x0000edde
#define ENTYPO_ICON_MAIL_7                          0x0000eddf
#define ENTYPO_ICON_HEART_7                         0x0000ede0
#define ENTYPO_ICON_STAR_7                          0x0000ede1
#define ENTYPO_ICON_USER_7                          0x0000ede2
#define ENTYPO_ICON_VIDEOCAM_5                      0x0000ede3
#define ENTYPO_ICON_CAMERA_7                        0x0000ede4
#define ENTYPO_ICON_PHOTO_1                         0x0000ede5
#define ENTYPO_ICON_ATTACH_6                        0x0000ede6
#define ENTYPO_ICON_LOCK_7                          0x0000ede7
#define ENTYPO_ICON_EYE_7                           0x0000ede8
#define ENTYPO_ICON_TAG_6                           0x0000ede9
#define ENTYPO_ICON_THUMBS_UP_5                     0x0000edea
#define ENTYPO_ICON_PENCIL_7                        0x0000edeb
#define ENTYPO_ICON_COMMENT_6                       0x0000edec
#define ENTYPO_ICON_LOCATION_7                      0x0000eded
#define ENTYPO_ICON_CUP_1                           0x0000edee
#define ENTYPO_ICON_TRASH_8                         0x0000edef
#define ENTYPO_ICON_DOC_7                           0x0000edf0
#define ENTYPO_ICON_NOTE_1                          0x0000edf1
#define ENTYPO_ICON_COG_6                           0x0000edf2
#define ENTYPO_ICON_PARAMS                          0x0000edf3
#define ENTYPO_ICON_CALENDAR_8                      0x0000edf4
#define ENTYPO_ICON_SOUND_1                         0x0000edf5
#define ENTYPO_ICON_CLOCK_7                         0x0000edf6
#define ENTYPO_ICON_LIGHTBULB_3                     0x0000edf7
#define ENTYPO_ICON_TV                              0x0000edf8
#define ENTYPO_ICON_DESKTOP_3                       0x0000edf9
#define ENTYPO_ICON_MOBILE_6                        0x0000edfa
#define ENTYPO_ICON_CD_3                            0x0000edfb
#define ENTYPO_ICON_INBOX_4                         0x0000edfc
#define ENTYPO_ICON_GLOBE_6                         0x0000edfd
#define ENTYPO_ICON_CLOUD_7                         0x0000edfe
#define ENTYPO_ICON_PAPER_PLANE_3                   0x0000edff
#define ENTYPO_ICON_FIRE_3                          0x0000ee00
#define ENTYPO_ICON_GRADUATION_CAP_2                0x0000ee01
#define ENTYPO_ICON_MEGAPHONE_3                     0x0000ee02
#define ENTYPO_ICON_DATABASE_3                      0x0000ee03
#define ENTYPO_ICON_KEY_5                           0x0000ee04
#define ENTYPO_ICON_BEAKER_1                        0x0000ee05
#define ENTYPO_ICON_TRUCK_1                         0x0000ee06
#define ENTYPO_ICON_MONEY_2                         0x0000ee07
#define ENTYPO_ICON_FOOD_1                          0x0000ee08
#define ENTYPO_ICON_SHOP_1                          0x0000ee09
#define ENTYPO_ICON_DIAMOND_1                       0x0000ee0a
#define ENTYPO_ICON_T_SHIRT                         0x0000ee0b
#define ENTYPO_ICON_WALLET                          0x0000ee0c
#define ENTYPO_ICON_SEARCH_8                        0x0000ee0d
#define ENTYPO_ICON_MAIL_8                          0x0000ee0e
#define ENTYPO_ICON_HEART_8                         0x0000ee0f
#define ENTYPO_ICON_HEART_EMPTY_4                   0x0000ee10
#define ENTYPO_ICON_STAR_8                          0x0000ee11
#define ENTYPO_ICON_USER_8                          0x0000ee12
#define ENTYPO_ICON_VIDEO_5                         0x0000ee13
#define ENTYPO_ICON_PICTURE_5                       0x0000ee14
#define ENTYPO_ICON_TH_LARGE_3                      0x0000ee15
#define ENTYPO_ICON_TH_4                            0x0000ee16
#define ENTYPO_ICON_TH_LIST_5                       0x0000ee17
#define ENTYPO_ICON_OK_6                            0x0000ee18
#define ENTYPO_ICON_OK_CIRCLE_1                     0x0000ee19
#define ENTYPO_ICON_CANCEL_7                        0x0000ee1a
#define ENTYPO_ICON_CANCEL_CIRCLE_2                 0x0000ee1b
#define ENTYPO_ICON_PLUS_CIRCLE_1                   0x0000ee1c
#define ENTYPO_ICON_MINUS_CIRCLE_1                  0x0000ee1d
#define ENTYPO_ICON_LINK_5                          0x0000ee1e
#define ENTYPO_ICON_ATTACH_7                        0x0000ee1f
#define ENTYPO_ICON_LOCK_8                          0x0000ee20
#define ENTYPO_ICON_LOCK_OPEN_7                     0x0000ee21
#define ENTYPO_ICON_TAG_7                           0x0000ee22
#define ENTYPO_ICON_REPLY_4                         0x0000ee23
#define ENTYPO_ICON_REPLY_ALL_2                     0x0000ee24
#define ENTYPO_ICON_FORWARD_4                       0x0000ee25
#define ENTYPO_ICON_CODE_3                          0x0000ee26
#define ENTYPO_ICON_RETWEET_4                       0x0000ee27
#define ENTYPO_ICON_COMMENT_7                       0x0000ee28
#define ENTYPO_ICON_COMMENT_ALT_2                   0x0000ee29
#define ENTYPO_ICON_CHAT_6                          0x0000ee2a
#define ENTYPO_ICON_ATTENTION_5                     0x0000ee2b
#define ENTYPO_ICON_LOCATION_8                      0x0000ee2c
#define ENTYPO_ICON_DOC_8                           0x0000ee2d
#define ENTYPO_ICON_DOCS_LANDSCAPE                  0x0000ee2e
#define ENTYPO_ICON_FOLDER_6                        0x0000ee2f
#define ENTYPO_ICON_ARCHIVE_2                       0x0000ee30
#define ENTYPO_ICON_RSS_7                           0x0000ee31
#define ENTYPO_ICON_RSS_ALT_1                       0x0000ee32
#define ENTYPO_ICON_COG_7                           0x0000ee33
#define ENTYPO_ICON_LOGOUT_3                        0x0000ee34
#define ENTYPO_ICON_CLOCK_8                         0x0000ee35
#define ENTYPO_ICON_BLOCK_5                         0x0000ee36
#define ENTYPO_ICON_RESIZE_FULL_6                   0x0000ee37
#define ENTYPO_ICON_RESIZE_FULL_CIRCLE              0x0000ee38
#define ENTYPO_ICON_POPUP_5                         0x0000ee39
#define ENTYPO_ICON_LEFT_OPEN_5                     0x0000ee3a
#define ENTYPO_ICON_RIGHT_OPEN_5                    0x0000ee3b
#define ENTYPO_ICON_DOWN_CIRCLE_1                   0x0000ee3c
#define ENTYPO_ICON_LEFT_CIRCLE_1                   0x0000ee3d
#define ENTYPO_ICON_RIGHT_CIRCLE_1                  0x0000ee3e
#define ENTYPO_ICON_UP_CIRCLE_1                     0x0000ee3f
#define ENTYPO_ICON_DOWN_DIR_3                      0x0000ee40
#define ENTYPO_ICON_RIGHT_DIR_3                     0x0000ee41
#define ENTYPO_ICON_DOWN_MICRO                      0x0000ee42
#define ENTYPO_ICON_UP_MICRO                        0x0000ee43
#define ENTYPO_ICON_CW_CIRCLE                       0x0000ee44
#define ENTYPO_ICON_ARROWS_CW_3                     0x0000ee45
#define ENTYPO_ICON_UPDOWN_CIRCLE                   0x0000ee46
#define ENTYPO_ICON_TARGET_5                        0x0000ee47
#define ENTYPO_ICON_SIGNAL_5                        0x0000ee48
#define ENTYPO_ICON_PROGRESS_4                      0x0000ee49
#define ENTYPO_ICON_PROGRESS_5                      0x0000ee4a
#define ENTYPO_ICON_PROGRESS_6                      0x0000ee4b
#define ENTYPO_ICON_PROGRESS_7                      0x0000ee4c
#define ENTYPO_ICON_PROGRESS_8                      0x0000ee4d
#define ENTYPO_ICON_PROGRESS_9                      0x0000ee4e
#define ENTYPO_ICON_PROGRESS_10                     0x0000ee4f
#define ENTYPO_ICON_PROGRESS_11                     0x0000ee50
#define ENTYPO_ICON_FONT_2                          0x0000ee51
#define ENTYPO_ICON_LIST_4                          0x0000ee52
#define ENTYPO_ICON_LIST_NUMBERED_1                 0x0000ee53
#define ENTYPO_ICON_INDENT_LEFT_2                   0x0000ee54
#define ENTYPO_ICON_INDENT_RIGHT_2                  0x0000ee55
#define ENTYPO_ICON_CLOUD_8                         0x0000ee56
#define ENTYPO_ICON_TERMINAL_1                      0x0000ee57
#define ENTYPO_ICON_FACEBOOK_RECT_2                 0x0000ee58
#define ENTYPO_ICON_TWITTER_BIRD_2                  0x0000ee59
#define ENTYPO_ICON_VIMEO_RECT_1                    0x0000ee5a
#define ENTYPO_ICON_TUMBLR_RECT_1                   0x0000ee5b
#define ENTYPO_ICON_GOOGLEPLUS_RECT_1               0x0000ee5c
#define ENTYPO_ICON_LINKEDIN_RECT_1                 0x0000ee5d
#define ENTYPO_ICON_SKYPE_6                         0x0000ee5e
#define ENTYPO_ICON_VKONTAKTE_RECT_1                0x0000ee5f
#define ENTYPO_ICON_YOUTUBE_4                       0x0000ee60
#define ENTYPO_ICON_ODNOKLASSNIKI_RECT_1            0x0000ee61
#define ENTYPO_ICON_DOWN_OPEN_2                     0x0000ee62
#define ENTYPO_ICON_UP_OPEN_2                       0x0000ee63
#define ENTYPO_ICON_RIGHT_OPEN_3                    0x0000ee64
#define ENTYPO_ICON_LEFT_OPEN_3                     0x0000ee65
#define ENTYPO_ICON_MENU_3                          0x0000ee66
#define ENTYPO_ICON_TH_LIST_3                       0x0000ee67
#define ENTYPO_ICON_TH_THUMB                        0x0000ee68
#define ENTYPO_ICON_TH_THUMB_EMPTY                  0x0000ee69
#define ENTYPO_ICON_COVERFLOW                       0x0000ee6a
#define ENTYPO_ICON_COVERFLOW_EMPTY                 0x0000ee6b
#define ENTYPO_ICON_PAUSE_4                         0x0000ee6c
#define ENTYPO_ICON_PLAY_4                          0x0000ee6d
#define ENTYPO_ICON_TO_END_3                        0x0000ee6e
#define ENTYPO_ICON_TO_START_3                      0x0000ee6f
#define ENTYPO_ICON_FAST_FORWARD_1                  0x0000ee70
#define ENTYPO_ICON_FAST_BACKWARD_1                 0x0000ee71
#define ENTYPO_ICON_UPLOAD_CLOUD_4                  0x0000ee72
#define ENTYPO_ICON_DOWNLOAD_CLOUD_2                0x0000ee73
#define ENTYPO_ICON_DATA_SCIENCE                    0x0000ee74
#define ENTYPO_ICON_DATA_SCIENCE_INV                0x0000ee75
#define ENTYPO_ICON_GLOBE_4                         0x0000ee76
#define ENTYPO_ICON_GLOBE_INV                       0x0000ee77
#define ENTYPO_ICON_MATH                            0x0000ee78
#define ENTYPO_ICON_MATH_CIRCLED_EMPTY              0x0000ee79
#define ENTYPO_ICON_MATH_CIRCLED                    0x0000ee7a
#define ENTYPO_ICON_PAPER_PLANE_2                   0x0000ee7b
#define ENTYPO_ICON_PAPER_PLANE_ALT2                0x0000ee7c
#define ENTYPO_ICON_PAPER_PLANE_ALT                 0x0000ee7d
#define ENTYPO_ICON_COLOR_ADJUST                    0x0000ee7e
#define ENTYPO_ICON_STAR_HALF_1                     0x0000ee7f
#define ENTYPO_ICON_STAR_HALF_EMPTY                 0x0000ee80
#define ENTYPO_ICON_CCW_2                           0x0000ee81
#define ENTYPO_ICON_HEART_BROKEN                    0x0000ee82
#define ENTYPO_ICON_HASH_1                          0x0000ee83
#define ENTYPO_ICON_REPLY_3                         0x0000ee84
#define ENTYPO_ICON_RETWEET_2                       0x0000ee85
#define ENTYPO_ICON_LOGIN_2                         0x0000ee86
#define ENTYPO_ICON_LOGOUT_2                        0x0000ee87
#define ENTYPO_ICON_DOWNLOAD_5                      0x0000ee88
#define ENTYPO_ICON_UPLOAD_4                        0x0000ee89
#define ENTYPO_ICON_LOCATION_5                      0x0000ee8a
#define ENTYPO_ICON_MONITOR_1                       0x0000ee8b
#define ENTYPO_ICON_TABLET_3                        0x0000ee8c
#define ENTYPO_ICON_MOBILE_5                        0x0000ee8d
#define ENTYPO_ICON_CONNECTED_OBJECT                0x0000ee8e
#define ENTYPO_ICON_ISIGHT                          0x0000ee8f
#define ENTYPO_ICON_VIDEOCAM_3                      0x0000ee90
#define ENTYPO_ICON_SHUFFLE_3                       0x0000ee91
#define ENTYPO_ICON_CHAT_5                          0x0000ee92
#define ENTYPO_ICON_BELL_4                          0x0000ee93
#define ENTYPO_ICON_MOVIE                           0x0000ee94
#define ENTYPO_ICON_RULER                           0x0000ee95
#define ENTYPO_ICON_VECTOR                          0x0000ee96
#define ENTYPO_ICON_MOVE                            0x0000ee97
#define ENTYPO_ICON_MIC_4                           0x0000ee98
#define ENTYPO_ICON_DOC_5                           0x0000ee99
#define ENTYPO_ICON_DRIBBBLE_CIRCLED_2              0x0000ee9a
#define ENTYPO_ICON_DRIBBBLE_3                      0x0000ee9b
#define ENTYPO_ICON_FACEBOOK_CIRCLED_2              0x0000ee9c
#define ENTYPO_ICON_FACEBOOK_4                      0x0000ee9d
#define ENTYPO_ICON_GITHUB_CIRCLED_ALT              0x0000ee9e
#define ENTYPO_ICON_GITHUB_CIRCLED_3                0x0000ee9f
#define ENTYPO_ICON_GITHUB_3                        0x0000eea0
#define ENTYPO_ICON_GITHUB_CIRCLED_ALT2             0x0000eea1
#define ENTYPO_ICON_TWITTER_CIRCLED_2               0x0000eea2
#define ENTYPO_ICON_TWITTER_4                       0x0000eea3
#define ENTYPO_ICON_GPLUS_CIRCLED_1                 0x0000eea4
#define ENTYPO_ICON_GPLUS_2                         0x0000eea5
#define ENTYPO_ICON_LINKEDIN_CIRCLED_2              0x0000eea6
#define ENTYPO_ICON_LINKEDIN_3                      0x0000eea7
#define ENTYPO_ICON_INSTAGRAM_2                     0x0000eea8
#define ENTYPO_ICON_INSTAGRAM_CIRCLED               0x0000eea9
#define ENTYPO_ICON_MFG_LOGO                        0x0000eeaa
#define ENTYPO_ICON_MFG_LOGO_CIRCLED                0x0000eeab
#define ENTYPO_ICON_USER_5                          0x0000eeac
#define ENTYPO_ICON_USER_MALE                       0x0000eead
#define ENTYPO_ICON_USER_FEMALE                     0x0000eeae
#define ENTYPO_ICON_USERS_3                         0x0000eeaf
#define ENTYPO_ICON_FOLDER_4                        0x0000eeb0
#define ENTYPO_ICON_FOLDER_OPEN_1                   0x0000eeb1
#define ENTYPO_ICON_FOLDER_EMPTY_2                  0x0000eeb2
#define ENTYPO_ICON_ATTACH_4                        0x0000eeb3
#define ENTYPO_ICON_OK_CIRCLED_1                    0x0000eeb4
#define ENTYPO_ICON_CANCEL_CIRCLED_3                0x0000eeb5
#define ENTYPO_ICON_INBOX_2                         0x0000eeb6
#define ENTYPO_ICON_TROPHY_1                        0x0000eeb7
#define ENTYPO_ICON_LOCK_OPEN_ALT_1                 0x0000eeb8
#define ENTYPO_ICON_LINK_4                          0x0000eeb9
#define ENTYPO_ICON_ZOOM_IN_3                       0x0000eeba
#define ENTYPO_ICON_ZOOM_OUT_3                      0x0000eebb
#define ENTYPO_ICON_STOP_5                          0x0000eebc
#define ENTYPO_ICON_EXPORT_4                        0x0000eebd
#define ENTYPO_ICON_EYE_5                           0x0000eebe
#define ENTYPO_ICON_TRASH_5                         0x0000eebf
#define ENTYPO_ICON_HDD_1                           0x0000eec0
#define ENTYPO_ICON_INFO_CIRCLED_2                  0x0000eec1
#define ENTYPO_ICON_INFO_CIRCLED_ALT                0x0000eec2
#define ENTYPO_ICON_PRINT_4                         0x0000eec3
#define ENTYPO_ICON_FONTSIZE                        0x0000eec4
#define ENTYPO_ICON_SOUNDCLOUD_2                    0x0000eec5
#define ENTYPO_ICON_SOUNDCLOUD_CIRCLED              0x0000eec6
#define ENTYPO_ICON_LINK_EXT                        0x0000eec7
#define ENTYPO_ICON_CHECK_EMPTY                     0x0000eec8
#define ENTYPO_ICON_BOOKMARK_EMPTY                  0x0000eec9
#define ENTYPO_ICON_PHONE_SQUARED                   0x0000eeca
#define ENTYPO_ICON_TWITTER                         0x0000eecb
#define ENTYPO_ICON_FACEBOOK                        0x0000eecc
#define ENTYPO_ICON_GITHUB_CIRCLED                  0x0000eecd
#define ENTYPO_ICON_RSS                             0x0000eece
#define ENTYPO_ICON_HDD                             0x0000eecf
#define ENTYPO_ICON_CERTIFICATE                     0x0000eed0
#define ENTYPO_ICON_LEFT_CIRCLED                    0x0000eed1
#define ENTYPO_ICON_RIGHT_CIRCLED                   0x0000eed2
#define ENTYPO_ICON_UP_CIRCLED                      0x0000eed3
#define ENTYPO_ICON_DOWN_CIRCLED                    0x0000eed4
#define ENTYPO_ICON_TASKS                           0x0000eed5
#define ENTYPO_ICON_FILTER                          0x0000eed6
#define ENTYPO_ICON_RESIZE_FULL_ALT                 0x0000eed7
#define ENTYPO_ICON_BEAKER                          0x0000eed8
#define ENTYPO_ICON_DOCS                            0x0000eed9
#define ENTYPO_ICON_BLANK                           0x0000eeda
#define ENTYPO_ICON_MENU                            0x0000eedb
#define ENTYPO_ICON_LIST_BULLET                     0x0000eedc
#define ENTYPO_ICON_LIST_NUMBERED                   0x0000eedd
#define ENTYPO_ICON_STRIKE                          0x0000eede
#define ENTYPO_ICON_UNDERLINE                       0x0000eedf
#define ENTYPO_ICON_TABLE                           0x0000eee0
#define ENTYPO_ICON_MAGIC                           0x0000eee1
#define ENTYPO_ICON_PINTEREST_CIRCLED               0x0000eee2
#define ENTYPO_ICON_PINTEREST_SQUARED               0x0000eee3
#define ENTYPO_ICON_GPLUS_SQUARED                   0x0000eee4
#define ENTYPO_ICON_GPLUS                           0x0000eee5
#define ENTYPO_ICON_MONEY                           0x0000eee6
#define ENTYPO_ICON_COLUMNS                         0x0000eee7
#define ENTYPO_ICON_SORT                            0x0000eee8
#define ENTYPO_ICON_SORT_DOWN                       0x0000eee9
#define ENTYPO_ICON_SORT_UP                         0x0000eeea
#define ENTYPO_ICON_MAIL_ALT                        0x0000eeeb
#define ENTYPO_ICON_LINKEDIN                        0x0000eeec
#define ENTYPO_ICON_GAUGE                           0x0000eeed
#define ENTYPO_ICON_COMMENT_EMPTY                   0x0000eeee
#define ENTYPO_ICON_CHAT_EMPTY                      0x0000eeef
#define ENTYPO_ICON_SITEMAP                         0x0000eef0
#define ENTYPO_ICON_PASTE                           0x0000eef1
#define ENTYPO_ICON_LIGHTBULB                       0x0000eef2
#define ENTYPO_ICON_EXCHANGE                        0x0000eef3
#define ENTYPO_ICON_DOWNLOAD_CLOUD                  0x0000eef4
#define ENTYPO_ICON_UPLOAD_CLOUD                    0x0000eef5
#define ENTYPO_ICON_USER_MD                         0x0000eef6
#define ENTYPO_ICON_STETHOSCOPE                     0x0000eef7
#define ENTYPO_ICON_SUITCASE                        0x0000eef8
#define ENTYPO_ICON_BELL_ALT                        0x0000eef9
#define ENTYPO_ICON_COFFEE                          0x0000eefa
#define ENTYPO_ICON_FOOD                            0x0000eefb
#define ENTYPO_ICON_DOC_TEXT                        0x0000eefc
#define ENTYPO_ICON_BUILDING                        0x0000eefd
#define ENTYPO_ICON_HOSPITAL                        0x0000eefe
#define ENTYPO_ICON_AMBULANCE                       0x0000eeff
#define ENTYPO_ICON_MEDKIT                          0x0000ef00
#define ENTYPO_ICON_FIGHTER_JET                     0x0000ef01
#define ENTYPO_ICON_BEER                            0x0000ef02
#define ENTYPO_ICON_H_SIGH                          0x0000ef03
#define ENTYPO_ICON_PLUS_SQUARED                    0x0000ef04
#define ENTYPO_ICON_ANGLE_DOUBLE_LEFT               0x0000ef05
#define ENTYPO_ICON_ANGLE_DOUBLE_RIGHT              0x0000ef06
#define ENTYPO_ICON_ANGLE_DOUBLE_UP                 0x0000ef07
#define ENTYPO_ICON_ANGLE_DOUBLE_DOWN               0x0000ef08
#define ENTYPO_ICON_ANGLE_LEFT                      0x0000ef09
#define ENTYPO_ICON_ANGLE_RIGHT                     0x0000ef0a
#define ENTYPO_ICON_ANGLE_UP                        0x0000ef0b
#define ENTYPO_ICON_ANGLE_DOWN                      0x0000ef0c
#define ENTYPO_ICON_DESKTOP                         0x0000ef0d
#define ENTYPO_ICON_LAPTOP                          0x0000ef0e
#define ENTYPO_ICON_TABLET                          0x0000ef0f
#define ENTYPO_ICON_MOBILE                          0x0000ef10
#define ENTYPO_ICON_CIRCLE_EMPTY                    0x0000ef11
#define ENTYPO_ICON_QUOTE_LEFT                      0x0000ef12
#define ENTYPO_ICON_QUOTE_RIGHT                     0x0000ef13
#define ENTYPO_ICON_SPINNER                         0x0000ef14
#define ENTYPO_ICON_CIRCLE                          0x0000ef15
#define ENTYPO_ICON_REPLY                           0x0000ef16
#define ENTYPO_ICON_GITHUB                          0x0000ef17
#define ENTYPO_ICON_FOLDER_EMPTY                    0x0000ef18
#define ENTYPO_ICON_FOLDER_OPEN_EMPTY               0x0000ef19
#define ENTYPO_ICON_SMILE                           0x0000ef1a
#define ENTYPO_ICON_FROWN                           0x0000ef1b
#define ENTYPO_ICON_MEH                             0x0000ef1c
#define ENTYPO_ICON_GAMEPAD                         0x0000ef1d
#define ENTYPO_ICON_KEYBOARD                        0x0000ef1e
#define ENTYPO_ICON_FLAG_EMPTY                      0x0000ef1f
#define ENTYPO_ICON_FLAG_CHECKERED                  0x0000ef20
#define ENTYPO_ICON_TERMINAL                        0x0000ef21
#define ENTYPO_ICON_CODE                            0x0000ef22
#define ENTYPO_ICON_REPLY_ALL                       0x0000ef23
#define ENTYPO_ICON_STAR_HALF_ALT                   0x0000ef24
#define ENTYPO_ICON_DIRECTION                       0x0000ef25
#define ENTYPO_ICON_CROP                            0x0000ef26
#define ENTYPO_ICON_FORK                            0x0000ef27
#define ENTYPO_ICON_UNLINK                          0x0000ef28
#define ENTYPO_ICON_HELP                            0x0000ef29
#define ENTYPO_ICON_INFO                            0x0000ef2a
#define ENTYPO_ICON_ATTENTION_ALT                   0x0000ef2b
#define ENTYPO_ICON_SUPERSCRIPT                     0x0000ef2c
#define ENTYPO_ICON_SUBSCRIPT                       0x0000ef2d
#define ENTYPO_ICON_ERASER                          0x0000ef2e
#define ENTYPO_ICON_PUZZLE                          0x0000ef2f
#define ENTYPO_ICON_MIC                             0x0000ef30
#define ENTYPO_ICON_MUTE                            0x0000ef31
#define ENTYPO_ICON_SHIELD                          0x0000ef32
#define ENTYPO_ICON_CALENDAR_EMPTY                  0x0000ef33
#define ENTYPO_ICON_EXTINGUISHER                    0x0000ef34
#define ENTYPO_ICON_ROCKET                          0x0000ef35
#define ENTYPO_ICON_MAXCDN                          0x0000ef36
#define ENTYPO_ICON_ANGLE_CIRCLED_LEFT              0x0000ef37
#define ENTYPO_ICON_ANGLE_CIRCLED_RIGHT             0x0000ef38
#define ENTYPO_ICON_ANGLE_CIRCLED_UP                0x0000ef39
#define ENTYPO_ICON_ANGLE_CIRCLED_DOWN              0x0000ef3a
#define ENTYPO_ICON_HTML5                           0x0000ef3b
#define ENTYPO_ICON_CSS3                            0x0000ef3c
#define ENTYPO_ICON_ANCHOR                          0x0000ef3d
#define ENTYPO_ICON_LOCK_OPEN_ALT                   0x0000ef3e
#define ENTYPO_ICON_BULLSEYE                        0x0000ef3f
#define ENTYPO_ICON_ELLIPSIS                        0x0000ef40
#define ENTYPO_ICON_ELLIPSIS_VERT                   0x0000ef41
#define ENTYPO_ICON_RSS_SQUARED                     0x0000ef42
#define ENTYPO_ICON_PLAY_CIRCLED                    0x0000ef43
#define ENTYPO_ICON_TICKET                          0x0000ef44
#define ENTYPO_ICON_MINUS_SQUARED                   0x0000ef45
#define ENTYPO_ICON_MINUS_SQUARED_ALT               0x0000ef46
#define ENTYPO_ICON_LEVEL_UP                        0x0000ef47
#define ENTYPO_ICON_LEVEL_DOWN                      0x0000ef48
#define ENTYPO_ICON_OK_SQUARED                      0x0000ef49
#define ENTYPO_ICON_PENCIL_SQUARED                  0x0000ef4a
#define ENTYPO_ICON_LINK_EXT_ALT                    0x0000ef4b
#define ENTYPO_ICON_EXPORT_ALT                      0x0000ef4c
#define ENTYPO_ICON_COMPASS                         0x0000ef4d
#define ENTYPO_ICON_EXPAND                          0x0000ef4e
#define ENTYPO_ICON_COLLAPSE                        0x0000ef4f
#define ENTYPO_ICON_EXPAND_RIGHT                    0x0000ef50
#define ENTYPO_ICON_EURO                            0x0000ef51
#define ENTYPO_ICON_POUND                           0x0000ef52
#define ENTYPO_ICON_DOLLAR                          0x0000ef53
#define ENTYPO_ICON_RUPEE                           0x0000ef54
#define ENTYPO_ICON_YEN                             0x0000ef55
#define ENTYPO_ICON_ROUBLE                          0x0000ef56
#define ENTYPO_ICON_WON                             0x0000ef57
#define ENTYPO_ICON_BITCOIN                         0x0000ef58
#define ENTYPO_ICON_DOC_INV                         0x0000ef59
#define ENTYPO_ICON_DOC_TEXT_INV                    0x0000ef5a
#define ENTYPO_ICON_SORT_NAME_UP                    0x0000ef5b
#define ENTYPO_ICON_SORT_NAME_DOWN                  0x0000ef5c
#define ENTYPO_ICON_SORT_ALT_UP                     0x0000ef5d
#define ENTYPO_ICON_SORT_ALT_DOWN                   0x0000ef5e
#define ENTYPO_ICON_SORT_NUMBER_UP                  0x0000ef5f
#define ENTYPO_ICON_SORT_NUMBER_DOWN                0x0000ef60
#define ENTYPO_ICON_THUMBS_UP_ALT                   0x0000ef61
#define ENTYPO_ICON_THUMBS_DOWN_ALT                 0x0000ef62
#define ENTYPO_ICON_YOUTUBE_SQUARED                 0x0000ef63
#define ENTYPO_ICON_YOUTUBE                         0x0000ef64
#define ENTYPO_ICON_XING                            0x0000ef65
#define ENTYPO_ICON_XING_SQUARED                    0x0000ef66
#define ENTYPO_ICON_YOUTUBE_PLAY                    0x0000ef67
#define ENTYPO_ICON_DROPBOX                         0x0000ef68
#define ENTYPO_ICON_STACKOVERFLOW                   0x0000ef69
#define ENTYPO_ICON_INSTAGRAM                       0x0000ef6a
#define ENTYPO_ICON_FLICKR                          0x0000ef6b
#define ENTYPO_ICON_ADN                             0x0000ef6c
#define ENTYPO_ICON_BITBUCKET                       0x0000ef6d
#define ENTYPO_ICON_BITBUCKET_SQUARED               0x0000ef6e
#define ENTYPO_ICON_TUMBLR                          0x0000ef6f
#define ENTYPO_ICON_TUMBLR_SQUARED                  0x0000ef70
#define ENTYPO_ICON_DOWN                            0x0000ef71
#define ENTYPO_ICON_UP                              0x0000ef72
#define ENTYPO_ICON_LEFT                            0x0000ef73
#define ENTYPO_ICON_RIGHT                           0x0000ef74
#define ENTYPO_ICON_APPLE                           0x0000ef75
#define ENTYPO_ICON_WINDOWS                         0x0000ef76
#define ENTYPO_ICON_ANDROID                         0x0000ef77
#define ENTYPO_ICON_LINUX                           0x0000ef78
#define ENTYPO_ICON_DRIBBBLE                        0x0000ef79
#define ENTYPO_ICON_SKYPE                           0x0000ef7a
#define ENTYPO_ICON_FOURSQUARE                      0x0000ef7b
#define ENTYPO_ICON_TRELLO                          0x0000ef7c
#define ENTYPO_ICON_FEMALE                          0x0000ef7d
#define ENTYPO_ICON_MALE                            0x0000ef7e
#define ENTYPO_ICON_GITTIP                          0x0000ef7f
#define ENTYPO_ICON_SUN                             0x0000ef80
#define ENTYPO_ICON_MOON                            0x0000ef81
#define ENTYPO_ICON_BOX                             0x0000ef82
#define ENTYPO_ICON_BUG                             0x0000ef83
#define ENTYPO_ICON_VKONTAKTE                       0x0000ef84
#define ENTYPO_ICON_WEIBO                           0x0000ef85
#define ENTYPO_ICON_RENREN                          0x0000ef86
#define ENTYPO_ICON_PAGELINES                       0x0000ef87
#define ENTYPO_ICON_STACKEXCHANGE                   0x0000ef88
#define ENTYPO_ICON_RIGHT_CIRCLED2                  0x0000ef89
#define ENTYPO_ICON_LEFT_CIRCLED2                   0x0000ef8a
#define ENTYPO_ICON_COLLAPSE_LEFT                   0x0000ef8b
#define ENTYPO_ICON_DOT_CIRCLED                     0x0000ef8c
#define ENTYPO_ICON_WHEELCHAIR                      0x0000ef8d
#define ENTYPO_ICON_VIMEO_SQUARED                   0x0000ef8e
#define ENTYPO_ICON_TRY                             0x0000ef8f
#define ENTYPO_ICON_PLUS_SQUARED_ALT                0x0000ef90
#define ENTYPO_ICON_SPACE_SHUTTLE                   0x0000ef91
#define ENTYPO_ICON_SLACK                           0x0000ef92
#define ENTYPO_ICON_MAIL_SQUARED                    0x0000ef93
#define ENTYPO_ICON_WORDPRESS                       0x0000ef94
#define ENTYPO_ICON_OPENID                          0x0000ef95
#define ENTYPO_ICON_BANK                            0x0000ef96
#define ENTYPO_ICON_GRADUATION_CAP                  0x0000ef97
#define ENTYPO_ICON_YAHOO                           0x0000ef98
#define ENTYPO_ICON_GOOGLE                          0x0000ef99
#define ENTYPO_ICON_REDDIT                          0x0000ef9a
#define ENTYPO_ICON_REDDIT_SQUARED                  0x0000ef9b
#define ENTYPO_ICON_STUMBLEUPON_CIRCLED             0x0000ef9c
#define ENTYPO_ICON_STUMBLEUPON                     0x0000ef9d
#define ENTYPO_ICON_DELICIOUS                       0x0000ef9e
#define ENTYPO_ICON_DIGG                            0x0000ef9f
#define ENTYPO_ICON_PIED_PIPER_SQUARED              0x0000efa0
#define ENTYPO_ICON_PIED_PIPER_ALT                  0x0000efa1
#define ENTYPO_ICON_DRUPAL                          0x0000efa2
#define ENTYPO_ICON_JOOMLA                          0x0000efa3
#define ENTYPO_ICON_LANGUAGE                        0x0000efa4
#define ENTYPO_ICON_FAX                             0x0000efa5
#define ENTYPO_ICON_BUILDING_FILLED                 0x0000efa6
#define ENTYPO_ICON_CHILD                           0x0000efa7
#define ENTYPO_ICON_PAW                             0x0000efa8
#define ENTYPO_ICON_SPOON                           0x0000efa9
#define ENTYPO_ICON_CUBE                            0x0000efaa
#define ENTYPO_ICON_CUBES                           0x0000efab
#define ENTYPO_ICON_BEHANCE                         0x0000efac
#define ENTYPO_ICON_BEHANCE_SQUARED                 0x0000efad
#define ENTYPO_ICON_STEAM                           0x0000efae
#define ENTYPO_ICON_STEAM_SQUARED                   0x0000efaf
#define ENTYPO_ICON_RECYCLE                         0x0000efb0
#define ENTYPO_ICON_CAB                             0x0000efb1
#define ENTYPO_ICON_TAXI                            0x0000efb2
#define ENTYPO_ICON_TREE                            0x0000efb3
#define ENTYPO_ICON_SPOTIFY                         0x0000efb4
#define ENTYPO_ICON_DEVIANTART                      0x0000efb5
#define ENTYPO_ICON_SOUNDCLOUD                      0x0000efb6
#define ENTYPO_ICON_DATABASE                        0x0000efb7
#define ENTYPO_ICON_FILE_PDF                        0x0000efb8
#define ENTYPO_ICON_FILE_WORD                       0x0000efb9
#define ENTYPO_ICON_FILE_EXCEL                      0x0000efba
#define ENTYPO_ICON_FILE_POWERPOINT                 0x0000efbb
#define ENTYPO_ICON_FILE_IMAGE                      0x0000efbc
#define ENTYPO_ICON_FILE_ARCHIVE                    0x0000efbd
#define ENTYPO_ICON_FILE_AUDIO                      0x0000efbe
#define ENTYPO_ICON_FILE_VIDEO                      0x0000efbf
#define ENTYPO_ICON_FILE_CODE                       0x0000efc0
#define ENTYPO_ICON_VINE                            0x0000efc1
#define ENTYPO_ICON_CODEOPEN                        0x0000efc2
#define ENTYPO_ICON_JSFIDDLE                        0x0000efc3
#define ENTYPO_ICON_LIFEBUOY                        0x0000efc4
#define ENTYPO_ICON_CIRCLE_NOTCH                    0x0000efc5
#define ENTYPO_ICON_REBEL                           0x0000efc6
#define ENTYPO_ICON_EMPIRE                          0x0000efc7
#define ENTYPO_ICON_GIT_SQUARED                     0x0000efc8
#define ENTYPO_ICON_GIT                             0x0000efc9
#define ENTYPO_ICON_HACKER_NEWS                     0x0000efca
#define ENTYPO_ICON_TENCENT_WEIBO                   0x0000efcb
#define ENTYPO_ICON_QQ                              0x0000efcc
#define ENTYPO_ICON_WECHAT                          0x0000efcd
#define ENTYPO_ICON_PAPER_PLANE                     0x0000efce
#define ENTYPO_ICON_PAPER_PLANE_EMPTY               0x0000efcf
#define ENTYPO_ICON_HISTORY                         0x0000efd0
#define ENTYPO_ICON_CIRCLE_THIN                     0x0000efd1
#define ENTYPO_ICON_HEADER                          0x0000efd2
#define ENTYPO_ICON_PARAGRAPH                       0x0000efd3
#define ENTYPO_ICON_SLIDERS                         0x0000efd4
#define ENTYPO_ICON_SHARE                           0x0000efd5
#define ENTYPO_ICON_SHARE_SQUARED                   0x0000efd6
#define ENTYPO_ICON_BOMB                            0x0000efd7
#define ENTYPO_ICON_SOCCER_BALL                     0x0000efd8
#define ENTYPO_ICON_TTY                             0x0000efd9
#define ENTYPO_ICON_BINOCULARS                      0x0000efda
#define ENTYPO_ICON_PLUG                            0x0000efdb
#define ENTYPO_ICON_SLIDESHARE                      0x0000efdc
#define ENTYPO_ICON_TWITCH                          0x0000efdd
#define ENTYPO_ICON_YELP                            0x0000efde
#define ENTYPO_ICON_NEWSPAPER                       0x0000efdf
#define ENTYPO_ICON_WIFI                            0x0000efe0
#define ENTYPO_ICON_CALC                            0x0000efe1
#define ENTYPO_ICON_PAYPAL                          0x0000efe2
#define ENTYPO_ICON_GWALLET                         0x0000efe3
#define ENTYPO_ICON_CC_VISA                         0x0000efe4
#define ENTYPO_ICON_CC_MASTERCARD                   0x0000efe5
#define ENTYPO_ICON_CC_DISCOVER                     0x0000efe6
#define ENTYPO_ICON_CC_AMEX                         0x0000efe7
#define ENTYPO_ICON_CC_PAYPAL                       0x0000efe8
#define ENTYPO_ICON_CC_STRIPE                       0x0000efe9
#define ENTYPO_ICON_BELL_OFF                        0x0000efea
#define ENTYPO_ICON_BELL_OFF_EMPTY                  0x0000efeb
#define ENTYPO_ICON_TRASH                           0x0000efec
#define ENTYPO_ICON_COPYRIGHT                       0x0000efed
#define ENTYPO_ICON_AT                              0x0000efee
#define ENTYPO_ICON_EYEDROPPER                      0x0000efef
#define ENTYPO_ICON_BRUSH                           0x0000eff0
#define ENTYPO_ICON_BIRTHDAY                        0x0000eff1
#define ENTYPO_ICON_CHART_AREA                      0x0000eff2
#define ENTYPO_ICON_CHART_PIE                       0x0000eff3
#define ENTYPO_ICON_CHART_LINE                      0x0000eff4
#define ENTYPO_ICON_LASTFM                          0x0000eff5
#define ENTYPO_ICON_LASTFM_SQUARED                  0x0000eff6
#define ENTYPO_ICON_TOGGLE_OFF                      0x0000eff7
#define ENTYPO_ICON_TOGGLE_ON                       0x0000eff8
#define ENTYPO_ICON_BICYCLE                         0x0000eff9
#define ENTYPO_ICON_BUS                             0x0000effa
#define ENTYPO_ICON_IOXHOST                         0x0000effb
#define ENTYPO_ICON_ANGELLIST                       0x0000effc
#define ENTYPO_ICON_CC                              0x0000effd
#define ENTYPO_ICON_SHEKEL                          0x0000effe
#define ENTYPO_ICON_MEANPATH                        0x0000efff
#define ENTYPO_ICON_BUYSELLADS                      0x0000f000
#define ENTYPO_ICON_CONNECTDEVELOP                  0x0000f001
#define ENTYPO_ICON_DASHCUBE                        0x0000f002
#define ENTYPO_ICON_FORUMBEE                        0x0000f003
#define ENTYPO_ICON_LEANPUB                         0x0000f004
#define ENTYPO_ICON_SELLSY                          0x0000f005
#define ENTYPO_ICON_SHIRTSINBULK                    0x0000f006
#define ENTYPO_ICON_SIMPLYBUILT                     0x0000f007
#define ENTYPO_ICON_SKYATLAS                        0x0000f008
#define ENTYPO_ICON_CART_PLUS                       0x0000f009
#define ENTYPO_ICON_CART_ARROW_DOWN                 0x0000f00a
#define ENTYPO_ICON_DIAMOND                         0x0000f00b
#define ENTYPO_ICON_SHIP                            0x0000f00c
#define ENTYPO_ICON_USER_SECRET                     0x0000f00d
#define ENTYPO_ICON_MOTORCYCLE                      0x0000f00e
#define ENTYPO_ICON_STREET_VIEW                     0x0000f00f
#define ENTYPO_ICON_HEARTBEAT                       0x0000f010
#define ENTYPO_ICON_VENUS                           0x0000f011
#define ENTYPO_ICON_MARS                            0x0000f012
#define ENTYPO_ICON_MERCURY                         0x0000f013
#define ENTYPO_ICON_TRANSGENDER                     0x0000f014
#define ENTYPO_ICON_TRANSGENDER_ALT                 0x0000f015
#define ENTYPO_ICON_VENUS_DOUBLE                    0x0000f016
#define ENTYPO_ICON_MARS_DOUBLE                     0x0000f017
#define ENTYPO_ICON_VENUS_MARS                      0x0000f018
#define ENTYPO_ICON_MARS_STROKE                     0x0000f019
#define ENTYPO_ICON_MARS_STROKE_V                   0x0000f01a
#define ENTYPO_ICON_MARS_STROKE_H                   0x0000f01b
#define ENTYPO_ICON_NEUTER                          0x0000f01c
#define ENTYPO_ICON_GENDERLESS                      0x0000f01d
#define ENTYPO_ICON_FACEBOOK_OFFICIAL               0x0000f01e
#define ENTYPO_ICON_PINTEREST                       0x0000f01f
#define ENTYPO_ICON_WHATSAPP                        0x0000f020
#define ENTYPO_ICON_SERVER                          0x0000f021
#define ENTYPO_ICON_USER_PLUS                       0x0000f022
#define ENTYPO_ICON_USER_TIMES                      0x0000f023
#define ENTYPO_ICON_BED                             0x0000f024
#define ENTYPO_ICON_VIACOIN                         0x0000f025
#define ENTYPO_ICON_TRAIN                           0x0000f026
#define ENTYPO_ICON_SUBWAY                          0x0000f027
#define ENTYPO_ICON_MEDIUM                          0x0000f028
#define ENTYPO_ICON_Y_COMBINATOR                    0x0000f029
#define ENTYPO_ICON_OPTIN_MONSTER                   0x0000f02a
#define ENTYPO_ICON_OPENCART                        0x0000f02b
#define ENTYPO_ICON_EXPEDITEDSSL                    0x0000f02c
#define ENTYPO_ICON_BATTERY_4                       0x0000f02d
#define ENTYPO_ICON_BATTERY_3                       0x0000f02e
#define ENTYPO_ICON_BATTERY_2                       0x0000f02f
#define ENTYPO_ICON_BATTERY_1                       0x0000f030
#define ENTYPO_ICON_BATTERY_0                       0x0000f031
#define ENTYPO_ICON_MOUSE_POINTER                   0x0000f032
#define ENTYPO_ICON_I_CURSOR                        0x0000f033
#define ENTYPO_ICON_OBJECT_GROUP                    0x0000f034
#define ENTYPO_ICON_OBJECT_UNGROUP                  0x0000f035
#define ENTYPO_ICON_STICKY_NOTE                     0x0000f036
#define ENTYPO_ICON_STICKY_NOTE_O                   0x0000f037
#define ENTYPO_ICON_CC_JCB                          0x0000f038
#define ENTYPO_ICON_CC_DINERS_CLUB                  0x0000f039
#define ENTYPO_ICON_CLONE                           0x0000f03a
#define ENTYPO_ICON_BALANCE_SCALE                   0x0000f03b
#define ENTYPO_ICON_HOURGLASS_O                     0x0000f03c
#define ENTYPO_ICON_HOURGLASS_1                     0x0000f03d
#define ENTYPO_ICON_HOURGLASS_2                     0x0000f03e
#define ENTYPO_ICON_HOURGLASS_3                     0x0000f03f
#define ENTYPO_ICON_HOURGLASS                       0x0000f040
#define ENTYPO_ICON_HAND_GRAB_O                     0x0000f041
#define ENTYPO_ICON_HAND_PAPER_O                    0x0000f042
#define ENTYPO_ICON_HAND_SCISSORS_O                 0x0000f043
#define ENTYPO_ICON_HAND_LIZARD_O                   0x0000f044
#define ENTYPO_ICON_HAND_SPOCK_O                    0x0000f045
#define ENTYPO_ICON_HAND_POINTER_O                  0x0000f046
#define ENTYPO_ICON_HAND_PEACE_O                    0x0000f047
#define ENTYPO_ICON_TRADEMARK                       0x0000f048
#define ENTYPO_ICON_REGISTERED                      0x0000f049
#define ENTYPO_ICON_CREATIVE_COMMONS                0x0000f04a
#define ENTYPO_ICON_GG                              0x0000f04b
#define ENTYPO_ICON_GG_CIRCLE                       0x0000f04c
#define ENTYPO_ICON_TRIPADVISOR                     0x0000f04d
#define ENTYPO_ICON_ODNOKLASSNIKI                   0x0000f04e
#define ENTYPO_ICON_ODNOKLASSNIKI_SQUARE            0x0000f04f
#define ENTYPO_ICON_GET_POCKET                      0x0000f050
#define ENTYPO_ICON_WIKIPEDIA_W                     0x0000f051
#define ENTYPO_ICON_SAFARI                          0x0000f052
#define ENTYPO_ICON_CHROME                          0x0000f053
#define ENTYPO_ICON_FIREFOX                         0x0000f054
#define ENTYPO_ICON_OPERA                           0x0000f055
#define ENTYPO_ICON_INTERNET_EXPLORER               0x0000f056
#define ENTYPO_ICON_TELEVISION                      0x0000f057
#define ENTYPO_ICON_CONTAO                          0x0000f058
#define ENTYPO_ICON_500PX                           0x0000f059
#define ENTYPO_ICON_AMAZON                          0x0000f05a
#define ENTYPO_ICON_CALENDAR_PLUS_O                 0x0000f05b
#define ENTYPO_ICON_CALENDAR_MINUS_O                0x0000f05c
#define ENTYPO_ICON_CALENDAR_TIMES_O                0x0000f05d
#define ENTYPO_ICON_CALENDAR_CHECK_O                0x0000f05e
#define ENTYPO_ICON_INDUSTRY                        0x0000f05f
#define ENTYPO_ICON_MAP_PIN                         0x0000f060
#define ENTYPO_ICON_MAP_SIGNS                       0x0000f061
#define ENTYPO_ICON_MAP_O                           0x0000f062
#define ENTYPO_ICON_MAP                             0x0000f063
#define ENTYPO_ICON_COMMENTING                      0x0000f064
#define ENTYPO_ICON_COMMENTING_O                    0x0000f065
#define ENTYPO_ICON_HOUZZ                           0x0000f066
#define ENTYPO_ICON_VIMEO                           0x0000f067
#define ENTYPO_ICON_BLACK_TIE                       0x0000f068
#define ENTYPO_ICON_FONTICONS                       0x0000f069
#define ENTYPO_ICON_REDDIT_ALIEN                    0x0000f06a
#define ENTYPO_ICON_EDGE                            0x0000f06b
#define ENTYPO_ICON_CREDIT_CARD_ALT                 0x0000f06c
#define ENTYPO_ICON_CODIEPIE                        0x0000f06d
#define ENTYPO_ICON_MODX                            0x0000f06e
#define ENTYPO_ICON_FORT_AWESOME                    0x0000f06f
#define ENTYPO_ICON_USB                             0x0000f070
#define ENTYPO_ICON_PRODUCT_HUNT                    0x0000f071
#define ENTYPO_ICON_MIXCLOUD                        0x0000f072
#define ENTYPO_ICON_SCRIBD                          0x0000f073
#define ENTYPO_ICON_PAUSE_CIRCLE                    0x0000f074
#define ENTYPO_ICON_PAUSE_CIRCLE_O                  0x0000f075
#define ENTYPO_ICON_STOP_CIRCLE                     0x0000f076
#define ENTYPO_ICON_STOP_CIRCLE_O                   0x0000f077
#define ENTYPO_ICON_SHOPPING_BAG                    0x0000f078
#define ENTYPO_ICON_SHOPPING_BASKET                 0x0000f079
#define ENTYPO_ICON_HASHTAG                         0x0000f07a
#define ENTYPO_ICON_BLUETOOTH                       0x0000f07b
#define ENTYPO_ICON_BLUETOOTH_B                     0x0000f07c
#define ENTYPO_ICON_PERCENT                         0x0000f07d
#define ENTYPO_ICON_GITLAB                          0x0000f07e
#define ENTYPO_ICON_WPBEGINNER                      0x0000f07f
#define ENTYPO_ICON_WPFORMS                         0x0000f080
#define ENTYPO_ICON_ENVIRA                          0x0000f081
#define ENTYPO_ICON_UNIVERSAL_ACCESS                0x0000f082
#define ENTYPO_ICON_WHEELCHAIR_ALT                  0x0000f083
#define ENTYPO_ICON_QUESTION_CIRCLE_O               0x0000f084
#define ENTYPO_ICON_BLIND                           0x0000f085
#define ENTYPO_ICON_AUDIO_DESCRIPTION               0x0000f086
#define ENTYPO_ICON_VOLUME_CONTROL_PHONE            0x0000f087
#define ENTYPO_ICON_BRAILLE                         0x0000f088
#define ENTYPO_ICON_ASSISTIVE_LISTENING_SYSTEMS     0x0000f089
#define ENTYPO_ICON_AMERICAN_SIGN_LANGUAGE_INTERPRETING  0x0000f08a
#define ENTYPO_ICON_ASL_INTERPRETING                0x0000f08b
#define ENTYPO_ICON_GLIDE                           0x0000f08c
#define ENTYPO_ICON_GLIDE_G                         0x0000f08d
#define ENTYPO_ICON_SIGN_LANGUAGE                   0x0000f08e
#define ENTYPO_ICON_LOW_VISION                      0x0000f08f
#define ENTYPO_ICON_VIADEO                          0x0000f090
#define ENTYPO_ICON_VIADEO_SQUARE                   0x0000f091
#define ENTYPO_ICON_SNAPCHAT                        0x0000f092
#define ENTYPO_ICON_SNAPCHAT_GHOST                  0x0000f093
#define ENTYPO_ICON_SNAPCHAT_SQUARE                 0x0000f094
#define ENTYPO_ICON_PIED_PIPER                      0x0000f095
#define ENTYPO_ICON_FIRST_ORDER                     0x0000f096
#define ENTYPO_ICON_YOAST                           0x0000f097
#define ENTYPO_ICON_THEMEISLE                       0x0000f098
#define ENTYPO_ICON_GOOGLE_PLUS_CIRCLE              0x0000f099
#define ENTYPO_ICON_FONT_AWESOME                    0x0000f09a
#define ENTYPO_ICON_HANDSHAKE_O                     0x0000f09b
#define ENTYPO_ICON_ENVELOPE_OPEN                   0x0000f09c
#define ENTYPO_ICON_ENVELOPE_OPEN_O                 0x0000f09d
#define ENTYPO_ICON_LINODE                          0x0000f09e
#define ENTYPO_ICON_ADDRESS_BOOK                    0x0000f09f
#define ENTYPO_ICON_ADDRESS_BOOK_O                  0x0000f0a0
#define ENTYPO_ICON_ADDRESS_CARD                    0x0000f0a1
#define ENTYPO_ICON_ADDRESS_CARD_O                  0x0000f0a2
#define ENTYPO_ICON_USER_CIRCLE                     0x0000f0a3
#define ENTYPO_ICON_USER_CIRCLE_O                   0x0000f0a4
#define ENTYPO_ICON_USER_O                          0x0000f0a5
#define ENTYPO_ICON_ID_BADGE                        0x0000f0a6
#define ENTYPO_ICON_ID_CARD                         0x0000f0a7
#define ENTYPO_ICON_ID_CARD_O                       0x0000f0a8
#define ENTYPO_ICON_QUORA                           0x0000f0a9
#define ENTYPO_ICON_FREE_CODE_CAMP                  0x0000f0aa
#define ENTYPO_ICON_TELEGRAM                        0x0000f0ab
#define ENTYPO_ICON_THERMOMETER                     0x0000f0ac
#define ENTYPO_ICON_THERMOMETER_3                   0x0000f0ad
#define ENTYPO_ICON_THERMOMETER_2                   0x0000f0ae
#define ENTYPO_ICON_THERMOMETER_QUARTER             0x0000f0af
#define ENTYPO_ICON_THERMOMETER_0                   0x0000f0b0
#define ENTYPO_ICON_SHOWER                          0x0000f0b1
#define ENTYPO_ICON_BATH                            0x0000f0b2
#define ENTYPO_ICON_PODCAST                         0x0000f0b3
#define ENTYPO_ICON_WINDOW_MAXIMIZE                 0x0000f0b4
#define ENTYPO_ICON_WINDOW_MINIMIZE                 0x0000f0b5
#define ENTYPO_ICON_WINDOW_RESTORE                  0x0000f0b6
#define ENTYPO_ICON_WINDOW_CLOSE                    0x0000f0b7
#define ENTYPO_ICON_WINDOW_CLOSE_O                  0x0000f0b8
#define ENTYPO_ICON_BANDCAMP                        0x0000f0b9
#define ENTYPO_ICON_GRAV                            0x0000f0ba
#define ENTYPO_ICON_ETSY                            0x0000f0bb
#define ENTYPO_ICON_IMDB                            0x0000f0bc
#define ENTYPO_ICON_RAVELRY                         0x0000f0bd
#define ENTYPO_ICON_EERCAST                         0x0000f0be
#define ENTYPO_ICON_MICROCHIP                       0x0000f0bf
#define ENTYPO_ICON_SNOWFLAKE_O                     0x0000f0c0
#define ENTYPO_ICON_SUPERPOWERS                     0x0000f0c1
#define ENTYPO_ICON_WPEXPLORER                      0x0000f0c2
#define ENTYPO_ICON_MEETUP                          0x0000f0c3
#define ENTYPO_ICON_GITHUB_SQUARED                  0x0000f0c4
#define ENTYPO_ICON_GITHUB_CIRCLED_1                0x0000f0c5
#define ENTYPO_ICON_TWITTER_3                       0x0000f0c6
#define ENTYPO_ICON_FLICKR_1                        0x0000f0c7
#define ENTYPO_ICON_TWITTER_SQUARED                 0x0000f0c8
#define ENTYPO_ICON_YANDEX                          0x0000f0c9
#define ENTYPO_ICON_VIMEO_1                         0x0000f0ca
#define ENTYPO_ICON_VIMEO_CIRCLED                   0x0000f0cb
#define ENTYPO_ICON_FACEBOOK_SQUARED                0x0000f0cc
#define ENTYPO_ICON_TWITTER_1                       0x0000f0cd
#define ENTYPO_ICON_TWITTER_CIRCLED                 0x0000f0ce
#define ENTYPO_ICON_SKYPE_4                         0x0000f0cf
#define ENTYPO_ICON_LINKEDIN_SQUARED                0x0000f0d0
#define ENTYPO_ICON_FACEBOOK_CIRCLED                0x0000f0d1
#define ENTYPO_ICON_FACEBOOK_SQUARED_1              0x0000f0d2
#define ENTYPO_ICON_GPLUS_1                         0x0000f0d3
#define ENTYPO_ICON_GPLUS_CIRCLED                   0x0000f0d4
#define ENTYPO_ICON_TUMBLR_3                        0x0000f0d5
#define ENTYPO_ICON_PINTEREST_1                     0x0000f0d6
#define ENTYPO_ICON_PINTEREST_CIRCLED_1             0x0000f0d7
#define ENTYPO_ICON_TWITTER_RECT                    0x0000f0d8
#define ENTYPO_ICON_TUMBLR_1                        0x0000f0d9
#define ENTYPO_ICON_TUMBLR_CIRCLED                  0x0000f0da
#define ENTYPO_ICON_JABBER                          0x0000f0db
#define ENTYPO_ICON_LINKEDIN_1                      0x0000f0dc
#define ENTYPO_ICON_LINKEDIN_CIRCLED                0x0000f0dd
#define ENTYPO_ICON_LINKEDIN_5                      0x0000f0de
#define ENTYPO_ICON_DRIBBBLE_1                      0x0000f0df
#define ENTYPO_ICON_DRIBBBLE_CIRCLED                0x0000f0e0
#define ENTYPO_ICON_WORDPRESS_2                     0x0000f0e1
#define ENTYPO_ICON_STUMBLEUPON_1                   0x0000f0e2
#define ENTYPO_ICON_STUMBLEUPON_CIRCLED_1           0x0000f0e3
#define ENTYPO_ICON_DIIGO                           0x0000f0e4
#define ENTYPO_ICON_LASTFM_1                        0x0000f0e5
#define ENTYPO_ICON_LASTFM_CIRCLED                  0x0000f0e6
#define ENTYPO_ICON_TUDOU                           0x0000f0e7
#define ENTYPO_ICON_RDIO                            0x0000f0e8
#define ENTYPO_ICON_RDIO_CIRCLED                    0x0000f0e9
#define ENTYPO_ICON_AMEX                            0x0000f0ea
#define ENTYPO_ICON_SPOTIFY_1                       0x0000f0eb
#define ENTYPO_ICON_SPOTIFY_CIRCLED                 0x0000f0ec
#define ENTYPO_ICON_MASTERCARD                      0x0000f0ed
#define ENTYPO_ICON_QQ_1                            0x0000f0ee
#define ENTYPO_ICON_BANDCAMP_1                      0x0000f0ef
#define ENTYPO_ICON_CODEPEN                         0x0000f0f0
#define ENTYPO_ICON_INSTAGRAM_1                     0x0000f0f1
#define ENTYPO_ICON_DROPBOX_1                       0x0000f0f2
#define ENTYPO_ICON_EVERNOTE                        0x0000f0f3
#define ENTYPO_ICON_FLATTR                          0x0000f0f4
#define ENTYPO_ICON_SKYPE_1                         0x0000f0f5
#define ENTYPO_ICON_SKYPE_CIRCLED                   0x0000f0f6
#define ENTYPO_ICON_RENREN_1                        0x0000f0f7
#define ENTYPO_ICON_SINA_WEIBO                      0x0000f0f8
#define ENTYPO_ICON_PAYPAL_1                        0x0000f0f9
#define ENTYPO_ICON_PICASA                          0x0000f0fa
#define ENTYPO_ICON_SOUNDCLOUD_1                    0x0000f0fb
#define ENTYPO_ICON_MIXI                            0x0000f0fc
#define ENTYPO_ICON_BEHANCE_1                       0x0000f0fd
#define ENTYPO_ICON_GOOGLE_CIRCLES                  0x0000f0fe
#define ENTYPO_ICON_VKONTAKTE_1                     0x0000f0ff
#define ENTYPO_ICON_SMASHING                        0x0000f100
#define ENTYPO_ICON_COMMENT_4                       0x0000f101
#define ENTYPO_ICON_FOLDER_OPEN_EMPTY_1             0x0000f102
#define ENTYPO_ICON_CALENDAR_5                      0x0000f103
#define ENTYPO_ICON_NEWSPAPER_2                     0x0000f104
#define ENTYPO_ICON_CAMERA_5                        0x0000f105
#define ENTYPO_ICON_SEARCH_5                        0x0000f106
#define ENTYPO_ICON_LOCK_ALT                        0x0000f107
#define ENTYPO_ICON_LOCK_5                          0x0000f108
#define ENTYPO_ICON_LOCK_OPEN_5                     0x0000f109
#define ENTYPO_ICON_JOYSTICK                        0x0000f10a
#define ENTYPO_ICON_FIRE_1                          0x0000f10b
#define ENTYPO_ICON_CHART_BAR_5                     0x0000f10c
#define ENTYPO_ICON_SPREAD                          0x0000f10d
#define ENTYPO_ICON_SPINNER1                        0x0000f10e
#define ENTYPO_ICON_SPINNER2                        0x0000f10f
#define ENTYPO_ICON_DB_SHAPE                        0x0000f110
#define ENTYPO_ICON_SWEDEN                          0x0000f111
#define ENTYPO_ICON_LOGO_DB                         0x0000f112

#endif // DOXYGEN_SHOULD_SKIP_THIS
