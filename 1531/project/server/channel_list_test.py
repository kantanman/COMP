from channel_list import channel_list
from channels_create import channels_create
from channel_invite import channel_invite
import server_data
import pytest
from myexcept import ValueError, AccessError
from ld_test_data import load_data

data = load_data()
token = 'test_user1'
token2 = 'test_user2'
channel_id = 1
channel_id2 = 2
channel_id3 = 3

u_id2 = server_data.retrieveUid(token2, data)

def test_diff_member_channel():

    # testing  differeent users get different channels 
    assert(channel_list(token2, data) == {'channels' : [{'channel_id': 1, 'name': get_chan_name(1)}]})
    channel_invite(token, channel_id3, u_id2, data)
    assert(channel_list(token2, data) == {'channels' : [{'channel_id': 1, 'name': get_chan_name(1)}, {'channel_id': 3, 'name': get_chan_name(3)}]})


def get_chan_name(channel_id):
    return data.channels[channel_id].name

