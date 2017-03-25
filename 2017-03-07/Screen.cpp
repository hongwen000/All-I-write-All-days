#include <iostream>
#include <vector>
class Screen {
    friend class Window_mgr;
    public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd, char c = ' '): height(ht), width(wd),
                                        contents(ht * wd, c) { }
        char getContent() const
            { return contents[cursor]; }
        inline char getContent(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
        Screen &set(char ch) { contents[cursor] = ch; return *this; }
        Screen &set(pos r, pos col, char ch) 
            { contents[getCursorPos(r, col)] = ch; return *this; }
        Screen &display(std::ostream &os)
            { do_display(os); return *this; }
        const Screen &display(std::ostream &os) const
            { do_display(os); return *this; }
    private:
        void do_display(std::ostream &os) const { os << contents; }
        pos getCursorPos() const { return cursor; }
        pos getCursorPos(pos r, pos c) const { return r * width + c; }
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};
inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
        ScreenIndex addScreen(const Screen&);
    private:
        std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
ScreenIndex addScreen(const Screen&)
{
    screens.push_back(s);
    return screens.size() - 1;
}
int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
    return 0;
}
