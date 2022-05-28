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
    void rrs(vector<process> &v, int n, int interval)
    {
        int ctime = 0;
        //remaining time = burst time
        for (int i = 0; i < n; i++)
        {
            v[i].remainingTime = v[i].burstTime;
        }
        int comproc = 0;
        string s1 = "Time : ";
        string s2 = "Process : ";
        int context_switch = 0;
        int prev_i = -1;
        while (comproc != n)
        {
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                //if any process has arrived
                if (v[i].arrivalTime <= ctime)
                {
                    // process is incomplete
                    if (v[i].remainingTime > 0)
                    {
                        flag = false;
                        if (prev_i != i && prev_i != -1)
                        {
                            if (v[prev_i].remainingTime != 0)
                            {
                                context_switch++;
                            }
                        }
                        prev_i = i;
                        if (v[i].remainingTime > interval)
                        {
                            ctime += interval;
                            v[i].remainingTime -= interval;
                            for (int j = 0; j < interval; j++)
                            {
                                s1 += "P" + to_string(v[i].processId) + " ";
                            }
                        }
                        else
                        {
                            for (int j = 0; j < v[i].remainingTime; j++)
                            {
                                s1 += "P" + to_string(v[i].processId) + " ";
                            }
                            ctime += v[i].remainingTime;
                            v[i].waitingTime = ctime - v[i].burstTime - v[i].arrivalTime;
                            v[i].remainingTime = 0;
                            v[i].completionTime = ctime;
                            //increment the completed process number
                            comproc++;
                            prev_i = i;
                        }
                    }
                }
            }
            if (flag == true)
            {
                ctime++;
                s1 += " ";
            }
        }
        for (int i = 0; i <= ctime; i++)
        {
            s2 += to_string(i) + " ";
            if (i < 10)
                s2 += " ";
        }
        for (int i = 0; i < n; i++)
        {
            v[i].turnarondTime = v[i].burstTime + v[i].waitingTime;
        }
        cout << "\n\nTotal number of context switching : " << context_switch;
    }
    //function for random input generation
    vector<process> randominput(int n)
    {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);
        uniform_int_distribution<int> d1(1, ((10 * n) + 1) / 2);
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
        int interval;
        cout << "Enter the time quantum for round robin : ";
        cin >> interval;
        vector<process> v1;
        //random input
        v1 = randominput(n);
        cout << "\nRandomly generated inputs are : ";
        cout << "\nProcess Id\tArrival Time\tBurst Time\n";
        for (int i = 0; i < n; i++)
        {
            cout << v1[i].processId << "\t\t"
                << v1[i].arrivalTime << "\t\t" << v1[i].burstTime << "\n";
        }
        //sorting according to arrive time
        sort(v1.begin(), v1.end(), cmp);
        rrs(v1, n, interval);
        int tot_wt = 0, tot_tt = 0;
        cout << "\n\nProcess ID\tArrival Time\tBurst Time\t Completion Time\tWaiting Time\tTurn Around Time\n";
            for (int i = 0; i < n; i++)
        {
            cout << "\t" << v1[i].processId << "\t\t" << v1[i].arrivalTime << "\t\t" << v1[i].burstTime << "\t\t "
                << v1[i].completionTime << "\t\t\t " << v1[i].waitingTime << "\t\t " << v1[i].turnarondTime << endl;
            tot_wt += v1[i].waitingTime;
            tot_tt += v1[i].turnarondTime;
        }
        cout << "\n\nAverage Waiting time : " << (float)tot_wt / (float)n;
        cout << "\nAverage Turn Around time : " << (float)tot_tt / (float)n;
    }