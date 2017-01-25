# Rollback Partner_Org_ETC Table
import pymysql
from db_connect import *

def rollback_Partner_Org_ETC():
    is_success = True
    rollback_stmt = "DELETE FROM Partner_Org_ETC;"
    try:
        insert_status = run_insert(rollback_stmt)
        if insert_status is False:
            is_success = False
            return is_success
                
    except IOError as e:
        is_success = False
        print ("rollback Partner_Org_ETC Error: " + e.strerror)

    return is_success
