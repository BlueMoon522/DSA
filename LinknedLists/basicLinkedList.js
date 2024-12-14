//Singly linked list
class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}
class LinkedList {
  constructor() {
    this.head = null;
    this.size = 0;
  }
  //Insert In first node
  insertFirst(data) {
    this.head = new Node(data, this.head);
    this.size++;
  }
  //methods for linked LinkedList
  //Insert in last node//Append
  append(data) {
    let node = new Node(data);
    let current;
    if (!this.head) {
      this.head = node;
    } else {
      current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = node;
    }
    this.size++;
  }
  //Insert at index
  insertN(data, index) {
    //index out of range
    if (index > 0 && index > this.size) {
      return;
    }
    //if first index it is head
    if (index === 0) {
      this.head = new Node(data, this.head);
      return;
    }
    const node = new Node(data);
    let current, previous;
    //set current to first
    current = this.head;
    let count = 0;
    while (count < index) {
      previous = current; //Node before index
      count++;
      current = current.next; //Node after index
    }
    node.next = current;
    previous.next = node;
    this.size++;
  }
  //getAt Index and show current value
  getAtIndex() {
    let current = this.head;
    let count = 0;
    while (current) {
      if (count == index) {
        console.log(current.data);
      }
      count++;
      current = current.next;
    }
    return null;
  }
  //remove at index
  remove(index) {
    if (index > 0 && index > this.size) {
      return;
    }
    let current = this.head;
    let previous;
    let count = 0;
    //remove first
    if (index === 0) {
      this.head = current.next;
    } else {
      while (count < index) {
        count++;
        previous = current;
        current = current.next;
      }
      previous.next = current.next;
    }
    this.size--;
  }
  //clear the LinkedList
  clear() {
    //class only knows about the head,so just remove the head,linked list is deleted,but value is still in the memory,so delete it
    this.head = null;
    this.size = 0;
    console.log("Removed!!");
  }
  //Print the list data
  printListData() {
    let current = this.head;
    while (current) {
      console.log(current.data);
      current = current.next;
    }
  }
}

//creating alinked list
const ll = new LinkedList();

ll.insertFirst(100);
ll.append(700);
ll.insertN(500, 2);
ll.remove(2);
ll.clear();
ll.printListData();
