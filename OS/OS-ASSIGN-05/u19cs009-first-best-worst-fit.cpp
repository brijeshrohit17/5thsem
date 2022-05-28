#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int block_id;
    int start_add;
    int end_add;
    int pointer_add;
    vector<int> processes;
    node* next;

    void print_detail()
    {
        cout << this->block_id << "\t";
        for(auto &x : processes)
            cout << x << ",";
        cout << "\t" << this->start_add << "\t\t";
        cout << this->end_add << "\t";
        cout << this->pointer_add << "\t\t";
        cout << this->end_add - this->pointer_add + 1;
    }
};

void print_list(node* head)
{
    cout << "Block\tProcess\tStartAdd\tEndAdd\tPointAdd\ttMemLeft";
    while(head != NULL)
    {
        cout << endl;
        head->print_detail();
        head = head->next;
    }
}

void del_list(node* head)
{
    while(head != NULL)
    {
        node* temp = head;
        head = head->next;
        free(temp);
    }
}

void first_fit(node* head, vector<int> &process, int size)
{
    vector<int> unallocProcess;
    node* temp = head;
    
    //traversing for each individual process in free list
    for(int i = 0 ; i < size ; i++)
    {
        bool flag = false;
        head = temp;

        //Memory having size >= current process requirement
        int memSize = head->end_add - head->pointer_add + 1;

        //checking if size fits or not
        while(process[i] > memSize)
        {
            //end of list and search completed but hole not found
            if(head->next == NULL)
            {
                unallocProcess.push_back(i+1);
                flag = true;
                break;
            }
            //traversing to next node if as size of block is smaller
            head = head->next;
            //new size of new node/block
            memSize = head->end_add - head->pointer_add + 1;
        }
        //when search is complete for current processs and found fit
        //add it to processes completed for fit
        if(flag)
        {
            head->pointer_add = head->pointer_add + process[i];
            head->processes.push_back(i+1);
        }
    }

    head = temp;
    print_list(head);
    
    //printing unallocated process
    cout << endl << "Un-allocated Pocesses are : ";
    for(int x : unallocProcess)
        cout << x << ", ";
    cout << endl;

    //resetting values to original
    head = temp;
    while(head != NULL)
    {
        head->processes.clear();
        head->pointer_add = head->start_add;
        head = head->next;
    }
    vector<int>().swap(unallocProcess);
    return;
}

void best_fit(node* head, vector<int> &process, int size)
{
    node* temp = head;
    node* temp1 = head;
    node* temp2 = head;
    vector<int> unallocProcess;

    //traversing for each process
    for(int i = 0 ; i < size ; i++)
    {
        int x = 10000000;

        temp1 = head;
        temp2 = head;
        
        //pointing node with minimum value that fits current process
        while(temp1 != NULL)
        {
            int memSize = temp1->end_add - temp1->pointer_add + 1;
            
            if((x >= memSize) && (memSize >= process[i]));
            {
                temp2 = temp1;
                x = temp2->end_add - temp2->pointer_add + 1;
            }
            temp1 = temp1->next;
        }
        temp1 = NULL;
        //adding process only if last modified temp2 node is sufficient
        //else if not fount going to next process after adding
        //current process to unallocated
        if((temp1->end_add - temp1->pointer_add + 1) >= process[i])
        {
            temp1->processes.push_back(i+1);
            temp1->pointer_add = temp1->pointer_add + process[i];
        }
        else
        {
            unallocProcess.push_back(i+1);
        }
    }

    head = temp;
    print_list(head);

    //printing unallocated process
    cout << endl << "Un-allocated Pocesses are : ";
    for(int x : unallocProcess)
        cout << x << ", ";
    cout << endl;

    //resetting values to original
    head = temp;
    while(head != NULL)
    {
        head->processes.clear();
        head->pointer_add = head->start_add;
        head = head->next;
    }
    vector<int>().swap(unallocProcess);
    return;
}

void worst_fit(node* head, vector<int> &process, int size)
{
    node* temp  = NULL;
    node* temp1  = NULL;
    node* temp2  = NULL;
    temp = head;
    vector<int> unallocProcess;

    //traversing for each process
    for(int i = 0 ; i < size ; i++)
    {
        int x = -1;

        temp1 = head;
        temp2 = head;
        
        //pointing node with maximum value that fits current process
        while(temp1 != NULL)
        {
            int memSize = temp1->end_add - temp1->pointer_add + 1;
            
            if((x <= memSize) && (memSize >= process[i]));
            {
                temp2 = temp1;
                x = temp2->end_add - temp2->pointer_add + 1;
            }
            temp1 = temp1->next;
        }
        temp1 = NULL;
        //adding process only if last modified temp2 node is sufficient
        //else if not fount going to next process after adding
        //current process to unallocated
        if((temp1->end_add - temp1->pointer_add + 1) >= process[i])
        {
            temp1->processes.push_back(i+1);
            temp1->pointer_add = temp1->pointer_add + process[i];
        }
        else
        {
            unallocProcess.push_back(i+1);
        }
    }  
    //printing unallocated process
    head = temp;
    print_list(head);
    
    cout << endl << "Un-allocated Pocesses are : ";
    for(int x : unallocProcess)
        cout << x << ", ";

    //resetting values to original
    head = temp;
    while(head != NULL)
    {
        head->processes.clear();
        head->pointer_add = head->start_add;
        head = head->next;
    }
    vector<int>().swap(unallocProcess);
    return; 
}

int main()
{
    int numFreeBlocks, numMemRequests, i, startAdd, endAdd;
    
    //number of free memory blocks / holes
    cout << "Please enter number of FREE BLOCKS/HOLES : ";
    cin >> numFreeBlocks;
    
    //head of linked list of Free Blocks
    node* headFree = new node();
    cout << "Enter Start Address and End Address of Block 1 : ";
    cin >> startAdd >> endAdd;
    headFree->block_id = 1;
    headFree->start_add = startAdd;
    headFree->end_add = endAdd;
    headFree->pointer_add = startAdd;

    //forming list ahead
    node* temp = new node();
    temp = headFree;
    node* temp1 = new node();
    temp1 = headFree;

    for(int i = 2 ; i <= numFreeBlocks ; i++)
    {
        node* freeblock = new node();
        cout << "Enter Start Address and End Address of Block " << i << " : ";
        cin >> startAdd >> endAdd;
        freeblock->block_id = i;
        freeblock->start_add = startAdd;
        freeblock->end_add = endAdd;
        freeblock->pointer_add = startAdd;

        //joining node;
        temp->next = freeblock;
        temp = temp->next;
    }

    headFree = temp1;

    //number of processes
    cout << "Please enter number of PROCESSES : ";
    cin >> numMemRequests;

    vector<int> requestSize(numMemRequests);
    for (i = 0 ; i < numMemRequests ; i++)
    {
        int temp;
        cout << "Please eneter size of process " << i+1 << " : ";
        cin >> temp;
        requestSize.push_back(temp);
    }
    

    //FIRST FIT
    cout << endl << "FIRST FIT" << endl;
    for(int i = 0 ; i < 6 ; i++)
        cout << "----------------";
    cout << endl;
    first_fit(headFree, requestSize, numMemRequests);
    headFree = temp1;

    //BEST FIT
    cout << endl << "BEST FIT" << endl;
    for(int i = 0 ; i < 6 ; i++)
        cout << "----------------";
    cout << endl;
    best_fit(headFree, requestSize, numMemRequests);
    headFree = temp1;

    //WORST FIT
    cout << endl << "WORST FIT" << endl;
    for(int i = 0 ; i < 6 ; i++)
        cout << "----------------";
    cout << endl;
    worst_fit(headFree, requestSize, numMemRequests);

    headFree = temp1;

    del_list(headFree);

    return 0;
}