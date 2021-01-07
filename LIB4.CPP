//**********************************************************
//	PROJECT : BOOK LIBRARY
//**********************************************************
//      GROUP 1: AMANDEEP KAUR & HITIKA NARANG
//**********************************************************
//	HEADER FILES
//**********************************************************

#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>

class BOOK
{
protected:
	int   bookcode, copies, avail ;
	char  bookname[26], author[26] ;
	float price ;
public :
	void list( ) ;
	char * get_bookname(int) ;
protected :
	void add_new_book(int, char[], char[], float, int, int) ;
	void modify(int, char[], char[], float) ;
	void deletion( ) ;
	void display(int) ;
	int  is_book_found(char []) ;
	void delete_rec(int) ;
	int   get_bookcode(char[]) ;
	int   get_available(int) ;
	char  * get_authorname(int) ;
	float get_bookprice(int) ;
	int   get_copies(int) ;
	void set_copies(int, int, int) ;
} ;

class MEMBER
{
	int  memcode, bookcode ;
	char memname[26], phone[11], address[31] ;
	int  dd, mm, yy ;      //date of returning
public :
	void list( ) ;
protected :
	void add_mem(int, int, char[], char[], char[], int, int, int) ;
	void modify(int, char[], char[], char[]) ;
	void display(int) ;
	int  issued(int) ;
	int  fine(int) ;
	void delete_rec(int) ;
	int  is_member_found(char[]) ;
	char * get_membername(int) ;
	int  get_membercode(char[]);
	char * get_memberphone(int) ;
	char * get_memberaddress(int) ;
	int  get_recordno(int) ;
	int  get_lastcode( ) ;
	void update_book(int, int, int, int, int) ;
} ;

class LIBRARY : public BOOK, public MEMBER
{
public :
	void issue_book( ) ;
	void return_book( ) ;
	void add_book( ) ;
	void add_member( ) ;
	void modify_book( ) ;
	void modify_member( ) ;
	void delete_book( ) ;
	void delete_member( ) ;
} ;

class DATE
{
public :
	int  day, mon, year ;
	int isLeapYear(int);
	void extend_date(int,int,int,int) ;
	int  diff(int, int, int, int, int, int) ;
} ;


void design();
void introduction();
void main_menu();
void edit_menu();
void edit_book_menu();
void edit_member_menu();
int login();

void main( )
{
	clrscr();
	design() ;
	introduction() ;
	if (login())
		main_menu();
	else
	{
		cout<<"\n\n Wrong Password .....";
		cout<<"\n\n You are NOT authenticated to login...";
		getch();
	}
}

int DATE :: isLeapYear (int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}

void DATE :: extend_date(int d1, int m1, int y1, int days)
{
	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;

	if (isLeapYear(y1))
		month[2] = 29;

	for (int i=1; i<=days; i++)
	{
		d1++ ;
		if (d1 > month[m1])
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	day  = d1 ;
	mon  = m1 ;
	year = y1 ;
}

int DATE :: diff(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int days = 0 ;

	if ((y2<y1) || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
		return days ;

	int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;

	if (isLeapYear(y1))
		month[2] = 29;

	while (d1 != d2 || m1 != m2 || y1 != y2)
	{
		days++ ;
		d1++ ;
		if ((d1 > month[m1]))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	return days ;
}

void design( )
{
  cout<<"\n\t L        i  bbbb    rrrr      A     rrrr   y     y   O      ";
  cout<<"\n\t L        I  B   B   R   R   A   A   R   R   y   y           ";
  cout<<"\n\t L        I  bbbb    rrrr    AaaaA   rrrr     y y            ";
  cout<<"\n\t L        I  B   B   R  R    A   A   R  R      y             ";
  cout<<"\n\t LLLLLLL  I  bbbb    R   R   A   A   R   R     y      O \n\t ";

  for (int i=0;i<55;i++)
   {  cout<<"_";delay(10); }
  cout<<"\n\n\n";
  cout<<"\n___    _  ___ _      _       _    _  __        _  _   _        o        __  ";
  cout<<"\n | |_||_   | |_ |\\/||_) |   |_   | | |_   |   |_ |_| |_) |\\  | | |\\  | | _  ";
  cout<<"\n | | ||_   | |_ |  ||   |__ |_   |_| |    |__ |_ | | | \\ |  \\| | |  \\| |__| o o ";

  for(int j=0;j<75;j++)
    { cout<<"x";delay(70);  }
  cout<<"\n\n\n\t\t\t PRESS ANY KEY TO CONTINUE..............";
  getch();

}
void main_menu( )
{
	LIBRARY L;
	BOOK B;
	MEMBER M;
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(29,6) ; cout <<"B O O K  L I B R A R Y" ;
		gotoxy(29,7) ; cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(30,10) ;cout <<"1. INTRODUCTION" ;
		gotoxy(30,11) ;cout <<"2. ADD NEW BOOK" ;
		gotoxy(30,12) ;cout <<"3. ADD NEW MEMBER" ;
		gotoxy(30,13) ;cout <<"4. ISSUE BOOK" ;
		gotoxy(30,14) ;cout <<"5. RETURN BOOK" ;
		gotoxy(30,15) ;cout <<"6. LIST OF BOOKS" ;
		gotoxy(30,16) ;cout <<"7. LIST OF MEMBERS" ;
		gotoxy(30,17) ;cout <<"8. EDIT" ;
		gotoxy(30,18) ;cout <<"0. QUIT" ;
		gotoxy(30,20) ;cout <<"Enter Your Choice [0-8] : " ;
		ch = getche() ;
		if (ch == '0')
			break;
		else if (ch == '1')
			introduction() ;
		else if (ch == '2')
			L.add_book() ;
		else if (ch == '3')
			L.add_member() ;
		else if (ch == '4')
			L.issue_book() ;
		else if (ch == '5')
			L.return_book() ;
		else if (ch == '6')
			B.list() ;
		else if (ch == '7')
			M.list() ;
		else if (ch == '8')
			edit_menu() ;
		else
		{
			gotoxy(30, 22);
			cout << "Invalid Choice. Press any key to continue...";
			getch();
		}
	};
}

void edit_menu( )
{
	char ch ;
	while(1)
	{      	clrscr();
		gotoxy(31,9) ; cout <<"E D I T  M E N U";
		gotoxy(31,10) ;cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. BOOKS" ;
		gotoxy(34,14) ;cout <<"2. MEMBERS" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(31,17) ;cout <<"Enter Your Choice [0-2] : " ;
		ch = getche() ;
		if (ch == '0')
			break;
		else if (ch == '1')
			edit_book_menu() ;
		else if (ch == '2')
			edit_member_menu() ;
		else
		{    	gotoxy(31, 19);
			cout << "Invalid Choice. Press any key to continue...";
			getch();
		}
	};
}

void edit_book_menu( )
{
	LIBRARY L ;
	char ch ;
	while(1)
	{      	clrscr() ;
		gotoxy(31,9) ; cout <<"E D I T  B O O K S";
		gotoxy(31,10) ;cout <<"~~~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. MODIFY" ;
		gotoxy(34,14) ;cout <<"2. DELETE" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(31,17) ;cout <<"Enter Your Choice [0-2] : " ;
		ch = getche() ;
		if (ch == '0')
			break;
		else if (ch == '1')
			L.modify_book() ;
		else if (ch == '2')
			L.delete_book() ;
		else
		{  	gotoxy(31, 19);
			cout << "Invalid Choice. Press any key to continue...";
			getch();
		}
	};
}

void edit_member_menu( )
{
	LIBRARY L;
	char ch ;
	while(1)
	{      	clrscr() ;
		gotoxy(29,9) ; cout <<"E D I T  M E M B E R S";
		gotoxy(29,10) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. MODIFY" ;
		gotoxy(34,14) ;cout <<"2. DELETE" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(29,17) ;cout <<"Enter Your Choice [0-2] : " ;
		ch = getche() ;
		if (ch == '0')
			break;
		else if (ch == '1')
			L.modify_member() ;
		else if (ch == '2')
			L.delete_member() ;
		else
		{	gotoxy(29, 19);
			cout << "Invalid choice. Press any key to continue...";
			getch();
		}
	};
}

void introduction( )
{
	clrscr() ;
	gotoxy(28,5) ;
	cout <<" WELCOME TO THE PROJECT " ;
	textcolor(BLACK+BLINK) ; textbackground(CYAN) ;
	gotoxy(30,7) ;
	cprintf(" LIBRARY MANAGEMENT ") ;
	textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
	gotoxy(15,10) ;
	cout <<"This project has facility of maintaining book records" ;
	gotoxy(15,12) ;
	cout <<"of BOOKS and MEMBERS." ;
	gotoxy(15,14) ;
	cout <<"Only one book is issued to a member at a time." ;
	gotoxy(15,16) ;
	cout <<"If he/she does not return the book within 15 days," ;
	gotoxy(15,18) ;
	cout <<"he/she is liable to pay fine of Rs.2/- per day." ;
	gotoxy(15,21) ;
	textcolor(LIGHTGRAY+BLINK) ;
	cprintf("Press any key to continue") ;
	textcolor(LIGHTGRAY) ;
	getch() ;
}

int BOOK :: is_book_found(char code_name[])
{
	fstream file ("BOOK.DAT", ios::in) ;
	int found=0, bcode = atoi (code_name);
	while (file.read((char *) this, sizeof(BOOK)))
	{       if (bookcode == bcode || strcmpi(bookname,code_name)==0)
		{   	found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}

int BOOK :: get_available(int bcode)
{
	fstream file ("BOOK.DAT", ios::in) ;
	int bavail=0 ;
	while (file.read((char *) this, sizeof(BOOK)))
	{       if (bookcode == bcode)
		{ 	bavail = avail ;
			break ;
		}
	}
	file.close() ;
	return bavail ;
}

int BOOK :: get_copies(int bcode)
{
	fstream file ("BOOK.DAT", ios::in) ;
	int bcopies ;
	while (file.read((char *) this, sizeof(BOOK)))
	{       if (bookcode == bcode)
		{ 	bcopies = copies ;
			break ;
		}
	}
	file.close() ;
	return bcopies ;
}

char *BOOK :: get_bookname(int bcode)
{
	fstream file ("BOOK.DAT", ios::in) ;
	char bname[31] ;
	while (file.read((char *) this, sizeof(BOOK)))
	{       if (bookcode == bcode)
		{ 	strcpy(bname,bookname) ;
			break ;
		}
	}
	file.close() ;
	return bname ;
}

char *BOOK :: get_authorname(int bcode)
{
	fstream file ("BOOK.DAT", ios::in) ;
	char bauthor[26] ;
	while (file.read((char *) this, sizeof(BOOK)))
	{       if (bookcode == bcode)
		{ 	strcpy(bauthor,author) ;
			break ;
		}
	}
	file.close() ;
	return bauthor ;
}

float BOOK :: get_bookprice(int bcode)
{
	fstream file ("BOOK.DAT", ios::in) ;
	float bprice ;
	while (file.read((char *) this, sizeof(BOOK)))
	{      	if (bookcode == bcode)
		{	bprice = price ;
			break ;
		}
	}
	file.close() ;
	return bprice ;
}

int BOOK :: get_bookcode(char bname[])
{
	fstream file ("BOOK.DAT", ios::in) ;
	int bcode ;
	while (file.read((char *) this, sizeof(BOOK)))
	{      	if (strcmpi(bookname,bname)==0)
		{ 	bcode = bookcode ;
			break ;
		}
	}
	file.close() ;
	return bcode ;
}

void BOOK :: delete_rec(int bcode)
{
	fstream file ("BOOK.DAT", ios::in) ;
	fstream temp ("TEMP.DAT", ios::out) ;
	while (file.read((char *) this, sizeof(BOOK)))
	{ 	if ( bookcode != bcode )
		   temp.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
	remove("BOOK.DAT");
	rename("TEMP.DAT","BOOK.DAT");
}

void BOOK :: add_new_book(int bcode,char bname[], char bauthor[], float bprice, int bcopies, int bavail)
{
	fstream file ("BOOK.DAT", ios::app) ;
	bookcode = bcode ;
	strcpy(bookname,bname) ;
	strcpy(author,bauthor) ;
	price = bprice ;
	copies = bcopies ;
	avail = bavail ;
	file.write((char *) this, sizeof(BOOK)) ;
	file.close() ;
}

void BOOK :: set_copies(int bcode, int bcopies, int bavail)
{
	fstream file ("BOOK.DAT", ios::in) ;
	fstream temp ("TEMP.DAT", ios::out) ;
	while (file.read((char *) this, sizeof(BOOK)))
	{     if ( bookcode == bcode )
		{ 	copies = bcopies ;
			avail = bavail ;
		}
		temp.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
	remove("BOOK.DAT");
	rename("TEMP.DAT","BOOK.DAT");
}

void BOOK :: modify(int bcode, char bname[], char bauthor[], float bprice)
{
	fstream file ("BOOK.DAT", ios::in) ;
	fstream temp ("temp.dat", ios::out) ;
	while (file.read((char *) this, sizeof(BOOK)) )
	{      	if ( bookcode == bcode )
		{ 	strcpy(bookname,bname) ;
			strcpy(author,bauthor) ;
			price = bprice ;
		}
		temp.write((char *) this, sizeof(BOOK)) ;
	}
	file.close() ;
	temp.close() ;
	remove("BOOK.DAT");
	rename("TEMP.DAT","BOOK.DAT");
}

void BOOK :: display(int bcode)
{
	fstream file ("BOOK.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(BOOK)))
	{       if (bookcode == bcode)
		{ 	gotoxy(5,5) ; cout <<"Book Code   : " <<bookcode ;
			gotoxy(5,7) ; cout <<"Book Name   : " <<bookname ;
			gotoxy(5,8) ; cout <<"Author Name : " <<author ;
			gotoxy(5,9) ; cout <<"Price       : Rs." <<price ;
			gotoxy(5,10) ;cout <<"Copies      : " <<copies ;
			gotoxy(5,11) ;cout <<"Available   : " <<avail ;
			break ;
		}
	}
	file.close() ;
}

void BOOK :: list( )
{
	clrscr() ;
	int row = 6, found=0,i=0;
	char ch ;
	gotoxy(32,2) ; cout <<" LIST OF BOOKS" ;
	gotoxy(32,3) ; cout <<"***************" ;
	gotoxy(1,4) ;
	cout <<"CODE  BOOK NAME                   AUTHOR               PRICE  COPIES  AVAILABLE" ;
	gotoxy(1,5) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	fstream file ("BOOK.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(BOOK)))
	{     	found = 1 ; i++;

		gotoxy(1,row) ;  cout << bookcode ;
		gotoxy(7,row) ;  cout << bookname ;
		gotoxy(35,row) ; cout << author ;
		gotoxy(56,row) ; cout << price ;
		gotoxy(65,row) ; cout << copies ;
		gotoxy(75,row) ; cout<<avail;
		row = row + 2 ;
	 }

	file.close () ;

	if (!found)
	{    gotoxy(1,row) ; cout <<"Records Not found" ;
	}
	     gotoxy(1, 24) ; cout <<"Press any key to continue..." ;
	     getch() ;
}

int MEMBER :: is_member_found(char code_name[])
{
	fstream file ("MEMBER.DAT", ios::in) ;
	int found=0 ;
	int mcode = atoi(code_name);
	while (file.read((char *) this, sizeof(MEMBER)))
	{     	if (memcode == mcode || strcmpi(memname, code_name)==0)
		{  	found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}

int MEMBER :: issued(int mcode)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	int bcode ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{      	if (memcode == mcode)
		{ 	bcode = bookcode ;
			break ;
		}
	}
	file.close() ;
	return bcode ;
}

int MEMBER :: fine(int mcode)
{
	DATE D ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	fstream file ("MEMBER.DAT", ios::in) ;
	int days, mfine ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{ 	if (memcode == mcode)
		{    	days = D.diff(dd,mm,yy,d1,m1,y1) ;
			mfine = days * 2 ;
			break ;
		}
	}
	file.close() ;
	return mfine ;
}

int MEMBER :: get_lastcode( )
{
	fstream file ("MEMBER.DAT", ios::in) ;
	int mcode=0 ;
	while (file.read((char *) this, sizeof(MEMBER)))
		mcode = memcode ;
	file.close() ;
	return mcode ;
}

char *MEMBER :: get_membername(int mcode)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	char mname[26] ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{    	if (memcode == mcode)
		{	strcpy(mname,memname) ;
			break ;
		}
	}
	file.close() ;
	return mname ;
}

int MEMBER :: get_membercode(char mname[])
{
	fstream file ("MEMBER.DAT", ios::in) ;
	int mcode;
	while (file.read((char *) this, sizeof(MEMBER)))
	{    	if (strcmpi(memname, mname)==0)
		{  	mcode = memcode;
			break ;
		}
	}
	file.close() ;
	return mcode ;
}

char *MEMBER :: get_memberphone(int mcode)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	char mphone[11] ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{      	if (memcode == mcode)
		{	strcpy(mphone,phone) ;
			break ;
		}
	}
	file.close() ;
	return mphone ;
}

char *MEMBER :: get_memberaddress(int mcode)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	char maddress[31] ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{      	if (memcode == mcode)
		{	strcpy(maddress,address) ;
			break ;
		}
	}
	file.close() ;
	return maddress ;
}

int MEMBER :: get_recordno(int mcode)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{   	count++ ;
		if (memcode == mcode)
			break ;
	}
	file.close() ;
	return count ;
}

void MEMBER :: delete_rec(int mcode)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	fstream temp ("TEMP.DAT", ios::out) ;
	while ( file.read((char *) this, sizeof(MEMBER)))
	{   	if ( memcode != mcode )
		temp.write((char *) this, sizeof(MEMBER)) ;
	}
	file.close() ;
	temp.close() ;
	remove("MEMBER.DAT");
	rename("TEMP.DAT","MEMBER.DAT");
}

void MEMBER :: update_book(int mcode, int bcode, int d1, int m1, int y1)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	fstream temp ("TEMP.DAT", ios::out) ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{    	if ( memcode == mcode )
		{ 	bookcode = bcode ;
			dd = d1 ;
			mm = m1 ;
			yy = y1 ;
		}
		temp.write((char *) this, sizeof(MEMBER)) ;
	}
	file.close() ;
	temp.close() ;
	remove("MEMBER.DAT") ;
	rename("TEMP.DAT", "MEMBER.DAT") ;
}

void MEMBER :: modify(int mcode, char mname[], char mphone[], char maddress[])
{
	fstream file ("MEMBER.DAT", ios::in) ;
	fstream temp ("TEMP.DAT", ios::out) ;
	while ( file.read((char *) this, sizeof(MEMBER)))
	{     	if ( memcode == mcode )
		{	strcpy(memname,mname) ;
			strcpy(phone,mphone) ;
			strcpy(address,maddress) ;
		}
		temp.write((char *) this, sizeof(MEMBER)) ;
	}
	file.close() ;
	temp.close() ;
	remove("MEMBER.DAT") ;
	rename("TEMP.DAT", "MEMBER.DAT") ;
}

void MEMBER :: add_mem(int mcode, int bcode, char mname[], char maddress[], char mphone[], int d1, int m1, int y1)
{
	fstream file ("MEMBER.DAT", ios::app) ;
	memcode = mcode ;
	bookcode = bcode ;
	strcpy(memname,mname) ;
	strcpy(address,maddress) ;
	strcpy(phone,mphone) ;
	dd = d1 ;
	mm = m1 ;
	yy = y1 ;
	file.write((char *) this, sizeof(MEMBER)) ;
	file.close() ;
}

void MEMBER :: display(int mcode)
{
	fstream file ("MEMBER.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{       if (memcode == mcode)
		{ 	gotoxy(5,3) ;cout <<"Member Code # " <<memcode ;
			gotoxy(5,4) ;cout <<"~~~~~~~~~~~~~~~~~" ;
			gotoxy(5,6) ;cout <<"Name    : " <<memname ;
			gotoxy(5,7) ;cout <<"Phone   : " <<phone ;
			gotoxy(5,8) ;cout <<"Address : " <<address ;
			break ;
		}
	}
	file.close() ;
}

void MEMBER :: list( )
{
	clrscr() ;

	BOOK B ;
	int row = 6, found=0;
	gotoxy(32,2) ;cout <<"LIST OF MEMBERS" ;
	gotoxy(31,3) ;cout <<"~~~~~~~~~~~~~~~~~" ;
	gotoxy(1,4) ; cout <<"CODE  NAME              PHONE          BOOK NAME (CODE)            RETURN DATE" ;
	gotoxy(1,5) ; cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	fstream file ("MEMBER.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{ 	found = 1 ;
		gotoxy(2,row) ;  cout <<memcode ;
		gotoxy(7,row) ; cout <<memname ;
		gotoxy(25,row) ; cout <<phone ;
		gotoxy(40,row) ;
		if (bookcode == 0)
		{  	cout <<"Not Issued" ;
			gotoxy(68,row); cout << "xx/xx/xxxx";
		}
		else
		{  	cout <<B.get_bookname(bookcode)<<" ("<<bookcode<<")";
			gotoxy(68,row) ; cout << dd << "/" << mm << "/" << yy ;
		}
		row += 2 ;
	}
	if (!found)
	{       gotoxy(5,10) ; cout <<"\nRecords Not Found" ;
	}
		gotoxy(1,24) ; cout <<"Press any key to continue..." ;
		getche() ;
		file.close () ;
}

void LIBRARY :: add_book( )
{
	int bcode, bcopies, bavail, found ;
	char ch, strbcode[26], bname[26], bauthor[26], strprice[10], strcopies[5] ;
	float bprice ;
	do
	{ 	found=0 ;
		clrscr() ;
		gotoxy(29,3) ; cout <<"ADDITION OF THE BOOKS" ;
		gotoxy(29,4) ; cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(72,1) ; cout <<"<0>=Exit" ;
		gotoxy(5,5) ;  cout <<"Code No: " ;
		gets(strbcode) ;
		bcode = atoi(strbcode) ;
		if (strlen(strbcode)==0)
		   return;

		if (bcode==0)
		{ 	gotoxy(5,7); cout << "Invalid Code. Press any key to continue...";
			getch();
			return ;
		}
		gotoxy(5,8) ;  cout << "Book Name   : ";
		gotoxy(5,10) ; cout << "Author Name : ";
		gotoxy(5,12);  cout << "Price       : Rs.";
		gotoxy(5,14);  cout << "Copies      :  (available)";
		gotoxy(5,16);  cout << "Copies      : " ;

		if (is_book_found(strbcode))
		{ 	found = 1;
			gotoxy(19,8) ;  cout << get_bookname(bcode);
			gotoxy(19,10) ; cout << get_authorname(bcode);
			gotoxy(19,12);  cout << get_bookprice(bcode);
			gotoxy(19,14);  cout << get_copies(bcode) << " (available)";
			gotoxy(19,16);
			gets(strcopies) ;
			bcopies = atoi(strcopies) ;
			bavail = get_available(bcode) + bcopies ;
			bcopies = get_copies(bcode) + bcopies ;
		}
		else
		{ 	gotoxy(19,8); gets(bname) ;
			strupr(bname) ;
			gotoxy(19,10); gets(bauthor) ;
			strupr(bauthor) ;
			gotoxy(22,12); gets(strprice) ;
			bprice = atof(strprice) ;
			gotoxy(5,14); cout << "Copies      : 0 (available)";
			gotoxy(19,16); gets(strcopies) ;
			bcopies = atoi(strcopies) ;
			bavail = bcopies ;
		}

		gotoxy(5,18) ; cout <<"Want to save (Y/N) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == 'Y')
		{ 	if (found)
			  set_copies(bcode,bcopies,bavail) ;
			else
			  add_new_book(bcode,bname,bauthor,bprice,bcopies,bavail) ;
		}

		gotoxy(5,20) ; cout <<"Want to add more (Y/N) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch == 'Y') ;
}

void LIBRARY :: add_member( )
{
	char ch, mname[26], mphone[11], maddress[31] ;
	int bcode, d1, m1, y1 ;
	int mcode = get_lastcode()+1 ;
	do
	{       clrscr() ;
		gotoxy(28,3) ; cout <<"ADDITION OF THE MEMBERS" ;
		gotoxy(28,4) ; cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(72,1) ; cout <<"<0>=Exit" ;
		gotoxy(5,7) ;  cout <<"Member Code # " <<mcode ;
		gotoxy(5,8) ;  cout <<"~~~~~~~~~~~~~~~~~" ;
		gotoxy(5,10) ; cout <<"Name    : " ;
		gotoxy(15,10) ;gets(mname) ;
		strupr(mname) ;
		gotoxy(5,12) ; cout <<"Phone   : " ;
		gotoxy(15,12) ;gets(mphone) ;
		gotoxy(5,14) ; cout <<"Address : ";
		gotoxy(15,14) ;gets(maddress) ;
		strupr(maddress) ;
		gotoxy(5,17) ; cout <<"Want to save (Y/N) : " ;
		ch = getche() ;
		ch = toupper(ch) ;

		if (ch == 'Y')
		{ 	bcode = 0 ;
			d1 = 0 ;
			m1 = 0 ;
			y1 = 0 ;
			add_mem(mcode,bcode,mname,maddress,mphone,d1,m1,y1) ;
			mcode++ ;
		}

		gotoxy(5,19) ; cout <<"Want to add more (Y/N) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch == 'Y') ;
}

void LIBRARY :: issue_book( )
{
	BOOK B ;
	MEMBER M ;
	DATE D ;
	char code_name[26], ch ;
	int bcode, mcode ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	clrscr() ;
	gotoxy(5,2) ; cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	gotoxy(72,1) ; cout <<"<0>=Exit" ;
	gotoxy(5,5) ;  cout <<"Enter Code or Name of the Book : " ;
	gets(code_name) ;
	if (code_name[0] == '0' || strlen(code_name) == 0)
		return ;
	if (!is_book_found(code_name))
	{  	gotoxy(5,10) ;
		cout <<"Record Not Found. Press any key to continue..." ;
		getch() ;
		return ;
	}
	bcode = atoi(code_name) ;
	if (bcode == 0)
		bcode = get_bookcode(code_name);
	if (get_available(bcode) == 0)
	{ 	gotoxy(5,10) ;
		cout <<"Sorry! Book (" <<get_bookname(bcode) <<") is not available." ;
		gotoxy(5,12) ;
		cout <<"Press any key to continue ..." ;
		getch() ;
		return ;
	}
	clrscr() ;
	gotoxy(5,2) ;  cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	gotoxy(72,1) ; cout <<"<0>=Exit" ;
	gotoxy(5,5) ;  cout << "Book Name : " << get_bookname(bcode) ;
	gotoxy(5,7) ;  cout << "Author    : " << get_authorname(bcode);
	gotoxy(5,9) ;  cout << "Price     : Rs." << get_bookprice(bcode);
	gotoxy(5,11);  cout << "Copies    : " << get_available(bcode) << " (available)";
	gotoxy(5,13) ; cout <<"Enter Code / Name of the Member: " ;
	gets(code_name) ;
	if (code_name[0] == '0' || strlen(code_name) == 0)
		return ;
	if (!is_member_found(code_name))
	{ 	gotoxy(5,15) ;
		cout <<"Record Not Found. Press any key to continue..." ;
		getch() ;
		return ;
	}

	mcode = atoi(code_name);
	if (mcode == 0)
		mcode = get_membercode(code_name);
	if (issued(mcode))
	{ 	gotoxy(5,15) ;
		cout <<"A book is already issued to " << get_membername(mcode);
		gotoxy(5,16) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		return ;
	}

	int bcopies, bavail ;
	bcopies = get_copies(bcode) ;
	bavail  = get_available(bcode) - 1 ;
	set_copies(bcode,bcopies,bavail) ;
	D.extend_date(d1,m1,y1,15) ;
	d1 = D.day ;
	m1 = D.mon ;
	y1 = D.year ;
	update_book(mcode,bcode,d1,m1,y1) ;
	gotoxy(5,15) ;
	cout <<"Book Issued to " <<get_membername(mcode) << " Successfully";
	gotoxy(5,17) ;
	cout <<"Date of Return : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	gotoxy(5,19) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}

void LIBRARY :: return_book( )
{
	MEMBER M ;
	char code_name[26], ch ;
	int mcode;
	clrscr() ;
	gotoxy(72,1) ; cout <<"<0>=Exit" ;
	struct date d;
	getdate(&d);
	int d1 = d.da_day;
	int m1 = d.da_mon;
	int y1 = d.da_year;
	gotoxy(5,2) ; cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	gotoxy(5,7) ; cout <<"Enter Code or Name of the Member : " ;
	gets(code_name) ;

	if (code_name[0] == '0' || strlen(code_name)==0)
		return ;

	if (!is_member_found(code_name))
	{ 	gotoxy(5,13) ;
		cout <<"Record Not Found / Invalid Member Code" ;
		gotoxy(5,14) ;
		cout <<"Press any key to continue..." ;
		getch() ;
		return ;
	}

	mcode = atoi(code_name);
	if (mcode == 0)
		mcode = get_membercode(code_name);

	int bcode = issued(mcode) ;

	if (bcode == 0)
	{ 	gotoxy(5,13) ; cout <<"Member has no book to return" ;
		gotoxy(5,14) ; cout <<"Press any key to continue..." ;
		getch() ;
		return ;
	}

	int bcopies, bavail ;
	gotoxy(5,13) ; cout <<"Book Code : " <<bcode ;
	gotoxy(5,14) ; cout <<"Book Name : " <<get_bookname(bcode) ;
	bcopies = get_copies(bcode) ;
	bavail = get_available(bcode) + 1 ;
	int fineAmt = fine(mcode) ;

	if (fineAmt != 0)
	{ 	gotoxy(5,16) ;
		cout <<"You have to pay a fine of Rs." << fineAmt ;
		gotoxy(5,17) ;
		cout <<"Please do not delay the Return of Book again" ;
	}
	set_copies(bcode,bcopies,bavail) ;
	update_book(mcode,0,0,0,0) ;
	gotoxy(5,19) ;
	cout <<"Book Received Successfully. Press any key to continue..." ;
	getch() ;
}

void LIBRARY :: modify_book( )
{
	BOOK B ;
	char code_name[26], bname[33], bauthor[26], strprice[10], ch ;
	int bcode ;
	float bprice ;
	clrscr() ;
	gotoxy(72,1) ; cout <<"<0>=Exit" ;
	gotoxy(5,5) ;  cout <<"Enter Code or Name of the Book : " ;
	gets(code_name) ;

	if (code_name[0] == '0' || strlen(code_name) == 0)
		return ;

	if (!is_book_found(code_name))
	{ 	gotoxy(5,10) ;
		cout <<"Record Not Found. Press any key to continue..." ;
		getch() ;
		return ;
	}
	 clrscr() ;
	 bcode = atoi(code_name) ;

	if (bcode == 0)
		bcode = get_bookcode(code_name);

	BOOK::display(bcode) ;
	gotoxy(5,16) ; cout <<"Book Name   : " ;
	gotoxy(5,17) ; cout <<"Author Name : " ;
	gotoxy(5,18) ; cout <<"Price       : Rs." ;
	gotoxy(5,25) ; cout <<"Enter Name of book or <ENTER> for no change" ;
	gotoxy(19,16) ;gets(bname) ;
	strupr(bname) ;

	if (strlen(bname) == 0)
		strcpy(bname,get_bookname(bcode)) ;
	gotoxy(5,25) ; clreol() ;
	cout <<"Enter Author's Name or <ENTER> for no change" ;
	gotoxy(19,17) ; clreol() ;
	gets(bauthor) ;
	strupr(bauthor) ;

	if (strlen(bauthor) == 0)
		strcpy(bauthor,get_authorname(bcode)) ;

	gotoxy(5,25) ; clreol() ;
	cout <<"Enter Price or <ENTER> for no change" ;
	gotoxy(22,18) ; clreol() ;
	gets(strprice) ;
	gotoxy(5,25); clreol();

	if (strlen(strprice) == 0)
		bprice = get_bookprice(bcode) ;
	else
		bprice = atof(strprice) ;

	gotoxy(5,20) ; clreol() ;
	cout <<"Want to save changes (Y/N) : " ;
	ch = getche() ;
	ch = toupper(ch) ;

	if (ch == 'Y')
	{
		BOOK::modify(bcode,bname,bauthor,bprice) ;
		gotoxy(5,23) ;
		cout <<"\nRecord Modified Successfully. Press any key to continue..." ;
		getch() ;
	}
}

void LIBRARY :: modify_member( )
{
	clrscr();
	MEMBER M ;
	char code_name[26], mname[26], mphone[11], maddress[31], ch ;
	int mcode ;
	gotoxy(72,1) ; cout <<"<0>=Exit" ;
	gotoxy(5,7) ;  cout <<"Enter Code or Name of the Member : " ;
	gotoxy(40,7) ;
	gets(code_name) ;

	if (code_name[0] == '0' || strlen(code_name)==0)
		return ;

	if (!is_member_found(code_name))
	{ 	gotoxy(5,13) ;
		cout <<"Record Not Found. Press any key to continue..." ;
		getch() ;
		return ;
	}
	clrscr() ;
	mcode = atoi(code_name) ;
	if (mcode == 0)
		mcode = get_membercode(code_name);

	MEMBER::display(mcode) ;

	gotoxy(5,13) ; cout <<"Name    : " ;
	gotoxy(5,14) ; cout <<"Phone   : " ;
	gotoxy(5,15) ; cout <<"Address : " ;
	gotoxy(5,25) ; clreol() ;
	cout <<"Enter Name of Member or <ENTER> for no change" ;
	gotoxy(15,13) ; gets(mname) ;
	strupr(mname) ;

	if (strlen(mname) == 0)
		strcpy(mname,get_membername(mcode)) ;

	gotoxy(5,25) ; clreol() ;
	cout <<"Enter Phone No. of Member or <ENTER> for no change" ;
	gotoxy(15,14) ; gets(mphone) ;

	if (strlen(mphone) == 0)
		strcpy(mphone, get_memberphone(mcode)) ;

	gotoxy(5,25) ; clreol() ;
	cout <<"Enter Address of Member or <ENTER> for no change" ;
	gotoxy(15,15) ; gets(maddress) ;
	strupr(maddress);
	gotoxy(5,25); clreol();

	if (strlen(maddress) == 0)
		strcpy(maddress, get_memberaddress(mcode)) ;

	gotoxy(5,18) ; clreol() ;
	cout <<"Want to save changes (Y/N) : " ;
	ch = getche() ;
	ch = toupper(ch) ;

	if (ch == 'Y')
	{
		MEMBER::modify(mcode,mname,mphone,maddress) ;
		gotoxy(5,23) ;
		cout <<"Record Modified Successfully. Press any key to continue..." ;
		getch() ;
	}
}

void LIBRARY :: delete_book( )
{
	BOOK B ;
	char code_name[26], bname[26], bauthor[26], ch ;
	int bcode ;
	clrscr() ;
	gotoxy(72,1) ;cout <<"<0>=Exit" ;
	gotoxy(5,5) ; cout <<"Enter Code or Name of the Book : " ;
	gets(code_name) ;
	if (code_name[0] == '0' || strlen(code_name) == 0)
		return ;

	if (!is_book_found(code_name))
	{ 	gotoxy(5,10) ;
		cout <<"Record Not Found. Press any key to continue..." ;
		getch() ;
		return ;
	}
	clrscr() ;
	bcode = atoi(code_name) ;
	if (bcode == 0)
	    bcode = get_bookcode(code_name);

	BOOK::display(bcode) ;

	gotoxy(5,13) ; clreol() ;
	cout <<"Want to delete this record (Y/N) : " ;
	ch = getche() ;
	ch = toupper(ch) ;

	if (ch == 'Y')
	{
		int bavail, bcopies ;
		bavail = get_available(bcode) ;
		bcopies = get_copies(bcode) ;
		if (bavail != bcopies)
		{ 	gotoxy(5,15) ;
			cout <<"Record cannot be deleted. This book is issued." ;
		}
		else
		{ 	BOOK::delete_rec(bcode) ;
			gotoxy(5,15) ; cout <<"Record Deleted.";
		}
	}
	gotoxy(5,17) ; cout <<"Press any key to continue..." ;
	getch() ;
}

void LIBRARY :: delete_member( )
{       MEMBER M ;
	char code_name[26], mname[26], mphone[11], maddress[31], ch ;
	int mcode ;
	clrscr() ;
	gotoxy(72,1) ; cout <<"<0>=Exit" ;
	gotoxy(5,7) ;  cout <<"Enter Code or Name of the Member : " ;
	gets(code_name) ;

	if (code_name[0] == '0' || strlen(code_name)==0)
		return ;

	if (!is_member_found(code_name))
	{  	gotoxy(5,13) ;
		cout <<"Record Not Found. Press any key to continue..." ;
		ch = getch() ;
		return ;
	}
	clrscr() ;
	mcode = atoi(code_name) ;

	if (mcode == 0)
		mcode = get_membercode(code_name);

	MEMBER::display(mcode) ;

	gotoxy(5,10) ; clreol() ;
	cout <<"Want to Delete this record (Y/N) : " ;
	ch = getche() ;
	ch = toupper(ch) ;

	if (ch == 'N')
		return ;

	if (issued(mcode))
	{
		gotoxy(5,15) ;
		cout <<"Record cannot be deleted because a book is issued to him." ;
	}
	else
	{	MEMBER::delete_rec(mcode) ;
		gotoxy(5,23) ; cout <<"Record Deleted Successfully." ;
	}
	gotoxy(5,17) ; cout << "Press any key to continue...";
	getch() ;
}

int login()
{       clrscr();
	char mypwd[25]="library",str[25]="";
	char ch;
	int i=0;
	gotoxy(25,9) ; cout<<" Enter The Password : ";
	while(ch!='\r')
	{	ch=getch();
		cout<<"*";
		str[i]=ch;
		i++;
	}
	str[i-1]='\0';
	if(strcmp(mypwd,str)!=0)
		return 0;
	else
		return 1;
}
