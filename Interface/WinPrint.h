#pragma once
#include <string>
#include "../Tools/ColorIO.h"
#include "../Tools/ConsoleSetting.h"

namespace scui {
    class WinPrint
    {
    public:
        void winPrint(const std::string& content, COLOR color,
            POINT constrainTL, POINT constrainBR, char NewLine = '\n')
        {
            short x_length = constrainBR.X - constrainTL.X + 1;
            short y_length = constrainBR.Y - constrainTL.Y + 1;
            short y_printAlready = 0;
            std::string tempSplit = "";
            for (int i = 0; i < content.size(); ++i) {
                if (tempSplit.size() <= x_length) {
                    tempSplit += content[i];
                }
                if (content[i] == '\n' || i == content.size() - 1) {
                    tempSplit.pop_back();
                    gotoXY({constrainTL.X, static_cast<short>(constrainTL.Y + y_printAlready)});
                    cout(color) << tempSplit;
                    tempSplit = "";
                    ++y_printAlready;
                }
                if (y_printAlready == y_length) {
                    break;
                }
            }
        }
    };
}
