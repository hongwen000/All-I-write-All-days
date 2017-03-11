#include <iostream>
using std::endl;
class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    public:
        Sales_data() = default;
        Sales_data(const std::string &s) : bookNo(s) { }
        Sales_data(const std::string &s, unsigned n, double p) :
            bookNo(s), units_sold(n), revenue(p * n) { }
        Sales_data(std::istream &is) { read(is, *this); }
        std::string isbn() const { return bookNo; }
        Sales_data& combine(const Sales_data&);
        void transaction();
    private:
        double avg_price() const
            { return units_sold ? revenue / units_sold : 0; }
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
std::istream &read(std::istream& is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
void Sales_data::transaction()
{
    Sales_data currItem, valItem;
    if(read(std::cin, currItem)) {
        while (read(std::cin, valItem)) {
            if (valItem.isbn() == currItem.isbn())
                currItem.combine(valItem);
            else {
                print(std::cout, currItem) << endl;
                currItem = valItem;
            }
        }
        print(std::cout, currItem) << endl;
    }
    else 
        std::cerr << " Wrong Input " << endl;
}
