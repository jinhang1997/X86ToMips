//
// Created by cyw35 on 2018/12/25.
//

#include<iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include "stringUtil.h"

using namespace std;


bool isNum(string str) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if ((isdigit(str[i])) || isspace(str[i])) {
            continue;
        }
        return false;
    }
    return true;
}

vector<string> split(const string &str, const string &delim) {    //字符串分割函数
    vector<string> res;
    if ("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());
    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    char *p = strtok(strs, d);
    while (p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
    return res;
}