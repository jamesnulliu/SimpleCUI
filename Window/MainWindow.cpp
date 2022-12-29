#include "MainWindow.h"

namespace scui {
    MainWindow MainWindow::_MainWindow;

    MainWindow::MainWindow() : Window()
    {
        set_priority(0);
        set_activated(true);
        set_ID(0);
        set_absPos({0,0}, {40, 40});
    }

    /**
     * @brief Refresh all existing and activated windows.
    */
    void MainWindow::refresh(POINT restrainTL, POINT restrainBR)
    {
        for (auto& windowPtr : _winPtrList) {
            if (check_activated(*windowPtr)) {
                windowPtr->refresh(_absPosTL, _absPosBR);
            }
        }
    }

    void MainWindow::addWindow(winPtr tWindow)
    {
        tWindow->set_ID(create_uniqueID());
        long long i = _winPtrList.size() - 1;
        while (i >= 0 && (_winPtrList[i])->get_priority() > tWindow->get_priority()) {
            --i;
        }
        // if (i < 0) ++i;
        _winPtrList.insert(_winPtrList.begin() + (i + 1), tWindow);
    }

    bool MainWindow::check_activated(Window& tWindow)
    {
        return tWindow.get_activated();
    }

    bool MainWindow::check_hasSameID(unsigned tID)
    {
        for (auto ptr : _winPtrList) {
            if (ptr->get_ID() == tID) {
                return true;
            }
        }
        return false;
    }

    unsigned MainWindow::create_uniqueID() {
        srand(time(0));
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<unsigned> distr(0, UINT_MAX);
        bool flag = true;
        unsigned seed = 0;
        while (flag) {
            seed = distr(eng);
            if (!check_hasSameID(seed)) {
                flag = false;
            }
        }
        return seed;
    }
}