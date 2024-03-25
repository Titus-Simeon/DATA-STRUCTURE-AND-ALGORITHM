class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseLinkedList(head):
    prev = None
    current = head
    
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    
    return prev

# Helper function to create a linked list
def createLinkedList(arr):
    if not arr:
        return None
    
    nodes = [ListNode(val) for val in arr]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    
    return nodes[0]

# Helper function to print the linked list
def printLinkedList(head):
    current = head
    while current:
        print(current.val, end=" ")
        current = current.next
    print()

# Test the function
head = createLinkedList([1, 2, 3, 4, 5])
print("Original Linked List:")
printLinkedList(head)

reversed_head = reverseLinkedList(head)
print("Reversed Linked List:")
printLinkedList(reversed_head)
