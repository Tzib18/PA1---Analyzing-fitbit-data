#include "Header.h"

int read_data(char *target, FitbitData* user, char* ID)
{
	FILE* infile = fopen("FitbitData", "r");
	char* buffer[100] = "";
	char* patient[10] = "";
	double ID;

	fgets(buffer, 100, infile);
	printf("data read: %s", buffer);

	if (ID == strtok(buffer, ","))
	{
		patient[10] = strtok(NULL, ",");
		strcpy(patient, ID);
	}
	fgets(buffer, 100, infile);

	int Mcount = 0;

	while (fgets(buffer, 100, infile) != NULL) {
		char* token = strtok(buffer, ",");
		if (token == NULL)
		{
			return 1;
		}
		if (strcmp(token, target) == 0)
		{
			strcpy(user[Mcount].patient, token);
		}
		else {
			return 0;
		}
		token = strtok(NULL, ",");
		if (token != NULL)
		{
			strcpy(user[Mcount].minute, token);
		}
		token = strtok(NULL, ",");
		user[Mcount].calories = atof(token);
		
		token = strok(NULL, ",");
		user[Mcount].distance = atof(token);

		token = strtok(NULL, ",");
		user[Mcount].floors = atoi(token);

		token = strtok(NULL, ",");
		user[Mcount].heartRate = atoi(token);

		token = strtok(NULL, ",");
		user[Mcount].steps = atoi(token);

		token = strtok(NULL, ",");
		user[Mcount].sleepLevel = atoi(token);
		Mcount++;
	}
}

void cleaning_lines(FILE*user)
{

}


double Tcalories(FitbitData* user)
{
	double total = 0;
	for (int i = 0; i < 1440; i++)
	{
		total += user[i].calories;
	}
	return total;
}

double Tdistance(FitbitData* user)
{
	double total = 0;
	for (int i = 0; i < 1440; i++)
	{
		total += user[i].distance;
	}
	return total;
}


double Tfloors(FitbitData* user)
{
	//int total = 0;
	//for (int i = 0; i < 1440; i++)
	//{
	//	total += user[i].floors;
	//}
	//return total;
	Tfloors = Tdistance; 
	return Tdistance; 

}








void main_menu()
{
	char *data[1400];



	return 0;
}