#ifndef MARTYRIA_HPP
#define MARTYRIA_HPP
#include "../IModifier.hpp"
#include "../IScale.hpp"

namespace IsonNotation {
    class Martyria : public IModifier {
    public:
        Martyria(const Parallagi i, const Scale s, const Parallagi b = NI, const std::string name = "Martyria") :
            first(i), base(b), scale(s), IModifier(name) {
            // So that the changed font code is accessible from pointer to base
            this->setFontCode(this->getMartyriaFontCode());
        }
        const Parallagi getBase() { return base; }
        const Parallagi getNote() { return first; }
        const Scale getScale() { return scale; }
        void setBase(const Parallagi b) { base = b; }
        void setNote(const Parallagi n) { first = n; }
        void setScale(Scale s) { scale = s; }

        const std::string getMartyriaFontCode() {
            switch(scale) {
            case DIATONIC:
                return diatonicFontCodes[first];
                break;
            case CHROMATIC:
                if (base == NI) return chromaticNiFontCodes[first];
                else return chromaticPaFontCodes[first];
                break;
            case ENHARMONIC:
                return enharmonicFontCodes[first];
                break;
            default:
                return "";
                break;
            }
        }

    private:
        Parallagi first;
        Parallagi base;
        Scale scale;

        // Define font codes that will render Martyria in EZ Psaltica font
        const std::string diatonicFontCodes[8] = {
            "cC", "vV", "bB", "nN", "m<C", ",<V", "./B", "c/N"
        };
        // Need to be updated with different font for this one
        const std::string chromaticNiFontCodes[8] = {
            "c<?", "v", "b<?", "n", "m<?", ",", "./<?", "c"
        };
        const std::string chromaticPaFontCodes[8] = {
            "v?", "bM", "n?", "mM", ",?", ".M", "c?", "vM"
        };
        const std::string enharmonicFontCodes[10] = {
            "cN", "vC", "bV", "nN", "m<C", ",<V", "./N", "c/<N", "v/V", "b/N"
        };
    };
}

#endif // MARTYRIA_HPP
