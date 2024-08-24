#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;     // Job Id 
    int dead;   // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

vector<int> JobScheduling(vector<Job> jb, int n) {
    // Sort jobs according to decreasing order of profit
    sort(jb.begin(), jb.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    });

    // To keep track of free time slots
    vector<int> result(n, -1);

    // To keep track of the total profit
    int maxProfit = 0;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, jb[i].dead) - 1; j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = i; // Assign job to this slot
                maxProfit += jb[i].profit;
                break;
            }
        }
    }

    // Result contains the index of jobs in the order of their scheduled time slots
    vector<int> jobOrder;
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            jobOrder.push_back(jb[result[i]].id);
        }
    }

    return jobOrder;
}

int main() {
    vector<Job> jb = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = jb.size();
    
    vector<int> jobOrder = JobScheduling(jb, n);
    
    cout << "The order of jobs for maximum profit is: ";
    for (int id : jobOrder) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
