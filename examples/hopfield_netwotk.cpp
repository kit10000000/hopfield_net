//
//  main.cpp
//  hopfield_network
//
//  Created by E. Chernikova on 29.05.2018.
//  Copyright © 2018 E. Chernikova. All rights reserved.
//

#include "../include/ui.h"

int main(int argc, const char * argv[]) {
    Hopfield::UI interface;
    Hopfield::hopfield network;
    interface.work(network);
    return 0;
}
