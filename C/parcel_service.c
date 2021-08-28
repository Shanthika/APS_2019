
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_transaction();
void business();
struct adress
{
	char home_name[20];
	int home_no;
	char street[20];
	int pincode;
};
struct web
{
	char mail_id[20];
};
struct voice_mail
{
	int code;
	int part1;
	int part2;
};
struct delivery_mode
{
	struct adress a;
	struct web w;
	struct voice_mail vm;
};
struct parcel
{
	char name[20];
	struct delivery_mode dm;
	int delivery_type;
	char month[10];
	int year;
	float charges;
}p[5];

int main()
{
	printf("Enter the input\n");
	get_transaction();
	business();
	return 0;
}

void get_transaction()
{
	for(int i=0;i<5;i++)
	{

		printf("Enter user name,month,year\n");
		scanf("%s%s%d",p[0].name,p[i].month,&p[i].year);
		printf("Enter mode of delivery\n");
		printf("1-HOME DELIVERY,2-WEB,3-VOICE MAIL\n");
		scanf("%d",&p[i].delivery_type);
	
		if(p[i].delivery_type==1)
		{
			printf("Enter house adress,no,street and pin code\n");
			scanf("%s%d%s%d",p[i].dm.a.home_name,&p[i].dm.a.home_no,p[i].dm.a.street,&p[i].dm.a.pincode);
			p[i].charges=250;
		}
		else if(p[i].delivery_type==2)
		{
			printf("Enter the mail id\n");
			scanf("%s",p[i].dm.w.mail_id);
			p[i].charges=100;
		}
		else if(p[i].delivery_type==3)
		{
			printf("Enter the pincode and phone no. in 2 parts\n");
			scanf ("%d%d%d",&p[i].dm.vm.code,&p[i].dm.vm.part1,&p[i].dm.vm.part2);
			p[i].charges=100;
		}
	}

}

void business()
{
	float home_delivary_charges=0,mail_charges=0,voice_mail_charges=0,total_charges=0;
	
	for(int i=0;i<5;i++)
	{
	if(p[i].delivery_type==1)
		home_delivary_charges+=p[i].charges;
	else if (p[i].delivery_type==2)
		mail_charges+=p[i].charges;
	else if (p[i].delivery_type==3)
		voice_mail_charges+=p[i].charges;
	}
	printf("Home delivery charge =%f\n",home_delivary_charges);
	printf("Web mail charges=%f\n",mail_charges);
	printf("Voice mail charges=%f\n",voice_mail_charges);
	total_charges+=home_delivary_charges+voice_mail_charges+mail_charges;
	printf("Total charges %f\n",total_charges);
}