class MyArray{
  constructor(){
    this.lenght = 0;
    this.data = {};
  }

  get(index){
    if(index < 0 || index >= this.lenght){
      return -1;
    }
    return this.data[index];
  }

  push(item){
    this.data[this.lenght] = item;
    this.lenght++;
    return this.lenght;
  }

  pop(){
    if(this.lenght < 0){
      return -1;
    }
    const item = this.data[this.lenght -1];
    delete this.data[--this.lenght];
    return item;
  }

  delete(index){
    if(this.lenght < 0){
      return -1;
    }
    const item = this.data[index];
    this.shiftItems(index);
    return item;
  }

  shiftItems(index){
    for(let i = index; i < this.lenght-1; i++){
      this.data[i] = this.data[i+1];
    }
    delete this.data[--this.lenght]
  }
}

const newArray = new MyArray();
newArray.push("hi");
newArray.push("you");
newArray.push("!");
newArray.delete(0);
newArray.pop();
newArray.pop();
console.log(newArray);