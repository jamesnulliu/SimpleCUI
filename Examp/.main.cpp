#include <iostream>
#include <limits>
#include "../Window/MainWindow.h"
#include "EXA_Title.h"

void init();

int main() {
    init();
    scui::MainWindow& mainWin = scui::MainWindow::get_instance();
    mainWin.run();
    std::cin.get();
}