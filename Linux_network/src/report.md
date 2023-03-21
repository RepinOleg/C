## Part 1. ipcalc tool

* **1.1. Networks and Masks**

    **1) Сетевой адрес 192.167.38.54/13 - 192.160.0.0**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.1.png)

    **2) Преобразование маски:**

    *255.255.255.0*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.2.1.png)

    */15*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.2.2.png)

    *11111111.11111111.11111111.1111000*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.2.3.png)

    **3) Минимальный и максимальный хост в сети 12.167.38.4**

    *1) с маской /8*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.3.1.png)

    *2) с маской 11111111.11111111.00000000.00000000*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.3.2.png)

    *3) с маской 255.255.254.0*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.3.3.png)

    *4) с маской /4*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/1.1.3.4.png)

* **1.2. localhost**

    194.34.23.100 - NO

    127.0.0.2 - YES

    127.1.0.1 - YES

    128.0.0.1 - NO

    Диапазон localhost 127.0.0.1 — 127.255.255.254

* **1.3. Network ranges and segments**

    **1) Какие из перечисленных IP можно использовать в качестве публичного, а какие только в качестве частных**


    private: 10.0.0.45, 192.168.4.2, 172.20.250.4, 172.16.255.255, 
    10.10.10.10

    public: 134.43.0.2, 172.0.2.1, 192.172.0.1, 172.68.0.2, 192.169.168.1

    **2) Какие из перечисленных IP адресов шлюза возможны у сети 10.10.0.0/18**

        10.0.0.1 - No

        10.10.0.2 - Yes

        10.10.10.10 - Yes

        10.10.100.1 - No

        10.10.1.255 - Yes

## Part 2. Static routing between two machines
* *IP a*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.1.png)

    *Изменение IP*

    *etc/netplan/00-installer-config.yaml (ws1)*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.1.2.png)

    *etc/netplan/00-installer-config.yaml (ws2)*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.1.1.png)

    *netplan apply*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.1.3.png)

* **2.1. Adding a static route manually**
    
    *ip r add ws1*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.2.1.png)

    *ip r add ws2*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.2.2.png)

    *ping*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.2.3.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.2.4.png)
* **2.2. Adding a static route with saving**

    *etc/netplan/00-installer-config.yaml (ws1)*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.3.2.png)

    *etc/netplan/00-installer-config.yaml (ws2)*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.3.1.png)

    *ping*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.3.3.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/2.3.4.png)

## Part 3. iperf3 utility

* **3.1. Connection speed**

    8 Mbps = 1 MB/s

    100 MB/s = 800000 kbps

    1 Gbps = 1000 Mbps

* **3.2. iperf3 utility**

    *Измерить скорость между хостами*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/3.2.1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/3.2.2.png)

## Part 4. Network firewall
* **4.1. Утилита iptables**


    *Создать файл /etc/firewall.sh, имитирующий фаерволл, на ws1 и ws2:*

    на ws1 применить стратегию когда в начале пишется запрещающее правило, а в конце пишется разрешающее правило (это касается пунктов 4 и 5)

    на ws2 применить стратегию когда в начале пишется разрешающее правило, а в конце пишется запрещающее правило (это касается пунктов 4 и 5)

    открыть на машинах доступ для порта 22 (ssh) и порта 80 (http)

    запретить echo reply (машина не должна "пинговаться”, т.е. должна быть блокировка на OUTPUT)

    разрешить echo reply (машина должна "пинговаться")

    **ws1 firewall:**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/4.1.png)

    **ws2 firewall:**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/4.2.png)

    **Запуск /etc/firewall.sh**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/4.3.png)

    *Из-за того что, правило на DROP на первой машине стоит первым, второе правило на ACCEPT не будет действовать и тоже самое на второй машине только наоборот.*

* **4.2. nmap utility**

    *NMAP помогает системным администраторам очень быстро понять какие компьютеры подключены к сети, узнать их имена, а также посмотреть какое программное обеспечение на них установлено, какая операционная система и какие типы фильтров применяются.*

    **Пингуем с ws2 - ws1, затем используем nmap**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/4.4.png)

## Part 5. Static network routing
* **5.1 Configuration of machine addresses**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/part5_network.png)

    *Настроить конфигурации машин в etc/netplan/00-installer-config.yaml согласно сети на рисунке.*

    **ws11**
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/ws11yaml.png)

    **ws21**
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/ws21yaml.png)

    **ws22**
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/ws22yaml.png)

    **r1**
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/r1yaml.png)
    
    **r2**
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/r2yaml.png)

    **Применение конфигурации, ip -4 a, ping**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/ws11_ip.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/ws21_ip.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/ws22_ip.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/r1_ip.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/r2_ip.png)

* **5.2. Enabling IP forwarding.**

    **Для включения переадресации IP, выполните команду на роутерах:**
    *sysctl -w net.ipv4.ip_forward=1*

    *r1*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.2.1.png)

    *r2*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.2.2.png)

    **Open /etc/sysctl.conf file and add the following line net.ipv4.ip_forward = 1**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.2.3.png)

* **5.3. Default route configuration**

    * *Настроить маршрут по-умолчанию (шлюз) для рабочих станций. Для этого добавить default перед IP роутера в файле конфигураций*

    *yaml ws11*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.ws11.png)

    *yaml ws21*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.ws21.yaml.png)

    *yaml ws22*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.ws21.yaml.png)

    *yaml r1*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.r1.yaml.png)

    *yaml r2*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.r2.yaml.png)

    * *Вызвать ip r и показать, что добавился маршрут в таблицу маршрутизации*

    *ws11*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.ws11%20ip.png)

    *ws21*
    
    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.ws21.ip.png)

    *ws22*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.ws22.ip.png)

    *r1*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.r1.ip.png)

    *r2*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.r2.ip.png)

    * *Пропинговать с ws11 роутер r2 и показать на r2, что пинг доходит. Для этого использовать команду:*
        tcpdump -tn -i eth1

    ping from ws11

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.3.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.3.3.1.png)

* **5.4. Adding static routes**

    *Добавить в роутеры r1 и r2 статические маршруты в файле конфигураций. Пример для r1 маршрута в сетку 10.20.0.0/26:*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.4.1.r1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.4.1.r2.png)

    *Вызвать ip r и показать таблицы с маршрутами на обоих роутерах*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.4.2.r1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.4.2.r2.png)

    *Запустить команды на ws11: ip r list 10.10.0.0/[маска сети] и ip r list 0.0.0.0/0*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.4.3.png)

    Если бы не был указан конкретный адрес перехода на пути пакета, то в качестве статического адреса по умолчанию указывается 0.0.0.0, а мы только что задали конкретный адрес, поэтому был выбран маршрут указаный мной.

* **5.5. Making a router list**

    *Запустить на r1 команду дампа: tcpdump -tnv -i eth0*

    *При помощи утилиты traceroute построить список маршрутизаторов на пути от ws11 до ws21*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.5.1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.5.2.png)

    Программа traceroute выполняет отправку данных к указанному узлу сети и при этом отображает сведения о всех промежуточных маршрутизаторах, через которые прошли данные. Она отправляет пакеты с TTL(время жизни), первый пакет имеет TTL=1. Когда маршрутизатор принимает пакет, он возвращает обратно сообщение ICMP. После этого traceroute фиксирует данные о маршрутизаторе и отправляет новый пакет с TTL + 1. Так повторяется пока пакет не достигает места назначения.

* **5.6. Using ICMP protocol in routing**

    *Запустить на r1 перехват сетевого трафика, проходящего через eth0 с помощью команды: tcpdump -n -i eth0 icmp*

    *Пропинговать с ws11 несуществующий IP (например, 10.30.0.111) с помощью команды: ping -c 1 10.30.0.111*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.6.1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/5.6.2.png)

## Part 6. Dynamic IP configuration using DHCP

* **Для r2 настроить в файле /etc/dhcp/dhcpd.conf конфигурацию службы DHCP**

    Указать адрес маршрутизатора по-умолчанию, DNS-сервер и адрес внутренней сети.

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.1.1.png)

* **В файле resolv.conf прописать nameserver 8.8.8.8**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.1.2.png)

* **Перезагрузить службу DHCP командой systemctl restart isc-dhcp-server. Машину ws21 перезагрузить при помощи reboot и через ip a показать, что она получила адрес. Также пропинговать ws22 с ws21.**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.2.3.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.2.1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.2.2.png)

* **Указать MAC адрес у ws11, для этого в etc/netplan/00-installer-config.yaml надо добавить строки: macaddress: 10:10:10:10:10:BA, dhcp4: true**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.4.1.png)

* **Для r1 настроить аналогично r2, но сделать выдачу адресов с жесткой привязкой к MAC-адресу (ws11). Провести аналогичные тесты**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.5.1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.5.2.png)

    Получили статичный IP прописанный вручную для этого MAC адреса

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.5.4.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.5.3.png)

* **Запросить с ws21 обновление ip адреса**

    **До обновления IP:**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.5.5.png)

    **После выполнения: sudo dhclient -r, sudo dhclient**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/6.5.6.png)

    Флаг -r освобождает все сетевые адреса

## Part 7. NAT

* **В файле /etc/apache2/ports.conf на ws22 и r1 изменить строку Listen 80 на Listen 0.0.0.0:80, то есть сделать сервер Apache2 общедоступным**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.1.1.png)

* **Запустить веб-сервер Apache командой service apache2 start на ws22 и r1**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.2.png)

* **Добавить в фаервол, созданный по аналогии с фаерволом из Части 4, на r2 следующие правила:**

    *удаление правил в таблице filter - iptables -F*


    *удаление правил в таблице "NAT" - iptables -F -t nat*


    *отбрасывать все маршрутизируемые пакеты - iptables --policy FORWARD DROP*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.3.1.png)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.3.2.png)

    *Проверить соединение между ws22 и r1 командой ping*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.3.3.png)

* **Добавить в файл ещё одно правило:**

    *Pазрешить маршрутизацию всех пакетов протокола ICMP*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.4.1.png)

    *Проверить соединение между ws22 и r1 командой ping*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.4.2.png)

* **Добавить в файл ещё два правила:**

    *включить SNAT, а именно маскирование всех локальных ip из локальной сети, находящейся за r2 (по обозначениям из Части 5 - сеть 10.20.0.0)*

    *включить DNAT на 8080 порт машины r2 и добавить к веб-серверу Apache, запущенному на ws22, доступ извне сети*

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.6.1.png)

* **Проверить соединение по TCP для SNAT, для этого с ws22 подключиться к серверу Apache на r1 командой telnet адрес порт**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.6.2.png)

* **Проверить соединение по TCP для DNAT, для этого с r1 подключиться к серверу Apache на ws22 командой: telnet (обращаться по адресу r2 и порту 8080)**

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/7.6.3.png)

## Part 8. Bonus. Introduction to SSH Tunnels

*   Запустить на r2 фаервол с правилами из Части 7

    Запустить веб-сервер Apache на ws22 только на localhost (то есть в файле /etc/apache2/ports.conf изменить строку Listen 80 на Listen localhost:80)

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/8.1.png)

    Выполнил sudo service apache2 start

* Воспользоваться Local TCP forwarding с ws21 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws21

    Скачал openssh на ws22, открыл порт 5555.

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/8.2.png)

    Проверка соединения

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/8.2.1.png)

* Воспользоваться Remote TCP forwarding c ws11 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws11

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/8.3.png)

    Проверка соединения

    ![](https://github.com/RepinOleg/Educational-projects/blob/develop/Linux_network/Images/8.3.1.png)

# It's ALL!

    





   



