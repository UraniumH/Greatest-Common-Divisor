#include <iostream>
#include <time.h>

#define llong long long
using namespace std;

//Main Functions Start
typedef struct {
    llong lcm;
    llong gcd;
} answer;

typedef answer (*FuncType)(llong a, llong b);

const string algorithmNames[4] = {
        "Euclidean",
        "Enumeration",
        "Multiplication",
        "Short Division"
};

llong calculate(llong array[], llong length, llong index, FuncType func) {
    clock_t begin, end;
    answer temp = func(array[0], array[1]);
    begin = clock();
    for (llong i = 2; i < length; i += 1) {
        temp.gcd = func(temp.gcd, array[i]).gcd;
        temp.lcm = func(temp.lcm, array[i]).lcm;
    }
    end = clock();
    cout << "Algorithm name: " << algorithmNames[index] << endl;
    cout << "Greatest Common Divisor: " << temp.gcd << endl;
    cout << "Least Common Multiplier: " << temp.lcm << endl;
    cout << "Time used: " << end - begin << endl << endl;
}

llong inputElements(llong array[]) {
    cout << "Please input the length of the array: ";
    llong n;
    cin >> n;
    cout << "Please input the elements: " << endl;
    for (llong i = 0; i < n; i += 1) {
        cin >> array[i];
    }
    return n;
}
//Main Functions End

//Recursion Starts
llong euclidean(llong a, llong b) {
    if (a % b == 0) {
        return b;
    } else {
        return euclidean(b, a % b);
    }
}

answer recursion(llong a, llong b) {
    llong temp = euclidean(a, b);
    answer ans;
    ans.gcd = temp;
    ans.lcm = (a / temp) * b;
    return ans;
}
//Recursion Ends

//Enumeration Starts
answer enumeration(llong a, llong b) {
    llong temp = 0;
    for (llong i = min(a, b); i > 0; i -= 1) {
        if (a % i == 0 && b % i == 0) {
            temp = i;
            break;
        }
    }
    answer ans;
    ans.gcd = temp;
    ans.lcm = (a / temp) * b;
    return ans;
}
//Enumeration Ends

//Multiplication Starts
answer multiplication(llong a, llong b) {
    llong temp;
    llong max = (a > b) ? a : b;
    llong min = (a < b) ? a : b;
    for (llong i = 1;; i += 1) {
        if ((max * i) % min == 0) {
            temp = max * i;
            break;
        }
    }
    answer ans;
    ans.gcd = a / (temp / b);
    ans.lcm = temp;
    return ans;
}
//Multiplication Ends

//Short Division Starts
bool coprime(llong a, llong b) {
    while (true) {
        llong t = a % b;
        if (t == 0) {
            break;
        } else {
            a = b;
            b = t;
        }
    }
    if (b > 1) {
        return false;
    } else {
        return true;
    }
}

answer shortDivision(llong a, llong b) {
    llong temp = 1;
    llong min = (a < b) ? a : b;
    while (true) {
        for (llong i = 1; i <= min; i += 1) {
            if (a % i == 0 && b % i == 0) {
                temp *= i;
                a /= i;
                b /= i;
                continue;
            }
        }
        if (coprime(a, b)) {
            break;
        }
    }
    answer ans;
    ans.gcd = temp;
    ans.lcm = temp * a * b;
    return ans;
}
//Short Division Ends

int main(int argc, char *argv[]) {
    llong arr[65536], length = 0;
    if (argc > 2) {
        length = argc - 1;
        for (llong i = 0; i < argc - 1; i += 1) {
            arr[i] = atoll(argv[i + 1]);
        }
    } else {
        length = inputElements(arr);
        if (!length >= 2) {
            cout << "Two or more numbers needed! " << endl;
            system("pause>nul");
            return 0;
        }
    }
    cout << endl;
    calculate(arr, length, 0, recursion);
    calculate(arr, length, 1, enumeration);
    calculate(arr, length, 2, multiplication);
    calculate(arr, length, 3, shortDivision);
    system("pause>nul");
    return 0;
}
