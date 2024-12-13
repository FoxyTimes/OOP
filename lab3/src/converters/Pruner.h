#include "Converter.h"


namespace SoundProcessor {
    class Pruner : public Converter {
    private:
        std::queue<std::unique_ptr<BaseArg>> queue_of_args;
    public:
        explicit Pruner(std::queue<std::unique_ptr<BaseArg>> queue_of_args);
        void convert() override;
        std::queue<std::unique_ptr<BaseArg>> get_args() override;
    };
}