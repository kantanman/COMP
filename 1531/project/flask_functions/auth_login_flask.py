''' AUTH LOGIN FUNCTION. MERGE INTO SERVER.PY WHEN FINISHED'''
from json import dumps
from flask import Flask, request
import hashlib 
import jwt
import re
import server_data
import datetime

APP = Flask(__name__)

SECRET = 'lambshank'

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

#using a jwt for a token so it can be used to verify user 
def generateToken(email):
    global SECRET
    encoded = jwt.encode({'email': email + datetime.now()}, SECRET, algorithm='HS256') 
    return str(encoded)

#Hashing password using sha256 algorithm
def hashedPassword(password):
    return hashlib.sha256(password.encode()).hexdigest()


#post request for login
@APP.route('/auth/login', methods=['POST'])
def login():
    lsdata = load_data()    

    email = request.form.get('email')
    password = request.form.get('password')
    hashedPassword = hashedPassword(password)

    existingEmail = False
    existingPassword = False
 
    for user in lsdata['users']:
        if user['email'] == email:
            existingEmail = True
        if user['password'] == hashedPassword:
            validPassword = True

                'token': generateToken(email, u_id)
            

    #wrong email returns "email is incorrect" 
    if existingEmail == False:
        raise ValueError
        sendError("Email is incorrect")

    #if email is correct but password if wrong, 
    if existingEmail == True and validPassword == False:
        raise ValueError
        sendError("Password is incorrect")
    
    if bool(validEmail(email)) == False:
        raise ValueError
        sendError("Email not a valid email")       


