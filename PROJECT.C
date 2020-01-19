#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
void lens();
void color();
void colorless();
void sol();
void review_cart();
struct node
{
	char *item;
	int q;
	int price;
	struct node *link;
};
struct node *first = NULL;
void main()
{
	int ch, cont,len;
	char name[100], ph_num[11], area[100], rp[10], lp[10];
	float bc;
	clrscr();
	printf("Welcome to IBall for your Eyeballs\n");
	printf("\n");
	printf("Enter your Name : ");
	gets(name);
	printf("Enter your Phone Number : ");
	gets(ph_num);
	len=strlen(ph_num);
	while(len!=10)
	{
		printf("Invalid phone number\n");
		printf("Enter the correct phone number\n");
		gets(ph_num);
		len=strlen(ph_num);
	}
	printf("\n");
	do
	{
		printf("What would you like to buy today? \n");
		printf("1. Contact Lenses\n");
		printf("2. Lens solution\n");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:lens();
			break;
			case 2: sol();
			break;
			default : printf("Invalid choice\n");
		}
		printf("Do you want to continue shopping\n");
		printf("Press 1. Yes	2. No\n");
		scanf("%d",&cont);
	}
	while(cont==1);
	review_cart();
	printf("\nCHECKOUT SCREEN\n\n");
	printf("Thank you %s for shopping with us (IBall for your Eyeballs!!)\n",name);
	printf("\nYour final shoping list is:\n");
	if(first==NULL)
		printf("Shopping cart is empty\n");
	else
	{
		struct node *tmp=first;
		int i=0,cost=0;
		printf("Sl.no. Item		 Quantity	Cost\n");
		while(tmp!=NULL)
		{

			i++;
			printf("%d.     %s\t   %d\t\t%d\n",i,tmp->item,tmp->q,tmp->price);
			cost=cost+tmp->data;
			tmp=tmp->link;
		}
		printf("\nThe amount to be paid is: Rs%d\n",cost);
		printf("Enter your right eye power: ");
		//gets(rp);
		scanf("%s",rp);
		printf("Enter your left eye power: ");
		//gets(lp);
		scanf("%s",lp);
		printf("Enter your base curve: ");
		scanf("%f",&bc);
		printf("\nEnter area of delivery: ");
		scanf("%s",&area);
		printf("\nYour order will be delivered to you within 3 working days.\n");
		printf("Our delivery partner will contact you on %s for delivery instructions.\n",ph_num);
		printf("\nPRECAUTIONS\n\nThe lenses purchased are monthly disposable and the lens solution should be used within 3 months from the date opening.\n");
		printf("Please do not use products after they expire or if their seal is broken\n");
		printf("For further information send your queries to Email - arohi0812@gmail.com\n");
	}
	getch();
}
void lens()
{
	int c;
	printf("Choose a option \n");
	printf("1. Coloured lens\n");
	printf("2. Colourless lenses\n");
	fflush(stdin);
	scanf("%d",&c);
	switch(c)
	{
		case 1: color();
		break;
		case 2: colorless();
		break;
		default: printf("Invalid choice\n");
		getch();
	}
	clrscr();
}
void color()
{
	int a,quantity,i;
	struct node *p;
	char l_color[10][100]={"Icy Blue   ","Amazing olive","Misty White","Sparkling Green","Dusty Brown"};
	printf("Which colour would you like to buy\n");
	for(i=0;i<5;i++)
		printf("%d. %s\n",i+1,l_color[i]);
	fflush(stdin);
	scanf("%d",&a);
	p=(struct node *)malloc(sizeof(struct node));
	if(a>0&&a<6)
	{
		p->item=l_color[a-1];
		printf("Cost of each box is Rs. 250/-\n");
		printf("Enter the number of boxes required ");
		fflush(stdin);
		scanf("%d",&p->q);
		p->price=(p->q)*250;
		p->link=first;
		first=p;
	}
	else
	{
		printf("Invalid choice\n");

		getch();
	}

}
void colorless()
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	printf("Price of each box is Rs. 200\n");
	printf("Enter the number of boxes required: ");
	scanf("%d",&p->q);
	p->price=200*(p->q);
	p->item="Colorless lens";
	p->link=first;
	first=p;
}
void sol()
{
	struct node *p;
	int a,i;
	p=(struct node *)malloc(sizeof(struct node));
	printf("Choose a item\n");
	printf("1. 60 ml Rs. 70\n");
	printf("2. 120ml Rs. 130\n");
	printf("3. 180ml Rs. 190\n");
	printf("4. 360ml Rs. 350\n");
	printf("5. 500ml Rs. 470\n");
	scanf("%d",&a);
	printf("Enter the number of boxes required: ");
	scanf("%d",&p->q);
	switch(a)
	{
		case 1: p->item="Solution 60ml";
			p->price=70*(p->q);
			break;
		case 2: p->item="Solution 120ml";
			p->price=130*(p->q);
			break;
		case 3: p->item="Solution 180ml";
			p->price=190*(p->q);
			break;
		case 4: p->item="Solution 360ml";
			p->price=350*(p->q);
			break;
		case 5: p->item="Solution 500ml";
			p->price=470*(p->q);
			break;
		default: printf("Invalid choice\n");
	}
	p->link=first;
	first=p;
	clrscr();
}
void review_cart()
{
	int cont,ch;
	clrscr();
	do
	{
		int i=0;
		struct node *tmp=first;
		printf("\nSHOPPING CART\n\n");
		if(first==NULL)
		{
			printf("Cart is empty\n");
			getch();
			break;
		}
		printf("The contents of cart are \n");
		printf("Sl.no. Item		 Quantity	Cost\n");
		while(tmp!=NULL)
		{

			i++;
			printf("%d.     %s\t   %d\t\t%d\n",i,tmp->item,tmp->q,tmp->price);
			tmp=tmp->link;
		}
		printf("Do you wish to delete any item from cart\n");
		printf("1.YES 2.NO\n");
		fflush(stdin);
		scanf("%d",&ch);
		if(ch==2)
			break;
		else if(ch==1)
		{
			struct node *prev=tmp;
			int flag =0,ele,d=0;
			tmp=first;
			printf("Enter the number you want to delete ");
			fflush(stdin);
			scanf("%d",&ele);
			if((first->link==NULL)&&(ele==1))
			{
				d=1;
				printf("%d number item is deleted\n\n",ele);
				free(tmp);
				first=NULL;
			}
			else if(ele==1&&first->link!=NULL)
			{
				d=1;
				printf("%d number item is deleted\n",ele);
				first=tmp->link;
				free(tmp);
			}
			else
			{
				tmp=first;
				while(tmp!=NULL)
				{
					flag++;
					if(ele==flag)
					{
						d=1;
						printf("%d number item is deleted\n\n",ele);
						prev->link=tmp->link;
						free(tmp);
						break;
					}
					else
					{
						prev=tmp;
						tmp=tmp->link;
					}
				}
			}
			if(d==0)
				printf("Data not found\n");
			printf("Do you wish to delete more items\n");
			printf("1.Yes	2.No\n");
			scanf("%d",&cont);
		}
	clrscr();
	}
	while(cont==1);
	clrscr();
}
