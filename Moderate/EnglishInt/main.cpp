#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NumberCovert {
    NumberCovert() = delete;
    static string convertEnglish(size_t number);
    static const vector<string> English[3];
public:
    static string toEnglish(size_t number);
};

const vector<string> NumberCovert::English[3] = {
    {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    },
    {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",
        "hundred"
    },
    {
        "",
        " thousand",
        " million",
        " billion",
        " trillion"
    },
};

string NumberCovert::convertEnglish(size_t number){
    if (number == 0){
        return "";
    }

    int hundreds = number / 100;
    number = number % 100;
    string words;

    if (hundreds){
        words = NumberCovert::English[0][hundreds] +
                " " + NumberCovert::English[1][10] +
                + (number ? " " : "");
    }

    if (number == 0){
        return words;
    }

    if (number < 20){
        return words + NumberCovert::English[0][number];
    }

    int tens = number / 10;
    int units = number % 10;
    if (tens){
        words += NumberCovert::English[1][tens];
    }
    if (units){
        words += (tens ? " " : "") + NumberCovert::English[0][units];
    }
    return words;
}

string NumberCovert::toEnglish(size_t number){
    if (number == 0){
        return English[0][number];
    }
    string words;
    for (int thousands = 0; number; ++thousands, number /= 1000){
        int chuck = number % 1000;
        if (chuck){
            words = NumberCovert::convertEnglish(chuck) +
                    NumberCovert::English[2][thousands] +
                    (words.size() ? " " : "") +
                    words;
        }
    }
    return words;
}

int main()
{
    vector<size_t> numbers = {3, 15, 20, 80, 109, 1809, 20977, 490001};
    for (auto n : numbers){
        cout << n << " = " << NumberCovert::toEnglish(n) << endl;
    }
    return 0;
}
