//
//  clothing.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/4.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include <string>
#include "goods.hpp"
#include "clothing.hpp"

Clothing::Clothing() {
    
}

Clothing::Clothing(string name,string description,double price,int remaining,string type, Merchant* mer){
    this->name = name;
    this->description = description;
    this->price = price;
    this->remaining = remaining;
    this->type = type;
    this->merchant = mer;
}

Clothing::~Clothing() {
    
}
