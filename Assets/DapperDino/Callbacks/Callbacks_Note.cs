using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
    Callbacks -> Just a function but its some specific function within Unity


    Every function has to be called by some other function. Main() functions 
    in pure C#, C++ etc. are called at the start. Similarly, there are some functions
    that Unity calls for you. Follow it all the way back and you
    get to the entry point. Unity Callbacks exist for you to run your code.
    Because without Callbacks, nothing would really happen lol.

    https://docs.unity3d.com/Manual/ExecutionOrder.html


*/
public class Callbacks_Note : MonoBehaviour
{

    private void Awake() {
        Debug.Log($"Awake: {name}");

        //Not really much of a difference between Awake and Start 
        //execution order

        //Awake is called when the component's GameObject is Active
        //Start is only called if the component is enabled
    }
    
    private void OnEnable() {
        Debug.Log($"OnEnable: {name}");
    }

    private void Start()
    {
        Debug.Log($"Start: {name}");

        //Called after Awake()
    }

    private void FixedUpdate() {
        Debug.Log($"FixedUpdate: {name}");

        //Used for physics logic due to being in sync with the physics engine
        //Not called every frame 

    }

    private void Update()
    {
        Debug.Log($"Update: {name}");

        //Used to run logic every single frame
        //Logic that needs to be updated 
    }

    private void LateUpdate() {
        Debug.Log($"LateUpdate: {name}");

        //Called after Update(). Whenever we have code that reacts to 
        //some change in Update(), do it in LateUpdate(). Player Follow Camera?
        //Use LateUpdate. It needs to react to where the player is looking.
        //similar to Awake and Start
    }

    private void OnDisable() {
        Debug.Log($"OnDisable: {name}");

        //Called every time you Disable script component.
        //OnEnable and OnDisable are recommended to be used for subscribing 
        //to events
    }

    private void OnDestroy() {
        Debug.Log($"OnDestroy: {name}");
    }
}
