#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> W;

void weightedMedian()
{
    vector<pair<int, double>> pr;

    for(int index = 0;
            index < arr.size();
            index++)
        pr.push_back({arr[index],
                        W[index]});


    sort(pr.begin(), pr.end());

    if (arr.size() % 2 != 0)
    {

        double sums = 0;
        for(auto element : pr)
        {

            // Update sums
            sums += element.second;

            // If sum becomes > 0.5
            if (sums > 0.5)
                cout << "The Weighted Median is element "
                     << element.first << endl;
        }
    }
    else
    {

        double sums = 0;
        for(auto element : pr)
        {
            sums += element.second;

            if (sums >= 0.5)
            {
                cout << "Lower Weighted Median is element "
                     << element.first << endl;
                break;
            }
        }
        sums = 0;
        for(int index = pr.size() - 1;
                index >= 0;
                index--)
        {
            int element = pr[index].first;
            double weight = pr[index].second;

            sums += weight;

            if (sums >= 0.5)
            {
                cout << "Upper Weighted Median is element "
                     << element;
                break;
            }
        }
    }
}

// Driver Code
int main()
{

    // Given array arr[]
arr = { 4, 1, 3, 2 };

    // Given weights W[]
   W = { 0.25, 0.49, 0.25, 0.01 };

    // Function Call
    weightedMedian();
}
