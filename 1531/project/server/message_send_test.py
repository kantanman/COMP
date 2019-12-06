from message_send import message_send
from auth_register import auth_register
from channels_create import channels_create
from ld_test_data import load_data
from myexcept import ValueError, AccessError
import pytest

data = load_data()
longStr = 'x' * 1001
test_uid = 1
user = data.users[test_uid]
test_token = None
for token, uid in data.token_dict.items():
    if uid == test_uid:
        test_token = token
test_channel_id = user.channel_in[0]

def test_message_send_returnVal():
    assert(message_send(test_token, test_channel_id, "g'day", data) == {'message_id': (data.message_id_ct - 1)})
    
def test_message_send_works():
    message_send(test_token, test_channel_id, "test1", data)
    for message in data.channels[test_channel_id].messages:
        if(message.message_id == data.message_id_ct):
            return
    print("Message ID not found, test unsucessful")
    
def test_message_send_long():
    with pytest.raises(ValueError):
        message_send(test_token, test_channel_id, longStr, data)
    
def test_message_send_faultytoken():
    faulty_token = 1111
    with pytest.raises(AccessError):
        message_send(faulty_token, test_channel_id, "test1", data)