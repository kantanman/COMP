import pytest
from myexcept import ValueError, AccessError
from ld_test_data import load_data
from channel_join import channel_join

def test_succ():
	data = load_data()
	channel_join('test_user2', 2, data)
	assert 2 in data.channels[2].members
	assert 2 in data.users[2].channel_in	

def test_private():
	data = load_data()
	print(data.channels[3].is_public)
	with pytest.raises(Exception):
		channel_join('test_user2', 3, data)


def test_fake_channel():
	data = load_data()
	with pytest.raises(ValueError):
		channel_join('test_user2', 4, data)
