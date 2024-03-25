//
//
//
////typedef struct Coordinates {
////	int x;
////	int y;
////} coordinates;
//
//
//int main() {
//
//	//coordinates coords;
//
//	/*coords.x = 5;
//	coords.y = 10;*/
//	//FILE* in;
//	//FILE* out;*/
//	//char buffer_in[256],buffer_out[256]; // Buffer For Input Output
//
//	//					// Writing File 
//	//fopen_s(&out, "padding.txt", "w"); // Open File For Writing
//	//sprintf_s(buffer_out, sizeof(buffer_out), "%d%d",coords.x,coords.y); // Move String In buffer_out
//	//size_t bytes_wrote = fwrite(buffer_out, sizeof(char), strlen(buffer_out), out); // buffer_out buffer write in file
//	//fclose(out); // first close the file  ( read the file) 
//	//
//	//					// Reading File
//	//fopen_s(&in, "padding.txt", "r"); // open for read file 
//	////fread_s(buffer_in,sizeof(buffer_out),sizeof(char),bytes_wrote, in); // move read (data) buffer_in
//	//if (fgets(buffer_in, sizeof(buffer_in), in) == NULL) { // Helps Read Data
//	//	fclose(in);
//	//	return 1;
//	//}  // Any Character Missed For Any Reason They Return NULL 
//
//	//coords.x = 15;
//	//coords.y = 25;
//	//sscanf_s(buffer_in, "%d   %d   " , &coords.x, &coords.y); // read data put data ( coords.x && coords.y )
//	//cout << coords.x << " " << coords.y << endl;
//	//fclose(in);
//
//
//
//	//cordinates coords1;
//	// 
//	//fopen_s(&out, "olx.bin", "wb"); // open for write file 
//	//if (out == NULL) {
//	//	return 1;
//	//}
//
//	//		// writing file .bin
//	//fwrite(&coords, sizeof(coords), 1, out);
//	//fclose(out);
//
//	//	// Reading File .bin
//	//fopen_s(&in, "olx.bin", "rb");
//	//if (in == NULL) {
//	//	return 2;
//	//}
//
//
//	//fread(&coords1, sizeof(cordinates), sizeof(cordinates), in);
//	//printf("%d - %d", coords1.x, coords.y);
//
//		//fopen_s(&out, "olx.txt", "w"); // open for write file 
//	//if (out == NULL) {
//	//	return 1;
//	//}
//	//char buffer[50];
//	//buffer[0] = 'a';
//	//buffer[1] = 'b';
//
//	//fprintf(out, "20");
//	//fseek(out, 1, SEEK_END);
//
//	//fprintf(out, "24");
//	//fclose(out);
//	//cout << SEEK_CUR << endl;
//
//
//
//
//}