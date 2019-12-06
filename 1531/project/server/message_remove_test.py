from message_remove import remove_message
from myexcept import ValueError, AccessError
import pytest
from ld_test_data import load_data

def test_succ():
	data = load_data()
	pre_len = len(data.channels[1].messages)
	remove_message('test_user1', 1, data)
	assert (data.msg_id_dict.get(1) == None)
	assert (len(data.channels[1].messages) == pre_len - 1)
