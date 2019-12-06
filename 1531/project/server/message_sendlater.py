import time
from myexcept import raise_err
from server_data import authToken, retrieveUid, Messages
from help_functions import is_real_channel_id, is_legal_length, is_user_in_channel
from ld_data import load_data, dump_data
def message_sendlater(token, channel_id, message, time_sent, data):
    if not authToken(token, data):
        raise_err('AccessError', 'This is an invalid token')
    
    u_id = retrieveUid(token, data)
    channel_id = int(channel_id)
    time_sent = float(time_sent)
    if not is_real_channel_id(channel_id, data):
        raise_err('ValueError', 'This is not a real channel_id')
    
    if not is_legal_length(1000, message):
        raise_err('ValueError', 'Ths message is too long')
    
    if time_sent < time.time():
        raise_err('ValueError', 'You can not send this message at a post time')

    if not is_user_in_channel(u_id, channel_id, data):
        raise_err('AccessError', 'You can not post a message in a channel which you are not in')
    
    message_id = data.message_id_ct
    data.message_id_increment()
    insert_message = Messages(message, u_id, message_id, time_sent)
    data.channels[channel_id].messages.insert(0, insert_message)


    return {
        'message_id' : message_id
    }