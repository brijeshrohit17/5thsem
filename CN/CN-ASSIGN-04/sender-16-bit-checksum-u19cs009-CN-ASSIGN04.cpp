#include <bits/stdc++.h>
using namespace std;

vector<int> sum_bit(vector<int> a, vector<int> b)
{
    vector<int> add(16, 0);
    int carry = 0;
    
    for (int i = 15 ; i >= 0 ; i--)
    {
        add[i] = (a[i] + b[i] + carry) % 2;
        carry = (a[i] + b[i] + carry) / 2;
    }
    
    return add;
}

void complement(vector<int> &v)
{
    for (int i = 0 ; i < v.size() ; i++)
        v[i] = (v[i] == 1) ? 0 : 1;

}

int main()
{
    //DATA input
    string s;
    cout << endl << "Enter DATA : ";
    cin >> s;
    int n = s.length();

    //2-D array/vector to store and manipulate DATA's encoding
    vector<vector<int>> v(n);
    
    for (int i = 0 ; i < n ; i++)
    {
        int val = s[i];
        vector<int> encode;

        while (val != 0)
        {
            encode.push_back(val % 2);
            val /= 2;
        }
        
        while (encode.size() != 16)
            encode.push_back(0);
        
        reverse(encode.begin(), encode.end());
        v[i] = encode;
    }

    //check sum bits
    vector<int> checksum(16, 0);

    for (int i = 0 ; i < n ; i++)
        checksum = sum_bit(v[i], checksum);
    
    complement(checksum);

    cout << endl << "We have divided DATA in n segments where n is length of input DATA." << endl;
    cout << "Encoded value of segments are as below :" << endl << endl;
    
    for (int i = 0 ; i < n ; i++)
    {
        cout << s[i] << "'s encoded value : ";

        for (int j = 0 ; j < 16 ; j++)
            cout << v[i][j];
        
        cout << endl;
    }
    cout << endl << "CHECKSUM\t  : ";

    for (int i = 0 ; i < 16 ; i++)
        cout << checksum[i];
    
    cout << endl << endl;
    return 0;
}

/*
Enter DATA : brijesh

We have divided DATA in n segments where n is length of input DATA.
Encoded value of segments are as below :

b's encoded value : 0000000001100010
r's encoded value : 0000000001110010
i's encoded value : 0000000001101001
j's encoded value : 0000000001101010
e's encoded value : 0000000001100101
s's encoded value : 0000000001110011
h's encoded value : 0000000001101000

CHECKSUM          : 1111110100011000
*/
/*
Enter DATA : Forouzan

We have divided DATA in n segments where n is length of input DATA.
Encoded value of segments are as below :

F's encoded value : 0000000001000110
o's encoded value : 0000000001101111
r's encoded value : 0000000001110010
o's encoded value : 0000000001110101
u's encoded value : 0000000001100001
z's encoded value : 0000000001111010
a's encoded value : 0000000001100001
n's encoded value : 0000000001101110

CHECKSUM          : 1111110100011000
*/