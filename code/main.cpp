//
// Created by cyw35 on 2018/12/18.
//

#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

#define N 4

string x86Resgiter[N] = { "eax","ebx","ecx","edx" };
string mipsResgiter[N] = { "t1","t2","t3","t4" };

map<string, string> strMap;	//寄存器之间的映射表

vector<string> readTxt(string file){	//读文件

	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
	vector<string> res;
	string s;
	while (getline(infile, s)) {
		int len = s.size();
		//处理句尾的‘；’
		s = s.at(len - 1) == ';' ? s.substr(0, len - 1) : s;
		res.insert(res.end(), s);
	}
	infile.close();              //关闭文件输入流
	return res;
}

void init() {
	//待补充
	for (int i = 0; i < N; i++) {
		strMap[x86Resgiter[i]] = mipsResgiter[i];
	}

}

vector<string> split(const string& str, const string& delim) {	//字符串分割函数
	vector<string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());
    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    char *p = strtok(strs, d);
    while(p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
    return res;
}

void writeTxt(char *file,string content){	//写文件
	ofstream outfile(file);
	outfile << content;
	outfile.close();
}

int main() {
	vector<string> readStr = readTxt("../data/X86Str.txt");
	string writeRes = "";
	init();
	int len = readStr.size();
	int pos;
	for (int i = 0; i < len; i++) {
		string str = readStr[i];
		string lineStr = "";

		//操作码为 add

		pos = readStr[i].find("add");
		if (pos != -1) {
			string temp = readStr[i].substr(pos+4);
			cout << temp << endl;
			vector<string> params = split(temp, ",");
			if (params.size() == 2) {	//跟两个寄存器的情况，且未考虑立即数
				lineStr += "lw $" +strMap[params[0]]+"\n";
				lineStr += "lw $" + strMap[params[1]] + "\n";
				lineStr += "addu $" + strMap[params[0]] + ",$"+ strMap[params[0]] + ",$" + strMap[params[1]];
			}
			//待拓展
		}
		writeRes += lineStr + "\n";
	}
	cout << writeRes << endl;
	writeTxt("../data/MipsStr.txt",writeRes);
	return 0;

}
