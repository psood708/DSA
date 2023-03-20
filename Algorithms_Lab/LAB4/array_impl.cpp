#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string name[10];
int x[10], y[10], num = 0;

// made the customized node that will be
class Node
{
public:
    string name;
    int xcord;
    int ycord;
    Node *next;
};

class LinkedList
{
private:
    Node *Head;

public:
    LinkedList() { Head = NULL; }
    LinkedList(string nm[], int xco[], int yco[], int n);
    void Display();
    void Insert(int num);
    void Delete();
    void Search();
    int numCities();
    void nearBy();
};
void LinkedList::nearBy(){
    Node *p=Head;
    cout<<"\n<<<<<<-Nearby Cities->>>>>>>\n";
    int m, n;
    cout << "Enter the coordinates of the point you want to start: ";
    cin >> m >> n;
    int distance;
    cout << "\n Here is the list for the nearby cities within (50kms) radius" << endl;
    do{
        p=p->next;
        distance = 0;
        distance = sqrt(pow((p->xcord- m), 2) + pow((p->ycord - n), 2));
        if(distance<50 && p->name!=""){
            cout<<p->name<<" is "<<distance<<" kms away from your given Location"<<endl;

        }
    }while(p->next!=NULL);
}
void LinkedList::Search()
{
    int choice;
    cout<<"/n<<<<<-Search Bar->>>>>\n";
    Node *p = Head;
    cout << "(1) to search by name (2) to search by coordinates";
    cin>>choice;
    if(choice==1){
        string sri;
        cout<<"Enter the name of the city: ";
        cin>>sri;
        do{
            p=p->next;
        }while(p->name!=sri);
        cout<<p->name<<" exists at coordinates "<<p->xcord<<" : "<<p->ycord<<endl;
    }
    else if(choice==0){
        int m,n;
        cout<<"Enter the coordinates: ";
        cin>>m>>n;
        do{
            p=p->next;
        }while(p->xcord!=m && p->ycord!=n);
        cout<<p->xcord<<":"<<p->ycord<<" pins to location of "<<p->name;
    }
    else{
        cout<<" You had a BAD INPUT!!";
    }
}
void LinkedList::Delete()
{
    Node *p, *q = NULL;
    string s1;
    int x, m, n;
    cout << " Enter (1) to delete by Name and (2) to delete by Coordinates: ";
    cin >> x;
    if (x == 1)
    {
        cout << "Enter the Name of the country to delete: ";
        cin >> s1;
        p = Head;
        do
        {
            q = p;
            p = p->next;
        } while (p->name != s1);
        q->next = p->next;
        cout << "\n<<<<<-Deleted->>>>>\n";
        cout << "City: " << p->name << " Coordinates: " << p->xcord << ":" << p->ycord;
        delete p;
    }
    else
    {
        cout << "Enter the Coordinates of the Location: ";
        cin >> m >> n;
        p = Head;
        do
        {
            q = p;
            p = p->next;
        } while (p->xcord != m && p->ycord != n);
        q->next = p->next;
        cout << "\n<<<<<-Deleted->>>>>\n";
        cout << "Coordinates: " << p->xcord << ":" << p->ycord << " City: " << p->name;
        delete p;
    }
}
void LinkedList::Insert(int num)
{
    string sm1;
    int b, c;
    if (num <= 9)
    {
        cout << "Enter the name of the city : ";
        cin >> sm1;
        cout << "Enter the coordinates of the city: ";
        cin >> b >> c;
    }
    Node *p = Head;
    Node *t;
    for (int i = 0; i < num; i++)
    {
        p = p->next;
    }
    t->name = sm1;
    t->xcord = b;
    t->ycord = c;
    p->next = t;
    t->next = NULL;
}

LinkedList::LinkedList(string nm[], int xco[], int yco[], int n)
{
    Node *last, *t;
    Head = new Node;
    Head->name = nm[0];
    Head->xcord = xco[0];
    Head->ycord = yco[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->name = nm[i];
        t->xcord = xco[i];
        t->ycord = yco[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void LinkedList::Display()
{
    Node *p = Head;
    cout << "\n<<<<<<<-Cities->>>>>>>" << endl;
    do
    {
        cout << "City: " << p->name << " Coordinates: " << p->xcord << " - " << p->ycord << endl;
        p = p->next;
    } while (p != NULL);
}
int LinkedList::numCities()
{
    Node *p = Head;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void insertCity(int num)
{
    if (num <= 9)
    {
        string sm1;
        int b, c;
        cout << "Enter the name of the city : ";
        cin >> sm1;
        cout << "Enter the coordinates of the city: ";
        cin >> b >> c;
        name[num] = sm1;
        x[num] = b;
        y[num] = c;
        num += 1;
    }
}
// here we will be asking for the coordinates of that specific point for this we have kept a situation of <50kms
void nearByCities()
{
    int m, n;
    cout << "Enter the coordinates of the city you want to start: ";
    cin >> m >> n;
    int distance;
    cout << "\n Here is the list for the nearby cities within (50kms) radius" << endl;
    for (int i = 0; i < 10; i++)
    {
        distance = 0;
        distance = sqrt(pow((x[i] - m), 2) + pow((y[i] - n), 2));
        if (distance < 50 && name[i] != "")
        {
            cout << name[i] << " is " << distance << " kms away from your location" << endl;
        }
    }
}
void searchCity()
{
    int choice, p, q;
    string s1;
    cout << "Enter choice (1) for Coordinates and (2) for Name";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter the coordinates: ";
        cin >> p >> q;
        for (int i = 0; i < 10; i++)
        {
            if (p == x[i] && q == y[i])
            {
                cout << "City found for the given coordinates: " << p << " : " << q << ":-" << name[i] << endl;
            }
        }
    }
    else
    {
        cout << "Enter the name of the city: ";
        cin >> s1;
        for (int i = 0; i < 10; i++)
        {
            if (s1 == name[i])
            {
                cout << "Coordinates found for the give city " << name[i] << ":- " << x[i] << ":" << y[i] << endl;
            }
        }
    }
}
void delByName()
{
    string st;
    cout << "Enter the name of the city to delete: ";
    cin >> st;
    for (int i = 0; i < 10; i++)
    {
        if (name[i] == st)
        {
            name[i] = "";
            x[i] = 0;
            y[i] = 0;
            cout << "City Deleted Successfully!!" << endl;
        }
    }
}
void delByCoordinate()
{
    int X, Y;
    cout << "Enter the Coordinates: ";
    cin >> X >> Y;
    for (int i = 0; i < 10; i++)
    {
        if ((X == x[i]) && (Y == y[i]))
        {
            x[i] = 0;
            y[i] = 0;
            name[i] = "";
        }
    }
}
void showALL()
{
    for (int i = 0; i < 10; i++)
    {
        if (name[i] != "" && x[i] != 0 && y[i] != 0)
        {
            cout << "City: " << name[i] << endl;
            cout << "Coordinates: " << x[i] << " " << y[i] << endl;
        }
    }
}
void enterDetails(int curr)
{
    string str1;
    int X, Y;
    cout << "Enter the name of the city: ";
    cin >> str1;
    cout << "Enter the X coordinate: ";
    cin >> X;
    cout << "Enter the Y coordinate: ";
    cin >> Y;
    name[curr] = str1;
    x[curr] = X;
    y[curr] = Y;
}
int main()
{
    int curr = 0;
    cout << "How many cities do you want to enter (max 10): ";
    cin >> num;
    for (curr; curr < num; curr++)
    {
        enterDetails(curr);
    }
    LinkedList ctyDB(name, x, y, num + 1);
    ctyDB.Insert(num);
    ctyDB.Display();
    ctyDB.Delete();
    ctyDB.Search();
    ctyDB.Display();
}