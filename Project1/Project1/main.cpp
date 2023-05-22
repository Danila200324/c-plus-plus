#include "Header.h"
int main()
{
    vector<password>data;
    vector<time_t>access;
    vector<string>code;
    string pass, ex;
    bool mode = false;
    int i = 0, k, count = 0;
    mainpassoutput(code);
    enteroutput(access);
    cout << "Write main password:" << endl;
    getline(cin, pass);
    time_t now = time(0);
    access.push_back(now);
    enterinput(access);
    desh(pass, 0);
    for (i = 0; i < code.size(); i++)
    {
        if (code[i] == pass)
        {					
            mode = true;	
            break;			
        }
    }
    if (mode)
        cout << "Password correct." << endl;
    else
        cout << "Password incorrect." << endl;
    while (1)
    {
        cout << "1.Main Passwords." << endl;
        cout << "2.Entering time." << endl;
        cout << "3.Regular passwords data." << endl;
        cout << "4.End running." << endl;

        while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 4)
        {															  
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
        }
        if (i == 1)
            mainpass(code);
        else if (i == 2)
            enterview(access);
        else if (i == 3)
            mainwork(data, mode);
        else
            break;
    }
    mainpassinput(code);
}

