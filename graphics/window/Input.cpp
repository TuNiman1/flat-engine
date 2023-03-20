#include "Input.h"

#include <SDL2/SDL_events.h>

#include "Window.h"

namespace fl
{
    Input::Input(Window *window, const InputCodes &input_codes) : m_window(window), m_keyStates(), m_keyEvents(), m_buttonStates(), m_buttonEvents(), m_mouseX(0.0), m_mouseY(0.0), m_mouseScroll(0.0), m_mouseLX(0.0), m_mouseLY(0.0), m_mouseLScroll(0.0), m_mouseDX(0.0), m_mouseDY(0.0), m_mouseDScroll(0.0)
    {

        // Input codes wrote according to https://www.glfw.org/docs/3.3/group__keys.html
        if (input_codes == INPUT_GLFW)
        {
            KEY_UNK = -1;
            KEY_ESCAPE = 256;
            KEY_F1 = 290;
            KEY_F2 = 291;
            KEY_F3 = 292;
            KEY_F4 = 293;
            KEY_F5 = 294;
            KEY_F6 = 295;
            KEY_F7 = 296;
            KEY_F8 = 297;
            KEY_F9 = 298;
            KEY_F10 = 299;
            KEY_F11 = 300;
            KEY_F12 = 301;
            KEY_GA = 96;
            KEY_NUM_0 = 48;
            KEY_NUM_1 = 49;
            KEY_NUM_2 = 50;
            KEY_NUM_3 = 51;
            KEY_NUM_4 = 52;
            KEY_NUM_5 = 53;
            KEY_NUM_6 = 54;
            KEY_NUM_7 = 55;
            KEY_NUM_8 = 56;
            KEY_NUM_9 = 57;
            KEY_MIN = 45;
            KEY_EQL = 61;
            KEY_BSPACE = 259;
            KEY_A = 65;
            KEY_B = 66;
            KEY_C = 67;
            KEY_D = 68;
            KEY_E = 69;
            KEY_F = 70;
            KEY_G = 71;
            KEY_H = 72;
            KEY_I = 73;
            KEY_J = 74;
            KEY_K = 75;
            KEY_L = 76;
            KEY_M = 77;
            KEY_N = 78;
            KEY_O = 79;
            KEY_P = 80;
            KEY_Q = 81;
            KEY_R = 82;
            KEY_S = 83;
            KEY_T = 84;
            KEY_U = 85;
            KEY_V = 86;
            KEY_W = 87;
            KEY_X = 88;
            KEY_Y = 89;
            KEY_Z = 90;
            KEY_TAB = 258;
            KEY_LBR = 91;
            KEY_RBR = 93;
            KEY_BSLASH = 92;
            KEY_CPSLK = 280;
            KEY_SCOLON = 59;
            KEY_APO = 39;
            KEY_ENTER = 257;
            KEY_LSHIFT = 340;
            KEY_COMMA = 44;
            KEY_PERIOD = 46;
            KEY_SLASH = 47;
            KEY_RSHIFT = 344;
            KEY_LCTRL = 341;
            KEY_LSUPER = 343;
            KEY_SPACE = 32;
            KEY_RALT = 346;
            KEY_RSUPER = 347;
            KEY_MENU = 348;
            KEY_RCTRL = 345;

            KEY_PRTSCR = 283;
            KEY_SCRLLCK = 281;
            KEY_PAUSE = 284;
            KEY_INSERT = 260;
            KEY_HOME = 268;
            KEY_PGUP = 266;
            KEY_DEL = 261;
            KEY_END = 269;
            KEY_PGDN = 267;

            KEY_UP = 265;
            KEY_DOWN = 264;
            KEY_LEFT = 263;
            KEY_RIGHT = 262;

            NPAD_KEY_NLOCK = 282;
            NPAD_KEY_DIVIDE = 331;
            NPAD_KEY_MUL = 332;
            NPAD_KEY_SUB = 333;
            NPAD_KEY_ADD = 334;
            NPAD_KEY_ENTER = 335;
            NPAD_KEY_0 = 320;
            NPAD_KEY_1 = 321;
            NPAD_KEY_2 = 322;
            NPAD_KEY_3 = 323;
            NPAD_KEY_4 = 324;
            NPAD_KEY_5 = 325;
            NPAD_KEY_6 = 326;
            NPAD_KEY_7 = 327;
            NPAD_KEY_8 = 328;
            NPAD_KEY_9 = 329;
            NPAD_KEY_DECIMAL = 330;

            MOUSE_BTN_1 = 0;
            MOUSE_BTN_2 = 1;
            MOUSE_BTN_3 = 2;
            MOUSE_BTN_4 = 3;
            MOUSE_BTN_5 = 4;
            MOUSE_BTN_6 = 5;
            MOUSE_BTN_7 = 6;
            MOUSE_BTN_8 = 7;
            MOUSE_BTN_LAST = MOUSE_BTN_8;
            MOUSE_BTN_LEFT = MOUSE_BTN_1;
            MOUSE_BTN_RIGHT = MOUSE_BTN_2;
            MOUSE_BTN_MIDDLE = MOUSE_BTN_3;
        }
        else if (input_codes == INPUT_SDL)
        {
        }
    }
}