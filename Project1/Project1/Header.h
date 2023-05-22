#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <ctime> 
using namespace std;
struct password
{
    int category;
    string login;
    string code;
    string name;
    string url;
};
void desh(string& s, int mode);
void view(vector<string>code);
void passview(vector<password>data);
void border1();
void border2(password ex, int i);
void addpassword(vector<password>& ex);
void categorysort(vector<password>& ex);
void passsort(vector<password>& ex);
void namesort(vector<password>& ex);
void fullsort(vector<password>& data);
ostream& output(ostream& stream);
void mainpassoutput(vector<string>& code);
void mainpassinput(vector<string>& code);
void enteroutput(vector<time_t>& access);
void enterinput(vector<time_t>& access);
void mainpass(vector<string>& code);
void enterview(vector<time_t>& access);
bool getdata(string path, bool mode, vector<password>& data);
void putdata(string path, bool mode, vector<password>& data);
void categoryfind(vector<password>& data);
void loginfind(vector<password>& data);
void codefind(vector<password>& data);
void namefind(vector<password>& data);
void urlfind(vector<password>& data);
void fullfind(vector<password>& data);
void fulledit(vector<password>& data);
void deletepass(vector<password>& data);
void deletecategory(vector<password>& data);
void mainwork(vector<password>& data, bool mode);