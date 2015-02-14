#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>

class item
{
	protected:

	char name[50];
	int index;
	float quantity;
	float price;

	public:

	void setindex(int i)
	{
	 	index=i+1;
          	quantity=1;
	}


	void read(char obj[20])
	{
          	strcpy(name,obj);
	}

	void price1(int range,int base)
	{
	  	price=rand()/100%(range)+ (base);
	}

	void display(int i)
	{
	  gotoxy(10,10+i);
		cout<<index<<"\t"<<name<<"\t";
		gotoxy(60,10+i);
		cout<<quantity<<"\t\t"<<price<<endl;
	}

	int retindex()
	{
		return index;
	}

	void initialize(float quantity1)			
	{

		quantity=quantity1;
		price=quantity1*price;
	}

	void name1(char temp[])
	{
		strcpy(temp,name);
	}

	float retprice()
	{
		return price;
	}

	float retquantity()
	{
		return quantity;
	}

};


class bill1 : public item
{
	public :

	void input(item obj1)
	{
		char temp[50];
		obj1.name1(temp);
		strcpy(name,temp);
		quantity=obj1.retquantity();
		price=obj1.retprice();
	}

	disp(int &flag)
	{
         	if(quantity!=0)
		{
			gotoxy(10,10+flag);
			cout<<flag+1<<"\t"<<name<<"\t";
			gotoxy(55,10+flag);
			cout<<quantity<<"\t\t"<<price<<endl;
			flag++;
		}
	}


	void check1(bill1 &obj)
	{
		if(strcmp(obj.name,name)==0)
		{
			quantity=obj.retquantity()+quantity;
			price=obj.retprice()+price;
			obj.quantity=0;
			obj.price=0;
			strcpy(obj.name,"\0");
		}
	}
};

struct memberz
{

	int memberid;
	char name[20];
	int age;
	char fname[20];
	char email[25];
	char possession[20];
	char heaven[20];
	int shoplong;
	int budget;
	char shopfor[20];
	char addr[70];
	int points;


	memberz()
	{
	    strcpy(name,"\0");
	    age=0;
	    strcpy(fname,"\0");
	    strcpy(email,"\0");
	    strcpy(possession,"\0");
	    strcpy(heaven,"\0");
	    shoplong=0;
	    budget=0;
	    strcpy(shopfor,"\0");
	    strcpy(addr,"\0");
	    points=0;
	}

};


int x=0;
int mid=0;
int offersct=0;
double discount=0,bp=0;

void info()
	{
		closegraph();
		int gdriver = DETECT, gmode ;
		initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
		settextstyle(4,0,5);
		outtextxy(225,8,"Information");
		fstream f ("Memberz",ios::in|ios::out|ios::binary);
		while(!f)
		{
			cout<<"Error";
			exit(1);
		}
		memberz obj;
		f.read((char*)&obj,sizeof(obj));
		int pos;
		while(!f.eof())
		{
			if(obj.memberid==mid)
			{
				break;
			}
			pos=f.tellg();
			f.read((char*)&obj,sizeof(obj));
		}
		gotoxy(10,10);
		cout<<"\n\tEnter your personnal infomation";
		cout<<"\nMember ID: "<<mid;
		cout<<"\nAge: ";
		cin>>obj.age;
		cout<<"\nFather's Name:";
		cin>>obj.fname;
		cout<<"\nEmail Address :";
		cin>>obj.email;
		cout<<"\nIn a week how many days do shop ??";
		cin>>obj.shoplong;
		cout<<"\nWhat do you shop for ??";
		cin>>obj.shopfor;
		cout<<"\nShopping Budget (per Week) : ";
		cin>>obj.budget;
		cout<<"\nPrized possession :";
		cin>>obj.possession;
		cout<<"\nYour Shopping Heaven :";
		cin>>obj.heaven;
		cout<<"\nThank you ";
		cout<<"\nHappy Shopping ";
		getch();
		f.seekg(pos);
		f.write((char*)&obj,sizeof(obj));

	}

void modify()
	{
		closegraph();
		int gdriver = DETECT, gmode ;
		initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
		settextstyle(4,0,5);
		outtextxy(225,8,"Information");
		fstream f ("Memberz",ios::in|ios::out|ios::binary);
		while(!f)
		{
			cout<<"Error";
			exit(1);
		}
		memberz obj;
		f.read((char*)&obj,sizeof(obj));
		int pos;
		while(!f.eof())
		{
			if(obj.memberid==mid)
			{
				break;
			}
			pos=f.tellg();
			f.read((char*)&obj,sizeof(obj));
		}
		gotoxy(10,10);
		
		cout<<"\n\tModify your personnal infomation";
		cout<<"\nMember ID: "<<mid;
		cout<<"\nAge: "<<obj.age;
		cout<<"\nFather's Name:"<<obj.fname;
		cout<<"\nEmail Address :"<<obj.email;
    cout<<"\nIn a week how many days do shop ??"<<obj.shoplong;
		cout<<"\nWhat do you shop for ??"<<obj.shopfor;
		cout<<"\nShopping Budget (per Week) : "<<obj.budget;
		cout<<"\nPrized possession :"<<obj.possession;
		cout<<"\nYour Shopping Heaven :"<<obj.heaven;
		getch();


		cout<<"\n\nTo retain earlier information press'0'";
		int age;
		char fname[20];
		char mar[2];
		char spouse[20];
		int nochild;
		char email[25];
		char possession[20];
		char heaven[20];
		int shoplong;
		int budget;
		char shopfor[20];
		cout<<"\nAge: ";
		cin>>age;
		cout<<"\nFather's Name:";
		cin>>fname;
		cout<<"\nEmail Address :";
		cin>>email;
		cout<<"\nIn a week how many days do you shop ??";
		cin>>shoplong;
		cout<<"\nWhat do you shop for ??";
		cin>>shopfor;
		cout<<"\nShopping Budget (per Week) : ";
		cin>>budget;
		cout<<"\nPrized possession :";
		cin>>possession;
		cout<<"\nYour Shopping Heaven :";
		cin>>heaven;


		if(age!=0)
		obj.age=age;
		if(budget!=0)
		obj.budget=budget;
		if(strcmpi("0",fname)!=0)
		strcpy(obj.fname,fname);




		if(strcmpi("0",heaven)!=0)
		strcpy(obj.heaven,heaven);
		if(strcmpi("0",possession)!=0)
		strcpy(obj.possession,possession);
		if(strcmpi("0",email)!=0)
		strcpy(obj.email,email);
		cout<<"\nThank you ";
		cout<<"\nHappy Shopping ";
		getch();

		f.seekg(pos);
		f.write((char*)&obj,sizeof(obj));

	}

void offers()
	{
		closegraph();
		int gdriver = DETECT, gmode ;
		initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
		settextstyle(4,0,5);
		outtextxy(250,8,"Offers");
		int pts,pos;
		fstream f ("Memberz",ios::in|ios::out|ios::binary);
		while(!f)
		{
			cout<<"Error";
			exit(1);
		}
		memberz obj3;
		f.read((char*)&obj3,sizeof(obj3));
		while(!f.eof())
		{
			if(obj3.memberid==mid)
			{
				
				pts=obj3.points;
				break;
			}
			f.read((char*)&obj3,sizeof(obj3));
		}
		gotoxy(10,10);
		lb2:
		cout<<"\nYour Choices :";
		cout<<"\n1.	Redeem your points for a discount ";
		cout<<"\n2.	Shop for more than Rs 500 and get 10 	bonus points";
		cout<<"\n3.	Shop for more than 10 items to get 30 bonus points";
		cout<<"\n4.	Continue Shopping";
		Choice :";
		int ch4;
		cin>>ch4;

		switch(ch4)
		{
			case 1:
		  cout<<"\nHow many points do you want to redeem??";
			cin>>discount;
			if (discount >pts)
			{

				cout<<"Sorry!! Maximum is "<<pts ;
				discount=pts;
			}
			obj3.points=pts-discount;
			cout<<"\nDone";
			offersct++;
			f.seekg(pos);
			f.write((char*)&obj3,sizeof(obj3));
			break;

			case 2:
			offersct++;
			if(offersct!=2)
			{
				cout<<"\nDone";
				bp=10;
			}
			else
			cout<<"Only one offer allowed ";
			break;
		
			case 3:
			offersct++;
			if(offersct!=2)
			{

				cout<<"\nDone";
				bp=30;
			}
			else
			cout<<"Only one offer allowed ";
			break;

			case 4:
			break;
			default:
			cout<<"Error";
			goto lb2;
		}


		cout<<"\nHappy Shopping";
		getch();

	}

void newmem()
	{
		memberz obj1,obj2;
		fstream f("Memberz",ios::in|ios::binary);
		fstream f1("Memberz",ios::app|ios::binary);

		if(!f)
		{

			cout<<"Error";
			exit(1);
		}

		fl:
		cout<<"\nWhat do you want New Member ID to be: ";
		cin>>obj1.memberid;
		char empch='y';
		int empcheck=0;
		obj1.points=rand()/100%(10)+ (10);
		if(obj1.memberid>100 && obj1.memberid<110)
		{
	
			cout<<"\nID reserved for employee's only";
			cout<<"\nAre you an employee?";
			cin>>empch;
		
			switch(empch)
			{

				case 'y':
				case 'Y':
				cout<<"\nEnter employee password :";
				cin>>empcheck;
				if(empcheck==13)
				{

					cout<<"Continue";
					obj1.points=0;
					break;
				}
				else
				cout<<"Error";
				default:goto fl;
			}			
		}

		f.seekg(0);
		f.read((char*)&obj2,sizeof(obj2));
		while(!f.eof())
		{
			
			if(obj2.memberid==obj1.memberid)
			{
				cout<<"\nSorry!!That ID already exists";
				goto fl;
			}
			else
			f.read((char*)&obj2,sizeof(obj2));
		}
		cout<<"\nEnter your name: ";
		gets(obj1.name);
		cout<<"\nEnter your address :";
		gets(obj1.addr);
		f1.write((char*)&obj1,sizeof(memberz));
		f.close();
		mid=obj1.memberid;
		cout<<"\nCongratulations!!!!";
		cout<<"\nYou are now our member";
    cout<<"\nYou have "<<obj1.points<<" points to start shopping      								with";
		cout<<"\nChoices :";
		cout<<"\n1.	Check out our cool offers";
		cout<<"\n2.	Enter Personnal Information";
		cout<<"\n3.	Continue Shopping";
		cout<<"\nYour Choice :";
		int ch3;
		cin>>ch3;
		
		switch(ch3)
		{

		case 1:
		offers();
		break;

		case 2:
		info();
		break;

		case 3:
		cout<<"Happy Shopping";
		break;
		
		default:
		cout<<"\nError";
		};
	}


void check2(bill1 obj1[])
	{

		for(int i=0;i<x;i++)
		{

			if(obj1[i].retquantity()!=0)
			for(int j=i+1;j<x;j++)
			obj1[i].check1(obj1[j]);
		}
	}


bill1 itm[30];
int face();
void bill();

int buy(item obj[],int n)
	{
		char ch1;
		int object;
		do
		{

			object=0;
      cout<<"What would you like to buy??
			cin>>object;
			int flag=0;
			float numitem=1;

			for(int i=0;i<n;i++)
			{
			if(object==obj[i].retindex())
			{
				flag++;
				break;
			}
		}
		if(flag==0)
		{
			
			if(object==0)
			break;
			else
			cout<<"Error\n";
		}
		else
		{
			ged:
	  	cout<<"How much would you like to buy (In quantity)?? ";
			cin>>numitem;
			if(numitem>10)
			{
		
				cout<<"Error";
				cout<<"\nYou cannot buy more the 10 items";
	      cout<<"\nWe are out of stock. Sorry for the inconvenience\n";
				goto ged;
			}

			obj[object-1].initialize(numitem);
			itm[x].input(obj[object-1]);
			x++;
		}
		
		}while(object!=0);


		cout<<"Would to go a different shop(Y\\N)??";
		delete obj;
		cin>>ch1;
		cleardevice();


		switch(ch1)
			{
				case 'n':
				case 'N':return 2;
				default:return 1;
			}

	}

int vegetables()
	{
		cleardevice();
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		randomize();
		item things[10];

		things[0].read("Potato");
		things[1].read("Onion");
		things[2].read("Carrot");
		things[3].read("Cabbage");
		things[4].read("Spinach");
		things[5].read("Ladysfinger");
		things[6].read("Apple");
		things[7].read("Mango");
		things[8].read("Banana");
		things[9].read("Orange");

		for(int i=0;i<10;i++)
		{
			
			things[i].setindex(i);
			things[i].price1(22,20);
		}
		
		setcolor(5);
		settextstyle(4,0,5);
		outtextxy(250,8,"Veggies");
		rectangle(1,1,633,60);
		rectangle(1,61,633,100);
		settextstyle(4,0,4);
		outtextxy(30,60,"Index");
		outtextxy(150,60,"Name");
		outtextxy(375,60,"Quantity(Kgs)");
		outtextxy(555,60,"Price");
		settextstyle(4,0,5);
		
		for(i=0;i<10;++i)
		{

			things[i].display(i);
		}		
		cout<<endl<<endl;
		char ch;
		return buy(things,10);

	}

int hardware()
	{
		cleardevice();
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		randomize();
		item things1[7];

		things1[0].read("Screw Driver");
		things1[1].read("Hammer");
		things1[2].read("Plier");
		things1[3].read("Floor Jack");
		things1[4].read("Spanner");
		things1[5].read("Springs");
		things1[6].read("Wallgrip");
		
		for(int i=0;i<7;i++)
		{

			things1[i].setindex(i);
			things1[i].price1(31,40);
		}
		setcolor(12);
		settextstyle(4,0,5);
		outtextxy(200,8,"Hardware World");
		rectangle(1,1,633,60);
		rectangle(1,61,633,100);
		settextstyle(4,0,4);
		outtextxy(30,60,"Index");
		outtextxy(150,60,"Name");
		outtextxy(400,60,"Quantity");
		outtextxy(555,60,"Price");

		for(i=0;i<7;++i)
		{

			things1[i].display(i);
		}
		cout<<endl<<endl;
		return buy(things1,7);

	}

int books()
	{
		clrscr();
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		settextstyle(4,0,2);
		randomize();
		item things2[10];
		things2[0].read("D C Pandey:Problems in Physics");
		things2[1].read("Tata Mcrawhill:Problems in Mathematics");
		things2[2].read("Resnick Halliday:Advanced Physics");
		things2[3].read("J D Lee:Inorganic Chemistry");
		things2[4].read("Wren & Martin:Advanced English");
		things2[5].read("S L Arora:Problems in Mathematics");
		things2[6].read("H C Verma:Problems in Physics");
		things2[7].read("R D Sharma:Problems in Mathematics");
		things2[8].read("Sumita Arora:Computer Science");
		things2[9].read("R S Agarwal:Problems in Mathematics");

		for(int i=0;i<10;i++)
		{
			
			things2[i].setindex(i);
			things2[i].price1(61,300);
		}
		setcolor(13);
		settextstyle(4,0,5);
		outtextxy(200,8,"Book Worm");
		rectangle(1,1,633,60);
		rectangle(1,61,633,100);
		settextstyle(4,0,4);
		outtextxy(30,60,"Index");
		outtextxy(150,60,"Name");
		outtextxy(400,60,"Quantity");
		outtextxy(555,60,"Price");
		settextstyle(4,0,5);

		for(i=0;i<10;++i)
		{
			things2[i].display(i);
		}
			cout<<endl<<endl;
		return buy(things2,10);
	}





int cafe()
	{
		cleardevice();
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		randomize();
		item things3[10];

		things3[0].read("Tea");
		things3[1].read("Coffee");
		things3[2].read("Sandwich");
		things3[3].read("Tomato soup");
		things3[4].read("Potato Puff");
		things3[5].read("Samosa");
		things3[6].read("Gatorade");
		things3[7].read("Pizza");
		things3[8].read("Cake");
		things3[9].read("Ice cream");
		things3[10].read("Fruit Juice");
		things3[11].read("Cold drinks");

		for(int i=0;i<12;i++)
		{

			things3[i].setindex(i);
			things3[i].price1(21,20);
		}
		setcolor(14);
		settextstyle(4,0,5);
		outtextxy(200,8,"Compsci Cafe");
		rectangle(1,1,633,60);
		rectangle(1,61,633,100);
		settextstyle(4,0,4);
		outtextxy(30,60,"Index");
		outtextxy(150,60,"Name");
		outtextxy(400,60,"Quantity");
		outtextxy(555,60,"Price");
		settextstyle(4,0,5);

		for(i=0;i<12;++i)
		{

			things3[i].display(i);
		}
		cout<<endl<<endl;
	return buy(things3,12);

	}

int stationary()
	{
		cleardevice();
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		randomize();
		item things4[10];
		things4[0].read("Scale");
		things4[1].read("Pencils");
		things4[2].read("Pens");
		things4[3].read("Eraser");
		things4[4].read("Stapler");
		things4[5].read("Whitener");
		things4[6].read("Cellotape");
		things4[7].read("A4 Paper Bundle");
		things4[8].read("Paints");
		things4[9].read("Paintbrush");
	
		for(int i=0;i<10;i++)
		{

			things4[i].setindex(i);
			things4[i].price1(21,10);
		}
		setcolor(15);
		settextstyle(4,0,5);
		outtextxy(200,8,"Stationeries");
		rectangle(1,1,633,60);
		rectangle(1,61,633,100);
		settextstyle(4,0,4);
		outtextxy(30,60,"Index");
		outtextxy(150,60,"Name");
		outtextxy(400,60,"Quantity");
		outtextxy(555,60,"Price");
		settextstyle(4,0,5);
	
		for(i=0;i<10;++i)
		{

			things4[i].display(i);
		}
		cout<<endl<<endl;
		return buy(things4,10);
		
	}

void employee()
	{
		closegraph();
		int gdriver = DETECT, gmode ;
		initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
		settextstyle(4,0,5);
		outtextxy(250,8,"Onwers");
		int pts,pos;
		fstream f ("Memberz",ios::in|ios::out|ios::binary);
		while(!f)
		{

			cout<<"Error";
			exit(1);
		}

		int cho;
		do
		{
			gotoxy(10,10);
			cout<<"\nWhat would you like do to ?";
			cout<<"\nChoices :";
			cout<<"\n1.	Check out member details";
			cout<<"\n2.	Modify member records";
			cout<<"\n3.	Delete members";
			cout<<"\n4.	Continue";
			cout<<"\nYour Choice :";

			memberz obj;
			cin>>cho;

			switch(cho)
			{
				case 1:
				f.seekg(0);
				while(!f.eof())
				{
					
					f.read((char*)&obj,sizeof(obj));
					cout<<"\nMember ID : "<<obj.memberid;
					cout<<"\nMember Name : "<<obj.name;
					cout<<"\nPoints : "<<obj.points;

				}
				getch();
				break;

				
				case 2:
				cout<<"\nEnter the Member ID whose details you want to edit?";
				int membid;
				cin>>membid;
				f.seekg(0);
				f.read((char*)&obj,sizeof(obj));
				int pos;

				while(!f.eof())
				{

					if(obj.memberid==membid)
					{

						break;
					}
					pos=f.tellg();
					f.read((char*)&obj,sizeof(obj));
				}

			  cout<<"\n\tModify your personnal infomation";
				cout<<"\nMember Name: "<<obj.name;
				cout<<"\nAge: "<<obj.age;
				cout<<"\nFather's Name:"<<obj.fname;
				cout<<"\nEmail Address :"<<obj.email;
        cout<<"\nIn a week how many days do shop ??"<<obj.shoplong;
        cout<<"\nWhat do you shop for ??"<<obj.shopfor;
        cout<<"\nShopping Budget (per Week) : "<<obj.budget;
        cout<<"\nPrized possession :"<<obj.possession;
        cout<<"\nYour Shopping Heaven :"<<obj.heaven;
				getch();
		  	cout<<"\n\nTo retain earlier information press'0'";

				int age;
				char fname[20];
				char mar[2];
				char spouse[20];
				int nochild;
				char email[25];
				char possession[20];
				char heaven[20];
				int shoplong;
				int budget;
				char shopfor[20];

				cout<<"\nAge: ";
				cin>>age;
				cout<<"\nFather's Name:";
				cin>>fname;
				cout<<"\nEmail Address :";
				cin>>email;
	    	cout<<"\nIn a week how many days do they shop ??";
				cin>>shoplong;
				cout<<"\nWhat do they shop for ??";
				cin>>shopfor;
				cout<<"\nShopping Budget (per Week) : ";
				cin>>budget;
				cout<<"\nPrized possession :";
				cin>>possession;
				cout<<"\nTheir Shopping Heaven :";
				cin>>heaven;
				if(age!=0)
				obj.age=age;
				if(budget!=0)
				obj.budget=budget;
				if(strcmpi("0",fname)!=0)
				strcpy(obj.fname,fname);
				if(strcmpi("0",heaven)!=0)
				strcpy(obj.heaven,heaven);
				if(strcmpi("0",possession)!=0)
				strcpy(obj.possession,possession);
				if(strcmpi("0",email)!=0)
				strcpy(obj.email,email);
				getch();

				f.seekg(pos);
				f.write((char*)&obj,sizeof(obj));
				break;

				case 3:
				
	      cout<<"\nEnter the Member ID whom you want to delete?";
				int membid2;
				cin>>membid2;
				fstream fout("temp",ios::out|ios::binary);
				char found='f',confirm='n';
				f.seekg(0);


				while(!f.eof())
				{

					f.read((char*)&obj,sizeof(obj));
					
					if(obj.memberid==membid2)
					{

				cout<<"\nMember ID : "<<obj.memberid;
				cout<<"\nMember Name : "<<obj.name;
				cout<<"\nPoints : "<<obj.points;
				found='t';
	    	cout<<"Are you sure you want to delete this member?";
						cin>>confirm;
						if(confirm=='n')
						fout.write((char*)&obj,sizeof(obj));
					}
				
					else
					fout.write((char*)&obj,sizeof(obj));
				}
				if(found=='f')
				cout<<"\nMember not found";
				fout.close();
				remove("Memberz");
				rename("temp","Memberz");
				break;

				case 4:
				break;

				default:
				cout<<"Error";
			}
	}while(cho!=4);
	
	cout<<"\nHappy Shopping";
	getch();

	}

void bill()
	{

	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	cleardevice();
			
		if (x==0)
		{
			setcolor(9);
			settextstyle(4,0,6);
			outtextxy(1,100,"Bye!!");
			outtextxy(1,170,"Do Come Again!!");
			int c=1;
			setcolor(c);
		
			for(int i=0;i<=360;++i)
			{
				for(int j=100;j>=0;j--)
				{
				
				arc(320, 370, 0, i, j);
				gotoxy(40,14);
					
				}
				setcolor(c++);
			}
			exit(0);
		}

		else
		
		{
			if(mid==0 && offersct==0)
			{

				memberz obj2;
				settextstyle(4,0,5);
				setcolor(9);
				outtextxy(250,8,"Memberzone");
				gotoxy(10,10);

				lb:
				cout<<"Enter your Member ID (else enter '0'): ";
				int memid;											cin>>memid;

				fstream ("Memberz",ios::in|ios::out|ios::binary);
				
				while(!f)
					{

						cout<<"Error";
						exit(1);
					}
					char found='n';
				
				if(memid!=0)
				{
					while(!f.eof())
					{
						f.read((char*)&obj2,sizeof(obj2));
						if(obj2.memberid==memid)
						{

						mid=memid;
		        cout<<"\nMember ID : "<<obj2.memberid;
					  cout<<"\nMember Name : "<<obj2.name;
					  cout<<"\nPoints : "<<obj2.points;
					  cout<<"\nChoices :";
				    cout<<"\n1.	Check out our cool offers";
						cout<<"\n2.	Continue Shopping";
						cout<<"\nYour Choice :";
				
						int ch3;
						cin>>ch3;

						switch(ch3)
						{

						case 1:offers();break;
						case 2:break;
						default:cout<<"\nError";break;
						};

						found='y';
						break;
						}
					}
					f.close();
				}

				else
				{

				char ch1;
			  cout<<"Do you want to be a member??(Y\\N) :";
			 	cin>>ch1;
				if(ch1=='y'||ch1=='Y')
				newmem();
				}

				if(found=='n' && memid!=0)
				{
				cout<<"\nInvalid\n";
				goto lb;
				}
			
			}//End of if;

			else if(mid!=0 && offersct==0 && mid<100&&mid>110)
			{

				settextstyle(4,0,5);
				outtextxy(250,8,"Memberzone");
				gotoxy(10,10);
		    cout<<"\nMember ID : "<<mid;
        cout<<"\nYou haven't availed our offers. Do have a look at them";
				cout<<"\nChoices :";
				cout<<"\n1.	Check out our cool offers";
				cout<<"\n2.	Continue to the bill";
				cout<<"\nYour Choice :";									int ch3;
				cin>>ch3;

				switch(ch3)
				{
					case 1:offers();break;
					case 2:break;
					default:cout<<"\nError";
				};
			}

			closegraph();

			initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
			setcolor(13);
			settextstyle(4,0,5);
			outtextxy(250,8,"Bill");
			rectangle(1,1,633,60);
			rectangle(1,61,633,100);
			settextstyle(4,0,4);
			outtextxy(30,60,"Index");
			outtextxy(150,60,"Name");
			outtextxy(400,60,"Quantity");
			outtextxy(555,60,"Price");
			settextstyle(4,0,5);
			check2(itm);
			int flag=0;
			for(int i=0;i<x;++i)
			{

				itm[i].disp(flag);
			}
			double total=0;

			for(int j=0;j<x;j++)
			{

				if(itm[j].retquantity()!=0)
				total+=itm[j].retprice();
			}

			double tax_amt = (total*2.00)/100.0;
			double totalfinal = total + tax_amt - discount;
			if(totalfinal<0)
			totalfinal=0;
			if(mid>100&&mid<110)
			{

				totalfinal=0;
				total=0;
				tax_amt=0;
				discount=0;
			}

			cout<<endl<<endl;
			cout<<"\n           Purchase is:  Rs "<<total;
			cout<<"\nTax (Inclusive of VAT):  Rs "<<tax_amt;
			cout<<"\nDiscount	       :  Rs "<<discount;
			cout<<"\n                 Total:  Rs "<<totalfinal;

			fstream f ("Memberz",ios::in|ios::out|ios::binary);
		
			while(!f)
			{

				cout<<"Error";
				exit(1);
			}

			memberz obj;
			long pos;

			while(!f.eof())	
			{

				pos=f.tellg();
				f.read((char*)&obj,sizeof(obj));
				if(obj.memberid==mid)
				{

					int pots=(totalfinal/10.0)+bp;
				cout<<"\n\nYour points added are :"<<pots;
					obj.points+=pots;
					f.seekg(pos);
					f.write((char*)&obj,sizeof(obj));
					break;
				}
			}
			f.seekg(0);

			while(!f.eof())
			{

				f.read((char*)&obj,sizeof(obj));
				if(obj.memberid==mid)
				{

					cout<<"\nMember ID : "<<obj.memberid;
					cout<<"\nMember Name : "<<obj.name;
					cout<<"\nPoints : "<<obj.points;
					break;
				}
			}
			getch();
			closegraph();


			initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
			setcolor(9);
			settextstyle(4,0,8);
			outtextxy(1,100,"Bye!!");
			outtextxy(1,170,"Do Come Again!!");
			int c=1;
			setcolor(c);
			for(i=0;i<=360;++i)
			{

				for(int j=100;j>=0;j--)
				{

					arc(320, 370, 0, i, j);
					gotoxy(40,14);
				}
				setcolor(c++);
			}

			exit(0);
		}	
		closegraph();

	}


int face()
	{
		int gdriver = DETECT, gmode;
		label:
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		static int chec=1;

		while(chec==1)
		{
			cleardevice();
			setcolor(14);
			circle(575, 150,50);
			pieslice(575, 100,190,350,35);
			pieslice(624,140,109,280,35);
			circle(550,150,5);
			pieslice(548,152,0,360,3);
			arc(545,135,255,300,45);
			arc(520,149,305,335,55);
			setcolor(5);
			arc(375,130,-15,318,100);
			arc(550,60,230,265,125);
			arc(475,75,257,300,125);
			gotoxy(41,6);
			cout<<("WELCOME BACK");
			gotoxy(37,9);
			cout<<"WHAT DO YOU WANT TO DO?";
			gotoxy(1,15);
			cout<<"LIST OF SHOPS:\n";
			cout<<"1.	Veggies"<<endl;
			cout<<"2.	Hardware World"<<endl;
			cout<<"3.	Stationaries"<<endl;
			cout<<"4.	Comsci Cafe"<<endl;
			cout<<"5.	Bookworm"<<endl;
			cout<<"6.	Member Zone"<<endl;
			cout<<"7.	Help"<<endl;
			cout<<"8.	Exit"<<endl;

			int n;
			cout<<"\nENTER YOUR CHOICE..........";
			cin>>n;
			
			switch(n)
			{

				case 1:chec=vegetables();break;
				case 2:chec=hardware();break;
				case 3:chec=stationary();break;
				case 4:chec=cafe();break;
				case 5:chec=books();break;
				case 6:
				{

					if(mid==0 && offersct==0)
					{

				initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
						memberz obj2;
						settextstyle(4,0,5);
						setcolor(6);
						outtextxy(250,8,"Memberzone");
						gotoxy(10,10);
						lb:
			cout<<"Enter your Member ID (else enter '0'): ";
						int memid;
						cin>>memid;
			fstream f ("Memberz",ios::in|ios::out|ios::binary);
					while(!f)
					{

						cout<<"Error";
						exit(1);
						}
						char found='n';
						if(memid!=0)
						{

						while(!f.eof())
						{
						 f.read((char*)&obj2,sizeof(obj2));
						 if(obj2.memberid==memid)
						   {

						mid=memid;
		cout<<"\nMember ID : "<<obj2.memberid;
		cout<<"\nMember Name : "<<obj2.name;
		cout<<"\nPoints : "<<obj2.points;
		cout<<"\nChoices :";
		cout<<"\n1.	Check out our cool offers";
		cout<<"\n2.	Modify information";
		cout<<"\n3.	Continue Shopping";
		if(mid>100&&mid<110)
		cout<<"\n4.	Employee Priveliges";
		cout<<"\nYour Choice :";
		int ch3;
		cin>>ch3;
		mid=memid;
		
				switch(ch3)
					{
						case 1:
						offers();break;
						case 2:
						modify();break;
						case 3:
						break;
						case 4:
						employee();break;
						default:
						cout<<"\nError";getch();
					};


						found='y';
						break;
						  }
				
						}
				f.close();
			}


					else
					{
					char ch1;
			cout<<"Do you want to be a member??(Y\\N) :";
					cin>>ch1;
					if(ch1=='y'||ch1=='Y')
					newmem();
					}

				if(found=='n' && memid!=0)
				{
					cout<<"\nInvalid\n";
					goto lb;
				}
			 }
			else if(mid!=0)
			{
				cout<<"\nMember ID : "<<mid;
				cout<<"\nChoices :";
				cout<<"\n1.	Check out our cool offers";
				cout<<"\n2.	Modify information";
				cout<<"\n3.	Continue Shopping";
				cout<<"\nYour Choice :";
				int ch3;
				cin>>ch3;
				switch(ch3)
				{

					case 1:offers();break;
					case 2:modify();break;
					case 3:break;
					default:cout<<"\nError";getch();
				};
			}

			goto label;

				}


				case 7:
				{
					cleardevice();
					int gdriver = DETECT, gmode ;
				  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
					settextstyle(4,0,5);
					setcolor(3);
					outtextxy(250,8,"Help");
					gotoxy(10,10);
          cout<<"\n*	In this programme we have tried to bring together all the";
          cout<<"\naspects of a mall.";
          cout<<"\n*	Throughout the programme the instructions are give everywhere.";
          cout<<"\n*	Make sure that you code in the correct item index.";
          cout<<"\n*	Make sure you press only Y (or N) in the appropriate place";
          cout<<"\nelse your choice is taken as N.";
          cout<<"\n\n*	We also have introduced Member Zone";
          cout<<"\nwhere one can avail good offers.";
          cout<<"\n*	Members are given a Member ID (interger) which helps us";
          cout<<"\nserve you better.";
          cout<<"\n*	Also one can collect points to get bonus next time.";
          cout<<"\n\nCome and have some fun";
          cout<<"\n\n";
          cout<<"Press any key to continue.......";
          getch();
          closegraph();

				}
				goto label;
				
				case 8:chec=2;closegraph();break;
				default:cout<<"\nError";getch();
	}
			
			
		};
	cleardevice();
	if(chec==2)
  return 1;
	else
	return 2;


void main()
	{

		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		setcolor(14);

		circle(575, 150,50);
		pieslice(575, 100,190,350,35);
		pieslice(624,140,109,280,35);
		circle(550,150,5);
		pieslice(548,152,0,360,3);
		arc(545,135,255,300,45);
		arc(520,149,305,335,55);
		setcolor(3);
		arc(375,130,-15,318,100);
		arc(550,60,230,265,125);
		arc(475,75,257,300,125);
		gotoxy(45,5);
		cout<<"HELLO!!!";
		gotoxy(40,8);
		cout<<"WELCOME TO THE ";
		gotoxy(43,11);
		cout<<"C-SHOP!!!";

		int s=30,w;
		gotoxy(20,23);
		cout<<"LOADING . . .";
    for (int x1=171,x2=171,y1=308,y2=331,y=1,S=0;x1<470;x1++,x2++,y++,S++)
			{

				setcolor(4);
				line (x1,y1,x2,y2);
				w=(x1-169)/3;
				for (int i=34; i<=78; i++)
				{

					gotoxy(i,23) ;
					cout <<" " ;
				}
				gotoxy(34,23);
				cout<<w<<"%";
				if (x2>270)
				s=20;
				if (x2>370)
				s=10;
				if (x2==320)
				delay(999);
				else
				delay(s);
			}
		delay(800);
		for (int i=27; i<=78; i++)
		{

			gotoxy(i,23) ;
			cout <<" " ;
		}
		gotoxy(28,23);
		cout<<"COMPLETE";
		gotoxy(20,25);
		cout<<"PRESS ANY KEY TO CONTINUE ";
		getch();
		closegraph();
		clrscr();
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		setcolor(8);
		ellipse(320,240,0,360,300,150);
		settextstyle(10,0,4);
		settextjustify(1,1);
		setcolor(5);
		outtextxy(320,170,"C-SHOP");
		delay(250);
		settextstyle(4,0,4);
		setcolor(20);
		outtextxy(320,220,"Presented By:");
		delay(250);
		setcolor(9);
		settextstyle(4,0,6);
		outtextxy(320,315,"Abhishek");
		setcolor(2);
		delay(250);
		outtextxy(320,265,"Hariharan");

		for (int stangle=0;!kbhit();stangle++)
		{

			setcolor(7);
			ellipse(320,240,stangle,stangle+20,300,150);
			ellipse(320,240,stangle+180,stangle+200,300,150);
			delay(9);
			setcolor(8);
			ellipse(320,240,stangle-1,stangle+19,300,150);
			ellipse(320,240,stangle1+180,stangle+199,300,150);

		}
		getch();
		closegraph();

		clrscr();
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		setcolor(14);
		circle(575, 150,50);
		pieslice(575, 100,190,350,35);
		pieslice(624,140,109,280,35);
		circle(550,150,5);
		pieslice(548,152,0,360,3);
		arc(545,135,255,300,45);
		arc(520,149,305,335,55);
		setcolor(5);
		arc(375,130,-15,318,100);
		arc(550,60,230,265,125);
		arc(475,75,257,300,125);
		gotoxy(41,6);
		cout<<"I AM ABHIHARI";
		gotoxy(37,9);
		cout<<"WHAT DO YOU WANT TO DO?";
		gotoxy(1,15);
		
		cout<<"LIST OF CHOICES:\n";
		cout<<"1.	To visit the shops"<<endl;
		cout<<"2.	Member Zone"<<endl;
		cout<<"3.	Help"<<endl;
		cout<<"4.	Credits"<<endl;
		cout<<"5.	Exit"<<endl;
		int n;
		int cho;

		do
		{
			cout<<"\nENTER YOUR CHOICE..........";
			cin>>n;
			switch(n)
			{

			case 1:
			{
				cho=face();
				n=1;
				closegraph();
				break;
			}
			
			case 2:
			{
				if(mid==0&&offersct==0)
				{

				initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
					memberz obj2;
					settextstyle(4,0,5);
					outtextxy(250,8,"Memberzone");
					gotoxy(10,10);

					lb:
				cout<<"Enter your Member ID (else enter '0'): ";
					int memid;
					cin>>memid;
			fstream f ("Memberz",ios::in|ios::out|ios::binary);
					while(!f)
					{

						cout<<"Error";
						exit(1);
					}
					char found='n';
					
					if(memid!=0)
					{

						while(!f.eof())
						{
							f.read((char*)&obj2,sizeof(obj2));
						if(obj2.memberid==memid)
						{

							mid=memid;
				cout<<"\nMember ID : "<<obj2.memberid;
				cout<<"\nMember Name : "<<obj2.name;
				cout<<"\nPoints : "<<obj2.points;
			cout<<"\nChoices :";
			cout<<"\n1.	Check out our cool offers";
			cout<<"\n2.	Modify information";
			cout<<"\n3.	Continue Shopping";
					if(mid>100&&mid<110)
					cout<<"\n4.	Employee Priveliges";
					cout<<"\nYour Choice :";
							int ch3;
							cin>>ch3;

							switch(ch3)
							{

								case 1:offers();break;
								case 2:modify();break;
								case 3:break;
								case 4:employee();break;
							default:
     cout<<"\nError";getch();
							};

							found='y';
							break;
						}

						}//end of While
						f.close();
				}

				else
				{

					char ch1;
			cout<<"Do you want to be a member??(Y\\N) :";
					cin>>ch1;
					if(ch1=='y'||ch1=='Y')
					newmem();
				}

				if(found=='n' && memid!=0)
				{

					cout<<"\nInvalid\n";
					goto lb;
				}
			}

		}
		cho=face();
		n=1;
		break;

		
		case 3:
		{

			cleardevice();
			int gdriver = DETECT, gmode ;
			initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
			settextstyle(4,0,5);
			setcolor(3);
			outtextxy(250,8,"Help");
			gotoxy(10,10);

    cout<<"\n* In this programme we have tried to bring  together all the";
    cout<<"\naspects of a mall.";
    cout<<"\n*	Throughout the programme the instructions are give 	everywhere.";
    cout<<"\n*	Make sure that you code in the correct item index.";
    cout<<"\n*	Make sure you press only Y (or N) in the appropriate place";
    cout<<"\nelse your choice is taken as N.";
    cout<<"\n\n*	We also have introduced Member Zone";
    cout<<"\nwhere one can avail good offers.";
    cout<<"\n*	Members are given a Member ID (interger) which helps us";
		cout<<"\nserve you better.";
	  cout<<"\n*	Also one can collect points to get bonus next time.";
			cout<<"\n\nCome and have some fun";
			cout<<"\n\n";
			cout<<"Press any key to continue.......";
			getch();
			closegraph();
			cho=face();
			n=1;
			break;
		}
	
		case 4:
		{
		cleardevice();
		int gdriver = DETECT, gmode ;
		initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
		settextstyle(4,0,5);
		setcolor(3);
		outtextxy(250,8,"Credits");
		gotoxy(10,10);
    cout<<"\nThis programme was coded by Hariharan and Abhishek";
		cout<<"\nUnder the guidance of Mrs Kala ";
	  cout<<"\nWe thank the school for giving us a platform to";
    cout<<"\nshowcase our ability and help us identify our strenghts";
		cout<<"\nThank you for visiting.\n\n";
		cout<<"Press any key to  continue........";
		getch();
		closegraph();
		}
		cho=face();
		n=1;
		break;

		case 5:
		{
			cho=1;
			closegraph();
			n=1;
			break;
		}
	
		default:
		cout<<"\nError";
		getch();
	}

	}while(n<1||n>4);


	if( cho==1)
	bill();
	getch();
	closegraph();
}


