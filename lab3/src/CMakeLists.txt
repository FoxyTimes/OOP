# src/CMakeLists.txt
set(BINARY ${CMAKE_PROJECT_NAME}_run)

# Собираем все исходники программы
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

# Создаем библиотеку для основного кода
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})

# Устанавливаем флаги компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

# Добавляем все заголовочные файлы
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/*/*.h)
set(HEADER_DIRS "")
foreach(header_file ${HEADER_FILES})
    get_filename_component(header_dir ${header_file} DIRECTORY)
    list(APPEND HEADER_DIRS ${header_dir})
endforeach()

include_directories(${HEADER_DIRS})

# Создаем исполнимый файл для основного кода
add_executable(${BINARY} ${SOURCES})
