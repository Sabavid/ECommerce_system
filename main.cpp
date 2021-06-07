//
//  main.cpp
//  账户和商品管理子系统
//
//  Created by Ice Bear on 2021/4/2.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include "account.hpp"
#include "account_system.hpp"
#include "user.hpp"
#include "merchant.hpp"
#include "consumer.hpp"
#include "goods.hpp"
#include "book.hpp"
#include "food.hpp"
#include "clothing.hpp"

int main(int argc, const char * argv[]) {
    AccountSystem account_system;
    account_system.mainMenu();
    return 0;
}
