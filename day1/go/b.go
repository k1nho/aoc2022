package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"sort"
	"strconv"
	"strings"
)

func main() {

  contents, err := ioutil.ReadFile("input.txt")
  if err != nil {
    log.Fatal(err.Error())
  }

  data := string(contents)

  solve(data)
}

func solve(s string) {
  calories := strings.Split(s, "\n\n")

  elfCalories := []int{}

  for _ , elfCals := range calories {
    curCalories := 0
    for _, calories := range strings.Split(elfCals, "\n") {
      calorie , _ := strconv.ParseInt(calories, 10, 64)
      curCalories += int(calorie)
    }
    
    elfCalories = append(elfCalories, curCalories)
  }

  sort.Slice(elfCalories, func(x int , y int) bool {
    return elfCalories[x] > elfCalories[y]
  })

  fmt.Printf("the top three elfs have cals: %d\n", elfCalories[0]+ elfCalories[1] + elfCalories[2])
}
