#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;
const char* ClassFile(int );
const char* AtenClassFile(int);
const char* FeeFile(int );
int Fixedfee(int );
class Employee{
	  private:
		string name;
		int Age;
		string Email_Id;
	  public:
		virtual void ViewStudentdata()=0;
		virtual void ViewTeacherdata()=0;
		 				
};

class Student: virtual public Employee{
	  private:
		string id;
		string Class;
		string data;
		string temp;
		int trigger;
	  public:
	  	void ViewStudentdata()
	  	{
	  		system("cls");
	  		const char *classfilename;
	//	    string data;
	        fstream fin;
	  		int cl;
	        cout<<"\n\nEnter the class!"<<endl;
	        cin>>cl;
	        if(cl>0&&cl<11)
	        {
	        classfilename=ClassFile(cl);
						
	        fin.open(classfilename);
	        system("cls");
	        cout<<"\n\n\t\t\t\t\t Record Of Class "<<cl<<" \n\n\n\n";
	        while(!fin.eof())
	        {
		      getline(fin,data);
		      cout<<data<<endl;
	        }
	        fin.close();
			}
			else
            {
            	cout<<"\n\n\t\t\tInvalid class entered!"<<endl;
			}
			cout<<endl<<endl<<endl;
			system("Pause");
        }
        
        // friend void TeacherView(Student);
               
         void SearchStudent()
        {
        	system("cls");
        	const char *classfilename;
	        fstream fin;
	  		int cl;
	        cout<<"\n\nEnter the class!"<<endl;
	        fflush(stdin);
	        cin>>cl;
	        fflush(stdin);
			  if(cl>0&&cl<11)
	           {
	            classfilename=ClassFile(cl);
	            fin.open(classfilename);
	            cout<<"\n\nEnter Student ID"<<endl;
	            cin>>id;
	            getline(fin,temp);
	            while(!fin.eof())
	           {
	             getline(fin,data);
	               if(data.compare(0,8,id)==0)
	              {
	              	cout<<"\n\n\t\t\t\t\t\t\t RECORD FOUND !!!";
	              	cout<<"\n\n\n\t\t"<<temp<<endl;
	  	            cout<<"\n\t\t"<<data;
	  	            trigger=1;
	              }
               }
               if(trigger!=1)
               {
               	cout<<"\n\n\t\t\t\t\t\t RECORD NOT FOUND !!!";
			   }
        	   fin.close();
               }
              else
              { 
            	cout<<"\n\n\t\t\tInvalid class entered!"<<endl;
		      }
        	  cout<<endl<<endl<<endl<<endl<<endl;
        	  system("Pause");
		}
          void AddStudent()
        {
    	    system("cls");
	  		int i=0,n;
	        string Email_id;
	        string name;
	        int Age;
	        int Fspace=32;
	        string studid;
	        ofstream fout;
	        const char *classfilename;
	  		int cl;
	        cout<<"\n\nEnter the class!"<<endl;
	        cin>>cl;
	        if(cl>0&&cl<11)
	        {
	         classfilename=ClassFile(cl);
	         cout<<"\n\nNo of student"<<endl;
	         cin>>n;
	         fout.open(classfilename,ios::app);
	          for(i=0;i<n;i++)
	        {
	          cout<<"\n\n\t\t Information Of Student"<<i+1<<endl;
	   	      cout<<"\nEnter student Id (16K-1234):";
	   	      cin>>id;
		      fout<<id;
		      fflush(stdin);
		      cout<<"\nEnter student name :";
	   	      getline(cin,name);
	   	      fflush(stdin);
	   	      fout<<" \t        ";
		      fout<<name;
		      cout<<"\nEnter student Age :";
	   	      cin>>Age;
	   	      for(int j=0;j<(Fspace-name.length());j++)
	          fout<<" ";
	   	      fout<<Age;
	   	      cout<<"\nEnter Email ID  : ";
	   	      cin>>Email_id;
			  fout<<"\t\t";
	   	      fout<<Email_id;
	   	      fout<<"\n";
	   	      cout<<"\n\n\n\t\t\tRecord Has Been Added !!!";
	       }        
           fout.close();
		}
		else
            {
            	cout<<"\n\n\t\t\tInvalid class entered!"<<endl;
			}
			cout<<endl<<endl<<endl;
			system("Pause");
		
    }
         
		 void RemoveStudent()
	{
	        system("cls");
        	const char *classfilename;
	        ifstream fin;
			ofstream fout;
	  		int cl,i=0,n;
	        cout<<"Enter the class!"<<endl;
	        fflush(stdin);
	        cin>>cl;
	        fflush(stdin);
			if(cl>0&&cl<11)
	        {
	            classfilename=ClassFile(cl);
	            cout<<"Enter no of student"<<endl;
	            cin>>n;
	            for(int j=0;j<n;j++)
	            {
	            cout<<"\n\nEnter Student ID : "<<endl;
	            cin>>id;
	            fout.open("temp1.txt",ios::app);
	            fin.open(classfilename);
                while(!fin.eof())
	           {
	             getline(fin,data);
	             if(data.compare(0,8,id)==0)
	             {
	         	 cout<<"\nDeleted!!";
	         	 i=1;
	             }
			    else
                {
	         		fout<<data;
	         		fout<<"\n";
		        }   
               }
                if(i!=1)
                {
           	    cout<<"\nStudent  Not found !!!";
		        }
                fout.close();
                fin.close();
                remove(classfilename);
                rename("temp1.txt",classfilename);
				}
            }
            else
            {
            	cout<<"\n\n\t\t\tInvalid class entered!"<<endl;
			}
			cout<<endl<<endl<<endl;
			system("Pause");
	}   
    
};
class Teacher: virtual public Employee{
	  private:
		string Major;
		string Degree;
		int Salary;
	  	string data;
	  	string temp;
	  	int trigger;
	  	int id;
	  public:	  
	   void ViewTeacherdata()
	   {
	   	    system("cls");
	        string Tname;
			ifstream fin;
	        int k;
			trigger=0;
	            fin.open("Teacher.txt");
                cout<<"\n\n\n1.View For Whole Staff\n";
                cout<<"2.View For Only Teacher\n";
                cout<<"\n\nEnter Option  : ";
                cin>>k;
              if(k==1)
		      {
		      	system("cls");
		      	cout<<"\n\n\n\t\t\t\tAll Teachers Records !!!\n\n";
		          while(!fin.eof())
		        {
		   	      getline(fin,data);
		   	      cout<<data<<"\n";
		        }
		      }
		       else if(k==2)
		      {
		   	    cout<<"\n\nEnter Teacher name\n";
		   	    cin>>Tname;
		   	    system("cls");
		   	    getline(fin,temp);
		   	    while(!fin.eof())
		   	   {
		   	     getline(fin,data);
		   	     if(data.compare(0,Tname.length(),Tname)==0)
		   	     {
		      	    cout<<"\n\n\n\t\t\t\tRecord Found !!!\n\n\n";
		   	     	cout<<temp<<endl<<endl;
					cout<<data<<"\n";
					trigger=1;
				 }
			   }
			   if(trigger!=1)
			   {
			   	cout<<"\n\n\n\t\t\t\tRECORDS NOT FOUND !!!\n\n";
			   }
		     }
		     else
		     {
		     	cout<<"\n\n\n\t\t\tInvalid Option"<<endl;
			 }
		      fin.close();
	        system("Pause");
	   }
	   
//	    void viewTeacher(Student obj)   // Friend function
//        {	
//        	system("cls");
//	  		const char *classfilename;
//	//	    string data;
//	        fstream fin;
//	  		int cl;
//	        cout<<"\n\nEnter the class!"<<endl;
//	        cin>>cl;
//	        if(cl>0&&cl<11)
//	        {
//	        classfilename=ClassFile(cl);
//						
//	        fin.open(classfilename);
//	        system("cls");
//	        cout<<"\n\n\t\t\t\t\t Record Of Class "<<cl<<" \n\n\n\n";
//	        while(!fin.eof())
//	        {
//		      getline(fin,data);
//		      cout<<data<<endl;
//	        }
//	        fin.close();
//			}
//			else
//            {
//            	cout<<"\n\n\t\t\tInvalid class entered!"<<endl;
//			}
//			cout<<endl<<endl<<endl;
//			system("Pause");
//        	
//        	
//		}
// 
	   int Login()
		{
	      string Fusername;
          string Username;
          string password;
          int Ulength;        //user name length
          int Pcount=0,n=0,i=0,teger=0;;
          char ch;
          fstream fin;
          do
	       {
	       cout<<"\n\n\t\t\t\t\t--------------------------------";
	       cout<<"\n\n\t\t\t\t\t  The SCHOOL MANAGMENT SYSTEM";
           cout<<"\n\n\t\t\t\t\t--------------------------------";
	       cout<<"\n\n\n\t\t\t\t\t\t    LOGIN ";
           cout<<"\n\n\t\t\t\t\t\t   Username :";
           cin>>Username;
	       fin.open("password.txt");
           cout<<"\n\t\t\t\t\t\t   Password :";
                ch = _getch();
                while(ch != 13){                      //character 13 is enter
                   password.push_back(ch);
                   cout << "*";
                   ch = _getch();
                 }
	         getline(fin,Fusername);
	         if(Fusername.compare(0,Fusername.length(),Username)==0)
	         {
	            getline(fin,Fusername);
	            if(Fusername.compare(0,password.length(),password)==0)
				{
				   n=1;
				   system("cls");
				   return 1;	
				}
				else
				{
				  	cout<<"\n\n\n\n\t\t\t\t\t\t\tIncorrect password!"<<endl<<endl;
				}	  	        
	           } 
			   else
			   {
			 	cout<<"\n\n\n\n\t\t\t\t\t\t\tIncorrect Username!"<<endl<<endl;
			   }  
			   Pcount++;
			   password="\0";
			   fin.close();
			   char c;
			   getch();
			   system("cls");
           } while(n!=1 && Pcount!=3);     
			   if(n!=1)
			     return 0;
     }
	   
	 
	void ViewAttendance()
	  	{
	  		system("cls");
	  	    int cl,i,random;
			float pcount=0.0;
            char id[8];
		    cout<<"Enter the class!"<<endl;
	        cin>>cl;
	    if(cl>0&&cl<11)
	    {
            //string data;
		    ifstream Sfin;
            ofstream fout;
            const char *classfilename=ClassFile(cl);
            Sfin.open(classfilename);
            const char *Atenclassfilename=AtenClassFile(cl);
            fout.open(Atenclassfilename);
            srand(time(NULL));
            fout<<"\n\n\t\t\t\t\t\t\tATTENDANCE "<<endl<<endl<<endl;
           	    fout<<"ID NO   \t\t";
           	    for(i=1;i<31;i++)
           	    {   
				 if(i<10)
           	      fout<<i<<"  ";
           	      else
           	      fout<<i<<" ";
			    }
			     fout<<"  Percentage";
           	     fout<<"\n\n";
           	    getline(Sfin,data);
                getline(Sfin,data);
				while(!Sfin.eof())
                {
		   	    getline(Sfin,data);
           	    for(i=0;i<8;i++)
           	     {
           	  	  id[i]=data[i];
				 }
				 id[i]='\0';
           	     fout<<id;
           	     fout<<"\t\t";
           	    if(!Sfin.eof())
				{  	
				  for(i=0;i<30;i++)
           	      {  
		            random=rand()%3 +0;
                    if(random==0)
                     {
                     	fout<<"P  ";
                     	pcount++;
					 }
					 else if(random==1)
                     {
                     	fout<<"A  ";
					 }
					 else if(random==2)
                     {
                     	fout<<"L  ";
					 }
				   
			     }
				 fout<<"    "<<(pcount/20)*100<<"%";
				 pcount=0.0;
				} 
           	     fout<<endl;
		   }
           Sfin.close();
           fout.close();
		   int k;
		   string ID;
           cout<<"1.View Whole class\n";
           cout<<"2.View Indivisually\n";
           cin>>k;
           Sfin.open(Atenclassfilename);
           if(k==1)
           {
           	system("cls");
		    while(!Sfin.eof())
		    {
		   	getline(Sfin,data);
		   	cout<<data<<"\n";
		    }
		   }
		   else if(k==2)
		   {
		   	system("cls");
		   	cout<<"\n\n\nEnter Student ID\n";
		   	cin>>ID;
			cout<<data<<"\n";
		    while(!Sfin.eof())
		    {
		   	   getline(Sfin,data);
		   	   if(data.compare(0,8,ID)==0)
				  {
				  cout<<"ID NO   		1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30   Percentage\n";
				  cout<<data<<"\n";
				  }	  	
		    }		   	
		   }
		   else
		   {
		   	 cout<<"\n\n\n\t\t\tInvalid Option"<<endl;
		   }
		   Sfin.close();	
	   }
	    else
        {
            cout<<"\n\n\t\t\tInvalid class entered!"<<endl;
		}
			cout<<endl<<endl<<endl;
			system("Pause");	   
	}
      
};
class Admin: public Student,public Teacher{
	private:
		int GR_no;
		string Class;
	public:
		ifstream fin;
        void ChangePassword()
        {
        	system("cls");
            string oldpassword;
            string Username;
            string password;
    		int Ulength;//user name length
    		int Pcount=0,n=0,i=0,teger=0;;
    		char ch;
    		ifstream fin;
			ofstream fout;
           do
	       {
			fin.open("password.txt");
            cout<<"\n\n\n\t\t\t\t\tEnter Old password: ";
            
                ch = _getch();
                while(ch != 13){            //character 13 is enter
                   oldpassword.push_back(ch);
                   cout <<"*";
                   ch = _getch();
                }
			    getline(fin,Username);
	            getline(fin,password);         
				fin.close();
				if(oldpassword.compare(0,password.length(),password)==0)
				{
	            fout.open("password.txt");		   
	         	cout<<"\n\n\t\t\t\t\tEnter New Password : ";
	            cin>>password;
	            fout<<Username<<endl;
	            fout<<password;
				//system("cls");
				cout<<"\n\n\t\t\t\t\t\t\tPassword has been changed"<<endl;
				fout.close();	  	        
				n=1;	
				}
				 else
				{
				  	cout<<"\n\n\n\n\t\t\t\t\t\t\tIncorrect password!"<<endl;
			    }
			   oldpassword="\0";
			   Pcount++;
			   char c;
			   getch();
			   system("cls");
           } while(n!=1 && Pcount!=3);
	    }
    void Fee()
	{
		    system("cls");
		    int cl,i,random,trigger=0;
			int Totalfee=0,Remaining=0;
            char id[8];
		    cout<<"Enter the class!"<<endl;
	        cin>>cl;
	        
	    if(cl>0&&cl<11)
		{    
	        int Fee=Fixedfee(cl);
            string data;
		    ifstream fin;
            ofstream fout;
            const char *classfilename=ClassFile(cl);
            fin.open(classfilename);
            const char *FeeFileName=FeeFile(cl);
            fout.open(FeeFileName);
            srand(time(NULL));
           	fout<<"ID NO   \t";
           	fout<<"  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec    Total Fee    Remaining Fee\n\n";
            fout<<"\n";
            getline(fin,data);
            getline(fin,data);
        while(!fin.eof())
        {
		   	    getline(fin,data);
           	    for(i=0;i<8;i++)
           	    {
           	  	  id[i]=data[i];
				}
				 id[i]='\0';
           	     fout<<id;
           	     fout<<"   \t";
           	if(!fin.eof())
			{  	
				for(i=0;i<12;i++)
           	    { 
		            random=rand()%2 +0;
                     if(random==0)
                     {
                     	fout<<"  p  ";
                     	Totalfee+=Fee;
					 }
					 else if(random==1)
                     {
                     	fout<<"  Np ";
                     	Remaining+=Fee;
					 }
			    }
				 fout<<"    "<<Totalfee<<" Rs        "<<Remaining<<" Rs";
				 Totalfee=0;
				 Remaining=0;
			} 
           	     fout<<endl;
		}
                fin.close();
                fout.close();
		        int choose;
		        string ID,index;
                cout<<"1.Fee for Whole class\n";
                cout<<"2.Fee for Indivisual\n";
                cin>>choose;
                fin.open(FeeFileName);
        if(choose==1)
        {
		   while(!fin.eof())
		   {
		   	getline(fin,data);
		   	if(data[0]!=' ')
		   	cout<<data<<"\n";
		   }
		}
		  else if(choose==2)
		  {
		   	cout<<"Enter ID\n";
		   	cin>>ID;
		   	getline(fin,index);
		   	
		    while(!fin.eof())
		    {
		   	getline(fin,data);
		   	  if(data.compare(0,8,ID)==0)
		   	  {
		   	   cout<<index<<endl<<endl;
		   	   cout<<data<<endl<<endl;
		   	   trigger=1;
			  }
		    }
	           if(trigger!=1)
		      {
			   cout<<"\nNo found !"<<endl;
		      }
		    fin.close();
	      }
	      else
          {
            cout<<"\n\n\t\t\tInvalid option!"<<endl;
		  }
	}
	else
    {
       cout<<"\n\n\t\t\tInvalid class entered!"<<endl;
	}
		cout<<endl<<endl<<endl;
	    system("Pause");
	        
  }
	      
};


const char* AtenClassFile(int cl)
{
    const char* classfile;
	//cout<<"Enter the class!"<<endl;
	//cin>>cl;
	switch(cl)
		{
			case 1:
			    classfile="Atenclass1.txt";	
				 return classfile;
				break;
			case 2:
			    classfile="Atenclass2.txt";	
				 return classfile;
				break;
			case 3:
			    classfile="Atenclass3.txt";	
				 return classfile;
				break;
				case 4:
			    classfile="Atenclass4.txt";	
				 return classfile;
				break;
			case 5:
			    classfile="Atenclass5.txt";	
				 return classfile;
				break;
			case 6:
			    classfile="Atenclass6.txt";	
				 return classfile;
				break;
			case 7:
			    classfile="Atenclass7.txt";	
				 return classfile;
				break;
			case 8:
			    classfile="Atenclass8.txt";	
				 return classfile;
				break;
			case 9:
			    classfile="Atenclass9.txt";	
				 return classfile;
				break;
			
			case 10:
			    classfile="Atenclass10.txt";	
				 return classfile;
				break;
			default :
				cout<<"\nInvalid Option";
				break;
		}
}
const char * ClassFile(int cl)
{
    const char* classfile;
	
	switch(cl)
		{
			case 1:
			    classfile="class1.txt";	
				 return classfile;
				break;
			case 2:
			    classfile="class2.txt";	
				 return classfile;
				break;
			case 3:
			    classfile="class3.txt";	
				 return classfile;
				break;
				case 4:
			    classfile="class4.txt";	
				 return classfile;
				break;
			case 5:
			    classfile="class5.txt";	
				 return classfile;
				break;
			case 6:
			    classfile="class6.txt";	
				 return classfile;
				break;
			case 7:
			    classfile="class7.txt";	
				 return classfile;
				break;
			case 8:
			    classfile="class8.txt";	
				 return classfile;
				break;
			case 9:
			    classfile="class9.txt";	
				 return classfile;
				break;
			
			case 10:
			    classfile="class10.txt";	
				 return classfile;
				break;
			default :
				cout<<"\nInvalid Option";
				break;
		}
}

   const char* FeeFile(int cl)
{
    const char* classfile;
	switch(cl)
		{
			case 1:
			    classfile="Feeclass1.txt";	
				 return classfile;
				break;
			case 2:
			    classfile="Feeclass2.txt";	
				 return classfile;
				break;
			case 3:
			    classfile="Feeclass3.txt";	
				 return classfile;
				break;
				case 4:
			    classfile="Feeclass4.txt";	
				 return classfile;
				break;
			case 5:
			    classfile="Feeclass5.txt";	
				 return classfile;
				break;
			case 6:
			    classfile="Feeclass6.txt";	
				 return classfile;
				break;
			case 7:
			    classfile="Feeclass7.txt";	
				 return classfile;
				break;
			case 8:
			    classfile="Feeclass8.txt";	
				 return classfile;
				break;
			case 9:
			    classfile="Feeclass9.txt";	
				 return classfile;
				break;
			
			case 10:
			    classfile="Feeclass10.txt";	
				 return classfile;
				break;
			default :
				cout<<"\nInvalid Option";
				break;
		}
}

int Fixedfee(int cl)
{
	switch(cl)
		{
			case 1:	
				 return 1000;
				break;
			case 2:	
				 return 1200;
				break;
			case 3:	
				 return 1400;
				break;
			case 4:
				 return 1600;
				break;
			case 5:	
				 return 1800;
				break;
			case 6:	
				 return 2000;
				break;
			case 7:	
				 return 2200;
				break;
			case 8:	
				 return 2400;
				break;
			case 9:	
				 return 2600;
				break;
			
			case 10:	
				 return 2800;
				break;
			default :
				cout<<"\nInvalid Option";
				break;
		}
}



int main()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLoading ";
	 for(int i=1; i<=30; i++)
      {
        Sleep(400);
        cout<<".";
      }
    cout<<endl<<endl<<endl<<endl<<endl;
	//system("Pause");
	system("cls");
	int flage;
	Admin  admin;
	flage =admin.Login();
	int option;
	if(flage==1)
	{
	do
    {
	  cout<<"\n\n\t\t\t\t--------------------------------------";
	  cout<<"\n\n\t\t\t\t  WELLCOME TO SCHOOL MANAGMENT SYSTEM";
      cout<<"\n\n\t\t\t\t--------------------------------------";
      cout<<"\n\n\n\t\t\t\t\t  1.View Student ";
      cout<<"\n\t\t\t\t\t  2.Search Student ";
      cout<<"\n\t\t\t\t\t  3.Add Student ";
      cout<<"\n\t\t\t\t\t  4.Remove Student ";
      cout<<"\n\t\t\t\t\t  5.View Teacher ";
      cout<<"\n\t\t\t\t\t  6.View Attendance ";
      cout<<"\n\t\t\t\t\t  7.Change password ";
      cout<<"\n\t\t\t\t\t  8.View Fee ";
      cout<<"\n\t\t\t\t\t  9.Exit ";
      cout<<"\n\nEnter Option : ";
      fflush(stdin);
      cin>>option;
      fflush(stdin);
      option=(int)option;
       switch(option)
       {
            case 1:
			    admin.ViewStudentdata();	
				break;
			case 2:
			    admin.SearchStudent();
				break;
			case 3:
				admin.AddStudent();
				break;
			case 4:
				admin.RemoveStudent();
				break;
			case 5:
				admin.ViewTeacherdata();
				break;
			case 6:
				admin.ViewAttendance();
				break;
			case 7:
				admin.ChangePassword();
				break;
			case 8:
				admin.Fee();
				break;
			case 9:
				break;
			default :
				cout<<"\nInvalid Option !"<<endl<<endl<<endl;
				system("Pause");
				break;
		}
			
      system("cls");
    } while(option!=9);
      system("color 1c");
      cout<<"\n\n\n\n\t\t\t\t\t\tTHANK YOU FOR VISIT!!! \n";
      cout<<"\n\t\t\t\t\t      SYSTEM BROUGHT TO YOU BY !!!";
      cout<<"\n\t\t\t\t\t---------------------------------------";
      cout<<"\n\t\t\t\t\t-\t"<<"MUHAMMAD IMRAN     K16-4050   -";
      cout<<"\n\t\t\t\t\t-\t"<<"DANIYAL RAZA       K16-3952   -";
      cout<<"\n\t\t\t\t\t-\t"<<"WASEEM HASSAN      K16-3773   -";
	  cout<<"\n\t\t\t\t\t---------------------------------------"; 
	   cout<<endl<<endl<<endl;
	   cout<<"\n\n\n\t\t\t\t\t\t\t Exiting\n\n";
        for(int i=1; i<=80; i++)
        {
         Sleep(50);
         cout<<"*";
        }
    }
    else
    {
    	cout<<"\n\n\n\n\n\n\t\t\t\t\tONLY ADMIN CAN ACCSISS !!!"<<endl;
	}
    
	    //system("Pause");
    return 0; 	
}

