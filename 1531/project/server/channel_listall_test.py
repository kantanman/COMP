from channel_listall import channel_listall
import pytest
from myexcept import ValueError, AccessError
from ld_test_data import load_data

data = load_data()
token = 'test_user1'
token2 = 'test_user2'
channel_id = 1
channel_id2 = 2

def test_diff_member_all_channels ():

    assert(channel_listall (token2, data) == {'channels' : [{'channel_id': 1, 'name': get_chan_name(1)}, 
        {'channel_id': 2, 'name': get_chan_name(2)}, {'channel_id': 3, 'name': get_chan_name(3)}]})

def get_chan_name(channel_id):
    return data.channels[channel_id].name
