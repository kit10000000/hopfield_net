//
//  ui.h
//  hopfield_network
//
//  Created by E. Chernikova on 29.05.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <limits>
#include <vector>
#include "../include/h_network.h"

#ifndef ui_h
#define ui_h
namespace  Hopfield {
    class UI {
    public:
        void work(hopfield& network);
        void print_menu();
        bool approve_choice();
        int input();
        std::string user_input();
        bool check_file_exist(std::string& path);
        std::vector<std::vector<int>> upload(bool need_path, hopfield& network);
        bool while_yes_or_no();
        
    };
}   //  namespace Hopfield

#endif /* ui_h */
