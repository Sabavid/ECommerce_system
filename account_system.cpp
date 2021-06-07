//
//  account_system.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/4.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <stdio.h>
#include "account.hpp"
#include "account_system.hpp"
#include "user.hpp"
#include "merchant.hpp"
#include "consumer.hpp"
#include "goods.hpp"
#include "book.hpp"
#include "food.hpp"
#include "clothing.hpp"

AccountSystem::AccountSystem() {
    readFile();
}

AccountSystem::~AccountSystem() {
    writeFile();
    for(int i = 0; i<accounts.size(); i++) {
        delete accounts[i];
    }
    for(int i = 0; i<goods.size(); i++) {
        delete goods[i];
    }
    for(auto item : merchants) {
        if(item.second!=nullptr) delete item.second;
    }
    for(auto item : consumers) {
        if(item.second!=nullptr) delete item.second;
    }
}

void AccountSystem::readFile() {
    ifstream fin_account;
    fin_account.open("/Users/tom/account.dic",ios::in);
    if (!fin_account.is_open()) {
        cout << "文件打开失败"<<endl;
        exit(EXIT_FAILURE);
    }
    string id, psw, type;
    double balance;
    while(fin_account>>id>>psw>>balance>>type) {
        Account *account = new Account(id,psw,balance,type);
        id2account[id] = account;
        accounts.push_back(account);
        Merchant* merchant;
        Consumer* consumer;
        if(type=="merchant") {
            merchant = new Merchant(account);
            merchants[account->get_id()] = merchant;
        }
        else {
            consumer = new Consumer(account);
            consumers[account->get_id()] = consumer;
        }
    }//while
    fin_account.close();
    
    ifstream fin_goods;
    fin_goods.open("/Users/tom/goods.dic",ios::in);
    if (!fin_goods.is_open()) {
        cout << "文件打开失败"<<endl;
        exit(EXIT_FAILURE);
    }
    string name, description;
    double price;
    int remaining;
    while(fin_goods>>name>>description>>price>>remaining>>type>>id) {
        Goods *good;
        if(type=="book") {
            good = new Book(name,description,price,remaining,type,merchants[id]);
        } else if(type=="food") {
            good = new Food(name,description,price,remaining,type,merchants[id]);
        } else {
            good = new Clothing(name,description,price,remaining,type,merchants[id]);
        }
        goods.push_back(good);
    }//while
    fin_goods.close();
}

void AccountSystem::writeFile() {
    ofstream fout_account;
    fout_account.open("/Users/tom/account.dic",ios::out|ios::trunc);
    if (!fout_account.is_open()) {
        cout <<"文件打开失败"<<endl;
        exit(EXIT_FAILURE);
    }
    for(auto account : accounts) {
        fout_account<<account->get_id()<<" "<<account->get_password()<<" "<<account->get_balance()<<" "<<account->get_type()<<endl;
    }
    fout_account.close();
    
    ofstream fout_goods;
    fout_goods.open("/Users/tom/goods.dic",ios::out|ios::trunc);
    if (!fout_goods.is_open()) {
        cout <<"文件打开失败"<<endl;
        exit(EXIT_FAILURE);
    }
    for(auto good : goods) {
        fout_goods<<good->get_name()<<" "<<good->get_description()<<"  "<<good->get_price()<<" "<<good->get_remaining()<<" "<<good->get_type()<<" "<<good->get_merchant()->get_account()->get_id()<<endl;
    }
    fout_goods.close();
}

void AccountSystem::mainMenu() {
    int x;
    cout << endl<<"       请选择操作序号！(0~2)" << endl;
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*              0.退出              *" << endl;
    cout << "*              1.登陆              *" << endl;
    cout << "*              2.注册              *" << endl;
    cout << "*         3.查看所有账号信息         *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
    cin>>x;
    while(x!=0)
    {
        switch(x) {
            case 1:
                login();
                break;
            case 2:
                signin();
                break;
            case 3:
                showAccounts();
                break;
            default:
                cout<<"请输入正确的数字哦～"<<endl;
                break;
        }
        cout << endl<<"       请选择操作序号！(0~2)" << endl;
        cout << "***********************************" << endl;
        cout << "*                                 *" << endl;
        cout << "*              0.退出              *" << endl;
        cout << "*              1.登陆              *" << endl;
        cout << "*              2.注册              *" << endl;
        cout << "*         3.查看所有账号信息         *" << endl;
        cout << "*                                 *" << endl;
        cout << "***********************************" << endl;
        cin>>x;
    }
}

void AccountSystem::signin() {
    string id,psw,check;
    cout<<"请输入您要注册的账号"<<endl;
    cin>>id;
    while(id2account.count(id)) {
        cout<<"该账号已存在，请更换后重新输入"<<endl;
        cin>>id;
    }
    do {
        cout<<"请输入密码"<<endl;
        cin>>psw;
        cout<<"请确认密码"<<endl;
        cin>>check;
        if(check!=psw) cout<<"两次输入密码不同"<<endl;
    } while(check!=psw);
    cout<<"请选择您要注册的账号类型(consumer或merchant）"<<endl;
    string type;
    cin>>type;
    Account *new_account = new Account(id,psw,type);
    //新注册账号对应的用户存入merchants或consumers
    if(type=="merchant") {
        Merchant *new_merchant = new Merchant(new_account);
        merchants[id] = new_merchant;
    } else {
        Consumer *new_consumer = new Consumer(new_account);
        consumers[id] = new_consumer;
    }
    accounts.push_back(new_account);
    id2account[id] = new_account;
    cout<<"恭喜您注册成功，您的账号是:"<<id<<endl;
}

void AccountSystem::signin(const string &id) {
    string psw,check;
    cout<<"您的账号是"<<id<<",";
    do {
        cout<<"请输入密码"<<endl;
        cin>>psw;
        cout<<"请确认密码"<<endl;
        cin>>check;
        if(check!=psw) cout<<"两次输入密码不同"<<endl;
    } while(check!=psw);
    cout<<"请选择您要注册的账号类型（consumer或merchant）"<<endl;
    string type;
    cin>>type;
    Account *new_account = new Account(id,psw,type);
    //新注册账号对应的用户存入merchants或consumers
    if(type=="merchant") {
        Merchant *new_merchant = new Merchant(new_account);
        merchants[id] = new_merchant;
    } else {
        Consumer *new_consumer = new Consumer(new_account);
        consumers[id] = new_consumer;
    }
    accounts.push_back(new_account);
    id2account[id] = new_account;
    cout<<"恭喜您注册成功，您的账号是:"<<id<<endl;
}

void AccountSystem::login() {
    string id,psw;
    cout<<"请输入您的账号"<<endl;
    cin>>id;
    int x;
    while(1){
        while(id2account.find(id)==id2account.end()) {
            //如果没找到
            cout<<"账号不存在，注册请输入1，重新输入账户输入2"<<endl;
            cin>>x;
            while(x!=1&&x!=2) {
                cout<<"请输入1或2"<<endl;
                cin>>x;
            }
            if(x==1) {
                signin(id);
                break;
            }
            cout<<"请重新输入您的账号"<<endl;
            else cin>>id;
        }//while(没找到)
        cout<<"请输入密码"<<endl;
        cin>>psw;
        while (psw!=id2account[id]->get_password()) {
            cout<<"密码错误，重新输入请按1，更换账号请按2"<<endl;
            cin>>x;
            while(x!=1&&x!=2) {
                cout<<"请输入1或2"<<endl;
                cin>>x;
            }
            if(x==2) break;
            cout<<"请重新输入密码"<<endl;
            cin>>psw;
        }//while(密码错误)
        if(psw==id2account[id]->get_password()) {
            cout<<"登陆成功"<<endl;
            online_account = id2account[id];
            break;
        }
    }
    if(online_account->get_type()=="merchant")
        merchantOperate();
    else consumerOperate();
}

void AccountSystem::showGoods() {
    if(goods.size()==0) {
        cout<<"当前系统中没有商品"<<endl;
        return;
    }
    cout<<"当前系统中有如下商品："<<endl<<endl;
    
    //商品编号从1开始，和下标有1的偏差
    for (int i = 0; i<goods.size(); i++) {
        cout<<"商品编号："<<i+1<<endl;
        goods[i]->show_good();
        cout<<endl;
    }
}

void AccountSystem::showAccounts() {
    if(accounts.size()==0) {
        cout<<"当前系统中没有账户"<<endl;
        return;
    }
    cout<<"当前系统中有如下账户："<<endl<<endl;
    
    //账户编号从1开始，和下标有1的偏差
    for (int i = 0; i<accounts.size(); i++) {
        cout<<"账户编号："<<i+1<<endl;
        accounts[i]->show_account();
        cout<<endl;
    }
}

void AccountSystem::merchantOperate() {
    int x;
    Merchant *merchant = merchants[online_account->get_id()];
    cout<<"当前在线账号id为："<<online_account->get_id()<<endl;
    merchant->menu();
    showGoods();
    cin>>x;
    while(x!=0) {
        switch(x) {
            case 1:
                merchant->set_name(goods);
                break;
            case 2:
                merchant->set_description(goods);
                break;
            case 3:
                merchant->set_remaining(goods);
                break;
            case 4:
                merchant->set_price(goods);
                break;
            case 5:
                merchant->add_goods(goods);
                break;
            case 6:
                merchant->onsale(goods);
                break;
            case 7:
                merchant->findGood(goods);
                break;
            case 8:
                //更改密码
                merchant->changePassword();
                break;
            case 9:
                //余额查询
                merchant->getBalance();
                break;
            case 10:
                //充值
                merchant->recharge();
                break;
            case 11:
                //消费
                merchant->purchase(goods);
                break;
            default:
                cout<<"请输入正确的数字哦～"<<endl;
                break;
        }//switch
        cout<<"当前在线账号id为："<<online_account->get_id()<<endl;
        merchant->menu();
        showGoods();
        cin>>x;
    }//while
    cout<<"您已成功退出商家管理系统"<<endl;
}

void AccountSystem::consumerOperate() {
    Consumer *consumer = consumers[online_account->get_id()];
    cout<<"当前在线账号id为："<<online_account->get_id()<<endl;
    consumer->menu();
    showGoods();
    int x;
    cin>>x;
    while(x!=0) {
        switch(x) {
            case 1: {
                //修改密码
                consumer->changePassword();
                break;
            }
            case 2: {
                //余额查询
                consumer->getBalance();
                break;
            }
            case 3: {
                //充值
                consumer->recharge();
                break;
            }
            case 4: {
                //购买商品
                consumer->purchase(goods);
                break;
            }
            case 5: {
                //查询商品
                consumer->findGood(goods);
                break;
            }
            case 6: {
                //购物车管理
                consumer->cartManage(goods);
                break;
            }
            default: {
                cout<<"请输入正确的数字哦～"<<endl;
                break;
            }
        }//switch
        cout<<"当前在线账号id为："<<online_account->get_id()<<endl;
        consumer->menu();
        showGoods();
        cin>>x;
    }//while
    cout<<"您已成功退出买家系统"<<endl;
}
