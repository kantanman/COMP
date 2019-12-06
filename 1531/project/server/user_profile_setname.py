from json import dumps

from flask import Flask, request

import server_data
from ld_data import dump_data, load_data
from myexcept import raise_err


# helper function to check length
def isCorrectLength(name):
    if(len(name) >= 50 or len(name) <= 1):
        return 0
    return 1
# Update authorized user's first name and last nam


def set_name(token, name_first, name_last, data):
    if not server_data.authToken(token, data):
	    raise_err('AccessError', 'This is an invalid token')
    u_id = server_data.retrieveUid(token, data)
    # valid input check
    if(isCorrectLength(name_first) == 0 or isCorrectLength(name_last) == 0):
        raise_err('ValueError', 'This is incorrct length')
    # authorize token
    
    # setname
    data.users[u_id].fname = name_first
    data.users[u_id].lname = name_last

    return {}
