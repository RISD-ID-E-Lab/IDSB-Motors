const express = require('express')
const bodyParser = require('body-parser')
const app = express()
const port = process.env.PORT || 4000;

app.use(bodyParser.urlencoded({extended: false}));

app.use((req, res, next) => {
    console.log(req.method, " ", req.path, " ", req.ip);
    next();
  })

let angle  = 90;

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.get('/angle', (req, res) => {
    res.send(angle.toString());
})

app.get('/set/:angle', (req, res) => {
    angle = req.params.angle
    console.log("angle set to: " + angle)
    res.send(angle.toString())
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})