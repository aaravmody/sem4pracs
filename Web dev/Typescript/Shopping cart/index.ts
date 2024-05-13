interface Shopping {
    (): void;
}

const initialValue = 0; // Initialize a variable
let currentValue = initialValue; // Track the current value

const ans = document.querySelector("#ans") as HTMLElement;

if (ans) {
    ans.innerHTML = String(initialValue); // Display the initial value
}

const up: Shopping = () => {
    currentValue++;
    if (ans) {
        ans.innerHTML = String(currentValue); // Update the displayed value
    }
};

const down: Shopping = () => {
    if(currentValue==1)
        {
            if (ans) {
                ans.innerHTML = String("Cart empty"); // Update the displayed value
            }

        }
        else{
    currentValue--;
    if (ans) {
        ans.innerHTML = String(currentValue); // Update the displayed value
    }}
};
