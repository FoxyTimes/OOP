#include "Head.h"

namespace SoundProcessor {

    // Конструктор
    Head::Head(const File& file_n) {
        FileManager& file_manager = FileManager::getInstance();
        const std::vector<std::fstream>& inputs = file_manager.get_inputs();
        auto& file = const_cast<std::fstream &>(inputs[file_n.get_number_of_file()-1]);
        if (!file.is_open()) {
            throw std::runtime_error("Error with input file");
        }

        file.clear();
        file.seekg(0);

        read_riff_header(file);
        read_fmt_chunk(file);
        read_data_chunk(file);

        file.clear();
        file.seekg(0);
    }

    // Чтение базового заголовка RIFF и WAVE
    void Head::read_riff_header(std::fstream& file) {
        char riff[4];
        file.read(riff, 4);
        if (std::string(riff, 4) != "RIFF") {
            throw std::runtime_error("Wrong RIFF");
        }

        file.read(reinterpret_cast<char*>(&file_size), 4);
        file_size += 8; // Добавляем 8 байт для "RIFF" и размера файла

        char wave[4];
        file.read(wave, 4);
        if (std::string(wave, 4) != "WAVE") {
            throw std::runtime_error("Wrong WAVE");
        }
    }

    // Чтение формата аудио (chunk fmt)
    void Head::read_fmt_chunk(std::fstream& file) {
        char fmt[4];
        file.read(fmt, 4);
        if (std::string(fmt, 4) != "fmt ") {
            throw std::runtime_error("Wrong fmt chunk");
        }

        int fmt_chunk_size;
        file.read(reinterpret_cast<char*>(&fmt_chunk_size), 4);
        if (fmt_chunk_size != 16) {  // Если размер fmt не равен 16, это не PCM
            throw std::runtime_error("Wrong PCM format");
        }

        file.read(reinterpret_cast<char*>(&audio_format), 2);  // Формат аудио (1 = PCM)
        file.read(reinterpret_cast<char*>(&num_channels), 2);  // Количество каналов
        file.read(reinterpret_cast<char*>(&sample_rate), 4);  // Частота дискретизации
        file.read(reinterpret_cast<char*>(&byte_rate), 4);    // byte_rate = sample_rate * num_channels * bits_per_sample / 8
        file.read(reinterpret_cast<char*>(&block_align), 2);   // block_align = num_channels * bits_per_sample / 8
        file.read(reinterpret_cast<char*>(&bits_per_sample), 2); // Биты на сэмпл (например, 16 для 16 бит)
    }

    // Чтение data chunk
    void Head::read_data_chunk(std::fstream& file) {
        char data[4];
        file.read(data, 4);
        if (std::string(data, 4) != "data" && std::string(data, 4) != "LIST") {
            throw std::runtime_error("Wrong data chunk.");
        }

        file.read(reinterpret_cast<char*>(&data_size), 4);
    }


    short Head::get_audio_format() const {
        return audio_format;
    }

    short Head::get_num_channels() const {
        return num_channels;
    }

    int Head::get_sample_rate() const {
        return sample_rate;
    }

    int Head::get_byte_rate() const {
        return byte_rate;
    }

    short Head::get_block_align() const {
        return block_align;
    }

    short Head::get_bits_per_sample() const {
        return bits_per_sample;
    }

    int Head::get_data_size() const {
        return data_size;
    }

    // Функция для вычисления размера заголовка
    int Head::get_header_size() const {
        // Стандартный размер заголовка для PCM файла
        return 12 + 24 + 8;  // 12 байт для "RIFF" + "WAVE", 24 байта для fmt chunk, 8 байт для data chunk
    }

    // Вывод информации о заголовке
    void Head::print_info() const {
        std::cout << "File Size: " << file_size << " bytes" << std::endl;
        std::cout << "Audio Format: " << (audio_format == 1 ? "PCM" : "Non-PCM") << std::endl;
        std::cout << "Channels: " << num_channels << std::endl;
        std::cout << "Sample Rate: " << sample_rate << " Hz" << std::endl;
        std::cout << "Byte Rate: " << byte_rate << " bytes per second" << std::endl;
        std::cout << "Block Align: " << block_align << " bytes" << std::endl;
        std::cout << "Bits per Sample: " << bits_per_sample << std::endl;
        std::cout << "Data Size: " << data_size << " bytes" << std::endl;
    }
}
