#ifndef I_SYMBOL_HPP
#define I_SYMBOL_HPP

namespace IsonNotation {
    class ISymbol {
    public:
        //virtual ~ISymbol() {}
        const int getStep() { return step; }

    private:
        const int step;
    };

    typedef struct Symbol {
        ISymbol symbol;
        Symbol(ISymbol s) : symbol(s) {}
    } Symbol;
}

#endif // I_SYMBOL_HPP
