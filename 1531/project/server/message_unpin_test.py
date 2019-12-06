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

def test_message_unpin():
    message_send(token, channel_id, 'hello!!', data)
    pin_message(token, message_id, data)
    #assume message_id is generated
    assert(unpin_message(token, message_id, data)) == {}

def test_faulty_token():
    pin_message(token, message_id, data)
    unpin_message(token, message_id, data)
    
    fake_token = 1111
    with pytest.raises(AccessError):
        unpin_message(fake_token, message_id, data)

'''
def test_user_notadmin():
    #message_send(token, channel_id, 'hello!!', data)
    pin_message(token, message_id, data)
    
    with pytest.raises(ValueError):
        unpin_message(token2, message_id, data)
'''
def test_user_notin_channel():
   #message_send(token, channel_id, 'hello!!', data)
    message_send(token, 2, 'hello', data)
    message_id = 5
    pin_message(token, message_id, data)
    with pytest.raises(AccessError):
        unpin_message(token3, message_id, data)


def test_message_notpinned():
    message_send(token, channel_id, 'hello!!6', data)
    message_id = 6
    with pytest.raises(ValueError):
        unpin_message(token, message_id, data)

def test_nomessage():
    #no messages sent
    with pytest.raises(ValueError):
        unpin_message(token, message_id, data)

def test_faulty_msg_id():
    message_send(token, channel_id, 'hello!!', data)
    fautly_msg_id = 000
    
    with pytest.raises(ValueError):
        unpin_message(token, fautly_msg_id, data)
