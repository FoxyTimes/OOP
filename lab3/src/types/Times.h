#pragma once
#include "BaseArg.h"
namespace SoundProcessor {
    class Times : public BaseArg {
    public:
        explicit Times(int seconds);

        std::string get_name() override;

        int get_time() const;

    private:
        int seconds = 0;
    };
}

