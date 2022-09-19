/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

/*
void removeSpecialCharacter(string s)
{
    for (int i = 0; i < s.size(); i++) {
         
        // Finding the character whose
        // ASCII value fall under this
        // range
        if (s[i] < 'A' || s[i] > 'Z' &&
            s[i] < 'a' || s[i] > 'z')
        {  
            // erase function to erase
            // the character
            s.erase(i, 1);
            i--;
        }
    }
    cout << s;
}
*/
bool validate_string(string s)
{
    if(s.empty())
    {
        return true;
    }    
    else
    {
        // removing non alphanumeric characters
        
        auto it = std::remove_if(s.begin(), s.end(), [](char const &c) {
        return !std::isalnum(c);
        });
        s.erase(it, s.end());

        
        // this inbuilt function transform entire string
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        /*
            another way of doing it
            for (int x=0; x<strlen(str); x++)
                putchar(toupper(arr[x]));
        */

        
        int i =0 , j = s.size()-1;
        
        for (i, j; i < j; i++, j--)
        {
            if (s[i] == s[j])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
    string str = "A man, a plan, a canal: Panama";
    cout << str << "\n";
    //transform(str.begin(), str.end(), str.begin(), ::tolower);
    //str.erase(remove_if(str.begin(), str.end(), (int(*)(int))!isalnum), str.end());
    auto result = validate_string(str);
    cout << result << "\n";
}