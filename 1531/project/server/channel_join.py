from json import dumps

from myexcept import raise_err
import server_data
from flask import request
from ld_data import dump_data, load_data
from help_functions import is_real_channel_id, is_channel_public, is_permitted

def channel_join (token, channel_id, data):
	channel_id = int(channel_id)
	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')

	u_id = server_data.retrieveUid(token, data)

	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is not a real channel_id')

	if not is_channel_public(channel_id, data) and not is_permitted(u_id, data):
		raise_err('AccessError', 'This is a private channel')


	data.channels[channel_id].members.append(u_id)
	data.users[u_id].channel_in.append(channel_id)

	return {}
