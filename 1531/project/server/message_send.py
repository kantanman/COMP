import time
from json import dumps

from flask import Flask, request

import server_data
from help_functions import is_legal_length, is_user_in_channel
from ld_data import dump_data, load_data
from myexcept import raise_err


def message_send(token, channel_id, message, data):
    channel_id = int(channel_id)

    if not server_data.authToken(token, data):
        raise_err('AccessError', 'This is an invalid token')
    if not is_legal_length(1000, message):
        raise_err('ValueError', 'Ths message is too long')

    u_id = server_data.retrieveUid(token, data)    
    
    if not is_user_in_channel(u_id, channel_id, data):
        raise_err('ValueError', 'You are not in this channel')
    
    #give message id
    message_id = data.message_id_ct
    #increment message_id
    data.message_id_increment()
    # add message data to id dict
    data.msg_id_dict[message_id] = channel_id

    insert_message = server_data.Messages(message, u_id, message_id, time.time())

    #inserting message and message_id into list of messages in class channels
    data.channels[channel_id].messages.insert(0,insert_message)

    return {'message_id': message_id}
