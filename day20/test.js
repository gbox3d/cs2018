var host = {
    address: "localhost",
    port: 3334
}

var dgram = require("dgram");
var udp_socket = dgram.createSocket("udp4");

//var ghosts = {};

udp_socket.on("message", (msg, remote_info) => {
    console.log("address :" + remote_info.address + ", port:" + remote_info.port);
    console.log(msg.toString());
    
    
})

udp_socket.bind(host.port, () => {
    console.log('binding port ' + host.port);
    startRepl();
});




//repl 
var repl = require('repl');
var theApp;

function startRepl() {

    var context = repl.start({
        prompt: 'input cmd>',
        input: process.stdin,
        output: process.stdout
    }).context;

    context.io = {
        ghosts : {},
        test: function () {
            console.log('test');
        },
        sendTest: function (x,y,ip) {
            //var text = "hello udp!";
            let _text = JSON.stringify({x:x,y:y});
            udp_socket.send(Buffer(_text),0, _text.length, 3333,ip);
            console.log('send text :' + _text);
        
        }
    }
    theApp = context;
}
