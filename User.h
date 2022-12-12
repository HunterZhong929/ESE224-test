#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<list>
#include"Book.h"
using namespace std;
class BookCopy;
class User{
    private:
    string password;
    string username;
    string main_key = username;
    public:
    
    string getPassword() const { return password; }
    void setPassword(const string &password_) { password = password_; }
    string getUsername() const { return username; }
    void setUsername(const string &username_) { username = username_; }
    friend std::istream& operator>>(std::istream& is, User& rhs){
        string name, password;
        is>>name>>password;
        rhs.setPassword(password);
        rhs.setUsername(name);
        return is;
    }   
    

};
class Reader:public virtual User{
    private:
    int MAX_COPIES;
    int MAX_BORROW_PERIOD;
    vector<BookCopy> borrowedList;
    int penalty;
    public:
    virtual void setMax_Copies(int n){};
    virtual void setMax_Period(int n){};

    
};
class Student:public virtual Reader{
    public:
    Student(){};
    ~Student(){};
    void setMax_Copies(int n){};
    void setMax_Period(int n){};
    friend std::istream& operator>>(std::istream& is, Student& rhs){
        string name, password;
        is>>name>>password;
        rhs.setPassword(password);
        rhs.setUsername(name);
        return is;
    }

};
class Teacher:public virtual Reader{
    public:
    Teacher(){};
    ~Teacher(){};
    void setMax_Copies(int n){};
    void setMax_Period(int n){};

    friend std::istream& operator>>(std::istream& is, Teacher& rhs){
        string name, password;
        is>>name>>password;
        rhs.setPassword(password);
        rhs.setUsername(name);
        return is;
    }

};
class Librarian:public virtual User{
    //ALL subject to change
    public:
    Librarian(){};
    ~Librarian(){};
    void addUser();
    void addBook();
    void deleteUser(); 
    void deleteBook();
    void searchUser();
    friend std::istream& operator>>(std::istream& is, Librarian& rhs){
        string name, password;
        is>>name>>password;
        rhs.setPassword(password);
        rhs.setUsername(name);
        return is;
    }
};
