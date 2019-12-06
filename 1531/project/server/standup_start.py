import time

from server_data import authToken, retrieveUid
from help_functions import is_real_channel_id, is_user_in_channel
from ld_data import dump_data, load_data
from myexcept import raise_err


def standup_start(token, channel_id, length, data):
    channel_id = int(channel_id)


    if not authToken(token, data):
        raise_err('AccessError', 'This is an invalid token')

    if not is_real_channel_id(channel_id, data):
        raise_err('ValueError', 'This is an invalid channel_id')

    u_id = retrieveUid(token, data)
    
    if not is_user_in_channel(u_id, channel_id, data):
        raise_err('AccessError', 'user is not in this channel')

    if data.channels[channel_id].status:
        raise_err('ValueError', 'There is a standup currently active in this channel')
    data.channels[channel_id].status = True


    finish_time = time.time() + float(length)
    data.channels[channel_id].time_finish = finish_time
    data.channels[channel_id].starter = u_id
    
    return {
        'time_finish' : finish_time
    }
