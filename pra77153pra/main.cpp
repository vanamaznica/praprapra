#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* str;
    int size;

public:
    String()
    {
        size = 80;
        str = new char[size + 1];
        str[0] = '\0';
    }

    String(int s)
    {
        size = s;
        str = new char[size + 1];
        str[0] = '\0';
    }

    String(const char* text)
    {
        size = strlen(text);
        str = new char[size + 1];
        strcpy(str, text);
    }

    String(const String& other)
    {
        size = other.size;
        str = new char[size + 1];
        strcpy(str, other.str);
    }

    void input()
    {
        char temp[1000];
        cout << "Enter string: ";
        cin.getline(temp, 1000);

        delete[] str;
        size = strlen(temp);
        str = new char[size + 1];
        strcpy(str, temp);
    }

    void show()
    {
        cout << str << endl;
    }

    ~String()
    {
        delete[] str;
    }
};

int main()
{
    String s1;
    String s2(20);
    String s3("Hello world");
    String s4(s3);

    cout << "Default string: ";
    s1.show();
    cout << "String from text: ";
    s3.show();
    cout << "Copied string: ";
    s4.show();
    s2.input();
    cout << "Entered string: ";
    s2.show();
}
