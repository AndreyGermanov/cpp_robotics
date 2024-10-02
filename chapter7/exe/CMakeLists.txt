cmake_minimum_required(VERSION 3.28)            # требуемая версия cmake
project(                                        
matrixdemo                                      # название проекта
    VERSION 1.0                                 # номер версии проекта
    DESCRIPTION "Matrix demo"                   # описание
    LANGUAGES CXX                               # язык программирования
)

set(CMAKE_CXX_STANDARD 17)                      # устанавливаем требуемый стандарт языка (это значит, что в проекте будут 
                                                # использоваться фичи этого стандарта)

set(CMAKE_CXX_STANDARD_REQUIRED ON)             # при сборке платформа будет проверять поддержку стандарта C++17 компилятором

set(CMAKE_BUILD_TYPE Debug)                     # конфигурация сборки - Debug

set(sources src/main.cpp)                       # записываем файлы исходного кода в переменную sources

add_executable(matrix_demo ${sources})          # название исполняемого файла и из каких исходных файлов его собирать

target_link_libraries(matrix_demo PRIVATE shared_matrix_lib)      # подключение динамической библиотеки
target_link_directories(matrix_demo PRIVATE "libs/matrixlib/")    # Установка пути, по которому производить поиск библиотеки

