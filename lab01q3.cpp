#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct node
{
  int data;
  node* next; 
}*head;

void initialize(int x)
{
  head = new node;
  head->data = x;
  head->next = NULL;
}

void insert(int x,int n)
{
  node *temp, *p;
  p = new node;
  temp = head;
  for(int i = 1;i<n-1;i++)
  {
    temp = temp->next;
    if(temp->next == NULL)
    {
      cout<<"n too high";
      break;
    }
  }
  p->data = x;
  p->next = temp->next;
  temp->next = p;

}

void del(int n)
{
  node *temp, *p;
  temp = head;
  for(int i = 1;i<n-1;i++)
  {
    temp = temp->next;
  }
  p = temp->next;
  temp->next = p->next;
  delete p;

  
}

void display()
{
  ofstream myfile2;
  myfile2.open("output.txt",ios::app);
  node *temp;
  temp = head;
  while(temp != NULL)
  {
    myfile2<<temp->data<<endl;
    temp = temp->next;
  }
  myfile2<<endl;
}



int main()
{
  char str[20];
  int a,b;
  ifstream myfile;
  myfile.open("input.txt");
  initialize(10);
  while(myfile>>str)
  {
    if(strcmp(str,"insert") == 0)
    {
      myfile>>a>>b;
      insert(a,b);
    }
    if(strcmp(str,"delete") == 0)
    {
      myfile>>a;
      del(a);
    }
    if(strcmp(str,"display") == 0)
    {
      display();
    }
  }
  return 0;
}
