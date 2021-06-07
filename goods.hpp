//
//  goods.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef goods_hpp
#define goods_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "merchant.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Merchant;

class Goods {
public:
    Goods();
    Goods(string name, string description, double price, int remaining, string type, Merchant *mer);
    virtual ~Goods();
        
    string get_name(){return name;}
    string get_description(){return description;}
    virtual double get_price() = 0;
    int get_remaining(){return remaining;}
    string get_type(){return type;}
    Merchant* get_merchant() {return merchant;}
    
    void set_description(string description){
        this->description = description;
    }
    void set_price(double price){this->price = price;}
    void set_remaining(int remain){remaining = remain;}
    void set_name(string name){this->name = name;}
    void set_type(string type){this->type = type;}
    void set_merchant(Merchant *mer) {merchant = mer;}
    
    void show_good();
    
protected:
    string name;
    string description;
    double price;
    int remaining;
    string type;
    //所属商家(只会把对应的id存入文件）
    Merchant* merchant;
};

#endif /* goods_hpp */
