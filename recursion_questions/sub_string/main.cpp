#include<bits/stdc++.h>
using namespace std;

void sub_string(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << "\n";
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    sub_string(ros, ans);
    sub_string(ros, ans+ch);
    sub_string(ros, ans+to_string(code));
}

int main()
{
    sub_string("ABC", "");
    cout << "\n";
}