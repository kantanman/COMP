from ld_data import load_data, dump_data
def auth_logout (token, data) :
	if data.token_dict.get(token) is None:
		return {'is_success' : False}
	del data.token_dict[token]
	return {'is_success' : True}
