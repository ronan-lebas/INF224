@echo off

REM Create the directory
mkdir Lebas__Ronan

REM Copy the directories into it
xcopy /E /I cpp Lebas__Ronan\cpp
xcopy /E /I swing Lebas__Ronan\swing

REM Convert the README to PDF
pandoc README.md -s -o README.pdf

REM Copy the PDF into the directory
copy README.pdf Lebas__Ronan\

REM Create a zip file of the directory
powershell.exe -nologo -noprofile -command "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::CreateFromDirectory('Lebas__Ronan', 'Lebas__Ronan.zip'); }"

REM Delete the directory and the PDF
rmdir /S /Q Lebas__Ronan
del README.pdf