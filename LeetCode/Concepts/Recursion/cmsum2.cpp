#include <bits/stdc++.h>
using namespace std;

void fComb(int x, int target, vector<int> &arr, vector<vector<int> > &ans, vector<int> &ds)
{

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = x; i < arr.size(); i++)
    {
        if (arr[i] <= target)
        {
            ds.push_back(arr[i]);
            fComb(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > ans;
    vector<int> ds;
    fComb(0, target, candidates, ans, ds);
    return ans;
}

/// subsets sum
/*
[ 3, 1, 2]--> we need to seleet one from the bunch


*/
void func(int x, int sum, vector<int> &arr, int N, vector<int> &sumSubset)
{
    if (x == N)
    {
        sumSubset.push_back(sum);
        return;
    }
    func(x + 1, sum + arr[x], arr, N, sumSubset);
    func(x + 1, sum, arr, N, sumSubset);
}

/*
Permutations







*/

void solvePerm(vector<int> &ds, vector<int> &nums, vector<vector<int> > &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            solvePerm(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int> > permute(vector<int> &nums)
{

    vector<vector<int> > ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    solvePerm(ds, nums, ans, freq);
    return ans;
}

vector<int> subsetSum(vector<int> arr, int N)
{
    vector<int> sumSubset;
    func(0, 0, arr, N, sumSubset);
    sort(sumSubset.begin(), sumSubset.end());
    return sumSubset;
}

/*building áfunction to print 2d vector array*/
void print2D(vector<vector<int> > &arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*building a functino to print 1d array*/
void print1D(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> pl = {4, 7, 1};
    int N = pl.size();
    vector<int> sumSubset = subsetSum(pl, N);
    vector<vector<int> > l = permute(pl);
    print2D(l);

    return 0;
}