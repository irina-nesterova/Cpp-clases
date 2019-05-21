#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int NOD(int a, int b)
{
    if (a < 0)
            a = abs(a);

    while(a > 0 && b > 0)

        if(a > b)
            a %= b;

        else
            b %= a;

    return a + b;
}

class RationalFractions
{
private:
    int numerator;
    int denominator;

public:

    RationalFractions(int numerator = 0, int denominator = 1):numerator(numerator),denominator(denominator){}

    int getNum()
    {
      int a = NOD(numerator,denominator);
        return numerator/a;
       // return numerator;
    }

    int getDenom()
    {
        int a = NOD(numerator,denominator);
        return denominator/a;
        //return denominator;
    }

    void setNum(int a)
    {
        numerator = a;
    }

    void setDenom(int b)
    {
        denominator = b;
    }


    RationalFractions RFSum(RationalFractions X, RationalFractions Y)
    {
        RationalFractions Z;
        Z.setNum(X.getNum()*Y.getDenom() + Y.getNum()*X.getDenom());
        Z.setDenom(X.getDenom()*Y.getDenom());
        return Z;
    }

    RationalFractions RFDiff(RationalFractions X, RationalFractions Y)
    {
        RationalFractions Z;
        Z.setNum(X.getNum()*Y.getDenom() - Y.getNum()*X.getDenom());
        Z.setDenom(X.getDenom()*Y.getDenom());
        return Z;
    }

    RationalFractions RFMult(RationalFractions X, RationalFractions Y)
    {
        RationalFractions Z;
        Z.setNum(X.getNum()*Y.getNum());
        Z.setDenom(X.getDenom()*Y.getDenom());
        return Z;
    }

    RationalFractions RFDiv(RationalFractions X, RationalFractions Y)
    {
        RationalFractions Z;
        Z.setNum(X.getNum()*Y.getDenom());
        Z.setDenom(X.getDenom()*Y.getNum());
        return Z;
    }

    RationalFractions RFUM(RationalFractions X)
    {
        RationalFractions Z;
        Z.setNum(-X.getNum());
        Z.setDenom(X.getDenom());
        return Z;
    }
};

int main()
{
    cout << "Input numenator and denominator of A " << "\n";
    int num_A;
    int denom_A;
    cin >> num_A >> denom_A;
    RationalFractions A(num_A,denom_A);
    cout << "Rational Fraction A is " << num_A <<"/"<< denom_A << "\n";

    cout << "Input numenator and denominator of B " << "\n";
    int num_B;
    int denom_B;
    cin >> num_B >> denom_B;
    RationalFractions B(num_B,denom_B);
    cout << "Rational Fraction B is " << num_B <<"/"<< denom_B << "\n";

    RationalFractions C;
    C = C.RFSum(A,B);
    cout << "Rational Fraction C - sum of A and B equals " << C.getNum() <<"/"<< C.getDenom() << "\n";

    RationalFractions D;
    D = D.RFDiff(A,B);
    cout << "Rational Fraction D - difference of A and B equals " << D.getNum() <<"/"<< D.getDenom() << "\n";

    RationalFractions E;
    E = E.RFMult(A,B);
    cout << "Rational Fraction E - multiplication of A and B equals " << E.getNum() <<"/"<< E.getDenom() << "\n";

    RationalFractions F;
    F = F.RFDiv(A,B);
    cout << "Rational Fraction F - division of A and B equals " << F.getNum() <<"/"<< F.getDenom() << "\n";

    RationalFractions G;
    G = G.RFUM(A);
    cout << "Rational Fraction G - unitar minus of A and equals " << G.getNum() <<"/"<< G.getDenom() << endl;

    return 0;
}
