# include <iostream>
# include <stdlib.h>
using namespace std;
# include "declaration.cpp"
# include "length.cpp"
# include "display_ll.cpp"
# include "append_ll.cpp"
# include "insert_at_start.cpp"
# include "insert_at_position.cpp"
# include "delete_at_end.cpp"
# include "delete_at_start.cpp"
# include "delete_at_position.cpp"
# include "reverse.cpp"
int main(void){
	int opt;
	do{
		cout<<"\n\nMenu : ";
		cout<<"\n1. Display Linked List";
		cout<<"\n2. Append Node";
		cout<<"\n3. Insert at Start";
		cout<<"\n4. Insert at Position";
		cout<<"\n5. Delete at End";
		cout<<"\n6. Delete at Start";
		cout<<"\n7. Delete at Position";
		cout<<"\n8. Reverse";
		cout<<"\n\nEnter your choice : ";
		cin>>opt;
		switch(opt)
			{
				case 1 :
					{
						display_ll();
						break;
					}
				case 2 :
					{
						append_ll();
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
						break;
					}
				case 6 :
					{
						delete_at_start();
						break;
					}
				case 7 :
					{
						delete_at_position();
						break;
					}
				case 8 :
					{
						start=reverse();
						break;
					}
			}
	}while(opt!=0);
}
