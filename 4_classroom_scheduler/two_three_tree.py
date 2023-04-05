#from application import application

# -------------------------------------------------------------------------
#                  Assignment #4-5 : Genevieve Latimer
#       node and data structure implementation for a 2-3 Tree 
#              organized by course reference number (CRN).
# -------------------------------------------------------------------------
# node class takes a course object as an argument
class Node():
    def __init__(self, new_data):
        self._data = list([new_data])
        self._data_count = len(self._data)
        self._CRN = new_data.CRN
        self._left_child = None
        self._middle_child = None
        self._right_child = None
        self._parent = None

    @property
    def left_child(self):
        return self._left_child
    @left_child.setter
    def left_child(self, new_left):
        self._left_child = new_left

    @property
    def middle_child(self):
        return self._middle_child
    @middle_child.setter
    def middle_child(self, new_middle):
        self._middle_child = new_middle
    
    @property
    def right_child(self):
        return self._right_child
    @right_child.setter
    def right_child(self, new_right):
        self._right_child = new_right

    @property
    def parent(self):
        return self._parent
    @parent.setter
    def parent(self, new_parent):
        self._parent = new_parent

    # node getters
    def get_left(self):
        return self._left_child
    def get_middle(self):
        return self._middle_child
    def get_right(self):
        return self._right_child

    # node setters
    def set_left(self, new_left):
        self._left_child = new_left
    def set_middle(self, new_middle):
        self._middle_child = new_middle
    def set_right(self, new_right):
        self._right_child = new_right

    # display node data
    def display(self):
        print("Data Count: ", self._data_count)
        for course in self._data:
            course.display()
            print()
        print()

    # compare the root data to a key. If found, return true
    def search_CRN(self, CRN_tofind):
        for course in self._data:
            if course._CRN == CRN_tofind:
                course.display()
                return True
            else:
                return False
        
                                                                                                                    
# ----------------------------------- TREE -----------------------------------
class Two_Three_Tree():
    def __init__(self):
        self._root = None
        self._done = False

    # for recursive insert, absorb at a leaf
    def _absorb(self, root, to_absorb):
        #print("Absorb " + to_absorb._CRN + " into " + root._data[0]._CRN + ". No new node needed.")
        if root._data_count < 2:
            root._data.append(to_absorb)
            root._data.sort()
            root._data_count = len(root._data)
        else: 
            # split the node and insert the data
            push_up = self._split(root, to_absorb)
            if push_up:
                # recursively insert the push_up node into the parent
                return self._insert(root._parent, push_up)
            else:
                return None
    
    # for recursive insert, split a leaf or split a parent
    def _split(self, root, new_data):
        # data = [0]smallest [1]middle [2]largest
        smallest = root._data[0]
        middle = root._data[1]
        largest = new_data #root._data[2]
        
        # build node to push up (redefine current node)
        push_up = root
        push_up._data.clear()
        push_up._data.append(middle)
        push_up._data_count = len(push_up._data)
        root = push_up
        #print("push_up: " + root._data[0].lname)
        
        # set push_up's left 
        temp_left = Node(smallest)
        # temp_left._data_count = len(root._data)
        temp_left._parent = root
        root._left_child = temp_left
        #print(root._data[0].lname + "'s left_child: " + root._left_child._data[0]._CRN)

        # set push_up's middle (push_up right = null)
        temp_middle = Node(largest)
        # temp_middle._data_count = len(temp_middle._data)
        temp_middle._parent = root
        root._middle_child = temp_middle
        #print(root._data[0].lname + "'s middle_child: " + root._middle_child._data[0]._CRN)
        
        # if parent exists, connect push_up to parent
        if root._parent:
            parent = root._parent
            # if parent has room, connect up and absorb data
            if parent._data_count < 2:
                #print("Push up " + root._data[0].lname + " to existing parent ")
                # connect smaller 
                if root._data[0] < parent._data[0]:
                    parent._left_child = root._left_child
                    parent._right_child = parent._middle_child
                    parent._middle_child = root._middle_child
                    parent._data.append(root._data[0])
                    parent._data_count = len(parent._data)
                    parent._data.sort()
                    root = parent
                    return root

                # connect larger 
                elif root._data[0] >= parent._data[0]:
                    parent._middle_child = root._left_child
                    root._left_child._parent = parent
                    parent._right_child = root._middle_child
                    root._middle_child._parent = parent
                    parent._data.append(root._data[0])
                    parent._data_count = len(parent._data)
                    parent._data.sort() # redundant?
                    root = parent
                    return 

        
    # pass the object into the insert function
    def insert(self, new_data):
        if self._root == None: 
            #print("Empty. Insert leaf: ", new_data._CRN)
            self._root = Node(new_data)
            self._root._data_count = len(self._root._data)
            return
        self._root = self._insert(self._root, new_data) #, self._done)

    # recursive insert
    def _insert(self, root, new_data):
        if root == None: 
            return Node(new_data) 

        # traverse to correct node 
        if root._data_count == 1 and new_data._CRN >= root._data[0]._CRN:
            root.set_middle(self._insert(root.get_middle(), new_data))
        elif root._data_count == 2 and new_data < root._data[1]:
            root.set_middle(self._insert(root.get_middle(), new_data))
        elif root._data_count == 2 and new_data >= root._data[1]:
            root.set_right(self._insert(root.get_right(), new_data))
        else:
            root.set_left(self._insert(root.get_left(), new_data))

        # leaf == if no children
        if (root._left_child == None and root._middle_child == None and root._right_child == None):
            # if leaf data is not full, absorb data
            if root._data_count < 2:
                #print("Not empty. Absorb " + new_data._CRN + " into " + root._data[0]._CRN + ". No new node needed.")
                root._data.append(new_data)
                root._data.sort()
                root._data_count = len(root._data)
                return root
                
            # if the leaf data is full, split
            if root._data_count == 2:
                #print("The data is full: " + root._data[0].lname + " and " + root._data[1].lname)
                root._data.append(new_data)
                root._data.sort()
                #print("Split node: " + root._data[0].lname + " and " + root._data[1].lname + " and " + root._data[2].lname)
                self._split(root, new_data)
        return root

    # display the 2-3 Tree
    def display_tree(self):
        if self._root == None:
            return
        self._inorder(self._root)

    # display the 2-3 Tree
    def _inorder(self, root):
        if root == None:
            return

        self._inorder(root.get_left()) 
        root.display()
        self._inorder(root.get_middle())
        self._inorder(root.get_right())
        
   # find a course in the tree by CRN
    def search(self, find_CRN):
        if self._root == None:
            return None
        found = self._search_CRN(self._root, find_CRN)
        return found

    # recurse through the tree inorder to find the CRN
    def _search_CRN(self, root, find_CRN):
        if root == None:
            return None
        
        if root.search_CRN(find_CRN) == True:
            return root._data

        self._search_CRN(root.get_left(), find_CRN)
        self._search_CRN(root.get_middle(), find_CRN)
        self._search_CRN(root.get_right(), find_CRN)
        return None