//
//  order.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/5/18.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef order_hpp
#define order_hpp

#include <stdio.h>
#include <map>
#include "goods.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Goods;

class Order {
public:
    Order();
    Order(vector<Goods*> &goods, const map<int,int> &selected);
    
    map<int,int> get_goods() {return good_list;}
    double get_price() {return total_price;}
    int get_state() {return state;}
    
    void set_state(int x) {state = x;}
    
    void release(vector<Goods*> &goods);
    void showOrder(vector<Goods*> &goods);
    void transfer(vector<Goods*> &goods);    //把用户扣除的钱转移到商家账户中
    
private:
    //first是商品编号，second是商品数量
    map<int,int> good_list;
    double total_price;
    
    //订单状态（0待支付/1已支付）
    int state;
};


#endif /* order_hpp */
