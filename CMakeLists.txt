cmake_minimum_required(VERSION 3.14)  # Updated for FetchContent
project(console_rpg)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror)

if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# GoogleTest requires threading support
find_package(Threads REQUIRED)
find_package(spdlog REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)
find_package(nlohmann_json CONFIG REQUIRED)


# Include directories

add_subdirectory(third_party/ChatGPT)

# Add the source files to the project
set(SOURCES
  src/Game.cpp
  src/Character.cpp
  src/Boss.cpp
  src/Enemy.cpp
  src/Event.cpp
  src/Inventory.cpp
  src/Item.cpp
  src/Armor.cpp
  src/Weapon.cpp
  src/Puzzle.cpp
  src/gui_functions.cpp
)

set(TEST_SOURCES
  tests/ArmorTest.cpp
  tests/InventoryTest.cpp
)

# Create the executable
add_executable(console_rpg 
  src/main.cpp
  ${SOURCES})

target_include_directories(console_rpg PRIVATE include third_party)
target_link_libraries(console_rpg PRIVATE nlohmann_json::nlohmann_json ChatGPTDll spdlog::spdlog Boost::filesystem Threads::Threads)

# Fetch GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(runTests ${TEST_SOURCES} ${SOURCES})
target_include_directories(runTests PRIVATE include third_party)

target_link_libraries(runTests PRIVATE nlohmann_json::nlohmann_json gtest gtest_main Threads::Threads ChatGPTDll spdlog::spdlog Boost::filesystem)

# Enables testing via the 'make test' command
enable_testing()
add_test(NAME runTests COMMAND runTests)