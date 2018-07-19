const http = require("http");

const server = http.createServer((req, res) => {

    res.statusCode = 200;
    res.setHeader("Content-Type", "text/plain");
    res.end("Hello nodejs! it is leeseokjun server.\n");

});

server.listen(8080, "14.55.207.250", () => {
    console.log("server is running..");

});