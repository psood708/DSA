#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> find_optimal_order(vector<double>& r) {
    int n = r.size();
    
    // Initialize F(1,k) for all k
    vector<vector<double>> F{{100.0}};
    for( int i = 2; i<=n; i++){
        vector<double> Finit;
        //this loop is for k --> years each year
        for(int k = 0; k<n;k++){
             // number of years
            // k will iterate over the rates
            double cost = F[i-2][k] + 100*pow(r[k],i-2);
            for(int j = 0; j< n; j++){
                if( j!= k){
                    double cost_j = F[i-2][j] + 100.0*pow(r[k],i-2);
                    cost = min(cost,cost_j);
                }
            }
            Finit.push_back(cost);
        }
        F.push_back(Finit);
    }





    // Find the optimal order and cost
    double min_cost = numeric_limits<double>::infinity();
    vector<int> optimal_order;

    for (int k = 0; k < n; k++) {
        double cost = F[n-1][k];
        if (cost < min_cost) {
            min_cost = cost;
            optimal_order = {k};
        } else if (cost == min_cost) {
            optimal_order.push_back(k);
        }
    }
    
    // Build the optimal order
    for (int i = n-2; i >= 0; i--) {
        int last_k = optimal_order.back();
        double min_cost = numeric_limits<double>::infinity();
        int next_k = -1;
        for (int k = 0; k < n; k++) {
            if (find(optimal_order.begin(), optimal_order.end(), k) == optimal_order.end()) {
                double cost = F[i][k] + 100.0 * pow(r[last_k], n-i-2);
                if (cost < min_cost) {
                    min_cost = cost;
                    next_k = k;
                }
            }
        }
        optimal_order.push_back(next_k);
    }
    
    reverse(optimal_order.begin(), optimal_order.end());
    return optimal_order;
}

int main() {
    vector<double> r{2.1, 3.4, 1.3,2.7 };
    vector<int> optimal_order = find_optimal_order(r);
    cout << "Optimal order: ";
    for (int k : optimal_order) {
        cout << k+1 << " ";
    }
    cout << endl;
    double total_cost = 0.0;
    for (int i = 0; i < optimal_order.size(); i++) {
        int k = optimal_order[i];
        double cost = 100.0 * pow(r[k], i);
        total_cost += cost;
        cout << "License " << k+1 << " (growth rate " << r[k] << ") purchased in month " << i+1 << " at a cost of $" << cost << endl;
    }
    cout << "Total cost: $" << total_cost << endl;
    return 0;
}
