#include <memory>
#include "EXA_Title.h"
#include "../Window/MainWindow.h"

using namespace scui;

void init() {
    // Get the unique main window:
    MainWindow& theMain = MainWindow::get_instance();
    // Create a EXA_Title window:
    auto title = std::make_shared<EXA_Title>(1, 1, scui::POINT{6,4}, scui::POINT{40,40});
    title->set_color({3});
    auto title2 = std::make_shared<EXA_Title>(2, 1, scui::POINT{15,5}, scui::POINT{40,40});
    title2->set_color({4});
    // Add the window to {theMian}:
    theMain.addWindow(title);
    theMain.addWindow(title2);
}