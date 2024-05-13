import { useState } from 'react'
import './App.css'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <h1>Counter app</h1>
      <h2>count is {count}</h2>
      <div className="card">
        <button className='inc' onClick={() => setCount((count) => count + 1)}>
          increment
        </button>
        <button className='dec' onClick={() => setCount((count) => count - 1)}>
          decrement
        </button>
        <button className='reset' onClick={() => setCount((count) => 0)}>
          reset
        </button>
      </div>
    </>
  )
}

export default App
