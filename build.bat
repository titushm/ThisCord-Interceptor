IF NOT EXIST build (
	mkdir build
) ELSE (
	rmdir /s /q build
)
gcc src/Update.c src/icon.res -o build/Update.exe
mt.exe -manifest src/Update.exe.manifest -outputresource:build/Update.exe;#1