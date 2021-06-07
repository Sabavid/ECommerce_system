//
//  account_system.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/4.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef account_system_hpp
#define account_system_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "account.hpp"
#include "merchant.hpp"
#include "consumer.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Account;
class Goods;
class Merchant;
class Consumer;

class AccountSystem {
public:
    AccountSystem();
    ~AccountSystem();
    
    void readFile();    //加载文件中存储的信息
    void writeFile();   //保存进文件
    void mainMenu();    //主界面,进行功能选择
    void merchantOperate();
    void consumerOperate();
    void showGoods();   //展示商品
    void showAccounts();
    void login();   //用户登陆
    void signin();  //用户注册
    void signin(const string &id);
    
private:
    map<string, Account*> id2account;    //账号到账户的映射
    vector<Account*> accounts;

    map<string, Merchant*> merchants;
    map<string, Consumer*> consumers;
    //存储所有的商品
    vector<Goods*> goods;
    
    Account *online_account;
};

#endif /* account_system_hpp */
