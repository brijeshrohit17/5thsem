#include <bits/stdc++.h>
using namespace std; 

class process
{
private:
    int id;
    int seekloc;
    int complete;

public:
    process(int id, int a)
    {
        this->id = id;
        this->seekloc = a;
        this->complete = 0;
    }
    int getSeekloc() { return this->seekloc; }
    void setSeekloc(int loc) { this->seekloc = loc; }
    int getId() { return this->id; }
    void setComplete() { this->complete = 1; }
    int getComplete() { return this->complete; }
};

//FUNCTION TO CALCULATE DISTANCES IN A ONE DIRECTION FROM HEAD TO SELECT PROCESSES
vector<pair<int, int>> calcd(vector<process> &p, int flag, int head)
{
    int n = p.size();
    if (flag == 0) //LEFT DIRECTION
    {
        vector<pair<int, int>> p1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].getSeekloc() <= head && p[i].getComplete() != 1)
            {
                p1.push_back({i, abs(p[i].getSeekloc() - head)});
            }
        }
        return p1;
    }
    else //RIGHT DIRECTION
    {
        vector<pair<int, int>> p1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].getSeekloc() >= head && p[i].getComplete() != 1)
            {
                p1.push_back({i, abs(p[i].getSeekloc() - head)});
            }
        }
        return p1;
    }
}

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

void scan(vector<process> &p, int n, int headloc, char dir)
{
    int curr = 0, itr = 0;
    int seekcount = 0, h = headloc;
    vector<pair<int, int>> output;
    while (curr < n + 1)
    {
        if (dir == 'l') //IF LEFT
        {
            vector<pair<int, int>> dis;
            dir = 'r'; //ALL THE PROCESSES IN THE LEFT OF THE HEAD
            dis = calcd(p, 0, h);
            sort(dis.begin(), dis.end(), compare);
            for (auto i : dis)
            { //PROCESS INCOMPLETE THEN ALLOCATE
                if (p[i.first].getComplete() != 1)
                {
                    seekcount += abs(p[i.first].getSeekloc() - h);
                    h = p[i.first].getSeekloc();
                    output.push_back({p[i.first].getId(), p[i.first].getSeekloc()});
                    p[i.first].setComplete();
                }
                curr++;
                if (curr >= n + 1)
                    break; //ALL PROCESS COMPLETE THEN BREAK;
            }
            if (curr >= n + 1)
                break; //ALL PROCESS COMPLETE THEN BREAK;
        }
        else if (dir == 'r') //IF RIGHT
        {
            vector<pair<int, int>> dis;
            dir = 'l'; //ALL THE PROCESSES IN THE RIGHT OF THE HEAD
            dis = calcd(p, 1, h);
            sort(dis.begin(), dis.end(), compare);
            for (auto i : dis)
            { //PROCESS INCOMPLETE THEN ALLOCATE
                if (p[i.first].getComplete() != 1)
                {
                    seekcount += abs(p[i.first].getSeekloc() - h);
                    h = p[i.first].getSeekloc();
                    output.push_back({p[i.first].getId(), p[i.first].getSeekloc()});
                    p[i.first].setComplete();
                }
                curr++;
                if (curr >= n + 1)
                    break; //ALL PROCESS COMPLETE THEN BREAK;
            }
            if (curr >= n + 1)
                break; //ALL PROCESS COMPLETE THEN BREAK;
        }
    }
    cout << "\nSeek count : " << seekcount << endl;
    cout << "\nSeek Sequence is : " << endl;
    cout << "Process\tSeekloc" << endl;
    cout << "head \t" << headloc << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i].first << "\t" << output[i].second << endl;
    }
}
int main()
{
    int n, size;
    cout << "Enter Number of Processes : ";
    cin >> n;
    cout << "Enter disk size : ";
    cin >> size;

    vector<process> p;
    cout << "Enter disk request sequence : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p.push_back(process(i + 1, a));
    }

    int headloc;
    cout << "Enter the head location : ";
    cin >> headloc;

    char dir;
    cout << "Enter initial direction : " << endl;
    cout << "type \"l\" for left, and \"r\" for right : ";
    cin >> dir;

    p.push_back(process(-1, 0));

    p.push_back(process(-2, size));

    scan(p, n, headloc, dir);

    return 0;
}