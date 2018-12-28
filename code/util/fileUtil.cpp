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
#include "fileUtil.h"

using namespace std;

vector<string> readTxt(string file) {    //读文件
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
    vector<string> res;
    string s;
    while (getline(infile, s)) {
        int len = s.size();
        s = s.at(len - 1) == ';' ? s.substr(0, len - 1) : s;    //处理句尾的‘；’
        res.insert(res.end(), s);
    }
    infile.close();              //关闭文件输入流
    return res;
}

void writeTxt(char *file, string content) {    //写文件
    ofstream outfile(file);
    outfile << content;
    outfile.close();
}

