#pragma once
namespace scui {
    class Procedure
    {
    public:
        virtual bool run() = 0;
        virtual ~Procedure() {}
    };
}
