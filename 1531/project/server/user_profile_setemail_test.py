from user_profile_setemail import set_email
from auth_register import auth_register
from ld_test_data import load_data
from myexcept import raise_err, ValueError, AccessError
from random import randint
import pytest

data = load_data()
test_user = data.users[3]
test_token = 'test_user3'
token = 'test_user3'

def test_user_setemail_returnVal():
    data = load_data()
    assert(set_email('test_user3', "newhello@unsw.com", data) == {})

def test_user_set_email():
    set_email('test_user3', "newemail@unsw.com", data)
    assert(data.users[3].email == "newemail@unsw.com")

def test_user_set_badEmails():
    data = load_data()
    with pytest.raises(ValueError):
        set_email(token, "@hotmail.com", data)
        set_email(token, "sillyemail@", data)
        set_email(token, "another silly email", data)
        set_email(token, "@wot@", data)

def test_used_email():
    data = load_data()
    with pytest.raises(ValueError):
        set_email(test_token, 'test2@email.com', data)

def test_current_email():
    data = load_data()
    with pytest.raises(ValueError):
        set_email(test_token, 'test3@email.com', data)

def test_invalid_user():
    data = load_data()
    fake_token = '1111'
    with pytest.raises (AccessError):
        set_email(fake_token, "dana@unsw.com", data)

