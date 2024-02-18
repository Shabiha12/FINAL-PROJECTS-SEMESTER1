#include <iostream>
#include <conio.h>
#include <windows.h> 
#include <fstream>
using namespace std;


void header();
void addUser(string username, string password, string role, string usernames[], string passwords[], string roles[], int &Count);
bool signIn(string username, string password, string usernames[], string passwords[], int &Count, int &indexuser);
bool isValidusername(string username, string password, string usernames[], string passwords[], int &Count);

int loginscreen();
void exitscreen();

void admin(int &bookCount,int &selection,int &Exit,string bookTitle[],string author[],int year[],string language[], int quantity[], int price[], int max_book,string SALARY);
void salesman(int &selection,int &Exit,string salary[],int ly,string bookAmount[],int MAX_BOOK,string itemName[],string prices[],int num,int MAX_ITEM,int MAX_SALESMAN,string salesmenName[],string leavesRequested[],string reviews,string salarys);
void customer(int &selection,int &Exit,string &name,int maxSize,string Usernames[],int x,string title[],string Author[],string Price[],int BOOKCOUNT,string review,string findbook[],int n);

int adminMenu();
int salesmanMenu();
int customerMenu();
// admin features
void displaybook(int &bookCount, string bookTitle[], string author[], int year[], string language[], int quantity[], int price[],int max_book);
void addbook(int &bookCount,string bookTitle[],string author[],int year[], string language[], int quantity[], int price[],int max_book);
void editbook(int &bookCount,string bookTitle[],string author[],int year[], string language[], int quantity[], int price[]);
void deletebook(int& bookCount, string bookTitle[], string author[], int year[], string language[], int quantity[], int price[], int max_book);
void IfBookexist();
void ifBooknotExist(bool BookexistORnot);
void deleteCheck(bool deleteBook_check);

void viewitem();
void viewcart(string &name);
void logout(int maxSize,string Usernames[]);

void SALARY(string salary[],int ly);
void store(string bookAmount[],int MAX_BOOK);
void additem(string itemName[], string prices[],int num,int MAX_ITEM);
void leave(int MAX_SALESMAN,string salesmenName[],string leavesRequested[]);
int  valid();
void askitem(string findbook[], int n);
void Review(string review);
void viewReview(string reviews);
void salary(string SALARY);
void viewsalary(string salarys);
void CHECK();
void gotoxy(int x,int y);
//file handling functions
void storeNames(string usernames[], string passwords[], int &Count,string roles[]);
void add(int &bookCount, string bookTitle[],string author[],int year[], string language[], int quantity[], int price[],int max_book);
void item(string itemName[], string prices[],int num,int MAX_ITEM);
void LEAVE(int MAX_SALESMAN,string salesmenName[],string leavesRequested[]);
void readData( string usernames[], string passwords[], int ,string roles[],int &Count);
void STORE(string bookAmount[],int MAX_BOOK);

string getField(string record, int field)
{
int commaCount = 1;
string item;
for (int x = 0; x < record.length(); x++)
{
if (record[x] == ',')
{
commaCount = commaCount + 1;
}
else if (commaCount == field)
{
item = item + record[x];
}
}
return item;
}

main()
{
    //array of book titles
    int n = 5;
    string findbook[n] = {"HARRY_POTER", "STARS","HISTORICAL","SCIENCE","CHILDREN"};

    //array for user information
    string usernames[100];
    string passwords[100];
    string roles[100];
    int Count = 0; //counter for number of user
    int indexuser = 0;//index of the sign in user
    int Exit = 0;//to control program exit
    int selection;//user menu selection
    int MAX_BOOK= 3; //maximun num of book
    string bookAmount[MAX_BOOK];//array to store book amount
    int ly=1;
    string salary[ly];//array for salary 
    int MAX_ITEM = 10;//maximum number of item
    string  prices[MAX_ITEM];//array to store price
    string itemName[MAX_ITEM];//array to store item names
    int num=0;//counter for number ot items
    int MAX_SALESMAN=3;// Maximum number of salesmen
    string salesmenName[MAX_SALESMAN];// Array to store salesmen names
    string leavesRequested[MAX_SALESMAN];  // Array to store leave requests
    int maxSize = 1;  // Array to store leave requests
    string Usernames[maxSize];// Array to store usernames
    int MAX_B = 3;// Maximum number of books (another definition)
    char book[MAX_B]; // Character array for book information
    

// Arrays for book details
    int max_book= 100;
    string bookTitle[max_book];
    string author[max_book];
    int year[max_book];
    string language[max_book];
    int quantity[max_book];
    int price[max_book];
    int bookCount = 0; // Counter for the number of books
    string name; // Variable for name information

// User and role information
   string username, password;
   string role;
   // Variables for user options
   int option;
   int x = 100;
   string title[x];
   string Author[x];
   string Price[x];
   int BOOKCOUNT = 0;// Counter for the number of books
   string review;// Variable for a review
   string reviews; // Variable for reviews
   string salarys;// Variable for salary information
   string SALARY;// Another variable for salary


while (true) {
    system("cls");
    system("Color 05");
    header();
    option = loginscreen();
    system("cls");
    if (option != 3) {
        if (option == 1)
        {
            cout << "                          ENTER YOUR NAME: ";
            cin>>username;
            cout << "                          ENTER YOUR PASSWORD:";
            cin>>password;
            cout << "                          ENTER YOUR ROLE(ADMIN,SALESMAN,CUSTOMER): ";
            cin>>role;
            if (isValidusername(username, password,usernames,passwords,Count) == true)
             {
                addUser(username, password, role,usernames,passwords,roles,Count);

            }
            else  

            {
                cout << "                     USERNAME ALREADY EXIST:" << endl;
            }

        }


        else if (option == 2) {
            cout << "                          ENTER YOUR NAME: ";
            cin>>username;
            cout << "                          ENTER YOUR PASSWORD: ";
            cin>>password;
            if (signIn(username, password,usernames,passwords,Count,indexuser) == true) {
                system("cls");
                if (roles[indexuser] == "admin")
                {
                    admin(bookCount,selection,Exit,bookTitle,author,year,language,quantity,price,max_book,SALARY);
                }

                else if (roles[indexuser] == "salesman") 
                {
                    salesman(selection,Exit,salary,ly,bookAmount,MAX_BOOK,itemName,prices,num,MAX_ITEM, MAX_SALESMAN,salesmenName,leavesRequested,reviews,salarys);
                }

                else if (roles[indexuser] == "customer") 
                {
                    customer(selection,Exit,name,maxSize,Usernames,x,title,Author,Price,BOOKCOUNT,review,findbook,n);
                }

                else
                {
                    cout << "                THE NAME AND PASSWORD DOES NOT EXIST IN OUR DATABASE" << endl;
                    cout << "                PLEASE CREATE YOUR ACCOUNT" << endl;
                }

            }

            else 
            {
                cout << "                   YOU HAVE ENTERED WRONG USERNAME OR PASSWORD CORRECT IT" << endl;
            }

        }

    }

    if (Exit == 0) {
        exitscreen();
    }

    if (option == 3) {
        break;
    }
}

}

void header() {


    cout<<"                            _______  _______  _______  ___   _    __   __  __   __  _______     "<<endl;
    cout<<"                           |  _    ||       ||       ||   | | |  |  | |  ||  | |  ||  _    |    "<<endl; 
    cout<<"                           | |_|   ||   _   ||   _   ||   |_| |  |  |_|  ||  | |  || |_|   |    "<<endl;
    cout<<"                           |       ||  | |  ||  | |  ||      _|  |       ||  |_|  ||       |    "<<endl;
    cout<<"                           |  _   | |  |_|  ||  |_|  ||     |_   |       ||       ||  _   |     "<<endl;
    cout<<"                           | |_|   ||       ||       ||    _  |  |   _   ||       || |_|   |    "<<endl;
    cout<<"                           |_______||_______||_______||___| |_|  |__| |__||_______||_______|    "<<endl;
    cout<<endl <<endl;                                                                

    cout << "                          *************************************************************       " << endl;
    cout << "                          *****************    WELCOME TO LOGIN MENU    ***************       " << endl;
    cout << "                          *************************************************************       " << endl << endl;
}
//login screen
int loginscreen() {
    int option;
    cout << "                           1.SIGN UP" << endl;
    cout << "                           2.SIGN IN" << endl;
    cout << "                           3.EXIT" << endl;
    cout << "                           ENTER ANY AVAILABLE OPTION: ";
    option = valid();
    return option;

}

void exitscreen() {
    cout << "                           ENTER ANY kEY TO EXIT: ";
    getch();

}
// Function to add a new user to the system
void addUser(string username, string password, string role,string usernames[],string passwords[],string roles[],int &Count) {

    usernames[Count] = username;
    passwords[Count] = password;
    roles[Count] = role;
    Count++;
    storeNames(usernames,passwords,Count,roles);

}
// Function to sign in a user and check if the entered credentials match any existing user
// Returns:
//   true - Successful sign-in
//   false - User not found or incorrect password

bool signIn(string username, string password,string usernames[],string passwords[],int &Count,int &indexuser) {
    bool check;
    for (int i = 0;i < Count;i++) {
        if (usernames[i] == username && passwords[i] == password) {
            check = true;
            indexuser = i;
            break;
        }
        else 

        {
            check = false;
        }
    }
    return check;

}

bool isValidusername(string username, string password,string usernames[],string passwords[],int &Count) 
{
    bool check = true;
    for (int i = 0;i < Count;i++) {
        if (username == usernames[i] && password == passwords[i]) 
        {
            check = false;
            break;
        }

    }

    return check;

}
// Function to display the admin menu and get the user's choice
int adminMenu() {

    int option;
    // Display the admin menu options
    cout << "                        1.ADD BOOK" << endl;
    cout << "                        2.DISPLAY BOOKS" << endl;
    cout << "                        3.EDIT BOOK" << endl;
    cout << "                        4.DELETE BOOK" << endl;
    cout << "                        5.ADD SALARY" << endl;
    cout << "                        6.EXIT"<<endl;
    cout << "                        ENTER ANY OPTION: ";
    option = valid();
     // Return the user's choice
    return option;

}
// Function to display the salesman menu and get the user's choice
int salesmanMenu(){

    int option;
     // Display the salesman menu options
    cout<<"                         1.VIEW HIS SALARY"<<endl;
    cout<<"                         2.STORE THE BOOK PRICE RECORD"<<endl;
    cout<<"                         3.ADD ITEM:"<<endl;
    cout<<"                         4.APPLY FOR LEAVE:"<<endl;
    cout<<"                         5.VIEW REVIEW:"<<endl;
    cout<<"                         6.EXIT:"<<endl;
    cout<<"                         ENTER ANY OPTION: "<<endl;
    option = valid();
    // Return the user's choice
    return option;
    }
// Function to display the customer menu and get the user's choice
int customerMenu(){
    int option;
    // Display the customer menu options
    cout<<"                          1.VIEW ITEMS:"<<endl;
    cout<<"                          2.VIEWCART:"<<endl;
    cout<<"                          3.LOGOUT:"<<endl;
    cout<<"                          4.ASKITEM"<<endl;
    cout<<"                          5.REVIEW:"<<endl;
    cout<<"                          6.EXIT:"<<endl;
    cout<<"                          ENTER ANY OPTION: "<<endl;
    option = valid();
    // Return the user's choice
    return option;
}

void admin(int &bookCount,int &selection,int &Exit,string bookTitle[],string author[],int year[],string language[],int quantity[],int price[],int max_book,string SALARY) {

header();
cout << "                              ADMIN MENU" << endl;
Exit = 0;
selection = adminMenu();
while (selection != 6)
// function calling
 {
    system("cls");
    header();
    if (selection == 1) {
       addbook(bookCount,bookTitle, author, year,language,quantity,price, max_book);
    }

    if (selection == 2) {
      displaybook(bookCount, bookTitle, author, year, language, quantity, price,max_book);
    }

    if (selection == 3) {
       editbook(bookCount, bookTitle, author, year, language, quantity, price);
    }

    if(selection == 4){
       deletebook(bookCount, bookTitle, author, year, language, quantity, price,max_book);
    }

    if (selection == 5) {
       salary(SALARY);
    }



    exitscreen();
    system("cls");
    header();
    selection = adminMenu();


}

if (selection == 5)

{
    Exit = 1;
}

}

void salesman(int &selection,int &Exit,string salary[],int ly,string bookAmount[],int MAX_BOOK,string itemName[],string prices[],int num,int MAX_ITEM,int MAX_SALESMAN,string salesmenName[],string leavesRequested[],string reviews,string salarys)
{


header();
cout << "                        SALESMAN MENU"  <<endl  <<endl;
Exit = 0;
selection = salesmanMenu();
while (selection != 6)
// function calling
 {
    system("cls");
    header();
    if (selection == 1) {
       viewsalary(salarys);
    }

    if (selection == 2) {
      store(bookAmount,MAX_BOOK);
    }

    if (selection == 3) {
       additem(itemName,prices,num,MAX_ITEM);
    }

    if(selection == 4){
       leave(MAX_SALESMAN,salesmenName,leavesRequested);
    }

    if (selection == 5) {
       viewReview(reviews);
    }



    exitscreen();
    system("cls");
    header();
    selection = salesmanMenu();

}

if (selection == 6)

{
    Exit = 1;
}
 
}
    


void customer(int &selection,int &Exit,string &name,int maxSize,string Usernames[],int x,string title[],string Author[],string Price[],int BOOKCOUNT,string review, string findbook[],int n)

{

    header();
cout << "                                CUSTOMER MENU"  <<endl  <<endl;
Exit = 0;
selection = customerMenu();
while (selection != 6)
// function calling
{
    system("cls");
    header();
    if (selection == 1){
       viewitem();
    }
    if (selection == 2){
       viewcart(name);
    }
    if (selection == 3){
       logout(maxSize,Usernames);
    }
    if(selection == 4){
       askitem(findbook, n);
    }
    if (selection == 5){
       Review(review);
    }
    
    exitscreen();
    system("cls");
    header();
    selection = customerMenu();
}

    if (selection == 6){
    Exit = 1;

}
 
}
// Function to display the details of all books 
void displaybook(int &bookCount,string bookTitle[],string author[],int year[], string language[], int quantity[], int price[],int max_book)

{
    int x=19;
    int y=12;
    {
    cout << "                   BookTitle\\" << "Author\\" << "Year\\" << "Language\\" << "Quantity\\" << "Price\\" << endl;
    // Loop through each book and display its details
    gotoxy(x, y + 2);
    for (int i = 0; i < bookCount; i++) 
    {
       
        cout <<                  bookTitle[i] << "      " << author[i] << "       " << year[i] << "      " << language[i] << "      " << quantity[i] << "      " << price[i] << endl;
    }


}
add(bookCount,bookTitle,author,year,language,quantity,price,max_book);
}


// Function to add a new book 
void addbook(int &bookCount, string bookTitle[],string author[],int year[], string language[], int quantity[], int price[],int max_book)

{
{
    if(bookCount < max_book)
 // Get details for the new book from the user
    {
        bool isbool;
        cout<<"                        ENTER THE BOOK TITLE: ";
        getchar();
        getline(cin,bookTitle[bookCount]);
        cout<<"                        ENTER THE AUTHOR NAME: ";
        getchar();
        getline(cin,author[bookCount]);
        cout<<"                        ENTER THE YEAR: ";
        year[bookCount] = valid();
        cout<<"                        ENTER THE LANGUAGE: ";
        getchar();
        getline(cin,language[bookCount]);
        cout<<"                        ENTER THE QUANTITY: ";
        quantity[bookCount] = valid();
        cout<<"                        ENTER THE PRICE: ";
        price[bookCount] = valid();
        isbool = true;
        for (int i = 0; i < bookCount; i++)

         {
            if (bookTitle[i] == bookTitle[bookCount] && author[i] == author[bookCount]) 

            {
                isbool = false;
            }
        }

        if (isbool == true) 

        {
            bookCount++;
        }
        else

        {
            IfBookexist();
        }
    }
    else
    {
        cout<<"NEW BOOKS RECORD ADDED:\n";

    }
}
add(bookCount,bookTitle,author,year,language,quantity,price,max_book);


}
void editbook(int& bookCount, string bookTitle[], string author[], int year[], string language[], int quantity[], int price[]) 
{
    int x=19;
    int y=12;
    string book_title;
    string Author;
    cout << "              ENTER THE BOOK TITLE: ";
    getchar();
    getline(cin,book_title);
    cout << "              ENTER AUTHOR: ";
    getchar();
    getline(cin,Author);
    bool BookexistORnot = false;  // Initialize to false

    for (int i = 0; i < bookCount; i++)
    {
        if (bookTitle[i] == book_title && author[i] == Author) 
        {
            cout <<"            BookTitle\\" << "Author\\" << "Year\\" << "Language\\" << "Quantity\\" << "Price\\" << endl;
            gotoxy(x, y + 2);
            cout << bookTitle[i] << "  " << author[i] << "  " << year[i] << "  " << language[i] << "  " << quantity[i] << "  " << price[i] << endl << endl;
            
            cout << "               Enter the new book title: ";
            getchar();
            getline(cin,bookTitle[i]);
            cout << "               Enter the new author name: ";
            getchar();
            getline(cin,author[i]);
            cout << "               Enter the new year: ";
            year[i] = valid();
            cout << "               Enter the new language: ";
            getchar();
            getline(cin,language[i]);
            cout << "               Enter the new quantity: ";
            quantity[i] = valid();
            cout << "               Enter the new price: ";
            price[i] = valid();

            BookexistORnot = true;
            break;
        }
    }

    ifBooknotExist(BookexistORnot);  // Call outside the loop

    // Move the success message outside the loop
    if (BookexistORnot) 
    {
        cout << "              BOOK EDIT SUCCESSFULLY!" << endl;
    }
}

        void ifBooknotExist(bool BookexistORnot) 
{
    if (!BookexistORnot)  // Check for false condition
    {
        cout << "                NO BOOK TO EDIT." << endl;
    }
}

// Function to delete a book from the system
void deletebook(int &bookCount,string bookTitle[],string author[],int year[],string language[],int quantity[],int price[],int max_book)

{

    string book_title;
    string Author;
    cout << "                 ENTER THE NAME OF BOOK YOU WANT TO DELETE:";
    getchar();
    getline(cin,book_title);
    cout << "                 ENTER AUTHOR NAME:";
    getchar();
    getline(cin,Author);
     // Flag to check if the book to be deleted exists
    bool deleteBook_check = false;
    
    for (int i = 0; i < bookCount; i++)
       // Set the flag to true to indicate the book has been found and is to be deleted
     {
        if (bookTitle[i] == book_title && Author == author[i])
         {
            deleteBook_check = true;
            while (i < bookCount - 1)

             {

                bookTitle[i] = bookTitle[i + 1];
                author[i] = author[i + 1];
                year[i] = year[i + 1];
                language[i] = language[i + 1]; 
                quantity[i] = quantity[i + 1];
                price[i] = price[i + 1];
                i++;

            }

            bookCount = bookCount - 1;
               // Break out of the loop since the book has been deleted
            break;

        }
add(bookCount,bookTitle,author,year,language,quantity,price,max_book);
    }

    deleteCheck(deleteBook_check);

}
// Function to display a message based on whether the book was successfully deleted or not
void deleteCheck(bool deleteBook_check) 
{

    if (deleteBook_check == true) 

    {
        cout << "                The book is deleted successfully" << endl;
    }

    else 
    {
        cout << "               The book does not exist in our DATABASE" << endl;
    }

}
 // Function to view availbale item.
void viewitem()
{
// available item
    string option;
    cout<<"                          1.Historical->"<<endl;
    cout<<"                          2.Novel(Urdu)->"<<endl;
    cout<<"                          3.Novel(English)->"<<endl;
    cout<<"                          4.Children story->"<<endl;
    cout<<"                          Choose any option:"<<endl;
    getchar();
    getline(cin,option);

    if(option =="Historical" || option == "historical" || option == "1")

    {
        cout<<"Orientalism"<<endl;
        cout<<"The Guns of August"<<endl;
        cout<<"1776"<<endl;
        cout<<"Joshua"<<endl;

    }

    else if(option == "Novel(Urdu)" || option == "novel(urdu)" || option == "2")

    {

       cout<<"Peer e kamil"<<endl;
       cout<<"Jannat ka paty"<<endl;
       cout<<"Aba hayat"<<endl;
       cout<<"lahasil"<<endl;

    }

    else if(option == "Novel(English)" ||option == "novel(english)" || option == "3")

    {

        cout<<"Forty rules of love"<<endl;
        cout<<"True story"<<endl;
        cout<<"Jane eyre"<<endl;
        cout<<"To kill Mockingbird"<<endl;

    }

    else if(option == "Children story "|| option == "children story" || option == "4")

    {

        cout<<"The dead bird"<<endl;
        cout<<"Corduroy"<<endl;
        cout<<"Charlottes Web"<<endl;
        cout<<"The name jar"<<endl;

    }

    else

    {
        cout<<"REQUIRED BOOK IS OUT OF STOCK"<<endl;
    }

}
 // Function to viewcart of each category
void viewcart(string &name)

{

cout<<"WHAT YOUR NAME?"<<endl;
getchar();
getline(cin,name);

cout<<"WHICH CATEGORY DO YOU LIKE?"<<endl;

cout<<"    --------------------------------------------------------------------     "<<endl;
cout<<"    ||                                  MENU                          ||     "<<endl;
cout<<"    --------------------------------------------------------------------     "<<endl;
cout<<"    1.FICTION:                                                                 "<<endl;
cout<<" Novels                                                                        "<<endl;
cout<<" Short stories                                                                 "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    2.NON-FICTION:                                                             "<<endl;
cout<<" Biography                                                                     "<<endl;
cout<<" History                                                                       "<<endl;
cout<<" Science                                                                       "<<endl;
cout<<" Fantasy                                                                       "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    3.MAGAZINES:                                                               "<<endl;
cout<<" Lifestyle                                                                     "<<endl;
cout<<" Fashion                                                                       "<<endl;
cout<<" Technology                                                                    "<<endl;
cout<<" News                                                                          "<<endl;
cout<<" Food and Cooking                                                              "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    4.CHILDREN'S LITERATURE:                                                   "<<endl;
cout<<" Picture Books                                                                 "<<endl; 
cout<<" Middle Grade                                                                  "<<endl;
cout<<" Young Adult                                                                   "<<endl;
cout<<" Early Readers                                                                 "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    5.EDUCATIONAL:                                                             "<<endl;
cout<<" Textbooks                                                                     "<<endl;
cout<<" Reference Books                                                               "<<endl;
cout<<" Humanities                                                                    "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    6.GENRE FICTION:                                                           "<<endl;
cout<<" Mystery                                                                       "<<endl;
cout<<" Science fiction                                                               "<<endl;
cout<<" Fantasy                                                                       "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    7.POETRY:                                                                  "<<endl;
cout<<" Haiku                                                                         "<<endl;
cout<<" Sonnets                                                                       "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    8.HISTORICAL FICTION:                                                      "<<endl;
cout<<" Ancient History                                                               "<<endl;
cout<<" World Wars Era                                                                "<<endl;

cout<<"          ************************************************************         "<<endl;
cout<<"    9.SELF HELP:                                                               "<<endl;
cout<<" Personal Development                                                          "<<endl;
cout<<" Motivational                                                                  "<<endl;

cout<<"          ************************************************************         "<<endl;

}
     // Function to store the amount of each book 
void store(string bookAmount[],int MAX_BOOK)
{
{
    cout<<"                     Enter the amount of books:"<<endl;
     // Loop to input the amount of each book
    for(int i=0; i < MAX_BOOK; i++)
    {
    cout<<"                  BOOK "<<i + 1 <<":";
    getchar();
    getline(cin,bookAmount[i]);   
    }

    cout<<"                      AMOUNT OF BOOK STORED: "<<endl;
     // Loop to display the stored amounts of book
    for (int i=0; i < MAX_BOOK; i++)
    cout<<"                      BOOK " <<i + 1 <<": " <<bookAmount[i] <<endl;

}
     STORE(bookAmount,MAX_BOOK);
}
    
     // Function to add a new item to the system
void additem(string itemName[], string prices[],int num,int MAX_ITEM)
{
    {
   
   if(num < MAX_ITEM)
   {
     cout<<"                  ENTER ITEM NAME:";
     getchar();
     getline(cin,itemName[num]);
     cout<<"                  ENTER THE PRICE ";
     getchar();
     getline(cin,prices[num]);
     cout<<"                  ITEM ADDED SUCCESSFULLY!"<<endl;
     // Increment for the number of items
     num++;

   }
    item(itemName,prices,num,MAX_ITEM);


}
}
     // Function to process leave requests for salesmen
void leave(int MAX_SALESMAN,string salesmenName[],string leavesRequested[])

{
    {
    int x = 20;
    int y = 22;
     // Loop to input leave requests for each salesman
    for(int i=0; i < MAX_SALESMAN; i++)
    {

        cout<<"                     ENTER THE NAME OF SALESMAN:"<<i + 1 <<":";
      
        cin>>salesmenName[i];

        cout<<"                     LEAVES REQUESTED FOR DAYS:" <<salesmenName[i] <<":";
       
        cin>>leavesRequested[i];
        
        }      
    
        cout<<"                      LEAVES APPLICATION:"<<endl;
      
        for(int i=0; i < MAX_SALESMAN; i++)

        {
        
        cout<<salesmenName[i] <<" HAS REQUESTED " <<leavesRequested[i] <<"LEAVES." <<endl;
        }

        LEAVE(MAX_SALESMAN,salesmenName,leavesRequested);        
    }
 
}

  
     // Function to log out a user and display a message
void logout(int maxSize, string Usernames[])
{
     // Constants for formatting output
    int x = 55;
    int y = 12;

    string usernames[maxSize] = {"user1", "user2", "user3"};

        int loggeduser = -1;
        // Prompt the user to enter their username
        string user;
        cout << "                  ENTER YOUR USERNAME:" << endl;
        gotoxy(x,y+1);
        getchar();
        getline(cin,user);
        gotoxy(x, y + 2);
        cout << user;
        gotoxy(x, y + 3);
        for (int i = 0; i < maxSize; i++)
        {
            if (Usernames[i] == user)
            {
                loggeduser = i;
                break;
            }
           cout<<"    USER LOGOUT:"<<endl;
    
    }

    
}
         // Function to check if a specific book is available in a list
         void askitem(string findbook[], int n)
         // Prompt the user to enter the book they want
{
    string user;
    cout << "                        WHICH BOOK DO YOU WANT:";
    getchar();
    getline(cin,user);

    bool bookFound = false;

    for (int x = 0; x < n; x++)
    {
        if (findbook[x] == user)
        {
            // Display the available book if found
            cout << "               AVAILABLE BOOK:" << endl;
            cout << user << endl;
            bookFound = true;
            break;
        }
    }

    if (!bookFound)
    {
           // Display a message if the book is not found
        cout << "                    BOOK IS NOT AVAILABLE:" << endl;
    }
    
}
          // Function to viewReview a user and display a message
        void viewReview(string reviews){
            int x = 109;
            int y = 23;
            system("cls");
            header();
            cout<<"               REVIEW BY THE CUSTOMER:" <<endl;
            //file handling
            fstream addFile;
            addFile.open("review.txt",ios::in);
            while (!addFile.eof())
            {
                getline(addFile,reviews);
                cout<<reviews<<endl;
                addFile.close();
            // the salary can save in text file by file handling
                system("pause");
            }
        }
            // Function to view a user and display a message
        void Review(string review)

        {
           
            system("cls");
            header();
            cout<<"                        KINDLY GIVE YOUR REVIEWS:";
            getchar();
            getline(cin,review);
            //file handling
            fstream addFile;
            addFile.open("review.txt",ios::out);
            addFile<<review;
            addFile.close();
            // the review can save in text file by file handling
            system("pause");

        }
        // Function to viewsalary a user and display a message
        void viewsalary(string salarys)
        {
           
            system("cls");
            header();
            cout<<"                     SALARY OF SALESMAN:" <<endl;
            //file handling
            fstream salaryFile;
            salaryFile.open("salary.txt",ios::in);
            while (!salaryFile.eof())
            {
                getline(salaryFile,salarys);
                cout<<salarys<<endl;
                salaryFile.close();
                // the salary can save in text file by file handling
                system("pause");
            }
        }
        // Function to salary a user and display a message
        void salary(string SALARY)
        {
            system("cls");
            header();
            cout<<"                   ADD THE SALESMAN SALARY:";
            getchar();
            getline(cin,SALARY);
            fstream salaryFile;
            salaryFile.open("salary.txt", ios::out);
            salaryFile << SALARY;
            salaryFile.close();
            system("pause");
        }
//* ______ *
    int valid()
    {

    string a;
    int b = 0;
    cin>>a;
    for(int i =0; a[i]!='\0'; i++)

    {
        if(a[i]<48||a[i]>57)

        {
            cout<<"                     ENTER A VALID INPUT:";
            cin>>a;
            cin.clear();
            cin.ignore(123, '\n');
        }

    }

    b=stoi(a);
    return b; 

}
void IfBookexist() 
{
    cout << "                         THIS BOOK RECORD IS ALREADY EXIST" << endl;
}
void storeNames(string usernames[], string passwords[], int &Count,string roles[])
{
        fstream file;
        file.open("add.txt",ios::out);
        for(int idx=0;idx<Count;idx++)
        {
        file << usernames[idx];
        file << ",";
        file << passwords[idx];
        file << ",";
        file << roles[idx];
        file << "\n";
        }
        file.close();
}
void add(int &bookCount, string bookTitle[],string author[],int year[], string language[], int quantity[], int price[],int max_book)
{
        fstream file;
        file.open("yu.txt",ios::out);
        for(int idx=0;idx<bookCount;idx++)
        {
        file <<bookTitle[idx]; ;
        file << ",";
        file <<author[idx];
        file << ",";
        file << year[idx];
        file << ",";
        file << language[idx];
        file <<",";
        file <<quantity[idx];
        file <<",";
        file << price[idx];
        file <<"\n";
}

file.close();
}
    void item(string itemName[], string  prices[],int num,int MAX_ITEM)
{
        fstream file;
        file.open("add.txt",ios::out);
        for(int idx=0;idx<num;idx++)
        {
        file << itemName[idx];
        file << ",";
        file << prices[idx];
        file << "\n";

}
file.close();
}
      void LEAVE(int MAX_SALESMAN,string salesmenName[],string  leavesRequested[])
{
        fstream file;
        file.open("add.txt",ios::out);
        for(int idx=0;idx<MAX_SALESMAN;idx++)
        {
        file << salesmenName[idx];
        file << ",";
        file << leavesRequested[idx];
        file << "\n";
        }
        file.close();
        }
 void readData( string usernames[], string passwords[], int ,string roles[],int &Count)
{
        string record;
        fstream data;
        data.open("credentials.txt", ios::in);
        while (!(data.eof()))
        {
        getline(data, record);
        usernames[Count] = getField(record, 1);
        passwords[Count] = getField(record, 2);
        roles[Count] = getField(record, 3);
        Count++;
        }
}
    void STORE(string bookAmount[],int MAX_BOOK)
{
        fstream file;
        file.open("store.txt",ios::out);
        for(int idx=0;idx<MAX_BOOK;idx++)
        {
        file << bookAmount[idx];
        file << "\n";
        }
        file.close();
        }

void gotoxy(int x,int y)

{

COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}   