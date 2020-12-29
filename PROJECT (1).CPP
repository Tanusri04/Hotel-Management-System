#include<fstream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class hotel
{
	int rno,tariff;
	char type[7];
	public:
	int nod;
	char doc[20],name[20],email[30],mobile[15],ssno[10];
	hotel()
	{
		name[0]='\0';
		doc[0]='\0';
		nod=0;
		mobile[0]='\0';
		ssno[0]='\0';
		email[0]='\0';
	}
	void input2()
	{
		cout<<"Name                     : ";gets(name);
		cout<<"Email Id                 : ";gets(email);
		cout<<"Mobile number            : ";gets(mobile);
		cout<<"Check in Date(DD-MM-YYYY): ";gets(doc);
		cout<<"Social Security no.      : ";gets(ssno);
		cout<<"Number of Days           : ";cin>>nod;
	}
	void input1()
	{
		cout<<"Room number             : ";cin>>rno;
		cout<<"Type(SB/DB/SUITE/DUPLET): ";gets(type);
		cout<<"Tariff                  : ";cin>>tariff;
	}
	void moditariff()
	{
		cout<<"New Tariff     : ";cin>>tariff;
	}
	void modinod()
	{
		cout<<"New number of days: ";cin>>nod;
	}
	void modidoc()
	{
		cout<<"New date of checkin: ";gets(doc);
	}
	void moditype()
	{
		cout<<"New room type: ";gets(type);
	}
	void output()
	{
		cout<<setw(4)<<rno<<setw(7)<<type<<setw(8)<<tariff<<
		setw(10)<<name<<setw(14)<<email<<setw(11)<<mobile<<
		setw(7)<<ssno<<setw(11)<<doc<<setw(4)<<nod<<endl<<endl;
	}
	int rtariff()
	{
		return tariff;
	}
	int rrno()
	{
		return rno;
	}
	char* rtype()
	{
		return type;
	}
	void empty()
	{
		name[0]='\0';
		email[0]='\0';
		nod=0;
		mobile[0]='\0';
		ssno[0]='\0';
		doc[0]='\0';
	}
};

void enter2()
{		
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in|ios::out);
	char ch[7];
	hotel a;
	int found=0;
	cout<<"Enter the room type(sb/db/duplet/suite): ";gets(ch);
	while(f.read((char*)&a,sizeof(a)))
	{
		if(strcmpi(a.rtype(),ch)==0 && found==0)
		if(strcmpi(a.name,'\0')==0)
		{
			cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(7)
			<<"Tariff"<<setw(10)<<"Name"<<setw(15)<<"Email"
			<<setw(11)<<"Mobile"<<setw(7)<<"Ssno"<<setw(11)
			<<"DoCheckin"<<setw(4)<<"nod"<<endl;
			a.output();
			a.input2();
			f.seekp(f.tellg()-sizeof(a));
			f.write((char*)&a,sizeof(a));
			cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(7)<<
			"Tariff"<<setw(10)<<"Name"<<setw(15)<<"Email"<<
			setw(11)<<"Mobile"<<setw(7)<<"Ssno"<<setw(11)
			<<"DoCheckin"<<setw(4)<<"nod"<<endl;
			a.output();
			found++;
		}
	}
	if(!found)
		cout<<"::Sorry,no room with this type available::"<<endl;
	f.close();
}

void searchbyname()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in);
	char ch[20];
	hotel a;
	cout<<"Enter name: ";gets(ch);
	while(f.read((char*)&a,sizeof(a)))
	{
		if(strcmpi(a.name,ch)==0)
		{
			cout<<"Room No.: "<<a.rrno()<<endl;
		}
	}
	f.close();
}

void modifyTariff()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in|ios::out);
	int rno, modi=0;
	hotel a;
	cout<<"Enter the room number: ";cin>>rno;
	while(!modi && f.read((char*)&a,sizeof(a)))
	{
		if(a.rrno()==rno)
		{
			a.moditariff();
			f.seekp(f.tellg()-sizeof(a));
			f.write((char*)&a,sizeof(a));
			cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(8)
			<<"Tariff"<<setw(10)<<"Name"<<setw(14)<<"Email"<<
			setw(11)<<"Mobile"<<setw(7)<<"Ssno"<<setw(11)
			<<"DoCheckin"<<setw(4)<<"nod"<<endl<<endl;
			a.output();
			modi++;
		}
	 }
	 if(!modi)
	  cout<<"No record found..."<<endl;
	f.close();
}

void modifynod()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in|ios::out);
	int rno, modi=0;
	hotel a;
	cout<<"Enter the room number: ";cin>>rno;
	while(!modi && f.read((char*)&a,sizeof(a)))
	{
		if(a.rrno()==rno)
		{
			a.modinod();
			f.seekp(f.tellg()-sizeof(a));
			f.write((char*)&a,sizeof(a));
			cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(8)
			<<"Tariff"<<setw(10)<<"Name"<<setw(14)<<"Email"<<
			setw(11)<<"Mobile"<<setw(7)<<"Ssno"<<setw(11)
			<<"DoCheckin"<<setw(4)<<"nod"<<endl<<endl;
			a.output();
			modi++;
		}
	 }
	 if(!modi)
	  cout<<"Record not found..."<<endl;
	f.close();
}

void modifytype()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in|ios::out);
	int rno,modi=0;
	hotel a;
	cout<<"Enter the room number: ";cin>>rno;
	while(!modi && f.read((char*)&a,sizeof(a)))
	{
		if(a.rrno()==rno)
		{
			a.moditype();
			f.seekp(f.tellg()-sizeof(a));
			f.write((char*)&a,sizeof(a));
			cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(8)
			<<"Tariff"<<setw(10)<<"Name"<<setw(14)<<"Email"<<
			setw(11)<<"Mobile"<<setw(7)<<"Ssno"<<setw(11)
			<<"DoCheckin"<<setw(4)<<"nod"<<endl<<endl;
			a.output();
			modi++;
		}
	}
		if(!modi)
			cout<<"Record not found..."<<endl;
	f.close();
}

void modifydoc()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in|ios::out);
	int rno,modi=0;
	hotel a;
	cout<<"Enter the room number: ";cin>>rno;
	while(!modi && f.read((char*)&a,sizeof(a)))
	{
		if(a.rrno()==rno)
		{
			a.modidoc();
			f.seekp(f.tellg()-sizeof(a));
			f.write((char*)&a,sizeof(a));
			cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(8)
			<<"Tariff"<<setw(10)<<"Name"<<setw(14)<<"Email"<<
			setw(11)<<"Mobile"<<setw(7)<<"Ssno"<<setw(11)
			<<"DoCheckin"<<setw(4)<<"nod"<<endl<<endl;
			a.output();
			modi++;
		}
	}
	if(!modi)
	 cout<<"Record not found..."<<endl;
	f.close();
}

void addroom()
{
	fstream f1,f2;
	f1.open("hotel1.dat",ios::binary|ios::in);
	f2.open("hotel2.dat",ios::binary|ios::app);
	hotel b,a;
	int ins=0;
	cout<<"::New Room::" <<endl;
	b.input1();
	while(f1.read((char*)&a, sizeof(a)))
	{
		if(!ins && b.rrno()<a.rrno())
		{
			f2.write((char*)&b,sizeof(b));
			ins++;
		}
		f2.write((char*)&a,sizeof(a));
	}
	if(!ins)
		f2.write((char*)&b,sizeof(b));
	f1.close();
	f2.close();
}

int deleteroom()
{
	fstream f1,f2;
	f1.open("hotel1.dat",ios::binary|ios::in);
	f2.open("hotel2.dat",ios::binary|ios::app);
	hotel a;
	int rno,del=0;
	cout<<"Room no. to be deleted: ";
	cin>>rno;
	while (f1.read((char*)&a,sizeof(a)))
	{
		if(a.rrno()!=rno)
			f2.write((char*)&a,sizeof(a));
		else
			del++;
	}
	if(!del)
		cout<<"Room no.not found..."<<endl;
	else
		cout<<"Room no. deleted..."<<endl;
	f1.close();
	f2.close();
	return del;
}

void occupiedroom()
{
	int occupied=0;
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in);
	hotel a;
	cout<<"::Occupied rooms::"<<endl;
	while(f.read((char*)&a,sizeof(a)))
	{
		if(strcmpi(a.name,'\0')!=0)
		{
		  cout<<"Room no: ";
		  cout<<a.rrno()<<endl;
		  occupied++;
		}
	}
	cout<<"No. of occcupied rooms: "<<occupied<<endl;
	f.close();
}

void emptyroom()
{
	int empty=0;
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in);
	hotel a;
	cout<<"::Empty rooms::"<<endl;
	while(f.read((char*)&a,sizeof(a)))
	{
		if(strcmpi(a.name,'\0')==0)
		{
			empty++;
			cout<<"Room no: ";
			cout<<a.rrno();
			cout<<"("<<a.rtype()<<")"<<endl;
			cout<<endl;
		}
	}
	cout<<"No. of empty rooms: "<<empty<<endl;
	f.close();
}

void displayroom()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in);
	hotel a;
	int n;
	cout<<"Enter room no: ";cin>>n;
	cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(7)<<"Tariff"<<
	setw(10)<<"Name"<<setw(15)<<"Email"<<setw(11)<<"Mobile"<<
	setw(7)<<"Ssno"<<setw(11)<<"DoCheckin"<<setw(4)<<"nod"<<endl;
	while(f.read((char*)&a,sizeof(a)))
	{
		if(a.rrno()==n)
			a.output();
	}
	f.close();
}

void displayfile()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in);
	hotel a;
	cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(8)<<"Tariff"<<
	setw(10)<<"Name"<<setw(14)<<"Email"<<setw(11)<<"Mobile"<<
	setw(7)<<"Ssno"<<setw(11)<<"DoCheckin"<<setw(4)<<"nod"<<endl<<endl;
	while(f.read((char*)&a,sizeof(a)))
		a.output();
	f.close();
}

void specificroomtype()
{
	fstream f;
	f.open("hotel1.dat",ios::binary|ios::in);
	char ch[7];
	int count=0;
	hotel a;
	cout<<"Enter the room type: ";gets(ch);
	while(f.read((char*)&a,sizeof(a)))
	{
		if(strcmp(a.rtype(),ch)==0 && strcmpi(a.name,'\0')==0)
		{
			cout<<"Room no: ";
			cout<<a.rrno()<<","<<'\b'<<endl;
			count++;
		}
	}
	if(!count)
	 cout<<"No room available with this type"<<endl;
	f.close();
}

void displaytransact()
{
	fstream f;
	f.open("transact.dat",ios::binary|ios::in);
	hotel a;
	cout<<setw(4)<<"Rno"<<setw(7)<<"Type"<<setw(8)<<"Tariff"<<
	setw(10)<<"Name"<<setw(14)<<"Email"<<setw(11)<<"Mobile"<<
	setw(7)<<"Ssno"<<setw(11)<<"DoCheckin"<<setw(4)<<"nod"<<endl<<endl;
	while(f.read((char*)&a,sizeof(a)))
		a.output();
	f.close();
}

void checkout()
{
	fstream f1,f2;
	f1.open("hotel1.dat",ios::binary|ios::in|ios::out);
	f2.open("transact.dat",ios::binary|ios::in|ios::app);
	int rno;
	hotel a;
	cout<<"Enter room no: ";cin>>rno;
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(a.rrno()==rno)
		{
			a.output();
			f2.write((char*)&a,sizeof(a));
			cout<<"Amount to be paid:"<<(a.rtariff()) * (a.nod)
			<<endl;
			a.empty();
			f1.seekp(f1.tellg()-sizeof(a));
			f1.write((char*)&a,sizeof(a));
		}
	}
	f1.close();
	f2.close();
}

void modifyroom()
{
	int a;
	hotel b;
	cout<<"1)Modify Tariff"<<endl;
	cout<<"2)Modify Type"<<endl;
	cout<<"3)Modify Date of Checkin"<<endl;
	cout<<"4)Modify Number of Days"<<endl;
	cout<<"5)Go back..."<<endl;
	do
	{
		cout<<"Enter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1: modifyTariff();break;
			case 2: modifytype();break;
			case 3: modifydoc();break;
			case 4: modifynod();break;
			case 5: cout<<"Menu..."<<endl;break;
			default: cout<<"::WRONG INPUT::"<<endl;
		}
	}
	while(a!=5);
}

void reports()
{
	int a;
	hotel b;
	cout<<"1)Empty Rooms"<<endl;
	cout<<"2)Occupied Rooms"<<endl;
	cout<<"3)Specific Type Room"<<endl;
	cout<<"4)Main Menu"<<endl;
	do
	{
		cout<<"Enter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1: emptyroom();break;
			case 2: occupiedroom();break;
			case 3: specificroomtype();break;
			case 4: cout<<"Main Menu..."<<endl;break;
			default: cout<<"::WRONG INPUT::"<<endl;
		}
	}
	while(a!=4);
}

void admin()
{
	int a;
	do
	{
		cout<<"1)Add Rooms  ";
		cout<<"2)Display Rooms  ";
		cout<<"3)Search Room by name"<<endl;
		cout<<"4)Delete Room  ";
		cout<<"5)Modify Room  ";
		cout<<"6)Display file "<<endl;
		cout<<"7)Display transact ";
		cout<<"8)Main Menu"<<endl;
		cout<<endl;
		cout<<"Enter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1: addroom();
				remove("hotel1.dat");
				rename("hotel2.dat","hotel1.dat");break;
			case 2: displayroom();break;
			case 3: searchbyname();break;
			case 4: if(deleteroom())
				{
					remove("hotel1.dat");
					rename("hotel2.dat","hotel1.dat");
				}
				else
					cout<<"No record Deleted...";  break;
			case 5: modifyroom();break;
			case 6: displayfile();break;
			case 7: displaytransact();break;
			case 8: cout<<"Main Menu..."<<endl;break;
			default: cout<<"::WRONG INPUT::"<<endl;
		}
	}
	while(a!=8);
}

void user()
{
	int a;
	hotel b;
	do
	{
		cout<<"1)Checkin"<<endl;
		cout<<"2)Checkout"<<endl;
		cout<<"3)Main Menu"<<endl;
		cout<<endl;
		cout<<"Enter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1: enter2();break;
			case 2: checkout();break;
			case 3: cout<<"Main Menu..."<<endl;break;
			default: cout<<"::WRONG INPUT::"<<endl;
		}
	}
	while(a!=3);
}

void main()
{
	clrscr();
	int a;
	hotel b;
	do
	{
		cout<<"1)Admin  2)User  3)Reports  4)Quit";
		cout<<endl;
		cout<<"Enter your choice: ";
		cin>>a;
		switch(a)
		{
			case 1: admin();break;
			case 2: user();break;
			case 3: reports();break;
			case 4: cout<<"Quitting..."<<endl;break;
			default: cout<<"::WRONG INPUT::"<<endl;
		}
	}
	while(a!=4);
	getch();
}