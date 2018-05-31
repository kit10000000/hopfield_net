//
//  ui.cpp
//  hopfield_network
//
//  Created by E. Chernikova on 29.05.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include "../include/ui.h"

void  Hopfield::UI::print_menu() {
    std::cout << "Выберите одну из операций:" << std::endl;
    std::cout << "1. Ввод эталона из файла" << std::endl;
    std::cout << "2. Ввод паттерна из файла" << std::endl;
    std::cout << "3. Распознавание" << std::endl;
    std::cout << "4. Вывод в файл" << std::endl;
    std::cout << "5. Вывод на экран" << std::endl;
    std::cout << "6. Очистка эталонов и паттернов" << std::endl;
    std::cout << "7. Завершить работу программы" << std::endl;
}

bool Hopfield::UI::check_file_exist(std::string &path) {
    std::ifstream f(path.c_str());
    return f.good();
}


std::vector<std::vector<int>> Hopfield::UI::upload(bool need_path,Hopfield::hopfield& network) {
    std::string path = "1.txt";
    if (need_path){
        std::cout << "Введите название файла" << std::endl;
        path = user_input();
    }
    bool check = check_file_exist(path);
    std::vector<std::vector<int>> inputs;
    if (check) {
        std::string buffer;
        std::ifstream f;
        f.open(path, std::ios::out);
        if (f.is_open()) {
            std::vector<int> tmp;
            int rows_count = 0;
            int cols_count = 0;
            while ( getline(f, buffer, '\n') ) {
                if (network.columns==0){
                    network.columns = (int)buffer.size();
                }
                    if (buffer.empty()){
                        if (network.rows==0){
                            network.rows = rows_count;
                        }
                        std::cout << buffer << std::endl;
                        rows_count = 0;
                        inputs.push_back(tmp);
                        tmp.clear();
                    } else {
                        rows_count++;
                        std::cout << buffer << std::endl;
                        cols_count = 0;
                        for (int i = 0; i < buffer.size(); i++){
                            cols_count++;
                            if(buffer[i] == '-')
                                tmp.push_back(-1);
                            if(buffer[i] == '1')
                                tmp.push_back(1);
                        }
                        buffer.clear();
                    }
            }
            if ((rows_count == network.rows) && (cols_count == network.columns))
            {
                inputs.push_back(tmp);
                tmp.clear();
                f.close();
                std::cout << "Изображения успешно загружены" << std::endl;
            }
            else{
                std::cout << "Изображения должны быть одного размера" << std::endl;
            }
        }
    } else {
        std::cerr << "Файла с заданным путем не существует" << std::endl;
    }
    return inputs;
}

std::string Hopfield::UI::user_input(){
    std::string in;
    while (!(std::cin >> in)) {
        std::cout << "Неправильный ввод";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return in;
}

int Hopfield::UI::input() {
    int in;
    while (!(std::cin >> in))
    {
        std::cout << "Неправильный ввод"<< std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return in;
}


void Hopfield::UI::work(Hopfield::hopfield& network) {
    print_menu();
    while (true) {
        std::cout << "Выберите одну из операций:" << std::endl;
        int c = input();
        switch (c) {
            case 1:
                std::cout << "1. Ввод эталона из файла" << std::endl;
                network.vectorization(upload(true, network), &network.etalon);
                print_menu();
                break;
            case 2:
                std::cout << "2. Ввод паттерна из файла" << std::endl;
                network.vectorization(upload(true,network), &network.patterns);
                print_menu();
                break;
            case 3:
                std::cout << "3. Распознавание" << std::endl; //to do: добавить предложение о сохранении образа в файл
                network.recognition();
                break;
            case 4:
                std::cout << "4. Вывод в файл" << std::endl;
                if (network.check_size(network.new_patterns)){
                        std::cout << "Введите название файла" << std::endl;
                        std::string file_name = Hopfield::UI::user_input();
                        if (Hopfield::UI::check_file_exist(file_name)){
                            std::cout << "Файл уже существует. Перезаписать?" << std::endl;
                            if(while_yes_or_no())
                            {
                                std::cout << ((network.save_to_file(file_name)) ? "Сохранено" : "Сохранить не удалось")<< std::endl;
                            } else{
                                break;
                            }
                        } else{
                            std::cout << ((network.save_to_file(file_name)) ? "Сохранено" : "Сохранить не удалось")<< std::endl;
                        }
                    }
                    else{
                        std::cout << "Нечего сохранять" << std::endl;
                    }
                break;
            case 5:
                std::cout << "5. Вывод на экран" << std::endl;
                network.print_result();
                print_menu();
                break;
            case 6:
                std::cout << "6. Очистка эталонов и паттернов" << std::endl;
                network.clean_vectors();
                break;
            case 7:
                std::cout << "7. Завершить работу программы" << std::endl;
                std::cout << "Вы уверены, что хотите выйти из программы ?" << std::endl;
                if(while_yes_or_no())
                    return;
                break;
            default:
                std::cout << "Не является пунктом меню" << std::endl;
        }
    }
}

bool Hopfield::UI::while_yes_or_no(){
    std::string decision = "";
    while (decision != "Нет" && decision != "Да") {
        std::cout << "Введите 'Да' или 'Нет'" << std::endl;
        decision = user_input();
    }
    if (decision == "Да") {
        return true;
    }
    return false;
}
