//this is program on supermarket billing system
#include<iostream>
#include<fstream>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;
class shopping {
private:
    int pcode;
    float price;
    float discount;
    string pname;

 public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu(){
    m:
int choice;


struct Admin{    //
string email;
string password;

};

   map<string , string > emailpassword;  // key value pair 

   emailpassword["soltad65@gmail.com"] = "sola1234";
   emailpassword["zekud@gmail.com"] = "zeku1234";
   emailpassword["yordi@gmail.com"] = "yordi1234";
   emailpassword["sura@gmail.com"] = "sura1234";
   emailpassword["sami@gmail.com"] = "sami1234";





Admin admins;

cout<<"\t\t\t\t_____________________________________________________\n";
cout<<"\t\t\t\t                                                     \n";
cout<<"\t\t\t\t                  Supermarket Main Menu              \n";
cout<<"\t\t\t\t                                                     \n";
cout<<"\t\t\t\t_____________________________________________________\n\n";
cout<<"\t\t\t\t| 1) Administrator          |\n";
cout<<"\t\t\t\t|                           |\n";
cout<<"\t\t\t\t| 2) Buyer                  |\n";
cout<<"\t\t\t\t|                           |\n";
cout<<"\t\t\t\t| 3) exit                   |\n";
cout<<"\t\t\t\t|                           |\n";
cout<<"\n\t\t\t  Please enter your choice: ";
cin>>choice;

switch(choice){
    case 1:
       cout<<"\t\t\t Please login \n";
       cout<<"\t\t\t Enter Email :";
       cin>>admins.email;
       cout<<"\t\t\t Enter Password :";
       cin>>admins.password;


       if(emailpassword.count(admins.email)&& emailpassword[admins.email]== admins.password){
        administrator();
       }
       else {
        cout<<"Invalid email/password";
       }
       break;

    case 2:{
        buyer();
        break;

    }
    case 3:
    {
        exit(0);
        break;
    }
  default : {
    cout<<"Please enter from the given option!";
  }

}
goto m;

}//end of menu


void shopping:: administrator(){
    m:
    int choice;
    cout<<"\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|____1) Add the product_____|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|____2) Modify the product__|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|____3) Delete the product__|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|____4) Back to Main menu___|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\tEnter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
        add();
        break;
        case 2:
        edit();
        break;
        case 3:
        rem();
        break;
        case 4:
        menu();
        break;

        default:
        cout<<"Invalid choice!";

   }
               goto m;
}//end of administrator

void shopping ::buyer(){
    m:
    int choice;
    cout<<"\t\t\t Buyer\n";
    cout<<"\t\t\t_____________________\n";
    cout<<"                             \n";
    cout<<"\t\t\t1)Buy product           \n";
    cout<<"                             \n";
    cout<<"\t\t\t2) Back to main menu     \n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){

        case 1:{
            receipt();
         break;
        }

        case 2:{
           menu();
         break;
        }

        default : cout<<"Invalid  choice!";
    }
    goto m;

}//end of buyer

void shopping::add(){
    m:
fstream data;
int c;
int token=0;
float p;
float d;
string n;

cout<<"\n\n\t\t\t Add new product :";
cout<<"\n\n\t Product code of the product :";
cin>>pcode;
cout<<"\n\n\t Name of the product :";
cin>>pname;
cout<<"\n\n\t Price of the product :";
cin>>price;
cout<<"\n\n\t Discount on product";
cin>>discount;


data.open("database.txt",ios::in);   //open the file to store the product
if(!data){//if the data doesn't exit then store the data on database.txt
    data.open("database.txt",ios::app|ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
    data.close();
}
else {

    data>>c>>n>>p>>d;//initialize the index of the file

    while(!data.eof()){

        if(c==pcode){//checks if there is redundancy in product
          token++;
        }
            data>>c>>n>>p>>d;//read mode for iteration
    }
    data.close();

    if(token==1){
            administrator();
       // goto m; //if there is a duplicate product then the go to top
    }
    else {//if there is no redundancy the store the data
    data.open("database.txt",ios::app|ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
    data.close();

    }
}

cout<<"\n\n\t\t Record inserted successfully!!";

}//end of add


void shopping::edit(){
    fstream data,data1;
    int pkey;
    int c;//product code
    int token=0;
    float p;
    float d;
    string n;//name of the new product

    cout<<"\n\t\t\t Modify the record!";
    cout<<"\n\t\t\t Product code ";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data){
    cout<<"\n\nFile doesn't exist!! ";
           }
     else {

    data1.open("database1.txt",ios::app|ios::out);

    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
        if(pkey==pcode){
         cout<<"\n\t\t Product new code :";
         cin>>c;
         cout<<"\n\t\t Name of the  Product :";
         cin>>n;
         cout<<"\n\t\t Product new price :";
         cin>>p;
         cout<<"\n\t\t New discount :";
         cin>>d;

             data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";

           cout<<"\n\n\t\t Record edited!!";
           token++;
        }
        else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        }
            data>>pcode>>pname>>price>>discount;
    }
    data.close();
    data1.close();

     remove("database.txt");
     rename("database1.txt","database.txt");

  if(token==0){
    cout<<"\n\n Record is not found";
  }
}
}//end of edit

void shopping::rem(){
    fstream data,data1;
    int pkey,token=0;

// <<<<<<< HEAD
    cout<<"\n\n\t ***Delete product***";
    cout<<"\n\n\t Enter product code: ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exit!";
    }
    else {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;

        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted successfully!";
                token++;
            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
            }
            data>>pcode>>pname>>price>>discount;
        }
       data.close();
       data1.close();

     remove("database.txt");
     rename("database1.txt","database.txt");
        if (token==0){
    cout<<"\n\n Product is not found!";
                     }
    }

}//end of remove product


void shopping:: list(){
    fstream data;
    data.open("database.txt",ios::in);

    cout<<"\n\n|_____________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|_____________________________________________________\n";
    data>>pcode>>pname>>price>>discount;

    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<endl;
            data>>pcode>>pname>>price>>discount;

    }
    data.close();

}//end of list function

void shopping:: receipt(){

    fstream data;
    int arrc[100],arrq[100],c=0;//array is used to store many product codes and quantities are ordered by the customer
    char choice;
    float amount=0,dis=0,total=0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);

    if(!data){
        cout<<"File doesn't exist!!";
    }

    else {
data.close();
list();//ccall the list function for available products
cout<<"\n___________________________________________\n";
cout<<"\n|                                          \n";
cout<<"\n|       Please place the order              \n";
cout<<"\n|                                          \n";
cout<<"\n___________________________________________\n";

 do{
    m:
    cout<<"\n\nEnter the product code :";
    cin>>arrc[c];
    cout<<"\n\nEnter the product quantity :";
    cin>>arrq[c];
    for (int i=0;i<c;i++){
        if(arrc[c]==arrc[i]){
            cout<<"\n\nDuplicate product code. please try again!";
            goto m;
        }
    }
    c++;
    cout<<"\n\n Do you want to buy another product?\n\tif yes press y\n\tno press n";
    cin>>choice;
 }while(choice=='y');

 cout<<"\n\n\t\t\t________________________RECEIPT________________________\n";
 cout<<"\nProduct No\t Product name\t Product Quantity\t Price\t Amount\tAmount with discount\n";

 for(int i=0;i<c;i++){

     data.open("database.txt",ios::in);
     data>>pcode>>pname>>price>>discount;
while(!data.eof()){

    if(pcode==arrc[i]){
        amount=price*arrq[i];
        discount=amount-(amount*discount/100);
        total+=discount;
        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
    }
     data>>pcode>>pname>>price>>discount;

}


 }
 data.close();

}
cout<<"\n\n_________________________________________________________";
cout<<"\n Total Amount :"<<total;

}//end of receipt

int main(){
    shopping s;
    s.menu();
}
// =======
// }//end of remaning
// >>>>>>> 92baa1ca4adb961784e050e52e8471b8ee363f59
