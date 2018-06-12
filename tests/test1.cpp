#include "catch.hpp"
#include "../include/h_network.h"
#include "../include/ui.h"

TEST_CASE("Test h_network", "[h_net]"){
    std::cout <<"Конструктор сети" << std::endl;
    Hopfield::hopfield h_net = Hopfield::hopfield();
    std::cout <<"Проверка размера массива с эталонами" << std::endl;
    REQUIRE(h_net.check_size(h_net.etalon)==false);
    REQUIRE(h_net.recognition()==false);
    std::cout <<"Проверка вывода для пустого массива" << std::endl;
    h_net.print_res(h_net.etalon);
    std::vector<std::vector<int>> inputs = {{-1, 1, -1, 1, 1,-1,-1, 1,-1,-1,1,-1, 1, 1, 1},{1, 1, 1,-1,-1,1,1,1, 1, 1, -1, -1, 1, 1,1}};
    h_net.rows = 5;
    h_net.columns = 3;
    std::cout <<"Векторизация введённых данных и вывод (для эталонов)" << std::endl;
    h_net.vectorization(inputs, &h_net.etalon);
    h_net.print_res(h_net.etalon);
    inputs ={{-1, 1, -1, -1, 1,-1,-1, 1,-11,-1,-1,-1, 1, 1, 1},{-1, -1, 1,1,-1,-1,-1,1, 1, 1, -1, 1, 1, 1,1}};
    std::cout <<"Векторизация введённых данных и вывод (для искаженных)" << std::endl;
    h_net.vectorization(inputs, &h_net.patterns);
    h_net.print_res(h_net.patterns);
    REQUIRE(h_net.recognition()==true);
    std::cout <<"Распознанные образы" << std::endl;
    h_net.print_res(h_net.new_patterns);
    std::string path = "1.txt";
    h_net.save_to_file(path);
    
}

