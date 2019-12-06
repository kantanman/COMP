from channel_leave import channel_leave
import pytest
from ld_test_data import load_data


def test_succ():
	data = load_data()
	channel_leave('test_user3', 1, data)
	assert 3 not in data.channels[1].members
	assert 1 not in data.users[3].channel_in

def test_owner_leave():
	data = load_data()
	channel_leave('test_user1', 1, data)
	assert 1 not in data.channels[1].members
	assert 1 not in data.channels[1].owner

