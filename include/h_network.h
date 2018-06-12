//
//  h_network.h
//  hopfield_network
//
//  Created by E. Chernikova on 29.05.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#ifndef h_network_h
#define h_network_h

namespace Hopfield {
class hopfield {
 public:
    int rows = 0;
    int columns = 0;
    std::vector<std::vector<int>> etalon;
    std::vector<std::vector<int>> patterns;
    std::vector<std::vector<int>> new_patterns;
    //!
    //!стандартный конструктор
    //!
    hopfield();
    //!
    //!векторизация изображения
    //!
    void vectorization(std::vector<std::vector<int>> inputs,
                       std::vector<std::vector<int>>* array);
    //!
    //!инициализация матрицы весов
    //!
    void init_weights(int size);
    //!
    //!этап распознавания
    //!
    bool recognition();
    //!
    //!проверка размера контейнеров
    //!
    bool check_size(std::vector<std::vector<int>> array);
    //!
    //!сподсчет сетевого выхода
    //!
    int count_net(int i, std::vector<int> n);
    //!
    //!перемножение строки на столбец для инициализации весов
    //!
    int multiply_pattern(int row, int col);
    //!
    //!очистка контейнеров
    //!
    void clean_vectors();
    //!
    //!вывод результата
    //!
    void print_res(std::vector<std::vector<int>> patterns);
    //!
    //!сохранение результата в файл
    //!
    bool save_to_file(std::string filename);
    //!
    //!деструктор
    //!
    ~hopfield();
 private:
    std::vector<std::vector<int>> weights;
};
}  // namespace Hopfield

#endif /* h_network_h */
