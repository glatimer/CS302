import pytest
from classrooms import classroom
# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#         This file contains the PyTest functions to test our 
#                   classroom hierarchy functions 
#          [1] be sure to run pytest -s in the command line
#          [2] I tried to streamline everyting with the same input
#                           - ints = 102
#                           - bools = True
# -------------------------------------------------------------------------

# =========================  CLASSROOM TESTING  ===========================
classroom_obj = classroom(333, 75, True, False)
classroom_to_compare = classroom(111, 50, True, False)

@pytest.fixture
def classroom_to_edit():
    classroom_to_edit = classroom(333, 75, True, False)
    return classroom_to_edit

def test_gt():
    assert classroom_obj.__gt__(classroom_to_compare) == True

def test_ge():
    assert classroom_obj.__ge__(classroom_to_compare) == True

def test_lt():
    assert classroom_obj.__lt__(classroom_to_compare) == False

def test_le():
    assert classroom_obj.__le__(classroom_to_compare) == False

def test_compare_room_number():
    assert classroom_obj.compare_room_num(333) == True

def test_edit_room_num(classroom_to_edit):
    new_room_num = 102
    classroom_to_edit.edit(1)
    classroom_to_edit._room_num = new_room_num 
    assert classroom_to_edit._room_num == new_room_num

def test_edit_num_seats(classroom_to_edit):
    new_num_seats = 102
    classroom_to_edit.edit(2)
    classroom_to_edit._num_seats = new_num_seats
    assert classroom_to_edit._num_seats == new_num_seats

def test_edit_handi_access(classroom_to_edit):
    classroom_to_edit.edit(3)
    classroom_to_edit._handi_access = True
    assert classroom_to_edit._handi_access == True

def test_edit_reserved(classroom_to_edit):
    classroom_to_edit.edit(4)
    classroom_to_edit._reserved = True
    assert classroom_to_edit._reserved == True


