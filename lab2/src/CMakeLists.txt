set(BINARY ${CMAKE_PROJECT_NAME})


file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES}
        Game.cpp
        Game.h
        Field.cpp
        Field.h
        Config.cpp
        Config.h
        Cell.cpp
        Cell.h
        Printer.cpp
        Printer.h
        Static.cpp
        Static.h
)