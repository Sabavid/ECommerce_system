//
//  account.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//
#include "account.hpp"

Account::Account(){}

Account::Account(string id,string password, string type):
id(id),password(password),balance(0),type(type) {
}

Account::Account(string id, string password, double balance, string type):id(id),password(password),balance(balance),type(type) {
    
}

Account::~Account() {
    
}

void Account::recharge(double money) {
    balance += money;
    cout<<"您本次充值"<<money<<"元，账户余额"<<balance<<"元"<<endl;
}

void Account::consume(double money) {
    balance -= money;
    cout<<"您本次消费"<<money<<"元，账户余额"<<balance<<"元"<<endl;
}

void Account::show_account() {
    cout<<"账号："<<id<<endl;
    cout<<"密码："<<password<<endl;
    cout<<"余额："<<balance<<endl;
    cout<<"类型："<<type<<endl;
}

void Account::transIn(double money) {
    balance += money;
    cout<<"账户："<<id<<" 转入 "<<money<<" 元"<<endl;
}

void Account::transOut(double money) {
    balance -= money;
    cout<<"账户："<<id<<" 转出 "<<money<<" 元"<<endl;
}
