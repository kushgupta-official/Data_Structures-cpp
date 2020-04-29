node *reverse(){
	node *p,*q,*r;
	p=NULL;
	q=start;
	r=start->next;
	while(q!=NULL){
		q->next=p;
		p=q;
		q=r;
		if(r!=NULL){
			r=r->next;
		}
	}
	cout<<"Linked List Reversed!";
	return p;
}
