#include<iostream>
#include<fstream>
#include"BST.h"
#include"BST.cpp"
#include"Book.h"
#include"User.h"
using namespace std;
BST<User*> users;
BST<Book> books;
BST<BookCopy> copys;
void scanFile(){
    int type;
	ifstream fin("student.txt");
	if (fin.fail()) {
		cerr << "Error opening student file.";
		exit(1);
	}

	do {
		fin >> type;
		if (type == 0) {

            Student* student = new Student();
		    fin >> *(student);
            User* user = student;
            users.insert(user);
		}
		else if( type == 1) {

            Teacher* teacher= new Teacher();

			fin >> *(teacher);
            User* user = teacher;
            users.insert(user);
        }
        else {

            Librarian* lib = new Librarian();
            fin>>*(lib);
            User* user = lib;
            users.insert(user);

        }
	} while (!fin.eof());
};


int main(){
    //Load from file
        //load into a BST
    
    //login
        //reader login
            //print reader menu
            //        


        //librarian login
            //print lib menu
                //request new book copy
                //delete existing copy
                //search users
                //add new users
                //delete old users



    //when ending, update the txt files 
    //testing code 
    BST<int> bst = BST<int>();
    bst.insert(1);
    bst.insert(3);
    bst.insert(10);
    bst.remove(1);
    bst.insert(0);
    bst.remove(3);
    int rest = *(bst.search(10));
    cout<<"search: "<<rest<<endl;
    cout<<bst.contains(10)<<endl;
    cout<<bst.contains(8);
    string s = "9781283329705";
    string s2 = "9781493938438	";
    long int isbn = stol(s);
    long int isbn2 = stol(s2);
    cout<<isbn;
    cout<<isbn2<<endl;
    cout<<(isbn<isbn2);
    //--------------------testing for file input ------------------
    users = BST<User*>();
    books = BST<Book>();
    copys = BST<BookCopy>();
    scanFile();
    User** u = users.search("James");
    Teacher* t =dynamic_cast<Teacher*>(*(u));
    t->setMax_Period(1);
}
