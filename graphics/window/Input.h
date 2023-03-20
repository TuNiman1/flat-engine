#pragma once

#include <unordered_map>

#include "../../Build.h"
#include "../../Types.h"

namespace fl
{
    class Window;

    enum InputCodes
    {
        INPUT_GLFW,
        INPUT_SDL
    };

    class FL_API Input
    {
    public:
        Input(Window *window, const InputCodes &codes);
        ~Input();

        void preUpdate();
        void postUpdate();

        void addKeyEvent(i32 key, bool state);
        void addButtonEvent(i32 button, bool state);
        void addMousePositionEvent(f64 x, f64 y);
        void addMouseScrollEvent(f64 scroll);

        bool getKeyState(i32 key) const;
        bool getKeyEvent(i32 key, bool state = true) const;
        bool getButtonState(i32 button) const;
        bool getButtonEvent(i32 button, bool state = true) const;

        bool isMouseGrabbed() const;
        void setMouseGrabbed(bool grabbed) const;

        inline f64 getMouseX() const { return m_mouseX; }
        inline f64 getMouseY() const { return m_mouseY; }
        inline f64 getMouseScroll() const { return m_mouseScroll; }

        inline f64 getMouseDX() const { return m_mouseDX; }
        inline f64 getMouseDY() const { return m_mouseDY; }
        inline f64 getMouseDScroll() const { return m_mouseDScroll; }

    private:
        Window *m_window;

        std::unordered_map<i32, bool> m_keyStates;
        std::unordered_map<i32, bool> m_keyEvents;

        std::unordered_map<i32, bool> m_buttonStates;
        std::unordered_map<i32, bool> m_buttonEvents;

        f64 m_mouseX;
        f64 m_mouseY;
        f64 m_mouseScroll;
        f64 m_mouseLX;
        f64 m_mouseLY;
        f64 m_mouseLScroll;
        f64 m_mouseDX;
        f64 m_mouseDY;
        f64 m_mouseDScroll;

    public:
        //! General Keys

        // UNKOWN KEY
        i32 KEY_UNK;
        // ESCAPE KEY
        i32 KEY_ESCAPE;
        // F1 KEY
        i32 KEY_F1;
        // F2 KEY
        i32 KEY_F2;
        // F3 KEY
        i32 KEY_F3;
        // F4 KEY
        i32 KEY_F4;
        // F5 KEY
        i32 KEY_F5;
        // F6 KEY
        i32 KEY_F6;
        // F7 KEY
        i32 KEY_F7;
        // F8 KEY
        i32 KEY_F8;
        // F9 KEY
        i32 KEY_F9;
        // F10 KEY
        i32 KEY_F10;
        // F11 KEY
        i32 KEY_F11;
        // F12 KEY
        i32 KEY_F12;

        // GRAVE ACCENT KEY (BELOW ESCAPE)
        i32 KEY_GA;
        // NUMBER 1 KEY
        i32 KEY_NUM_1;
        // NUMBER 2 KEY
        i32 KEY_NUM_2;
        // NUMBER 3 KEY
        i32 KEY_NUM_3;
        // NUMBER 4 KEY
        i32 KEY_NUM_4;
        // NUMBER 5 KEY
        i32 KEY_NUM_5;
        // NUMBER 6 KEY
        i32 KEY_NUM_6;
        // NUM 7 KEY
        i32 KEY_NUM_7;
        // NUM 8 KEY
        i32 KEY_NUM_8;
        // NUM 9 KEY
        i32 KEY_NUM_9;
        // NUM 0 KEY
        i32 KEY_NUM_0;
        // MINUS KEY (IN RIGHT OF ZERO)
        i32 KEY_MIN;
        // EQUAL KEY
        i32 KEY_EQL;
        // BACKSPACE KEY
        i32 KEY_BSPACE;

        // TAB KEY
        i32 KEY_TAB;
        // Q LETTER KEY
        i32 KEY_Q;
        // W LETTER KEY
        i32 KEY_W;
        // E LETTER KEY
        i32 KEY_E;
        // R LETTER KEY
        i32 KEY_R;
        // T LETTER KEY
        i32 KEY_T;
        // Y LETTER KEY
        i32 KEY_Y;
        // U LETTER KEY
        i32 KEY_U;
        // I LETTER KEY
        i32 KEY_I;
        // O LETTER KEY
        i32 KEY_O;
        // P LETTER KEY
        i32 KEY_P;
        // LEFT BRACKET KEY
        i32 KEY_LBR;
        // RIGHT BRACKET KEY
        i32 KEY_RBR;
        // BACKSLASH KEY
        i32 KEY_BSLASH;

        // CAPSLOCK KEY
        i32 KEY_CPSLK;
        // A LETTER KEY
        i32 KEY_A;
        // S LETTER KEY
        i32 KEY_S;
        // D LETTER KEY
        i32 KEY_D;
        // F LETTER KEY
        i32 KEY_F;
        // G LETTER KEY
        i32 KEY_G;
        // H LETTER KEY
        i32 KEY_H;
        // J LETTER KEY
        i32 KEY_J;
        // K LETTER KEY
        i32 KEY_K;
        // L LETTER KEY
        i32 KEY_L;
        // SIMICOLON KEY
        i32 KEY_SCOLON;
        // APOSTROPHE KEY
        i32 KEY_APO;
        // ENTER KEY
        i32 KEY_ENTER;

        // LEFT SHIFT KEY
        i32 KEY_LSHIFT;
        // Z LETTER KEY
        i32 KEY_Z;
        // X LETTER KEY
        i32 KEY_X;
        // C LETTER KEY
        i32 KEY_C;
        // V LETTER KEY
        i32 KEY_V;
        // B LETTER KEY
        i32 KEY_B;
        // N LETTER KEY
        i32 KEY_N;
        // M LETTER KEY
        i32 KEY_M;
        // COMMA KEY
        i32 KEY_COMMA;
        // PERIOD KEY
        i32 KEY_PERIOD;
        // SLASH KEY
        i32 KEY_SLASH;
        // RIGHT SHIFT KEY
        i32 KEY_RSHIFT;

        // LEFT CTRL
        i32 KEY_LCTRL;
        // LEFT SUPER KEY (AKA WINDOWS KEY)
        i32 KEY_LSUPER;
        // LEFT ALT KEY
        i32 KEY_LALT;
        // SPACE BAR KEY
        i32 KEY_SPACE;
        // RIGHT ALT KEY
        i32 KEY_RALT;
        // RIGHT SUPER KEY (AKA WINDOWS KEY)
        i32 KEY_RSUPER;
        // MENU KEY (LOCATED RIGHT)
        i32 KEY_MENU;
        // RIGHT CTRL KEY
        i32 KEY_RCTRL;

        //! Additional Keys

        // PRINT SCREEN KEY
        i32 KEY_PRTSCR;
        // SCROLL LOCK KEY
        i32 KEY_SCRLLCK;
        // PAUSE KEY
        i32 KEY_PAUSE;

        // INSERT KEY
        i32 KEY_INSERT;
        // HOME KEY
        i32 KEY_HOME;
        // PAGE UP KEY
        i32 KEY_PGUP;
        // DELETE KEY (NOT BACKSLASH)
        i32 KEY_DEL;
        // END KEY
        i32 KEY_END;
        // PAGE DOWN KEY
        i32 KEY_PGDN;

        // UP ARROW
        i32 KEY_UP;
        // DOWN ARROW
        i32 KEY_DOWN;
        // LEFT ARROW
        i32 KEY_LEFT;
        // RIGHT ARROW
        i32 KEY_RIGHT;

        //! Numpad keys

        // NUMPAD LOCK KEY
        i32 NPAD_KEY_NLOCK;
        // NUMPAD DIVIDE KEY
        i32 NPAD_KEY_DIVIDE;
        // NUMPAD MULTIPLY KEY
        i32 NPAD_KEY_MUL;
        // NUMPAD SUBSTRACT KEY
        i32 NPAD_KEY_SUB;
        // NUMPAD ADD KEY
        i32 NPAD_KEY_ADD;
        // NUMPAD ENTER KEY
        i32 NPAD_KEY_ENTER;
        // NUMPAD PERIOD KEY
        i32 NPAD_KEY_DECIMAL;

        // NUMPAD NUMBER 1 KEY
        i32 NPAD_KEY_1;
        // NUMPAD NUMBER 2 KEY
        i32 NPAD_KEY_2;
        // NUMPAD NUMBER 3 KEY
        i32 NPAD_KEY_3;
        // NUMPAD NUMBER 4 KEY
        i32 NPAD_KEY_4;
        // NUMPAD NUMBER 5 KEY
        i32 NPAD_KEY_5;
        // NUMPAD NUMBER 6 KEY
        i32 NPAD_KEY_6;
        // NUMPAD NUMBER 7 KEY
        i32 NPAD_KEY_7;
        // NUMPAD NUMBER 8 KEY
        i32 NPAD_KEY_8;
        // NUMPAD NUMBER 9 KEY
        i32 NPAD_KEY_9;
        // NUMPAD NUMBER 0 KEY
        i32 NPAD_KEY_0;

        //! Mouse buttons

        // MOUSE BTN 1
        i32 MOUSE_BTN_1;
        // MOUSE BTN 2
        i32 MOUSE_BTN_2;
        // MOSUE BTN 3
        i32 MOUSE_BTN_3;
        // MOUSE BTN 4
        i32 MOUSE_BTN_4;
        // MOUSE BTN 5
        i32 MOUSE_BTN_5;
        // MOSUE BTN 6
        i32 MOUSE_BTN_6;
        // MOUSE BTN 7
        i32 MOUSE_BTN_7;
        // MOUSE BTN 8
        i32 MOUSE_BTN_8;
        // LAST MOUSE BTN
        i32 MOUSE_BTN_LAST;
        // LEFT CLICK BUTTON
        i32 MOUSE_BTN_LEFT;
        // RIGHT CLICK BUTTON
        i32 MOUSE_BTN_RIGHT;
        // MIDDLE CLICK BUTTON
        i32 MOUSE_BTN_MIDDLE;
    };
}