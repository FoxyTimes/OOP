#include "Factory.h"
#include "types/InstName.h"
#include "Muter.h"
#include "Mixer.h"
#include "Pruner.h"
#include "memory"

namespace SoundProcessor {

    std::unique_ptr<Converter> Factory::create_converter(std::queue<std::unique_ptr<BaseArg>> arguments) {
        if (!(arguments.front()->get_name()=="InstName")) {
            throw std::runtime_error("Not instruction");
        }
        auto* raw_pointer = dynamic_cast<InstName*>(arguments.front().release());
        std::unique_ptr<InstName> name(raw_pointer);
        arguments.pop();
        if (name->get_name_inst()=="mute") {
            return std::make_unique<Muter>(std::move(arguments));
        }
        if (name->get_name_inst()=="mix") {
            return std::make_unique<Mixer>(std::move(arguments));
        }
        if (name->get_name_inst()=="prune") {
            return std::make_unique<Pruner>(std::move(arguments));
        }
        throw std::runtime_error("Incorrect instruction " + name->get_name_inst());
    }
}