::便捷刷入Magisk By St
::EasyMagisk By St
::Version: 1.2
::Date: 2023/12/8
::请勿编辑 DO NOT EDIT
::2023 St7530. 保留所有权利。
::联系邮箱：st75306@163.com

@echo off
set name=便捷刷入Magisk
set ver=1.2
title %name% Version:%ver% By St7530

echo --------------------
echo %name%
echo --------------------
echo.
echo 警告：
echo    1. 本程序为 seewo FC70ED 机型专用，请在希沃内置PC下运行本程序，非同款机型请慎重使用！
echo    2. 请仔细阅读并严格按照本程序的提示进行操作！
echo.
echo 注意：
echo    1. 请将 adb.exe 添加到环境变量，或将 adb.exe 和 AdbWinApi.dll 置于程序目录中
echo    2. 请设置 Windows 中用于与安卓互通的 Realtek 网卡的 IPv4 地址为 192.168.153.254 、子网掩码为 255.255.255.0 
echo    3. 请开启安卓的 USB调试 开关
echo    4. 请将 Magisk APK 安装包置于程序目录中并重命名为 "Magisk.apk" ，以便自动安装。
echo.
echo 请在知晓上述内容后，按任意键开始…
pause>nul

::Preparing
cls
adb kill-server
echo 正在连接安卓…
adb connect 192.168.153.253
adb devices
echo.
echo 正在安装Magisk.apk…
adb install Magisk.apk
echo 注意：如果安装失败，请先手动安装Magisk app后再继续！
echo.
adb root
adb shell mkdir /sdcard/EasyMagisk
echo.
pause

::Step 1
cls
echo 步骤1/2：修补并替换Recovery
adb shell cp /dev/block/recovery /sdcard
echo    1. 打开Magisk app
echo    2. 点击Magisk卡片旁的“安装”
echo    3. 勾选“安装到Recovery”，然后下一步
echo    4. 点击“选择并修补一个文件”，通过希沃自带的文件管理选择/sdcard/recovery，然后开始。
echo    5. 等待Magisk提示完成，你会得到/sdcard/Download/magisk_patched-[random_strings].img文件，这是修补后的Recovery，其中的[random_strings]是一个随机值。
echo.
echo 按任意键以打开Magisk app…
pause>nul
adb shell am start com.topjohnwu.magisk/.ui.MainActivity
echo 已打开Magisk app。
echo.
echo 请在修补操作完成后，按任意键继续…
pause>nul
echo.
echo 下方列出了当前/sdcard/Download/目录下的所有文件：
echo.
adb shell ls -l /sdcard/Download/
echo.
echo 例如：若修补后的文件名为magisk_patched-26300_AbCdE.img，则需要输入的[random_strings]值为26300_AbCdE

:dd1
set /p rand=请输入刚刚修补的映像的[random_strings]值：
echo.
adb shell cp /sdcard/Download/magisk_patched-%rand%.img /sdcard/EasyMagisk/recovery.img
echo 正在替换…
adb shell dd if=/sdcard/EasyMagisk/recovery.img of=/dev/block/recovery
adb shell dd if=/sdcard/EasyMagisk/recovery.img of=/dev/block/platform/ffe07000.emmc/recovery
adb shell dd if=/sdcard/EasyMagisk/recovery.img of=/dev/block/platform/ffe07000.emmc/by-name/recovery
echo.
choice /m 替换操作是否正常？若一切正常，请按Y继续；若刚刚输入了错误的[random_strings]值，请按N重新输入。
if %ERRORLEVEL% equ 2 (goto dd1)
adb shell mv /sdcard/recovery /sdcard/EasyMagisk/recovery_BAK
adb shell rm /sdcard/Download/magisk_patched-%rand%.img

::Step 2
cls
echo 步骤2/2：修补并替换Boot
adb shell cp /dev/block/boot /sdcard
echo    1. 打开Magisk app
echo    2. 点击Magisk卡片旁的“安装”
echo    3. 勾选“安装到Recovery”，然后下一步
echo    4. 点击“选择并修补一个文件”，通过希沃自带的文件管理选择/sdcard/boot，然后开始。
echo    5. 等待Magisk提示完成，你会得到/sdcard/Download/magisk_patched-[random_strings].img文件，这是修补后的Boot，其中的[random_strings]是一个随机值。
echo.
echo 按任意键以打开Magisk app…
pause>nul
adb shell am start com.topjohnwu.magisk/.ui.MainActivity
echo 已打开Magisk app。
echo.
echo 请在修补操作完成后，按任意键继续…
pause>nul
echo.
echo 下方列出了当前/sdcard/Download/目录下的所有文件：
echo.
adb shell ls -l /sdcard/Download/
echo.
echo 例如：若修补后的文件名为magisk_patched-26300_AbCdE.img，则需要输入的[random_strings]值为26300_AbCdE

:dd2
set /p rand=请输入刚刚修补的映像的[random_strings]值：
echo.
adb shell cp /sdcard/Download/magisk_patched-%rand%.img /sdcard/EasyMagisk/boot.img
echo 正在替换…
adb shell dd if=/sdcard/EasyMagisk/boot.img of=/dev/block/boot
adb shell dd if=/sdcard/EasyMagisk/boot.img of=/dev/block/platform/ffe07000.emmc/boot
adb shell dd if=/sdcard/EasyMagisk/boot.img of=/dev/block/platform/ffe07000.emmc/by-name/boot
echo.
choice /m 替换操作是否正常？若一切正常，请按Y继续；若刚刚输入了错误的[random_strings]值，请按N重新输入。
if %ERRORLEVEL% equ 2 (goto dd2)
adb shell mv /sdcard/boot /sdcard/EasyMagisk/boot_BAK
adb shell rm /sdcard/Download/magisk_patched-%rand%.img

::Done
adb shell sync
cls
echo 已完成Magisk刷入，相关文件已备份至 /sdcard/EasyMagisk 目录下。
echo 按任意键以重启到Recovery来启用Magisk…
pause>nul
adb reboot recovery
echo 按任意键退出程序…
pause>nul