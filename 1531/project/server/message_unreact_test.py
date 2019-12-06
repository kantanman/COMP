from message_unreact import unreact_message
from message_react import react_message
from message_pin import pin_message
from message_send import message_send
from search import search_mes
import pytest
from myexcept import ValueError, AccessError
from ld_test_data import load_data
    
    
data = load_data()

token = 'test_user1'
token2 = 'test_user2'
channel_id = 1
channel_id2 = 2
react_id = 1
message_id = 4


def test_message_unreact():
    message_send(token, channel_id, 'hello!!4', data)
    #react_message(token, message_id, react_id, data)
    assert(react_message(token, message_id, react_id, data) == {})
    unreact_message(token, message_id, react_id, data)
    assert(data.channels[channel_id].messages[-1].reaction == {1: {'is_this_user_reacted': False, 'u_ids': [1]}})


def test_faulty_token():
    message_send(token, channel_id, 'hello!!5', data)
    message_id = 5
    react_message(token, message_id, react_id, data)
    
    fake_token = 1111
    with pytest.raises(AccessError):
        unreact_message(fake_token, message_id, react_id, data)

def test_not_users_react():
    message_send(token, channel_id, 'hello!!6', data)
    message_id = 6
    react_message(token, message_id, react_id, data)

    with pytest.raises(Exception):
        unreact_message(token2, message_id, react_id, data)

def test_user_notin_channel():
    #message_send(token, channel_id, 'hello!!', data)
    react_message(token, message_id, react_id, data)
    
    with pytest.raises(Exception):
        unreact_message(token2, message_id, react_id, data)

def test_faulty_reactid():
    message_send(token, channel_id, 'hello!!7', data)
    message_id = 7
    react_message(token, message_id, react_id, data)
    
    fake_react_id = 1111
    with pytest.raises(ValueError):
        unreact_message(token, message_id, fake_react_id, data)


def test_noexisting_react():
    unreact_message(token, message_id, react_id, data)
    with pytest.raises(Exception):
        unreact_message(token, message_id, react_id, data)


def test_faulty_msg_id():
    fake_message_id = -1
    fautly_msg_id = 000
    
    with pytest.raises(Exception):
        unreact_message(token, fautly_msg_id, react_id, data)


