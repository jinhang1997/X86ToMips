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

using namespace std;

#define N1 8
#define N2 9
#define N3 3

string x86Resgiter[N1] = {"eax", "ebx", "ecx", "edx", "esi", "edi", "esp", "ebp"};
string mipsResgiter[N1] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7"};
map<string, string> strMap;    //寄存器之间的映射表

string binaryOp[N2] = {"mov", "add", "sub", "and", "or", "xor", "nor","shl", "shr"};
//string mipsBinaryOp[] = {"addi", "subi", "andi", "ori", "xori","nor" "shl", "shr", "move"};
string unaryOp[N3] = {"neg", "dec", "inc"};



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

void init() {
    //待补充
    for (int i = 0; i < N1; i++) {
        strMap[x86Resgiter[i]] = mipsResgiter[i];
    }
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

void writeTxt(char *file, string content) {    //写文件
    ofstream outfile(file);
    outfile << content;
    outfile.close();
}

bool isNum(string str) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if((isdigit(str[i]))|| isspace(str[i])){
            continue;
        }
        return false;
    }
    return true;
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
        } else if (i < N3 && paramStr == unaryOp[i] ) {
            int pos = lineStr.find(paramStr);
            string temp = lineStr.substr(pos + paramStr.length() + 1);
            temp = isNum(temp) ? temp : "$" + strMap[temp];
            return paramStr + " " + temp+ "\n";
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
