## 图书管理系统（QT、Mysql）

### 1.1 介绍

本项目设计并实现了一个精简的多用户图书管理系统，应用后端通过与 mysql 进行连接实现对数据的管理，数据存储在本地。游客可以查阅图书信息；用户可以登陆、注册、查看图书，借书、还书等操作；管理员可以通过登陆界面实现对用户和书籍的管理，具有添加/删除用户/书籍等权限。

**详细介绍见博客链接**：[图书管理系统（QT、Mysql）](https://zhekunren.github.io/archives/2ce88c53.html)

### 1.2 运行环境介绍、配置及测试

开发平台： Windows / QT5.5.1 / MySQL5.6
上述QT和Mysql软件的安装可以参考[Mysql安装与基础使用（QT、Matlab）](/archives/4fd3c7f0.html)。
软件安装后，需要配置Mysql环境如下：
1.确认Mysql的端口使用`3306`，数据库登录的用户名和密码均设置为`root`，这些是我工程中的基本链接配置；
2.新建数据库`mydatabase`，命令为：`create database mydatabase;` ；
3.数据库`mydatabase`下新建四个表格：用户（user）、管理员（manager）、图书（book）、借阅信息（borrow）。命令为：
```bash
use mydatabase;

create table user(
id varchar(20) primary key not null,
name varchar(20) not null,
password varchar(20) not null,
canBorrow boolean not null
);

create table manager(
id varchar(20) primary key not null,
name varchar(20) not null,
password varchar(20) not null
);

create table book(
book_id varchar(20) primary key,
name varchar(20) not null,
author_name varchar(20),
price numeric(9,2),
num int not null,
stock int not null,
publisher varchar(20),
publish_year year,
type varchar(20) not null
);

create table borrow(
user_id varchar(20),
book_id varchar(20),
borrow_date date,
return_date date,
primary key(user_id,book_id),
foreign key (user_id) references user(id),
foreign key (book_id) references book(book_id)
);
```
上述表中变量的含义（按顺序）：
①用户：学号（主键），姓名，密码、借阅权限
②管理员：账号（主键），姓名，密码
③图书：书籍编号（主键），书名，作者，价格，总库存，剩余量，出版社，出版年份，分类
④借阅信息：用户学号，书籍编号，借阅时间，归还时间

4.为了测试，默认添加1个管理员，3个用户，4本书
```bash
insert into manager (id , name, password) values ("0", "管理员", "0");

insert into user (id , name, password,canBorrow) values ("1", "任哲昆", "1",true);
insert into user (id , name, password,canBorrow) values ("2", "tom", "2",true);
insert into user (id , name, password,canBorrow) values ("3", "jime", "3",false);

insert into book (book_id, name, author_name, price, num, stock, publisher, publish_year, type) 
values ("00001", "C++ Primer 中文版", "Stanley B. Lippman", 128, 10, 10, "电子工业出版社", "2013", "计算机类");
insert into book (book_id, name, author_name, price, num, stock, publisher, publish_year, type) 
values ("00002", "月光落在左手上", "余秀华", 58, 2, 2, "北京十月文艺出版社", "2020", "文学类");
insert into book (book_id, name, author_name, price, num, stock, publisher, publish_year, type) 
values ("00003", "清代地方政府", "瞿同祖", 78, 5, 5, "新星出版社", "2022", "历史类");
insert into book (book_id, name, author_name, price, num, stock, publisher, publish_year, type) 
values ("00004", "从格致到科学", "张剑", 66, 8, 8, "中国工人出版社", "2022", "哲学类");
```

5.对于exe测试，可以直接打开前面下载的工程文件下的`\EXE\LibraryManageByMysqlQt_boxed.exe`，此时没有出现`无法创建数据库连接`，则环境配置成功。
另外，对于源码，需要在`LibraryManageByMysqlQt\`文件夹下新建`debug`和`release`文件夹，并将工程构建目录选择为LibraryManageByMysqlQt下，编译源码即可运行。