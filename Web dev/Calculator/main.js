const ans = document.getElementById('ans')

function display(input){
    ans.value+=input
}

function clearinput()
{

    ans.value='';
}

function calculate()
{
    try{
    ans.value= eval(ans.value)
    }
    catch{
        ans.value="Error"
    }
}
