# Create connection to database
import pymysql
import re

def create_connection():
    try:
        connection = pymysql.connect(host   = "localhost",
                                     user   = "root",
                                     passwd = "",
                                     db     = "ebola")
    
    except pymysql.Error as error:
        print ("connection error: ", error)
   
    return connection


def destroy_connection(conn):
    conn.close()

def run_insert(insert_stmt):
    is_success = True
    # run_protect against SQL injections
    if (run_protect(insert_stmt) is False):
        print("Suspicious activity detected. Action not permitted.")
        is_success = False
        return is_success

    try:
        conn = create_connection()
        cur = conn.cursor()
        cur.execute(insert_stmt)
        results = cur.fetchall()

        # output formatting for query results
        # widths = []
        # columns = []
        # tavnit = '|'
        # separator = '+' 

        # for cd in cur.description:
            # widths.append(max(cd[2], len(cd[0])))
            # columns.append(cd[0])

        # for w in widths:
            # tavnit += " %-"+"%ss |" % (w,)
            # separator += '-'*w + '--+'

        # print(separator)
        # print(tavnit % tuple(columns))
        # print(separator)
        # for row in results:
            # print(tavnit % row)
        # print(separator)

        conn.commit()
        destroy_connection(conn)

    # error checking
    except pymysql.Error as error:
        print ("insert error: ", error) 
        is_success = False
    return is_success


# function to protect against SQL injections
def run_protect(statement):
    if re.search('; drop table', statement, re.IGNORECASE):
        return False
    elif re.search('; truncate table', statement, re.IGNORECASE):
        return False
    elif re.search('; delete from', statement, re.IGNORECASE):
        return False
    elif re.search('or 1=1', statement, re.IGNORECASE):
        return False
    else:
        return True
