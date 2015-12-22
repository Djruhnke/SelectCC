//C program for calculating the hip and valley of a roof
//when no roof plan is present and only have access to elevations
//meant to be run as a .exe from the desktop for ease of access with
//users that are unexperienced with compiling and executing C
//programs with parameters and tags

#include <stdio.h>
#include <math.h>
#include <string.h>

void gatherInfo(float* length, float* height, float* pitch){
	float lengthFeet;
	float lengthInches;
	float heightFeet;
	float heightInches;

	//Gather info on length of rake
	printf("-The length from the start point to the end point of the \nhip or valley in when looking at it in elevation view (i.e. the rake)\n");
	printf("Please enter the length described above \nrounded down to the nearest whole foot: ");
	scanf("%f", &lengthFeet);
	printf("Please enter the remaining inches of the \nlength described above: ");
	scanf("%f", &lengthInches);

	//Calculate Length
	*length = lengthFeet + (lengthInches / 12);

	//Gather info on height of hip/valley
	printf("-The vertical height from the bottom of the hip/valley to the top\n");
	printf("Please enter the height described above \nrounded down to the nearest whole foot: ");
	scanf("%f", &heightFeet);
	printf("Please enter the remaining inches of the \nheight described above: ");
	scanf("%f", &heightInches);

	//Calculate Height
	*height = heightFeet + (heightInches / 12);

	//Gather info on pitch
	printf("-The pitch of the surface that is facing the elevation\n");
	printf("Please enter the pitch described above \nby entering as a single number (i.e. 6 not 6/12): ");
	scanf("%f", pitch);
}

void findResult(float length, float height, float pitch, float* resultFeet, float* resultInches){
	//Calculates the result in feet and inches, always rounding up to the next inch
	float depth = (height / pitch) * 12;
	*resultFeet = sqrt(length * length + depth * depth);
	*resultInches = ceil((*resultFeet - floor(*resultFeet)) * 12);
	*resultFeet = floor(*resultFeet);
	printf("\n");
	printf("The hip/valley is %d feet %d inches\n", (int) *resultFeet, (int) *resultInches);
	printf("\n");
}

int main (){
	float length;
	float height;
	float pitch;
	float depth;
	float resultFeet;
	float resultInches;
	char response[1000];

	gatherInfo(&length, &height, & pitch);

	findResult(length, height, pitch, &resultFeet, &resultInches);

	//Check if user desires to continue
	printf("Calculate another hip/valley? (Y/N): ");
	scanf("%s", response);
	printf("\n");

	//Repeat process if the user wishes to continue
	while (strcmp(response, "y") == 0 || strcmp(response, "Y") == 0 || strcmp(response, "YES") == 0 || strcmp(response, "Yes") == 0 || strcmp(response, "yes") == 0) {
		gatherInfo(&length, &height, &pitch);

		findResult(length, height, pitch, &resultFeet, &resultInches);

		printf("Calculate another hip/valley? (Y/N): ");
		scanf("%s", response);
		printf("\n");
	}
	return 0;
}