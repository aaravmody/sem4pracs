message=document.querySelector('.msg')
message.innerHTML= "submitted"

msg=''
for(i=0;i<16;i++)
    {
        if(i%2==0)
            {
              msg+=`${i} is even <br>` 
            }
        else{
            msg+=`${i} is odd <br>`
        }
    }
message.innerHTML = msg