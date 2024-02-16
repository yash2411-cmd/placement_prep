@echo off

REM Check if argument is provided
if "%~1"=="" (
    echo Error: Please provide a commit message.
    exit /b 1
)

REM Stage changes
git add .

REM Commit changes with provided message
git commit -m "%~1"

REM Push changes
git push
