from flask import Flask
from flask_mail import Mail, Message
from json import dumps
import string
import random
from myexcept import raise_err
from ld_data import load_data, dump_data


APP = Flask(__name__)
APP.config.update(
    MAIL_SERVER='smtp.gmail.com',
    MAIL_PORT=465,
    MAIL_USE_SSL=True,
    MAIL_USERNAME = 'theslackrteam@gmail.com',
    MAIL_PASSWORD = "lambshank1"
)

#generates code
def generate_code(length=6):
    lettersAndDigits = string.ascii_letters + string.digits
    code = ''.join(random.choice(lettersAndDigits) for i in range(length))
    return code

#get the name of the owner of an email address
def get_name(email, data):
    for user in data.users.keys():
        if data.users[user].email == email:
            return data.users[user].fname
    return False

#get the u_id of the owner of an email address
def get_u_id(email, data):
    for user in data.users:
        if data.users[user].email == email:
            return data.users[user].u_id
    return False


def send_mail(email, data):

    mail = Mail(APP)

    u_id = get_u_id(email, data)
    name = get_name(email, data)
    code = generate_code()

    if name == False:
        return dumps({
        '_error' : "email not found",
    })      

    #since user is valid, add reset code to list of valid reset codes
    data.reset_code[u_id] = code

    msg = Message("Password reset request mail",
        sender="theslackrteam@gmail.com",       #LambshankRedeption1531@gmail.com
        recipients=[email])
    msg.body = "Hello " + str(name) + ",\n\nYour password reset code is " + str(code) + '\n\nThe Slackr Team'
    mail.send(msg)
    return {}

    #add in error catcher 
    '''

    try:
        msg = Message("Password reset request mail",
            sender="theslackrteam@gmail.com",       #LambshankRedeption1531@gmail.com
            recipients=[email])
        msg.body = "Hello" + str(name) + "this is your password reset code" + str(code)
        mail.send(msg)
        return {}
    except:
        raise_err('ValueError', 'This is an invalid token')
   '''
