::���ˢ��Magisk By St
::EasyMagisk By St
::Version: 1.2
::Date: 2023/12/8
::����༭ DO NOT EDIT
::2023 St7530. ��������Ȩ����
::��ϵ���䣺st75306@163.com

@echo off
set name=���ˢ��Magisk
set ver=1.2
title %name% Version:%ver% By St7530

echo --------------------
echo %name%
echo --------------------
echo.
echo ���棺
echo    1. ������Ϊ seewo FC70ED ����ר�ã�����ϣ������PC�����б����򣬷�ͬ�����������ʹ�ã�
echo    2. ����ϸ�Ķ����ϸ��ձ��������ʾ���в�����
echo.
echo ע�⣺
echo    1. �뽫 adb.exe ��ӵ������������� adb.exe �� AdbWinApi.dll ���ڳ���Ŀ¼��
echo    2. ������ Windows �������밲׿��ͨ�� Realtek ������ IPv4 ��ַΪ 192.168.153.254 ����������Ϊ 255.255.255.0 
echo    3. �뿪����׿�� USB���� ����
echo    4. �뽫 Magisk APK ��װ�����ڳ���Ŀ¼�в�������Ϊ "Magisk.apk" ���Ա��Զ���װ��
echo.
echo ����֪���������ݺ󣬰��������ʼ��
pause>nul

::Preparing
cls
adb kill-server
echo �������Ӱ�׿��
adb connect 192.168.153.253
adb devices
echo.
echo ���ڰ�װMagisk.apk��
adb install Magisk.apk
echo ע�⣺�����װʧ�ܣ������ֶ���װMagisk app���ټ�����
echo.
adb root
adb shell mkdir /sdcard/EasyMagisk
echo.
pause

::Step 1
cls
echo ����1/2���޲����滻Recovery
adb shell cp /dev/block/recovery /sdcard
echo    1. ��Magisk app
echo    2. ���Magisk��Ƭ�Եġ���װ��
echo    3. ��ѡ����װ��Recovery����Ȼ����һ��
echo    4. �����ѡ���޲�һ���ļ�����ͨ��ϣ���Դ����ļ�����ѡ��/sdcard/recovery��Ȼ��ʼ��
echo    5. �ȴ�Magisk��ʾ��ɣ����õ�/sdcard/Download/magisk_patched-[random_strings].img�ļ��������޲����Recovery�����е�[random_strings]��һ�����ֵ��
echo.
echo ��������Դ�Magisk app��
pause>nul
adb shell am start com.topjohnwu.magisk/.ui.MainActivity
echo �Ѵ�Magisk app��
echo.
echo �����޲�������ɺ󣬰������������
pause>nul
echo.
echo �·��г��˵�ǰ/sdcard/Download/Ŀ¼�µ������ļ���
echo.
adb shell ls -l /sdcard/Download/
echo.
echo ���磺���޲�����ļ���Ϊmagisk_patched-26300_AbCdE.img������Ҫ�����[random_strings]ֵΪ26300_AbCdE

:dd1
set /p rand=������ո��޲���ӳ���[random_strings]ֵ��
echo.
adb shell cp /sdcard/Download/magisk_patched-%rand%.img /sdcard/EasyMagisk/recovery.img
echo �����滻��
adb shell dd if=/sdcard/EasyMagisk/recovery.img of=/dev/block/recovery
adb shell dd if=/sdcard/EasyMagisk/recovery.img of=/dev/block/platform/ffe07000.emmc/recovery
adb shell dd if=/sdcard/EasyMagisk/recovery.img of=/dev/block/platform/ffe07000.emmc/by-name/recovery
echo.
choice /m �滻�����Ƿ���������һ���������밴Y���������ո������˴����[random_strings]ֵ���밴N�������롣
if %ERRORLEVEL% equ 2 (goto dd1)
adb shell mv /sdcard/recovery /sdcard/EasyMagisk/recovery_BAK
adb shell rm /sdcard/Download/magisk_patched-%rand%.img

::Step 2
cls
echo ����2/2���޲����滻Boot
adb shell cp /dev/block/boot /sdcard
echo    1. ��Magisk app
echo    2. ���Magisk��Ƭ�Եġ���װ��
echo    3. ��ѡ����װ��Recovery����Ȼ����һ��
echo    4. �����ѡ���޲�һ���ļ�����ͨ��ϣ���Դ����ļ�����ѡ��/sdcard/boot��Ȼ��ʼ��
echo    5. �ȴ�Magisk��ʾ��ɣ����õ�/sdcard/Download/magisk_patched-[random_strings].img�ļ��������޲����Boot�����е�[random_strings]��һ�����ֵ��
echo.
echo ��������Դ�Magisk app��
pause>nul
adb shell am start com.topjohnwu.magisk/.ui.MainActivity
echo �Ѵ�Magisk app��
echo.
echo �����޲�������ɺ󣬰������������
pause>nul
echo.
echo �·��г��˵�ǰ/sdcard/Download/Ŀ¼�µ������ļ���
echo.
adb shell ls -l /sdcard/Download/
echo.
echo ���磺���޲�����ļ���Ϊmagisk_patched-26300_AbCdE.img������Ҫ�����[random_strings]ֵΪ26300_AbCdE

:dd2
set /p rand=������ո��޲���ӳ���[random_strings]ֵ��
echo.
adb shell cp /sdcard/Download/magisk_patched-%rand%.img /sdcard/EasyMagisk/boot.img
echo �����滻��
adb shell dd if=/sdcard/EasyMagisk/boot.img of=/dev/block/boot
adb shell dd if=/sdcard/EasyMagisk/boot.img of=/dev/block/platform/ffe07000.emmc/boot
adb shell dd if=/sdcard/EasyMagisk/boot.img of=/dev/block/platform/ffe07000.emmc/by-name/boot
echo.
choice /m �滻�����Ƿ���������һ���������밴Y���������ո������˴����[random_strings]ֵ���밴N�������롣
if %ERRORLEVEL% equ 2 (goto dd2)
adb shell mv /sdcard/boot /sdcard/EasyMagisk/boot_BAK
adb shell rm /sdcard/Download/magisk_patched-%rand%.img

::Done
adb shell sync
cls
echo �����Magiskˢ�룬����ļ��ѱ����� /sdcard/EasyMagisk Ŀ¼�¡�
echo ���������������Recovery������Magisk��
pause>nul
adb reboot recovery
echo ��������˳�����
pause>nul