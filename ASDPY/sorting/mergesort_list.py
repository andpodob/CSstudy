class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def get_middle(list):
    if list == None:
        return list
    
    slow = list
    fast = list

    while (slow.next != None and fast.next.next != None):
        slow = slow.next
        fast = fast.next.next

    return slow

def merge(list1, list2):
    if(list1 == None):
        return list2
    if(list2 == None):
        return list1
    
