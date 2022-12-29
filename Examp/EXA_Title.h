#pragma once
#include <string>
#include "../Window/Window.h"
#include "../Tools/ConsoleSetting.h"
#include "../Tools/ColorIO.h"
#include "../Interface/WinPrint.h"

namespace scui {
    class EXA_Title :
        public Window,
        public WinPrint
    {
    public:
        EXA_Title(unsigned priority, bool activate, POINT TL, POINT BR) {
            set_priority(priority);
            set_activated(activate);
            set_absPos(TL, BR);
        }
        void set_color(COLOR color) {
            _color = color;
        }
        void refresh(POINT cTL, POINT cBR) {
            WinPrint::winPrint(_text, _color, TLest(cTL, _absPosTL), BRest(cBR, _absPosBR));
        }
    private:
        std::string _text = "\n\n        ouo        ouoo        \n      uuuuuuzuu uuuuuuuuu\n     uuuauauuuuuuuuuuuuuuu\n    +uuu1uuuuuuuuuuuuuuuuu\n     uuuuuuuuuuuuuuuuuuuuu\n      uuuuuuuuuuuuuuuuuuu\n        uuuuuuuuuuuuuuu\n          uuuuuuuuuuu\n            -uuuuu\n               uuu";
        COLOR _color;
    };
}
