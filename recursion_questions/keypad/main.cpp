#include<bits/stdc++.h>
using namespace std;

string keyboard[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s , string ans)
{
    if (s.length() == 0)
    {
        cout << ans << "\n";
        return;
    }
    char ch = s[0];
    string code = keyboard[ch-'0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans+code[i]);
    }
    

}

int main()
{
    keypad("23", "");
    cout << "\n";
}