
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

function buyTotalDisplay(price, n, totalBalance) { // assume inputs are correct
    let total = price * n;
    if (total > totalBalance) {
        document.querySelector("#buytotal").style.color = "red";
        }
    else {
        document.querySelector("#buytotal").style.color = "green";
    }
    document.querySelector("#buytotal").innerHTML = "Total Price :$ " + total.toFixed(2);
}

function buyValueCheck(unitprice, input ,totalbalance) { // returns 0 for ok, 1 for not enough funds, 2 for invalid input

    const pattern =  /^\d+$/;
    let n = 0;

    if ((pattern.test(input)) || (input == '')) {

        if (input != '')
            n = input;

        if (unitprice * n <= totalbalance)
            return "0";
        else
            return "1";
    }
    else
        return "2";
}
