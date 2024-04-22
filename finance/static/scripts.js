
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

function buyValueCheck(price, n ,totalBalance) {

    const pattern =  /^\d+$/;

    if ((pattern.test(autoEl.value)) || (autoEl.value == '')) {

        if (autoEl.value == '')
            n = 0;
        else
            n = autoEl.value;
        let price = responseObj["price"];

        buyTotalDisplay (price, n, totalbalance);
        document.querySelector("#buystatus").innerHTML = ""
    }
    else
        document.querySelector("#buystatus").innerHTML = "Input must be strictly numeric"
}
