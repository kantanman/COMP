import server_data
from myexcept import raise_err
from ld_data import load_data
def users_all(token, data):
    if not server_data.authToken(token, data):
        raise_err('AccessError', 'This is an invalid token')
    u_lst = []
    for u_id in data.users.keys():
        u_dct = {
            'profile_img_url' : data.users[u_id].profile_img_url,
            'u_id' : u_id,
            'email' : data.users[u_id].email,
            'name_fist' : data.users[u_id].fname,
            'name_last' : data.users[u_id].lname,
            'handle_str' : data.users[u_id].handle
        }
        u_lst.append(u_dct)
    return {
        'users' : u_lst
        }