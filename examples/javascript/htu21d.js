/* Author: John van Drasek <john.r.van.drasek@intel.com>
* Copyright (c) 2015 Intel Corporation.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

var htu21d = require('jsupm_htu21d')

var sensor = new htu21d.HTU21D(0);

sensor.testSensor();
setInterval(function()
{
    compRH = sensor.getCompRH(1);
    sensor.sampleData();
    humidity = sensor.getHumidity();
    temperature = sensor.getTemperature();

    console.log("humidity value = " + humidity);
    console.log("temperature value = " + temperature);
    console.log("compensated RH value = " + compRH);
    console.log(""); 
}, 1000);

// Print message when exiting
process.on('SIGINT', function()
{
    console.log("Exiting...");
    process.exit(0);
});
