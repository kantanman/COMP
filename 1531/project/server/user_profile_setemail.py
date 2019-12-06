import server_data
from auth_register import valid_email_test
from myexcept import raise_err
from help_functions import is_email_used

def set_email(token, new_email, data):
	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalide token')
	u_id = server_data.retrieveUid(token, data)
	 # check if email is valid
	if not valid_email_test(new_email):
        	raise_err('ValueError', 'This is an invalid email')
	# check if email isn't used by another user
	if is_email_used(new_email, data):
		raise_err('ValueError', 'This email is used by another user')
	data.users[u_id].email = new_email
	return {}
