#ifndef I_SYMBOL_HPP
#define I_SYMBOL_HPP
#include <string>

namespace IsonNotation {
    class ISymbol {
    public:
        ISymbol(const std::string n, const int s = -1, const bool u = true, const std::string f = "0", const std::string c = "0")
            : name(n), step(s), up(u), fontCode(f), code(c) {}
        const int getStep() { return step; }
        const std::string getFontCode() { return fontCode; }
        const std::string getCode() { return code; }
        const bool isUp() { return up; }
        const std::string getName() { return name; }
    protected:
        void setFontCode(const std::string fc) {
            fontCode = fc;
        }
    private:
        bool up;
        int step;
        std::string code;
        std::string fontCode;
        std::string name;
    };
}

#endif // I_SYMBOL_HPP
