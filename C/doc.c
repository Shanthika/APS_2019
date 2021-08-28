#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_transaction();
void business();

struct adress
{
	int home_no;
	char home_name[];
	char street[];
	int pincode;
};
