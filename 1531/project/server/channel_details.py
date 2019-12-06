
from ld_data import load_data, dump_data
from myexcept import raise_err
import server_data
from help_functions import is_real_channel_id, is_user_in_channel



def channel_details(token, channel_id, data):
	channel_id = int(channel_id)
	if not (server_data.authToken(token, data)):
		raise_err('AccessError', 'This is an invalid token')
		
	u_id = server_data.retrieveUid(token, data)

	if not is_real_channel_id(channel_id, data):
		raise_err('ValueError', 'This is not a real channel_id')

	if not is_user_in_channel(u_id, channel_id, data):
		return {
			'name' : data.channels[channel_id].name,
			'owner_members' : [],
			'all_members' : []
		}

	owner_list = []
	member_list = []

	for o_id in data.channels[channel_id].owner:
		owner_dict = {
			'name_first' : data.users[o_id].fname,
			'name_last' : data.users[o_id].lname,
			'u_id' : o_id,
			'profile_img_url' : data.users[o_id].profile_img_url
		}
		owner_list.append(owner_dict)
	for m_id in data.channels[channel_id].members:
		member_dict = {
			'name_first' : data.users[m_id].fname,
			'name_last' : data.users[m_id].lname,
			'u_id' : m_id,
			'profile_img_url' : data.users[m_id].profile_img_url
		}
		member_list.append(member_dict)

	return {
		'name' : data.channels[channel_id].name,
		'owner_members' : owner_list,
		'all_members' : member_list
		}


