from user_profile_setname import set_name
from user_profile import user_profile
from auth_register import auth_register
from myexcept import raise_err, AccessError, ValueError
from ld_test_data import load_data, dump_data
import pytest
import server_data

long_str = "123457eocjdkrncjkfdkjremcmnfndjvmfmdmncksdnrmvmndmcjdmckjsmxjcmd xjns8"

data = load_data()
test_user = data.users[3]
test_token = ''


def test_user1_lastname():
    data = load_data()
    new_nameLast = "smith"
    set_name('test_user3', test_user.fname, new_nameLast, data)
    assert(data.users[3].lname == new_nameLast)

def test_noname():
    data = load_data()
    with pytest.raises (ValueError):
        set_name('test_user3', "" , "", data)

def test_long_namefirst():
    data = load_data()
    with pytest.raises (ValueError):
        set_name('test_user3', long_str, "smith", data)

def test_long_namelast():
    data = load_data()
    with pytest.raises(ValueError):
        set_name('test_user3', "john", long_str, data)

def test_invalid_token():
    data = load_data()
    with pytest.raises(AccessError):
        set_name(1111, "John", "Smith", data)


