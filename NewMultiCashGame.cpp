#include<iostream>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<time.h>
#include<iomanip>

using namespace std;    

void login();
int menu();
void help();
void displayLetterGrid();
int ** randomHiddenGrid();
int insertInitialAmount();
void selection_options();
void calculate_and_display_amount(string &player_name);
string getName();
void store_data(string &player_name,int &initial_amount,int &attempts,int &amount1,int &amount2,int &amount3,int &bonus,double &penalty_charge,double &total_amount);
void view_player_details();
void create_new_admin_account();
void new_user_registration();
void reset_password();

void main(){
	selection_options();    
}

void selection_options(){   //method for select menu options.
  int choice=7;            //variable for store menu option
  while(choice!=6 && choice!=1){
    choice=menu();
	cout<<"\n";
	system("pause");
	switch(choice){
	  case 1:{   
		         system("cls");
		         login();
			 }
	             break;
	  case 2:{
			    system("cls");
				view_player_details();
			 }
			     break;
	  case 3:{
			     system("cls");
				 create_new_admin_account();
			 }
			     break;
	  case 4:{
			     system("cls");
				 new_user_registration();
			 }
			     break;
	case 5:{
			     system("cls");
				 reset_password();
			 }
			     break;
	  case 6:{
		         system("cls");
		         cout<<"\n*****************THANK U****************"<<endl;
			 }
		         break;
	  default:{
		        cout<<"!!!!!!!!!!!!!!!!!!!SORRY...INVALID CHOICE.PLEASE TRY AGAIN!!!!!!!!!!!!!!!!!!!!"<<endl;
		        Sleep(1000);
			  }
	  }
	  
	}
}

void login(){

      string user,pass,user_name,password,headline;  
	  ifstream logintext;
	  int count=0;           //variable for control the while loop

	  cout<<"\n                            LOGIN                            "<<endl;
      cout<<"*************************************************************"<<endl;

	  while(count<3){

		  cout<<"\n* ENTER USER NAME       :";
		  cin.clear();		 
		  cin.ignore(10000000,'\n');
		  cin>>user_name;   //get user name from the user
		  cout<<"\n* ENTER PASSWORD        :";
		  cin>>password;   //get password from the user
  
		  logintext.open("Authentication.txt");	  
		  getline(logintext,headline);  //read headline from the text file
		  logintext>>user>>pass;   //read user name and password from the text file
          while(logintext){ 

		        if(strcmpi(user_name.c_str(),user.c_str())==0 && password==pass){  //user name is case insensitive

					count=3;
					cout<<"\n\n*************USER NAME AND PASSWORD ARE CORRECT**************"<<endl;
					cout<<"\n@@@@@@@@@@@@@YOU ARE ALLOWED TO ACCESS NEXT STEP@@@@@@@@@@@@@"<<endl;	
					cout<<"\n";
					system("pause");
					system("cls");
					help();
					displayLetterGrid();
					calculate_and_display_amount(getName());
					return;
		        }
	            logintext>>user>>pass;  //read user name and password from the text file
          }
          if(count<2){  //check whether attempts exeeds the limit.

			  count+=1;
			  cout<<"\n\n!!!!!!!!!!!!!WARNING:LOGIN DETAILS ARE INCORRECT!!!!!!!!!!!!!"<<endl;
			  cout<<"\n!!!!!!!!!!!!!!!!!!!!!YOU HAVE "<<3-count<<" ATTEMPTS!!!!!!!!!!!!!!!!!!!!!"<<endl;
	      }else if(count==2){

			  cout<<"\n\n!!!!!WARNING:ATTEMPTS EXCEED THE LIMIT.SYSTEM IS LOCKED!!!!!!";
			  cout<<"\n";
			  system("pause");
			  selection_options();
			  return;
	      }
          logintext.close();
	  }
  }

int menu(){  
	int choice;  //to store menu option
	system("cls");
    cout<<"\n******************************Menu*******************************"<<endl;
    cout<<"\n* 1.LOGIN                                                       *"<<endl;    
	cout<<"\n* 2.VIEW PLAYERS' DETAILS                                       *"<<endl;
	cout<<"\n* 3.CREATE NEW ADMIN ACCOUNT                                    *"<<endl;
	cout<<"\n* 4.NEW USER REGISTRATION                                       *"<<endl;
	cout<<"\n* 5.RESET PASSWORD                                              *"<<endl;
	cout<<"\n* 6.EXIT                                                        *"<<endl;
	cout<<"\n*****************************************************************"<<endl;
    cout<<"\nENTER YOUR CHOICE(1,2,3,4,5 or 6):";
    cin>>choice;
    return choice;
}

void help(){
	system("cls");
    cout<<"\n************************GUIDLINES FOR THE NEW USER**************************"<<endl;
	cout<<"\n*1.Player can insert the initial amount to start the game.                 *"<<endl;
	cout<<"\n*2.Player can select any letter any of the letter from the Letter Grid.    *"<<endl;
	cout<<"\n*3.Once the player inserts the selected letter,winning amount is displayed *\n   on the screen."<<endl;
	cout<<"****************************************************************************"<<endl;
	cout<<"\n\n\n*************************RULES AND REGULTAIONS******************************"<<endl;
	cout<<"\n*1.Initial amount must be between Rs.500-Rs.10000.                         *"<<endl;
	cout<<"\n*2.Player can pick only one letter at a time.                              *"<<endl;
	cout<<"\n*3.One player can select the lucky letter for 3 attempts.                  *"<<endl;
	cout<<"\n*4.Players who get the same value in all 3 attempts(other than zero) will  *\n   get bonus amount of Rs.500."<<endl;
	cout<<"\n*5.If the palyer wish to exit the game after first or second attempt       *\n   5% penalty will be deducted from the winning amount."<<endl;
	cout<<"****************************************************************************"<<endl;
	cout<<"\n"<<endl;
	system("pause");
	
  }

void displayLetterGrid(){

	   system("cls");
	   char letters[4][4]={{'A','B','C','D'},{'E','F','G','H'},{'I','J','K','L'},{'M','N','O','P'}};

	   cout<<"************************LETTER GRID***************************"<<endl;
	   cout<<"\n";

	   for(int i=0;i<22;i++){  //loop for counting spaces
		   cout<<" ";
	   }

	   for(int j=0;j<9;j++){
		   cout<<"- ";
	   }

	   cout<<"\n";

	   for(int k=0;k<4;k++){
		   for(int l=0;l<22;l++){
			   cout<<" ";     //loop for counting spaces
		   }

		   for(int m=0;m<4;m++){
			   cout<<"| "<<letters[k][m]<<" ";
			   if(m==3){
			      cout<<"|";
			   }
		   }

		   cout<<"\n";

		   for(int n=0;n<22;n++){
			   cout<<" ";    //loop for counting spaces
		   }

		   for(int p=0;p<9;p++){
		       cout<<"- ";
		   }

		   cout<<"\n";
	   }
	}

int ** randomHiddenGrid(){
	static int ** random_numbers=new int *[4];
	
	srand(time(NULL));
	for(int a=0;a<4;a++){
		random_numbers[a]=new int[4];
		for(int b=0;b<4;b++){	      
	        random_numbers[a][b]=rand()%6;		  
		}
	}
	return random_numbers;
}

string getName(){            //function for get player name
	string player_name;  //to store player name
	cout<<"\n\n* ENTER YOUR NAME                                   :";
	cin.clear();		 
	cin.ignore(10000000,'\n');
	getline(cin,player_name);
	return player_name;
  }

int insertInitialAmount(){

	int int_amount;  //to store intial amount
	int countloop=1; //variable for control the while loop	
	int count_attempt=0;  //variable for counting number of attempts

	while(countloop!=0 && count_attempt<3){

		cout<<"\n\n* ENTER VALID INITIAL AMOUNT BETWEEN Rs.500-Rs.10000\n  (WARNING:PLEASE DON'T INSERT CENTS,CENTS PART\n   WILL BE IGNORED AUTOMATICALLY)                   :";  //no decimal values   
  		cin>>int_amount;    //it takes only integer part of the input,so if the user enters 45j it takes only 45 as the input. 
		countloop=0;
		count_attempt+=1;   

		if(cin.fail()){   //check whether input is valid or not
			  cin.clear();		 
			  cin.ignore(10000000,'\n');

			  if(count_attempt<3){  //check whether attempts exceed the limit
					   cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!!!YOU HAVE "<<3-count_attempt<<" MORE ATTEMPTS!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;	       
					   countloop=1; 	   
			  }else{
					   cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!!!WARNING:NO MORE ATTEMPTS!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
					   cout<<"\n";
					   system("pause");
					   selection_options();
					   return 0;
			  }
		}else{   
		      if(int_amount<500 || int_amount>10000){  //check whether value is equal and greater than 500 and equal and less than 10000
			           if(count_attempt<3){
						    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!!!YOU HAVE "<<3-count_attempt<<" MORE ATTEMPTS!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;	         
						    countloop=1;		 
			           }else{
				            cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!!!WARNING:NO MORE ATTEMPTS!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
				            cout<<"\n";
				            system("pause");
				            selection_options();
				            return 0;
			           }
		      }
		      cin.clear();		 
		      cin.ignore(10000000,'\n');
		}
   
    }
	return int_amount;
}

void calculate_and_display_amount(string &player_name){   
		
		string player_name1=player_name;           //variable to store player name		
		int initial_amount=insertInitialAmount();  //assigning initial_amount 
		int bonus=0;                               //to store bonus amount
		double total_amount=initial_amount;        //to store total winning amount
		double penalty_charge=0;                   //to store penalty charge 
		double current_amount=total_amount;        //to store amount,win at one round.		
		int count_loop=0;                          //to store game round
		int multiply=0;                            //to store random hidden value
		int check_repeat=0;		                   //to check whether valid game round or not.
		char letter;                               //to store user input letter
		char yes_no;                               //variable to control the exit the game
		bool want_to_break=false;                  //to break the outer loop of nested for loop
		bool matched_the_letter=false;             //to check the any letter matches with the input
		int array_ele1=0;                          //to increment multiply_per_attempt array index
		int array_ele2=0;                          //to increment multiply_per_attempt array index

		int ** newrandom_numbers;
		newrandom_numbers=randomHiddenGrid();      //assigning random hidden values to array.
		
		char letters[4][4]={{'A','B','C','D'},{'E','F','G','H'},{'I','J','K','L'},{'M','N','O','P'}};
		int count_selection[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};  //to store number of times the letter has selected
		int multiply_per_attempt[3]={0,0,0};     //to store hidden value in each round
		int amount_per_attempt[3]={0,0,0};     //to store amount winning in each round

		while(count_loop<3){   //loop for control the 3 attempts
			cout<<"\n\n* ENTER YOUR LUCKY LETTER                           :";  //prompt user to enter the letter			
			cin>>letter;
			count_loop+=1;

			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(letter==letters[i][j]){   //check letter is matching with the letter grid                          
 						if(count_selection[i][j]==0){ //check whether the selected letter is already selected or not.
						   multiply=newrandom_numbers[i][j]; //get hidden random value.
						   count_selection[i][j]+=1;    
						   want_to_break=true;
						   matched_the_letter=true;
						   break;
						}else{
						   cout<<"\n\n!!WARNING:YOU HAVE SELECTED THIS LETTER ALREADY.PLEASE SELECT ANOTHER ONE!!"<<endl;
					       count_loop-=1;
						   check_repeat+=1;
						   want_to_break=true;
						   matched_the_letter=true;
						   break;
						}  
					}
				}
				if(want_to_break){
				   break;
				}
				
			}
			if(matched_the_letter==false){      //check validity of the letter
				cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!WARNING:ENTER VALID LETTER!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
				cin.clear();
				cin.ignore(1000,'\n');
				count_loop-=1;
				check_repeat+=1;
			}
			if(check_repeat==0){  //If user has been entered valid letter,calculation is done				
				total_amount=total_amount*multiply;			
				multiply_per_attempt[array_ele1]=multiply;
				amount_per_attempt[array_ele2]=total_amount;
				array_ele1++;
				array_ele2++;
				cout<<"\n\n* YOUR WINNING AMOUNT                               :";                       
				cout<<"Rs."<<current_amount<<"x"<<multiply<<"=Rs."<<total_amount<<endl;
				current_amount=total_amount;		
			}			
			if(count_loop<3 && check_repeat==0 && matched_the_letter==true){   //user is allowed to exit the game after finishing the round, that he took successfully.
				cout<<"\n\n* DO YOU WANT TO EXIT THE GAME?\n  (ENTER Y/y FOR YES & N/n FOR NO)                  :";
				cin>>yes_no;
				do{
					switch(yes_no){
					    case 'Y':case 'y':{
						                      if(total_amount>0){
									              penalty_charge=(total_amount*5)/100;
									              total_amount=(total_amount*95)/100;
							                  }else{
							                      penalty_charge=0;
								                  total_amount=0;
							                  }
									          cout<<"\n\n* PENALTY CHARGE Rs.                                :"<<penalty_charge<<endl;
									          cout<<"\n\n* YOUR TOTAL WINNING AMOUNT Rs.                     :"<<total_amount<<endl;
									          store_data(player_name1,initial_amount,count_loop,amount_per_attempt[0],amount_per_attempt[1],amount_per_attempt[2],bonus,penalty_charge,total_amount);  //store data
									          cout<<"\n";
									          system("pause");
									          selection_options();
									          return;
									     }
							             break;
					    case 'N':case 'n':;
						                 break;
					    default:{cout<<"\n\n* WARNING:ENTER VALID LETTER                        :";
						                 cin>>yes_no;
							    }
					
					}
				}while(yes_no!='Y' && yes_no!='y' && yes_no!='N' && yes_no!='n');
			}
			check_repeat=0;
			want_to_break=false;
			matched_the_letter=false;
		}
		if(count_loop==3 && multiply_per_attempt[0]!=0 && multiply_per_attempt[1]!=0 && multiply_per_attempt[2]!=0){ //Player who get the same multiply value in all 3 attempts
			if(multiply_per_attempt[0]==multiply_per_attempt[1]==multiply_per_attempt[2]){                         //(other than zero) will get bonus amount of Rs.500 
			    total_amount+=500;
			    bonus=500;
			}  
		}
	
		system("pause");
		system("cls");
		cout<<"********************THE FINAL REPORT********************"<<endl;
		cout<<"* PLAYER NAME                        :"<<player_name1<<endl;
		cout<<"* NUMBER OF ATTEMPTS                 :3"<<endl;
		cout<<"* WINING AMOUNT OF FIRST ATTEMPT  Rs.:"<<amount_per_attempt[0]<<endl;
		cout<<"* WINING AMOUNT OF SECOND ATTEMPT Rs.:"<<amount_per_attempt[1]<<endl;
		cout<<"* WINING AMOUNT OF THIRD ATTEMPT  Rs.:"<<amount_per_attempt[2]<<endl;
		cout<<"* BONUS                           Rs.:"<<bonus<<endl;
		cout<<"* PENALTY CHARGE                  Rs.:"<<penalty_charge<<endl;
		cout<<"* TOTAL WINING AMOUNT             Rs.:"<<total_amount<<endl;
		
		store_data(player_name1,initial_amount,count_loop,amount_per_attempt[0],amount_per_attempt[1],amount_per_attempt[2],bonus,penalty_charge,total_amount);  //store data
		
		delete[] newrandom_numbers;  //delete the ram space allocated for the array
		cout<<endl;
		system("pause");
		selection_options();
		array_ele1=0;
		array_ele2=0;
		return;
	}

void store_data(string &player_name,int &initial_amount,int &attempts,int &amount1,int &amount2,int &amount3,int &bonus,double &penalty_charge,double &total_amount){
	    ofstream store_file;
		ifstream get_file;		
		string content;          //to store the content of text file
		bool has_content=false;  //check whether the text file already has some content

		get_file.open("PlayerRecords.txt",ios::in);
		getline(get_file,content);		
		while(!get_file.eof()){
		      has_content=true;
		      getline(get_file,content);
		}
		get_file.close();

		store_file.open("PlayerRecords.txt",ios::app);		
		if(has_content==false){
		      store_file<<left<<setw(50)<<"PLAYER NAME"<<setw(50)<<"INITIAL AMOUNT"<<setw(50)<<"NUMBER OF ATTEMPTS"<<setw(50)<<"WINING AMOUNT OF FIRST ATTEMPT(Rs.)"<<setw(50)<<"WINING AMOUNT OF SECOND ATTEMPT(Rs.)"<<setw(50)<<"WINING AMOUNT OF THIRD ATTEMPT(Rs.)"<<setw(50)<<"BONUS(Rs.)"<<setw(50)<<"PENALTY CAHRGE(Rs.)"<<setw(50)<<"TOTAL WINNING AMOUNT(Rs.)"<<endl;
		      store_file<<left<<setw(50)<<player_name<<setw(50)<<initial_amount<<setw(50)<<attempts<<setw(50)<<amount1<<setw(50)<<amount2<<setw(50)<<amount3<<setw(50)<<bonus<<setw(50)<<penalty_charge<<setw(50)<<total_amount<<endl;
		}else{
		      store_file<<left<<setw(50)<<player_name<<setw(50)<<initial_amount<<setw(50)<<attempts<<setw(50)<<amount1<<setw(50)<<amount2<<setw(50)<<amount3<<setw(50)<<bonus<<setw(50)<<penalty_charge<<setw(50)<<total_amount<<endl;
		}
		cout<<"\n SAVED SUCCESSFULLY"<<endl;
		store_file.close();
}

void view_player_details(){      //open PlayerRecord text file
	string pass;                 //variable to store admin password entered by the user
	int i;                       //variable to control the while loop
	int count_loop=0;            //variable to control the attempts

	cout<<"*************WELCOME TO VIEW PLAYER DETAILS PAGE***********"<<endl;
    cout<<"\n TO CONTINUE ENTER ADMIN PASSWORD:";
	cin>>pass;
	do{		
		i=0;
		count_loop+=1;
		ifstream admin_file;     
		string password;         //variable to store admin password read from the text file   
		string user_name;        //variable to store admin user_name read from the text file

		admin_file.open("admin_account.txt");
		admin_file>>user_name;
		while(admin_file){		
			  admin_file>>password;
	    }
		admin_file.close();

        if(password!=pass){     //check whether user entered password with the text file password
          i++;
	      cout<<"\n ENTER VALID PASSWORD:";
		  cin.clear();
		  cin.ignore(100000000,'\n');
		  cin>>pass;
        }else{
			system("cls");
		    string file = "notepad.exe PlayerRecords.txt";
            system(file.c_str());
			return;
	    }      

	}while(i!=0 && count_loop<2);
	    cout<<"\n YOU ARE FAILED IN ALL 3 ATTEMPTS.SORRY"<<endl;
	    cout<<"\n";
	    system("pause");
	    return;		
         
}
 
void create_new_admin_account(){
   cout<<"**************WELCOME TO NEW ADMIN REGISTRATION PAGE**************"<<endl;
   
   ifstream admin_file;
   string content;          //to store content of the text file
   bool has_content=false; //to check the text file already has some content

   admin_file.open("admin_account.txt");
   admin_file>>content;
   while(admin_file){
		 has_content=true; 
		 admin_file>>content;
   }

   if(has_content){
	     char option;  //to store yes or no option
         cout<<"\n* ADMIN HAS ALREADY REGISTERED.DO YOU WANT TO MODIFY THE DETAILS?"<<endl;
	     cout<<"* ENTER Y OR y FOR YES AND N OR n FOR NO         :";
	  
	           do{		  
		             cin>>option;
	                 switch(option){
	                       case 'Y':case 'y':{
			                                   int i=0;
		                                       string pass;
		                                       cout<<"\n* TO CONTINUE ENTER THE CURRENT PASSWORD         :";
						                       do{
						                           cin>>pass;    //to store admin password entered by the user
						                           cin.clear();
						                           cin.ignore(10000000,'\n');
						                           i++;

						                           if(content==pass){
														  string user_name,password;	
														  int w;

														  do{
															 w=0;   //variable to control the do-while loop
															 cout<<"\n* ENTER NEW USER NAME(USER NAME MUST BE ONE WORD):";  								   
															 getline(cin,user_name); //get new password from the user
															 for(int i=0;i<user_name.length();i++){
																 if(user_name.substr(i,1)==" "){  //check whether user name is one word or not
																	 w++;
																	 cin.clear();
																	 cin.ignore(10000000,'\n');
																 }
															 }
														  }while(w==1);

														  cout<<"\n* ENTER NEW PASSWORD                             :";
														  cin>>password;  //get new password from the user

														  ofstream modify_file;
														  modify_file.open("admin_account.txt");
														  modify_file<<user_name<<"\t"<<password<<endl;
														  modify_file.close();
														  cout<<"\n MODIFIED SUCCESSFULLY."<<endl;
														  cout<<endl;
														  system("pause");
														  return;
						                           }else{
						                                  cout<<"\n* ENTER VALID PASSWORD                           :";
					                               }
						                       }while(i<3);
						                       return;
			                                 }
			                                 break;
	                       case 'N':case 'n':{			               
						                       return;
			                                 }
			                                 break;
	                       default:{
			                                 cout<<"\n* ENTER VALID LETTER                             :";
				                             cin.clear();
		                                     cin.ignore(10000000,'\n');
			                       }
			                                 break;
	                 }
	           }while(option!='Y' && option!='y' && option!='N' && option!='n');
   }else{
               string user_name,password;
		       int w;
		       cin.clear();
		       cin.ignore(1000000,'\n');
		             do{
			               w=0;
			               cout<<"\n* ENTER USER NAME(USER NAME MUST BE ONE WORD)   :";			
			               getline(cin,user_name);
			               for(int i=0;i<user_name.length();i++){
							       if(user_name.substr(i,1)==" "){
									         w++;
									         cin.clear();
		                                     cin.ignore(10000000,'\n');
									}
						   }
			         }while(w==1);			
		
		       cout<<"\n* ENTER PASSWORD                                :";
		       cin>>password;
		       ofstream create_file;
		       create_file.open("admin_account.txt");
		       create_file<<user_name<<"\t"<<password<<endl;
		       create_file.close();
		       cout<<"\n CREATED SUCCESSFULLY."<<endl;
		       cout<<"\n";
		       system("pause");
		       return;  
   }
}
  
void new_user_registration(){    
	string pass;        //variable to store admin password enterd by the user
	int i;              //variable to control the loop
	int count_loop=0;   //variable to count the attempts
	cout<<"*************WELCOME TO NEW USER REGISTRATION PAGE***********"<<endl;
    cout<<"\n TO CONTINUE ENTER ADMIN PASSWORD:";
	cin>>pass;
	cin.clear();
    cin.ignore(100000000,'\n');
	do{
		
		i=0;
		count_loop+=1;
		ifstream admin_file;
		string password;  //variable to store password read from text file        
		string user_name; //varable to store user_name read from text file

		admin_file.open("admin_account.txt");
		admin_file>>user_name;
		while(admin_file){		
			admin_file>>password;
	    }
		admin_file.close();

        if(password!=pass){
            i++;
	        cout<<"\n* ENTER VALID PASSWORD:";		  
		    cin>>pass;
		    cin.clear();
            cin.ignore(100000000,'\n');
        }else{
		    string user_name2,password2;		   		    
			cout<<"\n* ENTER USER NAME(USER NAME MUST BE ONE WORD)   :";  //no validation has done to control user name to one word			
			cin>>user_name2; //get user name from user						
		    cout<<"\n* ENTER PASSWORD:";
		    cin>>password2;  //get password from user

		    ifstream get_data;
		    string content;
		    bool hasContent=false; //variable to check whether text file has content or not
		    get_data.open("Authentication.txt");
		    getline(get_data,content);    //read content from the file
		    while(get_data){
			   hasContent=true;
			   getline(get_data,content); //read content from the file
		    }
	        get_data.close();

            ofstream store_file;
            store_file.open("Authentication.txt",ios::app);
	        if(hasContent==true){
	           store_file<<left<<setw(50)<<user_name2<<setw(50)<<password2<<endl;
	           cout<<"\n CREATED SUCCESSFULLY"<<endl;
			   store_file.close();
			   cout<<"\n";
			   system("pause");
	           return;
	        }else{
			   store_file<<left<<setw(50)<<"User Name"<<setw(50)<<"Password"<<endl;
		       store_file<<left<<setw(50)<<user_name2<<setw(50)<<password2<<endl;
		       cout<<"\n CREATED SUCCESSFULLY"<<endl;
			   store_file.close();
			   cout<<"\n";
			   system("pause");
		       return;
	        }
         
        }

	}while(i!=0 && count_loop<2);
	    cout<<"\n YOU ARE FAILED IN ALL 3 ATTEMPTS.SORRY"<<endl;
	    cout<<"\n";
	    system("pause");
	    return;
}

void reset_password(){     //only admin can reset the password or to reset the password user must have admin permission
    string pass;           //variable to store admin password enterd by the user
	int i;                 //variable to control the loop
	int count_loop=0;      //variable to count the attempts
	cout<<"*************WELCOME TO PASSWORD RESETTING PAGE***********"<<endl;
    cout<<"\n TO CONTINUE ENTER ADMIN PASSWORD:";
	cin>>pass;
	do{		
		i=0;
		count_loop+=1;
		ifstream admin_file;
		string password;    //variable to store password read from text file   
		string user_name;   //varable to store user_name read from text file
		admin_file.open("admin_account.txt");
		admin_file>>user_name;

		while(admin_file){		
			  admin_file>>password;
	    }
		admin_file.close();

        if(password!=pass){
              i++;
	          cout<<"\n ENTER VALID PASSWORD:";
		      cin.clear();
		      cin.ignore(100000000,'\n');
		      cin>>pass;
        }else{
		      string file = "notepad.exe Authentication.txt";
              system(file.c_str());  //open Authentication.txt on the desktop
			  return;
	    }      

	}while(i!=0 && count_loop<2);
	cout<<"\n YOU ARE FAILED IN ALL 3 ATTEMPTS.SORRY"<<endl;
	cout<<"\n";
	system("pause");
	return;
}