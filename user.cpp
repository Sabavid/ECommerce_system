//
//  user.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include "account.hpp"
#include "user.hpp"
#include "goods.hpp"

User::User():account(){
}

User::User(Account *account):account(account) {
    
}

User::~User() {
    
}

void User::findGood(vector<Goods *> &goods) {
    int x;
    cout << endl<<"      请选择操作序号！(0~6)" << endl;
        cout << "***********************************" << endl;
        cout << "*                                 *" << endl;
        cout << "*              0.退出              *" << endl;
        cout << "*          1.筛选商品名称           *" << endl;
        cout << "*       2.筛选高于给定价格的商品      *" << endl;
        cout << "*       3.筛选低于给定价格的商品      *" << endl;
        cout << "*       4.筛选高于给定余量的商品      *" << endl;
        cout << "*       5.筛选低于给定余量的商品      *" << endl;
        cout << "*           6.筛选商品种类          *" << endl;
        cout << "*                                 *" << endl;
        cout << "***********************************" << endl;
    cin>>x;
    while(x!=0) {
            switch (x) {
            case 1:
                findGoodName(goods);
                break;
            case 2:
                findGoodPriceUp(goods);
                break;
            case 3:
                findGoodPriceDown(goods);
                break;
            case 4:
                findGoodRemainUp(goods);
                break;
            case 5:
                findGoodRemainDown(goods);
                break;
            case 6:
                findGoodType(goods);
                break;
            default:
                cout<<"请输入正确的数字哦～"<<endl;
                break;
        }
        cout << endl<<"      请选择操作序号！(0~6)" << endl;
            cout << "***********************************" << endl;
            cout << "*                                 *" << endl;
            cout << "*              0.退出              *" << endl;
            cout << "*          1.筛选商品名称           *" << endl;
            cout << "*       2.筛选高于给定价格的商品      *" << endl;
            cout << "*       3.筛选低于给定价格的商品      *" << endl;
            cout << "*       4.筛选高于给定余量的商品      *" << endl;
            cout << "*       5.筛选低于给定余量的商品      *" << endl;
            cout << "*           6.筛选商品种类          *" << endl;
            cout << "*                                 *" << endl;
            cout << "***********************************" << endl;
        cin>>x;
    }
}

void User::findGoodName(vector<Goods*> &goods) {
    int flag = 0,x;
    string name;
    while (1) {
        flag = 0;
        cout<<"请输入搜索的商品名称"<<endl;
        cin>>name;
        cout<<endl;
        for(int i = 0;i<goods.size();i++) {
            if(goods[i]->get_name()==name) {
                flag = 1;
                //商品编号从1开始
                cout<<"商品编号："<<i+1<<endl;
                goods[i]->show_good();
                cout<<endl;
            }
        }
        if(flag==0) cout<<"没找到你要的商品"<<endl;
        cout<<"继续筛选商品名称请按1，退出请按0"<<endl;
        cin>>x;
        while(x!=0&&x!=1) {
            cout<<"请输入0或1，继续筛选商品名称请按1，退出请按0"<<endl;
            cin>>x;
        }
        if(x==0) break;
    }
}

//筛选高于某个价格的商品
void User::findGoodPriceUp(vector<Goods*> &goods) {
    int flag = 0,x;
    double price;
    while (1) {
        flag = 0;
        cout<<"请输入筛选的商品价格下限"<<endl;
        cin>>price;
        cout<<endl;
        for(int i = 0;i<goods.size();i++) {
            if(goods[i]->get_price()>=price) {
                flag = 1;
                //商品编号从1开始
                cout<<"商品编号："<<i+1<<endl;
                goods[i]->show_good();
                cout<<endl;
            }
        }
        if(flag==0) cout<<"没找到你要的商品"<<endl;
        cout<<"继续筛选商品价格请按1，退出请按0"<<endl;
        cin>>x;
        while(x!=0&&x!=1) {
            cout<<"请输入0或1，继续筛选商品价格请按1，退出请按0"<<endl;
            cin>>x;
        }
        if(x==0) break;
    }
}

//筛选低于某个价格的商品
void User::findGoodPriceDown(vector<Goods*> &goods) {
    int flag = 0,x;
    double price;
    while(1) {
        flag = 0;
        cout<<"请输入筛选的商品价格上限"<<endl;
        cin>>price;
        cout<<endl;
        for(int i = 0;i<goods.size();i++) {
            if(goods[i]->get_price()<=price) {
                flag = 1;
                //商品编号从1开始
                cout<<"商品编号："<<i+1<<endl;
                goods[i]->show_good();
                cout<<endl;
            }
        }
        if(flag==0) cout<<"没找到你要的商品"<<endl;
        cout<<"继续筛选商品价格请按1，退出请按0"<<endl;
        cin>>x;
        while(x!=0&&x!=1) {
            cout<<"请输入0或1，继续筛选商品价格请按1，退出请按0"<<endl;
            cin>>x;
        }
        if(x==0) break;
    }
}

void User::findGoodType(vector<Goods*> &goods) {
    int flag = 0,x;
    string type;
    while(1) {
        flag = 0;
        cout<<"请输入筛选的商品种类"<<endl;
        cin>>type;
        cout<<endl;
        for(int i = 0;i<goods.size();i++) {
            if(goods[i]->get_type()==type) {
                flag = 1;
                //商品编号从1开始
                cout<<"商品编号："<<i+1<<endl;
                goods[i]->show_good();
                cout<<endl;
            }
        }
        if(flag==0) cout<<"没找到你要的商品"<<endl;
        cout<<"继续筛选商品种类请按1，退出请按0"<<endl;
        cin>>x;
        while(x!=0&&x!=1) {
            cout<<"请输入0或1，继续筛选商品种类请按1，退出请按0"<<endl;
            cin>>x;
        }
        if(x==0) break;
    }
}

void User::findGoodRemainUp(vector<Goods*> &goods) {
    int flag = 0,x;
    int remain;
    while(true) {
        flag = 0;
        cout<<"请输入筛选的商品余量下限"<<endl;
        cin>>remain;
        cout<<endl;
        for(int i = 0;i<goods.size();i++) {
            if(goods[i]->get_remaining()>=remain) {
                flag = 1;
                //商品编号从1开始
                cout<<"商品编号："<<i+1<<endl;
                goods[i]->show_good();
                cout<<endl;
            }
        }
        if(flag==0) cout<<"没找到你要的商品"<<endl;
        cout<<"继续筛选商品余量请按1，退出请按0"<<endl;
        cin>>x;
        while(x!=0&&x!=1) {
            cout<<"请输入0或1，继续筛选商品余量请按1，退出请按0"<<endl;
            cin>>x;
        }
        if(x==0) break;
    }
}

void User::findGoodRemainDown(vector<Goods*> &goods) {
    int flag = 0,x;
    int remain;
    while(true) {
        flag = 0;
        cout<<"请输入筛选的商品余量上限"<<endl;
        cin>>remain;
        cout<<endl;
        for(int i = 0;i<goods.size();i++) {
            if(goods[i]->get_remaining()<=remain) {
                flag = 1;
                //商品编号从1开始
                cout<<"商品编号："<<i+1<<endl;
                goods[i]->show_good();
                cout<<endl;
            }
        }
        if(flag==0) cout<<"没找到你要的商品"<<endl;
        cout<<"继续筛选商品余量请按1，退出请按0"<<endl;
        cin>>x;
        while(x!=0&&x!=1) {
            cout<<"请输入0或1，继续筛选商品余量请按1，退出请按0"<<endl;
            cin>>x;
        }
        if(x==0) break;
    }
}

void User::changePassword() {
    string psw,check;
    do {
        cout<<"请输入新的密码"<<endl;
        cin>>psw;
        cout<<"请确认密码"<<endl;
        cin>>check;
        if(check!=psw) cout<<"两次输入密码不同"<<endl;
    } while(check!=psw);
    account->set_password(psw);
    cout<<"密码修改成功"<<endl;
}

void User::getBalance() {
    cout<<"您账户余额还有："<<account->get_balance()<<"元"<<endl;
}

void User::recharge() {
    double money;
    cout<<"请输入您充值的数额："<<endl;
    cin>>money;
    account->recharge(money);
}

void User::purchase(vector<Goods*> &goods) {
    if(goods.size()==0) return;
    cout<<"请输入你想购买的商品编号："<<endl;
    int n;
    cin>>n;
    if(goods[n-1]->get_remaining()==0) {
        cout<<"商品库存不足"<<endl;
        return;
    }
    if(goods[n-1]->get_price()>account->get_balance()) {
        cout<<"您账户中没有足够的余额，商品需要"<<goods[n-1]->get_price()<<"元，您只有"<<account->get_balance()<<"元"<<endl;
        return;
    }
    account->consume(goods[n-1]->get_price());
    goods[n-1]->set_remaining(goods[n-1]->get_remaining()-1);
    cout<<"您买下了"<<n<<"号商品："<<goods[n-1]->get_name()<<endl;
    cout<<"谢谢惠顾"<<endl;
}
