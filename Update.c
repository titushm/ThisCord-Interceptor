#include <stdlib.h>
#include <string.h>

int main() {
	char *APPDATA = getenv("LOCALAPPDATA");
	char *THISCORD_PATH = strcat(APPDATA, "\\Thiscord\\ThisCord-Master\\src\\main.py");
	system(THISCORD_PATH);
	return 0;
}
