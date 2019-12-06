from flask import request 
from ld_data import load_data, dump_data
from myexcept import raise_err
from json import dumps
import server_data
from help_functions import is_real_channel_id, is_real_u_id, is_user_in_channel

def channel_invite(token, channel_id, u_id, data):
	if not (server_data.authToken(token, data)):
		raise_err('AccesError', 'This is an invalid token')

	u_id_inviter = server_data.retrieveUid(token, data)
	channel_id = int(channel_id)
	u_id = int(u_id)
	
	if not is_real_u_id(u_id, data):
                raise_err('ValueError', 'This is not a real u_id')


	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is not a real channel_id')

	if not is_user_in_channel(u_id_inviter, channel_id, data):
		raise_err('AccessError', 'You are not a member of this channel')


	data.users[u_id].channel_in.append(channel_id)
	data.channels[channel_id].members.append(u_id)
	return {}
