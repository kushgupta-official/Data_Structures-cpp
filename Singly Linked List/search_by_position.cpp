void search_by_position(){
	node *temp;
	int pos;
	cout<<"Enter position : ";
	cin>>pos;
	int len=length();
	if (pos>len){
		cout<<"Wrong Position Entered, Position cannot exceed the size of Linked List\n Size of your Linked List = "<<len;
		return;
	}
	else if(pos<1){
		cout<<"Position Cannot be less than 1";
		return;
	}
	else{
		int i=1;
		temp=start;
		while(temp!=NULL){
			if (i==pos){
				cout<<"Value at Position "<<pos<<" is = "<<temp->data;
				return;
			}
			
			temp=temp->next;
			i++;
		}
	}
}
