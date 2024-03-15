//Linked List that is Sorted Alternatingly
//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;
    
    public Node (int data){
        this.data = data;
        this.next = null;
    }
}

class GFG {
    static void printList(Node node) 
	{ 
		while (node != null) 
		{ 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
		System.out.println(); 
	}
	public static void main (String[] args) {
		Scanner sc  = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    
		    Node head = new Node(sc.nextInt());
		    Node tail = head;
		    
		    for(int i=1; i<n; i++){
		        tail.next = new Node(sc.nextInt());
		        tail = tail.next;
		    }
		    Solution obj = new Solution();
		    head = obj.sort(head);
		    printList(head);
		}
	}
}

// } Driver Code Ends



/*
class Node {
    int data;
    Node next;
    
    public Node (int data){
        this.data = data;
        this.next = null;
    }
}
*/

class Solution {
    
  public Node sort(Node head){
        return separate(head); // sort the linked list by separating it into two parts
   }

   public Node separate(Node head){
   		Node head2 = null, tail2 = null, temp = head;
   		
   		while(temp != null && temp.next != null){
   			if(head2 == null){
   				head2 = temp.next; // head2 points to the next node of temp
   				tail2 = head2; // tail2 is updated to head2
   			} else {
   				tail2.next = temp.next; // update next node of tail2 to temp.next
   				tail2 = tail2.next; // tail2 is updated to the new tail
   			}
   			temp.next = temp.next.next; // skip next node of temp
   			temp = temp.next; // move temp to the next node
   		}
   		
   		if(head2 == null)
   		    return head; // if head2 is null, return head
   		    
   		tail2.next = null; // set the next node of tail2 to null
   		
   		tail2 = head2; // update tail2 to head2
   		head2 = reverse(head2); // reverse the second part
   		
   		temp = head;
   		
   		//head and tail of final list 
   		Node head3 = null, tail3 = null; // initialize head and tail of the final list
   		while(head != null && head2 != null){ // while both lists are not empty
   		    if(head.data < head2.data){ // if data of head is less than data of head2
   		        if(head3 == null){
   		            head3 = head; // set head3 to head
   		            tail3 = head3; // set tail3 to head3
   		        } else {
   		            tail3.next = head; // link tail3 to head
   		            tail3 = tail3.next; // update tail3 to the new tail
   		        }
   		        head = head.next; // move head to the next node
   		    } else {
   		        if(head3 == null){
   		            head3 = head2; // set head3 to head2
   		            tail3 = head3; // set tail3 to head3
   		        } else {
   		            tail3.next = head2; // link tail3 to head2
   		            tail3 = tail3.next; // update tail3 to the new tail
   		        }
   		        head2 = head2.next; // move head2 to the next node
   		    }
   		}
   		
   		while(head != null){
   		    tail3.next = head; // link tail3 to remaining nodes of head
   		    tail3 = tail3.next; // update tail3 to the new tail
   		    head = head.next; // move head to the next node
   		}
   		
   		while(head2 != null){
   		    tail3.next = head2; // link tail3 to remaining nodes of head2
   		    tail3 = tail3.next; // update tail3 to the new tail
   		    head2 = head2.next; // move head2 to the next node
   		}
   		
        tail3.next = null; // set the next node of tail3 to null
   		
   		return head3; // return the sorted linked list
   }
   
   public Node reverse(Node head){
       Node prev = null, curr = head, next = head; // initialize prev, curr, and next nodes
       while(curr != null){ // while curr is not null
           next = curr.next; // store the next node of curr
           curr.next = prev; // reverse the link of curr pointing to prev
           prev = curr; // move prev to curr
           curr = next; // move curr to next
       }
       return prev; // return prev as the new head of the reversed linked list
   }
   public void po(Object o){
   		System.out.println(o); // print the given object
   }


}
