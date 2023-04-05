import pytest
from standard_rooms import standard_room
# ========================== standard ROOM TESTING ==========================
#           [1] be sure to run pytest -s in the command line
#           [2] I tried to streamline everyting with the same input
#                    - ints = 102
#                    - bools = True
#           [3] keep entering 7 until it quits?
# =======================================================================
standard_obj = standard_room(201, 40, False, False, 1)
standard_to_edit = standard_room(95, 50, True, False, 2)

@pytest.fixture
def standard_to_edit():
    standard_to_edit = standard_room(101, 40, True, False, 3)
    return standard_to_edit

# def test_compare_room_number():
#     assert standard_obj.compare_room_num(201) == True

def test_edit_standard_room_num(standard_to_edit):
    new_room_num = 102
    standard_to_edit.edit()
    standard_to_edit._room_num = new_room_num 
    assert standard_to_edit._room_num == new_room_num

def test_edit_standard_num_seats(standard_to_edit):
    new_num_seats = 102
    standard_to_edit.edit()
    standard_to_edit._num_seats = new_num_seats
    assert standard_to_edit._num_seats == new_num_seats

def test_edit_standard_handi_access(standard_to_edit):
    standard_to_edit.edit()
    standard_to_edit._handi_access = True
    assert standard_to_edit._handi_access == True

def test_edit_standard_reserved(standard_to_edit):
    standard_to_edit.edit()
    standard_to_edit._reserved = True
    assert standard_to_edit._reserved == True

def test_edit_standard_monitor(standard_to_edit):
    new_num_monitor = 102
    standard_to_edit.edit()
    standard_to_edit._num_monitor = new_num_monitor
    assert standard_to_edit._num_monitor == new_num_monitor

