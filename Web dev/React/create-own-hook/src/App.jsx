
import './App.css';
import useCustomHook from './useCustomHook';
function App() {
  const [count, {increment, decrement, reset}] = useCustomHook(0);
  return (
    <div className='container'>
    
  <div>
    <h1 className='count'>{count}</h1>
  </div>

  <div className='buttons'>
    <button className='button' id ='increment' onClick={increment}>Increment</button>
    <button className='button' id ='decrement' onClick={decrement}>Decrement</button>
    <button className='button' id ='reset' onClick={reset}>Reset</button>
  </div>
    </div>
  );
}

export default App;