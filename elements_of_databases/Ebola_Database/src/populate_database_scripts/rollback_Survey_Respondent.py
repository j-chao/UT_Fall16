# Rollback Survey_Respondent Table
import pymysql
from db_connect import *

def rollback_Survey_Respondent():
    is_success = True
    rollback_stmt = "DELETE FROM Survey_Respondent;"
    try:
        insert_status = run_insert(rollback_stmt)
        if insert_status is False:
            is_success = False
            return is_success

    except IOError as e:
        is_success = False
        print ("rollback Survey_Respondent Error: " + e.strerror)

    return is_success
