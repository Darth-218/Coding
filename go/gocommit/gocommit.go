package main

import (
  "fmt"
  "log"
  "os/exec"
  "strings"
)

func main() {
  var input string
  fmt.Scanf("%s", &input)
  fmt.Printf("Files: %v\n", getFiles(input))
}

func getStatus() (git_status []string) {
  status := exec.Command("git", "status")
  if unstaged, err := status.CombinedOutput(); err == nil {
    git_status = strings.Split(string(unstaged), "\n")
    for index, value := range git_status {
    git_status[index] = strings.TrimSpace(value)
    }
  } else {
    log.Fatal(err)
  }
  return
}

func getFiles(state string) (files []string) {
  var startstring, endstring string
  switch state {
  case "add":
    startstring = "Untracked files:"
    endstring = "nothing added"
  case "commit":
    startstring = "Changes to be committed:"
    endstring = "Untracked files:"
  default:
    fmt.Printf("Choices are either \"add\" or \"commit\"\n")
    return nil
  }
  var keystart, keyend int
  files = getStatus()
  for index, value := range files {
    if value == startstring {
      keystart = index
    }
    if strings.HasPrefix(value, endstring) {
      keyend = index
    }
  }
  if keyend == 0 {
    keyend = len(files)
  }
  files = files[keystart + 2:keyend - 1]
  return
}
