#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
	char *APPDATA = getenv("LOCALAPPDATA");
	int processStartArgProvided = 0;
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--processStart") == 0 && i < argc - 1 && strcmp(argv[i + 1], "Discord.exe") == 0)
		{
			processStartArgProvided = 1;
			break;
		}
	}
	if (argc == 1)
	{
		processStartArgProvided = 1;
	}

	if (processStartArgProvided)
	{
		char *THISCORD_PATH = strcat(APPDATA, "\\Thiscord\\ThisCord-Master\\src\\main.py");
		system(THISCORD_PATH);
	}
	else
	{
		char *UPDATE_DISCORD_PATH = strcat(APPDATA, "\\Update_Discord.exe");
		char argsString[4096] = "";
		for (int i = 1; i < argc; i++)
		{
			strcat(argsString, argv[i]);
			strcat(argsString, " ");
		}
		char command[4096];
		snprintf(command, sizeof(command), "\"%s\" %s", UPDATE_DISCORD_PATH, argsString);
		system(command);
	}

	return 0;
}
