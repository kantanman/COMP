from ld_data import load_data, dump_data
import server_data
import hashlib
from myexcept import raise_err

def auth_passwordreset_reset(reset_code, new_password, data):
    if reset_code not in data.reset_code.values():
        raise_err('ValueError', 'Invalid reset code!')
    if len(new_password) < 6:
        raise_err('ValueError', 'New password is too short!')
    u_id = get_u_id(reset_code, data)
    del data.reset_code[u_id]
    data.users[u_id].password = hashlib.sha256(new_password.encode()).hexdigest()
    return {}

def get_u_id(given_code, data):
    for u_id, reset_code in data.reset_code.items():
        if reset_code == given_code:
            return u_id