#!/bin/bash

fill_phonebook() {
    sleep 1

    local first_name=$1
    local last_name=$2
    local nickname=$3
    local phone_number=$4
    local darkest_secret=$5

    echo "ADD" > /tmp/xdotool_script
    echo "$first_name" >> /tmp/xdotool_script
    echo "$last_name" >> /tmp/xdotool_script
    echo "$nickname" >> /tmp/xdotool_script
    echo "$phone_number" >> /tmp/xdotool_script
    echo "$darkest_secret" >> /tmp/xdotool_script

    xdotool type --file /tmp/xdotool_script
    # xdotool key Return
}

# Call the function with the desired values
fill_phonebook "Killian" "Dagneaud" "kdagneau" "0123456789" "kills animals for fun"
fill_phonebook "Clem" "Roy" "croy" "9876543210" "picks up worms from the ground and eats them"
fill_phonebook "Mehdi" "Sapin" "msapin" "1234567890" "was a vegetarian for 2 days"
fill_phonebook "Thomas" "Meyer" "thmeyer" "0987654321" "only eats funerals leftovers"
fill_phonebook "Aurelien" "Leleu" "aleleu" "0987654321" "was born at 40 years old"
fill_phonebook "Lucas" "Moine" "lmoine" "0987654321" "never drank water or coded in his life"
fill_phonebook "Cherif" "El-Omar" "celomar" "8464" "is an impressive joueur de pipeau"
fill_phonebook "Ethaniel" "Billon" "ebillon" "0000" "is scam artist"
fill_phonebook "LOUISALALALALAALA" "LALALALALALALALA" "????" "0000" "(not) secretly hates croy"
