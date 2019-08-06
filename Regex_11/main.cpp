#include <iostream>
#include <regex>

using namespace std;

int main()
{
    string str = "test@gmail.com; test2@yahoo.com ;; test3@qq.com";
    regex e("([[:w:]]+)@([[:w:]]+)\.com");
//    regex e("([[:w:]]+)@([[:w:]]+)\.com", regex_constants::grep|regex_constants::icase);


    sregex_iterator pos(str.cbegin(), str.cend(), e);
    sregex_iterator end;

    for (;pos!=end;pos++){
        cout << "Matched: " << pos->str(0) << endl;
        cout << "User name: " << pos->str(1) << endl;
        cout << "Domain: " << pos->str(2) << endl;
        cout << endl;
    }
    cout << "===================\n\n";

    // extra argument to specify which part you want to match
    sregex_token_iterator post(str.cbegin(), str.cend(), e, 1);
    sregex_token_iterator endt;

    for (;post!=endt;post++){
        cout << "Matched: " << post->str() << endl;
        cout << endl;
    }
    cout << "===================\n\n";

    cout << regex_replace(str, e, "$1 is on $2", regex_constants::format_no_copy) << endl;
    cout << regex_replace(str, e, "$1 is on $2", regex_constants::format_no_copy|regex_constants::format_first_only) << endl;
    cin >> str;
    return 0;
}
