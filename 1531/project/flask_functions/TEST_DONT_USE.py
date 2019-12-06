from json import dumps
from flask import Flask, request
import hashlib
import jwt
import re

APP = Flask(__name__)
        
data = {
    'users': [],
}

SECRET = 'sempai'

def getData():
    global data
    return data

def sendSuccess(data):
    return dumps(data)

def sendError(message):
    return dumps({
        '_error' : message,
    })

def generateToken(username):
    global SECRET
    encoded = jwt.encode({'username': username}, SECRET, algorithm='HS256')
    print(encoded)
    return str(encoded)

def getUserFromToken(token):
    global SECRET  
    decoded = jwt.decode(token, SECRET, algorithms=['HS256']) 
    return decoded['username']

def hashedPassword(password):
    return hashlib.sha256(password.encode()).hexdigest()
'''
def validUsername(username):
    regex = '^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$'
    if(re.search(regex,username)): 
        return True
    else:
        return False
'''
@APP.route('/secrets', methods=['GET'])
def get():
    if getUserFromToken(request.args.get('token')) is None:
        return sendError('Invalid token')
    return sendSuccess({
        'secrets' : ['I', 'like', 'rats'],
    })

@APP.route('/register', methods=['POST'])
def create():
    data = getData()
    username = request.form.get('username')
    password = request.form.get('password')
    hashedpassword = hashedPassword(password)
    data['users'].append({
        'username': username,
        'password': hashedpassword,
    })
    print(data)
    return sendSuccess({
        'token': generateToken(username),
    })

@APP.route('/login', methods=['PUT'])
def connect():
    data = getData()
    username = request.form.get('username')
    password = request.form.get('password')
    hashedpassword = hashedPassword(password)
    print(data)

#    if bool(validUsername(username)) == False:
 #     sendError("username not a valid username")
  #    raise ValueError

    existingUsername = False
    validPassword = False

    for user in data['users']:
        if user['username'] == username:
            existingUsername = True
        if user['password'] == hashedPassword:
            validPassword = True
        if existingUsername == True and validPassword == True:
            return sendSuccess({
                'token': generateToken(Username)
            })

    #wrong email returns "email is incorrect"
    if existingUsername == False:
        sendError("Username is incorrect")
        raise ValueError

    #if email is correct but password if wrong,
    if existingUsername == True and validPassword == False:
        sendError("Password is incorrect")
        raise ValueError

if __name__ == '__main__':
    APP.run()
