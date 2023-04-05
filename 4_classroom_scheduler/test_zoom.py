import pytest
from zoom_rooms import zoom_room
# ========================== ZOOM ROOM TESTING ==========================
#           [1] be sure to run pytest -s in the command line
#           [2] I tried to streamline everyting with the same input
#                    - ints = 102
#                    - bools = True
#           [3] keep entering 7 until it quits?
# =======================================================================
zoom_obj = zoom_room(201, 40, False, False, 1, 1)
zoom_to_edit = zoom_room(95, 50, True, False, 2, 3)

@pytest.fixture
def zoom_to_edit():
    zoom_to_edit = zoom_room(101, 40, True, False, 3, 2)
    return zoom_to_edit

# def test_compare_room_number():
#     assert zoom_obj.compare_room_num(201) == True

def test_edit_zoom_room_num(zoom_to_edit):
    new_room_num = 102
    zoom_to_edit.edit()
    zoom_to_edit._room_num = new_room_num 
    assert zoom_to_edit._room_num == new_room_num

def test_edit_zoom_num_seats(zoom_to_edit):
    new_num_seats = 102
    zoom_to_edit.edit()
    zoom_to_edit._num_seats = new_num_seats
    assert zoom_to_edit._num_seats == new_num_seats

def test_edit_zoom_handi_access(zoom_to_edit):
    zoom_to_edit.edit()
    zoom_to_edit._handi_access = True
    assert zoom_to_edit._handi_access == True

def test_edit_zoom_reserved(zoom_to_edit):
    zoom_to_edit.edit()
    zoom_to_edit._reserved = True
    assert zoom_to_edit._reserved == True

def test_edit_zoom_cameras(zoom_to_edit):
    new_num_cameras = 102
    zoom_to_edit.edit()
    zoom_to_edit._num_cameras = new_num_cameras
    assert zoom_to_edit._num_cameras == new_num_cameras

def test_edit_zoom_mic(zoom_to_edit):
    new_num_mic = 102
    zoom_to_edit.edit()
    zoom_to_edit._num_mic = new_num_mic
    assert zoom_to_edit._num_mic == new_num_mic

