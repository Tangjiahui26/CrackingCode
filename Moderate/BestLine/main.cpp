#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <boost/functional/hash.hpp>

using namespace std;

// here is the solution to a similar coding question:
// Count Maximum Points on the same line

// get gcd

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int maxPointsOnTheSameLine(vector<pair<int, int>> points){
    int num = points.size();
    if (num < 2){
        return num;
    }

    int maxPoint = 0;
    int curMax, overleapPoints, verticalPoints;

    unordered_map<pair<int, int>, int, boost::hash<pair<int, int>>> slopeMap;

    for (int i = 0; i < num; i++){
        curMax = 0; overleapPoints = 0; verticalPoints = 0;
        for (int j = i + 1; j < num; j++){
            if (points[i] == points[j]){
                overleapPoints++;
            } else if (points[i].first == points[j].first){
                verticalPoints++;
            } else {
                int xDiff = points[i].first - points[j].first;
                int yDiff = points[i].second - points[j].second;

                // get greatest common divider
                int g = gcd(xDiff, yDiff);

                xDiff /= g;
                yDiff /= g;

                slopeMap[make_pair(yDiff, xDiff)]++;
                curMax = max(curMax, slopeMap[make_pair(yDiff, xDiff)]);
            }
            curMax = max(curMax, verticalPoints);
        }
        maxPoint = max(maxPoint, curMax + overleapPoints + 1);
        slopeMap.clear();
    }
    return maxPoint;
}

int main()
{
    const int size = 6;
    int arr[size][2] = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4}};
    vector<pair<int, int>> points;
    for (int i = 0; i < size; i++){
        points.push_back(make_pair(arr[i][0], arr[i][1]));
    }

    cout << "Maximum Points on the same line: "<< maxPointsOnTheSameLine(points) << endl;
    return 0;
}
