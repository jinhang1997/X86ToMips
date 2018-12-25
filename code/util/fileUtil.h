//
// Created by cyw35 on 2018/12/25.
//

#ifndef X86TOMIPS_FILEUTILL_H
#define X86TOMIPS_FILEUTILL_H

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

//文件处理类
class fileUtil {
    vector<string> readTxt(string file);

    void writeTxt(char *file, string content);
};


#endif //X86TOMIPS_FILEUTILL_H
