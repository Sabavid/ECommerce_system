//
//  consumer.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//
#include "account.hpp"
#include "goods.hpp"
#include "consumer.hpp"

Consumer::Consumer() {
    
}

Consumer::Consumer(Account *account) {
    this->account = account;
    total_price = 0;
}

Consumer::~Consumer() {
    
}

void Consumer::menu() {
    cout << endl<<"      请选择操作序号！(0~6)" << endl;
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*            0.退出登陆             *" << endl;
    cout << "*            1.修改密码             *" << endl;
    cout << "*            2.余额查询             *" << endl;
    cout << "*            3.充值                *" << endl;
    cout << "*            4.购买商品             *" << endl;
    cout << "*            5.查询商品             *" << endl;
    cout << "*            6.购物车管理           *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
}

void Consumer::cartManage(vector<Goods*> &goods) {
    int x;
    showCart(goods);
    cartMenu();
    cin>>x;
    while(x!=0) {
        switch (x) {
            case 1:
                addCart(goods);
                break;
            case 2:
                rmCart(goods);
                break;
            case 3:
                changeCart(goods);
                break;
            case 4:
                select(goods);
                break;
            case 5:
                unselect(goods);
                break;
            case 6:
                generateOrder(goods);
                break;
            case 7:
                payOrder(goods);
                break;
            case 8:
                cancelOrder(goods);
                break;
            case 9:
                showOrders(goods);
                break;
            default:
                cout<<"请输入正确的数字哦～"<<endl;
                break;
        }
        showCart(goods);
        cartMenu();
        cin>>x;
    }
}

void Consumer::cartMenu() {
    cout << endl<<"      请选择操作序号！(0~6)" << endl;
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*            0.退出                *" << endl;
    cout << "*            1.增加商品             *" << endl;
    cout << "*            2.删除商品             *" << endl;
    cout << "*            3.修改数量             *" << endl;
    cout << "*            4.选中商品             *" << endl;
    cout << "*            5.取消选中             *" << endl;
    cout << "*            6.生成订单             *" << endl;
    cout << "*            7.支付订单             *" << endl;
    cout << "*            8.取消订单             *" << endl;
    cout << "*            9.查看全部订单         *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
}

void Consumer::showCart(const vector<Goods *> &goods) {
    if(cart.size()==0) {
        cout<<"当前购物车中没有商品"<<endl;
        return;
    }
    cout<<"当前购物车中有如下商品："<<endl<<endl;
    for(auto item : cart) {
        if(item.second==0) continue;
        cout<<"商品编号："<<item.first<<endl;
        goods[item.first-1]->show_good();
        cout<<"购物车中数量："<<item.second<<endl;
        cout<<"共计价格："<<item.second*goods[item.first-1]->get_price()<<endl;
        if(selected[item.first]) cout<<"是否选中：已选中"<<endl;
        else cout<<"是否选中：未选中"<<endl<<endl;
    }
    cout<<"选中商品价格共计："<<total_price<<endl;
}

void Consumer::addCart(const vector<Goods *> &goods) {
    int no,amount;
    cout<<"请输入您要添加入购物车的商品编号,1~"<<goods.size()<<endl;
    cin>>no;
    while(no>goods.size()||no<1) {
        cout<<"请输入正确的商品编号,1~"<<goods.size()<<endl;
        cin>>no;
    }
    cout<<"请输入您要添加的件数，1~"<<goods[no-1]->get_remaining()-cart[no]<<endl;
    cin>>amount;
    while(amount>goods[no-1]->get_remaining()-cart[no]||amount<1) {
        cout<<"请输入正确的商品数量,1~"<<goods[no-1]->get_remaining()-cart[no]<<endl;
        cin>>amount;
    }
    cart[no] += amount;
}

void Consumer::rmCart(const vector<Goods *> &goods) {
    int no,amount;
    cout<<"请输入您要从购物车移出的商品编号,1~"<<goods.size()<<endl;
    cin>>no;
    while(no>goods.size()||no<1) {
        cout<<"请输入正确的商品编号,1~"<<goods.size()<<endl;
        cin>>no;
    }
    cout<<"请输入您要移出的件数,1~"<<cart[no]<<endl;
    cin>>amount;
    while(amount>cart[no]||amount<1) {
        cout<<"请输入正确的商品数量,1~"<<cart[no]<<endl;
        cin>>amount;
    }
    cart[no] -= amount;
}

void Consumer::changeCart(const vector<Goods *> &goods) {
    int no,amount;
    cout<<"请输入您要更改数量的商品编号"<<endl;
    cin>>no;
    while(no>goods.size()||no<1) {
        cout<<"请输入正确的商品编号,1~"<<goods.size()<<endl;
        cin>>no;
    }
    cout<<"请输入您要更改后的件数,0~"<<goods[no-1]->get_remaining()<<endl;
    cin>>amount;
    while(amount>cart[no]||amount<0) {
        cout<<"请输入正确的商品数量,0~"<<goods[no-1]->get_remaining()<<endl;
        cin>>amount;
    }
    cart[no] = amount;
}

void Consumer::select(const vector<Goods *> &goods) {
    int no;
    cout<<"请输入您要选中的商品编号"<<endl;
    cin>>no;
    while(no>goods.size()||no<1) {
        cout<<"请输入正确的商品编号,1~"<<goods.size()<<endl;
        cin>>no;
    }
    selected[no] = cart[no];
    total_price += cart[no]*goods[no-1]->get_price();
}

void Consumer::unselect(const vector<Goods *> &goods) {
    int no;
    cout<<"请输入您要取消选中的商品编号"<<endl;
    cin>>no;
    while(no>goods.size()||no<1) {
        cout<<"请输入正确的商品编号,1~"<<goods.size()<<endl;
        cin>>no;
    }
    selected[no] = 0;
    total_price -= cart[no]*goods[no-1]->get_price();
}

//生成订单
void Consumer::generateOrder(vector<Goods*> &goods) {
    int x;
    cout<<"确认将选中商品下单？ 输入1确认，0返回"<<endl;
    cin>>x;
    while(x!=1&&x!=0) {
        cout<<"请输入正确的数字，输入1确认，0返回"<<endl;
        cin>>x;
    }
    if(x==0) return;
    Order temp(goods,selected);
    orders.push_back(temp);
    //生成订单后购物车选中部分清空
    for(auto &item : selected) {
        cart[item.first] -= item.second;
        item.second = 0;
    }
    total_price = 0;
    cout<<"订单生成成功"<<endl;
//    cout<<"订单生成成功，是否立即支付？ 输入1确认，0返回"<<endl;
//    cin>>x;
//    while(x!=1&&x!=0) {
//        cout<<"请输入正确的数字，输入1确认，0返回"<<endl;
//        cin>>x;
//    }
//    if(x==0) return;
//    orders.pop_back();
//    payOrder(goods);
//    orders.push_back(temp);
}

void Consumer::payOrder(vector<Goods*> &goods) {
    cout<<"您待支付的订单如下："<<endl;
    int flag = 0;
    for(int i = 0; i<orders.size(); i++) {
        cout<<"订单编号："<<i+1<<endl;
        if(orders[i].get_state()==0) {
            orders[i].showOrder(goods);
            flag = 1;
        }
    }
    if(flag==0) {
        cout<<"没有待支付的订单"<<endl;
        return;
    }
    cout<<"请选择您要支付的订单编号："<<endl;
    int no;
    cin>>no;
    while(no<1||no>orders.size()||orders[no-1].get_state()==1) {
        if(no<1||no>orders.size())
            cout<<"请输入正确的订单编号，1～"<<orders.size()<<endl;
        else cout<<"该订单已支付，请重新输入要支付的订单编号"<<endl;
        cin>>no;
    }
    //如果账户余额足够
    while(this->account->get_balance()<orders[no-1].get_price()) {
        cout<<"余额不足，是否立即充值？ 1确认，0返回"<<endl;
        int x;
        cin>>x;
        while(x!=0&&x!=1) {
            cout<<"请输入正确的数字，1确认，0返回"<<endl;
            cin>>x;
        }
        if(x==1) recharge();
    }
    this->account->transOut(orders[no-1].get_price());
    orders[no-1].set_state(1);
    orders[no-1].transfer(goods);
    orders[no-1].release(goods);
    cout<<"订单支付成功"<<endl;
}

//取消订单，释放冷冻量
void Consumer::cancelOrder(vector<Goods*> &goods) {
    cout<<"您待支付的订单如下："<<endl;
    int flag = 0;
    for(int i = 0; i<orders.size(); i++) {
        cout<<"订单编号："<<i+1<<endl;
        if(orders[i].get_state()==0) {
            orders[i].showOrder(goods);
            flag = 1;
        }
    }
    if(flag==0) {
        cout<<"没有待支付的订单"<<endl;
        return;
    }
    cout<<"请选择您要取消的订单编号："<<endl;
    int no;
    cin>>no;
    while(no<1||no>orders.size()||orders[no-1].get_state()==1) {
        if(no<1||no>orders.size())
            cout<<"请输入正确的订单编号，1～"<<orders.size()<<endl;
        else cout<<"该订单已支付，请重新输入要取消的订单编号"<<endl;
        cin>>no;
    }
    orders[no-1].release(goods);
    orders.erase(orders.begin()+no-1);
    cout<<"订单取消成功"<<endl;
}

void Consumer::showOrders(vector<Goods*> &goods) {
    cout<<"所有订单如下："<<endl;
    for(int i = 0; i<orders.size(); i++) {
        cout<<"订单编号："<<i+1<<endl;
        orders[i].showOrder(goods);
    }
}
