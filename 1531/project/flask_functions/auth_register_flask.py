from json import dumps
from flask import Flask, request
import hashlib
import jwt
import re 
import server_data

APP = Flask(__name__)

SECRET = 'lambshank'

data = {
    'users': [],
}

def getData():
    global data
    return data

def sendSuccess(data):
    return dumps(data)

def sendError(message):
    return dumps({
        '_error' : message,
    })

def validEmail(email):
    regex = '^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$'
    if(re.search(regex,email)): 
        return True
    else:
        return False


