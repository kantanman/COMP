from flask import Flask
from flask_mail import Mail, Message
from json import dumps
import string
import random
from ld_data import dump_data, load_data
#generates code
def generate_code(length=6):
    lettersAndDigits = string.ascii_letters + string.digits
    code = ''.join(random.choice(lettersAndDigits) for i in range(length))
    return code

#get the name of the owner of an email address
def get_name(email):
    lsdata = load_data()
    for user in lsdata.user.keys():
        if lsdata.users[user].email == email:
            return lsdata.users[user].name
        else:
            return False

#get the u_id of the owner of an email address
def get_u_id(email):
    lsdata = load_data
    for user in lsdata.user.keys():
        if lsdata.users[user].email == email:
            return lsdata.users[user].u_id
        else:
            return False

#setup for sending automated mail
APP = Flask(__name__)
APP.config.update(
    MAIL_SERVER='smtp.gmail.com',
    MAIL_PORT=465,
    MAIL_USE_SSL=True,
    MAIL_USERNAME = 'LambshankRedeption1531@gmail.com',
    MAIL_PASSWORD = "unsw1234"
)

@APP.route('auth/passwordreset/request', methods=['POST'])
def send_mail(email):

    lsdata = load_data()
    mail = Mail(APP)

    email = request.form.get('email')
    u_id = get_u_id(email)
    name = get_name(email)
    code = generate_code()

    if name == False:
        return dumps({
        '_error' : "email not found",
    })      

    #since user is valid, add reset code to list of valid reset codes
    lsdata.reset_code[u_id] = code
    dump_data(lsdata) 

    try:
        msg = Message("Password reset request mail",
            sender="LambshankRedeption1531@gmail.com",
            recipients=[email])
        msg.body = "Hello" + str(name) + "this is your password reset code" + str(code)
        mail.send(msg)
        return 'Mail sent!'
    except Exception as e:
        return (str(e))

if __name__ == '__main__':
    APP.run()

