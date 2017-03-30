#ifndef I_SCALE_HPP
#define I_SCALE_HPP

namespace IsonNotation {
    enum Parallagi {
        NI = 0,
        PA,
        VOU,
        GA,
        THI,
        KE,
        ZO,
        NI_OCTAVE,
        PA_OCTAVE_UP,
        VOU_OCTAVE_UP
    };

    enum Scale {
        DIATONIC = 0,
        CHROMATIC,
        ENHARMONIC
    };

    static float scaleSteps[8] = {
        0.0f, 2.0f, 4.0f, 5.0f, 7.0f, 9.0f, 11.0f, 12.0f
    };

    class IScale {

    };
}

#endif // I_SCALE_HPP
