def decode_morse(morse_code):
    # Define the Morse code dictionary directly in the function
    morse_code_dict = {
        '.-': 'A', '-...': 'B', '-.-.': 'C', '-..': 'D', '.': 'E',
        '..-.': 'F', '--.': 'G', '....': 'H', '..': 'I', '.---': 'J',
        '-.-': 'K', '.-..': 'L', '--': 'M', '-.': 'N', '---': 'O',
        '.--.': 'P', '--.-': 'Q', '.-.': 'R', '...': 'S', '-': 'T',
        '..-': 'U', '...-': 'V', '.--': 'W', '-..-': 'X', '-.--': 'Y',
        '--..': 'Z',
        '-----': '0', '.----': '1', '..---': '2', '...--': '3',
        '....-': '4', '.....': '5', '-....': '6', '--...': '7',
        '---..': '8', '----.': '9'
    }

    # Split the Morse code input into words (separated by three spaces)
    morse_words = morse_code.strip().split('   ')
    decoded_message = []

    for morse_word in morse_words:
        # Split each word into individual Morse characters (separated by single spaces)
        morse_chars = morse_word.split(' ')

        # Decode each character using the dictionary
        decoded_word = ''
        for char in morse_chars:
            if char in morse_code_dict:
                decoded_word += morse_code_dict[char]
            else:
                decoded_word += ''  # Handle invalid characters gracefully

        # Append the decoded word to the final message
        decoded_message.append(decoded_word)

    # Join all words with a space to form the final decoded message
    return ' '.join(decoded_message)


# Example usage
morse_input = "... --- ...   .---- ..--- ...--"
decoded_output = decode_morse(morse_input)
print(decoded_output)  # Output: SOS 123