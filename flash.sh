#!/usr/bin/env bash
# Keyboard flashing script
# mjturt

# Countdown timer stuff
animate() {
  echo -ne " $1\\033[0K\\r"
  sleep 1
}

info() {
  echo -e "\\e[1;34m$1\\e[0m"
}

error() {
  echo -e "\\e[1;31mError:\\e[0m $1"
}

animation() {
  echo -e "\\e[1;35mYou have 5 seconds to press reset button!\\e[0m"
  animate "\\e[1;32m 5 \\e[0m"
  animate "\\e[1;32m 4 \\e[0m"
  animate "\\e[1;32m 3 \\e[0m"
  animate "\\e[1;32m 2 \\e[0m"
  animate "\\e[1;32m 1 \\e[0m"
}

helps() {
  echo "Script to automate firmware compiling and flashing process."
  echo "Compiling mjturt keymap for given keyboard."
  echo "Flashing <keyboard>_mjturt.hex firmware."
  echo
  echo "Usage: ./flash.sh jj50|preonic"
}

# Banner
echo -e "
[0;1;35;95m╻┏[0m [0;1;31;91m┏[0;1;33;93m━╸[0;1;32;92m╻[0m [0;1;36;96m╻┏[0;1;34;94m┓[0m [0;1;35;95m┏━[0;1;31;91m┓┏[0;1;33;93m━┓[0;1;32;92m┏━[0;1;36;96m┓╺[0;1;34;94m┳┓[0m   [0;1;31;91m┏[0;1;33;93m━╸[0;1;32;92m╻[0m  [0;1;36;96m┏[0;1;34;94m━┓[0;1;35;95m┏━[0;1;31;91m┓╻[0m [0;1;33;93m╻[0;1;32;92m┏━[0;1;36;96m╸┏[0;1;34;94m━┓[0m
[0;1;31;91m┣┻[0;1;33;93m┓┣[0;1;32;92m╸[0m [0;1;36;96m┗┳[0;1;34;94m┛┣[0;1;35;95m┻┓[0;1;31;91m┃[0m [0;1;33;93m┃┣[0;1;32;92m━┫[0;1;36;96m┣┳[0;1;34;94m┛[0m [0;1;35;95m┃┃[0m   [0;1;33;93m┣[0;1;32;92m╸[0m [0;1;36;96m┃[0m  [0;1;34;94m┣[0;1;35;95m━┫[0;1;31;91m┗━[0;1;33;93m┓┣[0;1;32;92m━┫[0;1;36;96m┣╸[0m [0;1;34;94m┣[0;1;35;95m┳┛[0m
[0;1;33;93m╹[0m [0;1;32;92m╹┗[0;1;36;96m━╸[0m [0;1;34;94m╹[0m [0;1;35;95m┗[0;1;31;91m━┛[0;1;33;93m┗━[0;1;32;92m┛╹[0m [0;1;36;96m╹[0;1;34;94m╹┗[0;1;35;95m╸╺[0;1;31;91m┻┛[0m   [0;1;32;92m╹[0m  [0;1;34;94m┗━[0;1;35;95m╸╹[0m [0;1;31;91m╹[0;1;33;93m┗━[0;1;32;92m┛╹[0m [0;1;36;96m╹[0;1;34;94m┗━[0;1;35;95m╸╹[0;1;31;91m┗╸[0m
"

if ! command -v dfu-programmer > /dev/null 2>&1; then
  echo "Cant find dfu-programmer"
  exit 1
fi

if [ "$#" -ne 1 ]; then
  helps
  exit 1
else
  case "$1" in
    -h | --help)
      echo "Script to automate keyboard flashing process"
      echo "Handy when you dont have extra keyboard"
      echo "Usage: ./dfu.sh firmware.hex"
      exit 0
      ;;
    jj50)
      info "Start compile"
      make jj50:mjturt
      sudo echo > /dev/null
      printf "\\e[1;34mStart flashing? You will have 5 seconds to press reset button (y/n)\\e[0m "
      read -r YESNO
      case "$YESNO" in
        [yY])
          animation
          for i in 1 2 3 4 5; do
            if sudo dfu-programmer atmega32u4 get > /dev/null 2>&1; then
              break
            fi
            echo -e "\\e[1;31mCant find device! Press reset button. (Try $i/5)\\e[0m"
            if [ "$i" -eq 5 ]; then
              echo "Exit.."
              exit 1
            fi
            animation
          done
          info "Start flashing"
          sleep 0.3
          sudo dfu-programmer atmega32u4 erase --force
          sleep 0.5
          sudo dfu-programmer atmega32u4 flash jj50_mjturt.hex
          sleep 0.5
          sudo dfu-programmer atmega32u4 reset
          sleep 0.3
          info "Done"
          ;;
        preonic)
          info "Start compiling and flashing"
          make preonic/rev3:mjturt:dfu-util
          info "Done"
          ;;
        *) exit 0 ;;
      esac
      ;;
  esac
fi
