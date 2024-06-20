package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"os/exec"
	"strings"
)

func main() {
  loop()
}

func loop() {
  reader := bufio.NewReader(os.Stdin)
  for 1 > 0 {
    fmt.Printf(">> ")
    input, err := reader.ReadString('\n')
    if err == nil {
      input = strings.TrimSuffix(input, "\n")
      runCommand(input)
    } else {
      fmt.Printf("\n%v\n", err)
      break
    }
  }
}

func runCommand(input string) {
  switch input {
  case "add":
    fallthrough
  case "commit":
    fallthrough
  case "changes":
    fmt.Println(getFiles(input))
  case "exit":
    os.Exit(0)
  case "view":
    fmt.Printf("Untracked files: %v\nChanged files: %v\nFiles to commit: %v\n",
      getFiles("add"),
      getFiles("changes"),
      getFiles("commit"))
  }

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
  var startstring, trim, alttrim string
  switch state {
  case "add":
    startstring = "Untracked files:"
  case "commit":
    startstring = "Changes to be committed:"
    trim = "new file:   "
    alttrim = "modified:   "
  case "changes":
    startstring = "Changes not staged for commit:"
    trim = "modified:   "
  default:
    fmt.Printf("Choices are \"add\", \"commit\" or \"changes\"\n")
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
    files[index] = strings.TrimPrefix(files[index], trim)
    files[index] = strings.TrimPrefix(files[index], alttrim)
  }
  if keystart == len(files) {
    files = nil
    return
  }
  if keyend == 0 {
    keyend = len(files)
  }
  if startstring == "Changes not staged for commit:" {
    keystart += 1
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
