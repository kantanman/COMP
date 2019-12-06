from auth_logout import auth_logout 
import pytest 
from ld_test_data import load_data

data = load_data()

def test_logout_1 ():
	assert auth_logout('test_user1', data) == {'is_success' : True}
	assert 'test_user1' not in data.token_dict.keys()

def test_logout_2 () :
	assert auth_logout('test_user2', data) == {'is_success' : True}
	assert 'test_user2' not in data.token_dict.keys()

def test_logout_fail():
	assert 'logout_test_1' not in data.token_dict.keys()
	assert auth_logout('logout_test_3',data) == {'is_success' : False}