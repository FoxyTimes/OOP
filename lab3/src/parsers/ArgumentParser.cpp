#include "ArgumentParser.h"
#include "Static.h"
namespace SoundProcessor {
    std::unique_ptr<BaseArg> ArgumentParser::parse_arguments(const std::string& argument) {
        std::unique_ptr<File> arg1 = parse_file(argument);
        if (arg1 != nullptr) {
            return arg1;
        }
        std::unique_ptr<Times> arg3 = parse_time(argument);
        if (arg3 != nullptr) {
            return arg3;
        }
        std::unique_ptr<InstName> arg4 = parse_instname(argument);
        return arg4;
    }

    std::unique_ptr<Times> ArgumentParser::parse_time(const std::string& argument) {
        try {
            Times time(stoi(argument));
            return std::make_unique<Times>(time);
        }
        catch (std::exception& e) {
            return nullptr;
        }
    }

    std::unique_ptr<File> ArgumentParser::parse_file(const std::string& argument) {
        try {
            if (argument[0] == '$') {
                std::string temp = Static::copy_str(argument, 1, argument.size());
                int number_of_file = stoi(temp);
                File result(number_of_file);
                return std::make_unique<File>(result);
            }
            return nullptr;
        }
        catch (std::exception &e) {
            return nullptr;
        }
    }

    std::unique_ptr<InstName> ArgumentParser::parse_instname(const std::string& argument) {
        try {
            InstName instname(argument);
            return std::make_unique<InstName>(instname);
        }
        catch (std::exception& e) {
            return nullptr;
        }
    }
}