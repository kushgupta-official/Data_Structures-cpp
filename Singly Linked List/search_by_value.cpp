void search_by_value(){
	node *temp;
	int x;
	cout<<"Enter Value you want to search for : ";
	cin>>x;
	temp=start;
	int flag=0,pos=1;
	while(temp!=NULL){
		if (x==temp->data){
			flag=1;
			cout<<x<<" founded at position "<<pos<<endl;
		}
		temp=temp->next;
		pos++;
	}
	if (flag==0){
		cout<<"This Value does not exists in Linked List";
	}
}
