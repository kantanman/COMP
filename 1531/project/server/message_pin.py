from json import dumps

from flask import Flask, request

from myexcept import raise_err
import server_data
from ld_data import dump_data, load_data
from help_functions import is_real_message, is_user_in_channel

def pin_message(token, message_id, data):
    if not (server_data.authToken(token, data)):
        raise_err('AccessError', 'This a invalid token')
    u_id = server_data.retrieveUid(token, data)
    message_id = int(message_id)
   
    if not is_real_message(message_id, data):
        raise_err('ValueError', 'This is not a valid message_id')
    
    channel_id = data.msg_id_dict[message_id]

    if not is_user_in_channel(u_id, channel_id, data):
        raise_err('AccessError', 'You are not in this channel')

    
    for message in data.channels[channel_id].messages:
        if message.message_id == message_id:
            print(message.status)
            if message.status:
                raise_err('ValueError', 'The message is pinned')
            message.status = True
    return {}
