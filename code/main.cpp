<<<<<<< HEAD
//
// Created by cyw35 on 2018/12/18.
//

=======
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
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

<<<<<<< HEAD
map<string, string> strMap;	//å¯„å­˜å™¨ä¹‹é—´çš„æ˜ å°„è¡¨

vector<string> readTxt(string file){	//è¯»æ–‡ä»¶

	ifstream infile;
	infile.open(file.data());   //å°†æ–‡ä»¶æµå¯¹è±¡ä¸æ–‡ä»¶è¿æ¥èµ·æ¥
	assert(infile.is_open());   //è‹¥å¤±è´¥,åˆ™è¾“å‡ºé”™è¯¯æ¶ˆæ¯,å¹¶ç»ˆæ­¢ç¨‹åºè¿è¡Œ
=======
map<string, string> strMap;	//¼Ä´æÆ÷Ö®¼äµÄÓ³Éä±í 

vector<string> readTxt(string file){
	ifstream infile;
	infile.open(file.data());   //½«ÎÄ¼şÁ÷¶ÔÏóÓëÎÄ¼şÁ¬½ÓÆğÀ´ 
	assert(infile.is_open());   //ÈôÊ§°Ü,ÔòÊä³ö´íÎóÏûÏ¢,²¢ÖÕÖ¹³ÌĞòÔËĞĞ 
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
	vector<string> res;
	string s;
	while (getline(infile, s)) {
		int len = s.size();
<<<<<<< HEAD
		//å¤„ç†å¥å°¾çš„â€˜ï¼›â€™
		s = s.at(len - 1) == ';' ? s.substr(0, len - 1) : s;
		res.insert(res.end(), s);
	}
	infile.close();              //å…³é—­æ–‡ä»¶è¾“å…¥æµ
=======
		//´¦Àí¾äÎ²µÄ¡®£»¡¯
		s = s.at(len - 1) == ';' ? s.substr(0, len - 1) : s;
		res.insert(res.end(), s);
	}
	infile.close();             //¹Ø±ÕÎÄ¼şÊäÈëÁ÷ 
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
	return res;
}

void init() {
<<<<<<< HEAD
	//å¾…è¡¥å……
	for (int i = 0; i < N; i++) {
		strMap[x86Resgiter[i]] = mipsResgiter[i];
	}

}

vector<string> split(const string& str, const string& delim) {	//å­—ç¬¦ä¸²åˆ†å‰²å‡½æ•°
	vector<string> res;
	if ("" == str) return res;
	//å…ˆå°†è¦åˆ‡å‰²çš„å­—ç¬¦ä¸²ä»stringç±»å‹è½¬æ¢ä¸ºchar*ç±»å‹
	char * strs = new char[str.length() + 1];
=======
	//´ı²¹³ä 
	for (int i = 0; i < N; i++) {
		strMap[x86Resgiter[i]] = mipsResgiter[i];
	}
}

vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if ("" == str) return res;
	//ÏÈ½«ÒªÇĞ¸îµÄ×Ö·û´®´ÓstringÀàĞÍ×ª»»Îªchar*ÀàĞÍ
	char * strs = new char[str.length() + 1]; //²»ÒªÍüÁË
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
	strcpy(strs, str.c_str());
	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());
	char *p = strtok(strs, d);
	while (p) {
<<<<<<< HEAD
		string s = p; //åˆ†å‰²å¾—åˆ°çš„å­—ç¬¦ä¸²è½¬æ¢ä¸ºstringç±»å‹
		res.push_back(s); //å­˜å…¥ç»“æœæ•°ç»„
=======
		string s = p; //·Ö¸îµÃµ½µÄ×Ö·û´®×ª»»ÎªstringÀàĞÍ
		res.push_back(s); //´æÈë½á¹ûÊı×é
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
		p = strtok(NULL, d);
	}
	return res;
}

<<<<<<< HEAD
void writeTxt(char *file,string content){	//å†™æ–‡ä»¶
	ofstream outfile(file);
	outfile << content;
	outfile.close();
}

int main() {
	vector<string> readStr = readTxt("../data/X86Str.txt");
=======
void writeTxt(char *file,string content){
	ofstream outfile(file); 
	outfile << content;
	outfile.close();
} 

int main() {
	vector<string> readStr = readTxt("../data/X86Str.txt");	
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
	string writeRes = "";
	init();
	int len = readStr.size();
	int pos;
	for (int i = 0; i < len; i++) {
		string str = readStr[i];
		string lineStr = "";
<<<<<<< HEAD

		//æ“ä½œç ä¸º add
=======
		
		//²Ù×÷ÂëÎª add 
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
		pos = readStr[i].find("add");
		if (pos != -1) {
			string temp = readStr[i].substr(pos+4);
			//cout << temp << endl;
			vector<string> params = split(temp, ",");
<<<<<<< HEAD
			if (params.size() == 2) {	//è·Ÿä¸¤ä¸ªå¯„å­˜å™¨çš„æƒ…å†µï¼Œä¸”æœªè€ƒè™‘ç«‹å³æ•°
				lineStr += "lw $" +strMap[params[0]]+"\n";
				lineStr += "lw $" + strMap[params[1]] + "\n";
				lineStr += "addu $" + strMap[params[0]] + ",$"+ strMap[params[0]] + ",$" + strMap[params[1]];
			}
			//å¾…æ‹“å±•
=======
			if (params.size() == 2) {	//¸úÁ½¸ö¼Ä´æÆ÷µÄÇé¿ö£¬ÇÒÎ´¿¼ÂÇÁ¢¼´Êı
				lineStr += "lw $" +strMap[params[0]]+"\n";
				lineStr += "lw $" + strMap[params[1]] + "\n";
				lineStr += "addu $" + strMap[params[0]] + ",$"+ strMap[params[0]] + ",$" + strMap[params[1]];
			}	
			//´ıÍØÕ¹ 
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
		}
		writeRes += lineStr + "\n";
	}
	cout << writeRes << endl;
	writeTxt("../data/MipsStr.txt",writeRes);
	return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 3ef6f7fa663d6286faece44255056ad496c92e28
