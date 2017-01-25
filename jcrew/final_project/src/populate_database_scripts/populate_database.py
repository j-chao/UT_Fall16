#!/bin/python2

import pymysql
from import_Country import *
from import_Country_Org import *
from import_ETC import *
from import_ETC_Org import *
from import_Organization import *
from import_Partner_Org_ETC import *
from import_Partner_Orgs import *
from import_Survey_Respondent import *
from rollback_Country import *
from rollback_Country_Org import *
from rollback_ETC import *
from rollback_ETC_Org import *
from rollback_Organization import *
from rollback_Partner_Org_ETC import *
from rollback_Partner_Orgs import *
from rollback_Survey_Respondent import *

# rollback Partner_Org_ETC table
is_success = rollback_Partner_Org_ETC()
if is_success is True:
    print "rollback Partner_Org_ETC: successful"
else:
    print "rollback Partner_Org_ETC: failed"

# rollback Partner_Orgs table
is_success = rollback_Partner_Orgs()
if is_success is True:
    print "rollback Partner_Orgs: successful"
else:
    print "rollback Partner_Orgs: failed"

# rollback ETC_Org table
is_success = rollback_ETC_Org()
if is_success is True:
    print "rollback ETC_Org: successful"
else:
    print "rollback ETC_Org: failed"

# rollback Country_Org table
is_success = rollback_Country_Org()
if is_success is True:
    print "rollback Country_Org: successful"
else:
    print "rollback Country_Org: failed"

# rollback Organization table
is_success = rollback_Organization()
if is_success is True:
    print "rollback Organization: successful"
else:
    print "rollback Organization: failed"

# rollback ETC table
is_success = rollback_ETC()
if is_success is True:
    print "rollback ETC: successful"
else:
    print "rollback ETC: failed"

# rollback Survey_Respondent table
is_success = rollback_Survey_Respondent()
if is_success is True:
    print "rollback Survey_Respondent: successful"
else:
    print "rollback Survey_Respondent: failed"

# rollback Country table
is_success = rollback_Country()
if is_success is True:
    print "rollback Country: successful"
else:
    print "rollback Country: failed"

# populate Country table
is_success = import_Country()
if is_success is True:
    print "import Country: successful"
else:
    print "import Country: failed"

# populate Survey_Respondent table
is_success = import_Survey_Respondent()
if is_success is True:
    print "import Survey_Respondent: successful"
else:
    print "import Survey_Respondent: failed"

# populate ETC table
is_success = import_ETC()
if is_success is True:
    print "import ETC: successful"
else:
    print "import ETC: failed"

# populate Organization table
is_success = import_Organization()
if is_success is True:
    print "import Organization: successful"
else:
    print "import Organization: failed"

# populate Country_Org table
is_success = import_Country_Org()
if is_success is True:
    print "import_Country_Org: successful"
else:
    print "import_Country_Org: failed"

# populate ETC_Org table
is_success = import_ETC_Org()
if is_success is True:
    print "import ETC_Org: successful"
else:
    print "import ETC_Org: failed"

# populate Partner_Orgs table
is_success = import_Partner_Orgs()
if is_success is True:
    print "import Partner_Orgs: successful"
else:
    print "import Partner_Orgs: failed"

# populate Partner_Org_ETC table
is_success = import_Partner_Org_ETC()
if is_success is True:
    print "import Partner_Org_ETC: successful"
else:
    print "import Partner_Org_ETC: failed"
