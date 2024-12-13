# CMakeLists.txt в корне проекта
cmake_minimum_required(VERSION 3.22)
project(lab3)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Флаги для покрытия тестами
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Добавляем необходимые директории с исходными файлами
include_directories(src)
include_directories(src/converters)
include_directories(src/types)
include_directories(src/parsers)

# Добавляем подкаталоги для исходного кода, тестов и GoogleTest
add_subdirectory(src)           # Основной код
add_subdirectory(test)          # Тесты
add_subdirectory(lib/googletest) # GoogleTest
