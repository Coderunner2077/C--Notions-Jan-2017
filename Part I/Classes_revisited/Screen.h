#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include <vector>
//ATTENTION, LES DEFINITIONS DE FONCTIONS NON-INLINE ET AINSI QUE CELLES DES MEMBRES STATIQUES NORMALEMENT SE FONT DANS DES
//FICHIERS .c (ou .cc, .ccp, etc.)

class Screen; // declaration

//Window_mng
class Window_mng {
public:
    //location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &s);
    std::vector<Screen>::const_iterator getBegin() const { return screens.begin(); }
    std::vector<Screen>::const_iterator getEnd() const { return screens.end(); }
private:
    //std::vector<Screen> screens{Screen(24, 80, ' ')};
    std::vector<Screen> screens;
};

class Screen{
    //friend class Window_mng;
    friend void Window_mng::clear(ScreenIndex); // ==> requires careful structuring !!
public:
    typedef std::string::size_type pos; // or using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos w) : height(ht), width(w), contents(ht*w, ' ') {}
    Screen(pos ht, pos w, char c) : height(ht), width(w), contents(ht*w, c) {}
    //member functions
    Screen &move(pos, pos);
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

inline Screen& Screen::move(pos r, pos col)
{
    cursor = r * height + col;
    return *this;
}

inline void Screen::some_member() const
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
    pos index = r*height + col;
    if(index < contents.size())
        contents[index] = c;
    else
        contents += c;
    return *this;
}

inline void Window_mng::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Window_mng::ScreenIndex Window_mng::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}
//ScreenIndex Window_mng::addScreen(const Screen &s) {} // ==> ERROR because the return type appears first



#endif // SCREEN_H_INCLUDED
