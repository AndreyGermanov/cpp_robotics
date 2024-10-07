from linalgebra import *;

# Создаем два вектора
v1 = Vector([1.2,2.3,3.3,3.4])
v2 = Vector([2,3,4,5])

# Тесты операторов
print("Сложение 3.2 5.3 7.3 8.4 =", v1+v2)
print("Вычитание 0.8 0.7 0.7 1.6 =", v1-v2)
print("Скалярное произведение 39.5 =", v1*v2)

# Тесты функций
print("Евклидова норма 5.401851534427801 =", v1.norm())
v1.normalize()
print("Нормализованный вектор 0.222146 0.42578 0.610902 0.629414 =", v1)
print("Норма нормализованного вектора:",v1.norm())
