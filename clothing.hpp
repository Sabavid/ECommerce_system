//
//  clothing.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/4.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef clothing_hpp
#define clothing_hpp

#include <stdio.h>
#include "merchant.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Goods;
class Merchant;

class Clothing : public Goods {
public:
    Clothing();
    Clothing(string name, string description,double price,int remaining,string type, Merchant *mer);
    ~Clothing();
    double get_price(){return price;}
    
};

#endif /* clothing_hpp */
