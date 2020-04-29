void delete_at_position(){
	node *temp,*ptr;
	int pos;
	cout<<"Enter position of node you want to delete : ";
	cin>>pos;
	int len=length();
	if (pos>len){
		cout<<"Wrong Position Entered, Position cannot exceed the size of Linked List\n Size of Linked List = "<<len;
		return;
	}
	else if(pos<1){
		cout<<"Position cannot be less than 1";
		return;
	}
	else if (pos==1){
		temp=start;
		start=start->next;
		temp->next=NULL;
		free(temp);
	}
	else{
		int i=1;
		temp=start;
		while(i<=len){
			ptr=temp;
			temp=temp->next;
			i++;
			if(i==pos){
				break;
			}
		}
		ptr->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
	
}
