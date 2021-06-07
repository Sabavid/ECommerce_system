//
//  food.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/4.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef food_hpp
#define food_hpp

#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Goods;
class Merchant;

class Food : public Goods {
public:
    Food();
    Food(string name, string description,double price,int remaining,string type, Merchant *mer);
    ~Food();
    
    double get_price() {return price;}
    
};

#endif /* food_hpp */
