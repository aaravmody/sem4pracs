function check(){
num=document.querySelector('#number').value
msg=document.querySelector('.msg')
console.log(num)
ans=0
ans=(9*num)/5 + 32
msg.innerHTML = `${ans} F`
}