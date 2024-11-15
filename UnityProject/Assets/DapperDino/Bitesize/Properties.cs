using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Properties : MonoBehaviour
{
    //fields are just variables, properties are similar to fields


    //Auto-property: both get and set
    public int Health { get; set; }

    //only read and not write
    public int Health2 { get; }
    //public get, but private set, private set -> set only internally within class
    public int Health3 { get; private set; }


    //Backing-field: property that doesnt act as a value storer, but acts as a
    //way to interact with a value

    private int speed;

    public int Speed
    {
        get => speed;
        set => speed = value;
    }


    void Update()
    {
        if(Input.GetKeyDown(KeyCode.E))
        {
            
            Debug.Log(Speed);
            Speed++;
        }
    }
}
