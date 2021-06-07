//
//  user.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef user_hpp
#define user_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "account.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Account;
class Goods;

class User {
public:
    User();
    User(Account *account);
    virtual ~User();
    
    virtual string getUserType() = 0;
    
    Account* get_account(){return account;}
    
    void changePassword();
    
    void getBalance();
    void recharge();
    void purchase(vector<Goods*> &goods);
    
    void findGood(vector<Goods*> &goods);
    
    void findGoodName(vector<Goods*> &goods);
    void findGoodPriceUp(vector<Goods*> &goods);
    void findGoodPriceDown(vector<Goods*> &goods);
    void findGoodRemainUp(vector<Goods*> &goods);
    void findGoodRemainDown(vector<Goods*> &goods);
    void findGoodType(vector<Goods*> &goods);
    
protected:
    Account *account;
};

#endif /* user_hpp */
