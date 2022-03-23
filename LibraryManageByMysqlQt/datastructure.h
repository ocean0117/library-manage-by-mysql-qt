#ifndef DATASTRUCTURE
#define DATASTRUCTURE

#include <QVector>
class People{
public:
    /*
    三种人员权限说明：
    0 MANAGER 检索图书，图书入库出库，给予用户权限
    1 USER 检索图书，借书还书
    2 VISITOR 检索图书
    */
    enum { MANAGER, USER, VISITOR};
    QString user_Name;
    QString user_ID;
    QString user_Password;
    bool user_canBorrow;
    int booknum;
    int user_Type;//人员的类型: MANAGER, USER, VISITOR
};

class Book {
public:
    QString book_id;
    QString name;
    QString author_name;
    double price;
    int num;
    int stock;
    QString publisher;
    QString publish_year;
    QString type;
};

class BookQuery {
public:
    QString book_id;
    QString name;
    QString author_name;
    int begin_year;
    int end_year;
    QString publisher;
    double low_price;
    double high_price;
    bool have_stock;
    QString type;
};

class BorrowBook {
public:
    Book book;
    QString userID;
    QString dateBorrow;
    QString dateReturn;
};

class UserDetial{
public:
    People user;
    QVector<BorrowBook> borrowbook;
};

class BorrowUser {
public:
    People user;
    QString dateBorrow;
    QString dateReturn;
};

class BookDetial{
public:
    Book book;
    QVector<BorrowUser> user;
};

const QString booktype[] = {"文学类","艺术类","自然科学类","计算机类","思政类","经济类","哲学类","军体类",
                        "医学类","工业技术","环境科学类","历史类","地理类"};

#endif // DATASTRUCTURE

