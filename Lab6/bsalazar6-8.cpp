/*
Brandon Salazar
Professor Santosh
CSE 100 Summer 2020
July 22nd 
Lab VI Hash Table with Chaining
*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <list>

using namespace std;

void Srch(int key, int s, vector<list<int>> &v){
	int x = 0;
	for(list<int>::iterator i = v[key%s].begin(); i != v[key%s].end(); i++){
		if(*i == key){
			cout<<key<<":FOUND_AT"<<key%s<<","<<x<<";"<<endl;
			return;
		}//end if statement
		x++;
	}//end i loop
	cout<<key<<":NOT_FOUND;"<< endl;
}//end search function

void Del(int key, int s, vector<list<int>> &v){
	for(list<int>::iterator i = v[key%s].begin(); i != v[key%s].end(); i++){
		if(*i == key){
			v[key%s].erase(i);
			cout<<key<<":DELETED;"<<endl;
			return;
		}//end if statment
	}//end i loop
	cout<<key<<":DELETE_FAILED;"<<endl;
}//end delete function

void Out(vector<list<int>> &v){
	for(int i = 0; i < v.size(); i++){
		cout<<i<<":";
		for(list<int>::iterator j = v[i].begin(); j != v[i].end(); j++){
			cout<<*j<< "->";
		}//end j-loop
		cout<<";"<<endl;
	}//end i loop
}//end output function

void Insrt(int key, int s, vector<list<int> > &v){
	v[key % s].push_front(key);
}//end insertion function

int main(int argc,char **argv){
	
    int s;
	cin >> s;

	vector<list<int>> v(s, list<int>());
    
    bool terminate = true;
	string input;
    while(terminate){
		cin >> input ;
		
        int key = atoi(input.substr(1, input.size()).c_str());
		
        if(input[0] == 's')
			Srch(key, s, v);
		else if(input[0] == 'i')
			Insrt(key, s, v);
		else if(input[0] == 'd')
			Del(key, s, v);
        else if(input[0] == 'o')
			Out(v); 
        else if(input[0] == 'e')
			terminate = false;       
	}//end while loop
}//end main function
       

/*
Hash Table with Chaining

Description In this assignment you are requested to implement a hash table that handles
collisions by chaining. You have to use linked lists, either from the Standard Template Library
(STL) (recommended) or by implementing your own. For usage of STL, refer for instance to
http://www.cppreference.com/wiki.

You need to implement the insert, search and delete operations. The keys are integers (C++
int type) and you can assume that all keys are non-negative. The first number in the input will
be the size m of the chained hash table. You will use the simple hash function h(k) = k mod m.
Then lines will follow starting with ‘i’, ‘s’, ‘d’,‘o’, or ‘e’. The details are as follows:

• Use the hash function h(k) = k mod m.

• i(key): Insert (key) into the table. For example, “i2” implies “Insert key 2 into the table.”
For collisions, insert the colliding key at the beginning of the linked list. You just need to
insert the key and don’t have to output anything in this case.

• d(key): delete (key) from the table. For example, d2 implies “Delete key 2 from the table.”
If there are multiple elements of the same key value, delete the element of the key value
that appears the earliest in the list. If the delete was successful, you have to output

(key):DELETED;

If not (since there was no element with the key value), output

(key):DELETE_FAILED;

• s(key): search (key) in the table. If there is an element with the key value, then you have
to output

(key):FOUND_ATi,j;

where i is the hash table index and j is the linked list index. If there are multiple elements
with the same key value, choose the first one appearing in the linked list. If you couldn’t
find the key, then output
(key):NOT_FOUND;

• o: output the table. Output the entire hash table. Each line should begin with the
slot/hash table index followed by key values in the linked list. For example, if m = 3 and
we inserted 3, 6, and 1 into an empty table in this order, then you should output

0:6->3->;
1:1->;
2:;

• e: finish your program.

Example of input and output

The following example shows an execution of the program in interactive mode. See the input
files and output files under the testfiles folder for examples where input and output are separated.

2
i4
i2
i6
i3
o
0:6->2->4->;
1:3->;
s2
2:FOUND_AT0,1;
s4
4:FOUND_AT0,2;
d5
5:DELETE_FAILED;
d2
2:DELETED;
o
0:6->4->;
1:3->;
e
*/