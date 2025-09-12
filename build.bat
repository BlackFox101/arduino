@echo off

REM Проверяем, передан ли параметр
if "%~1"=="" (
    echo Error: Source dir is not supplied
    exit /b 1
)

REM Получаем путь к директории bat файла
set "SCRIPT_DIR=%~dp0"
set "SCR_DIRNAME=%~1

REM Проверяем существование папки
if not exist "%SCRIPT_DIR%\%SCR_DIRNAME%\" (
    echo Project "%SCR_DIRNAME%" not found
    exit /b 0
)

set PLATFORMIO_SRC_DIR=%SCR_DIRNAME%
set ENV=nano328new

pio run -t upload -e %ENV%