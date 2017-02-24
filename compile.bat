@ECHO OFF
echo "Calling VsDevCmd.bat, run cmd.exe first then..."
echo  
CALL "%VS140COMNTOOLS%\VsDevCmd.bat"
CALL "rc.exe" icons.rc
CALL "cl.exe" /LD our_dll.cpp /link icons.res
CALL "cl.exe" load_dll.cpp
CALL "cl.exe" /LD resource_only.cpp /link icons.res /NOENTRY /out:resource_only.dll
echo "Finished, now run load_dll.exe and watch the popup/s..."
echo "To delete all the compiled stuff run..."
echo "----------------------------------"
echo del *.obj *.lib *.exp *.res *.dll *.exe
echo "----------------------------------"
echo rundll32.exe .\our_dll.dll,MsgBox(0)
echo "----------------------------------"

