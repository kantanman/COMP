from message_react import react_message
from message_unreact import unreact_message
from message_pin import pin_message
from message_send import message_send
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

def test_react_message():
    message_send(token, channel_id, 'hello!!', data)
    assert(react_message(token, message_id, react_id, data) == {})
    unreact_message(token, message_id, react_id, data)

def test_re_react():
    react_message(token, message_id, react_id, data)
    unreact_message(token, message_id, react_id, data)

    assert(react_message(token, message_id, react_id, data) == {})

def test_faulty_token(): 
    fake_token = 1111
    with pytest.raises(AccessError):
        react_message(fake_token, message_id, react_id, data)

def test_user_notin_channel():
    message_send(token, channel_id2, 'hello!!5', data)
    message_id = 5

    with pytest.raises(ValueError):
        react_message(token3, message_id, react_id, data)

def test_faulty_reactid():
    message_send(token, channel_id, 'hello!!', data)
    
    fake_react_id = 1111
    with pytest.raises(ValueError):
        react_message(token, message_id, fake_react_id, data)

def test_existing_react():
    message_send(token, channel_id, 'hello!!7', data)
    message_id = 7
    react_message(token, message_id, react_id, data)
    with pytest.raises(ValueError):
        react_message(token, message_id, react_id, data)

def test_faulty_msg_id():
    fautly_msg_id = 000
    
    with pytest.raises(Exception):
        react_message(token, fautly_msg_id, react_id, data)