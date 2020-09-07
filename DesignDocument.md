# Design Document


## Integration with DirectX or another back-end
- Do the actual integration in C++/CLR
- Do the abstractions in C#
- Provide only interfaces and use DI/factories to create the concrete classes. So the back-end can be decided at runtime.
    - Model the abstraction closely to DirectX because its probably infeasible to create anything else.


## Game loop

- Seperate Render and Logic loop. Both should be able to run at a different frequency. The render loop should take the entities from the logic loop and interpolate their state. This is probably easiest by being 1 tick later. However that would introduce extra delays.