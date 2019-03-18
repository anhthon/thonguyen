#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;
using namespace std;

typedef struct tagNode {	
    int   	Info;  	// Luu thông tin b?n thân
    string SDT;
    string ND;
    int Gio;
    int Phut;
    struct  tagNode  *pNext; //tr? d?n Node d?ng sau
}Node;

typedef struct  tagList {	
    Node  *pHead;//Luu d?a ch? Node d?u tiên trong List
    Node  *pTail; //Luu d?a ch? c?a Node cu?i cùng trong List
}List;
void CreateList(List &l);
void AddHead(List &l, Node* p);
Node* CreateNode(int Gio, int Phut, string sdt, string nd);
void AddTail(List &l, Node *p);
void InsertAfterQ(List &l, Node *p, Node *q);
int RemoveHead(List &l, int &x);
int RemoveAfterQ(List &l,Node *q, int &x);
int RemoveX(List &l, int x);
void PrintList(List &l);
Node *Search(List l, int  gio, int phut, string sdt);

int main(int argc, char *argv[])
{    
    Node *p;
    List l;
    CreateList(l);
    int gio=0, phut;
    string sdt, nd;
    char c;
    do
    {
        cout<<"Cac chuc nang:\n";
        cout<<"1. Nhan tin\n";
        cout<<"2. Tim tin nhan\n";
        cout<<"0. Tat chuong trinh\n";
        cin>>c;
        switch(c)
        {
            case '1':
                 cout<<"SDT can gui: ";
                 cin>>sdt;
                 cin.ignore();
                 cout<<"Tin nhan: ";
                 getline(cin,nd);
                 gio=25;
                 while(gio<0||gio>23)
                 {
                     cout<<"Gio: ";
                     cin>>gio;
                     if(gio<0||gio>23)
                         cout<<"Gio khong hop le\n";
                 }
                 cout<<"Phut: ";
                 cin>>phut;                 
                 p=CreateNode(gio, phut, sdt, nd);
                 AddHead(l, p);
                 cout<<"TN vua gui: ";
                 cout<<"SDT: "<<p->SDT<<endl;
                 cout<<"ND: "<<p->ND<<endl;
                 cout<<"Gio gui: "<<p->Gio<<endl;
                 cout<<"Phut gui: "<<p->Phut<<endl;
                 
                 break;
            case '2':
                 Node *t;
                 cout<<"SDT: ";
                 cin>>sdt;
                 cout<<"Gio: ";
                 cin>>gio;
                 cout<<"Phut: ";
                 cin>>phut;
                 t=Search(l, gio, phut, sdt);
                 cout<<"SDT: "<<t->SDT<<endl;
                 cout<<"ND: "<<t->ND<<endl;
                 cout<<"Gio gui: "<<t->Gio<<endl;
                 cout<<"Phut gui: "<<t->Phut<<endl;
                 break;                 
        }
    }while(c!='0');
    getch();
    return EXIT_SUCCESS;
}
Node *Search(List l, int  gio, int phut, string sdt) 
{	
	Node *p;
	p = l.pHead;
	while((p!= NULL)&&(p->Gio!=gio || p->Phut!=phut || p->SDT!=sdt)) 
		p = p->pNext;
	return p;
}

void PrintList(List &l)
{
    Node *p;
    p=l.pHead;
    while(p!=NULL)
    { 
        cout<<"Node: "<<p->Info<<endl;
        p=p->pNext;
    }
}

int RemoveX(List &l, int x) 
{	
    Node *p,*q = NULL; p=l.pHead;
    while((p!=NULL)&&(p->Info!=x)) 
    { //tìm
        q=p;
        p=p->pNext;
    }
    if(p==NULL) //không tìm th?y ph?n t? có khoá b?ng x
        return 0;
    if(q!=NULL) //tìm th?y ph?n t? có khoá b?ng x	
        RemoveAfterQ(l,q,x);
    else //ph?n t? c?n xoá n?m d?u List 
    	RemoveHead(l,x);
    return 1;
}

int RemoveAfterQ(List &l,Node *q, int &x) 
{	
    Node *p;
    if(q!=NULL)
    {	
        p=q->pNext; //p là nút c?n xoá
        if(p!=NULL) 
        { // q không phài là nút cu?i
            if(p==l.pTail) //nút c?n xoá là nút cu?i cùng 
				l.pTail=q; //c?p nh?t l? pTail
			q->pNext=p->pNext; x=p->Info;
			delete p;
        }
			return 1;
    }
    else 
        return 0;	
}

int RemoveHead(List &l, int &x)
{	
    Node *p;
    if(l.pHead!=NULL)
    {	
        p=l.pHead; 
        x=p->Info; //luu Data c?a nút c?n h?y 
        l.pHead=l.pHead->pNext;
        delete p;
        if(l.pHead==NULL)
        l.pTail=NULL;
        return 1;
   	}
    return 0;
}

void InsertAfterQ(List &l, Node *p, Node *q)
{
    if(q!=NULL)
    {
    	p->pNext = q->pNext;
    	q->pNext = p;
    	if(l.pTail == q) 
    		l.pTail = p;
    }
 else
	AddHead(l,q);// thêm q vào d?u list
}

void CreateList(List &l) 
{ 	
	l.pHead=NULL;
	l.pTail=NULL;
}

Node* CreateNode(int gio, int phut, string sdt, string nd) 
{	
    Node *p;
    p = new Node; //C?p phát vùng nh? cho ph?n t?
    if ( p==NULL)  
        exit(1); 
    p ->Gio = gio; 	//gán d?a li?u cho node
    p ->Phut = phut;
    p ->SDT = sdt;
    p ->ND = nd;
    p->pNext = NULL;
    return p; 
}

void AddHead(List &l, Node* p)
{
	if (l.pHead==NULL) 
    { 
		l.pHead = p; 
		l.pTail = l.pHead; 
	}
	else 
    { 
		p->pNext = l.pHead;
		l.pHead = p; 	
	}
}

void AddTail(List &l, Node *p)
{
	if (l.pHead==NULL)  
	{	
		l.pHead = p; 
		l.pTail = l.pHead; 
	}
	else
	{ 
		l.pTail->pNext = p;	
		l.pTail = p; 
	}
}
