# 1 "2.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "2.h"
# 10 "2.h"
    QString isbn() const { return m_isbn; } void setIsbn(const isbn& _isbn) { m_isbn = _isbn; emit isbnChanged(); }
    QString bookName() const { return m_bookName; } void setBookName(const bookName& _bookName) { m_bookName = _bookName; emit bookNameChanged(); }
    QString author() const { return m_author; } void setAuthor(const author& _author) { m_author = _author; emit authorChanged(); }
    QDate publishDate() const { return m_publishDate; } void setPublishDate(const publishDate& _publishDate) { m_publishDate = _publishDate; emit publishDateChanged(); }
    int totalStock() const { return m_totalStock; } void setTotalStock(const totalStock& _totalStock) { m_totalStock = _totalStock; emit totalStockChanged(); }
    int avaiStock() const { return m_avaiStock; } void setAvaiStock(const avaiStock& _avaiStock) { m_avaiStock = _avaiStock; emit avaiStockChanged(); }
    int borrowedNum() const { return m_borrowedNum; } void setBorrowedNum(const borrowedNum& _borrowedNum) { m_borrowedNum = _borrowedNum; emit borrowedNumChanged(); }
    QVariantList borrower() const { return m_borrower; } void setBorrower(const borrower& _borrower) { m_borrower = _borrower; emit borrowerChanged(); }
    QVariantList borrowDate() const { return m_borrowDate; } void setBorrowDate(const borrowDate& _borrowDate) { m_borrowDate = _borrowDate; emit borrowDateChanged(); }
