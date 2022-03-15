
const { os } = Deno.build;


export default function systemInfo(){
    switch(os){
    case 'linux' : return {
        libraryType : 'so' ,
        device : '/dev/ttyUSB0'
    };
    case 'windows': return {
        libraryType : 'dll' ,
        device : 'COM0'
    };
    case 'darwin' : return {
        libraryType : 'dylib' ,
        device : ''
    };
    default:
        throw `Unknown System : ${ os }`;
    }
}
