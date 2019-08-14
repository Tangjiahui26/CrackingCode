#include <iostream>

using namespace std;

// a simple version of calculator. NO BODMAS is followed

bool isOperand(char c){
    return c >= '0' && c <= '9';
}

int value(char c) {
    return (c - '0');
}

int calculator(char* exp){
    if(*exp == '\0') {
        return INT_MIN;
    }

    int res = value(exp[0]);

    for (int i = 1; exp[i]; i += 2){
        char opr = exp[i];
        char opd = exp[i+1];

        if (!isOperand(opd)){
            return INT_MIN;
        }
        if (opr == '+'){
            res += value(opd);
        } else if (opr == '-'){
            res -= value(opd);
        } else if (opr == '*'){
            res *= value(opd);
        } else if (opr == '/'){
            res /= value(opd);
        } else {
            return INT_MIN;
        }
    }
    return res;
}

int main()
{
    char expr1[] = "1+2*5+3";
    int res1 = calculator(expr1);
    (res1 == INT_MIN) ? cout << expr1 << " is " << "INVALID\n" : cout << "Value of " << expr1 << " is " << res1 << endl;

    char expr2[] = "1++1";
    int res2 = calculator(expr2);
    (res2 == INT_MIN) ? cout << expr2 << " is " << "INVALID\n" : cout << "Value of " << expr2 << " is " << res2 << endl;
    return 0;
}

/*
 * Below is the pseudocode (JAVA) for more complex version of calculator
 *
// Term is a string parser to get the arithmetic info, like [{SUBSTRACT, 5}, {MULTIPLE, 5}..]
// Term has Operator enumerate, double value, and getNumber(), getOperator(), setNumber() APIs.
// Term also has functions to parse string and get the arithmetic sequence

double applyOp(double left, Operator op, double right){
    if(op == Operator.ADD) return left + right;
    else if (op == Operator.SUBTRACT) return left - right;
    else if (op == Operator.MULTIPLE) return left * right;
    else if (op == Operator.DIVIDE) return left / right;
    else return right;
}

Term collapseTerm(Term primary, Term secondary) {
    if(primary == null) {
    return secondary;
    }

    if(secondary == null) {
    return primary;
    }

    double value = applyOp(primary.getNumber(), secondary.getOperator(), secondary.getNumber());
    primary.setNumber(value);
    return primary;
}

double calculator(string sequence){
    list<Term> terms;
    if (terms == null) {
    return INT_MIN;
    }

    double result = 0;
    // processing variable to maintain the results of the current cluster of terms
    Term processing = null;
    for (int i = 0; i < terms.size(); i++) {
    // current variable (result)
    Term current = terms.get(i);
    Term next = i + 1 < terms.size() ? terms.get(i + 1) : null;

    processing = collapseTerm(processing, current);

    if (next == null || next.getOperator() == Operator.ADD || next.getOperator == Operator.SUBTRACT) {
        result = applyOp(result, processing.getOperator(), processing.getNumber());
        processing = null;
    }
    }
    return result;
}
