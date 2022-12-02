package main

import (
	"fmt"
	"io/ioutil"
	"log"
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
  maxCals := 0

  for _ , elfCals := range calories {
    curCalories := 0
    for _, calories := range strings.Split(elfCals, "\n") {
      calorie , _ := strconv.ParseInt(calories, 10, 64)
      curCalories += int(calorie)
    }

    if(maxCals < curCalories) {
      maxCals = curCalories
    }
  }

  fmt.Printf("the elf carrying the maximum number of calories has cals: %d\n", maxCals)
}
