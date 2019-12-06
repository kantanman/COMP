from flask import request

import server_data
from ld_data import dump_data, load_data
from myexcept import raise_err
from help_functions import is_real_channel_id, is_user_in_channel, is_permitted

def channel_removeowner (token, channel_id, u_id, data):
	channel_id = int (channel_id)
	u_id = int (u_id)
	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')

	u_id_inviter = server_data.retrieveUid(token, data)
	

	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is not a real channel_id')

	if not is_user_in_channel(u_id, channel_id, data):
		raise_err('ValueError', 'This user is not a member of this channel')

	if u_id not in data.channels[channel_id].owner:
		raise_err('ValueError', 'This user is not a owner of this channel')

	if (u_id_inviter not in data.channels[channel_id].owner) and not is_permitted(u_id_inviter, data):
		raise_err('AccessError', 'You are not permitted to do this')

	data.channels[channel_id].owner.remove(u_id)
	return {}
