
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
