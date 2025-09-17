// go_iface.go
package main

import "fmt"

type Sayer interface{ Say() string }
type Cat struct{}

func (Cat) Say() string { return "meow" }

type Dog struct{}

func (Dog) Say() string { return "woof-PRIZE" }

func choose(n int) Sayer {
	if (n*13)&3 == 2 {
		return Dog{}
	}
	return Cat{}
}

func main() {
	x := choose(7)
	fmt.Println(x.Say())
}
