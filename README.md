# hopfield_net
[![Build Status](https://travis-ci.org/kit10000000/hopfield_net.svg?branch=master)](https://travis-ci.org/kit10000000/hopfield_net)
[![Build status](https://ci.appveyor.com/api/projects/status/6tueohl8ln6lont9?svg=true)](https://ci.appveyor.com/project/kit10000000/hopfield-net)

Целью данного проекта является программная реализация на языке C++ метода распознавания простейшего изображения на основе нейронной сети Хопфилда.

Интерфейс программы:

Выберите одну из операций:
1. Ввод эталона из файла
2. Ввод паттерна из файла
3. Распознавание изображения
4. Вывод в файл
5. Вывод на экран
6. Очистка эталонов и паттернов
7. Завершить работу программы

Документация: [:green_book:](https://kit10000000.github.io/hopfield_net/index.html)

Требования:
1. - [x] Файлы исходного кода должны располагаться на сервисе GitHub
в открытом репозитории
2. - [x] Код должен быть читабельным и оформлен в едином стиле.
astyle
3. - [x] Файлы исходного кода должны пройти проверку утилитой
cpplint.
4. - [x] Оформить README.md файл, содержащий описание проекта.
5. - [x] Оформить .gitignore файл.
6. - [x] Создать CMakeLists.txt для автоматизации сборки проекта.
7. - [x] Добавить в CMakeLists.txt автоматизацию процесса сборки
примеров.
8. - [x] Обеспечить непрерывный процесс сборки и тестирование проекта
с использованием сервисов Travis CI и AppVeyor.
9. - [x] Написать документацию к проекту с использованием инструмента
doxygen и разместить ее на сервисе GitHub Page.
10. - [x] Добавить в CMakeLists.txt автоматизацию процесса
пакетирования.
11. - [x] Обеспечить 100% покрытие кода с использованием фреймворка
Catch.



```ShellSession
$ git clone https://github.com/kit10000000/hopfield_net.git hopfield_net
$ cd hopfield_net
$ cmake -H. -B_build 
$ cmake --build _build
```
