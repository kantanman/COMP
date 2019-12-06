from json import dumps
from flask import Flask, request
import server_data
from ld_data import load_data, dump_data
from myexcept import raise_err
from help_functions import is_permitted, is_real_message
from message_remove import remove_message
def edit_message(token, message_id, message, data):
    if not (server_data.authToken(token, data)):
       raise_err('AccessError', 'This is an invalid token')
    u_id = server_data.retrieveUid(token, data)
    message_id = int(message_id)

    if not is_real_message(message_id, data):
        raise_err('ValueError', 'This is not a real message_id')

    channel_id = data.msg_id_dict[message_id]

    if(str(message) == '' or str(message) == None):
        remove_message(token, message_id, data)
        return {}

    for msg in data.channels[channel_id].messages:
        if msg.message_id == message_id:
            if is_permitted(u_id, data) or (msg.sender == u_id) or (u_id in data.channels[channel_id].owner):
                msg.content = message
                break
            else :
                raise_err('AccessError', 'You are not permitted to do this')
    return {}
