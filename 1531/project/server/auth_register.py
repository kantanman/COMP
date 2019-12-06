import server_data
from json import dumps
from ld_data import dump_data, load_data
from myexcept import raise_err
import re
from help_functions import is_legal_length, is_email_used



def auth_register(email, password, name_first, name_last, data):
    
    if not (valid_email_test(email)):
        raise_err('ValueError', 'This is an invalid email')
        
    if len(password) < 5:
        raise_err('ValueError', 'Your password is too short')

    if not is_legal_length(50, name_first):
        raise_err('ValueError', 'First name is too long')

    if not is_legal_length(50, name_last):
        raise_err('ValueError', 'Last name is too long')

    if is_email_used(email, data):
        raise_err('ValueError', 'This email has benn registered')
    
    data.u_id_increment()
    u_id = data.u_id_ct

    user = server_data.User(name_first, name_last, email, password, u_id)

    data.users[u_id] = user 
    token = user.generateToken() 
    
    data.token_dict[token] = u_id
    #dump_data(data)
    return {
        'u_id' : u_id,
        'token' : token
    }

def valid_email_test(email):
    regex = '^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$'
    return re.search(regex,email)
    
