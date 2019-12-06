from standup_send import standup_send 
from standup_start import standup_start
from standup_active import standup_active
import pytest 
import time 
from ld_test_data import load_data
from myexcept import ValueError, AccessError

data = load_data()

token1 = 'test_user1'
token2 = 'test_user2'
channel_id = 1
channel_id2 = 2
length = 1
fake_channel = -3
message = 'hello!'

def test_channel_doesnot_exist ():
	with pytest.raises (ValueError):
		standup_send (token1, fake_channel, message, data)

def test_message_too_long ():
    long_message = 'x' * 10000
    with pytest.raises (ValueError):
    	standup_send (token1, channel_id, long_message, data)    

def test_user_not_in_channel ():
    with pytest.raises (AccessError):
    	standup_send (token2, channel_id2, message, data)

def test_time_stop ():
    standup_start (token1, channel_id, 2, data)
    time.sleep (3)
    standup_active (token1, channel_id, data)
    print (data.channels[channel_id].status)

    with pytest.raises (AccessError):
    	standup_send (token1, channel_id, message, data)

def test_pass ():
    standup_start (token1, channel_id, 3, data)
    standup_send (token1, channel_id, message, data)
