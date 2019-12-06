from channel_removeowner import channel_removeowner
import pytest
from ld_test_data import load_data
from myexcept import ValueError, AccessError
def test_succ():
    data = load_data()
    channel_removeowner('test_user1', 1, 3, data)
    assert 3 not in data.channels[1].owner

def test_not_owner():
    data = load_data()
    with pytest.raises(ValueError):
        channel_removeowner('test_user1', 1, 2, data)

def test_accessError():
    data = load_data()
    with pytest.raises(AccessError):
        channel_removeowner('test_user2', 1, 1, data)