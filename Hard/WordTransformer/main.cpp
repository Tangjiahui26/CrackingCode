#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

// Using BFS to get the length of shortest chain

bool isOneEditAway(string& a, string& b){
    int count = 0;
    int n = a.length();

   for (int i = 0; i < n; i++)
   {
       if (a[i] != b[i]) count++;
       if (count > 1) return false;
   }
   return count == 1 ? true : false;
}

// a queue item to store word and minimum chain length to reach the word.
struct QItem{
    string word;
    int len;
};

int shortestChainLen(string& start, string& target, set<string> &D){
    queue<QItem> Q;
    QItem item = {start, 1};
    Q.push(item);

    while (!Q.empty())
    {
        QItem curr = Q.front();
        Q.pop();

        for (set<string>::iterator it = D.begin(); it != D.end(); it++)
        {
            string temp = *it;
            if (isOneEditAway(curr.word, temp))
            {
                item.word = temp;
                item.len = curr.len + 1;
                Q.push(item);


                D.erase(temp);

                // If we reached target
                if (temp == target)
                  return item.len;
            }
        }
    }
    return 0;
}

int main()
{
    set<string> D;
    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");
    string start = "toon";
    string target = "plea";
    cout << "Length of shortest chain is: "
         << shortestChainLen(start, target, D);
    return 0;
}
