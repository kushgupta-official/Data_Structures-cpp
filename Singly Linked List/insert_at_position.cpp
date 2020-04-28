//have to repaired for position number 1 and more than the length of linked list

void insert_at_position(){
	node *temp,*ptr,*qtr;
	qtr=(node*)malloc(sizeof(node));
	cout<<"Enter data : ";
	cin>>qtr->data;
	int pos;
	cout<<"Enter position you want to insert data at : ";
	cin>>pos;
	temp=start;
	int i=1;
	while (temp->next!=NULL){
		if (i==pos-1){
			break;
		}
		i++;
		temp=temp->next;
	}
	ptr=temp->next;
	temp->next=qtr;
	qtr->next=ptr;
	cout<<"\nNode Inserted\n";
}
