
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

async function buyTotalDisplay() {
    let totalprice = responseObj["price"]*autoEl.value;
    document.querySelector("#buytotal").innerHTML = "Total Price : $" + totalprice.toFixed(2);



}