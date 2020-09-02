#include<iostream>

using namespace std;

class Node
{
	public:
		int key;
		Node* next;
		
		Node(int key)
		{
			this->key = key;
			this->next = NULL;
		}
			
};

class HashMap
{
	public:
		
		Node **arr;
		int size;
		
		HashMap(int size)
		{
			this->size = size;
			arr = new Node*[size];
			for(int i=0;i<size;i++)
			{
				arr[i] = NULL;
			}
		}
		
		int hash(int n)
		{
			return n%size;
		}
		
		int insert(int n)
		{
			int key = n;
			int index = hash(key);
			
			Node* blk = new Node(n);
			
			if(arr[index] == NULL)
			{
				arr[index] = blk;
				return 1;
			}
			else
			{
				Node *ptr;
				ptr = arr[index];
				while(ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = blk;
				return 1;
			}
		}
		
		int search(int n)
		{
			int index = hash(n);
			
			Node *ptr;
			ptr = arr[index];
			int count = 0;
			while(ptr != NULL && count <= size)
			{
				if(ptr->key == n)
				{
					return 1;
				}
				ptr = ptr->next;
				count++;
			}
			return 0;
		}
		
		int del(int n)
		{
			int index = hash(n);
			
			Node *ptr;
			Node *preptr;
			preptr = arr[index];
			ptr = preptr;
			int count = 0;
			while(ptr != NULL && count <= size)
			{
				if(ptr->key == n)
				{
					preptr->next = ptr->next;
					//free ptr
					return 1;
				}
				count ++;
				preptr = ptr;
				ptr = ptr->next;
			}
			return 0;
		}
		
		void display()
		{
			for(int i=0;i<size;i++)
			{
				printf("Index %d : ",i);
				
				Node *ptr;
				ptr = arr[i];
				
				while(ptr != NULL)
				{
					cout << ptr->key << " ";
					ptr = ptr->next;
				}
				
				cout << endl;
				
			}
		}
};

int main()
{
	HashMap H(5);
	H.insert(3);
	H.insert(8);
	H.insert(13);
	H.display();
	
	cout << endl;
	H.del(8);
	H.display();
}
