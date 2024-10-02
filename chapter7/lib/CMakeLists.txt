cmake_minimum_required(VERSION 3.28)            # требуемая версия cmake
project(                                        
    matrixlib                                       # название проекта
    VERSION 1.0                                 # номер версии проекта
    DESCRIPTION "Matrix lib"                    # описание
    LANGUAGES CXX                               # язык программирования
)

set(CMAKE_CXX_STANDARD 17)                      # устанавливаем требуемый стандарт языка (это значит, что в проекте будут 
                                                # использоваться фичи этого стандарта)

set(CMAKE_CXX_STANDARD_REQUIRED ON)             # при сборке платформа будет проверять поддержку стандарта C++17 компилятором

set(CMAKE_BUILD_TYPE Debug)                     # конфигурация сборки - Debug

# создаем cmake-переменную sources, которая содержит список файлов исходного кода
set(sources                                     
    src/matrix.h
    src/matrix.cpp
    src/c/c_api.h
    src/c/c_api.cpp
)

# подключение модуля для генерации заголовочного файла экспорта
include(GenerateExportHeader)                                   

# исходный код будет компилироваться и собираться в динамическую библиотеку
add_library(shared_matrix_lib SHARED ${sources})                

# какие директории включать в сборку
target_include_directories(shared_matrix_lib                    
    PUBLIC
    "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

# Параметры заголовочного файла экспорта
generate_export_header(                                         
    shared_matrix_lib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)