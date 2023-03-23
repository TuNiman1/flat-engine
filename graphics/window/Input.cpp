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
            KEY_UNK = SDLK_UNKNOWN;
            KEY_ESCAPE = SDLK_ESCAPE;
            KEY_F1 = SDLK_F1;
            KEY_F2 = SDLK_F2;
            KEY_F3 = SDLK_F3;
            KEY_F4 = SDLK_F4;
            KEY_F5 = SDLK_F5;
            KEY_F6 = SDLK_F6;
            KEY_F7 = SDLK_F7;
            KEY_F8 = SDLK_F8;
            KEY_F9 = SDLK_F9;
            KEY_F10 = SDLK_F10;
            KEY_F11 = SDLK_F11;
            KEY_F12 = SDLK_F12;
            KEY_GA = SDLK_UNKNOWN;
            KEY_NUM_0 = SDLK_0;
            KEY_NUM_1 = SDLK_1;
            KEY_NUM_2 = SDLK_2;
            KEY_NUM_3 = SDLK_3;
            KEY_NUM_4 = SDLK_4;
            KEY_NUM_5 = SDLK_5;
            KEY_NUM_6 = SDLK_6;
            KEY_NUM_7 = SDLK_7;
            KEY_NUM_8 = SDLK_8;
            KEY_NUM_9 = SDLK_9;
            KEY_MIN = SDLK_MINUS;
            KEY_EQL = SDLK_EQUALS;
            KEY_BSPACE = SDLK_BACKSPACE;
            KEY_A = SDLK_a;
            KEY_B = SDLK_b;
            KEY_C = SDLK_c;
            KEY_D = SDLK_d;
            KEY_E = SDLK_e;
            KEY_F = SDLK_f;
            KEY_G = SDLK_g;
            KEY_H = SDLK_h;
            KEY_I = SDLK_i;
            KEY_J = SDLK_j;
            KEY_K = SDLK_k;
            KEY_L = SDLK_l;
            KEY_M = SDLK_m;
            KEY_N = SDLK_n;
            KEY_O = SDLK_o;
            KEY_P = SDLK_p;
            KEY_Q = SDLK_q;
            KEY_R = SDLK_r;
            KEY_S = SDLK_s;
            KEY_T = SDLK_t;
            KEY_U = SDLK_u;
            KEY_V = SDLK_v;
            KEY_W = SDLK_w;
            KEY_X = SDLK_x;
            KEY_Y = SDLK_y;
            KEY_Z = SDLK_z;
            KEY_TAB = SDLK_TAB;
            KEY_LBR = SDLK_LEFTBRACKET;
            KEY_RBR = SDLK_RIGHTBRACKET;
            KEY_BSLASH = SDLK_BACKSLASH;
            KEY_CPSLK = SDLK_CAPSLOCK;
            KEY_SCOLON = SDLK_SEMICOLON;
            KEY_APO = SDLK_UNKNOWN;
            KEY_ENTER = SDLK_RETURN;
            KEY_LSHIFT = SDLK_LSHIFT;
            KEY_COMMA = SDLK_COMMA;
            KEY_PERIOD = SDLK_PERIOD;
            KEY_SLASH = SDLK_SLASH;
            KEY_RSHIFT = SDLK_RSHIFT;
            KEY_LCTRL = SDLK_LCTRL;
            KEY_LSUPER = SDLK_UNKNOWN;
            KEY_SPACE = SDLK_SPACE;
            KEY_RALT = SDLK_RALT;
            KEY_RSUPER = SDLK_UNKNOWN;
            KEY_MENU = SDLK_MENU;
            KEY_RCTRL = SDLK_RCTRL;

            KEY_PRTSCR = SDLK_PRINTSCREEN;
            KEY_SCRLLCK = SDLK_SCROLLLOCK;
            KEY_PAUSE = SDLK_PAUSE;
            KEY_INSERT = SDLK_INSERT;
            KEY_HOME = SDLK_HOME;
            KEY_PGUP = SDLK_PAGEUP;
            KEY_DEL = SDLK_DELETE;
            KEY_END = SDLK_END;
            KEY_PGDN = SDLK_PAGEDOWN;

            KEY_UP = SDLK_UP;
            KEY_DOWN = SDLK_DOWN;
            KEY_LEFT = SDLK_LEFT;
            KEY_RIGHT = SDLK_RIGHT;

            NPAD_KEY_NLOCK = SDLK_NUMLOCKCLEAR;
            NPAD_KEY_DIVIDE = SDLK_KP_DIVIDE;
            NPAD_KEY_MUL = SDLK_KP_MULTIPLY;
            NPAD_KEY_SUB = SDLK_KP_MEMSUBTRACT;
            NPAD_KEY_ADD = SDLK_KP_MEMADD;
            NPAD_KEY_ENTER = SDLK_KP_ENTER;
            NPAD_KEY_0 = SDLK_KP_0;
            NPAD_KEY_1 = SDLK_KP_1;
            NPAD_KEY_2 = SDLK_KP_2;
            NPAD_KEY_3 = SDLK_KP_3;
            NPAD_KEY_4 = SDLK_KP_4;
            NPAD_KEY_5 = SDLK_KP_5;
            NPAD_KEY_6 = SDLK_KP_6;
            NPAD_KEY_7 = SDLK_KP_7;
            NPAD_KEY_8 = SDLK_KP_8;
            NPAD_KEY_9 = SDLK_KP_9;
            NPAD_KEY_DECIMAL = SDLK_KP_DECIMAL;

            MOUSE_BTN_1 = SDL_BUTTON_LEFT;
            MOUSE_BTN_2 = SDL_BUTTON_RIGHT;
            MOUSE_BTN_3 = SDL_BUTTON_MIDDLE;
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
    }

    Input::~Input()
    {

    }

    void Input::preUpdate()
	{
		m_keyEvents.clear();
		m_buttonEvents.clear();
	}

	void Input::postUpdate()
	{
		m_mouseDX = m_mouseX - m_mouseLX;
		m_mouseDY = m_mouseY - m_mouseLY;
		m_mouseDScroll = m_mouseScroll - m_mouseLScroll;
		m_mouseLX = m_mouseX;
		m_mouseLY = m_mouseY;
		m_mouseLScroll = m_mouseScroll;
	}

	void Input::addKeyEvent(i32 key, bool state)
	{
		m_keyStates[key] = state;
		m_keyEvents[key] = state;
	}

	void Input::addButtonEvent(i32 button, bool state)
	{
		m_buttonStates[button] = state;
		m_buttonEvents[button] = state;
	}

	void Input::addMousePositionEvent(f64 x, f64 y)
	{
		m_mouseX = x;
		m_mouseY = y;
	}

	void Input::addMouseScrollEvent(f64 scroll)
	{
		m_mouseScroll = scroll;
	}

	bool Input::getKeyState(i32 key) const
	{
		auto& it = m_keyStates.find(key);
		if (it == m_keyStates.end()) {
			return false;
		}
		return it->second;
	}

	bool Input::getKeyEvent(i32 key, bool state) const
	{
		auto& it = m_keyEvents.find(key);
		if (it == m_keyEvents.end()) {
			return false;
		}
		return it->second == state;
	}

	bool Input::getButtonState(i32 button) const
	{
		auto& it = m_buttonStates.find(button);
		if (it == m_buttonStates.end()) {
			return false;
		}
		return it->second;
	}

	bool Input::getButtonEvent(i32 button, bool state) const
	{
		auto& it = m_buttonEvents.find(button);
		if (it == m_buttonEvents.end()) {
			return false;
		}
		return it->second == state;
	}

	bool Input::isMouseGrabbed() const
	{
		return m_window->isMouseGrabbed();
	}

	void Input::setMouseGrabbed(bool grabbed) const
	{
		m_window->setMouseGrabbed(grabbed);
	}

}