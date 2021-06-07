//
//  merchant.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef merchant_hpp
#define merchant_hpp

#include <stdio.h>
#include "user.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Account;
class Goods;
class User;

class Merchant : public User {
public:
    Merchant();
    Merchant(Account *account);
    ~Merchant();
    string getUserType(){return "merchant";}
    
    void menu();
    
    //商品名称管理
    void set_name(vector<Goods*> &goods);
    
    //商品价格管理
    void set_price(vector<Goods*> &goods);
    
    //商品剩余量管理
    void set_remaining(vector<Goods*> &goods);
    
    //商品描述管理
    void set_description(vector<Goods*> &goods);
    
    //添加商品
    void add_goods(vector<Goods*> &goods);
    
    //对同一类商品打折
    void onsale(vector<Goods*> &goods);
};

#endif /* merchant_hpp */
