#pragma once
#include <Windows.h>
#include "../Config/PREDEFINED.h"

namespace scui {
    class Window
    {
    public:
        // Constructer:
        Window() = default;
        // Distructor:
        virtual ~Window() {}

        // Compare:
        bool operator==(const Window& tWindow) const { return this->_ID == tWindow._ID; }

        // Manage members: @{
        /**
         * @brief Set absolute position (meanwhile set the size).
        */
        void set_absPos(POINT topLeft, POINT botRight) { _absPosTL = topLeft; _absPosBR = botRight; }
        void set_priority(unsigned p) { _priority = p; }
        void set_activated(bool YesOrNo) { _activated = YesOrNo; }
        void set_ID(unsigned id) { _ID = id; }
        // @}

        // Get members: @{
        POINT    get_topLeft()     const { return _absPosTL; }
        POINT    get_bottomRight() const { return _absPosBR; }
        unsigned get_priority()    const { return _priority; }
        bool     get_activated()   const { return _activated; }
        unsigned get_ID()          const { return _ID; }
        // @}

        /**
         * @brief Refresh the window according to {_rPos} and {_priority}.
        */
        virtual void refresh(POINT restrainTL, POINT restrainBR) {};

    protected:
        // Absolute position of the top-left corner.
        POINT    _absPosTL = {0,0};
        // Absolute position of the bottom-right corner.
        POINT    _absPosBR = {0,0};
        // Stack priority. The window with smaller {_priotity} will refresh earlier and show behind.
        unsigned _priority = 0;
        // Marks whether the window is activated, waiting to refresh.
        bool     _activated = true;
        // Unique ID for each window.
        unsigned _ID = 0;
    };
}
