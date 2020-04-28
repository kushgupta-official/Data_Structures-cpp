# include <iostream>
# include <stdlib.h>
using namespace std;
# include "declaration.cpp"
# include "display_ll.cpp"
# include "append_ll.cpp"
# include "insert_at_start.cpp"
# include "insert_at_position.cpp"
# include "delete_at_end.cpp"


int main(void){
	int opt;
	do{
		cout<<"\n\nEnter your choice : ";
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
				case 4 :
					{
						insert_at_position();
						break;
					}
				case 5 :
					{
						delete_at_end();
					}
			}
	}while(opt!=0);
}
