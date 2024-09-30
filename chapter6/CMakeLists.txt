cmake_minimum_required(VERSION 3.28)            # требуемая версия cmake
project(                                        
    matrix                                      # название проекта
    VERSION 1.0                                 # номер версии проекта
    DESCRIPTION "Matrix"                        # описание
    LANGUAGES CXX                               # язык программирования
)

set(CMAKE_CXX_STANDARD 17)                      # устанавливаем требуемый стандарт языка (это значит, что в проекте будут 
                                                # использоваться фичи этого стандарта)

set(CMAKE_CXX_STANDARD_REQUIRED ON)             # при сборке платформа будет проверять поддержку стандарта C++17 компилятором

set(CMAKE_BUILD_TYPE Debug)                     # конфигурация сборки - Debug

add_executable(matrix)                          # эта команда сообщает платформе сборки, что будет компилироваться исполняемый файл


set(sources                                     # создаем cmake-переменную sources, которая содержит список файлов исходного кода
    src/main.cpp
    src/matrix.h
    src/matrix.cpp
)

target_sources(matrix PRIVATE ${sources})       # команда указывает компилятору, что исполняемый файл будет компилироваться из исходников,
                                                # перечисленных в sources

