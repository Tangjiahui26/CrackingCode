#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int binarySearch(const vector<string>& strings, const string& str, int first, int last){
    if (first > last){
        return -1;
    }
    int mid = (first + last)/2;

    if (strings[mid].empty()){
        // find the closest non-empty string
        int left = mid - 1;
        int right = mid + 1;
        while (true){
            if (left < first && right > last){
                return -1;
            } else if (right <= last && !strings[right].empty()){
                mid = right;
                break;
            } else if (left >= first && !strings[left].empty()){
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }

    if (str.compare(strings[mid]) == 0){
        return mid;
    } else if (strings[mid].compare(str) < 0) {
        return binarySearch(strings, str, mid + 1, last);
    } else {
        return binarySearch(strings, str, first, mid -1);
    }
}

int sparseSearch(const vector<string> & strings, const string& str){
    if (strings.empty() || str.empty() || str == "") {
        return -1;
    }
    return binarySearch(strings, str, 0, strings.size() - 1);
}

int main()
{
    vector<string> strings = {"", "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    string str[] = {"at", "ball", "car", "dad"};
    for (string& s : str){
        cout << "The position of " << s << " is " << sparseSearch(strings, s) << endl;
    }
    return 0;
}
