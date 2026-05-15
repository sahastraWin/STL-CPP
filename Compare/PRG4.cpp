/*
// check if all elements are equal
if (all_of(a.begin(), a.end(), [&](int x) { return x == a[0]; }))
    break;
🔍 Explanation
all_of(a.begin(), a.end(), ...)

This is a C++ STL algorithm from <algorithm>.

It checks whether all elements in the range [a.begin(), a.end()) satisfy a condition (predicate).

Returns:

true → if all elements satisfy the condition.

false → otherwise.

[&](int x) { return x == a[0]; }

This is a lambda function (an inline anonymous function).

It takes each element x from the array a and checks if it is equal to the first element a[0].

The [&] means the lambda captures variables by reference (so it can use a[0]).

Putting it together:

The lambda checks if every element x in a is equal to a[0].

If this is true, it means all elements of the array are equal.

if (...) break;

If the condition is true (all elements equal), we break out of the loop.

That means the process of making all elements equal is complete.

✅ Example
cpp
Copy code
a = [5, 5, 5];
all_of(a.begin(), a.end(), [&](int x) { return x == a[0]; })

Checks: 5 == 5, 5 == 5, 5 == 5

All true → returns true

Loop breaks.

cpp
Copy code
a = [5, 4, 5];
Checks: 5 == 5 (true), 4 == 5 (false), 5 == 5 (true)

Since one element is false, result = false

Loop continues.

👉 In short:
This line is a compact way to check if all elements in the array are equal to the first element.

Do you want me to also show you how to write the same check manually with a simple for loop (without all_of)?

Using a for loop
cpp
Copy code
bool allEqual = true;   // assume all are equal
for (int i = 1; i < n; i++) {
    if (a[i] != a[0]) { // if any element differs from the first
        allEqual = false;
        break;
    }
}

if (allEqual)
    break;   // exit the loop if all elements are equal
🔍 Step-by-step
Start by assuming all elements are equal → allEqual = true.

Compare every element a[i] with the first element a[0].

If any element differs, set allEqual = false and break early (no need to check further).

After the loop:

If allEqual == true, it means every element matched → break out of the while loop.

Otherwise, continue the process.

✅ This loop does exactly what

all_of(a.begin(), a.end(), [&](int x) { return x == a[0]; })
was doing, but in a more beginner-friendly, explicit way.
*/