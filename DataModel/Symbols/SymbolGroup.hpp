#ifndef SYMBOL_GROUP_HPP
#define SYMBOL_GROUP_HPP
#include <vector>

namespace IsonNotation {
    class SymbolGroup : public ISymbol {
    public:
        SymbolGroup(const std::string name, const int step, const bool up, const std::string f, const std::string c) :
            ISymbol(n, step, up, f, c) {

        }
        const std::vector<std::shared_ptr<ISymbol>> getGroup();
    private:
        std::vector<std::shared_ptr<ISymbol>> group;
    };
}

#endif // SYMBOL_GROUP_HPP
