#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "fileswork/FileManager.h"
#include "File.h"

namespace SoundProcessor {

    class Head {
    private:
        int file_size;          // Размер файла (в байтах)
        short audio_format;     // Формат аудио (1 - PCM, другие значения - нестандартные форматы)
        short num_channels;     // Количество каналов (1 - моно, 2 - стерео и т.д.)
        int sample_rate;        // Частота дискретизации (в Гц)
        int byte_rate;          // byte_rate = sample_rate * num_channels * bits_per_sample / 8
        short block_align;      // block_align = num_channels * bits_per_sample / 8
        short bits_per_sample;  // Количество бит на сэмпл (например, 16 для 16-битных данных)
        int data_size;          // Размер данных (в байтах)

        // Чтение базового заголовка RIFF и WAVE
        void read_riff_header(std::fstream& file);

        // Чтение формата аудио (chunk fmt)
        void read_fmt_chunk(std::fstream& file);

        // Чтение data chunk
        void read_data_chunk(std::fstream& file);

    public:
        // Конструктор
        explicit Head(const File& file_n);

        // Доступ к данным
        short get_audio_format() const;
        short get_num_channels() const;
        int get_sample_rate() const;
        int get_byte_rate() const;
        short get_block_align() const;
        short get_bits_per_sample() const;
        int get_data_size() const;

        // Вывод информации о заголовке
        void print_info() const;

        // Функция для вычисления размера заголовка
        int get_header_size() const;

        // Деструктор
        ~Head()=default;
    };
}
