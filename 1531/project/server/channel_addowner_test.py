from ld_test_data import load_data
from myexcept import AccessError, ValueError
from channel_addowner import channel_addowner
import pytest

def test_add_1():
	data = load_data()
	rt_data = channel_addowner('test_user1', 1, 2, data)
	assert rt_data == {}
	assert 2 in data.channels[1].owner
	
	
def test_fail():	
	data = load_data()
	with pytest.raises (ValueError):
		channel_addowner('test_user1', 4, 2, data)	

def test_already_owner():
	data = load_data()
	with pytest.raises (ValueError):
		channel_addowner('test_user1', 1, 3, data)
