#include<bits/stdc++.h>

using namespace std;

struct Process
{
    int brust_time;
    int priority;
    int arrival_time;
    int waiting_time;
    int use;

}P[100];


void fcfs()
{
    int n;

    cout << "\nEnter number of process : " ;
    cin >> n ;
    cout <<endl;

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i+1 << " burst time : ";
        cin >> P[i].brust_time;
    }

    int wt = 0;  // for waiting time..

    for(int i = 0; i < n; i++)
    {
        P[i].waiting_time = wt;
        wt += P[i].brust_time;
    }

    int total_wt = 0;

    for(int i = 0; i < n; i++)
    {
        total_wt += P[i].waiting_time;
    }

    float avg_wt = (float)total_wt/n ;

    cout << "\nThe Avg waiting time : " << avg_wt << endl;


}

bool compare1(Process x, Process y)
{
    return x.brust_time < y.brust_time;
}

bool compare2(Process x, Process y)
{
    return x.priority < y.priority;
}

void sjf()
{
    int n;
    cout << "\nEnter number of process : " ;
    cin >> n ;
    cout <<endl;

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i+1 << " burst time : ";
        cin >> P[i].brust_time;
    }

    sort(P, P+n, compare1);

    int wt = 0;  // for waiting time..

    for(int i = 0; i < n; i++)
    {
        P[i].waiting_time = wt;
        wt += P[i].brust_time;
    }

    int total_wt = 0;

    for(int i = 0; i < n; i++)
    {
        total_wt += P[i].waiting_time;
    }

    float avg_wt = (float)total_wt/n ;

    cout << "\nThe Avg waiting time : " << avg_wt << endl;
}

void ps()
{
    int n;
    cout << "\nEnter number of process : " ;
    cin >> n ;
    cout <<endl;

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i+1 << " burst time and priority :";
        cin >> P[i].brust_time >> P[i].priority;
    }

    sort(P, P+n, compare2);

    int wt = 0;  // for waiting time..

    for(int i = 0; i < n; i++)
    {
        P[i].waiting_time = wt;
        wt += P[i].brust_time;
    }

    int total_wt = 0;

    for(int i = 0; i < n; i++)
    {
        //cout << P[i].waiting_time << "\t";
        total_wt += P[i].waiting_time;
    }

    float avg_wt = (float)total_wt/n ;

    cout << "\nThe Avg waiting time : " << avg_wt << endl;
}

void psjf()
{
    int n;
    cout << "\nEnter number of process : " ;
    cin >> n ;
    cout <<endl;

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i+1 << " burst time and arrival time :  ";
        cin >> P[i].brust_time >> P[i].arrival_time;
    }
    int total_process = n;
    int time = 0;
    int minimum = INT_MAX;
    int m_index = 0;
    int flag = 0;
    int wt = 0;
    int cpy_brust_time[n];

    for(int i = 0; i < n; i++)
    {
        cpy_brust_time[i] = P[i].brust_time;
    }

    while(total_process != 0)
    {
        for(int i = 0; i < n; i++)
        {
            if( (P[i].arrival_time <= time) && ( cpy_brust_time[i] <minimum ) && (cpy_brust_time[i] > 0))
            {
                minimum = cpy_brust_time[i];
                m_index = i;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            time++;
            continue;
        }
        cpy_brust_time[m_index] -= 1;
        minimum = cpy_brust_time[m_index];

        if(minimum == 0)
        {
            minimum = INT_MAX;
        }

        if(cpy_brust_time[m_index] == 0)
        {
            total_process--;
            flag = 0;
            wt = time + 1;
            P[m_index].waiting_time = wt - P[m_index].brust_time-P[m_index].arrival_time;
            if(P[m_index].waiting_time < 0)
            {
                P[m_index].waiting_time = 0;
            }
        }
        time++;
    }

    int total_wt = 0;

    for(int i = 0; i < n; i++)
    {
        //cout << P[i].waiting_time << "\t";
        total_wt += P[i].waiting_time;
    }

    float avg_wt = (float)total_wt/n ;

    cout << "\nThe Avg waiting time : " << avg_wt << endl;
}

void rr()
{
    int n;
    cout << "\nEnter number of process : " ;
    cin >> n ;
    cout <<endl;

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i+1 << " burst time : ";
        cin >> P[i].brust_time;
        P[i].use = -1;
    }

    int quantum;
    cout << "\nQuantum time : ";
    cin >> quantum ;
    cout << endl;

    int wt = 0;  // for waiting time..

    while(1)
    {
        int flag = 1;
        for(int i = 0; i < n; i++)
        {
            if(P[i].brust_time>0)
            {
                flag = 0;
                P[i].use += 1;
                if(P[i].brust_time >= quantum)
                {
                    P[i].brust_time -= quantum;
                    P[i].waiting_time = wt;
                    wt += quantum;
                }
                else
                {
                    P[i].waiting_time = wt;
                    wt += P[i].brust_time;
                    P[i].brust_time = 0;
                }
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        //cout << P[i].use << "\t" ;
        P[i].waiting_time = P[i].waiting_time - (P[i].use * quantum);
    }

    int total_wt = 0;

    for(int i = 0; i < n; i++)
    {
        //cout << P[i].waiting_time << "\t";
        total_wt += P[i].waiting_time;
    }

    float avg_wt = (float)total_wt/n ;

    cout << "\nThe Avg waiting time : " << avg_wt << endl;

}

int main()
{
    int n;

    cout << "Select a scheduling Algorithm : \n"
         << "\n1.FCFS"
         << "\n2.SJF"
         << "\n3.PS"
         << "\n4.PSJF"
         << "\n5.RR" << endl;

    cout << "\nEnter your choice : ";
    cin >> n ;
    cout <<endl;

    if(n == 1)
    {
        fcfs();
    }
    else if(n == 2)
    {
        sjf();
    }
    else if(n == 3)
    {
        ps();
    }
    else if(n == 4)
    {
        psjf();
    }
    else if(n == 5)
    {
        rr();
    }
    else
    {
        cout << "Wrong .....!" << endl;
    }
    return 0;
}

/**
5
10
6
2
4
8
*/

/**
5
10 3
6 5
2 2
4 1
8 4
*/

/** psjf
4
6 1
8 1
7 2
3 3
*/
