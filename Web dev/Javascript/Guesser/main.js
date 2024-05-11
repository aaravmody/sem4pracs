var random=Math.floor(Math.random()*10)

function check(){
num=document.querySelector('#number').value
console.log(random)
msg=document.querySelector('.msg')
console.log(num)
if(parseInt(num)===random)
    {
        msg.innerHTML = "Good Work"
    }
    else{
        msg.innerHTML = "Not matched"
    }
    document.querySelector('#number').value=''
}