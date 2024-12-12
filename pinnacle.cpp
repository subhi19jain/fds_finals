#include<iostream>
#include<map>
using namespace std;

class Node{
    string name;
    int PRN;
    Node* next;

    public:
      Node(string name,int prn){
        this->name=name;
        this->PRN=prn;
        this->next=NULL;
      }

      int getPRN()
      {
        return PRN;
      }

      void setPRN(int prn){
        PRN=prn;
      }

      string getName(){
        return name;
      }

      void setName(string name){
        this->name=name;
      }

      Node* getNext(){
        return next;
      }

      void setnext(Node* nextNode)
      {
        next=nextNode;
      }
};

class Club{
    private:
      Node*head;
      Node*tail;
      int count;

    public:
     Club(){
        head=NULL;
        tail=NULL;
        count=0;
        }

        void addMember(string name, int prn)
        {
            Node* newNode = new Node(name,prn);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->setnext(newNode);
                tail= newNode;
            }
            count++;
        }

        void addPresident(string name, int prn)
        {
            Node* newNode = new Node(name,prn);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                newNode->setnext(head);
                head= newNode;
            }
            count++;
        }

        void addSecretary(string name, int prn)
        {
            Node* newNode = new Node(name,prn);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->setnext(newNode);
                tail= newNode;
            }
            count++;
        }
        void displayMembers(){
            Node*current= head;
            if(current==NULL){
                cout<<"no members!!";
                return;}
            while (current){
                cout<<"Name: "<<current->getName()<<" , PRN: "<<current->getPRN()<<"\n";
                current = current->getNext();
                }

            }  

        int getTotalmember(){
                return count;
            } 
        
            
             

        void deleteMember(int prn) {
        if (head == NULL) {
            cout << "The club has no members to delete.\n";
            return;
        }

        // Deleting the president (head)
        if (head->getPRN() == prn) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
            count--;
            cout << "President deleted successfully.\n";
            if (head == NULL) { // If the list is now empty
                tail = NULL;
            }
            return;
        }

        // Deleting any other member (or secretary)
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->getPRN() != prn) {
            prev = current;
            current = current->getNext();
        }

        if (current == NULL) {
            cout << "Member with PRN " << prn << " not found.\n";
            return;
        }

        // If deleting the secretary (tail)
        if (current == tail) {
            tail = prev;
        }

        prev->setnext(current->getNext()) ;
        delete current;
        count--;
        cout << "Member with PRN " << prn << " deleted successfully.\n";
    }
};

int main() {
    Club Pinnacle;
    int choice, prn;
    string name;

    do {
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Delete Member\n";
        cout << "5. Display Members\n";
        cout << "6. Total Members\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter President's Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter President's PRN: ";
                cin >> prn;
                Pinnacle.addPresident(name, prn);
                cout << "President added successfully!\n";
                break;

            case 2:
                cout << "Enter Secretary's Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Secretary's PRN: ";
                cin >> prn;
                Pinnacle.addSecretary(name, prn);
                cout << "Secretary added successfully!\n";
                break;

            case 3:
                cout << "Enter Member's Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Member's PRN: ";
                cin >> prn;
                Pinnacle.addMember(name, prn);
                cout << "Member added successfully!\n";
                break;

            case 4:
            cout << "Enter PRN of the member to delete: ";
            cin >> prn;
            Pinnacle.deleteMember(prn); // Call deleteMember with only the PRN
            break;

            case 5:
                Pinnacle.displayMembers();
                break;

            case 6:
                cout << "Total Members: " << Pinnacle.getTotalmember() << "\n";
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}


