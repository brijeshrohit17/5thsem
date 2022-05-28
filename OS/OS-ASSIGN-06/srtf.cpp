#include <bits/stdc++.h>
using namespace std;
class process
{
public:
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnarondTime;
    int waitingTime;
    int remainingTime;
    process(int processId, int a, int b)
    {
        this->processId = processId;
        this->arrivalTime = a;
        this->burstTime = b;
    }
};
//function to compare process
bool cmp(const process &obj1, const process &obj2)
{
    if (obj1.arrivalTime == obj2.arrivalTime)
    {
        return obj1.burstTime < obj2.burstTime;
    }
    return obj1.arrivalTime < obj2.arrivalTime;
}
// Shortest Remaining Time First
void srtf(vector<process> &v, int n)
{
    //remaing time = burst time initially
    for (int i = 0; i < n; i++)
    {
        v[i].remainingTime = v[i].burstTime;
    }
    int context_switch = 0;
    int compnum = 0, ctime = 0, minrem_time = INT_MAX;
    int minproc = 0, tcomp;
    bool flag = false;
    string s = "", s1 = "";
    while (compnum != n)
    {
        s1 += to_string(ctime) + " ";
        if (ctime < 10)
            s1 += " ";
        bool flag1 = false;
        for (int i = 0; i < n; i++)
        {
            //condition for minimum remaining time
            if ((v[i].arrivalTime <= ctime) && (v[i].remainingTime < minrem_time) && (v[i].remainingTime > 0))
            {
                //a new process is executed no context switching
                if (minrem_time == INT_MAX)
                {
                    flag1 = true;
                }
                minrem_time = v[i].remainingTime;
                minproc = i;
                flag = true;
                if (flag1 == true)
                    continue;
                context_switch++;
            }
        }
        //No process in queue with minimum remaining time
        if (flag == false)
        {
            if (minrem_time == INT_MAX)
                s += " ";
            else
                s += "P" + to_string(v[minproc].processId) + " ";
            ctime++;
            continue;
        }
        s += "P" + to_string(v[minproc].processId) + " ";
        //decrementing remaining time of the feasable process
        v[minproc].remainingTime--;
        minrem_time = v[minproc].remainingTime; //updating minrem_time
        if (minrem_time == 0)                   //process is complete thus reseting
        {
            minrem_time = INT_MAX;
        }
        if (v[minproc].remainingTime == 0) //process is complete so caculating other times
        {
            compnum++; //completed process incremented
            flag = false;
            tcomp = ctime + 1; //completion time = current time + 1;
            //updating data members
            v[minproc].completionTime = tcomp;
            v[minproc].waitingTime = tcomp - v[minproc].burstTime - v[minproc].arrivalTime;
            if (v[minproc].waitingTime < 0)
            {
                v[minproc].waitingTime = 0;
            }
            v[minproc].turnarondTime = v[minproc].waitingTime + v[minproc].burstTime;
        }
        ctime++;
    }
    cout
        << "\n\nTotal number of context switching : " << context_switch;
}
//function to generated random inputs
vector<process> randominput(int n)
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> d1(0, ((10 * n) + 1) / 2);
    uniform_int_distribution<int> d2(1, 10);
    vector<process> input;
    for (int i = 0; i < n; i++)
    {
        input.push_back(process(i + 1, d1(generator), d2(generator)));
        d1.reset();
    }
    return input;
}
int main()
{
    int n;
    cout << "Enter Number of Processes : ";
    cin >> n;
    vector<process> v;
    //random inputs
    v = randominput(n);
    cout << "Random process genrated are : ";
    cout << "\nProcess Id\tArrival Time\tBurst Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i].processId << "\t\t"
             << v[i].arrivalTime << "\t\t" << v[i].burstTime << "\n";
    }
    //sorting according to arrival time
    sort(v.begin(), v.end(), cmp);
    srtf(v, n);
    cout << "\n\nProcess Id\tArrival Time\tBurst Time\t Completion Time\tWaiting Time\tTurn Around Time\n";
        int tot_wt = 0,
            tot_tt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].processId << "\t\t" << v[i].arrivalTime << "\t\t" << v[i].burstTime << "\t\t" << v[i].completionTime << "\t\t\t" << v[i].waitingTime << "\t\t" << v[i].turnarondTime << "\n";
        tot_wt += v[i].waitingTime;
        tot_tt += v[i].turnarondTime;
    }
    cout << "\n\nAverage Waiting time : " << (float)tot_wt / (float)n;
    cout << "\nAverage Turn Around time : " << (float)tot_tt / (float)n;
}