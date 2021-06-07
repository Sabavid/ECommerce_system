//
//  goods.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include "goods.hpp"

Goods::Goods() {
    
}

Goods::Goods(string name,string description, double price, int remaining,string type, Merchant *mer):
    name(name),description(description),price(price),remaining(remaining),type(type),merchant(mer)
{
}

Goods::~Goods() {
}

void Goods::show_good() {
    cout<<"名称："<<name<<endl;
    cout<<"描述："<<description<<endl;
    cout<<"价格："<<price<<endl;
    cout<<"剩余量："<<remaining<<endl;
    cout<<"种类："<<type<<endl;
    cout<<"所属商家id："<<merchant->get_account()->get_id()<<endl;
}
