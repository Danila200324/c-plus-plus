#include "Header.h"
#pragma warning(disable : 4996);//нужно для правильной записи попытки входа
void desh(string& s, int mode)
{
    if (mode)
    {
        for (int i = 0; i < s.length(); i++)
            s[i] -= 4;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
            s[i] += 4;
    }
}
void view(vector<string>code)
{
    for (int i = 0; i < code.size(); i++)
        cout << i + 1 << "." << code[i] << endl;
}
void passview(vector<password>data)
{
    border1();
    for (int i = 0; i < data.size(); i++)
        border2(data[i], i);
}
void border1()
{
    cout << "+--------------------------------------";
    cout << "--------------------------------------+" << endl;
    cout << "| № | Category : | Login:     | ";
    cout << "Password:    | Destination: | URL:           |" << endl;
    cout << "+--------------------------------------";
    cout << "--------------------------------------+" << endl;
}
void border2(password ex, int i)
{
    cout << "| " << i + 1 << " | " << setw(10) << output << ex.category << " | " << setw(10) << output << ex.login << " | ";
    cout << setw(12) << output << ex.code << " | " << setw(12) << output << ex.name << " | " << setw(14) << output << ex.url << " |" << endl;
    cout << "+-------------------------------------";
    cout << "---------------------------------------+" << endl;
}
void categorysort(vector<password>& ex)
{
    for (int i = 0; i < ex.size(); i++)
    {
        for (int j = i + 1; j < ex.size(); j++)
        {
            if (ex[i].category > ex[j].category)
                swap(ex[i], ex[j]);
        }
    }
    border1();
    for (int i = 0; i < ex.size(); i++)
        border2(ex[i], i);
}
void passsort(vector<password>& ex)
{
    for (int i = 0; i < ex.size(); i++)
    {
        for (int j = i + 1; j < ex.size(); j++)
        {
            if (ex[i].code.compare(ex[j].code) > 0)
            {
                swap(ex[i], ex[j]);
            }
        }
    }
    border1();
    for (int i = 0; i < ex.size(); i++)
        border2(ex[i], i);
}
void namesort(vector<password>& ex)
{
    for (int i = 0; i < ex.size(); i++)
    {
        for (int j = i + 1; j < ex.size(); j++)
        {
            if (ex[i].name.compare(ex[j].name) > 0)
            {
                swap(ex[i], ex[j]);
            }
        }
    }
    border1();
    for (int i = 0; i < ex.size(); i++)
        border2(ex[i], i);
}
ostream& output(ostream& stream)
{
    stream << setiosflags(ios_base::left);
    return stream;
}
void mainpassoutput(vector<string>& code)
{
    ifstream mainout;
    mainout.open("main.txt", ios_base::in);
    while (!mainout.eof())
    {
        code.emplace_back();
        mainout >> code[code.size() - 1];
    }
    mainout.close();
}
void mainpassinput(vector<string>& code)
{
    ofstream mainin;
    mainin.open("main.txt", ios_base::out | ios_base::trunc);
    for (int i = 0; i < code.size(); i++)
    {
        mainin << code[i];
        if (i != code.size() - 1)
            mainin << endl;
    }
    mainin.close();
}
void enteroutput(vector<time_t>& access)
{
    ifstream enterout;
    enterout.open("enter.txt", ios_base::in);
    while (!enterout.eof())
    {
        access.emplace_back();
        enterout >> access[access.size() - 1];
    }
    enterout.close();
}
void enterinput(vector<time_t>& access)
{
    ofstream enterin;
    enterin.open("enter.txt", ios_base::out | ios_base::trunc);
    for (int i = 0; i < access.size(); i++)
    {
        enterin << access[i];
        if (i != access.size() - 1)
            enterin << endl;
    }
    enterin.close();
}
void addpassword(vector<password>& ex)
{
    int i;
    ex.emplace_back();
    cout << "Write category:" << endl;
    while (!(cin >> ex[ex.size() - 1].category) || (cin.peek() != '\n') || ex[ex.size() - 1].category <= 0)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    cin.get();
    cout << "Write login:" << endl;
    getline(cin, ex[ex.size() - 1].login);
    cout << "Write by hand or random password?(1/0)" << endl;
    while (!(cin >> i) || (cin.peek() != '\n') || i < 0 || i>1)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    cin.get();
    if (i)
        getline(cin, ex[ex.size() - 1].code);
    else
    {
        for (i = 0; i < 8; i++)
            ex[ex.size() - 1].code += char('a' + rand() % 25);
        cout << "Password generated!" << endl;
    }
    cout << "Write destiny(ex.:instagram):" << endl;
    getline(cin, ex[ex.size() - 1].name);
    cout << "Write URL:(ex.:instagram.com)" << endl;
    getline(cin, ex[ex.size() - 1].url);
}
void mainpass(vector<string>& code)
{
    string ex;
    int i, k;
    cout << "1.Overview main passwords." << endl;
    cout << "2.Edit main passwords." << endl;
    cout << "3.Add main password." << endl;
    cout << "4.Delete main password." << endl;
    while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 4)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    if (i == 1)
    {
        view(code);
    }
    else if (i == 2)
    {
        view(code);
        cout << "Choose number:" << endl;
        while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > code.size())
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
        }
        cout << "Are u sure u want to edit?(1/0)" << endl;
        while (!(cin >> k) || (cin.peek() != '\n') || k <= 0 || k > 1)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
        }
        if (k)
        {
            cin.get();
            cout << "Write new password:" << endl;
            getline(cin, code[i - 1]);
        }
    }
    else if (i == 3)
    {
        cin.get();
        cout << "Write new password:" << endl;
        getline(cin, ex);
        code.push_back(ex);
    }
    else
    {
        view(code);
        cout << "Choose number:" << endl;
        while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > code.size())
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
        }
        cout << "Are you sure that you want to delete?(1/0)" << endl;
        while (!(cin >> k) || (cin.peek() != '\n') || k < 0 || k > 1)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
        }
        if (k)
            code.erase(code.begin() + i - 1);
    }
}
void enterview(vector<time_t>& access)
{
    for (int i = 0; i < access.size(); i++)
    {
        char* dt = ctime(&access[i]);
        cout << "Enter attempt:" << dt;
    }
}
bool getdata(string path, bool mode, vector<password>& data)
{
    ifstream passwordsout;
    passwordsout.open(path, ios_base::in);
    if (passwordsout.is_open())
    {
        while (!passwordsout.eof())
        {
            data.emplace_back();
            passwordsout >> data[data.size() - 1].category;
            passwordsout >> data[data.size() - 1].login;
            passwordsout >> data[data.size() - 1].code;
            passwordsout >> data[data.size() - 1].name;
            passwordsout >> data[data.size() - 1].url;
        }
        //если пароль неверный,то шифрование
        if (!mode)
        {
            for (int i = 0; i < data.size(); i++)
            {
                data[i].category -= 4;
                desh(data[i].login, 1);
                desh(data[i].code, 1);
                desh(data[i].name, 1);
                desh(data[i].url, 1);
            }
        }
    }
    return passwordsout.is_open();
    passwordsout.close();
}
void putdata(string path, bool mode, vector<password>& data)
{
    int i;
    ofstream passwordsin;
    passwordsin.open(path, ios_base::trunc | ios_base::out);
    if (!mode)
    {
        for (i = 0; i < data.size(); i++)
        {
            data[i].category += 4;
            desh(data[i].login, 0);
            desh(data[i].code, 0);
            desh(data[i].name, 0);
            desh(data[i].url, 0);
        }
    }
    for (i = 0; i < data.size(); i++)
    {
        passwordsin << data[i].category << " ";
        passwordsin << data[i].login << " ";
        passwordsin << data[i].code << " ";
        passwordsin << data[i].name << " ";
        passwordsin << data[i].url;
        if (i != data.size() - 1)
            passwordsin << endl;
    }
    data.clear();
    passwordsin.close();
}
void categoryfind(vector<password>& data)
{
    int k, count = 0, i;
    cout << "Write category to find:" << endl;
    cin >> k;
    for (i = 0; i < data.size(); i++)
    {
        if (k == data[i].category)
        {
            if (!count)
                border1();
            border2(data[i], count);
            count++;
        }
    }
    if (!count)
        cout << "Nothing." << endl;
}
void loginfind(vector<password>& data)
{
    int i, count = 0;
    string find;
    cout << "Write part of login to find:" << endl;
    getline(cin, find);
    for (i = 0; i < data.size(); i++)
    {
        if (data[i].login.find(find) != -1)
        {
            if (!count)
                border1();
            border2(data[i], count);
            count++;
        }
    }
    if (count == 0)
        cout << "Nothing." << endl;
}
void codefind(vector<password>& data)
{
    int i, count = 0;
    string find;
    cout << "Write part of password to find:" << endl;
    getline(cin, find);
    for (i = 0; i < data.size(); i++)
    {
        if (data[i].code.find(find) != -1)
        {
            if (!count)
                border1();
            border2(data[i], count);
            count++;
        }
    }
    if (count == 0)
        cout << "Nothing." << endl;
}
void namefind(vector<password>& data)
{
    int i, count = 0;
    string find;
    cout << "Write part of destiny to find:" << endl;
    getline(cin, find);
    for (i = 0; i < data.size(); i++)
    {
        if (data[i].name.find(find) != -1)
        {
            if (!count)
                border1();
            border2(data[i], count);
            count++;
        }
    }
    if (count == 0)
        cout << "Nothing." << endl;
}
void urlfind(vector<password>& data)
{
    int i, count = 0;
    string find;
    cout << "Write part of URL to find:" << endl;
    getline(cin, find);
    for (i = 0; i < data.size(); i++)
    {
        if (data[i].url.find(find) != -1)
        {
            if (!count)
                border1();
            border2(data[i], count);
            count++;
        }
    }
    if (count == 0)
        cout << "Nothing." << endl;
}
void fullfind(vector<password>& data)
{
    int count = 0, i;
    cout << "1.Find by category number." << endl;
    cout << "2.Find by login." << endl;
    cout << "3.Find by password." << endl;
    cout << "4.Find by destiny." << endl;
    cout << "5.Find by URL." << endl;
    while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 5)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    cin.get();
    if (i == 1)
        categoryfind(data);
    else if (i == 2)
        loginfind(data);
    else if (i == 3)
        codefind(data);
    else if (i == 4)
        namefind(data);
    else
        urlfind(data);
}
void fullsort(vector<password>& data)
{
    int i;
    cout << "1.Sort by category." << endl;
    cout << "2.Sort by destiny." << endl;
    cout << "3.Sort by name(alphabet)." << endl;
    while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 3)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Ошибка ввода.Повторите ввод." << "\x1b[0m" << endl;
    }
    if (i == 1)
        categorysort(data);
    else if (i == 2)
        namesort(data);
    else
        passsort(data);
}
void fulledit(vector<password>& data)
{
    passview(data);
    int i, k;
    cout << "Choose number:" << endl;
    while (!(cin >> k) || (cin.peek() != '\n') || k <= 0 || k > data.size())
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    cout << "Are u sure u want to edit?(1/0)" << endl;
    while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 1)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    cout << "1.Edit category." << endl;
    cout << "2.Edit login." << endl;
    cout << "3.Edit password." << endl;
    cout << "4.Edit destiny." << endl;
    cout << "5.Edit URL." << endl;
    while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 5)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    cin.get();
    if (i == 1)
    {
        cout << "Write new category:" << endl;
        while (!(cin >> data[k - 1].category) || (cin.peek() != '\n') || i <= 0)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
        }
    }
    else if (i == 2)
    {
        cout << "Write new login:" << endl;
        getline(cin, data[k - 1].login);
    }
    else if (i == 3)
    {
        cout << "Write new password:" << endl;
        getline(cin, data[k - 1].code);
    }
    else if (i == 4)
    {
        cout << "Write new destiny(ex.:instagram):" << endl;
        getline(cin, data[k - 1].name);
    }
    else
    {
        cout << "Write new URL:(ex.:instagram.com)" << endl;
        getline(cin, data[k - 1].url);
    }
}
void deletepass(vector<password>& data)
{
    int k, i;
    passview(data);
    cout << "Choose number:" << endl;
    while (!(cin >> k) || (cin.peek() != '\n') || k <= 0 || k > data.size())
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    cout << "Are u sure u want to delete?(1/0)" << endl;
    while (!(cin >> i) || (cin.peek() != '\n') || i < 0 || i > 1)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    if (i)
        data.erase(data.begin() + k - 1);
}
void deletecategory(vector<password>& data)
{
    int k, i, count = 0;
    passview(data);
    cout << "Write category of passwords to delete:" << endl;
    while (!(cin >> k) || (cin.peek() != '\n') || k <= 0)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
    }
    for (i = 0; i < data.size(); i++)
    {
        if (data[i].category == k)
            count++;
    }
    if (count != 0)
    {
        cout << "Are u sure u want to delete?(1/0)" << endl;
        while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 1)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
        }
        if (i)
        {
            for (i = 0; i < data.size();)
            {
                if (data[i].category == k)
                {
                    data.erase(data.begin() + i);
                    i = 0;
                }
                else
                    i++;
            }
        }
    }
    else
        cout << "Nothing." << endl;
}
void mainwork(vector<password>& data, bool mode)
{
    string path;
    int i;
    cin.get();
    cout << "Write file name(without .txt):" << endl;
    getline(cin, path);//ввод названия файла,
    path += ".txt";	   //содержащего данные паролей
    if (getdata(path, mode, data))//если файл существует
    {
        while (1)
        {
            cout << "1.Data overview." << endl;
            cout << "2.Find data." << endl;
            cout << "3.Sort data." << endl;
            cout << "4.Add data." << endl;
            cout << "5.Edit data." << endl;
            cout << "6.Remove data." << endl;
            cout << "7.Add new category." << endl;
            cout << "8.Delete category of passwords." << endl;
            cout << "9.Back." << endl;
            while (!(cin >> i) || (cin.peek() != '\n') || i <= 0 || i > 9)
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "\x1b[31;1m" << "Error.Please try again:" << "\x1b[0m" << endl;
            }
            if (i == 1)
                passview(data);//просмотр паролей
            else if (i == 2)
                fullfind(data);//поиск паролей
            else if (i == 3)
                fullsort(data);//сортировка паролей
            else if (i == 4)
                addpassword(data);//добавление пароля
            else if (i == 5)
                fulledit(data);//редактирование пароля
            else if (i == 6)
                deletepass(data);//удаление пароля
            else if (i == 7)//создание новой категории
            {
                cout << "Write data for new category:" << endl;
                addpassword(data);
            }
            else if (i == 8)//удаление паролей с 1 категории
                deletecategory(data);
            else
                break;
        }
        putdata(path, mode, data);//запись изменённой информации в файл
    }
    else
        cout << "File with that name not exist." << endl;
}

