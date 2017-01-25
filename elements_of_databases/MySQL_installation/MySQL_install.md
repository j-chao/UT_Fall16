# Installing MySQL on MacOS 
There are a couple different ways for installing MySQL. 
This method will install MySQL using native packages.

The following instructions should work for OS X Yosemite and later.
We're also assuming that you are a root user of your system.

## Completely Remove Any Previous MySQL Files
First stop all MySQL processes, including the database server.
You can check for MySQL processes using the following command in Terminal:

~~~~~~~ {.sh}
ps -ax | grep mysql
kill (replace this with the process ID)
~~~~~~~~

Now remove any previously failed installation files by running the following
commands in Terminal:

~~~~ {.sh}
sudo rm /usr/local/mysql
sudo rm -rf /usr/local/mysql*
sudo rm -rf /Library/StartupItems/MySQLCOM
sudo rm -rf /Library/PreferencePanes/My*
sudo vi /etc/hostconfig (Remove line MYSQLCOM=-YES) 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
(This step may not be necessary if you do not have a hostconfig file)

~~~~~~~{.sh}
sudo rm -rf /Library/Receipts/mysql*
sudo rm -rf /Library/Receipts/MySQL*
sudo rm -rf /var/db/receipts/com.mysql.*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

## Installing MySQL Using Native Packages

1. Download the .dmg file that contains the MySQL package installer. 
You can find it here: http://dev.mysql.com/downloads/mysql/

2. Double-click the MySQL installer package and proceed through a "Standard
   Install" on your system. 

3. When complete, a note will pop up with a temporary password that has been
   generated for root@localhost. WRITE THIS DOWN SOMEWHERE.

4. Close the installer and open Terminal.

5. Now set the $PATH in .bash_profile by running the following command in
   Terminal:

~~~~~~~{.sh}
        echo "export PATH=$PATH:/usr/local/mysql/bin" >> ~/.bash_profile
~~~~~~~~~~~

6. You can confirm the installation of MySQL by restarting Terminal and running
   the following command: 

~~~~~~~{.sh}
        mysql --version
~~~~~~~~
        It should return something like this: 
        mysql  Ver 14.14 Distrib 5.7.15, for osx10.11 (x86_64) using  EditLine wrapper

## Start MySQL server

You can either start the MySQL server from the MySQL Preference Pane in your
System Preferences, or by running the following command in Terminal:

~~~~~{.sh}
sudo launchctl load -F /Library/LaunchDaemons/com.oracle.oss.mysql.mysqld.plist
~~~~~

You may choose to have MySQL Server start automatically on Startup by selecting
the option in the MySQL Preference Pane, again, located in System Preferences.

# Start MySQL

In Terminal, run the following command:

~~~~{.sh}
mysql -u root -p
~~~~~~~
It will then prompt you for a password. Enter the temprorary password that you
wrote down earlier, and press enter.
This should start MySQL for the first time.

## Reset Password Upon First Startup

When you first start up MySQL, you will need to reset your password using the
ALTER USER statement.

To do this, run the following command in MySQL:

~~~~~~~{.sh}
ALTER USER 'root'@'localhost' IDENTIFIED BY '(replace with your password)';
~~~~~~~~~~~
It should return this:   
Query OK, 0 rows affected (0.00 sec)

If you do not want a password to be set, simply type the following
instead:

~~~~~~{.sh}
ALTER USER 'root'@'localhost' IDENTIFIED BY '';
~~~~~~~~~

## Optional: Making a Shell(bash) Alias

The way we have MySQL set up now requires you to type "mysql -u root -p" in
Terminal everytime to start MySQL. 
If you opted to not have a password set, then you would just type "mysql -u root".

To make life easier, we can create an alias in our .bash_profile file.

To do this, run the following command in Terminal:

~~~~~{.sh}
echo "alias mysql='mysql -u root -p'" >> ~/.bash_profile
~~~~~~

Of course, if you opted not to have a password, run this instead:

~~~~~~~{.sh}
echo "alias mysql='mysql -u root'" >> ~/.bash_profile
~~~~~~~~~

Restart Terminal.
Now, you can simply type "mysql" in Terminal to start MySQL.
