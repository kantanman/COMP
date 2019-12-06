from channel_details import channel_details
import pytest
from channels_create import channels_create
from auth_register import auth_register
from myexcept import AccessError, ValueError
from ld_test_data import load_data

data = load_data()

token1 = 'test_user1'
token3 = 'test_user3'

def test_channel_true_false ():

    channel_details (token1, 1, data) # correct input, no error

    with pytest.raises (ValueError):
    	channel_details (token1, '123456', data)
    	# channel id does not exist

def test_invalid_token ():

    with pytest.raises (Exception):
    	channel_details ('token4', 1, data) 