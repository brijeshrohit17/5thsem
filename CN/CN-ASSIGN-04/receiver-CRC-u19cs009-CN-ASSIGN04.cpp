#include <bits/stdc++.h>
using namespace std;

bool decode(vector<int> data, vector<int> key, int n, int r)
{
    for (int i = 0; i < n - r + 1; i++)
    {
        if (data[i] != key[0])
            continue;
        
        for (int j = 0, k = i; j < r; j++, k++)
            data[k] ^= key[j];
    }

    for (int i = n - r; i < n; i++)
        if (data[i] != 0)
            return false;

    return true;
}

int main()
{
    int n, r;
    
    //length of DATA received
    cout << endl << "Enter size of received message\t: ";
    cin >> n;
    
    //length of KEY
    cout << "Enter size of key\t\t: ";
    cin >> r;
    
    //vector/array to store DATA and KEY
    vector<int> data(n), key(r);
    string temp;
    
    //input DATA
    cout << "Enter received signal\t\t: ";
    cin >> temp;
    
    //keying DATA with respect to ASCII of '0'
    for (int i = 0; i < n; i++)
        data[i] = temp[i] - '0';
    
    //input KEY
    cout << "Enter key\t\t\t: ";
    cin >> temp;
    
    //keying KEYS with respect to ASCII of '0'
    for (int i = 0; i < r; i++)
        key[i] = temp[i] - '0';

    //checking if DATA is errorfree and decodable or not
    if (decode(data, key, n, r))
    {
        cout << endl << "Errorfree DATA!" << endl;
        
        //printing original DATA if found error free
        cout << "Received DATA is\t\t: ";
        for (int i = 0 ; i < n - r + 1 ; i++)
            cout << data[i];
    }

    else
        cout << endl << "Error Detected!";
    
    cout << endl << endl;
    return 0;
}