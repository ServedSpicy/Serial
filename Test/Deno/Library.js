
import SystemInfo from './SystemInfo.js';
import Definitions from './Definitions.js';

const { dlopen } = Deno;

const { libraryType } = SystemInfo();


const path = `./Build/Serial.${ libraryType }`;
const library = dlopen(path,Definitions);


export default library.symbols;
