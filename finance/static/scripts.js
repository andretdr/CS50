
async function updateMainBalance() { // assume loggedin
    let response = await fetch('/checktotal');
    let responset = await response.text();
    let responseObj = JSON.parse(responset);
    let balance = responseObj['balance'];

    document.querySelector("#accountbalance").innerHTML = balance.toFixed(2);
}

async function returnBalance() { // assume loggedin
    let response = await fetch('/checktotal');
    let responset = await response.text();
    let responseObj = JSON.parse(responset);

    return responseObj['balance'];
}

function buyStatus(str) {
    document.querySelector("#buystatus").innerHTML = str;
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

function sellSharesCheck(input, totalshares) { // returns 0 for ok, 1 for not enough funds, 2 for invalid input

    const pattern =  /^\d+$/;
    let n = 0;

    if ((pattern.test(input)) || (input == '')) {

        if (input != '')
            n = input;

        if (n <= totalshares)
            return "0";
        else
            return "1";
    }
    else
        return "2";
}

function sellTotalDisplay(price, n, totalshares) { // assume inputs are correct
    let total = price * n;
    if (n > totalshares) {
        document.querySelector("#selltotal").style.color = "red";
        }
    else {
        document.querySelector("#selltotal").style.color = "green";
    }
    document.querySelector("#selltotal").innerHTML = "Total Price :$ " + total.toFixed(2);
}


function sellCheckStatus(str) {
    document.querySelector("#sellcheckstatus").innerHTML = str;
}

function sellStatus(str) {
    document.querySelector("#sellstatus").innerHTML = str;
}

async function sell_updateSharesDisplay(argsym) {
    let reply = await fetch('/sellcheck?q=' + argsym);
    let replytxt = await reply.text();
    let replyobj = JSON.parse(replytxt);

    if (replyobj == null)
        currshares = 0;
    else
        currshares = replyobj['shares'];

    document.querySelector("#sellshares").innerHTML = `Shares Owned : ${currshares}`;
}

function update_historypage(argsym, argtrans, argprice, argshares, argdate, argtime) {

    let color = '';
    if (argtrans == 1)
    {
        buycode = 'BUY';
        color = 'green';
    }
    else
    {
        buycode = 'SELL'
        color = 'red';
    }

    html = `
            <tr>
                <td>${argsym}</td>
                <td style="color:${color};">${buycode}</td>
                <td>${argprice}</td>
                <td>${argshares}</td>
                <td>${argdate}</td>
                <td>${argtime}</td>



            `


}
