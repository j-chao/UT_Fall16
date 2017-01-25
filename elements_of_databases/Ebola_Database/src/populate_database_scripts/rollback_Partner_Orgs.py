# Rollback Partner_Orgs Table
import pymysql
from db_connect import *

def rollback_Partner_Orgs():
    is_success = True
    rollback_stmt = "DELETE FROM Partner_Orgs;"
    try:
        insert_status = run_insert(rollback_stmt)
        if insert_status is False:
            is_success = False
            return is_success

                
    except IOError as e:
        is_success = False
        print ("rollback Partner_Orgs Error: " + e.strerror)

    return is_success
