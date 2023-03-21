## Part 1. Installation of the OS

* command cat /etc/issue.

    ![quest1](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/Quest1.png)

## Part 2. Creating a user

* Создание нового пользователя и добавление его в группу adm

    sudo useradd new_person

    sudo usermod -a -G adm new_person

    cat /etc/passwd

    ![quest2](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/Quest2.png)

## Part 3. Setting up the OS network
* Изменение названия машины

    ![quest3_1](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.1.png)

* Установка временной зоны

    ![quest3.2](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.2.png)

* Вывод названия сетевых интерфейсов

    ![quest3.3](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.3.png)

    Интерфейс lo виртуальный интерфейс всегда присутствующий на linux. Используется для отладки сетевых программ и запуска серверных приложений на локальной машине. 
    У него всегда адрес 127.0.0.1

* Получаем новый IP от DHCP

    ![quest3.4](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.4.png)

    DHCP - Dynamic Host Configuration Protocol

* Внешний и внутренний IP

    ![quest3.5](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.5.png)

* Задаем статичный IP в конфигурационном файле
    sudo vim /etc/netplan/...

    ![quest3.5](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.6.png)

    Применяем изменения:
    sudo netplan apply

* Перезагружаем: reboot

    Проверяем что у нас теперь статичный IP

    ![quest3.7](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.7.png)

    Пингуем удаленные хосты

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.7.2.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/3.7.3.png)

## Part 4. OS Update
* Установка обновлений

   sudo apt upgrade

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/4.png)

## Part 5. Using the sudo command
*  Наделение правами другого пользователя

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/5.1.png)

    Изменение названия машина с правами root от другого пользователя

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/5.2.png)

    Благодаря sudo (substitute user and do, подменить пользователя и выполнить) пользователь может выполнить привелигиированные команды без необходимости быть суперпользователем root.
## Part 6. Installing and configuring the time service
* Установка и настройка службы времени

    sudo apt-get install ntp

    sudo vim /etc/systemd/timesyncd.conf

    sudo timedatectl set-ntp true

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/6.png)
## Part 7. Installing and using text editors
* Сохранение

    vim  -    :wq

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.1.1.png)

    nano - Ctrl + O

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.1.2.png)

    joe - Ctrl + K and Q

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.1.3.png)
* Выход без сохранения

    vim   -  :q!

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.2.1.png)

    nano - Ctrl + X and NO

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.2.2.png)

    joe -  Ctrl + C and YES

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.2.3.png)
* Поиск по файлу и замена

    vim - /...

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.3.1.png)

    nano - Ctrl + W

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.3.2.png)

    joe - Ctrl + K and F

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.3.3.png)

    vim - :s/"что"/"чем"

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.3__1.png)

    nano - Ctrl + \ 

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.3__2.png)

    joe - Ctrl + K and F and R(eplace)
    
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/7.3__3.png)

## Part 8. Installing and basic setup of the SSHD service
* sudo apt install openssh-server

* sudo systemctl enable sshd

* Изменил в файле порт на 2022
    sudo vim /etc/ssh/sshd_config

* Наличие процесса sshd

    ps -C sshd
    
    ps - команда для того чтобы посмотреть процессы
    
    -С - флаг позволяет выбрать процесс по имени

* netstat -tan

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/8.png)
    
    Ключи:

    -a Отображает все активные TCP-подключения и порты TCP и UDP, на которых    компьютер прослушивает

    -n Отображает активные TCP-подключения, однако адреса и номера портов выражаются числовым образом и не предпринимается никаких попыток определения имен
    
    -t Отображает TCP подключения

* Proto - протокол (tcp, udp, raw), используемый сокетом

    Recv-Q - счётчик байт не скопированных программой пользователя из этого сокета
    
    Send-Q - счётчик байтов, не подтверждённых удалённым узлом

    Local Address - адрес и номер порта локального конца сокета

    Foreign Address - адрес и номер порта удалённого конца сокета

    State - состояние сокета

    LISTEN - cокет ожидает входящих подключений

    IP-адрес 0.0.0.0 — это немаршрутизируемый адрес IPv4, который можно использовать в разных целях, в основном, в качестве адреса по умолчанию или адреса-заполнителя. Несмотря на то, что адрес 0.0.0.0 может использоваться в компьютерных сетях, он не является адресом какого-либо устройства.

## Part 9. Installing and using the top, htop utilities
* top:

    uptime 1:23

    1 user

    load average: 0.00, 0.00, 0.00

    Tasks: 95 total

    %Cpu(s): 0.0 us, 0.0 sy, 0.0 ni, 100.0 id, 0.0 wa, 0.0 hi, 0.0 si, 0.0 st

    Mib Mem: 1983.4 total, 1162.4 free, 165.0 used, 656.0 buf/cache

    653

    2313

* htop

    Сортировка по PID

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/9.1.png)

    Сортировка по CPU

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/9.2.png)

    Сортировка по MEM

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/9.3.png)

    Сортировка по TIME

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/9.4.png)

    Фильтр sshd

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/9.5.png)

    Поиск syslog

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/9.6.png)

    Добавление hostname, clock, uptime

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/9.7.png)

## Part 10. Using the fdisk utility
* Disk /dev/sda: 10.24 GiB, 10992394240 bytes, 21469520 sectors

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/10.png)

## Part 11. Using the df utility
* df

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/11.1.png)

    килобайты

* df -Th

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/11.2.png)

    ext4

## Part 12. Using the du utility

* du

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/12.1.png)

* sudo -hs du /home

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/12.2.png)

* sudo -hs /var 

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/12.2.1.png)

* sudo -hs /var/log

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/12.2.2.png)

* sudo -h /var/log/*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/12.3.png)

## Part 13. Installing and using the ncdu utility

* ncdu /home

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/13.1.png)

* ncdu /var

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/13.2.png)

* ncdu /var/log/

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/13.3.png)

## Part 14. Working with system logs

* vim /var/log/dmesg

    vim /var/log/syslog

    vim /var/log/auth.log

* Время последнего входа: Feb 21, 18:29:25, user oleg, method login

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/14.1.png)

* Restart sshd: sudo systemctl restart ssh

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/14.2.png)

## Part 15. Using the CRON job scheduler

* crontab -e and changed file

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/15.1.png)

* syslog, uptime is working

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/15.2.png)
* Задачи cron
    
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/15.4.png)

* Удалил задания из планировщика задач

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_part1/Images/15.3.png)

It's all!