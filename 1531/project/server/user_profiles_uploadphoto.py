from PIL import Image
import sys
from server_data import authToken, retrieveUid
from ld_data import load_data, dump_data
import urllib.request
import urllib.parse
from myexcept import raise_err
import imghdr

def user_uploadphoto(token, img_url, x_start, y_start, x_end, y_end, data, host):
    if not authToken(token, data):
        raise_err('AccessError', 'This is an invalid token')
    x1 = int(x_start)
    x2 = int(x_end)
    y1 = int(y_start)
    y2 = int(y_end)
    u_id = retrieveUid(token, data)
    dir = '/server/images/'
    img_name = dir + str(u_id) + '.jpg'

    try:
        get_img(img_url, '.' + img_name)
    except Exception:
        raise_err('ValueError','This is a invalid URL')

    if imghdr.what('.' + img_name) != 'jpeg':
        raise_err('ValueError', 'This is not a jpg image')

    imageObject = Image.open('.' + img_name)
    cropped = imageObject.crop((x1, y1, x2, y2))
    cropped.save('.' + img_name)

    data.users[u_id].profile_img_url = 'http://' + host + img_name

    return {}
def get_img(img_url, img_name):
    urllib.request.urlretrieve(img_url, img_name)

if __name__ == '__main__':
    get_img('http://blog.hubspot.com/hubfs/image8-2.jpg?fbclid=IwAR1l_OxAPgfYKGW8qjN_SGeiFGjiHcZBYNd16oQ3lBnS6cvEuT5i62PSDlQ', './images/cat.jpg')
    print(imghdr.what('./images/cat.jpg'))
