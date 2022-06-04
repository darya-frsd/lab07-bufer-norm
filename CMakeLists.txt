# CMakeList.txt: проект CMake для lab07-bufer-norm; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("lab07-bufer-norm")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab07-bufer-norm "lab07-bufer-norm.cpp" "lab07-bufer-norm.h" "lab07-bufer-main.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
