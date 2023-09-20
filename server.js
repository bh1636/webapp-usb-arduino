const express = require('express');
const http = require('http');
const socketIo = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = socketIo(server);

const PORT = 3000;

app.use(express.static('public'));  // public klasöründeki statik dosyaları sunmak için

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/public/index.html');
});

io.on('connection', (socket) => {
    // Burada Bluetooth ile ilgili işlemleri gerçekleştirebilirsiniz.
    socket.on('setAngle', (angle) => {
        console.log(`Angle set to: ${angle}`);
        // Gerçek bir Bluetooth entegrasyonu için burada ek kodlar gerekebilir.
    });
});

server.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
