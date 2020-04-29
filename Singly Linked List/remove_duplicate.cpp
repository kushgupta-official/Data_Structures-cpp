void remove_duplicate(){
	node *ptr,*temp1,*temp2;
	temp1=start;
	int x;
	while(temp1!=NULL){
		x=temp1->data;
		temp2=temp1;
		while(temp2->next!=NULL){
			ptr=temp2;
			temp2=temp2->next;
			if(temp2->data==x){
				ptr->next=temp2->next;
				temp2->next=NULL;
				free(temp2);
				temp2=ptr;
			}
		}
		temp1=temp1->next;
	}
	cout<<"Duplicate Elements Deleted from Linked List";
}
