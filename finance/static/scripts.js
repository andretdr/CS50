
async function updateMainBalance() { // assume loggedin
    let response = await fetch('/checktotal');
    let responset = await response.text();
    let responseObj = JSON.parse(responset);

    document.querySelector("#accountbalance").innerHTML = responseObj['balance'];
}

async function returnBalance() { // assume loggedin
    let response = await fetch('/checktotal');
    let responset = await response.text();
    let responseObj = JSON.parse(responset);

    return responseObj['balance'];
}

function buyTotalDisplay(price, n, totalBalance) {
    let total = price * n;
    if (total > totalBalance) {
        document.querySelector("#buytotal").style.color = "red";
        }
    else {
        document.querySelector("#buytotal").style.color = "green";
    }
    document.querySelector("#buytotal").innerHTML = "Total Price :$ " + total.toFixed(2);
}

function buyValueCheck(unitprice, input ,totalBalance) {

    const pattern =  /^\d+$/;
    let n = 0;

    if ((pattern.test(input)) || (input == '')) {

        if (input != '')
            n = input;

        buyTotalDisplay (unitprice, n, totalbalance);
        
        document.querySelector("#buystatus").innerHTML = ""
    }
    else
        return = "Input must be strictly numeric"
}
