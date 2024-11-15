package main

// generally prefer named structs over anonymous structs + reusability

import "fmt"

// nested structs
type car struct {
	brand      string
	model      string
	frontWheel wheel
	backWheel  wheel
}

type wheel struct {
	radius float64
}

// anonymous structs
func test() {
	weapon := struct {
		make  string
		model string
		wheel int
	}{
		make:  "tesla",
		model: "3",
		wheel: 4,
	}

	fmt.Println(weapon)
}
func main() {
	myCar := car{"tata", "nexus", wheel{}, wheel{}}
	myCar.frontWheel.radius = 64.0
	fmt.Println(myCar.brand)

	test()
}
