int length(){
	node *temp;
	temp=start;
	int len=0;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	return len;	
}

