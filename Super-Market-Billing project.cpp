#include<iostream>
#include<fstream>
using namespace std;
class Shopping
{
	private:
		int pcode;
		float price;
		float dis;
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
void Shopping::menu()
{
	m:
		int choice;
		string email;
		string password;
		cout<<"\t\t\t\t *****************************************\n";
		cout<<"\t\t\t\t                                          \n";
		cout<<"\t\t\t\t   WELCOME TO SUPER MARKET                  \n";
		cout<<"\t\t\t\t                                            \n";
		cout<<"\t\t\t\t ********************************************\n";
		cout<<"\t\t\t\t                                              \n";
		
		cout<<"\t\t\t\t| 1)    ADMINISTRATOR                          |\n";
		cout<<"\t\t\t\t                                                \n";
	    cout<<"\t\t\t\t| 2)    BUYER                                  |\n";
	    cout<<"\t\t\t\t                                                \n";
	    cout<<"\t\t\t\t| 3)    EXIT                                   |\n";
	    cout<<"\t\t\t\t|                                              |\n";
	    cout<<"\n\t\t\t     PLEASE SELECT!";
	    cin>>choice;
	    switch(choice)
	    {
	    	case 1:
	    		{
				
	    		cout<<"\t\t\t PLEASE LOGIN  \n";
	    		cout<<"\t\t\t  Enter Administrator Email  \n";
	    		cin>>email;
	    		cout<<"\t\t\t    Enter Administrator Password   \n";
	    		cin>>password;
	    		if(email== "gouri@email.com" && password == "gouri@123")
	    		{
	    			administrator();
				}
				else{
					cout<<"Invalid email or password";
				}
				break;
			}
				
				case 2:
					{
						buyer();
					}
					
					case 3:
						{
                            cout<<"Thankyou for visiting";
							exit(0);
						}
						default:
							{
								cout<<"INVALID CHOICE!. PLEASE TRY AGAIN";
							}
		}
		goto m;
	}
	void Shopping :: administrator()
	{
		m:
			int choice;
			cout<<"\n\n\n\t\t\t============ ADMINISTRATOR MENU  ======";
			cout<<"\n\n\n\t\t\t|_________  1) Add the product_________|";
			cout<<"\n\n\n\t\t\t|                                      |";
		    cout<<"\n\n\n\t\t\t|_________  2) Modify the product______|";
		    cout<<"\n\n\n\t\t\t|                                      |";
		    cout<<"\n\n\n\t\t\t|_________  3) Delete the product______|";
		    cout<<"\n\n\n\t\t\t|                                      |";
		    cout<<"\n\n\n\t\t\t|_________  4) Back to Main Menu_______|";
		    
		    cout<<"\n\n\t  Please enter your choice here :";
		    cin>>choice;
		    
		    switch(choice)
		    {
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
		    					cout<<"Invalid Choice!";
		    				}
		    				goto m;
		    			}
		    			void Shopping :: buyer()
		    			{
		    				m:
		    					int choice;
		    					cout<<"\t\t\t_____  1)BUYER ____ \n";
		    					cout<<"\t\t\t______________________\n";
		    					cout<<"\t\t\t_____  2)Buy product____ \n";
		    					cout<<"\t\t\t                          \n";
		    					cout<<"\t\t\t_____  3)Go back __________\n";
		    					cout<<"\t\t\t                            \n";
		    					cout<<"\t\t\t Enter your choice:";
		    					cin>>choice;
		    					
		    					switch(choice)
		    					{
		    						case 1:
		    							receipt();
		    							break;
		    							
		    							case 2:
		    								menu();
		    								
		    								default:
		    									cout<<"Invalid Choice";
								}
								goto m;
							}

                            
                            
		    				void Shopping :: add()
							{
								m:
									fstream data;
									int c;
									int token =0;
									float p;
									float d;
									string n;
									cout<<"\n\n\t\t\t  Add new product";
									cout<<"\n\n\t  Product code of the product : ";
									cin>>pcode;
									cout<<"\n\n\t Name of the product : ";
									cin>>pname;
									cout<<"\n\n\t  Price of the product: ";
									cin>>price;
									cout<<"\n\n\t  Discount on product: ";
									cin>>dis;
									data.open("database.txt",ios::in);
									if(!data)
									{
										data.open("database.txt",ios::app|ios::out);
										data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
										data.close();
									}
									else
									{
										data>>c>>n>>p>>d;
										while(!data.eof())
										{
											if(c==pcode)
											{
												token++;												
											}
											data>>c>>n>>p>>d;
										}
										data.close();
										if(token == 1)
										goto m;
										else{
											data.open("database.txt",ios::app|ios::out);
											data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
											data.close();
										}
									}
									cout<<"\n\n\t\t Record Inserted!";
								}
								
								void Shopping :: edit()
								{
									fstream data,data1;
									int pkey;
									int token = 0;
									int c;
									float p;
									float d;
									string n;
									
									
									cout<<"\n\t\t\t  Modify the record";
									cout<<"\n\t\t\t  Product Code: ";
									cin>>pkey;
									data.open("database.txt",ios::in);
									if(!data)
									{
										cout<<"\n\n File doesn't exist!";
									}
									else{
										data1.open("database1.txt",ios::app|ios::out);
										data>>pcode>>pname>>price>>dis;
										while(!data.eof())
										{
											if(pkey==pcode)
											{
												cout<<"\n\t\t  Product new code: ";
												cin>>c;
												cout<<"\n\t\t  Name of the product: ";
												cin>>n;
												cout<<"\n\t\t  Price: ";
												cin>>p;
												cout<<"\n\t\t  Discount: ";
												cin>>d;
												data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
												cout<<"\n\n\t\t  Record edited";
												token++;
											}
											else{
												data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
											}
											data>>pcode>>pname>>price>>dis;
										}
										data.close();
										data1.close();
										remove("database.txt");
										rename("database.txt","database.txt");
										if(token == 0)
										{
											cout<<"\n\n Record not found!";
										}
									}
									}	
		    					
		    					void Shopping :: rem()
		    					{
		    						fstream data,data1;
		    						int  pkey;
		    						int token =0;
		    						cout<<"\n\n\t Delete Product";
		    						cout<<"\n\n\t Product Code: ";
		    						cin>>pkey;
		    						data.open("database.txt",ios::in);
		    						if(!data)
		    						{
		    							cout<<"File doesn't exist!";
									}
									else{
										data1.open("database1.txt",ios::app|ios::out);
										data>>pcode>>pname>>price>>dis;
										while(!data.eof())
										{
											if(pcode == pkey){
												cout<<"\n\n\t  Product deleted succesfully";
												token++;
											}
											else{
												data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
											}
											data>>pcode>>pname>>price>>dis;
										}
										data.close();
										data1.close();
										remove("database.txt");
										rename("database1.txt","database.txt");
										if(token == 0)
										{
											cout<<"\n\n Record not found";
										}										
									}
								}
								 
								 void Shopping:: list()
								 {
								 	fstream data;
								 	data.open("database.txt",ios::in);
								 	cout<<"\n\n|_________________________|\n";
								 	cout<<"ProductNo\t\tName\t\tPrice\n";
								 	cout<<"\n\n|_________________________|\n";
								 	data>>pcode>>pname>>price>>dis;
								 	while(!data.eof())
								 	{
								 		cout<<pcode<<"\t\t"<<pname<<"\\t\t"<<price<<"\n";
								 		data>>pcode>>pname>>price>>dis;
									 }
									 data.close();
								 	
								 }
                                /* void searchProduct(){
                                    int pcode;
                                    float price;
                                    float dis;
                                    string pname;
                                string searchName;
                                cout<<"Enter product name to search : ";
                                cin>>searchName;
                                fstream data;
                                data.open("data.txt",ios::in);
                                if(!data){
                                    cout<<"NO PRODUCT FOUND!";
                                    return;
                                }
                                int found = 0;
                                while(data>>pcode>>pname>>price>>dis){
                                    if(pname==searchName){
                                        cout<<"Product Found: code: "<<pcode<<"name: "<<price: "<<",DIscount: ";
                                                                         
                                    found = 1;
                                   }
                                }
                                if(!found){
                                    cout<<"No product with name: "<<searchName<<"found\n";
                                }
                                data.close();
                                 } */

								 
								 void Shopping :: receipt()
								 {
								 	fstream data;
								 	int arrc[100];
								 	int arrq[100];
								 	char choice;
								 	int c = 0;
								 	float amount = 0;
								 	float dis = 0;
								 	float total = 0;
								 	cout<<"\n\n\t\t\t  RECEIPT";
								 	data.open("database.txt",ios::in);
								 	if(!data)
								 	{
								 		cout<<"\n\n Empty database";								 		
									 }
									 else{
									 	data.close();
									 	list();
									 	cout<<"\n===================================\n";
									 	cout<<"\n                                   \n";
									 	cout<<"\n  Please place the order \n";
									 	cout<<"\n                                   \n";
									 	cout<<"\n====================================\n";
									 	
									 	do{
									 		m:
									 			cout<<"\n\n Enter Product code: ";
									 			cin>>arrc[c];
									 			cout<<"\n\n Enter the product quality: ";
									 			cin>>arrq[c];
									 			for(int i=0; i<c; i++)
									 			{
									 				if(arrc[c] == arrc[i])
									 				{
									 					cout<<"\n\n Duplicate product code. Please try again!";
									 					goto m;
													 }
												 }
												 c++;
												 cout<<"\n\n Do you want to buy another product? if yes then press y else  no";
												 cin>>choice;
												 
										 }
										 while(choice =='y');
										 cout<<"\n\n\t\t\t__________________RECEIPT_____________________\n";
										 cout<<"\nProductNo\t product Nmae\t product quantity\t price\t Amount\t Amount with discount\n";
										 for(int i=0; i<c; i++)
										 {
										 	data.open("database.txt",ios::in);
										 	data>>pcode>>pname>>price>>dis;
										 	while(!data.eof())
										 	{
										 		if(pcode== arrc[i])
										 		{
										 			amount = price * arrc[i];
													 dis = amount - (amount*dis/100);
													 total = total + dis;
													 cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
												 }
												 data>>pcode>>pname>>price>>dis;

											 }											 
										 }
										 data.close();
									 	
									 }
									 cout<<"\n\n______________________________________";
									 cout<<"\n Total Amount : "<<total;
								 }
								 
								 int main()
								 {
								 	Shopping s;
								 	s.menu();
								 }
						
		    			
			
		    
		     
		    
		    
	
	    
	    
	    
		
		
		

