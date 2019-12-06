from json import dumps
from flask import Flask, request
import server_data
from ld_data import load_data, dump_data
from myexcept import raise_err
from help_functions import is_user_in_channel, is_real_message

def unreact_message(token, message_id, react_id, data):
    react_id = int(react_id)
    message_id = int(message_id)
    if not (server_data.authToken(token, data)):
        raise_err('AccessError', 'This is an invalid token')

    u_id = server_data.retrieveUid(token, data)

    #  check if valid ID
    if react_id is not 1:
       raise_err('ValueError', 'This is an invalid react_id')

    if not is_real_message(message_id, data):
        raise_err('ValueError', 'This is not a real message_id')

    channel_id = data.msg_id_dict[message_id]

    if not is_user_in_channel(u_id, channel_id, data):
        raise_err('AccessError', 'You are not a member of this channel')
    
    for message in data.channels[channel_id].messages:
        if message.message_id == message_id:
            if message.reaction.get(react_id) == None:
                raise_err('ValueError', 'No one reacts on the message yet')
            message.reaction[react_id]['u_ids'].remove(u_id)
            if u_id is message.sender:
                message.reaction[react_id]['is_this_user_reacted'] = False
            if message.reaction[react_id]['u_ids'] is []:
                message.pop(react_id)

    return {}
