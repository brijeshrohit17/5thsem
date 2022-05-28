#include<bits/stdc++.h>
using namespace std;

class LRU
{
public:
    //data members
    int frame;
    //queue to store page
    list<int> dq;
    map<int, list<int>::iterator> mp;

    LRU(int frame) //constructor
    {
        this->frame = frame;
    }
    //member function
    void check(int x)
    {
        //if the page is not present in queue
        if (mp.find(x) == mp.end())
        {
            //if the queue is full
            if (frame == dq.size())
            {
                //erasing least recently used .
                int temp = dq.back();
                dq.pop_back();
                mp.erase(temp);
            }
        }
        else
        {
            //just erasing it from the queue
            dq.erase(mp[x]);
        }
        //adding the page to the queue
        dq.push_front(x);
        mp[x] = dq.begin();
    }

    void printdetails()
    {
        cout << " ";
        int j = 0;
        for (auto i : dq)
        {
            cout << i << " ";
            j++;
        }
        while (j < frame)
        {
            cout << "-"
                 << " ";
            j++;
        }
        cout << endl;
    }
};
int main()
{
    int frames;
    cout << "Enter Number of Frames : ";
    cin >> frames;

    LRU qu(frames);
    int n;
    cout << "Enter Number of pages : ";
    cin >> n;
    cout << "Enter the pages : ";
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }
    cout << "Frames ";
    for (int i = 0; i < frames; i++)
        cout << i + 1 << " ";
    cout << "\n\n";
    //for eac page checking the frames
    for (int i = 0; i < n; i++)
    {
        cout << temp[i];
        qu.check(temp[i]);
        qu.printdetails();
    }
}