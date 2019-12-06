from auth_register import auth_register
import pytest
from ld_test_data import load_data
import string
import random

def generate_code(length=6):
    lettersAndDigits = string.ascii_letters + string.digits
    code = ''.join(random.choice(lettersAndDigits) for i in range(length))
    return code

data = load_data()

def get_token(u_id):
    #data = load_data()
    for key in data.token_dict:
        if u_id == data.token_dict[key]:
            return key

email = generate_code() + '@unsw.edu.au'
pword = 'pAssworD'
firstname = 'John'
lastname = 'Doe'


def test_valid_credentials():
    #data = load_data()
    assert auth_register(email, pword, firstname, lastname, data) == {
        'u_id' : data.u_id_ct,
        'token' : get_token(data.u_id_ct)
    }


def test_invalid_email():
    with pytest.raises(Exception):
        auth_register('bademail', pword, firstname, lastname, data)

def test_used_email():
    #auth_register(email, pword, firstname, lastname, data)
    with pytest.raises(Exception):
        auth_register(email, pword, firstname, lastname, data)

def test_invald_pword():
    with pytest.raises(Exception):
        auth_register(email, "abc", firstname, lastname, data)
        auth_register(email, "", firstname, lastname, data)
        auth_register(email, "badp", firstname, lastname, data)
        auth_register(email, "1111", firstname, lastname, data)

def test_long_fname():
    longname = 'abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz'
    with pytest.raises(Exception):
        auth_register(email, pword, longname, lastname, data)

def test_long_lname():
    longname = 'abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz'
    with pytest.raises(Exception):
        auth_register(email, pword, firstname, longname, data)


def test_short_password ():
    with pytest.raises(Exception):
        auth_register(email, '1asf', firstname, lastname, data)