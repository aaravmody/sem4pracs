username=document.querySelector('#name')
dob=document.querySelector('#dob')
address=document.querySelector('#address')
email=document.querySelector('#email')
contact=document.querySelector('#contact')
form=document.querySelector('.form')
msg=document.querySelector('.msg')


form.addEventListener('submit',onsubmit)

function onsubmit(e){
    e.preventDefault();
    if(contact.value.length!=10)
        {
            alert('Contact not 10 numbers')
        }
    if(username.value.length<3)
        {
            alert('name cannot be less than 3 letters')
        }
    console.log('submitted')
    username.value=''
    dob.value=''
    address.value=''
    email.value=''
    contact.value=''

    msg.innerHTML= "submitted"
}