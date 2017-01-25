#!/usr/local/bin/python
import pymysql

db = pymysql.connect (host   ="localhost", # your host, for this lab, you don't need to change
                      user   = "root",     # your username
                      passwd = "",         # your password
                      db     = "ebola")    # name of the database

# you must create a Cursor object. It will let you execute all the queries you need
cur = db.cursor()

# Use all the SQL you like
cur.execute("select * from ETC")
cur.execute("show tables")
print("Explain ETC")
cur.execute("explain ETC")


# print all the first cell of all the rows
for row in cur.fetchall():
    print row

db.close()
