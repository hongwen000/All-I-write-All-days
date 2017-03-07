class Sales_data {
    public:
        std::string isbn() const { return bookNo; }
        Sales_data& combine(const Sales_data&);
        double avg_price() const;
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};
