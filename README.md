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
