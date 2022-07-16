#ifndef EXOS_H_INCLUDED
#define EXOS_H_INCLUDED
//ATTENTION, LES DEFINITIONS DE FONCTIONS NON-INLINE ET AINSI QUE CELLES DES MEMBRES STATIQUES NORMALEMENT SE FONT DANS DES
//FICHIERS .c (ou .cc, .ccp, etc.)

//p.291
//order of initialization
struct X {
    X(int i, int j) : base(i), rem(base / j) {} // WARNING ! rem initialized first, and base only after
    int rem, base;
};

class Book{
friend inline std::ostream& print(std::ostream&, const Book&);
friend inline std::istream& read(std::istream&, Book&);
public:
    typedef std::vector<std::string> page;
    Book(std::string titre, std::string auteur, std::string gre) : title(titre), author(auteur), genre(gre) {
         std::cout << "{titre, aut, gen}\n";}
    //delegating constructors
    Book(std::string titre) : Book(titre, "", "") {  std::cout << "{titre, , }\n";}
    Book() : Book("", "", "") {  std::cout << "{}\n";}
    Book(std::istream &is ) : Book() {  std::cout << "{cin}\n"; read(is, *this); }
private:
    std::string title;
    std::string author;
    std::string genre;
    std::string mot;
    unsigned cursor = 0;
    short nb_pages = 0;
    page courante;
    std::vector<page> contents;
};

inline std::istream& read(std::istream& is, Book& book)
{
    getline(is, book.title);
    getline(is, book.author);
    getline(is, book.genre);
    return is;
}

inline std::ostream &print(std::ostream &os, const Book &book)
{
    os  << "Title : " << book.title << "\n"
        << "Author : " << book.author << "\n"
        << "Genre : " << book.genre;
    return os;
}

//p.294
class NoDefault {
public:
    NoDefault(int nb);
    int getNombre() const { return nombre; }
private:
    int nombre = 0;
};

class C {
public:
    //C() {}
    NoDefault getMembre() const { return c_member; }
private:
    NoDefault c_member;
    //int nb = c_member.nombre;
};

//p.300
//example of an aggregate class
struct AggClass {
    int val; //not : int val = 0; !!
    std::string s;
};

/*
Unlike others classes, classes that have litteral type may have function members that are constexpr.
An aggregate class whose data members are all of litteral type is a litteral type.
A nonaggregate class, that meets the following restrictions, is a litteral class :
    -   data members all must have litteral type
    -   at least one constexpr constructor
    -   the in-class initialazers must be a constant expression or if the member is a class-type member, the initializer must
            use the member's own constexpr
    -   the class must use default definition for its destructor, which is the member that destroys objects of the class type
*/
int tourout;
struct LitClass {
    constexpr LitClass() : nb(0) { }
private:
    int nb;
};
//an example of a litteral class
class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b), nb(0) { /*just an empty body*/ }
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o), nb(0) { }
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }
private:
    bool hw;
    bool io;
    bool other;
    int nb;
    LitClass litClass;
};



#endif // EXOS_H_INCLUDED
