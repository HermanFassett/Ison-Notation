#ifndef I_MODIFIER_HPP
#define I_MODIFIER_HPP

namespace IsonNotation {

    typedef struct Modifier {
        IModifier mod;
        Modifier(IModifier m) : mod(m) {}
    } Modifier;

    class IModifier {

    };
}

#endif // I_MODIFIER_HPP
