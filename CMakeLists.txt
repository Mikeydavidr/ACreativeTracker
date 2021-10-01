# CMakeList.txt : CMake project for ACreativeTracker, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_C_STANDARD 11)

project ("ACreativeTracker")

# Add source to this project's executable.
add_executable (ACreativeTracker "ACreativeTracker.cpp" "ACreativeTracker.h" "Seed.h" "Seed.cpp" "Hint.cpp" "Hint.h" "Translators.h" "Translators.cpp" "Unit_Tester.h" "Unit_Tester.cpp" "Defines.h")

# TODO: Add tests and install targets if needed.