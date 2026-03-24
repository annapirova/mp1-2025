#include <iostream> 
using namespace std; 
 
class Drobi {
public:     

    int chis;
    int znam;
    
    Drobi(int c = 0, int z = 1) : chis(c), znam(z) {}
    
    Drobi operator+(const Drobi& dd) const {
        int c, z;
        c = chis * dd.znam + dd.chis * znam;
        z = dd.znam * znam;
        return Drobi(c, z);
    }
    
    Drobi& operator=(const Drobi& dd) {
        chis = dd.chis;
        znam = dd.znam;
        return *this;
    }
    
    Drobi& operator+=(const Drobi& dd) {
        int c, z;
        c = chis * dd.znam + dd.chis * znam;
        z = dd.znam * znam;
        this->chis = c;
        this->znam = z;
        return *this;
    }
    
    Drobi operator-(int k) {
        const Drobi d2(k);
        int c, z;
        c = chis * d2[1] - d2[0] * znam;
        z = znam * d2[1];
        return Drobi(c, z);
    }
    
    void print() {
        std::cout << chis << "/" << znam << "\n";
    }
    
    bool operator==(const Drobi& d2) const {
        return ((chis == d2.chis) && (znam == d2.znam)) ? true : false;
    }
    
    int& operator[](size_t i) {
        if (i == 0)
            return chis;
        else return znam;
    }
    
    const int& operator[](size_t i) const {
        if (i == 0)
            return chis;
        else return znam;
    }
    
    // префиксный ++, ++d
    Drobi& operator++() {
        chis += znam;
        return *this;
    }

    // постфиксный ++, d++
    Drobi operator++(int) {
        Drobi x(chis + znam, znam);
        return x;
    }

    int& operator()(int i, int j) {
        return chis;
    }


/*    friend Drobi operator-(const Drobi& d1, const Drobi& d2);
    friend operator-(int k, const Drobi& d2);
    friend ostream& operator<<(ostream& s, const Drobi& d);
    */
};


Drobi operator-(const Drobi& d1, const Drobi& d2) {
        int c, z;
        c = d1.chis * d2.znam - d2.chis * d1.znam;
        z = d1.znam * d2.znam;
        return Drobi(c, z);
    }

Drobi operator-(int k, const Drobi& d2) {
    Drobi d1(k);
        int c, z;
        c = d1.chis * d2.znam - d2.chis * d1.znam;
        z = d1.znam * d2.znam;
        return Drobi(c, z);
    }

  ostream& operator<<(ostream& s, const Drobi& d)
  {
      s << d.chis << "/" << d.znam;
      return s;
  }

// type of cin is basic_istream<char> 
  istream& operator>>(istream& s,  Drobi& d)
  {
      s >> d.chis >> d.znam;
      return s;
  }
 
int main() 
{ 
   Drobi d(3, 5), d2(1, 4), d3;
   
   Drobi z = ++d;
   Drobi z1 = ++d;
   
   cout << z << " " << z1 << " " << d;

   d(1, 1);

   d3 = d - d2;

   //d3.operator=(d.operator-(d2));

   return 0; 
}