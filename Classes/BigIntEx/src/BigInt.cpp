#include "BigInt.h"
#include <string.h>
BigInt::BigInt(int n)
{
    memset(digits, 0, MAXLEN);
    len = 0;
    do{
        digits[len++] = n % 10;
        n /= 10;
    }while(n);
}

BigInt::BigInt(const char * s){
    memset(digits, 0, MAXLEN);
    len = strlen(s);
    if(len > MAXLEN) throw("OVERFLOW");
    if(len){
        for(int i = len - 1; i >= 0; i--){
            if(s[i] >= '0' && s[i] <= '9')
                digits[len - i - 1] = s[i] - '0';
            else throw("INVALID NUMBER");
        }
    }
    else{
        len = 1;
    }
}

BigInt::BigInt(BigInt& ob){
    int i;
    len = ob.len;
    memset(digits, 0 , MAXLEN);
    for(i = 0; i < len; i++){
        digits[i] = ob.digits[i];
    }
}

//checks if the bigint is null
bool is0(const BigInt& ob){
    return ob.len == 1 && ob.digits[0] == 0;
}

//assignment operator

BigInt& BigInt::operator =(const BigInt & ob){
    int i;
    if(this != &ob){
        len != ob.len;
        memset((*this).digits, 0, MAXLEN);
        for(i = 0;i < len; i++) digits[i] = ob.digits[i];
    }
    return *this;
}

//index operator

int BigInt::operator [] (const int pos) const{
    if(pos < 0 || pos >= len) throw("RANGE ERROR");
    return digits[pos];
}

//increment / decrement

BigInt & BigInt::operator ++(){
    int i;
    for(i = 0; i < len && digits[i] == 9; i++) digits[i] = 0;
    if(i == MAXLEN) throw("OVERFLOW");
    digits[i]++;
    if(i == len) len++;
}

BigInt BigInt::operator ++(int fictional){
    BigInt temp;
    temp = *this;
    ++(*this);
    return temp;
}

BigInt& BigInt::operator --(){
    int i;
    if(len == 1 && digits[0] == 0) throw("UNDERFLOW");
    for(i = 0; digits[i] == 0; i++) digits[i] = 9;
    digits[i]--;
    if(len > 1 && digits[len -1] == 0) len--;
}

BigInt BigInt::operator--(int fictional){
    BigInt temp;
    temp = *this;
    --(*this);
    return temp;
}

//equality operators
bool operator == (const BigInt & ob1, const BigInt & ob2){
    int i;
    if(ob1.len != ob2.len) return false;
    for(i = 0; i < ob1.len && ob1.digits[i] == ob2.digits[i]; i++);
    return i == ob1.len;
}

bool operator != (const BigInt & ob1, const BigInt& ob2){
    return !(ob1 == ob2);
}

//relational operators

bool operator < (const BigInt & ob1, const BigInt& ob2){
    int i;
    if(ob1.len < ob2.len) return true;
    if(ob1.len < ob2.len) return false;
    for(i = ob1.len; i >= 0 && ob1.digits[i] == ob2.digits[i]; i--);
    if(i == -1) return false;
    if(ob1.digits[i] > ob2.digits[i]) return false;
    return true;
}

bool operator > (const BigInt & ob1, const BigInt & ob2){
    return ob2 < ob1;
}

bool operator <= (const BigInt & ob1, const BigInt & ob2){
    return !(ob1 > ob2);
}

bool operator >= (const BigInt & ob1, const BigInt & ob2){
    return !(ob1 < ob2);
}

BigInt& operator += (BigInt & ob1, const BigInt & ob2){
    int t = 0, s, i;
    if(ob2.len > ob1.len) ob1.len = ob2.len;
    for(i = 0; i < ob1.len; i++){
        s = ob1.digits[i] + ob2.digits[i] + t;
        t = s / 10;
        ob1.digits[i] = s % 10;
    }
    if(t){
        if(ob1.len == MAXLEN) throw("OVERFLOW");
        ob1.digits[ob1.len++] = t;
    }
    return ob1;
}

BigInt operator +(const BigInt &ob1, const BigInt &ob2){
    BigInt temp;
    temp = ob1;
    temp += ob2;
    return temp;
}


BigInt& operator -= (BigInt & ob1, const BigInt & ob2){
    int i, t = 0, s;
    if(ob1 < ob2) throw("UNDERFLOW");
    for(i = 0; i < ob1.len; i++){
        s = ob1.digits[i] - ob2.digits[i] - t;
        t = 0;
        if(s < 0){
            s += 10;
            t = 1;
        }
        ob1.digits[i] = s;
    }
    if(ob1.len >= 1 && ob1.digits[ob1.len - 1] == 0){
        ob1.len--;
    }
    return ob1;
}

BigInt operator - (const BigInt & ob1, const BigInt & ob2){
    BigInt temp;
    temp = ob1;
    temp -= ob2;
    return temp;
}

BigInt& operator *= (BigInt & ob1, const BigInt & ob2){
    int v[MAXLEN];
    int i, j, t, s;
    memset(v, 0, sizeof(int)*MAXLEN);
    if(is0(ob1) || is0(ob2)){
        ob1 = BigInt();
        return ob1;
    }
    for(i = 0; i < ob1.len; i++){
        for(j = 0; j < ob2.len; j++){
            if(i + j > MAXLEN) throw("");
            v[i + j] += ob1.digits[i] * ob1.digits[j];
        }
    }
    for(t = i = 0; i < MAXLEN; i++){
        s  = t + v[i];
        v[i] = s % 10;
        t = s /10;
    }
    if(t) throw("OVERFLOW");
    for(ob1.len = MAXLEN; ob1.len > 1 && !v[ob1.len - 1]; ob1.len--);
    for(i = 0; i < ob1.len; i++) ob1.digits[i] = v[i];
    return ob1;
}

BigInt operator * (const BigInt & ob1, const BigInt & ob2){
    BigInt temp;
    temp = ob1;
    temp *= ob2;
    return temp;
}

BigInt & operator /= (BigInt & ob1, const BigInt & ob2){
    int q[MAXLEN], i, lq = 0, cc;
    if(is0(ob2)) throw("Division by 0");
    if(ob1 < ob2){ob1 = BigInt(); return ob1;}
    if(ob1 == ob2){ob1 = BigInt(1); return ob1;}
    BigInt t;
    for(i = ob1.len - 1; t * 10 + ob1.digits[i] < ob2; i--){
        t *= 10;
        t += ob1.digits[i];
    }

    for(;i >= 0; i--){
        t = t * 10 + ob1.digits[i];
        for(cc = 9; ob2 * cc > t; cc--);
        t -= cc * ob2;
        q[lq++] = cc;
    }
    ob1.len = lq;
    for(i = 0; i < ob1.len; i++) ob1.digits[i] = q[lq - i - 1];
    return ob1;
}

BigInt operator / (const BigInt & ob1, const BigInt & ob2){
    BigInt temp;
    temp = ob1;
    temp /= ob2;
    return temp;
}

BigInt& operator %= (BigInt & ob1, const BigInt & ob2){
    int q[MAXLEN], i, lq = 0, cc;
    if(is0(ob2)) throw("Division by 0");
    if(ob1 < ob2){return ob1;}
    if(ob1 == ob2){ob1 = BigInt(); return ob1;}
    BigInt t;
    for(i = ob1.len - 1; t * 10 + ob1.digits[i] < ob2; i--){
        t *= 10;
        t += ob1.digits[i];
    }

    for(; i >= 0; i--){
        t = t * 10 + ob1.digits[i];
        for(cc = 9; cc * ob2 > t; cc--);
        t -= cc * ob2;
        q[lq++] = cc;
    }
    while(t.len > 1 && t.digits[t.len - 1] == 0) t.len--;
    ob1 = t;
    return ob1;
}

BigInt operator % (const BigInt & ob1, const BigInt & ob2){
    BigInt temp;
    temp = ob1;
    temp %= ob2;
    return temp;
}

//read / write operators

std::istream & operator >> (std::istream & in, BigInt & ob){
    char s[MAXLEN + 1];
    in >> s;
    ob.len = strlen(s);
    if(ob.len > MAXLEN) throw("OVERFLOW");
    for(int i = ob.len - 1; i >= 0; i--) ob.digits[ob.len - 1 - i] = s[i] - '0';
    return in;
}

std::ofstream & operator << (std::ofstream & out, const BigInt & ob){
    for(int i = ob.len - 1; i >= 0; i--) out << (int)ob.digits[i];
    return out;
}

