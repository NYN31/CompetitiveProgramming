#include<bits/stdc++.h>
using namespace std;

int palin(string temp)
{
    int c;
    for(int z = 0; z<temp.size()/2; z++){
        if(temp[z] == temp[temp.size()-z-1])
            c = 0;
        else{
            c=1;
            return 0;
        }
    }
    if(c==0)
        return 1;
}
string getString(char x)
{
    string s(1, x);
    return s;
}
int main()
{
    string s, temp,inp;
    while(cin >> s)
    {
        set<string>s3;
        set<string>::iterator it;

        for(int i = 0; i<s.size(); i++){
            inp = getString(s[i]);
            s3.insert(inp);
        }

        int k = 2, c;
        for(int i = 1; i<s.size(); i++){
            for(int j = 0; j<s.size(); j++){
                temp = s.substr(j, k);

                if(palin(temp)) s3.insert(temp);
                temp.clear();
            }
            k++;
        }

        cout << "The string \'" << s << "\' contains " << s3.size() << " palindromes." << endl;
        s3.clear();
    }
    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;

int palin(string temp)
{
    int c;
    for(int z = 0; z<temp.size()/2; z++){
        if(temp[z] == temp[temp.size()-z-1])
            c = 0;
        else{
            c=1;
            return 0;
        }
    }
    if(c==0)
        return 1;
}

int main()
{
    string s, temp,inp;
    while(cin >> s)
    {
        set<string>s3;

        int k = 1, c;
        for(int i = 0; i<s.size(); i++){
            for(int j = 0; j<s.size(); j++){
                temp = s.substr(j, k);

                if(palin(temp)) s3.insert(temp);
                if(temp.size() == 1) s3.insert(temp);
                temp.clear();
            }
            k++;
        }

        cout << "The string \'" << s << "\' contains " << s3.size() << " palindromes." << endl;
        s3.clear();
    }
    return 0;
}
*/
