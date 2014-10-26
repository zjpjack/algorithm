/**
 *  Author: Jianping Zeng
 *  PhD Student of Computer Science and Engineering Department
 *  The University of Nebraska-Lincoln
 *  email : jizeng@cse.unl.edu
 ** /
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
 *  Euclidean Algorithm
 */
int gcdEuclidean(int x, int y) {
    return (!y)?x : gcdEuclidean(y, x%y);
}

/*
 *  Due to mod operation is too expensive for big integer.
 *  An improvement is using subtraction to replace mod.
 *  This method will have segment fault when x is extremely large,
 *  e.g. x = 10,000,000 and y = 1
 */
int gcdImprovement(int x, int y) {
    /*gcd(x,y) = gcd(y,x), this can avoid x is negative but y is
     * positive*/
    if (x < y) return gcdImprovement(y, x);
    if (y == 0)
        return x;
    else {
        return gcdImprovement(x - y, y);
    }
}

/*
 *  However, the iteration of subtraction is too much.
 *  We use bit operation to accelerate the computation.
 *  The basic idea is as following:
 *  (1) For x and y, if y = k*y1 and x = k*x1, then gcd(x,y) =
 *  k*gcd(x1, y1)
 *  (2) if x = p * x1, p is a prime number, and y%p != 0, then
 *  gcd(x,y) = gcd(p*x1, y) = gcd(x1, y)
 *  As we know, 2 is a prime number, and for big integer, we can
 *  easily transfer multiplying 2 and deviding 2 into shifting
 *  operation.
 *  This algorithm is named binary GCD algorithm.
 *  Please reference link:
 *  http://en.wikipedia.org/wiki/Binary_GCD_algorithm.
 */
bool isEven(int x) {
    if ((x & 1) != 0)
        return false;
    else {
        return true;
    }
}

int binaryGCD(int x, int y) {
    if (x < y)
        return binaryGCD(y, x);
    if (y == 0)
        return x;
    else {
        if (isEven(x)) {
            if (isEven(y)) {
                return binaryGCD(x>>1, y>>1)<<1;
            } else {
                return binaryGCD(x>>1, y);
            }
        } else {
            if (isEven(y)) {
                return binaryGCD(x, y>>1);
            } else {
                //both x and y are odd number
                return binaryGCD(y, x - y);
            }
        }
    }
}

int main(int argc, char** argv){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int res = gcdEuclidean(x, y);
    cout<<"Common divisor : "<<res<<endl;
    res = gcdImprovement(x, y);
    cout<<"Common divisor : "<<res<<endl;
    res = binaryGCD(x, y);
    cout<<"Common divisor : "<<res<<endl;
    return 0;
}
