#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef map<string, int> StrIntMap;

void countWords(istream& in, StrIntMap& words){
    string s;
    while (in >> s){
        ++words[s];
    }
}

int main(int argc, char** argv)
{
    if (argc < 2){
        return(EXIT_FAILURE);
    }
    ifstream in(argv[1]);

    if (!in){
        return(EXIT_FAILURE);
    }

    StrIntMap w;
    countWords(in, w);

    for (StrIntMap::iterator p = w.begin(); p != w.end(); ++p){
        cout << p->first <<" occurred " << p->second << " times" << endl;
    }
    return 0;
}
