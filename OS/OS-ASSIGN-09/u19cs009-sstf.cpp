#include <bits/stdc++.h>
using namespace std;

class process
{
private:
    int id;
    int seekloc;

public:
    process(int id, int a)
    {
        this->id = id;
        this->seekloc = a;
    }
    int getSeekloc()
    {
        return this->seekloc;
    }
    void setSeekloc(int loc)
    {
        this->seekloc = loc;
    }
    int getId()
    {
        return this->id;
    }
};

//FUNCTION TO GET THE PROCESS CLOSEST TO THE HEAD
int nextnearprocess(vector<process> &p, int l, int head)
{
    int n = p.size();
    int min = INT_MAX;
    int index = -1;
    for (int i = l; i < p.size(); i++)
    {
        int dis = abs(p[i].getSeekloc() - head);
        if (dis < min)
        {
            min = dis;
            index = i;
        }
    }
    return index;
}

//FUNCTION TO IMPLEMENT SSTF
void sstf(vector<process> &p, int n, int headpos)
{
    int curr = 0, itr = 0;
    int seekcount = 0, h = headpos; //loop till all processes are completed
    while (curr < n)
    {
        int closestInd = nextnearprocess(p, curr, headpos); //getting Index of closest process
        if (closestInd == -1)
        {
            break;
        }
        seekcount += abs(p[closestInd].getSeekloc() - headpos);
        headpos = p[closestInd].getSeekloc();
        swap(p[closestInd], p[itr]); //swapping inorder to remove the process that are completed and then increasing the itr
        itr++;
        curr++;
    }
    cout << endl << "Seek count : " << seekcount << endl;
    cout << endl << "Seek Sequence is : " << endl;
    cout << "Process\tSeekloc" << endl;
    cout << "head \t" << h << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].getId() << "\t" << p[i].getSeekloc() << endl;
    }
}

int main()
{
    int n;
    cout << "Enter Number of Processes : ";
    cin >> n;
    
    vector<process> p;
    
    cout << "Enter disk request sequence : ";
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p.push_back(process(i + 1, a));
    }
    
    int headpos;
    cout << "Enter the head location : ";
    cin >> headpos;
    
    sstf(p, n, headpos);
    
    return 0;
}