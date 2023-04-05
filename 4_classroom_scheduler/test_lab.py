import pytest
from lab_rooms import lab_room
# ========================== ZOOM ROOM TESTING ==========================
#           [1] be sure to run pytest -s in the command line
#           [2] I tried to streamline everyting with the same input
#                    - ints = 102
#                    - bools = True
#           [3] keep entering 7 until it quits?
# =======================================================================
lab_obj = lab_room(201, 40, False, False, 1)
lab_to_edit = lab_room(95, 50, True, False, 2)

@pytest.fixture
def lab_to_edit():
    lab_to_edit = lab_room(101, 40, True, False, 3)
    return lab_to_edit

# def test_compare_room_number():
#     assert lab_obj.compare_room_num(201) == True

def test_edit_lab_room_num(lab_to_edit):
    new_room_num = 102
    lab_to_edit.edit()
    lab_to_edit._room_num = new_room_num 
    assert lab_to_edit._room_num == new_room_num

def test_edit_lab_num_seats(lab_to_edit):
    new_num_seats = 102
    lab_to_edit.edit()
    lab_to_edit._num_seats = new_num_seats
    assert lab_to_edit._num_seats == new_num_seats

def test_edit_lab_handi_access(lab_to_edit):
    lab_to_edit.edit()
    lab_to_edit._handi_access = True
    assert lab_to_edit._handi_access == True

def test_edit_lab_reserved(lab_to_edit):
    lab_to_edit.edit()
    lab_to_edit._reserved = True
    assert lab_to_edit._reserved == True

def test_edit_lab_computers(lab_to_edit):
    new_num_computers = 102
    lab_to_edit.edit()
    lab_to_edit._num_computers = new_num_computers
    assert lab_to_edit._num_computers == new_num_computers


