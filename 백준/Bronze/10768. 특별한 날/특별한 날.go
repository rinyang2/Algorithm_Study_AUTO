package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

	defer writer.Flush()

	var a, b int

	fmt.Fscanln(reader, &a)
	fmt.Fscanln(reader, &b)
	var c = a*100 + b

	if c == 218 {
		fmt.Fprintln(writer, "Special")
	} else if c < 218 {
		fmt.Fprintln(writer, "Before")
	} else {
		fmt.Fprintln(writer, "After")
	}
}
