//Basic types
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var id = 5;
var company = "Web dev";
var x = 'Hello';
var ids = [1, 2, 3, 4, 5];
var arr = [1, true, "Hello"];
//Tuple
var person = [1, 'Aarav', true];
var employee;
employee = [
    [1, 'Aarav'],
    [2, 'John']
];
//UNION
var pid;
pid = '22';
//Enum
var Direction;
(function (Direction) {
    Direction[Direction["up"] = 1] = "up";
    Direction[Direction["down"] = 2] = "down";
    Direction[Direction["right"] = 3] = "right";
    Direction[Direction["left"] = 4] = "left";
})(Direction || (Direction = {}));
console.log(Direction.up);
var user = {
    id: 1,
    name: "Aarav"
};
//Type Assertion
var cid = 2;
var customerId = cid;
//Functions
function add(x, y) {
    return x + y;
}
console.log(add(1, 2));
function log(message) {
    console.log(message);
}
var User1 = {
    id: 2,
    name: "Aarav"
};
User1.id = 5;
var p1 = 1;
var addition = function (x, y) { return x + y; }; //basicalyy yeh dono interface h like java same 
var subtraction = function (x, y) { return x - y; };
//Classes
var Person = /** @class */ (function () {
    function Person(id, name) {
        this.id = id;
        this.name = name;
    }
    return Person;
}());
var aarav = new Person(1, 'aarav mody');
console.log(aarav);
aarav.id = 5;
console.log(aarav);
//extend class
var Employee = /** @class */ (function (_super) {
    __extends(Employee, _super);
    function Employee(id, name, position) {
        var _this = _super.call(this, id, name) || this;
        _this.position = position;
        return _this;
    }
    return Employee;
}(Person));
var emp = new Employee(3, 'David', 'Webdev');
console.log(emp.name);
console.log(emp.position);
