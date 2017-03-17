#include <string>
class Stock
{
public:
	Stock(string symbol, string name);
	string getSymbol();
	string getName();
	double getPreviousClosingPrice();
	double getCurrentPrice();
	void setPreviousClosingPrice(double previousClosingPrice);
	void setCurrentPrice(double currentPrice);
	double changePercent();
private:
	string symbol;
	string name;
	double previousClosingPrice;
	double currentPrice;
};

Stock::Stock(string symbol, string name)
{
	Stock::symbol = symbol;
	Stock::Name = name;
}

string Stock::getSymbol()
{
	return Stock::Symbol;
}

string Stock::getName()
{
	return Stock::Name;
}

double Stock::getPreviousClosingPrice()
{
	return Stock::previousClosingPrice;
}

double Stock::getCurrentPrice()
{
	return Stock::currentPrice;
}

void Stock::setPreviousClosingPrice(double previousClosingPrice)
{
	Stock::previousClosingPrice = previousClosingPrice;
}

void Stock::setCurrentPrice(double currentPrice)
{
	Stock::currentPrice = currentPrice;
}

double Stock::changePercent()
{
	return (currentPrice-previousClosingPrice)/previousClosingPrice;
}
