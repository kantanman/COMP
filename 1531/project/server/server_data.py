import jwt
from datetime import datetime
from ld_data import dump_data, load_data
import yaml
import hashlib
from datetime import timezone, datetime
import time
class Data:
    def __init__(self):
        self.users = {}  # dictionary -> {u_id: {instantiated user object}}
        self.token_dict = {} # {token: u_id}
        self.channels = {} # {} -> {channel_id: {instantiated channel object}}
        self.u_id_ct = 0
        self.channel_id_ct = 0
        self.reset_code = {}
        self.message_id_ct = 0
        self.msg_id_dict = {}

    def u_id_increment(self):
        self.u_id_ct = self.u_id_ct + 1

    def channel_id_increment(self):
        self.channel_id_ct = self.channel_id_ct + 1

    def message_id_increment(self):
        self.message_id_ct = self.message_id_ct + 1

lsdata = Data()
#with open('server_data.yml', 'w') as FILE:
        #global lsdata
        #yaml.dump(lsdata, FILE, allow_unicode = True)

class User():

    def __init__(self, first_name, last_name, email, password, u_id):
        self.fname = first_name
        self.lname = last_name
        self.email = email
        self.password = hashlib.sha256(password.encode()).hexdigest()
        self.handle = '@' + first_name + last_name
        #self.token = [] # dictionary of tokens {'email' + datetime.now(): token} # CHANGE doesn't need to be dict
        self.u_id = u_id
        self.channel_in = []
        self.permission_id = 3
        self.profile_img_url = None
    
    def generateToken(self):
        secret = 'lambshank'
        token = jwt.encode({'email' : self.email + str(datetime.now())}, secret, algorithm='HS256')
        # add {string: token} pair to current user for multiple devices
        return token.decode('utf-8')




# I TOOK ALL THESE FUNCTIONS OUT OF THE USER CLASS

def authToken(token, data):
    if token in data.token_dict.keys():
        return True
    else:
        return False
    #   ADDING A RETRIEVE U_ID FUNCTION
def retrieveUid(token, data):
    return data.token_dict[token]
    #   ADDING A REMOVE TOKEN FUNCTION
def removeToken(token, lsdata):
    for u_id in lsdata.users:
        if token in lsdata.users[u_id].token:
            lsdata.users[u_id].token.remove(token)
            dump_data(lsdata)
            return True


# This funtion generates a u_id number which will be used to name the user object
def createUser(first_name, last_name, email, password, lsdata):
    lsdata.u_id_increment() # user_id is simply ascending integers that are iterating
    new_u_id_int = lsdata.u_id_ct
    lsdata.users[new_u_id_int] =  User(first_name, last_name, email, password, new_u_id_int)
    return new_u_id_int



class Channels:
    def __init__(self, owner, is_public, name, channel_id):
        self.owner = [owner]   #list of dictionaries of users
        self.is_public = is_public
        self.name = name
        self.members = [owner]   #list of dictionaries of users
        self.messages = []
        self.status = False #if standup is called, then the status turns to True 
        self.time_finish = None
        self.starter = None
        self.channel_id = channel_id
        self.standups = []  #user_name : content

class Messages:
    def __init__(self, content, u_id, message_id, send_time):
        self.message_id = message_id
        self.content = content
        self.sender = u_id
        self.status = False
        self.time = send_time
        self.reaction = {}
        
