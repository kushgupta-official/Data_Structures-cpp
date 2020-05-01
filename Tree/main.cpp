//strictly binary and full nodes not working
# include <iostream>
# include <stdlib.h>
# include <process.h>
using namespace std;
# include "declaration.cpp"
# include "create_btree.cpp"
# include "traversals.cpp"
# include "max_depth.cpp"
# include "number_leaf_nodes.cpp"
# include "number_internal_nodes.cpp"
# include "number_all_nodes.cpp"
# include "number_full_nodes.cpp"
# include "check_strictly_binary.cpp"

int menu(){
	int choice;
	cout<<"\n\nMenu : ";
	cout<<"\n1. Create a Binary Tree";
	cout<<"\n2. Show Preorder";
	cout<<"\n3. Show Inorder";
	cout<<"\n4. Show Postorder";
	cout<<"\n5. Calculate Maximum Height/Depth of the Tree";
	cout<<"\n6. Display Number of Leaf nodes";
	cout<<"\n7. Display Number of Internal nodes";
	cout<<"\n8. Display Number of all nodes";
	cout<<"\n9. Display Number of full nodes";
	cout<<"\n10. Check Strictly Binary";
	cout<<"\n0. Exit";
	cout<<"\n\nEnter your Choice : ";
	cin>>choice;
	return choice;
}

int main(void){
	int choice;
	do{
		choice=menu();
		switch(choice){
			case 0:
				{
					exit(0);
				}
			case 1:
				{
					root=create_btree();
					break;
				}
			case 2:
				{
					preorder(root);
					break;
				}
			case 3:
				{
					inorder(root);
					break;
				}
			case 4:
				{
					postorder(root);
					break;
				}
			case 5:
				{
					int depth=max_depth(root);
					cout<<depth;
					break;	
				}
			case 6:
				{
					int leaf_nodes=number_leaf_nodes(root);
					cout<<"Leaf Node = "<<leaf_nodes;
					break;
				}
			case 7:
				{
					int internal_nodes=number_internal_nodes(root);
					cout<<"Internal Nodes or Non Leaf Nodes = "<<internal_nodes;
					break;
				}
			case 8:
				{
					int all_nodes=number_all_nodes(root);
					cout<<"Number of all Nodes = "<<all_nodes;
					break;
				}
			case 9:
				{
					cout<<"Number of full Nodes = "<<number_full_nodes(root);
					break;
				}
			case 10:
				{
					if (!check_strictly_binary){
						cout<<"This Tree is not a strictly Binary Tree";
					}
					else{
						cout<<"This Tree is a Strictly Binary Tree";
					}
				}
			default:
				{
					cout<<"Please Enter the Correct Choice";
				}
		}
	}while(1);
}
