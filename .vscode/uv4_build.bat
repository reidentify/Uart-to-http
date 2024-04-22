@echo off

:: keil目录,需要修改为你电脑上keil的位置
set UV=C:\Keil_v5\UV4\UV4.exe

::uvproj文件所在目录
set UV_PRO_PATH=.\\Project
::uvproj文件名称
set UV_PRO_FILE=PMCU_DEMO.uvproj

set UV_BUILD_TARGET=%UV_PRO_PATH%\\%UV_PRO_FILE%

::临时文件，用于存储编译日志
set LOG_FILE=uv4_build.log
set LOG_PATH=%UV_PRO_PATH%
set LOG_TARGET=%LOG_PATH%\\%LOG_FILE%

echo Start building
echo wait...
::清空编译日志
echo . > %LOG_TARGET%
:: 执行keil编译命令
"%UV%" -j0 -b "%UV_BUILD_TARGET%" -l %LOG_TARGET%
:: 输出编译日志
type %LOG_TARGET%
::删除编译日志
del %LOG_TARGET%
echo Done.
exit
