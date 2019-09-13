#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// solution 1 - runtime O(n^2):

// compute volume between start and end
// assume that the tallest bar and the second tallest is at start or end (index)
int borderedVolume(vector<int> histogram, int start, int end){
    if (start >= end){
        return 0;
    }

    int min = std::min(histogram[start], histogram[end]);
    int sum = 0;
    for(int i = start + 1; i < end; i++){
        sum += min - histogram[i];
    }
    return sum;
}

// Find the tallest bar in histogram between start and end
int findIndexOfMax(vector<int> histogram, int start, int end){
    int indexOfMax = start;
    for (int i = start + 1; i <= end; i++){
        if (histogram[i] > histogram[indexOfMax]){
            indexOfMax = i;
        }
    }
    return indexOfMax;
}

// compute the volume of a subgraph of the histogram

int subgraphVolume(vector<int> histogram, int start, int end, bool isLeft){
    if (start >= end){
        return 0;
    }
    int sum = 0;
    if (isLeft){
        int max = findIndexOfMax(histogram, start, end - 1);
        sum += borderedVolume(histogram, max, end);
        sum += subgraphVolume(histogram, start, max, isLeft);
    } else {
        int max = findIndexOfMax(histogram, start + 1, end);
        sum += borderedVolume(histogram, start, max);
        sum += subgraphVolume(histogram, max, end, isLeft);
    }
    return sum;
}

int computeHistogramVolume(vector<int> histogram){
    int start = 0;
    int end = histogram.size() - 1;

    int max = findIndexOfMax(histogram, start, end);
    int leftVolume = subgraphVolume(histogram, start, max, true);
    int rightVolume = subgraphVolume(histogram, max, end, false);

    return leftVolume + rightVolume;
}


// simple solution:
// store the leftmax, rightmax, delta info  - runtime O(n)

// step1: sweep left to right, tracking the max height you've seen and setting left max
// step2: sweep right to left, tracking the max height you've seen and setting right max
// step3: sweep across the histogram, computing the mininum of the right max and letf max for each index
// step4: sweep across the histogram, computing the delta between each minimum and the bar. Sum the deltas

int computeHistogramVolumeSimple(vector<int> histo){
    vector<int> leftMaxes(histo.size());
    int leftMax = histo[0];
    for (int i = 0; i < histo.size(); i++){
        leftMax = std::max(leftMax, histo[i]);
        leftMaxes[i] = leftMax;
    }

    int sum = 0;
    int rightMax = histo[histo.size() - 1];
    for (int i = histo.size() - 1; i >= 0; i--){
        rightMax = std::max(rightMax, histo[i]);
        int secondTallest = min(rightMax, leftMaxes[i]);

        if (secondTallest > histo[i]){
            sum += secondTallest - histo[i];
        }
    }
    return sum;
}

int main()
{
    vector<int> hist = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
    cout << computeHistogramVolume(hist) << endl;
    cout << computeHistogramVolumeSimple(hist) << endl;
    return 0;
}
