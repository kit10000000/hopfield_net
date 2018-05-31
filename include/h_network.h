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

#ifndef h_network_h
#define h_network_h

namespace Hopfield {
    class hopfield{
    public:
        int rows = 0;
        int columns = 0;
        std::vector<std::vector<int>> etalon;
        std::vector<std::vector<int>> patterns;
        std::vector<std::vector<int>> new_patterns;
        hopfield();
        void vectorization(std::vector<std::vector<int>> inputs, std::vector<std::vector<int>>* array);
        void init_weights(int size);
        bool recognition();
        bool check_size(std::vector<std::vector<int>> array);
        int count_net(int i, std::vector<int> n);
        int multiply_pattern(int row, int col);
        void clean_vectors();
        void print_res(std::vector<std::vector<int>> patterns);
        bool save_to_file(std::string filename);
        ~hopfield();
    private:
        std::vector<std::vector<int>> weights;
    };
}

#endif /* h_network_h */
