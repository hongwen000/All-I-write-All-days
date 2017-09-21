#define DEF_PROPERTY_IMPL(type, propertyName, PropertyName)  \
    type propertyName() const {                \
        return m_##propertyName;               \
    }                                          \
     \
    void set##PropertyName(const propertyName& _##propertyName) {\
        m_##propertyName = _##propertyName;    \
        emit propertyName##Changed();          \
    }
    DEF_PROPERTY_IMPL(QString,isbn,Isbn)
    DEF_PROPERTY_IMPL(QString,bookName,BookName)
    DEF_PROPERTY_IMPL(QString,author,Author)
    DEF_PROPERTY_IMPL(QDate,publishDate,PublishDate)
    DEF_PROPERTY_IMPL(int,totalStock, TotalStock)
    DEF_PROPERTY_IMPL(int,avaiStock,AvaiStock)
    DEF_PROPERTY_IMPL(int,borrowedNum,BorrowedNum)
    DEF_PROPERTY_IMPL(QVariantList,borrower,Borrower)
    DEF_PROPERTY_IMPL(QVariantList,borrowDate,BorrowDate)
