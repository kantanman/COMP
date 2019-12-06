import yaml
import sys
sys.path.insert(1,'../')
def load_data():
	with open('server_data.yml', 'r') as FILE:
		data = None
		while data is None:
			data = yaml.load(FILE, Loader = yaml.FullLoader)
		return data


def dump_data(data):
	with open('server_data.yml', 'w') as FILE:
		yaml.dump(data, FILE, allow_unicode = True)


if __name__ == '__main__':
	data = load_data()
	print(data)