cmake_minimum_required(VERSION 3.16)
project(PokerEquityEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Engine library: everything except main()
add_library(poker_engine
    src/card.cpp
)
target_include_directories(poker_engine PUBLIC include)
target_compile_options(poker_engine PRIVATE -Wall -Wextra -Wpedantic)

# CLI front end
add_executable(equity src/main.cpp)
target_link_libraries(equity PRIVATE poker_engine)
target_compile_options(equity PRIVATE -Wall -Wextra -Wpedantic)

# Tests
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.1
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_executable(tests tests/test_card.cpp)
target_link_libraries(tests PRIVATE poker_engine Catch2::Catch2WithMain)
target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
add_test(NAME tests COMMAND tests)

