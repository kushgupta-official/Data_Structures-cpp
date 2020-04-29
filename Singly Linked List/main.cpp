# include <iostream>
# include <stdlib.h>
# include <process.h>
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
# include "remove_duplicate.cpp"
# include "search_by_value.cpp"
# include "search_by_position.cpp"

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
		cout<<"\n9. Remove all Duplicate Elements";
		cout<<"\n10. Search by Value";
		cout<<"\n11. Search by Position";
		cout<<"\n0. Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>opt;
		switch(opt)
			{
				case 0 :
					{
						exit(0);
					}
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
				case 9 :
					{
						remove_duplicate();
						break;
					}
				case 10 :
					{
						search_by_value();
						break;
					}
				case 11 :
					{
						search_by_position();
						break;
					}
				default : 
					{
						cout<<"Wrong Choice Entered";
					}
			}
	}while(1);
}
