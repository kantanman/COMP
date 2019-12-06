import jwt
import datetime

class Data:
    def __init__(self):
        self.users = {}  # dictionary -> {u_id: {instantiated user class}}
        # self.valid_token_list = {}
        self.channel = {} 
        self.u_id_ct = 0
        self.channel_id_ct = 0
        self.reset_code = {}
        self.message_id_ct = 0

    def u_id_increment(self):
        self.u_id_ct = self.u_id_ct + 1

    def channel_id_increment(self):
        self.channel_id_ct = self.channel_id_ct + 1

    def message_id_increment(self):
        self.message_id_ct = self.message_id_ct + 1

lsdata = Data()

class User():

    def __init__(self, first_name, last_name, email, password, u_id):
        self.fname = first_name
        self.lname = last_name
        self.email = email
        self.password = password
        self.handle = '@' + first_name + last_name
        self.token = {} # dictionary of tokens {'email' + datetime.now(): token}
        self.u_id = u_id
        self.channel_in = []
        self.permission_id = 3

    
    def generateToken(email):
        secret = 'lambshank'
        string = email + datetime.now()
        token = jwt.encode({'email': string}, secret, algorithm='HS256')
        # add {string: token} pair to current user for multiple devices
        lsdata.users[self.u_id].token.update({string: token })
        return token

    def authToken(token):
        if token in lsdata.users[self.u_id].token.values():
            # lsdata.valid_token_list.pop(token)
            return True
        else:
            return False


# This funtion generates a u_id number which will be used to name the user object
def createUser(first_name, last_name, email, password):
    lsdata.u_id_increment() # user_id is simply ascending integers that are iterating
    new_u_id_int = lsdata.u_id_ct
    lsdata.users[new_u_id_int] =  User(first_name, last_name, email, password, new_u_id_int)
    return new_u_id_int



'''
class Channel:
    def __init__(self, owner, name, is_public):
        global User_list
        self.users = {}
        #automatically make user with token an owner
        self.users['Channel Owner'] = u_id
        self.valid_token_list = [uid.token]
        self.channel = {}
        self.u_id_ct = 0
        self.message_id_ct = 0
        self.channel_id_ct = 0

'''
class Channels:
	def __init__ (self, owner, is_public, name, channel_id):
        self.owner = [owner]
		self.is_public = is_public
		self.name = name
		self.members = [owner]
		self.messages = []
		self.status = False #if standup is called, then the status turns to True 
        self.channel_id = channel_id
        def addowner(self, new_owner):
		self.owner.append(new_owner)

	def removeowner(self, aim_owner):
		self.owner.remove(aim_owner)


class Messages:
	def __init__(self, content, u_id, message_id):
		self.message_id = str(message_id)
		self.content = content
		self.sender = u_id
		self.status = False
		self.reaction = {}
        
