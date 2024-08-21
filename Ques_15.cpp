/*You are given a string 'STR'. The string contains [a-z] [A-Z] [0-9] [special characters]. You have to find the reverse of the string.

For example:

 If the given string is: STR = "abcde". You have to print the string "edcba".*/

#include <bits/stdc++.h>
void reverse(string &name, int i, int j)
{

    if (i > j)
    {
        return;
    }

    swap(name[i], name[j]);
    i++;
    j--;
    reverse(name, i, j);
}

string reverseString(string str)
{
    reverse(str, 0, str.length() - 1);
    return str;
}
