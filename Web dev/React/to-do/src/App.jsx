import React, { useState } from 'react';
import './App.css';

function App() {
  const [todo, setTodo] = useState('');
  const [todoList, setTodoList] = useState([]);

  const handleInputChange = (event) => {
    setTodo(event.target.value);
  };

  const handleAddTodo = () => {
    if (todo.trim() !== '') {
      setTodoList([...todoList, { id: Date.now(), text: todo }]);
      setTodo('');
    }
  };

  const handleDeleteTodo = (id) => {
    const updatedTodoList = todoList.filter((todo) => todo.id !== id);
    setTodoList(updatedTodoList);
  };

  return (
    <>
      <h1>Todo List</h1>
      <label htmlFor="todoInput">Enter todo:</label>
      <input
        type="text"
        id="todoInput"
        value={todo}
        onChange={handleInputChange}
      />
      <button onClick={handleAddTodo}>Add Todo</button>
      <ul>
        {todoList.map((item) => (
          <li key={item.id}>
            {item.text}
            <button onClick={() => handleDeleteTodo(item.id)}>Delete</button>
          </li>
        ))}
      </ul>
    </>
  );
}

export default App;