import jwt
import datetime

class Users:
    def __init__(self, first_name, last_name, email, password):
    self.first_name = first_name
    self.last_name = last_name
    self.email = email
    self.password = password
    self.handle = '@' + first_name + last_name
    self.u_id = None
    self.channel_in = []
    self.permission_id = 3
    


def generateToken(email)
    secret = 'lambshank'
    string = email + datetime.now
    token = jwt.encode({'email': string}, secret, algorithm='HS256')
    return token

    

