// // 1.Ways to print
// console.log("Hello world");
// document.write("This is document write");

// // 2.Javascript console API
// console.log("Hello world",4+6,"Another log");
// console.warn("This is a warning");
// console.error("This is an error");

// // 3.Variables
// var number1=34;
// var number2=56;
// console.log(number1+number2);
// // Data types--->>>
// // There are 2 types of data types-
//     // 1.Primitive datatype: Undefined,null,number.string,boolen,symbol
//     // 2.Reference datatype: Arrays,objects
                
//             // 1.PRIMITIVE
//                 // a.Numbers
//                     var num1=34;
//                     var num2=56;
//                     console.log(num1+num2);

//                 // b.Strings
//                     var str1="This is a string";
//                     var str2='This is also a string';
//                     console.log(str1+",",str2);

//                 // c.Booleans
//                     var a=true;
//                     var b=false;
//                     console.log(a,b);
                
//                 // d.Undefined
//                     var un;
//                     console.log(un);
            
//             // 2.REFERENCE
                
//                 // a.Array
//                     var array=[1,2,"bablu",4,5];
//                     console.log(array);
                
//                 // b.Objects
//                     var marks={
//                         ravi:34,
//                         astu:99,
//                         harry: 78,
//                     }
//                     console.log(marks);
            
// function add (num,num2) 
// {
//     console.log(num+num2);
// }

// add(3,4);
        

// console.log(document.getElementById('my-form'))

// const ul = document.querySelector('.items')

// ul.firstElementChild.textContent='hello'

// const button = document.querySelector('.btn')

// button.style.background = 'red'

// button.addEventListener('click',(e)=>{e.preventDefault();
//     console.log('click');
    
//     document.querySelector('#my-form').style.background = 'blue'

//     document.querySelector('body').classList.add('bg-dark')


// }


// )

const myform = document.querySelector('#my-form')
const nameInput = document.querySelector('#name')
const emailInput = document.querySelector('#email')
const msg = document.querySelector('.msg')
const userList = document.querySelector('#users')

myform.addEventListener('submit',onsubmit);

function onsubmit(e){
    e.preventDefault();

    if(nameInput.value=='' || emailInput.value=='')
        {
            msg.classList.add('error')
            msg.innerHTML = "Please enter all"

        }
    else{
        console.log(`name ${nameInput.value} email ${emailInput.value}`)
        const li = document.createElement('li')
        li.appendChild(document.createTextNode(`name ${nameInput.value} email ${emailInput.value}`))

        userList.appendChild(li);
        nameInput.value=''
        emailInput.value=''
    }
}