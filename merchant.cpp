//
//  merchant.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include "account.hpp"
#include "merchant.hpp"
#include "goods.hpp"
#include "book.hpp"
#include "food.hpp"
#include "clothing.hpp"

Merchant::Merchant() {
    
}

Merchant::Merchant(Account *account) {
    this->account = account;
}

Merchant::~Merchant() {
    
}

void Merchant::set_name(vector<Goods*> &goods) {
    if(goods.size()==0) return;
    cout<<"请输入你想管理名称的商品编号"<<endl;
    int n;
    cin>>n;
    //判断编号是否合法、商品是否所属该商家
    while(n>goods.size()||n<1||
          (n<=goods.size()&&n>0&&goods[n-1]->get_merchant()!=this)) {
        if(n>goods.size()||n<1)
            cout<<"请输入正确的商品编号，1～"<<goods.size()<<endl;
        else cout<<"您无权修改不属于您的商品，请重新输入"<<endl;
        cin>>n;
    }
    string name;
    cout<<"请输入更改后的名称"<<endl;
    cin>>name;
    goods[n-1]->set_name(name);
    cout<<"名称修改成功"<<endl;
}

void Merchant::set_price(vector<Goods*> &goods) {
    if(goods.size()==0) return;
    cout<<"请输入你想管理价格的商品编号"<<endl;
    int n;
    cin>>n;
    //判断编号是否合法、商品是否所属该商家
    while(n>goods.size()||n<1||
          (n<=goods.size()&&n>0&&goods[n-1]->get_merchant()!=this)) {
        if(n>goods.size()||n<1)
            cout<<"请输入正确的商品编号，1～"<<goods.size()<<endl;
        else cout<<"您无权修改不属于您的商品，请重新输入"<<endl;
        cin>>n;
    }
    double price;
    cout<<"请输入更改后的价格"<<endl;
    cin>>price;
    goods[n-1]->set_price(price);
    cout<<"价格修改成功"<<endl;
}

void Merchant::set_remaining(vector<Goods*> &goods) {
    //商品编号从1开始
    if(goods.size()==0) return;
    cout<<"请输入你想管理剩余量的商品编号"<<endl;
    int n;
    cin>>n;
    //判断编号是否合法、商品是否所属该商家
    while(n>goods.size()||n<1||
          (n<=goods.size()&&n>0&&goods[n-1]->get_merchant()!=this)) {
        if(n>goods.size()||n<1)
            cout<<"请输入正确的商品编号，1～"<<goods.size()<<endl;
        else cout<<"您无权修改不属于您的商品，请重新输入"<<endl;
        cin>>n;
    }
    int remaining;
    cout<<"请输入更改后的剩余量"<<endl;
    cin>>remaining;
    goods[n-1]->set_remaining(remaining);
    cout<<"剩余量修改成功"<<endl;
}

void Merchant::set_description(vector<Goods*> &goods) {
    if(goods.size()==0) return;
    cout<<"请输入你想管理描述的商品编号"<<endl;
    int n;
    cin>>n;
    //判断编号是否合法、商品是否所属该商家
    while(n>goods.size()||n<1||
          (n<=goods.size()&&n>0&&goods[n-1]->get_merchant()!=this)) {
        if(n>goods.size()||n<1)
            cout<<"请输入正确的商品编号，1～"<<goods.size()<<endl;
        else cout<<"您无权修改不属于您的商品，请重新输入"<<endl;
        cin>>n;
    }
    string description;
    cout<<"请输入更改后的描述"<<endl;
    cin>>description;
    goods[n-1]->set_description(description);
    cout<<"描述修改成功"<<endl;
}

void Merchant::add_goods(vector<Goods*> &goods) {
    Goods *good;
    int remaining;
    string name,description,type;
    double price;
    cout<<"请输入你想添加的商品种类(book/food/clothing)"<<endl;
    cin>>type;
    cout<<"请输入商品名称(用下划线代替空格)"<<endl;
    cin>>name;
    cout<<"请输入商品描述(用下划线代替空格)"<<endl;
    cin>>description;
    cout<<"请输入商品价格"<<endl;
    cin>>price;
    cout<<"请输入商品剩余量"<<endl;
    cin>>remaining;
    if(type=="book") {
        good = new Book(name,description,price,remaining,type,this);
    } else if(type=="food") {
        good = new Food(name,description,price,remaining,type,this);
    } else {
        good = new Clothing(name,description,price,remaining,type,this);
    }
    goods.push_back(good);
    cout<<"商品增加成功"<<endl;
}

void Merchant::onsale(vector<Goods*> &goods) {
    if(goods.size()==0) return;
    cout<<"请输入你想打折的商品种类(book/food/clothing)"<<endl;
    string type;
    cin>>type;
    double rate;
    cout<<"输入你想打折的折扣率"<<endl;
    cin>>rate;
    for(auto &good : goods) {
        //只能管理属于自己的商品
        if(good->get_type()==type && good->get_merchant()==this)
            good->set_price(good->get_price()*rate);
    }
    cout<<"打折成功"<<endl;
}

void Merchant::menu() {
    cout << endl<<"      请选择操作序号！(0~6)" << endl;
    cout << "************************************" << endl;
    cout << "*                                  *" << endl;
    cout << "*           0.退出登陆              *" << endl;
    cout << "*           1.商品名称管理           *" << endl;
    cout << "*           2.商品描述管理           *" << endl;
    cout << "*           3.商品剩余量管理         *" << endl;
    cout << "*           4.商品价格管理           *" << endl;
    cout << "*           5.添加商品              *" << endl;
    cout << "*           6.同类商品打折           *" << endl;
    cout << "*           7.查询商品              *" << endl;
    cout << "*           8.更改密码              *" << endl;
    cout << "*           9.余额查询              *" << endl;
    cout << "*           10.充值                *" << endl;
    cout << "*           11.消费                *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
}
