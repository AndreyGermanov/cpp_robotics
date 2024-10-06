cmake_minimum_required(VERSION 3.28)
project(                                        
    vector3d                                    # название проекта
    VERSION 1.0                                 # номер версии проекта
    DESCRIPTION "Snake"                         # описание
    LANGUAGES CXX                               # язык программирования
)

# Сборка в режиме отладки
set (CMAKE_BUILD_TYPE Debug)

# Используемый стандарт C++
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Файлы исходного кода
set (source src/main.cpp src/vector3d.h)

# Определение исполняемого файла
add_executable(vector3d ${source})