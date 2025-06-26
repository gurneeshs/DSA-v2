#include <bits/stdc++.h>
using namespace std;

bool check(string s, int i)
{
    int n = s.size();
    cout<<n<<endl;
    if (i >= n/2)
    {
        return true;
    }
    if (s[i] != s[n - i - 1])
    {
        return false;
    }
    return check(s, i + 1);
}
bool isPalindrome(string s)
{
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        if (isalpha(s[i]))
        {
            str += tolower(s[i]);
            continue;
        }
    }
    return check(str, 0);
}

int main(){
    cout<<isPalindrome("Race a car")<<endl;
    return 0;
}