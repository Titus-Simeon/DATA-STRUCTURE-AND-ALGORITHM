class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def hasCycle(head: ListNode) -> bool:
    if not head or not head.next:
        return False

    slow = head
    fast = head.next

    while fast and fast.next:
        if slow == fast:
            return True
        slow = slow.next
        fast = fast.next.next

    return False

# Example usage:
# Creating the linked list from the example
node4 = ListNode(-4)
node3 = ListNode(0, node4)
node2 = ListNode(2, node3)
node1 = ListNode(3, node2)
node4.next = node2  # Creating the cycle

# Checking if there's a cycle
print(hasCycle(node1))  # Output: True
