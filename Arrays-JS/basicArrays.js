//Some basic array operations
//lookup 0(1)
//push 0(1)
//insert O(n)
//delete O(n)
//
//you can change strings to arrays of using split method(can split based on certain conditions) on the string
//you can change strings to arrays using split("") method on the string

//dynamic arrays copy the whole array in the new location,so basically all of these become O(n).But operations themselves happen at their time
//time complexity
const strings = ["a", "b", "c", "d"];
strings[2]; //item in index 2

//push-> add at to the end of the array
strings.push("e");

//pop -> remove the end of the array
strings.pop(); //O(1)

//unshift -> add x at the beginning of the array
strings.unshift("x"); //O(n)

//splice -> add at the index postion
strings.splice(2, 0, "4"); //O(n)//splice(start index,remove the x amount of elements from the current index,Things (can be multiple) to add at the index position)

console.log(strings);

//creating our own array
//unnecessary but good to know
class myArray {
  //constructor get called initially after the class has been invoked
  constructor() {
    this.length = 0; //initial lenth of array will be zero
    this.data = {}; //data is an object,array will be empty initially
  }
  get(index) {
    return this.data[index];
  }

  //creating a push method for our array
  push(item) {
    this.data[this.length] = item; //setting the value of item to this.data
    this.length++; //once the data is inserted increase the lenth of the array
  }
  //pop method for our array
  pop() {
    delete this.data[this.length - 1]; //deleting the length -1 th item
    this.length--;
  }
  //delete method for the array
  delete(index) {
    this.data[index];
    this.shiftItem(index); //shift the item after deletion
  }

  shiftItem(index) {
    for (let i = index; i < this.length - 1; i++) {
      this.data[i] = this.data[i + 1];
    }
    //this is necessary Because we are moving all the value one index up,but the last value will still be there after deletion and the previous before the last will be the value of the last element in an array.So at the end ,we need to delete the last element,to prevent multiple last element
    delete this.data[this.length - 1];
    this.length--;
  }
}

const newArray = new myArray();
newArray.push("6");
newArray.push("8");
console.log(newArray);
newArray.pop();
console.log(newArray);

//Reversing the string

function reverseString(str) {
  //check input
  if (!str || str.length < 2 || undefined || typeof str !== "string") {
    return null;
  }
  let reverse = [];
  const length = str.length - 1;
  for (i = length; i >= 0; i--) {
    reverse.push(str[i]); //u can actually just use strings as any array,can use almost all the same methods on it
  }

  return reverse.join(""); //join all the elements in an array
}

//same thing using methods
function reverseEasy(str) {
  return str.split("").reverse().join("");
}

let string = "string";
const reverse = reverseString(string);
const reverse2 = reverseString(string);
console.log("reverse", reverse);
console.log("reverse", reverse2);
console.log("reverse", reverseNext(string));
