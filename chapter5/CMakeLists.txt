cmake_minimum_required(VERSION 3.22)            # требуемая версия cmake
project(                                        
    cars                                         # название проекта
    VERSION 1.0                                 # номер версии проекта
    DESCRIPTION "Fibonacchi Numbers"            # описание
    LANGUAGES CXX                               # язык программирования
)

set(CMAKE_CXX_STANDARD 17)                      # устанавливаем требуемый стандарт языка (это значит, что в проекте будут 
                                                # использоваться фичи этого стандарта)

set(CMAKE_CXX_STANDARD_REQUIRED ON)             # при сборке платформа будет проверять поддержку стандарта C++17 компилятором

set(CMAKE_BUILD_TYPE Debug)                     # конфигурация сборки - Debug

add_executable(cars)                            # эта команда сообщает платформе сборки, что будет компилироваться исполняемый файл


set(sources                                     # создаем cmake-переменную sources, которая содержит список файлов исходного кода
    src/car.h
    src/lorry.h
    src/car.cpp
    src/lorry.cpp
    src/main.cpp
)

target_sources(cars PRIVATE ${sources})         # команда указывает компилятору, что исполняемый файл будет компилироваться из исходников,
                                                # перечисленных в sources