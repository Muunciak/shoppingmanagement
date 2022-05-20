#include <iostream>
#include <fstream>

using namespace std;


class shop{
	private:
		int Pcode;
		float price;
		float dsc;
		string Pname;
		
	public:
			void menu();
			void admin();
			void client();
			void add();
			void edit();
			void delet();
			void list();
			void receipt();
			
			
		
};

void shop :: menu(){
	int c,count=1;
	string mail,passw,IDmail,IDpass;
	
	ifstream check("admin.txt");
	m:
		cout<<"\t\t\t\t________________________________________________\t\t\t\t\n";
		cout<<"\t\t\t\t________________________________________________\t\t\t\t\n";
		cout<<"\t\t\t\t_____________Supermarket main menu______________\t\t\t\t\n";
		cout<<"\t\t\t\t___1) Admin_____________________________________\t\t\t\t\n";
		cout<<"\t\t\t\t___2) Client____________________________________\t\t\t\t\n";
		cout<<"\t\t\t\t___3) Leave_____________________________________\t\t\t\t\n";
		cout<<"\t\t\t\t________________________________________________\t\t\t\t\n";
		
		cout<<"\t\tSelect your choice: ";cin>>c;
		
		switch(c){
			case 1: cout<<"\t\t\t\tEnter work individual mail: ";cin>>mail;
					cout<<"\t\t\t\tEnter password: ";cin>>passw;
					while(check>>IDmail>>IDpass){
						if(IDmail==mail && IDpass==passw){
							count=1;
							}
						}
						check.close();
						if(count==1){
							cout<<"login succ.";
							admin();
						}
						else
							cout<<"\t\t\t\tWrong login or password. ";
						break;
			case 2:{
				client();
				break;
			}
			case 3:{
				exit(0);
				break;
			}
			default: {
				cout<<"Please select from the given options";
				break;
				goto m;
			}
		}
}
void shop :: admin(){
	m:
	int c;
	cout<<"\n\n \t\t\t\t Admin menu\n";
	cout<<"\t\t\t\t 1) Add product \n";
	cout<<"\t\t\t\t 2) Manage product\n";
	cout<<"\t\t\t\t 3) Remove product\n";
	cout<<"\t\t\t\t 4) Back to main menu";
	
	cout<<"\n\n What do you want to do?: ";cin>>c;
	
	switch(c){
		case 1:
			add();
			break;
			
		case 2:
			edit();
			break;
			
		case 3:
			delet();
			break;
			
		case 4:
			menu();
			break;
			
		default:
			cout<<"Wrong choice, choose again";
	}
	goto m;
}
void shop :: client(){
	m:
	int c;
	cout<<"\t\t\t\t  Buyer \n";
	cout<<endl;
	cout<<"\t\t\t\t1) Buy product \n";
	cout<<endl;
	cout<<"\t\t\t\t2) Go back \n";
	cout<<"\t\t\t\t Enter your choice: ";cin>>c;
	
	switch(c){
		case 1: 
			receipt();
			break;
			
		case 2:
			menu();
			break;
		default:
			cout<<"Wrong choice.";
	}
	goto m;
}
void shop :: add(){
	m:
	fstream data;
	int c,token=0;
	float p,d;
	string n;
	
	cout<<"\n\n\n\t\t\t\t Add new product ";
	cout<<"\n\n\t\t\t\t Set code of product: "; cin>>Pcode;
	cout<<"\n\n\t\t\t\t Set name of the product: ";cin>>Pname;
	cout<<"\n\n\t\t\t\t Set price of the product: ";cin>>price;
	cout<<"\n\n\t\t\t\t Discount of the product: ";cin>>dsc;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<Pcode<<" "<<Pname<<" "<<price<<" "<<dsc<<"\n";
		data.close();
	}else{
		data>>c>>n>>p>>d;
		
		while(!data.eof()){
		if(c==Pcode){
			token++;
		}
		data>>c>>n>>p>>d;
		}
		data.close();
	}
	if(token==1){
		goto m;
	}else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<Pcode<<" "<<Pname<<" "<<price<<" "<<dsc<<"\n";
		data.close();
	}
	cout<<"\n\n\t\t\t\t Record added.";
}
void shop :: edit(){
	fstream data, data1;
	int Pkey, token=0, c;
	float p,d;
	string n;
	
	cout<<"\n\t\t\t Modify record:";
	cout<<"\n\n\t\t\t\t Enter product code: "; cin>>Pkey;

	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n File doesn't exist.";
	}else{
		data1.open("database1.txt", ios::app|ios::out);
		
		data>>Pcode>>Pname>>price>>dsc;
		while(!data.eof()){
			if(Pkey==Pcode){
				cout<<"\n\t\t\t\t Product new code: "; cin>>c;
				cout<<"\n\n\t\t\t\t Name: "; cin>>n;
				cout<<"\n\t\t\t\t Price:"; cin>>p;
				cout<<"\n\t\t\t\t Discount: "; cin>>d;			
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
			}else{
				data1<<" "<<Pcode<<" "<<Pname<<" "<<price<<" "<<dsc<<endl;
			}
			data.close();
			data1.close();
			remove("database.txt");
			rename("database1.txt","database.txt");
			
			if(token==0){
				cout<<"\n\n\t\t\t\t Record not found sorry!";
			}
		}
	}
}
void shop :: delet(){
	fstream data,data1;
	int Pkey,token=0;
	cout<<"\n\n\t\t\t\t Delete product";
	cout<<"\n\t\t\t\t Enter product code: "; cin>>Pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"File doesn't exist";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>Pcode>>Pname>>price>>dsc;
		while(!data.eof()){
			if(Pcode==Pkey){
				cout<<"Deleted.";
				token++;
			}
			else{
				data1<<" "<<Pcode<<" "<<Pname<<" "<<price<<" "<<dsc<<endl;
			}
			data>>Pcode>>Pname>>price>>dsc;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token==0){
			cout<<"\n\n Not found record";
		}
	}
}
void shop :: list(){

	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|____________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|____________________________________________\n";
	data>>Pcode>>Pname>>price>>dsc;
	while(!data.eof()){
		cout<<Pcode<<"\t\t"<<Pname<<"\t\t"<<price<<endl;
		data>>Pcode>>Pname>>price>>dsc;
	}
	data.close();
}

void shop :: receipt(){
	fstream data;
	m:
	int arrc[100];
	int arrq[100];
	string choice;
	int c=0;
	float amount;
	float dsc=0;
	float all=0;
	
	cout<<"\n\n\t\t\t\t Receipt";
	data.open("database.txt",ios :: in);
	if(!data){
		cout<<"No data to display. ";
	}else{
		data.close();
		
		list();
		cout<<"\n____________________________________________\n";
		cout<<"\n_____________Place the order________________n";
		cout<<"\n____________________________________________n";
		
		do{
			cout<<"\n\nEnter product: "; cin>>arrc[c];
			cout<<"\n\nHow much you want to order: "; cin>>arrq[c];
			
			for(int i=0;i<c;i++){
				if(arrc[c]==arrc[i]){
					cout<<"You already ordered this product. Change quantity if you want to.";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Wanna buy more products? Yes(y) else no"; cin>>choice;
		}
		while(choice=="y");
		
		cout<<"\n\n\t\t\t\t Receipt\n";
		cout<<"\nProduct No\t Product Name\t Product quantity\tprice\tamount\tamount with discout\n";
		
		for(int i=0;i<c;i++){
			data.open("database.txt",ios::in);
			data>>Pcode>>Pname>>price>>dsc;
			while(!data.eof()){
				if(Pcode==arrc[i]){
					amount=price*arrq[i];
					dsc=amount-(amount*dsc/100);
					all=all+dsc;
					cout<<endl<<Pcode<<"\t\t"<<Pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dsc;
				}
				data>>Pcode>>Pname>>price>>dsc;
			}
		}
		data.close();
	}
	cout<<"\n\n Total amount: "<<all;
}
int main(){
	shop s;
	s.menu();
}
