from flask import Flask, request
from json import dumps
import server_data
from myexcept import raise_err

# For a valid user, returns dumps about email, first name, last name, and handle
def user_profile(token, u_id, data):
	u_id = int(u_id)
	if not server_data.authToken(token, data):
		raise_err('AccessError', 'This is an invalid token')
	# reqeust user data
	

	return {
		'email' : data.users[u_id].email,
		'handle_str' : data.users[u_id].handle,
		'name_first' : data.users[u_id].fname,
		'name_last' : data.users[u_id].lname,
		'profile_img_url' : data.users[u_id].profile_img_url
	}
