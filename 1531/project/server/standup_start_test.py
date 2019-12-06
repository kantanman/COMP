from standup_start import standup_start
from standup_active import standup_active
import time
import pytest
from ld_test_data import load_data
from myexcept import ValueError, AccessError

data = load_data()

token = 'test_user1'
token2 = 'test_user2'
channel_id = 1
channel_id2 = 2
length = 1

def test_standup_success():
    finish_time = time.time() + float(length)
    standup_start(token, channel_id, length, data)
    assert(data.channels[channel_id].status == True)
    standup_active(token, channel_id, data)
time.sleep(2)


def test_faulty_token():
    faulty_token = 1234
    with pytest.raises (AccessError):
        standup_start(faulty_token, channel_id, length, data)
        standup_active(token, channel_id, data)

def test_notin_channel():
    with pytest.raises (Exception):   
        standup_start(token2, channel_id2, length, data)

def test_faulty_channel():
    channel_fake_name = 'Fake Name'
    with pytest.raises (ValueError):
        standup_start(token, channel_id, length, data)
