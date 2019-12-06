import time

from help_functions import is_real_channel_id
from ld_data import dump_data, load_data
from myexcept import raise_err
from server_data import authToken, Messages

def standup_active(token, channel_id, data):
    channel_id = int(channel_id)
    if not authToken(token, data):
        raise_err('AccessError', 'This is an invalid token')
    

    if not is_real_channel_id(channel_id, data):
        raise_err('ValueError', 'This is not a real channel_id')
    
    if data.channels[channel_id].status:
        if time.time() >= data.channels[channel_id].time_finish:
            data.channels[channel_id].status = False
            data.channels[channel_id].time_finish = None
            
            message_id = data.message_id_ct
            data.message_id_increment()
            data.msg_id_dict[message_id] = channel_id

            string = ''
            for msg in data.channels[channel_id].standups:
                string = string + msg + '\n'

            insert_message = Messages(string, data.channels[channel_id].starter, message_id, time.time())
            data.channels[channel_id].messages.insert(0,insert_message)
            data.channels[channel_id].starter = None
            data.channels[channel_id].standups = []
        else:
            pass

    return {
        'is_active' : data.channels[channel_id].status,
        'time_finish' : data.channels[channel_id].time_finish
    }