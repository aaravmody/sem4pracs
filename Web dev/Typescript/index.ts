//Basic types

let id: number =5
let company: string = "Web dev"
let x:any = 'Hello'

let ids:number[] = [1,2,3,4,5]
let arr: any[] = [1,true,"Hello"]

//Tuple
let person : [number,string,boolean] = [1,'Aarav',true]

let employee : [number,string][]

employee = [
    [1,'Aarav'],
    [2,'John']
]

//UNION

let pid:number|string 
pid='22'

//Enum

enum Direction{
    up=1,down,right,left
}

console.log(Direction.up)

//Object

type User = {
    id:number,name:string
}

const user: User ={
    id:1,
    name:"Aarav"
}

//Type Assertion
let cid: any =2
let customerId = cid as number

//Functions
function add(x:number,y:number) :number
{
    return x+y
}

console.log(add(1,2))

function log(message:string | number) : void {
    console.log(message)
}

//Interfaces
interface UserInterface {
    id: number,
    name: string,
    age?:number
}

const User1: UserInterface = {
    id: 2,
    name: "Aarav"
}

User1.id = 5

type point = number | string
const p1: point = 1


interface Mathfunc{
    (x:number, y:number): number
}

const addition: Mathfunc = (x: number, y:number) => x+y     //basicalyy yeh dono interface h like java same 
const subtraction: Mathfunc = (x: number, y:number) => x-y    

//Classes

class Person{
    id: number  //public,private,protected ...java jaisa daal sakte h id ya kisike b aage
    name: string

    constructor(id: number, name:string)
    {
        this.id = id
        this.name = name
    }
}

const aarav = new Person(1,'aarav mody')
console.log(aarav)

aarav.id=5
console.log(aarav)

//extend class
class Employee extends Person{
    position:string

    constructor(id:number, name:string, position:string)
    {
        super(id,name)
        this.position=position
    }
}

const emp = new Employee(3,'David','Webdev')
console.log(emp.name)
console.log(emp.position)
