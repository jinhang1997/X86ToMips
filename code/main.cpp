//
// Created by cyw35 on 2018/12/18.
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

#include "util/fileUtil.h"
#include "util/stringUtil.h"

using namespace std;

#define N1 8
#define N2 9
#define N3 3

string x86Resgiter[N1] = {"eax", "ebx", "ecx", "edx", "esi", "edi", "esp", "ebp"};
string mipsResgiter[N1] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"};
map<string, string> strMap;    //寄存器之间的映射表

string binaryOp[N2] = {"mov", "add", "sub", "and", "or", "xor", "nor", "shl", "shr"};
//string mipsBinaryOp[] = {"addi", "subi", "andi", "ori", "xori","nor" "shl", "shr", "move"};
string unaryOp[N3] = {"neg", "dec", "inc"};

vector<string> readTxt(string file);
void writeTxt(char *file, string content);
bool isNum(string str);
vector<string> split(const string &str, const string &delim);


void init() {
    //建立对应关系
    for (int i = 0; i < N1; i++) {
        strMap[x86Resgiter[i]] = mipsResgiter[i];
    }
}

string Transfer(string lineStr) {
    string paramStr = split(lineStr, " ")[0];   //取出操作符
    for (int i = 0; i < N2; i++) {
        if (paramStr == binaryOp[i]) {
            int pos = lineStr.find(paramStr);
            string temp = lineStr.substr(pos + paramStr.length() + 1);
            vector<string> params = split(temp, ",");
            params[0] = "$" + strMap[params[0]];
            params[1] = isNum(params[1]) ? params[1] : "$" + strMap[params[1]];
            return paramStr + " " + params[0] + "," + params[1] + "\n";
        } else if (i < N3 && paramStr == unaryOp[i]) {
            int pos = lineStr.find(paramStr);
            string temp = lineStr.substr(pos + paramStr.length() + 1);
            temp = isNum(temp) ? temp : "$" + strMap[temp];
            return paramStr + " " + temp + "\n";
        }
    }
    return lineStr + "\n";  //不在当前匹配的运算符中
}


int main() {
    vector<string> readStr = readTxt("../data/X86Str.txt");
    string writeRes = "";
    int len = readStr.size();
    init();
    for (int i = 0; i < len; i++) {
        string lineStr = readStr[i];
        writeRes += Transfer(lineStr);
    }
    cout << writeRes << endl;
    writeTxt("../data/MipsStr.txt", writeRes);
    return 0;
}
