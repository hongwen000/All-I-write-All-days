using std::string;
using std::endl;
class Person
{
    friend std::istream &read(std::istream& is, Person &pn);
    friend std::ostream &print(std::ostream& os, const Person &pn);
    private:
        string name;
        string address;
    public:
        Person() = default;
        Person(std::istream& is) { read(is, *this); }
        Person(const string ne, const string as) : name(ne), address(as) { }
        string getName() const { return name; }
        string getAddress() const { return address; }

};
std::istream &read(std::istream& is, Person &pn)
{
    std::cout << " Please Input Name and Address " << endl;
    is >> name >> address;
    return is;
}
std::ostream &print(std::ostream& os, const Person &pn) 
{
    os << "Name is: " << name << endl
        << " Address is: " << address << endl;
    return os;
}
