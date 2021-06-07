//
//  account.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef account_hpp
#define account_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Account {
public:
    Account();
    Account(string id, string password, string type);
    Account(string id, string password, double balance, string type);
    ~Account();
    
    string get_password(){return password;}
    string get_id(){return id;}
    double get_balance(){return balance;}
    string get_type(){return type;}
    
    void set_id(string id){this->id = id;}
    void set_password(string psw){password = psw;}
    
    void recharge(double money);
    void consume(double money);
    
    void show_account();
    void transIn(double money);
    void transOut(double money);
    
protected:
    string id;
    string password;
    double balance;//余额
    string type;   //"consumer"表示消费者，"merchant"表示商家
};

#endif /* account_hpp */
