<div align="center">
<img height="200" src="https://static.studytonight.com/css/resource.v3/icons/subject/logo-ds.svg">
</div>

<div align="center">
    <h1 align='center'>⚡️<i>Datastructures</i>⚡️</h1>
    <p> A practice on datastructures course provided by <b>Dr.Mostafa Saad</b> </p>
    <a target="_blank" href="https://www.udemy.com/course/dscpp-skills/">Course on Udemy</a>
</div>

<h2 style="display:inline">📝 Table of Contents</h2>

- 📑 About
- ⛏️ Current DSs
- 🕵️‍♂️ DSs implementations
- ✍️ Contributors
- 🔒 License

---

## 📑 About

- This repo is a practice on datastructures implementations and some challenges.

- Implemented using C++17

---

## ⛏️ Current DSs

- <a href="#vector"> Vector </a>
- <a href="#sll"> Singly LinkedList (SLL) </a>
- <a href="#dll"> Doubly LinkedList (DLL) </a>
- <a href="#sparse-arr"> Sparse Array using (DLL) </a>
- <a href="#sparse-mat"> Sparse Matrix using (DLL) </a>

---

## 🕵️‍♂️ DSs implementations

<section id="vector">
  <h2 style="font-size: 25px; font-weight: 500"> Vector </h2>
  <h3>Description</h3>
  <div style="background-color: #1c1b19; padding: 15px; font-size: 15px; font-weight: 500">This is the vector (array-based) implementation</div>
  <h3>Features</h3>
  <ul style="background-color: #1c1b19;  font-size: 15px; font-weight: 500">
    <li>
      <code>int find(int value):</code>
      <span>find the value in the array in <b>O(n)</b></span>
    </li>
    <li>
      <code>void push_back(int value):</code>
      <span>pushes the value in the array in <b>O(1)</b></span>
    </li>
    <li>
      <code>void rotateRight():</code>
      <span>rotate right the array in <b>O(n)</b></span>
    </li>
    <li>
      <code>void rotateRightMultipleOfTimes(int k):</code>
      <span>rotate right the array k-number of times in <b>O(n)</b></span>
    </li>
    <li>
      <code>void rotateLeft():</code>
      <span>rotate left the array in <b>O(n)</b></span>
    </li>
    <li>
      <code>int pop(int idx):</code>
      <span>delete the element at position (idx) from the array <b>O(n)</b></span>
    </li>
    <li>
      <code>void expand_capacity():</code>
      <span>a private funciont to expand the capacity of the array for some performance issues <b>O(n)</b></span>
    </li>
  </ul>
</section>

---

<section id="sll">
  <h2 style="font-size: 25px; font-weight: 500"> Single Linked List </h2>
  <h3>Description</h3>
  <div style="background-color: #1c1b19; padding: 15px; font-size: 15px; font-weight: 500">This is the single linked list consisting from list of nodes connected togther using <em>next pointer</em></div>
  <h3>Features</h3>
  <ul style="background-color: #1c1b19;  font-size: 15px; font-weight: 500">
    <li>
      <code>struct Node:</code>
      <span>this is the building component of the linked list <b>has data and pointer to the next node</b></span>
    </li>
    <li>
      <code>void insertNode(int val):</code>
      <span>insert a value at the end of the list in <b>O(n)</b></span>
    </li>
    <li>
      <code>void insertFront(int val):</code>
      <span>insert a value at the beginning of the list in<b>O(1)</b></span>
    </li>
    <li>
      <code>void deleteFront():</code>
      <span>delete the first element in the list in <b>O(1)</b></span>
    </li>
    <li>
      <code>Node* get_nth_fromBack(int n):</code>
      <span>get the element number(n) from bakck in <b>O(n)</b></span>
    </li>
    <li>
      <code>Node* get_nth(int n):</code>
      <span>get the element number(n) from forward in <b>O(n)</b></span>
    </li>
    <li>
      <code>bool isSame(LinkedList& other):</code>
      <span>compare two linked lists are they the same or not in <b>O(n)</b></span>
    </li>
    <li>
      <code>int search(int val):</code>
      <span>search for a value in the list in <b>O(n)</b></span>
    </li>
    <li>
      <code>delete_node_with_key(int val):</code>
      <span>delete the first node with the specified value in <b>O(n)</b></span>
    </li>
    <li>
      <code>void reverse():</code>
      <span>reverse the list in <b>O(n)</b></span>
    </li>
    <li>
      <code>void rotateLeft():</code>
      <span>rotate left the list in <b>O(n)</b></span>
    </li>
    <li>
      <code>void arrangeOddEvenNodes():</code>
      <span>make the nodes that its position is odd, then the even ones in <b>O(n)</b></span>
    </li>
    <li>
      <code>void delete_even_positions():</code>
      <span>delete the nodes that are in even positions in <b>O(n)</b></span>
    </li>
    <li>
      <code>void insertToBeSorted(int val):</code>
      <span>insert a value in the list and still the list is sorted in <b>O(n)</b></span>
    </li>
    <li>
      <code>void addHugeNumber(LinkedList& l, LinkedList& sum):</code>
      <span>represent numbers as a linked list but with reverse order; the first node represents the ones, second represents tens and so on...,
      then add the two numbers in <b>O(n)</b></span>
    </li>
  </ul>
</section>

---

<section id="dll">
  <h2 style="font-size: 25px; font-weight: 500"> Double Linked List </h2>
  <h3>Description</h3>
  <div style="background-color: #1c1b19; padding: 15px; font-size: 15px; font-weight: 500">This is the doubly linked list consisting from list of nodes connected togther using <em>next pointer</em> and <em>previous pointer</em></div>
  <h3>Features</h3>
  <ul style="background-color: #1c1b19;  font-size: 15px; font-weight: 500">
    <li>
      <code>struct Node:</code>
      <span>this is the building component of the linked list <b>has data, pointer to the prevous node and pointer to the next node</b></span>
    </li>
    <li>
      <code>void link(Node* first, Node*second):</code>
      <span>link the two nodes through the pointers</b></span>
    </li>
    <li>
      <code>void insert_end(int val):</code>
      <span>insert a value at the end of the list in<b>O(1)</b></span>
    </li>
    <li>
      <code>void insert_front(int val):</code>
      <span>insert a value at the beginning of the list in<b>O(1)</b></span>
    </li>
    <li>
      <code>void delete_front():</code>
      <span>delete the first element in the list in <b>O(1)</b></span>
    </li>
    <li>
      <code>void delete_end():</code>
      <span>delete the last element in the list in <b>O(1)</b></span>
    </li>
    <li>
      <code>void delete_node_with_key(int val):</code>
      <span>delete the first node with the specified value in <b>O(n)</b></span>
    </li>
    <li>
      <code>void swap_forward_backward(int k):</code>
      <span>Swap the first element and the last element<b>O(1)</b></span>
    </li>
    <li>
      <code>void insert_sorted(int value):</code>
      <span>insert a value in the list and still the list is sorted in <b>O(n)</b></span>
    </li>
    <li>
      <code>Node* find_middle():</code>
      <span>Find the middle of the list in <b>O(n)</b></span>
    </li>
  </ul>
</section>

---

<section id="sparse-arr">
  <h2 style="font-size: 25px; font-weight: 500"> Sparse Array </h2>
  <h3>Description</h3>
  <ul style="background-color: #1c1b19; padding: 15px; font-size: 15px; font-weight: 500">
    <li>In some applications, we might want to represent an array with indices very 
huge (e.g. 10^8), however, most of it are just zeros (e.g. 95%)
 `</li>
  <li>
    Creating such huge arrays is very time & memory harmful with no return
  </li>
  <li>
    A better idea is to represent such arrays using a linked list
  </li>
  <li>
    A useful application: Polynomial representation (e.g. 2X<sup>60</sup> + 17X<sup>1500</sup>)
  </li>
  </ul>
  <h3>Features</h3>
  <ul style="background-color: #1c1b19;  font-size: 15px; font-weight: 500">
    <li>
      <code>struct Node:</code>
      <span>this is the building component of the linked list <b>has data, index that represents the position of the element in the array, pointer to the prevous node and pointer to the next node</b></span>
    </li>
    <li>
      <code>void  set(int val, int index):</code>
      <span>link the two nodes through the pointers</b></span>
    </li>
    <li>
      <code>int get(int index):</code>
      <span>get the element int the given index</span>
    </li>
    <li>
      <code>void add(ArrayLinkedList& arr):</code>
      <span>Add the two arrays like adding two polynomials with different powers</span>
    </li>
    <li>
      <code>void print():</code>
      <span>Print the array</span>
    </li>
  </ul>
</section>

---

<section id="sparse-mat">
  <h2 style="font-size: 25px; font-weight: 500"> Sparse Matrix </h2>
  <h3>Description</h3>
  <ul style="background-color: #1c1b19; padding: 15px; font-size: 15px; font-weight: 500">
    <li>A more severe/common case is a sparse matrix where most of it are zeros
 `</li>
  <li>
    Similarly, we will implement SparseMatrix to act like 2D array
  </li>
  <li>
    Design wise:
    <ul>
      <li>Each row in the sparse matrix, is what we actually implemented in the 1D case</li>
      <li>Now we can think of sparse matrix as linked list of linked list</li>
      <li>
        <ul>
          <li>2 linked lists</li>
          <li>First: the 1D array linked list</li>
          <li>Second: linked list, the data of each node is a 1D linked list</li>
          <li>Again use a doubly linked list
</li>
        </ul>
      </li>
    </ul>
  </li>
  </ul>
  <h3>Features</h3>
  <ul style="background-color: #1c1b19;  font-size: 15px; font-weight: 500">
    <li>
      <code>struct MatrixRow:</code>
      <span>this is the building component of the Sparse Matrix <b>has ArrayLinkedList to represent the data in the row, rowIndex that represents the position of the row in the matrix, pointer to the prevous row and pointer to the next row</b></span>
    </li>
    <li>
      <code>void  set(int val, int index):</code>
      <span>link the two nodes through the pointers</b></span>
    </li>
    <li>
      <code>int get(int index):</code>
      <span>get the element int the given index</span>
    </li>
    <li>
      <code>ArrayLinkedList add(SparseMatrix& mat) :</code>
      <span>Add the two Matricies and save the result to the current matrix</span>
    </li>
    <li>
      <code>void print():</code>
      <span>Print the matrix</span>
    </li>
  </ul>
</section>

---

## ✍️ Contributors

<table>
  <tr>

<td align="center">
<a href="https://github.com/ahmedasad236" target="_black">
<img src="https://avatars.githubusercontent.com/u/68563546" width="150px;" alt="Ahmed Asaad"/><br /><sub><b>Ahmed Asaad</b></sub></a><br />
</td>

</tr>
 </table>

---
