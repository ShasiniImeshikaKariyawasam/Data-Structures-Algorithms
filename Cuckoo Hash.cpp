#include<iostream>
using namespace std;

class HashTable
{
	public:
		int *arr;
		int size;
		
		HashTable(int size)
		{
			this->size = size;
			arr = new int[size];
			
			for(int i=0;i<size;i++)
			{
				arr[i] = 0;
			}
		}
};

class HashMap
{
	public:
		
		HashTable *T1;
		HashTable *T2;
		int size;
		
		HashMap(int size)
		{
			T1 = new HashTable(size);
			T2 = new HashTable(size);
			this->size = size;
		}
		
		int hash1(int key)
		{
			return (3*key+5)%size;
		}
		
		int hash2(int key)
		{
			return (5*key+7)%size;
		}
		
		int hash3(int key)
		{
			return (7*key+11)%size;
		}
		
		int insert(int key)
		{
			int index1 = hash1(key);
			int index2 = hash2(key);
			int index3 = hash3(key);
			
			if(T1->arr[index1] == 0)
			{
				T1->arr[index1] = key;
			}
			else
			{
				int temp = T1->arr[index1];
				T1->arr[index1] = key;
				
				if(T2->arr[index2] == 0)
				{
					T2->arr[index2] = temp;
				}
				else
				{
					int etemp = T2->arr[index2];
					T2->arr[index2] = temp;
					
					T1->arr[index3] = etemp;
				}

			}
			
		}
		
		void display()
		{
			for(int i=0;i<size;i++)
			{
				cout << T1->arr[i] << " ";
			}
			cout << endl;
			for(int i=0;i<size;i++)
			{
				cout << T2->arr[i] << " ";
			}
			cout << endl;
			cout << endl;
			
		}
};

int main()
{
	HashMap H(11);
	H.insert(13);
	H.display();
	H.insert(3);
	H.display();
	H.insert(6);
	H.display();
	H.insert(2);
	H.display();
	H.insert(8);
	H.display();
	H.insert(14);
	H.display();
	H.insert(18);
	H.display();
	H.insert(22);
	H.display();
	H.insert(15);
	H.display();
	H.insert(16);
	H.display();
	H.insert(17);
	H.display();
	H.insert(20);
	H.display();
	H.insert(25);
	H.display();
	H.insert(28);
	H.display();
	H.insert(1);
	H.display();
}
