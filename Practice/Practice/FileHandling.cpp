#include <iostream>
#include <string>
#include <crtdbg.h>
using namespace std;


typedef struct Coordinates {
	int x;
	int y;
} cordinates;

int main() {
	cordinates coords;

	coords.x = 5;
	coords.y = 10;

	FILE* in;
	FILE* out;
	char buffer_in[256], buffer_out[256]; // Buffer For Input Output

	// Writing File 
	fopen_s(&out, "padding.txt", "w"); // Open File For Writing
	sprintf_s(buffer_out, sizeof(buffer_out), "%d%d", coords.x, coords.y); // Move String In buffer_out
	size_t bytes_wrote = fwrite(buffer_out, sizeof(char), strlen(buffer_out), out); // buffer_out buffer write in file
	fclose(out); // do not close ( do not read the file) so close file !

	// Reading File
	fopen_s(&in, "padding.txt", "r"); // open for read file 
	//fread_s(buffer_in,sizeof(buffer_out),sizeof(char),bytes_wrote, in); // move read (data) buffer_in
	if (fgets(buffer_in, sizeof(buffer_in), in) == NULL) {
		fclose(in);
		return 1;
	}  // Any Character Missed For Any Reason They Return 

	coords.x = 15;
	coords.y = 25;
	
	fclose(in);

};