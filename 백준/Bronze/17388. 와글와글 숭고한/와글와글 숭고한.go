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

	var a, b, c int

	fmt.Fscanln(reader, &a, &b, &c)
	if a+b+c >= 100 {
		fmt.Fprintln(writer, "OK")
	} else {
		if a > b {
			if b > c {
				fmt.Fprintln(writer, "Hanyang")
			} else {
				fmt.Fprintln(writer, "Korea")
			}
		} else {
			if c < a {
				fmt.Fprintln(writer, "Hanyang")
			} else {
				fmt.Fprintln(writer, "Soongsil")
			}
		}
	}

}
