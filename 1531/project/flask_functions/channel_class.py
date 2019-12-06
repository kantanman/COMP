# Copied this from Jacks SERVER FOLDER 

class Channels:
	def __init__ (self, owner, is_public, name, channel_id):
		self.owner = [owner]
		self.is_public = is_public
		self.name = name
		self.members = [owner]
		self.messages = {}
		self.status = False #if standup is called, then the status turns to True 
		self.channel_id = channel_id
	def addowner(self, new_owner):
		self.owner.append(new_owner)

	def removeowner(self, aim_owner):
		self.owner.remove(aim_owner)
