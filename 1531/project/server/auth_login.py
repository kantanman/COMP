from ld_data import load_data, dump_data
from myexcept import raise_err
import hashlib
import server_data
from auth_register import valid_email_test
def auth_login(email, password, data):
    password = hashlib.sha256(password.encode()).hexdigest()

    if not valid_email_test(email):
        raise_err('Value', 'This is an invalid email')
    
    e_found = False

    for user in data.users.keys():
        if email == data.users[user].email:
            e_found = True
            if password == data.users[user].password:
                break
            else:
                raise_err('ValueError', 'The password is incorrect')
    
    if e_found is False:
       raise_err('ValueError', 'Please enter a registed email')

    # found the user
    token = data.users[user].generateToken()
    u_id = data.users[user].u_id
    data.token_dict[token] = u_id
    return {
        'u_id' : u_id,
        'token' : token
        }