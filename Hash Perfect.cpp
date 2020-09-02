#include<iostream>

using namespace std;

class Sec
{
	public:
		int *T2;
		int m;
		int a;
		int b;
		
		Sec(int m = 5, int a = 3, int b = 7)
		{
			T2 = new int[m];
			this->a = a;
			this->b = b;
			this->m = m;	
			
			for(int i=0;i<m;i++)
			{
				T2[i] = 0;
			}
		}
};

class HashMap
{
	public:
		
		Sec **T1;
		int size;
		
		HashMap(int size)
		{
			this->size = size;
			T1 = new Sec*[size];	
			
			for(int i=0;i<size;i++)
			{
				Sec* l;
				l = new Sec;
				T1[i] = l;
			}
		}
		
		int hash1(int k)
		{
			return ((5*k+11)%7)%size;
		}
		
		int hash2(int k,int m = 5, int a = 3, int b = 7)
		{
			return ((a*k+b)%7)%m;
		}
		
		int insert(int key)
		{
			int k = key;
			int index_1 = hash1(k);
			int index_2 = hash2(k);
			
			T1[index_1]->T2[index_2]= key; 
		}
		
		void display()
		{
			for(int i=0;i<size;i++)
			{
				cout << i << " : ";
				for(int j=0;j<T1[i]->m;j++)
				{
					cout << T1[i]->T2[j] << " ";
				}
				cout << endl;
			}
		}
		
		
		
};

int main()
{
	HashMap H(5);
	H.insert(13);
	H.insert(8);
	H.insert(54);
	H.insert(32);
	H.display();
}
