import pytest
from auth_passwordreset_reset import auth_passwordreset_reset 
from ld_test_data import load_data
from auth_passwordreset_request import send_mail

invalid_reset_code = '11111'

data = load_data()

def test_ValueError_1 ():
	with pytest.raises (Exception):
	 	auth_passwordreset_reset (invalid_reset_code, '123456', data)

def test_ValueError_2 ():
	#send_mail('test3@email.com', data)
	data.reset_code[3] = '123bca'
	with pytest.raises (Exception):
		auth_passwordreset_reset (data.reset_code[3], 'abcd', data)
		# the new password is too short

def test_pass ():
	auth_passwordreset_reset (data.reset_code[3], 'gjbfau33r', data)