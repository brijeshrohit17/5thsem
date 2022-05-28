#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    //data members
    int blockid;
    vector<int> process;
    int startad;
    int endad;
    int pointad;
    node *next;
    //member functions
    void addprocess(int x)
    {
        this->process.push_back(x);
    }
    void setid(int id)
    {
        this->blockid = id;
    }
    void showdetails()
    {
        cout << this->blockid << "\t";
        int sum = 0;
        for (auto i : this->process)
        {
            cout << i << ",";
        }
        cout << "\t";
        cout << this->startad << "\t\t";
        cout << this->endad << "\t";
        cout << this->pointad << "\t\t";
        cout << this->endad - this->startad + 1 << "\t";
        cout << this->endad - this->pointad + 1;
    }
};
//function to display the frames
void showblock(node *n)
{
    cout << "BlockID\tProcess\tStart Ad\tEnd Ad\tPoint Ad\tMemoryI\tMemoryLeft";
    while (n != NULL)
    {
        cout << "\n";
        n->showdetails();
        n = n->next;
    }
}
void clear(node *n)
{
    while (n != NULL)
    {
        node *temp = n;
        n = n->next;
        free(temp);
    }
}
int main()
{
    node *head = NULL;
    int n;
    cout << "Enter number of blocks/ partitions : ";
    cin >> n;
    cout << "Enter starting and ending address of block 1 : ";
    head = new node();
    int temp1, temp2;
    cin >> temp1 >> temp2;
    head->setid(1);
    head->startad = temp1;
    head->pointad = temp1;
    head->endad = temp2;
    node *tnode = NULL;
    tnode = head;
    for (int i = 2; i <= n; i++)
    {
        node *t = new node();
        cout << "Enter starting and ending address of block " << i << " : ";
        cin >> temp1 >> temp2;
        t->setid(i);
        t->startad = temp1;
        t->pointad = temp1;
        t->endad = temp2;

        tnode->next = t;
        tnode = tnode->next;
    }
    cout << "\n\n----------------------------------Initially----------------------------------\n ";
        showblock(head);
    int m;
    cout << "\n\n\nEnter Number of process : ";
    cin >> m;
    cout << "Enter Size of each process : ";
    vector<int> list;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        list.push_back(x);
    }

    //First Fit
    cout << "\n\n----------------------------------First Fit----------------------------------\n ";
        vector<int>
            unallocatedprocess;
    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        tnode = head;
        //looking for 1st block having enough memory.
        int mem = tnode->endad - tnode->pointad + 1;
        while ((list[i] > mem))
        {
            //if no block exists then adding the process to
            //unallocated process
            if (tnode->next == NULL)
            {
                unallocatedprocess.push_back(i + 1);
                flag = 1;
                break;
            }
            tnode = tnode->next;
            mem = tnode->endad - tnode->pointad + 1;
        }
        //flag=0 indicates block has been found
        //and thus we would allocated the process.
        if (flag == 0)
        {
            tnode->pointad += list[i];
            tnode->addprocess(i + 1);
        }
    }
    showblock(head);
    cout << "\nUnallocated processes: ";
    for (auto i : unallocatedprocess)
    {
        cout << i << ",";
    }

    //reseting
    tnode = head;
    while (tnode != NULL)
    {
        tnode->process.clear();
        tnode->pointad = tnode->startad;
        tnode = tnode->next;
    }
    unallocatedprocess.clear();
    //Best Fit
    cout << "\n\n----------------------------------Best Fit----------------------------------\n ";
        node *tnode1 = NULL;
    for (int i = 0; i < m; i++)
    {
        tnode = head;
        tnode1 = head;
        int x = 1000000;
        //loop to find smmalest block with enough memory.
        while (tnode != NULL)
        {
            int y;
            y = (tnode->endad - tnode->pointad + 1);
            //finding minimum.
            if ((x >= y) && (y >= list[i]))
            {
                tnode1 = tnode;
                x = tnode1->endad - tnode1->pointad + 1;
            }
            tnode = tnode->next;
        }
        tnode = NULL;
        //checking if memory of tnode1 is actually
        //enough or not.
        if ((tnode1->endad - tnode1->pointad + 1) >= list[i])
        {
            tnode1->addprocess(i + 1);
            tnode1->pointad += list[i];
        }
        else
        {
            //not found then not alloacate.
            unallocatedprocess.push_back(i + 1);
        }
    }
    showblock(head);
    cout << "\nUnallocated processes: ";
    for (auto i : unallocatedprocess)
    {
        cout << i << ",";
    }
    //reseting
    tnode = head;
    while (tnode != NULL)
    {
        tnode->process.clear();
        tnode->pointad = tnode->startad;
        tnode = tnode->next;
    }
    unallocatedprocess.clear();
    //Worst Fit
    cout << "\n\n----------------------------------Worst Fit----------------------------------\n ";

        for (int i = 0; i < m; i++)
    {
        tnode = head;
        tnode1 = head;
        int x = -1;
        //loop to found biggest block
        while (tnode != NULL)
        {
            int y;
            y = (tnode->endad - tnode->pointad + 1);
            if ((x <= y) && (y >= list[i]))
            {
                tnode1 = tnode;
                x = tnode1->endad - tnode1->pointad + 1;
            }
            tnode = tnode->next;
        }
        tnode = NULL;
        //checking if we have enough memory or not
        if ((tnode1->endad - tnode1->pointad + 1) >= list[i])
        {
            tnode1->addprocess(i + 1);
            tnode1->pointad += list[i];
        }
        else
        {
            unallocatedprocess.push_back(i + 1);
        }
    }
    showblock(head);
    cout << "\nUnallocated processes: ";
    for (auto i : unallocatedprocess)
    {
        cout << i << ",";
    }

    clear(head);
}