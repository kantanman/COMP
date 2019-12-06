#message send flask function

from json import dumps
from flask import Flask, request
import server_data
import myexcept
from ld_data import load_data, dump_data

@APP.route('/message/send', methods=['POST'])
def send_message():
    lsdata = load_data()

    token = request.form.get('token')
    channel_id = request.form.get('channel_id')
    message = request.form.get('message')

    if len(message) > 1000:
        err = ValueError()
        myexcept.defaultHandler(err)

    u_id = server_data.retrieveUid(token, lsdata)    
    
    if channel_id not in lsdata.users[u_id].channel_in:
        err = ValueError()
        myexcept.defaultHandler(err)
    
    #give message id
    message_id = lsdata.message_id_ct
    #increment message_id
    lsdata.message_id_increment()

    insert_message = Messages(message, u_id, message_id)

    #inserting message and message_id into list of messages in class channels
    lsdata.channels[channel_id].messages.insert(0,insert_message)

    dump_data(lsdata)
    return dumps({'message_id': message_id})

