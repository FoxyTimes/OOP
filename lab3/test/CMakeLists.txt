# CMakeLists.txt в директории test
cmake_minimum_required(VERSION 3.22)
project(lab3_tests)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Флаги для покрытия тестами
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Собираем все исходники тестов
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

# Создаем исполнимый файл для тестов
set(TEST_BINARY ${CMAKE_PROJECT_NAME}_tst)

add_executable(${TEST_BINARY} ${TEST_SOURCES} ParsersTest.cpp
        SoundProcTest.cpp)

# Линкуем с основной библиотекой и GoogleTest
target_link_libraries(${TEST_BINARY} PUBLIC
        ${CMAKE_PROJECT_NAME}_lib  # Ваша библиотека, собранная в src
        gtest
        gtest_main
)

# Указываем пути к заголовочным файлам для GoogleTest
target_include_directories(${TEST_BINARY} PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include
        ${CMAKE_SOURCE_DIR}/src
)

# Настроим тесты с помощью CTest
add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY})

# Дополнительно: Если используется покрытие тестами, указываем флаги компиляции для целей тестирования
target_compile_options(${TEST_BINARY} PRIVATE
        -fprofile-arcs
        -ftest-coverage
)
