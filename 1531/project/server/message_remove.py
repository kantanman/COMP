from json import dumps
from flask import Flask, request
import server_data
from ld_data import load_data, dump_data
from myexcept import raise_err
from help_functions import is_permitted, is_real_message
def remove_message(token, message_id, data):
    message_id = int(message_id)

    #request data from user
    #get u_id from the token
    if not (server_data.authToken(token, data)):
        raise_err('AccessError', 'This is an invalid token')

    u_id = server_data.retrieveUid(token, data) 

    if not is_real_message(message_id, data):
        raise_err('ValueError', 'This is not a real message_id')

    channel_id = data.msg_id_dict[message_id]

    for message in data.channels[channel_id].messages:
        if message.message_id == message_id:
            if is_permitted(u_id, data) or (message.sender == u_id) or u_id in data.channels[channel_id].owner:
                data.msg_id_dict.pop(message_id)
                data.channels[channel_id].messages.remove(message)
                break
            else :
                raise_err('AccessError', 'You are not allowed to delete this message')

                
    
    return{}