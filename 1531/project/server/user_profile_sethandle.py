from flask import Flask, request
import server_data
from json import dumps
from auth_register import valid_email_test
from ld_data import load_data, dump_data
from myexcept import raise_err

def set_handle(token, handle_str, data):
    if not server_data.authToken(token, data):
        raise_err('AccessError', 'This is an invalid token')
    u_id = server_data.retrieveUid(token, data)
    # check for valid length
    if(len(handle_str) <= 3 or len(handle_str) >= 20):
        raise_err('ValueError', 'Length is incorrect')
    # check if it isn't another users handle
    for user in data.users.keys():
        if(handle_str == data.users[user].handle):
            raise_err('ValueError', 'This handle has been taken')

    data.users[u_id].handle = handle_str
    return {}
    
