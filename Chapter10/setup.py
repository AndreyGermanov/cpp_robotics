from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup

# Используем расширение Pybind11 для компиляции C++ в Python3
ext_modules = [
    Pybind11Extension(
        # Модуль будет называться:
        "linalgebra",
        # и будет компилироваться из этих файлов
        ["src/vector.cpp"]
    ),
]

# Запускаем процедуру сборки и установки пакета, которая включает 
# процедуру компиляции кода C++, определенную выше
setup(name="linalgebra", ext_modules=ext_modules, version="0.0.1")