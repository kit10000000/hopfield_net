//
//  h_network.cpp
//  hopfield_network
//
//  Created by E. Chernikova on 29.05.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include "../include/h_network.h"

Hopfield::hopfield::hopfield(){
    std::vector<std::vector<int>> etalon ={};
    std::vector<std::vector<int>> patterns ={};
    std::vector<std::vector<int>> weights = {};
    std::vector<std::vector<int>> new_patterns = {};
    this -> rows = 0;
    this -> columns = 0;
};

Hopfield::hopfield::~hopfield(){
    clean_vectors();
};

void Hopfield::hopfield::vectorization(std::vector<std::vector<int>> inputs, std::vector<std::vector<int>> *array){
    if (check_size(inputs)){
        for (auto n : inputs) {
            array->push_back(n);
        }
    }
};

void Hopfield::hopfield::clean_vectors(){
    this->etalon.clear();
    this->patterns.clear();
    this->new_patterns.clear();
    this->weights.clear();
    this -> rows = 0;
    this ->columns = 0;
};

bool Hopfield::hopfield::check_size(std::vector<std::vector<int>> array){
    if(array.size() > 0){
        return true;
    }
    return false;
}

int Hopfield::hopfield::multiply_pattern(int row, int col) {
    int element = 0;
    for(auto n : etalon){
        element += n[row]*n[col];
    }
    return element;
}
void Hopfield::hopfield::init_weights(int size){
    for( int row = 0; row < size; row++ ){
        std::vector<int> temp;
        for( int col = 0; col < size; col++ ) {
            if( row == col ) {
                temp.push_back( 0 );
            }else {
                temp.push_back(multiply_pattern(row, col));
            }
        }
        weights.push_back(temp);
    }
};
int Hopfield::hopfield::count_net(int i, std::vector<int> n){
    int net = 0;
    for (int j = 0; j < weights.size(); j++){
        net+= weights[j][i]* n[j];
    }
    return net;
};
bool Hopfield::hopfield::recognition(){
    if (check_size(etalon) && check_size(patterns)){
        init_weights((int)etalon[0].size());
        for (auto n :patterns){
            std::vector <int> recognised_vec = n;
            for (int age = 0; age < 10 ; age ++){
                for (int i = 0; i < n.size(); i ++){
                    int get_net = count_net(i, recognised_vec);
                    if (get_net > 0) {
                        recognised_vec[i] = 1;
                    }
                    if (get_net < 0) {
                        recognised_vec[i] = - 1;
                    }
                }
            }
            this -> new_patterns.push_back(recognised_vec);
        }
        if (this -> new_patterns.size() > 0){
            std::cout<<"Распознавание закончено успешно"<<std::endl;
            return true;
        }
        else{
            std::cout<<"Распознавание закончено неуспешно"<<std::endl;
            return false;
        }
        
    }else{
        
        std::cout<<"Нет паттернов или эталонов для распознавания"<<std::endl;
        return false;
    }
    return false;
};
bool Hopfield::hopfield::save_to_file(std::string filename){
    
    std::ofstream f;
    f.open(filename);
    for(auto n: new_patterns){
        for( int i = 0; i < n.size(); i+= this -> columns) {
            for( int j = i; j < this -> columns+i && j < n.size(); j++) {
                if( n[j] == -1 ) f << "\u2B1C";
                else f << "\u2B1B";
            }
            f<<std::endl;
        }
        f <<"\n" <<std::endl;
    }
    f.close();
    return true;
}
void Hopfield::hopfield::print_res(std::vector<std::vector<int>> vec) {
    if (check_size(vec)){
        for(auto n: vec){
            for( int i = 0; i < n.size(); i+= this -> columns) {
                for( int j = i; j < this -> columns+i && j < n.size(); j++) {
                    if( n[j] == -1 || n[j] == '-') std::cout << "\u2B1C";
                    else std::cout << "\u2B1B";
                }
                std::cout<<std::endl;
            }
            std::cout <<"\n" <<std::endl;
        }
    }
    else{
        std::cout<<"Нечего выводить"<<std::endl;
    }
    
};

