# Rollback ETC_Org Table
import pymysql
from db_connect import *

def rollback_ETC_Org():
    is_success = True
    rollback_stmt = "DELETE FROM ETC_Org;"
    
    try:
            insert_status = run_insert(rollback_stmt)
            if insert_status is False:
                is_success = False
                return is_success
                
    except IOError as e:
        is_success = False
        print ("rollback ETC_Org Error: " + e.strerror)

    return is_success
