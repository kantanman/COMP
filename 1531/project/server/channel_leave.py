from json import dumps

from flask import request

import server_data
from myexcept import raise_err
from ld_data import dump_data, load_data
from help_functions import is_real_channel_id, is_user_in_channel

def channel_leave (token, channel_id, data):
	channel_id = int(channel_id)
	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')
	u_id = server_data.retrieveUid(token, data)

	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is not a real channel_id')

	if not is_user_in_channel(u_id, channel_id, data):
		raise_err('AccessError', 'You are not a member of this channel')

	data.channels[channel_id].members.remove(u_id)
	
	if u_id in data.channels[channel_id].owner:
		data.channels[channel_id].owner.remove(u_id)

	data.users[u_id].channel_in.remove(channel_id)
	return {}
