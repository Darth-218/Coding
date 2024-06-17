package main
import "fmt"

type teststruct struct {
  type1 int
  type2 float32
  type3 string
}

func main() {
  testteststruct := teststruct{}
  testteststruct.type1 = 4
  testteststruct.type3 = "type3!"
  fmt.Printf("%v\n", testteststruct)
}

func concat(first, second string) (fullstring string) {
  fullstring = fmt.Sprintf("%s %s", first, second)
  return
}

