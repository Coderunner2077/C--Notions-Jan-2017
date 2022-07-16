#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
class Screen;
class Link_screen {
    //Screen window; ERREUR because Screen has incomplete type (declared but not defined)
    Link_screen *next; // a class can have data members that ara pointers (or &) to its own type
    Link_screen *prev;
    //Link_screen moi; //erreur
};
class Screen{
public:
    typedef std::string::size_type pos; // or using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos w) : height(ht), width(w), contents(ht*w, ' ') {}
    Screen(pos ht, pos w, char c) : height(ht), width(w), contents(ht*w, c) {}
    Screen &move(pos, pos);
    //member functions
    char get() const { return contents[cursor]; }
    char get(pos r, pos col) const { return contents[r*width + col]; }
    Screen& set(char);
    Screen& set(pos, pos, char);
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen& display(std::ostream &os) const { do_display(os); return *this; }
    void some_member() const;
private:
    void do_display(std::ostream &os) const { os << contents;}
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0;
};

Screen& Screen::move(pos r, pos col)
{
    cursor = r * width + col;
    return *this;
}

void Screen::some_member() const
{
    ++access_ctr;
    std::cout << access_ctr;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char c)
{
    contents[r*width + col] = c;
    return *this;
}

struct Y; //declaration obligatoire avant la définition de X qui possède un pointeur sur Y

class X {
    Y *y;
};

struct Y {
    X x;
};

#endif // SCREEN_H_INCLUDED
