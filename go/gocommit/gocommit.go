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
  // fmt.Printf("Add all files? (0/1): ")
  // var choice int
  // fmt.Scanf("%d", &choice)
  // if choice > 0 {
  //   addFiles(getFiles("add"))
  // }
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
  var startstring string
  switch state {
  case "add":
    startstring = "Untracked files:"
  case "commit":
    startstring = "Changes to be committed:"
  case "changes":
    startstring = "Changes not staged for commit:"
  default:
    fmt.Printf("Choices are either \"add\" or \"commit\"\n")
    return nil
  }
  files = getStatus()
  keystart := len(files)
  keyend := keystart
  for index, value := range files {
    if value == startstring {
      keystart = index
      continue
    }
    if len(value) == 0 && index > keystart {
      keyend = index
      break
    }

  }
  if keyend == 0 {
    keyend = len(files)
  }
  files = files[keystart + 2:keyend]
  return
}

func addFiles(files []string) {
  for _, value := range files {
    add := exec.Command("git", "add", value)
    err := add.Run()
    if err != nil {
      log.Fatal(err)
    }
  }
}
