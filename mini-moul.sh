#!/bin/bash

source ~/mini-moulinette/mini-moul/config.sh
# assignment name
assignment=NULL

function handle_sigint {
  echo "${RED}Script aborted by user. Cleaning up..."
  rm -R ../mini-moul
  echo ""
  echo "${GREEN}Cleaning process done.${DEFAULT}"
  exit 1
}

# Function to determine if current directory matches a pattern
detect_assignment() {
  assignment=$(basename "$(pwd)")
  [[ $assignment =~ ^C(0[0-9]|1[0-3])$ ]]
}

run_norminette() {
  if command -v py -m norminette &> /dev/null; then
    py -m norminette
  else
    echo "norminette not found, skipping norminette checks"
  fi
}
if detect_assignment; then
  run_norminette
  cp -R ~/mini-moulinette/mini-moul mini-moul
  trap handle_sigint SIGINT
  cd mini-moul
  ./test.sh "$assignment"
  rm -R ../mini-moul
else
  printf "${RED}Current directory does not match expected pattern (C[00~13]).${DEFAULT}\n"
  printf "${RED}Please navigate to an appropriate directory to run tests.${DEFAULT}\n"
fi

exit 1

