
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
    if total > totalBalance {
        document.querySelector("balance").style.color = "red";
        }
    else {
        document.querySelector("balance").style.color = "green";
    }
    document.querySelector("balance").innerHTML = total;
}
