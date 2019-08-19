#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// cnblogs @grandyang

// build HtWt class
class HtWt {
public:
    int Ht, Wt;
    HtWt(int h, int w) : Ht(h), Wt(w) {}

    bool isBefore(HtWt * other){
        if (Ht < other->Ht && Wt < other->Wt){
            return true;
        } else {
            return false;
        }
    }
};

bool comp(HtWt const &a, HtWt const &b){
     return a.Ht < b.Ht;
}

//vector<HtWt*> seqWithMaxLength(vector<HtWt*> seq1, vector<HtWt*> seq2){
//    if (seq1.empty()) return seq2;
//    if (seq2.empty()) return seq1;
//    return seq1.size() > seq2.size() ? seq1 : seq2;
//}

//void longestIncreasingSubsequence(vector<HtWt *> &array, vector<vector<HtWt*>> solutions, int curIndex){
//    if(curIndex >= array.size() || curIndex < 0) {
//        return;
//    }
//    HtWt* cur = array[curIndex];
//    vector<HtWt*> res;
//    for (int i = 0; i < curIndex; ++i){
//        if (array[i]->isBefore(cur)){
//            res = seqWithMaxLength(res, solutions[i]);
//        }
//    }
//    vector<HtWt*> new_solution = res;
//    new_solution.push_back(cur);
//    solutions.push_back(new_solution);
//    longestIncreasingSubsequence(array, solutions, curIndex + 1);
//}

//vector<HtWt*> longestIncreasingSubsequence(vector<HtWt*> &array){
//    vector<vector<HtWt*>> solutions;
//    longestIncreasingSubsequence(array, solutions, 0);
//    vector<HtWt*> res;
//    for (auto & a : solutions){
//        res = seqWithMaxLength(res, a);
//    }
//    return res;
//}

//vector<HtWt*> getIncreasingSequence(vector<HtWt*> &items){
//    sort(items.begin(), items.end());
//    return longestIncreasingSubsequence(items);
//}

// simple implementation here
// longestIncreasingSubsequence DP
int anotherWayUsingLIS(vector<HtWt> & a){
    sort(a.begin(), a.end(), comp);

    vector<int> f(a.size());

    f[0] = 1;

    for (int i = 1; i < a.size(); i++){
        f[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[i].Ht > a[j].Ht && a[i].Wt > a[j].Wt){
                f[i] = max(f[i], f[i] + 1);
            }
        }
    }

    int maxF = 0;
    for (int i = 0; i < f.size(); i++){
        maxF = max(maxF, f[i]);
    }

    return maxF;
}

int main()
{
    vector<HtWt> a;
    a.push_back(HtWt(65, 100));
    a.push_back(HtWt(70, 150));
    a.push_back(HtWt(56, 90));
    a.push_back(HtWt(75, 190));
    a.push_back(HtWt(60, 95));
    a.push_back(HtWt(68, 110));
    cout << anotherWayUsingLIS(a) << endl;
    return 0;
}
