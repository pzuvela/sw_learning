# Contributing

This project favors simple, readable, maintainable, and testable code over clever or unnecessarily complex solutions.

The following principles should guide implementation, review, refactoring, and testing decisions.

## 1. Prefer Simplicity

**Simple is better than unnecessarily complex.**

Use the simplest design that correctly solves the current problem. Introduce additional abstractions, patterns, layers, or infrastructure only when they solve a concrete problem.

Prefer:

- Direct calls over unnecessary indirection.
- Standard-library functionality over custom implementations.
- Simple data structures over elaborate abstractions.
- Straightforward control flow over clever code.
- A plain function or class over a design pattern when no pattern is needed.

Follow the principles of **KISS** and **YAGNI**.

Complexity must justify itself.

Do not build functionality merely because it may be useful in the future.

## 2. Keep Responsibilities Focused

Methods and classes should have clear, focused responsibilities.

A method should ideally be describable with one concise sentence. If a method performs several conceptually different operations, consider separating those responsibilities.

Prefer:

```cpp
bool ProcessEngine::run(Wafer& wafer, const Recipe& recipe)
{
    if (!moveToProcessModule(wafer))
        return false;

    if (!processWafer(wafer, recipe))
        return false;

    return moveToOutput(wafer);
}
```

over a single method containing movement, processing, logging, persistence, error recovery, statistics, notifications, and other unrelated responsibilities.

Do not refactor solely because a method exceeds an arbitrary number of lines. A longer cohesive method may be easier to understand than many tiny methods requiring constant navigation between files.

Refactor when responsibilities become unclear or mixed.

## 3. Write Self-Explanatory Code

Code should explain **what** it does.

Comments should explain **why** it does it.

Avoid comments that merely repeat the code.

Do not write:

```cpp
// Initialize the robot
robot.initialize();

// Update wafer location
wafer.location = destination;
```

Prefer comments that capture design intent, constraints, non-obvious decisions, or important invariants:

```cpp
// Update software state only after the physical move succeeds
// so it never gets ahead of the equipment state.
if (robot.moveWafer(wafer, destination))
{
    wafer.location = destination;
}
```

If code requires a comment simply to explain what a variable, method, or block of code does, first consider improving the names or structure.

## 4. Prefer Descriptive Names

Prefer full, descriptive names over abbreviations.

Prefer:

```cpp
processModule
destination
processResult
waferLocation
processEngine
```

over:

```cpp
pm
dest
procRes
wLoc
pe
```

Names should make the purpose of the code clear without requiring explanatory comments.

Well-established technical or domain terminology may remain abbreviated when the abbreviation itself is the conventional name, for example:

```text
API
ID
FOUP
```

Avoid inventing project-specific abbreviations merely to save characters.

## 5. Keep Tests Focused

Each unit test should verify **one clear behavior**.

Use the **Arrange, Act, Assert (AAA)** structure where appropriate:

```cpp
TEST(SimProcessModuleTest, IsReadyAfterInitialization)
{
    // Arrange
    SimProcessModule module;

    // Act
    module.initialize();

    // Assert
    EXPECT_TRUE(module.isReady());
}
```

The comments above are useful while learning or where they clarify test structure, but they do not need to be mechanically added to every obvious test.

Test behavior and contracts rather than implementation details.

## 6. Limit Assertions per Test

Aim for **no more than three meaningful assertions per test**.

This is a guideline rather than an absolute rule, but a large number of assertions is usually a signal worth investigating.

If a test requires more than three assertions, consider whether to:

1. Split the test into multiple tests covering separate behaviors.
2. Parameterize the test when the same behavior needs verification across multiple inputs.
3. Refactor the underlying method or class if it has accumulated too many responsibilities.

A small number of related assertions describing a single outcome is acceptable.

For example:

```cpp
EXPECT_TRUE(result);
EXPECT_EQ(wafer.location.station, Station::Aligner);
EXPECT_EQ(wafer.location.slot, 1);
```

can reasonably represent one behavior.

## 7. Parameterize Repeated Behavior

Use parameterized tests when the **same behavior** must be verified against multiple inputs or scenarios.

Do not use parameterization merely to reduce line count.

If the scenarios represent fundamentally different behaviors, separate tests are clearer.

## 8. Preserve Clear Ownership and State

Make ownership and responsibility for state changes explicit.

A component should not modify state that belongs to another layer merely because it has access to that state.

For example, a robot may execute a physical wafer movement and report whether it succeeded:

```cpp
bool moveWafer(
    const Wafer& wafer,
    const Location& destination);
```

The component coordinating the operation is responsible for updating the software representation of the wafer location after successful movement.

This preserves the invariant that software state must not claim a physical operation succeeded when it did not.

## 9. Prefer Interfaces at Component Boundaries

Components should depend on abstractions where multiple implementations or test substitutes are useful.

For example:

```cpp
class ProcessEngine
{
private:
    IRobot& robot_;
};
```

allows the process engine to operate with a simulator, real hardware implementation, or test double without changing the engine itself.

Do not create interfaces purely for abstraction's sake. Introduce them where they establish a useful component boundary or provide meaningful substitutability.

## 10. Prefer Standard Resource Management

Prefer RAII and standard C++ resource-management facilities.

Use standard containers and smart pointers rather than manual memory management whenever practical.

Prefer:

```cpp
std::vector
std::string
std::unique_ptr
std::shared_ptr
```

over manually managing equivalent resources.

Follow the **Rule of Zero** where possible.

Manual resource ownership and Rule-of-Five implementations should exist only when there is a concrete reason for them.

## 11. Optimize for Maintainability

Code is read far more often than it is written.

Prefer code that another engineer can understand, debug, test, and modify safely.

When choosing between two correct solutions, favor the one that is:

- Simpler.
- More explicit.
- Easier to test.
- Easier to debug.
- Less surprising.
- Clearer about ownership and responsibility.

Avoid cleverness for its own sake.

---

## Guiding Principle

When uncertain, choose the design that makes the intent obvious.

**Simple. Focused. Explicit. Readable. Testable.**