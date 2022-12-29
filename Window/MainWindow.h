#pragma once
#include <vector>
#include <memory>
#include <unordered_set>
#include <random>
#include "Window.h"
#include "Option.h"

namespace scui {
    class MainWindow : public Window
    {
    public:
        static MainWindow& get_instance() { return _MainWindow; }

        void run() { refresh({}, {}); }

        /**
         * @brief Refresh all existing and activated windows.
        */
        void refresh(POINT restrainTL, POINT restrainBR);

        void addWindow(winPtr tWindow);

    private:
        bool check_activated(Window& tWindow);
        bool check_hasSameID(unsigned tID);
        unsigned create_uniqueID();

    private:
        std::vector<winPtr> _winPtrList;      // The list of all shared_ptrs to existing window.

    private:
        MainWindow();
        MainWindow(const MainWindow&) = delete;
        MainWindow& operator=(const MainWindow&) = delete;
        static MainWindow _MainWindow;
    };
}
