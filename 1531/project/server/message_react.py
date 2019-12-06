from json import dumps
from flask import Flask, request
import server_data
from ld_data import load_data, dump_data
from myexcept import raise_err
from help_functions import is_user_in_channel

def react_message(token, message_id, react_id, data):
    if not (server_data.authToken(token, data)):
        raise_err('AccessError', 'This is an invalid token')

    u_id = server_data.retrieveUid(token, data)
    react_id = int(react_id)

    message_id = int(message_id)
    react_id = int(react_id)
    #  check if valid react ID

    if react_id != 1:
        raise_err('ValueError', 'This is not a valid react_id')
    
    channel_id = data.msg_id_dict[message_id]

    if not is_user_in_channel(u_id, channel_id, data):
        raise_err('ValueError', 'You are not a member of this channel')
    
    message = [m for m in data.channels[channel_id].messages if m.message_id == message_id][0]
    if message.reaction.get(react_id) == None:
        message.reaction[react_id] = {
            'u_ids' : [u_id],
            'is_this_user_reacted' : False
        }
    else :
        if u_id in message.reaction[react_id]['u_ids']:
            raise_err('ValueError', 'You already react on this message')
        message.reaction[react_id]['u_ids'].append(u_id)
    
    
    return {} 
