from user_profile_sethandle import set_handle
from user_profile import user_profile
from auth_register import auth_register
import server_data
import pytest
from myexcept import raise_err, AccessError, ValueError
from ld_test_data import load_data, dump_data
#set up

dummy_token = '1111'
data = load_data()
test_user = data.users[3]
test_token = 'test_user3'
token = 'test_user3'
def test_user_returnVal():
    data = load_data()
    assert(set_handle(test_token, "@teststring", data) == {})


def test_user_sethandle():
    data = load_data()
    set_handle(test_token, "@teststring2", data)
    assert(data.users[3].handle == "@teststring2")

def test_nohandle():
    data = load_data()
    with pytest.raises(ValueError):
        set_handle(token, "", data)

def test_long_handle():
    data = load_data()
    with pytest.raises(ValueError):
        set_handle(test_token, "@thishandleisfartoolongfortheprogram", data)

def test_invalid_user():
    data = load_data()
    with pytest.raises(AccessError):
        set_handle(dummy_token, "@testString", data)
