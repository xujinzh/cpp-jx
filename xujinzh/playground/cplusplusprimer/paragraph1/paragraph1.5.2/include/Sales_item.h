/**
 * This file contains code from "C++ Primer, Fifth Edition": https://www.informit.com/store/c-plus-plus-primer-9780321714114
 *
 */

/**
 * This file defines the Sales_item class used in chapter 1.
 * The code used in this file will be explained in Chapter 7(Classes) and Chapter 14(Overloaded Operators)
 */

//  we're here only if _SALES_ITEM_H_ has not yet been defined
#ifndef _SALES_ITEM_H_
#define _SALES_ITEM_H_

//  Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class Sales_item
{
    friend std::istream &operator>>(std::istream &, Sales_item &);
    friend std::ostream &operator<<(std::ostream &, const Sales_item &);
    friend bool operator<(const Sales_item &, const Sales_item &);
    friend bool operator==(const Sales_item &, const Sales_item &);

public:
    // constructor: default constructor needed to initialize members of built-in type
    Sales_item() = default;
    Sales_item(const std::string &book) : bookNo(book) {}
    Sales_item(std::istream &is) { is >> *this; }

public:
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to impolicit this pointer
    Sales_item &operator+=(const Sales_item &);
    // operations on Sales_item objects
    std::string isbn() const { return bookNo; }
    double avg_price() const;

private:
    std::string bookNo;      // implicitly initialized to the empty string
    unsigned units_sold = 0; // explicitly initialized
    double revenue = 0.0;
};

inline bool
compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item &, const Sales_item &);

inline bool
operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.isbn() == rhs.isbn();
}

inline bool
operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    // != defined in terms of operator==
    return !(lhs == rhs);
}

// assumes that both objects refer to the same ISBN
Sales_item &Sales_item::operator+=(const Sales_item &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// assumes that both objects refer to the sam ISBN
Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs)
{
    Sales_item ret(lhs); // copy (|lhs|) into a local object that we'll return
    ret += rhs;          // add in the contents of (|rhs|)
    return ret;          // return (|ret|) by value
}

std::istream &operator>>(std::istream &in, Sales_item &s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeded
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_item(); // input failed: reset object to default state

    return in;
}

std::ostream &operator<<(std::ostream &out, const Sales_item &s)
{
    out << s.isbn() << " " << s.units_sold << " " << s.revenue << " -> avg_price: " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

#endif
