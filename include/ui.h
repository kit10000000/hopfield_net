//
//  ui.h
//  hopfield_network
//
//  Created by E. Chernikova on 29.05.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include "../include/h_network.h"


#ifndef ui_h
#define ui_h
namespace  Hopfield {
class UI {
 public:
    //!
    //!работа с сетью
    //!
    void work(hopfield& network);
    //!
    //!вывод меню
    //!
    void print_menu();
    //!
    //!подтверждение выхода из программы
    //!
    bool approve_choice();
    //!
    //!числовой пользовательский ввод
    //!
    int input();
    //!
    //!строковый пользовательский ввод
    //!
    std::string user_input();
    //!
    //!проверка существования файла
    //!
    bool check_file_exist(std::string& path);
    //!
    //!загрузка изображений из файла
    //!
    std::vector<std::vector<int>> upload(bool need_path, hopfield& network);
    //!
    //!получение "да" или "нет" от пользователя
    //!
    bool while_yes_or_no();
};
}   //  namespace Hopfield

#endif /* ui_h */
