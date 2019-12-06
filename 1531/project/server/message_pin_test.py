from message_unpin import unpin_message
from message_pin import pin_message
from message_send import message_send
from search import search_mes
from auth_register import auth_register
import pytest
from myexcept import ValueError, AccessError
from ld_test_data import load_data

data = load_data()

token = 'test_user1'
token2 = 'test_user2'
token3 = 'test_user3'
channel_id = 1
channel_id2 = 2
react_id = 1
message_id = 4

def test_pin_message_returnVal():
    message_send(token, channel_id, 'hello!!4', data)
    assert(pin_message(token, message_id, data) == {})

def test_pin_message():
    pin_message(token, 1, data) #pin first message
    print(data.channels[channel_id].messages[-1].content)
    assert(data.channels[channel_id].messages[-1].status == True)

def test_faulty_token():    
    fake_token = 1111
    with pytest.raises(AccessError):
        pin_message(fake_token, message_id, data)

def test_user_notin_channel():
    message_send(token, channel_id2, 'hello!!5', data)
    message_id = 5
    
    with pytest.raises(AccessError):
        pin_message(token3, message_id, data)

def test_pin_messagened():
    message_send(token, channel_id, 'hello!!6', data)
    message_id = 6
    pin_message(token, message_id, data)

    with pytest.raises(ValueError):
        pin_message(token, message_id, data)

def test_faulty_msg_id():
    fautly_msg_id = 000
    with pytest.raises(Exception):
        pin_message(token, fautly_msg_id, data)
        

