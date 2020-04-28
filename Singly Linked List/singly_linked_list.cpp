# include <iostream>
# include <stdlib.h>
using namespace std;
# include "declaration.cpp"
# include "display_ll.cpp"
# include "append_ll.cpp"
# include "insert_at_start.cpp"
# include "insert_at_position.cpp"

int main(void){
	int opt;
	do{
		cout<<"\nEnter your choice : ";
		cin>>opt;
		switch(opt)
			{
				case 1 :
					{
						append_ll();
						break;
					}
				case 2 :
					{
						display_ll();
						break;
					}
				case 3 :
					{
						insert_at_start();
						break;
					}
			}
	}while(opt!=0);
}
