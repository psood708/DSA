#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;
//here we initialize infinity
const int INF = numeric_limits<int>::max();

int n; // number of cities
vector<vector<int>> graph;
vector<int> tour, bestTour;
vector<bool> visited; // keeps track of visited cities
int bestCost = INF;
vector<vector<int>> allBestTours; // keeps track of all permutations that have the best cost

void tspBranchAndBound(int level, int currentCity, int currentCost)
{
    if (level == n) // if all cities have been visited
    {
        int totalCost = currentCost + graph[currentCity][0]; // calculate the total cost of the current permutation
        if (totalCost < bestCost)
        {
            bestCost = totalCost;
            bestTour = tour;
            allBestTours.clear();             // clear the vector of all previous permutations
            allBestTours.push_back(bestTour); // add the new best permutation
        }
        else if (totalCost == bestCost) // if the current permutation has the same cost as the best permutation
        {
            allBestTours.push_back(tour); // add the current permutation to the vector of best permutations
        }
        return;
    }
    for (int i = 1; i < n; ++i) // for each unvisited city
    {
        if (!visited[i] && currentCost + graph[currentCity][i] < bestCost) // if it's a valid next city to visit
        {
            visited[i] = true;                                                    // mark it as visited
            tour[level] = i;                                                      // add it to the current permutation
            tspBranchAndBound(level + 1, i, currentCost + graph[currentCity][i]); // explore further
            visited[i] = false;                                                   // backtrack and mark the city as unvisited
        }
    }
}
int main()
{
    char arr_alpha[100] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // array to label the cities
    cout << "Enter the number of cities: ";
    cin >> n;
    graph.resize(n, vector<int>(n));
    visited.resize(n, false); // initialize visited to an n-size vector with all elements false
    tour.resize(n);
    cout << "Enter the adjacency matrix representing the cost in graph:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr_alpha[i] << " : ";
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }
    visited[0] = true;
    tour[0] = 0;
    tspBranchAndBound(1, 0, 0); // explore further starting from level 1, current city 0, and current cost 0
    cout << "All best tours with cost " << bestCost << ":" << endl;
    for (int i = 0; i < allBestTours.size(); ++i) // output all the best permutations found

    {
        for (int j = 0; j < allBestTours[i].size(); j++)
        {
            cout << arr_alpha[allBestTours[i][j]] << " "; // use arr_alpha to output the label of the city
        }
         cout<<endl;
    }
    cout << endl;
    cout << "Best cost: " << bestCost << endl;
    return 0;
}
