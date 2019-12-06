from admin_userpermission_change import admin_userpermission_change
from ld_test_data import load_data
from myexcept import AccessError, ValueError
import pytest

def test_succ():
	data = load_data()
	admin_userpermission_change('test_user1', 2, 2, data)
	assert data.users[2].permission_id == 2

def test_not_permitted():
	data = load_data()
	with pytest.raises(AccessError):
		admin_userpermission_change('test_user2', 3, 2, data)
