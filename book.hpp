//
//  book.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/4.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef book_hpp
#define book_hpp

#include <stdio.h>
#include "goods.hpp"
#include "merchant.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Goods;
class Merchant;

class Book : public Goods {
public:
    Book();
    Book(string name,string description,double price,int remaining, string type,Merchant *mer);
    ~Book();
    double get_price(){return price;}
    
};

#endif /* book_hpp */
