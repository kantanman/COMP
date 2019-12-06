from flask import Flask, request
import server_data
import jwt

global lsdata

APP = Flask(__name__)



@APP.route('/auth/logout', methods=['POST'])
def logout():
    token = request.form.get('token')
    #check if token is valid. If not, get_u_id returns access error
    if(not server_data.authToken(token)):
        raise AccessError

        


if __name__ == "__main__":
    APP.run()
