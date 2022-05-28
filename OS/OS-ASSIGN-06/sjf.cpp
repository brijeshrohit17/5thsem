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
//Shortest job first
void sjf(vector<process> &v, int n)
{
    int tcomp, curr;
    // First process will complete
    v[0].completionTime = v[0].arrivalTime + v[0].burstTime;
    v[0].turnarondTime = v[0].completionTime - v[0].arrivalTime;
    v[0].waitingTime = v[0].turnarondTime - v[0].burstTime;
    for (int i = 1; i < n; i++)
    {
        tcomp = v[i - 1].completionTime;
        int min_burst = v[i].burstTime;
        curr = -1;
        while (curr == -1)
        {
            for (int j = i; j < n; j++)
            {
                if (tcomp >= v[j].arrivalTime && min_burst >= v[j].burstTime)
                {
                    min_burst = v[j].burstTime;
                    curr = j;
                }
            }
            if (curr == -1)
                tcomp = v[i].arrivalTime;
        }
        v[curr].completionTime = tcomp + v[curr].burstTime;
        v[curr].turnarondTime = v[curr].completionTime - v[curr].arrivalTime;
        v[curr].waitingTime = v[curr].turnarondTime - v[curr].burstTime;
        process temp = v[i];
        v[i] = v[curr];
        v[curr] = temp;
    }
}
// function to generate random input
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
    vector<process> v1;
    //random generation
    v1 = randominput(n);
    cout << "\nRandomly generated inputs are : \n";
    cout << "\nProcess Id\tArrival Time\tBurst Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << v1[i].processId << "\t\t"
             << v1[i].arrivalTime << "\t\t" << v1[i].burstTime << "\n";
    }
    //sorting process according to arrival time
    sort(v1.begin(), v1.end(), cmp);
    sjf(v1, n);
    int tot_wt = 0, tot_tt = 0;
    cout << "\n\nProcess Id\tArrival Time\tBurst Time\t Completion Time\tWaitingTime\tTurn Around Time\n";
        for (int i = 0; i < n; i++)
    {
        cout << v1[i].processId << "\t\t" << v1[i].arrivalTime << "\t\t" << v1[i].burstTime << "\t\t " << v1[i].completionTime << "\t\t\t" << v1[i].waitingTime << "\t\t " << v1[i].turnarondTime << "\n";
        tot_wt += v1[i].waitingTime;
        tot_tt += v1[i].turnarondTime;
    }
    cout << "\n\nAverage Waiting time : " << (float)tot_wt / (float)n;
    cout << "\nAverage Turn Around time : " << (float)tot_tt / (float)n;
}