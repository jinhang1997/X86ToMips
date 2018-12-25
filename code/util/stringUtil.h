//
// Created by cyw35 on 2018/12/25.
//

#ifndef X86TOMIPS_STRINGUTIL_H
#define X86TOMIPS_STRINGUTIL_H

#include<iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

//字符串处理类
class stringUtil {
    bool isNum(string str);

    vector<string> split(const string &str, const string &delim);
};


#endif //X86TOMIPS_STRINGUTIL_H
