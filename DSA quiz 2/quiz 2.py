class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detectCycle(head):
    if not head or not head.next:
        return None
    
    slow = head
    fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            break
    else:
        return None  # No cycle found
    
    # Move one of the pointers to the head
    slow = head
    
    # Move both pointers at the same pace until they meet again
    while slow != fast:
        slow = slow.next
        fast = fast.next
    
    return slow

# Helper function to create a linked list
def createLinkedList(arr, pos):
    if not arr:
        return None
    
    nodes = [ListNode(val) for val in arr]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    
    if pos != -1:
        nodes[-1].next = nodes[pos]
    
    return nodes[0]

# Test cases
head1 = createLinkedList([3, 2, 0, -4], 1)
head2 = createLinkedList([1, 2], 0)
head3 = createLinkedList([1], -1)

print(detectCycle(head1))  # Output: tail connects to node index 1
print(detectCycle(head2))  # Output: tail connects to node index 0
print(detectCycle(head3))  # Output: no cycle
