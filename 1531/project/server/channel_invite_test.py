from ld_test_data import load_data
from myexcept import ValueError, AccessError
import pytest
from channel_invite import channel_invite

def test_succ():
	data = load_data()
	channel_invite('test_user1', 2, 2, data)
	assert 2 in data.users[2].channel_in
	assert 2 in data.channels[2].members

def test_fake_channel():
	data = load_data()
	with pytest.raises(ValueError):
		channel_invite('test_user1', 4, 2, data)

def test_fake_user():
	data = load_data()
	with pytest.raises(ValueError):
		channel_invite('test_user1', 2, 4, data)

def test_not_in():
	data = load_data()
	with pytest.raises(AccessError):
		channel_invite('test_user2', 3, 3, data)
