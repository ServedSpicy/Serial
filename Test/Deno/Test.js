
const { log } = console;


log('Testing Serial FFI');


import Serial from './Library.js';
import SystemInfo from './SystemInfo.js';


const { device } = SystemInfo();


log(`Setting Up Test`);



function toChars(string){
    return [...string];
}

function toBytes(string){
    return toChars(string)
        .map((char) => char.codePointAt(0));
}


const teststring = `Hello Worl4`;
const charCount = teststring.length;
const byteCount = charCount + 3;

const bytes = [
    byteCount >> 4 ,
    byteCount & 255 ,
    charCount ,
    ...toBytes(teststring)
];


log('Bytes :',bytes);
log('Device :',device);


const exitCode = await Serial.synchronize(
    new Uint8Array(toBytes(device)),
    new Uint8Array(bytes),
    byteCount);


switch(exitCode){
case  1 : log(`Success`);           break;
case  0 : log(`Unknown Error`);     break;
case -1 : log(`Timeout`);           break;
case -2 : log(`Machine Not Ready`); break;
}
