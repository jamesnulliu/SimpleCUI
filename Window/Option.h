#pragma once
#include <string>
#include <memory>
#include "../Procedure/Procedure.h"
#include "../Config/PREDEFINED.h"

namespace scui {
    /**
     * @brief A single option includes {key} for choosing, {hint} for brief describing, and {proc} which
     *        is a pointer points to a certain procedure.
    */
    struct Option
    {
        std::string                 key = "";
        std::string                 hint = "";
        std::shared_ptr<Procedure>  proc = nullptr;
    };
}
