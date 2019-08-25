#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Median of two sorted arrays

// Problem 1: two arrays with the same size

// Problem 1: Approach 1: Merge Sort procedure O(n)

int getMedianUsingMerge(int arr1[], int arr2[], int n){
    int i = 0; // current index of arr1[]
    int j = 0; // current index of arr2[]

    int count;
    int m1 = -1;
    int m2 = -1;

    // after merging arr1 and arr2, then
    // the median should be average of
    // elements at index n-1 and n
    for (count = 0; count <= n; count++){

        // Case: all elements of arr1[] are
        // smaller than smallest (or first)
        // element of arr2
        if (i == n){
            m1 = m2;
            m2 = arr2[0];
            break;
        } else if (j == n){
            // Case: all elements of arr1[] are
            // smaller than smallest (or first)
            // element of arr2
            m1 = m2;
            m2 = arr1[0];
            break;
        }

        if (arr1[i] < arr2[j]){
            m1 = m2;
            m2 = arr1[i];
            i++;
        } else {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
    }
    return (m1 + m2) /2;
}

// Problem 1: Approach 2: Divide and Conquer O(logn)

/*
 * 1) Calculate the medians m1 and m2 of the input arrays ar1[]
 * and ar2[] respectively.
 * 2) If m1 and m2 both are equal then we are done.
 * return m1 (or m2)
 * 3) If m1 is greater than m2, then median is present in one
 * of the below two subarrays.
 *      a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
 *      b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
 * 4) If m2 is greater than m1, then median is present in one
 * of the below two subarrays.
 *      a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
 *      b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
 * 5) Repeat the above process until size of both the subarrays
 * becomes 2.
 * 6) If size of the two arrays is 2 then use below formula to get
 * the median.
 * Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
 */

// helper function to get median
int median(int arr[], int n){
    if (n == 0){
        return -1;
    }
    if (n % 2==0){
        return (arr[n/2] + arr[n/2 - 1]) / 2;
    } else {
        return arr[n/2];
    }
}

int getMedianByComparing(int arr1[], int arr2[], int n){
    if (n <= 0){
        return -1;
    }
    if (n == 1){
        return (arr1[0] + arr2[0]) / 2;
    }
    if (n == 2){
        return (std::max(arr1[0], arr2[0])
                + std::min(arr1[1], arr2[1])) /2;
    }

    int m1 = median(arr1, n);
    int m2 = median(arr2, n);

    if (m1 == m2){
        return m1;
    }

    if (m1 < m2){
        if (n % 2 == 0){
            return getMedianByComparing(arr1 + n /2 - 1, arr2, n - n/2 +1);
        }
        return getMedianByComparing(arr1 + n /2, arr2, n - n /2);
    }

    if (n % 2 == 0){
        return getMedianByComparing(arr2 + n /2 -1, arr1, n - n/2 +1);
    }
    return getMedianByComparing(arr2 + n/2, arr1, n - n/2);
}

// Problem 2: two arrays with different size

// Problem 2: Approach 1: O(n)
int getMedianDifferentSizeUsingMerge(int arr1[], int arr2[], int n, int m){
    int i = 0;
    int j = 0;
    int count;
    int m1 = -1, m2 = -1;

    if ((m + n) % 2 == 1){
        for (count = 0; count <= (n + m)/2; count++){
            if (i != n && j != m){
                m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];
            } else if (i < n){
                m1 = arr1[i++];
            } else {
                // for case when j < m
                m1 = arr1[j++];
            }
        }
        return m1;
    } else {
        for (count = 0; count <= (n + m)/2; count++){
            m2 = m1;
            if (i != n && j!=m){
                m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];
            } else if ( i < n){
                m1 = arr1[i++];
            } else {
                m1 = arr1[j++];
            }
        }
        return (m1 + m2) /2;
    }
}

// Problem 2: Approach 2: O(logn) complex implementation
// @geeksforgeeks

// utility to find median of two int
float MO2(int a, int b){
    return (a + b) / 2.0;
}

// utility to find median of three int
float MO3(int a, int b, int c){
    return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

// utility to find median of four int
float MO4(int a, int b, int c, int d){
    int Max = max(a, max(b, max(c, d)));
    int Min = min(a, min(b, min(c, d)));
    return (a + b + c + d - Max - Min) / 2.0;
}

float findMedianUtil(int A[], int N, int B[], int M){
    if (N == 0){
        return median(B, M);
    }

    if (N == 1){
        if (M == 1){
            // case 1: if the larger array also has one element
            return MO2(A[0], B[0]);
        }

        if ( M & 1){
            // case two: odd number
            return MO2(B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 +1]));
        }
        // case three: even number
        return MO3(B[M/2], B[M/2 - 1], A[0]);
    } else if (N == 2){
        if (M == 2){
            // case four: m = 2 n = 2
            return MO4(A[0], A[1], B[0], B[1]);
        }
        if ( M&1){
            // case five
            return MO3(B[M/2], max(A[0], B[M/2 - 1]), min(A[1], B[M/2 + 1]));
        }
        // case six
        return MO4(B[M/2], B[M/2 -1], max(A[0], B[M/2 -2]), min(A[1], B[M/2 + 1]));
    }

    int indexA = (N - 1) / 2;
    int indexB = (M - 1) / 2;

    if (A[indexA] <= B[indexB]){
        return findMedianUtil(A + indexA, N/2 + 1, B, M - indexA);
    }
    return findMedianUtil(A, N/2 + 1, B + indexA, M - indexA);
}

float getMedianDifferentSizeByComparing(int A[], int N, int B[], int M){
    if (N > M){
        return findMedianUtil(B, M, A, N);
    }
    return findMedianUtil(A, N, B, M);
}

int main()
{
    int test1[] = {1, 12, 15, 26, 38};
    int test2[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(test1)/sizeof(test1[0]);
    int n2 = sizeof(test2)/sizeof(test2[0]);
    if (n1 == n2) {
        cout << "Median is " << getMedianUsingMerge(test1, test2, n1) << endl;
        cout << "Median is " << getMedianByComparing(test1, test2, n1) << endl;
    } else {
        cout << "Sizes are not the same. " << endl;
    }

    int ar1[] = {900};
    int ar2[] = {5, 8, 10, 20};

    int size1 = sizeof(ar1)/sizeof(ar1[0]);
    int size2 = sizeof(ar2)/sizeof(ar2[0]);
    cout << "Median is " << getMedianDifferentSizeUsingMerge(ar1, ar2, size1, size2) << endl;
    cout << "Median is " << getMedianDifferentSizeByComparing(ar1, size1, ar2, size2) << endl;
    return 0;
}
