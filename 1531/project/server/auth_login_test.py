from auth_login import auth_login
from auth_register import auth_register
from auth_logout import auth_logout
from ld_test_data import load_data
import re
import pytest
import string
import random

data = load_data()

def generate_code(length=6):
    lettersAndDigits = string.ascii_letters + string.digits
    code = ''.join(random.choice(lettersAndDigits) for i in range(length))
    return code

def get_token(u_id):
    count = 0
    for key in data.token_dict:
        if u_id == data.token_dict[key]:
            count += 1
            if count == 2:
                return key

email = generate_code() + '@unsw.com.au'
password = 'pAssworD'

def test_invald_email():
    with pytest.raises(Exception):
        auth_login('@abc', 'yeah', data)
        auth_login('bademail', 'yeah', data)
        auth_login('!()woah', 'yeah', data)
        auth_login('stoopidemail@', 'yeah', data)
        auth_login('ba@demail@', 'yeah', data)
        auth_login('bad**/?email.', 'yeah', data)

def test_unused_email():
    with pytest.raises(Exception):
        auth_login('NEWemail@unsw.edu.au', 'yeah', data)


def test_correct_logins():
    auth_register(email, password, 'John', 'Doe', data)
    auth_logout(data.u_id_ct, data)
    assert auth_login(email, password, data) == {
        'u_id' :  data.u_id_ct,
        'token' : get_token(data.u_id_ct)
    }
