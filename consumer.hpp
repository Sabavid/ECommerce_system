//
//  consumer.hpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef consumer_hpp
#define consumer_hpp

#include <stdio.h>
#include <map>
#include "user.hpp"
#include "order.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Goods;
class Account;
class Order;

class Consumer : public User {
public:
    Consumer();
    Consumer(Account *account);
    ~Consumer();
    
    string getUserType(){return "consumer";}
    
    void menu();
    void cartManage(vector<Goods*> &goods);
    void cartMenu();
    void showCart(const vector<Goods*> &goods);
    void addCart(const vector<Goods*> &goods);
    void rmCart(const vector<Goods*> &goods);
    void changeCart(const vector<Goods*> &goods);
    void select(const vector<Goods*> &goods);
    void unselect(const vector<Goods*> &goods);
    void generateOrder(vector<Goods*> &goods);   //订单生成
    void payOrder(vector<Goods*> &goods);    //订单支付
    void cancelOrder(vector<Goods*> &goods); //订单取消
    void showOrders(vector<Goods*> &goods);
    
private:
    //商品编号需要-1才等于商品下标
    //商品编号作为key，商品数量作为value，需要映射到goods数组中获取商品具体信息
    map<int,int> cart;
    //商品编号作为key，是否选中作为value
    map<int,int> selected;
    double total_price;
    
    //除非订单取消，否则都会存在这里（待支付/已支付）
    vector<Order> orders;
    
};

#endif /* consumer_hpp */
