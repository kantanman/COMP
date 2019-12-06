from user_profile import user_profile
from auth_register import auth_register
from ld_test_data import load_data
import pytest
from myexcept import raise_err, AccessError

dummy_token = '1111'
data = load_data()
test_user = data.users[3]
test_token = 'test_user3'

def test_userprofile():
    assert(user_profile(test_token, 3, load_data())) == {'email' : test_user.email, 'name_first': test_user.fname,'name_last' : test_user.lname, 'handle_str' : test_user.handle, 'profile_img_url' : None}

def test_invalid_user():
    with pytest.raises (AccessError):
        user_profile(dummy_token, 2, load_data())

