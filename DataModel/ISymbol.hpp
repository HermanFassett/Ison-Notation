#ifndef I_SYMBOL_HPP
#define I_SYMBOL_HPP
#include <string>

namespace IsonNotation {
    class ISymbol {
    public:
        ISymbol(const std::string n, const int s = -1, const bool u = true,
                const std::string f = "0", const std::string c = "0", float d = 1.0f)
            : name(n), step(s), up(u), fontCode(f), code(c), duration(d) {}
        const int getStep() { return step; }
        const std::string getFontCode() { return fontCode; }
        const std::string getCode() { return code; }
        const bool isUp() { return up; }
        const std::string getName() { return name; }
        float getDuration() { return duration; }
        void setDuration(float d) {
            duration = d;
        }
    protected:
        void setFontCode(const std::string fc) {
            fontCode = fc;
        }
        void setCode(const std::string c) {
            code = c;
        }
        void setStep(const int s) {
            step = s;
        }
        void setUp(bool u) {
            up = u;
        }

    private:
        bool up;
        int step;
        float duration;
        std::string code;
        std::string fontCode;
        std::string name;
    };
}

#endif // I_SYMBOL_HPP
