var host = {
    address: "localhost",
    port: 3333
}

var dgram = require("dgram");
var udp_socket = dgram.createSocket("udp4");

//var ghosts = {};

udp_socket.on("message", (msg, remote_info) => {
    console.log("address :" + remote_info.address + ", port:" + remote_info.port);
    console.log(msg.toString());
    
    try {
        let packet = JSON.parse(msg.toString())
        let ghosts = theApp.io.ghosts
        ghosts[remote_info.address] = {
            x:packet.x,
            y:packet.y
        }
    }
    catch(e)
    {
        console.log(e);
    }
    
    
})

udp_socket.bind(host.port, () => {
    console.log('binding port ' + host.port);
    startRepl();
    _loop();
});


function _loop()
{
    let ghosts = theApp.io.ghosts


    
    
   // let _data =JSON.stringify(ghosts);
   let _data = [];

    for(var prop in ghosts) {
        _data.push(ghosts[prop]);
    }

    _data = JSON.stringify(_data);


    for(var prop in ghosts) {
        theApp.io.sendTo(_data,prop,3334);

    }
    setTimeout(_loop,500);
}



//



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
        sendTo: function (text,ip,port) {
            //var text = "hello udp!";
            udp_socket.send(Buffer(text),0, text.length, port,ip);
           // console.log('send text :' + text);
        
        },
        resetGhost : function() {
            this.ghosts = {};

        }
    }
    theApp = context;
}




