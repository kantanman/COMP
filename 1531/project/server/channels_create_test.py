from channels_create import channels_create
import pytest
from ld_test_data import load_data
from myexcept import ValueError
def test_succ():
	data = load_data()
	channels_create('test_user1', 'TEST_CHANNEL_4', 'true', data)
	assert 4 in data.channels.keys()
	assert 4 in data.users[1].channel_in
	assert 1 in data.channels[4].owner
	assert 1 in data.channels[4].members

def test_long_name():
	data = load_data()
	with pytest.raises(ValueError):
		name = 'n' * 21
		channels_create('test_user1', name, 'true', data)	
