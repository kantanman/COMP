import server_data
from myexcept import raise_err
from ld_data import load_data, dump_data
from help_functions import is_permitted, is_real_u_id

def admin_userpermission_change(token, u_id, permission_id, data):
    if not (server_data.authToken(token, data)):
        raise_err('AccessError', 'This is an invalid token')
    u_id = int(u_id)
    permission_id = int(permission_id)

    u_id_exe = server_data.retrieveUid(token, data)

    if not is_permitted(u_id_exe, data):
        raise_err('AccessError', 'You are not permitted to do this')
    if not is_real_u_id(u_id, data):
        raise_err('ValueError', 'This is not a real u_id')

    if permission_id != 1 and permission_id != 2 and permission_id != 3:
        raise_err('ValueError', 'No such permission_id')
        
    data.users[u_id].permission_id = permission_id
    return {}