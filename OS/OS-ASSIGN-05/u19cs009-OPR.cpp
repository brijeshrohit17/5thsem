#include <bits/stdc++.h>
using namespace std;
class OPR
{
public:
    //data members
    int frame;
    vector<int> v;
    map<int, vector<int>::iterator> mp;
    //constructor
    OPR(int frame)
    {
        this->frame = frame;
    }
    //member functions
    bool search(int x)
    {
        for (auto i : v)
        {
            if (i == x)
                return true;
        }

        return false;
    }
    void check(int x, vector<int> page, int k)
    { //if queue is empty then pushing
        //directly
        if (frame != v.size())
        {
            v.push_back(x);
            mp[x] = v.end();
            return;
        }
        //if the queue doesn't have the page
        if (mp.find(x) == mp.end())
        {
            int fno = 0;
            //if vector is full
            if (frame == v.size())
            {
                auto farthest = page.begin();
                //finding the frame containg page
                //with farthest next occurance or no
                //occurance
                for (auto i : v)
                {

                    auto p = find(page.begin() + k + 1, page.end(), i);
                    if (p == page.end())
                    {
                        fno = i;
                        break;
                    }
                    if (p - page.begin() > farthest - page.begin())
                    {
                        farthest = p;
                        fno = i;
                    }
                }
            }
            //finding that page in frame vector
            vector<int>::iterator p = find(v.begin(), v.end(), fno);
            v.erase(p);     //erasing that frame
            mp.erase(fno);  //erasing that mapping
            v.insert(p, x); //insertung at that place the new page
            mp[x] = p;      //mapping
        }
    }

    void printdetails()
    {
        cout << " ";
        int j = 0;
        for (auto i : v)
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

    OPR qu(frames);
    int n;
    cout << "Enter Number of pages : ";
    cin >> n;
    cout << "Enter the pages : ";
    vector<int> page;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        page.push_back(temp);
    }
    cout << "Frames ";
    for (int i = 0; i < frames; i++)
        cout << i + 1 << " ";
    cout << "\n\n";
    //checking for each page
    for (int i = 0; i < n; i++)
    {
        cout << page[i];
        qu.check(page[i], page, i);
        qu.printdetails();
    }
}