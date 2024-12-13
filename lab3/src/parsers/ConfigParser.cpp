#include <fstream>
#include "ConfigParser.h"
#include "string"
#include "Static.h"
#include "ArgumentParser.h"

namespace SoundProcessor {
    Instruction ConfigParser::parse_string_to_inst(std::ifstream &config) {
        //разделение на слова
        std::string our_string;
        std::getline(config, our_string);
        std::vector<std::string> splited_string = Static::split_str(our_string, " ");

        //проверка на комментарий
        if (splited_string[0][0]=='#') {
            Instruction result(true, splited_string);
            return result;
        }
        else {
            Instruction result(false, splited_string);
            return result;
        }
    }

    std::queue<std::unique_ptr<BaseArg>> ConfigParser::parse_instruction(Instruction inst) {
        std::queue<std::unique_ptr<BaseArg>> queue_args;
        if (inst.get_is_comment()) {
            return queue_args;
        }

        for (int i = 0; i < inst.get_instruction().size()&&!inst.get_instruction()[i].empty(); ++i) {
            std::unique_ptr<BaseArg> our_arg = ArgumentParser::parse_arguments(inst.get_instruction()[i]);
            if (our_arg) {  // Проверка на nullptr
                queue_args.push(std::move(our_arg));  // Используем std::move для передачи владения
            }
        }
        return queue_args;  // Возвращаем очередь
    }

    std::queue<std::unique_ptr<BaseArg>> ConfigParser::parse_config_string(std::ifstream &config) {
        Instruction inst = parse_string_to_inst(config);
        return parse_instruction(inst);
    }


}