//
//  order.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/5/18.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include "order.hpp"
#include "goods.hpp"

Order::Order() {
    total_price = 0;
}

Order::Order(vector<Goods*> &goods, const map<int,int> &selected) {
    for(auto item : selected) {
        good_list[item.first] = item.second;
        total_price += goods[item.first-1]->get_price()*item.second;
        state = 0;
        
        //冷冻商品
        goods[item.first-1]->set_remaining(goods[item.first-1]->get_remaining()-item.second);
    }
}

//释放冻结的商品余量
void Order::release(vector<Goods*> &goods) {
    for(auto item : good_list) {
        goods[item.first-1]->set_remaining(goods[item.first-1]->get_remaining()+item.second);
    }
}

void Order::showOrder(vector<Goods*> &goods) {
    cout<<"订单中商品如下："<<endl;
    for(auto item : good_list) {
        cout<<"商品名称："<<goods[item.first-1]->get_name()<<"，商品单价："<<goods[item.first-1]->get_price()<<"，商品件数："<<item.second<<endl;
    }
    cout<<"订单总金额："<<total_price<<endl;
    if(state==0) cout<<"订单状态：待支付"<<endl;
    else cout<<"订单状态：已支付"<<endl;
}

void Order::transfer(vector<Goods*> &goods) {
    for(auto item : good_list) {
        double money = goods[item.first-1]->get_price()*item.second;
        //商品盈利转入商家账户
        goods[item.first-1]->get_merchant()->get_account()->transIn(money);
    }
}
