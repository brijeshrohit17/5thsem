#include <bits/stdc++.h>
using namespace std;

vector<int> sum(vector<int> a, vector<int> b)
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

bool decode(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        if (v[i] == 0)
            return false;
    }

    return true;
}

int decodeToChar(vector<int> v)
{
    reverse(v.begin(), v.end());
    int val = 0;

    for (int i = 0; i < v.size(); i++)
        val += v[i] * (1 << i);
    
    return val;
}

int main()
{
    //input DATA
    int n;
    cout << endl << "Enter number of segment of encoded data: ";
    cin >> n;
    cout <<  endl;

    //2-D array/vector to store and manipulate DATA's decoding
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cout << "Enter data of segment " << i + 1 << " : ";
        cin >> s;
        
        vector<int> segment(s.length());

        for (int i = 0 ; i < s.length() ; i++)
            segment[i] = s[i] - '0';
        
        v[i] = segment;
    }

    //check sum bits
    vector<int> checksum(16, 0);

    for (int i = 0 ; i < n ; i++)
        checksum = sum(v[i], checksum);

    if (decode(checksum))
    {
        cout << endl << "Error not Detected!" << endl;
        cout << "Received message is : ";

        for (int i = 0; i < n - 1; i++)
        {
            int n = decodeToChar(v[i]);
            cout << (char)n;
        }

        cout << endl;
    }
    else
        cout << "Error Detected!" << endl;
    
    cout << endl;
    return 0;
}
/*
Entered DATA : brijesh
n=8
0000000001100010
0000000001110010
0000000001101001
0000000001101010
0000000001100101
0000000001110011
0000000001101000
1111110100011000

*/
/*
Entered DATA : Forouzan
n=9
0000000001000110
0000000001101111
0000000001110010
0000000001110101
0000000001100001
0000000001111010
0000000001100001
0000000001101110
1111110010111001
*/