void display_ll(){
	node *temp=start;
	cout<<"START -> ";
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL";
}
