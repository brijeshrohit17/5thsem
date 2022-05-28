#include <bits/stdc++.h>
using namespace std;

void encode(vector<int> &data, vector<int> key, int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        if (data[i] != key[0])
            continue;
        
        for (int j = 0, k = i; j < r; j++, k++)
            data[k] ^= key[j];
    }
}
int main()
{
    int n, r;
    
    //length of DATA
    cout << endl << "Enter length of message\t: ";
    cin >> n;
    
    //length of KEY
    cout << "Enter length of key\t: ";
    cin >> r;
    
    //vector/Array to store DATA, KEYS and ENCODED data
    vector<int> data(n + r - 1, 0);
    vector<int> key(r);
    vector<int> crcEncoded(n + r - 1, 0);
    
    //input data
    string temp;
    cout << "Enter message\t\t: ";
    cin >> temp;
    
    //keying DATA with respect to ASCII of '0'
    for (int i = 0; i < n; i++)
        data[i] = temp[i] - '0';
    
    //input KEY
    cout << "Enter key\t\t: ";
    cin >> temp;

    //keying KEYS with respect to ASCII of '0'
    for (int i = 0; i < r; i++)
        key[i] = temp[i] - '0';
    
    crcEncoded = data;

    //encoding using encode function
    encode(crcEncoded, key, n, r);

    //encoded output
    cout << endl << "CRC of code is\t\t: ";
    for (int i = 0; i < r - 1; i++)
    {
        data[n + i] = crcEncoded[n + i];
        cout << data[n + i];
    }

    cout << endl << "Encoded DATA is\t\t: ";
    for (int i = 0; i < n + r - 1; i++)
        cout << data[i];
    
    cout << endl << endl;
    return 0;
}