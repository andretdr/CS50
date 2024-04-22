
updateMainBalance() { // assume loggedin
    let response = await fetch('/checkbalance');
    let responset = await response.text();
    let responseObj = JSON.parse(responset);
    console.log(responseObj['balance']);
//    document.querySelector("accountbalance").innerHTML =

}

