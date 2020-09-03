#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <fstream>
#define MAXLEN 1000



class BigInt
{
    private:
        char digits[MAXLEN];
        int len;

    public:
        BigInt(int n = 0);
        BigInt(const char * s);
        BigInt(BigInt&);
        int getLen(){return len; }

    friend bool is0(const BigInt &);

    //assignment operator
    BigInt& operator = (const BigInt &);

    //indexing operator

    int operator [] (const int) const;

    BigInt& operator++();
    BigInt operator++(int fictional);
    BigInt& operator--();
    BigInt operator--(int fictional);

    friend BigInt operator +(const BigInt &, const BigInt &);
    friend BigInt& operator += (BigInt &, const BigInt &);

    friend BigInt operator -(const BigInt &, const BigInt &);
    friend BigInt& operator -= (BigInt &, const BigInt &);

    friend BigInt operator *(const BigInt &, const BigInt &);
    friend BigInt& operator *= (BigInt &, const BigInt &);

    friend BigInt operator /(const BigInt &, const BigInt &);
    friend BigInt& operator /= (BigInt &, const BigInt &);

    friend BigInt operator %(const BigInt &, const BigInt &);
    friend BigInt& operator %= (BigInt &, const BigInt &);

    //equality operators
    friend bool operator == (const BigInt &, const BigInt &);
    friend bool operator != (const BigInt &, const BigInt &);

    //relational operators
    friend bool operator < (const BigInt &, const BigInt &);
    friend bool operator <= (const BigInt &, const BigInt &);
    friend bool operator > (const BigInt &, const BigInt &);
    friend bool operator >= (const BigInt &, const BigInt &);

    //read / write operators

    friend std::istream& operator >>(std::istream &, BigInt &);
    friend std::ofstream& operator <<(std::ofstream &, const BigInt &);


};

#endif // BIGINT_H
