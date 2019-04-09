#include <iostream>

using namespace std;

int NOD(int a, int b)
{
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
    unsigned denominator;

public:

    RationalFractions(int numerator = 0, unsigned denominator = 1):numerator(numerator),denominator(denominator){}

    int getNum()
    {
      int a = NOD(numerator,denominator);
        return numerator/a;
       // return numerator;
    }

    unsigned getDenom()
    {
        int a = NOD(numerator,denominator);
        return denominator/a;
        //return denominator;
    }

    void setNum(int a)
    {
        numerator = a;
    }

    void setDenom(unsigned b)
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
    RationalFractions A(5,10);
    int num = A.getNum();
    unsigned denom = A.getDenom();
    cout << "Rational Fraction A is " << num <<"/"<< denom << "\n";
    RationalFractions B;
    B.setNum(7); B.setDenom(5);
    cout << "Rational Fraction B is " << B.getNum() <<"/"<< B.getDenom() << "\n";
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

