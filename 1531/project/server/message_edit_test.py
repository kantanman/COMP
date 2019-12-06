from message_edit import edit_message
from message_send import message_send
from myexcept import ValueError, AccessError
from ld_test_data import load_data
import pytest

data = load_data()
test_uid = 1
user = data.users[test_uid]
test_token = None
for token, uid in data.token_dict.items():
    if uid == test_uid:
        test_token = token
test_channel_id = user.channel_in[0]

def test_message_edit_returnval():
    message_send(test_token, test_channel_id, "test 1", data)
    assert(edit_message(test_token, (data.message_id_ct - 1), 'test 1 edit', data) == {})

def test_message_edit_working():
    edit_message(test_token, (data.message_id_ct - 1), 'change', data)
    for message, messageId in data.msg_id_dict.items():
        if messageId == (data.message_id_ct - 1):
            assert(message.content == 'change')

def test_faulty_token():
    faulty_token = 1234
    with pytest.raises(AccessError):
        edit_message(faulty_token, 1, 'hello', data)
