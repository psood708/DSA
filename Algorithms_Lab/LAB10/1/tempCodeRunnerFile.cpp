#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;
// Function to find the optimal order in which to purchase licenses
vector<int> find_optimal_order(vector<double> &r)
{
    int n = r.size();
    // Initialize F(1,k) for all k
    // F[i][j] represents the minimum cost to purchase licenses 1 through i
    // when the ith license is license j+1
    vector<vector<double>> F{{100.0}};
    // Loop over each month (i)
    for (int i = 2; i <= n; i++)
    {
        vector<double> Finit;
        // Loop over each license rate (k)
        for (int k = 0; k < n; k++)
        {
            // Compute the cost of purchasing license k+1 in month i
            double cost = F[i - 2][k] + 100 * r[k] * (i - 2);
            // Loop over each license rate (j) that is not equal to k
            for (int j = 0; j < n; j++)
            {
                if (j != k)
                {
                    double cost_j = F[i - 2][j] + 100.0 * r[k] * (i - 2);
                    // Choose the minimum cost among all j
                    cost = min(cost, cost_j);
                }
            }
            // Store the minimum cost in Finit for license k
            Finit.push_back(cost);
        }
        // Store the minimum cost for each license in F for month i
        F.push_back(Finit);
    }
    // Find the optimal order and cost
    double min_cost = numeric_limits<double>::infinity();
    vector<int> optimal_order;
    // Loop over each license rate (k) for the last month (n)
    for (int k = 0; k < n; k++)
    {
        double cost = F[n - 1][k];
        if (cost < min_cost)
        {
            min_cost = cost;
            optimal_order = {k};
        }
        else if (cost == min_cost)
        {
            optimal_order.push_back(k);
        }
    }
    // Loop over each month (i) from the second-to-last month (n-2) to the first month (0)
    for (int i = n - 2; i >= 0; i--)
    {
        int last_k = optimal_order.back();
        double min_cost = numeric_limits<double>::infinity();
        int next_k = -1;
        // Loop over each license rate (k) that has not already been added to optimal_order
        for (int k = 0; k < n; k++)
        {
            if (find(optimal_order.begin(), optimal_order.end(), k) == optimal_order.end())
            {
                // Compute the cost of purchasing license k+1 in month i+1 and choosing last_k in month i
                double cost = F[i][k] + 100.0 * r[last_k] * (n - i - 2);
                // Choose the minimum cost among all k
                if (cost < min_cost)
                {
                    min_cost = cost;
                    next_k = k;
                }
            }
        }
        // Add the license with minimum cost to optimal_order for month i+1
        optimal_order.push_back(next_k);
    }
    // Reverse the order of optimal_order so that it represents the order of occurrence
    reverse(optimal_order.begin(), optimal_order.end());
    return optimal_order;
}
int main()
{
    // Create a vector to store the growth rates of each license
    vector<double> r;
    // Ask the user to input how many growth rates they want to add
    int n1;
    cout << "Enter how many rates you want to add: ";
    cin >> n1;
    // Loop through the number of growth rates entered by the user and add them to the vector
    for (int i = 0; i < n1; i++)
    {
        double inter = 0;
        cin >> inter;
        r.push_back(inter);
    }
    // Find the optimal order in which to purchase the licenses
    vector<int> optimal_order = find_optimal_order(r);
    // Print the optimal order in which to purchase the licenses
    cout << "Optimal order: ";
    for (int k : optimal_order)
    {
        cout << k + 1 << " "; // Add 1 to k to print the license number starting from 1 instead of 0
    }
    cout << endl;
    // Calculate the total cost of purchasing the licenses in the optimal order
    double total_cost = 0.0;
    for (int i = 0; i < optimal_order.size(); i++)
    {
        double cost;
        int k = optimal_order[i];
        // For the first license purchased, the cost is 100.0
        if (i == 0)
        {
            cost = 100.0;
        }
        // For all other licenses, the cost is 100.0 multiplied by the growth rate of the license and the month number
        else
        {
            cost = 100.0 * r[k] * i;
        }
        total_cost += cost; // Add the cost to the total cost
        // Print the details of the license purchase
        cout << "License " << k + 1 << " (growth rate " << r[k] << ") purchased in month " << i + 1 << " at a cost of $" << cost << endl;
    }
    // Print the total cost of purchasing the licenses in the optimal order
    cout << "Total cost: $" << total_cost << endl;
    return 0;
}
