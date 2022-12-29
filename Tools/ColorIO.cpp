#include "ColorIO.h"

namespace scui {
    ostream ostream::_cout;
    istream istream::_cin;

    template<class T> ostream& ostream::operator<<(const T& _obj)
    {
        std::cout << _obj;
        return *this;
    }
    template<> ostream& ostream::operator<< <char> (const char& _obj)
    {
        putchar(_obj);
        return *this;
    }
    template<> ostream& ostream::operator<< <std::string> (const std::string& _obj)
    {
        puts(_obj.c_str());
        return *this;
    }
    ostream& cout(int fColor, int bColor, bool fIntensity, bool bIntensity)
    {
        setConColor(fColor, bColor, fIntensity, bIntensity);
        return ostream::_cout;
    }
    ostream& cout(COLOR color) {
        setConColor(color.fColor, color.bColor, color.fIntensity, color.bIntensity);
        return ostream::_cout;
    }
    template<class T> istream& istream::operator>>(T& _obj)
    {
        std::cin >> _obj;
        return *this;
    }
    istream& cin(int fColor, int bColor, bool fIntensity, bool bIntensity)
    {
        setConColor(fColor, bColor, fIntensity, bIntensity);
        return istream::_cin;
    }
    istream& cin(COLOR color) {
        setConColor(color.fColor, color.bColor, color.fIntensity, color.bIntensity);
        return istream::_cin;
    }
}