#ifndef NAME_LOOKUP_H_INCLUDED
#define NAME_LOOKUP_H_INCLUDED
//ATTENTION, LES DEFINITIONS DE FONCTIONS NON-INLINE ET AINSI QUE CELLES DES MEMBRES STATIQUES NORMALEMENT SE FONT DANS DES
//FICHIERS .c (ou .cc, .ccp, etc.)

typedef std::string Type;
Type initVal();
Type val = "ba";

class Exercice {
public:
    typedef double Type;
    Type setVal(Type val);
    Type initVal();
    Type getVal() const { return val; }
private:
    Type val;
};

inline Exercice::Type Exercice::setVal(Type val) {
    this->val = val + initVal() + ::val.size();
    return Exercice::val;
}
//1st lookup : function
//2nd lookup : class
//3d lookup : surrounding scope (before the first apparition of the name)
inline Exercice::Type Exercice::initVal() {
    Type val = 1.0;
    return val;
}


#endif // NAME_LOOKUP_H_INCLUDED
