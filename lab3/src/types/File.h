#pragma once

#include "BaseArg.h"
#include "string"

namespace SoundProcessor {
    class File : public BaseArg {
    private:
        int number_of_file;
    public:
        [[nodiscard]] int get_number_of_file() const;

        std::string get_name() override;

        explicit File(int number_of_file);
    };
}
