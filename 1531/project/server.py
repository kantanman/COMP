"""Flask server"""
import sys
import signal
from json import dumps

from flask import Flask, request, send_from_directory
from flask_cors import CORS

sys.path.insert(1,'server/')

import server_data
from admin_userpermission_change import admin_userpermission_change
from auth_login import auth_login
from auth_logout import auth_logout
from auth_passwordreset_request import send_mail
from auth_passwordreset_reset import auth_passwordreset_reset
from auth_register import auth_register
from channel_addowner import channel_addowner
from channel_details import channel_details
from channel_invite import channel_invite
from channel_join import channel_join
from channel_leave import channel_leave
from channel_list import channel_list
from channel_listall import channel_listall
from channel_messages import channel_messages
from channel_removeowner import channel_removeowner
from channels_create import channels_create
from ld_data import dump_data, load_data
from message_edit import edit_message
from message_pin import pin_message
from message_react import react_message
from message_remove import remove_message
from message_send import message_send
from message_sendlater import message_sendlater
from message_unpin import unpin_message
from message_unreact import unreact_message
from search import search_mes
from standup_active import standup_active
from standup_send import standup_send
from standup_start import standup_start
from user_profile import user_profile
from user_profile_setemail import set_email
from user_profile_sethandle import set_handle
from user_profile_setname import set_name
from user_profiles_uploadphoto import user_uploadphoto
from users_all import users_all





APP = Flask(__name__, static_url_path='/images/')
CORS(APP)

APP.config.update(
    MAIL_SERVER='smtp.gmail.com',
    MAIL_PORT=465,
    MAIL_USE_SSL=True,
    MAIL_USERNAME = 'LambshankRedeption1531@gmail.com',
    MAIL_PASSWORD = "unsw1234"
)


def signal_handler(sig, frame):
        dump_data(data)
        sys.exit(0)

@APP.route('/auth/register', methods = ['POST'])
def register_auth():
    global data
    name_first = request.form.get('name_first')
    name_last = request.form.get('name_last')
    email = request.form.get('email')
    password = request.form.get('password')
    return_data = auth_register(email, password, name_first, name_last, data)
    return dumps(return_data)

@APP.route('/auth/login', methods = ['POST'])
def login_auth():
    global data
    email = request.form.get('email')
    password = request.form.get('password')
    return_data = auth_login(email, password, data)
    return dumps(return_data)
@APP.route('/auth/logout', methods = ['POST'])
def logout_auth():
    global data
    token = request.form.get('token')
    return_data = auth_logout(token, data)
    return dumps(return_data)
@APP.route('/channels/create', methods = ['POST'])
def create_channel():
    global data
    token = request.form.get('token')
    name = request.form.get('name')
    is_public = request.form.get('is_public')
    return_data = channels_create(token, name, is_public, data)
    return dumps(return_data)

@APP.route('/channel/addowner', methods = ['POST'])
def addowner_channel():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    u_id = request.form.get('u_id')
    return_data = channel_addowner(token, channel_id, u_id, data)
    return dumps(return_data)
@APP.route('/channel/details', methods = ['GET'])
def details_channel():
    global data
    token = request.args.get('token')
    channel_id = request.args.get('channel_id')
    return_data = channel_details(token, channel_id, data)
    return dumps(return_data)
@APP.route('/channel/invite', methods = ['POST'])
def invite_channel():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    u_id = request.form.get('u_id')
    return_data = channel_invite(token, channel_id, u_id, data)
    return dumps(return_data)
@APP.route('/channel/join', methods = ['POST'])
def join_channel():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    return_data = channel_join(token, channel_id, data)
    return dumps(return_data)
@APP.route('/channel/leave', methods = ['POST'])
def leave_channel():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    return_data = channel_leave(token, channel_id, data)
    return dumps(return_data)
@APP.route('/channels/list', methods = ['GET'])
def list_channel():
    global data
    token = request.args.get('token')
    return_data = channel_list(token, data)
    return dumps(return_data)
@APP.route('/channels/listall', methods = ['GET'])
def listall_channel():
    global data
    token = request.args.get('token')
    return_data = channel_listall(token, data)
    return dumps(return_data)
@APP.route('/channel/messages', methods = ['GET'])
def messages_channel():
    global data
    token = request.args.get('token')
    channel_id = request.args.get('channel_id')
    start = request.args.get('start')
    return_data = channel_messages(token, channel_id, start, data)
    print(return_data['messages'])
    return dumps(return_data)
@APP.route('/standup/start', methods = ['POST'])
def start_standup():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    length = request.form.get('length')
    return_data = standup_start(token, channel_id, length, data)
    return dumps(return_data)
@APP.route('/channel/removeowner', methods = ['POST'])
def owner_remove():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    u_id = request.form.get('u_id')
    return_data = channel_removeowner(token, channel_id, u_id, data)
    return dumps(return_data)
@APP.route('/message/edit', methods=['PUT'])
def editmessage():
    global data
    token = request.form.get('token')
    message_id = request.form.get('message_id')
    message = request.form.get('message')
    return_data = edit_message(token, message_id, message, data)
    return dumps(return_data)
    
@APP.route('/message/pin', methods=['POST'])
def pinmessage():
    global data
    token = request.form.get('token')
    message_id = request.form.get('message_id')
    return_data = pin_message(token, message_id, data)
    return dumps(return_data)

@APP.route('/message/send', methods=['POST'])
def send_message():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    message = request.form.get('message')
    return_data = message_send(token, channel_id, message, data)
    return dumps(return_data)

@APP.route('/message/react', methods=['POST'])
def message_react():
    global data
    token = request.form.get('token')
    message_id = request.form.get('message_id')
    react_id = request.form.get('react_id')
    return_data = react_message(token, message_id, react_id, data)
    return dumps(return_data)
@APP.route('/message/remove', methods=['DELETE'])
def messageremove():
    global data
    token = request.form.get('token')
    message_id = request.form.get('message_id')
    return_data = remove_message(token, message_id, data)
    return dumps(return_data)

@APP.route('/user/profile', methods=['GET'])
def userprofile():
    global data
    token = request.args.get('token')
    u_id = request.args.get('u_id')
    return_data = user_profile(token, u_id, data)
    return dumps(return_data)
@APP.route('/user/profile/setemail', methods=['PUT'])
def setemail():
    global data
    token = str(request.form.get('token'))
    new_email = str(request.form.get('email'))
    return_data = set_email(token, new_email, data)
    return dumps(return_data)
@APP.route('/user/profile/setname', methods=['PUT'])
def setname():
    global data
    token = str(request.form.get('token'))
    new_fname = str(request.form.get('name_first'))
    new_lname = str(request.form.get('name_last'))
    return_data = set_name(token, new_fname, new_lname, data)
    return dumps(return_data)
@APP.route('/user/profile/sethandle', methods=['PUT'])
def sethandle():
    global data
    token = str(request.form.get('token'))
    handle_str = str(request.form.get('handle_str'))
    return_data = set_handle(token, handle_str, data)
    return dumps(return_data)
@APP.route('/message/unpin', methods=['POST'])
def unpinmessage():
    global data
    token = request.form.get('token')
    message_id = request.form.get('message_id')
    return_data = unpin_message(token, message_id, data)
    return dumps(return_data)
@APP.route('/message/unreact', methods=['POST'])    
def unreactmessage():
    global data
    token = request.form.get('token')
    message_id = request.form.get('message_id')
    react_id = request.form.get('react_id')
    return_data = unreact_message(token, message_id, react_id, data)
    return dumps(return_data)
@APP.route('/admin/userpermission/change', methods = ['POST'])
def ad_p_c():
    global data
    token = request.form.get('token')
    u_id = request.form.get('u_id')
    permission_id = request.form.get('permission_id')
    return_data = admin_userpermission_change(token, u_id, permission_id, data)
    return dumps(return_data)
@APP.route('/auth/passwordreset/reset', methods = ['POST'])
def auth_pw_reset():
    global data
    reset_code = request.form.get('reset_code')
    new_password = request.form.get('new_password')
    return_data = auth_passwordreset_reset(reset_code, new_password, data)
    return dumps(return_data)
@APP.route('/users/all', methods = ['GET'])
def all_users():
    global data
    token = request.args.get('token')
    return_data = users_all(token, data)
    return dumps(return_data)
@APP.route('/standup/active', methods = ['GET'])
def standupActive():
    global data
    token = request.args.get('token')
    channel_id = request.args.get('channel_id')
    return_data = standup_active(token, channel_id, data)
    return dumps(return_data)
@APP.route('/standup/send', methods = ['POST'])
def standupSend():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    message = request.form.get('message')
    return_data = standup_send(token, channel_id, message, data)
    return dumps(return_data)


@APP.route('/auth/passwordreset/request', methods=['POST'])
def mail_send():
    global data
    email = request.form.get('email')
    return_data = send_mail(email, data)
    return dumps(return_data)
    
@APP.route('/search', methods=['GET'])
def search_():
    global data
    token = request.args.get('token')
    query_str = request.args.get('query_str')
    return_data = search_mes(token, query_str, data)
    return dumps(return_data)

@APP.route('/message/sendlater', methods=['POST'])
def sendlater_message():
    global data
    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    message = request.form.get('message')
    time_sent = request.form.get('time_sent')
    return_data = message_sendlater(token, channel_id, message, time_sent, data)
    return dumps(return_data)
@APP.route('/user/profiles/uploadphoto', methods = ['POST'])
def upload_photo():
    global data
    token = request.form.get('token')
    img_url = request.form.get('img_url')
    x_start = request.form.get('x_start')
    x_end = request.form.get('x_end')
    y_start = request.form.get('y_start')
    y_end = request.form.get('y_end')
    return_data = user_uploadphoto(token, img_url, x_start, y_start, x_end, y_end, data, request.host)
    return dumps(return_data)
    
@APP.route('/<path:path>')
def send_js(path):
    return send_from_directory('', path)

if __name__ == '__main__':
    data = load_data()
    
    signal.signal(signal.SIGINT, signal_handler)

    APP.run(port=(sys.argv[1] if len(sys.argv) > 1 else 5000))

