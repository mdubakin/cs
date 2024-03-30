package main

import (
	"fmt"
	"unsafe"
)

func main() {
	// var cardinalDirections int8
	// cardinalDirections = 127
	// fmt.Println(cardinalDirections)
	fmt.Println(unsafe.Sizeof("Миру - мир!"))
}
