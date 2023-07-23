#include <iostream>
#include<string>
using namespace std;

int main()
{
   string str1;
   string str2;
    getline(cin,str1);
    getline(cin,str2);
   //cin>>str1;
   //cin>>str2;
    int n;
    n = str1.length();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(str1[j]==str1[i] && str2[i]!=str2[j] ||
            str2[i]==str2[j] && str1[i]!=str1[j]) {
                cout << "false" << endl;
                return 0;
            }
        }
    }
    cout << "true" << endl;
	return 0;
}
