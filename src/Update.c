#include <windows.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	char *APPDATA = getenv("LOCALAPPDATA");
	bool processStartArgProvided = false;
	bool uninstallArgProvided = false;
	if (argc == 1)
	{
		processStartArgProvided = true;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (strcmp(argv[i], "--processStart") == 0 && i < argc - 1 && strcmp(argv[i + 1], "Discord.exe") == 0)
			{
				processStartArgProvided = true;
				break;
			}
			else if (strcmp(argv[i], "--uninstall") == 0)
			{
				uninstallArgProvided = true;
			}
		}
	}

	if (processStartArgProvided)
	{
		char *THISCORD_PATH = strcat(APPDATA, "\\Thiscord\\ThisCord-Master\\src\\main.py");
		system(THISCORD_PATH);
	}
	else
	{
		if (uninstallArgProvided)
		{
			int result = MessageBox(NULL, "Please uninstall ThisCord via the installer before uninstalling Discord.\nThe installer can be found at github.com/titushm/Thiscord-Installer", "Thiscord", MB_OK);
			if (result == IDOK)
			{
				char *UPDATE_DISCORD_PATH = strcat(APPDATA, "\\Discord\\Update_Discord.exe");
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
		}
		else
		{
			char *UPDATE_DISCORD_PATH = strcat(APPDATA, "\\Discord\\Update_Discord.exe");
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
	}

	return 0;
}
