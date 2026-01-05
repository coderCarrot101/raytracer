cmake_minimum_required(VERSION 3.15)

project(inOneWeekend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where SDL3 is installed
set(SDL3_DIR "C:/Libraries/SDL3/SDL3-3.4.0/cmake")

find_package(SDL3 CONFIG REQUIRED)

add_executable(inOneWeekend
    main.cpp
)

target_link_libraries(inOneWeekend
    SDL3::SDL3
)
