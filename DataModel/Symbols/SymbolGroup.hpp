#ifndef SYMBOL_GROUP_HPP
#define SYMBOL_GROUP_HPP
#include "../ISymbol.hpp"
#include <vector>

namespace IsonNotation {
    typedef struct Group {
        int step;
        bool up;
        std::string fontCode;
        Group(const int s = -1, const bool u = true, const std::string fc = "0")
            : step(s), up(u), fontCode(fc) {}
    } Group;

    enum SymbolGroups {
        //UP
        OligonKentema,
        OligonPetaste,
        KentemaOligon,
        KentemaPetaste,
        OligonYpsele,
        PetasteYpsele,
        YpseleOligon,
        YpselePetaste,
        KentemaOligonYpsele,
        KentemaPetasteYpsele,
        YpseleKentemaOligon,
        YpseleKentemaPetaste,
        //DOWN
        ApostrophosPetaste,
        ElaphronPetaste,
        ElaphronApostrophos,
        ElpahronApsotrophosPetaste,
        //KamelePetaste,
        KameleApostrophos,
        //KameleApostrophosPetaste,
        KameleElaphron,
        //KameleElaphronPetaste,
        KameleElaphronApostrophos,
        //KameleElaphronApostrophosPetaste
    };

    class SymbolGroup : public ISymbol {
    public:
        SymbolGroup(SymbolGroups s, const std::string name = "Group") :
            ISymbol(name) {
            this->group = s;
            Group g = getGroup();
            setFontCode(g.fontCode);
            setUp(g.up);
            setStep(g.step);
        }
        const std::vector<std::shared_ptr<ISymbol>> getSymbols();

        const Group getGroup() {
            const Group groups[19] = {
                //UP
                Group(2, true, "2"),
                Group(2, true, "w"),
                Group(3, true, "3"),
                Group(3, true, "e"),
                Group(4, true, "4"),
                Group(4, true, "r"),
                Group(5, true, "5"),
                Group(5, true, "t"),
                Group(6, true, "6"),
                Group(6, true, "y"),
                Group(7, true, "7"),
                Group(7, true, "u"),
                //DOWN
                Group(1, false, "Q"),
                Group(2, false, "W"),
                Group(3, false, "#"),
                Group(3, false, "E"),
                Group(5, false, "%"),
                Group(6, false, "^"),
                Group(7, false, "&")
            };
            return groups[group];
        }

    private:
        SymbolGroups group;
        //std::vector<std::shared_ptr<ISymbol>> group;
    };
}

#endif // SYMBOL_GROUP_HPP
