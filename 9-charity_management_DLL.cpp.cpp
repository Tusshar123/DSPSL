#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Roll {
public:
	int roll;
	string classs;
	string name;
	int attended=0;
    float opinion=0;

	void accept(int x) {
		cout<<"Student no. "<<x<<endl;
		cout<<"Enter the Roll No.: ";
		cin>>roll;
		cout<<"Enter the Class:";
		cin>>classs;


		cout<<"Enter the Name:";
		cin.ignore();
		getline(cin, name);
	}

	void display() {
		cout << setw(15) << left << classs
		     << setw(15) << left << roll
		     << setw(15) << left << name << endl;
	}

    void display2()
    {
        	cout << setw(15) << left << classs
		     << setw(15) << left << roll
		     << setw(15) << left << name 
             << setw(15) << left << opinion <<endl;
    }

    




};

int main()
{	Roll a[20];
	int i,ch,N=0,temproll,flag,A=0,count=0,tempattended,check=0;
    int  q1,q2,q3,q4,q5;
    float total=0;
    float opi=0;
	string tempclasss;

	do
	{
		cout<<"\nMenu\n1.Accept\n2.Display\n3.Feed\n4.Display Feed\n5.Search(Using Linear Search)\n6.Search(Using Binary Search)\n7.FeedBack\n8.Display Opinion\n9.Exit\n";
		cin>>ch;

		switch (ch)
		{
		case 1:
			cout<<"Enter the Total No. of Students you are going to Enter: ";   //I made changes and removed the extra object 'b'...
			cin>>N;
			for ( i = 0; i < N; i++)
			{
				a[i].accept(i+1);
			}

			break;

		case 2:
			cout << setw(15) << left << "Class"                            //It will display 'a', as we are going to perform operation on 'a' only...
			     << setw(15) << left << "Roll no"
			     << setw(10) << right << "Name" << endl;

			cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

			for ( i = 0; i < N; i++)
			{
				a[i].display();
			}

			break;

		case 3:



			cout<<"Enter the Total No. of Students who Attended:";
			cin>>A;

			for ( i = 0; i < A; i++)
			{
				flag=1;

				cout<<"Student no. "<<i+1<<endl;

				cout<<"Enter the Roll No.: ";
				cin>>temproll;
				cout<<"Enter the Class:";
				cin.ignore();
				getline(cin, tempclasss);
				cout<<endl;

				for ( int j = 0; j < N; j++)
				{
					if (a[j].roll==temproll && (a[j].classs==tempclasss))    //it will check if student is in data base or not...
					{
						a[j].attended=1;                                    //if yes then it will change the attended variable...
						flag=0;
						break;
					}

				}
				if (flag==1)
				{   i--;
					cout<<" Student Not in Database\n";
				}


			}



			break;

		case 4:


			cout<<"\nYour Feed is:\n";

			cout << setw(15) << left << "Class"
			     << setw(15) << left << "Roll no"<< endl;

			cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

			for ( i = 0; i < N; i++)
			{
				if (a[i].attended==1)
				{
					a[i].display();
				}

			}



			break;

		case 5:

			cout<<"Enter the Roll no. of student You want to Search:";
			cin>>temproll;
			cout<<"Enter the Class of Student:";
			cin.ignore();
			cin>>tempclasss;
			flag=1;
			check=0;                     //it will check if the student we are searching is in our 'a' or not...
			for ( i = 0; i < N; i++)

			{	if(temproll==a[i].roll && (a[i].classs==tempclasss))

				{	if (a[i].attended==1)
					{	check=1;
						cout<<"Student Has Attended the Program\n";
						flag=0;
						break;
					}

				}

			}
			if (flag==1)
			{
				cout<<"Nope student Didnt Attend\n";
			}
			else if(check==0)
			{
				cout<<"\nStudent Didn't found in database\n";
			}



			break;


		case 6:
			int low,mid,high;

			for ( i = 0; i < N; i++)                //sorting the Array of Objects
			{
				for (int j = 0; j < N-1; j++)
				{
					if (a[j].roll>a[j+1].roll)
					{
						temproll=a[j].roll;
						a[j].roll=a[j+1].roll;
						a[j+1].roll=temproll;


						tempclasss=a[j].classs;
						a[j].classs=a[j+1].classs;
						a[j+1].classs=tempclasss;

						tempattended=a[j].attended;                //swapping the attended var. as well...
						a[j].attended=a[j+1].attended;
						a[j+1].attended=tempattended;

					}

				}

			}


			cout<<"\nYour Sorted Feed is:\n";
			for ( i = 0; i < A; i++)
			{
				cout << setw(15) << left << "Class"
				     << setw(15) << left << "Roll no"<< endl;

				cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

				for ( i = 0; i < N; i++)
				{
					if (a[i].attended==1) {

						a[i].display();
					}

				}
			}



			high=N-1;
			low=0;
			mid=(low+high)/2;

			flag=0;

			cout<<"Enter the Roll no. of student You want to Search:";
			cin>>temproll;
			cout<<"Enter the Class of Student:";
			cin>>tempclasss;

			check=0;

			while (low<=high)
			{
				if(temproll==a[mid].roll && (a[mid].classs==tempclasss))
				{	if (a[mid].attended==1)
					{
						cout<<"Student Has Attended the Program\n";
						flag=1;
						check=1;                                       //same use, i commented out in case 5 earlier...
						break;
					}


				}
				else if(temproll>a[mid].roll)
				{
					low=mid+1;
				}
				else
				{
					high=mid-1;
				}
				mid=(low+high)/2;
			}
			if(flag==0)
			{
				cout<<"\nStudent Didn't Attend the Program\n";
			}
			else if(check==0)
			{
				cout<<"\nStudent Didn't found in database\n";
			}



			break;

        case 7:
		       int studentno=0;
               for ( i = 0; i < A; i++)
               {for (  i = 0; i < N; i++)
				{   
					if (a[i].attended==1) {
						
                        q1=q2=q3=q4=q5=0;
                        opi=0;
                        float average=0;
                        cout<<"Student "<<studentno+1<<endl;
                         cout<<"1.Do you uhink Traing Program was worth it?\n";
                         cout<<"(1)Yes\n(0)No\n";
                         cin>>q1;
                         cout<<"2.Do you think college made proper use of your precious time by inviting the respective Guest?";
                          cout<<"\n(1)Yes\n(0)No\n";
                         cin>>q2;
                         cout<<"DO you think we were Doing time pass, By calling you at Holiday???";
                         cout<<"\n(0)Yes\n(1)No\n";
                         cin>>q3;
                         cout<<"Did you get Gyst of Trainer's Lecture Or you were sleeping??\n";
                         cout<<"(1)Yes\n(0)No\n";
                         cin>>q4;
                         cout<<"Shall we force you Again for Such type of programs in future again?\nNOTE:not like your choice matters";
                         cout<<"\n(1)Yes\n(0)No\n";
                         cin>>q5;
                         
                        
                        opi=q1+q2+q3+q4+q5;
                        average=(opi/5)*100;
                        cout<<average;
                        a[i].opinion=average;
						total+=opi;
                        studentno++;

					}
                    
				}
               }
             
        break;

        case 8:

        cout<<"\nAttended Students Opinion is:\n";		
             cout << setw(15) << left << "Class"
		     << setw(15) << left << "Roll"
		     << setw(15) << left << "Name" 
             << setw(15) << left << "Opinion(out of 100)" <<endl;

            for ( i = 0; i < A; i++)
			{
		
				cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

				for ( i = 0; i < N; i++)
				{
					if (a[i].attended==1) {

						a[i].display2();
					}

				}
			}
          
          if(((total/(A*5))*100) >= 70)
          {
            cout<<"Students Are Interested in such Future Programs...\n";
            cout<<((total/(A*5))*100)<<"was the Percentile";
          }
          else{
            cout<<"Students Not Interested...\n";
            cout<<((total/(A*5))*100)<<"was the Percentile";
          }
        

        break;


		case 9:
			break;



		default:
			cout<<"Wrong Choice...\n";
			break;
		}


	} while (ch!=9);



	return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string bookTitle;
    string author;
    string isbnNo;
    Node* next;
};

class list {
public:
    Node* head = NULL;

    void insertAtFirst() {
        Node* newNode = new Node;

        cout << "Enter Book Title (use underscores for spaces): ";
        cin >> newNode->bookTitle;
        cout << "Enter Author Name (use underscores for spaces): ";
        cin >> newNode->author;
        cout << "Enter ISBN No: ";
        cin >> newNode->isbnNo;

        newNode->next = head;
        head = newNode;
    }

    void insertAtLast() {
        Node* newNode = new Node;

        cout << "Enter Book Title (use underscores for spaces): ";
        cin >> newNode->bookTitle;
        cout << "Enter Author Name (use underscores for spaces): ";
        cin >> newNode->author;
        cout << "Enter ISBN No: ";
        cin >> newNode->isbnNo;

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAfterPosition() {
        Node* newNode = new Node;
        Node* temp = head;
        int pos, i = 1;

        cout << "Enter the position after which you want to insert the new book: ";
        cin >> pos;

        while (i < pos && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        cout << "Enter Book Title (use underscores for spaces): ";
        cin >> newNode->bookTitle;
        cout << "Enter Author Name (use underscores for spaces): ";
        cin >> newNode->author;
        cout << "Enter ISBN No: ";
        cin >> newNode->isbnNo;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (head == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        Node* temp = head;
        Node* prevNode = NULL;

        while (temp->next != NULL) {
            prevNode = temp;
            temp = temp->next;
        }

        if (prevNode != NULL) {
            prevNode->next = NULL;
        } else {
            head = NULL;
        }

        delete temp;
    }

    void deleteAtPosition() {
        if (head == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        Node* temp = head;
        Node* prevNode = NULL;
        int pos, i = 1;

        cout << "Enter the position from which you want to delete the book: ";
        cin >> pos;

        if (pos == 1) {
            head = temp->next;
            delete temp;
            return;
        }

        while (i < pos && temp != NULL) {
            prevNode = temp;
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        prevNode->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "Library list is empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << "Book Title: " << temp->bookTitle 
                 << ", Author: " << temp->author 
                 << ", ISBN No: " << temp->isbnNo << endl;
            temp = temp->next;
        }
    }
} l;

int main() {
    int choice, ch;

    do {
        cout << "\n1. INSERT AT START\n2. INSERT AT LAST\n3. INSERT AFTER POSITION\n4. DELETE FIRST\n5. DELETE LAST\n6. DELETE AT POSITION\n7. DISPLAY\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.insertAtFirst();
                break;
            case 2:
                l.insertAtLast();
                break;
            case 3:
                l.insertAfterPosition();
                break;
            case 4:
                l.deleteFirst();
                break;
            case 5:
                l.deleteLast();
                break;
            case 6:
                l.deleteAtPosition();
                break;
            case 7:
                l.display();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }

        cout << "Do you want to continue? (1 for yes): ";
        cin >> ch;
    } while (ch == 1);

    return 0;
}
*/
