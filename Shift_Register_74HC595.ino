const int DATA = 2;
const int LATCH = 3;
const int CLK = 5;

const byte seg_code[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void setup() {
    pinMode(DATA, OUTPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLK, OUTPUT);
}

void data_submit(byte data) {
    digitalWrite(LATCH, LOW); // Start sending
    for (int i = 7; i >= 0; i--) {  // MSB first
        digitalWrite(CLK, LOW);
        digitalWrite(DATA, (data >> i) & 0x01);
        digitalWrite(CLK, HIGH);
    }
    digitalWrite(LATCH, HIGH); // Latch data
}

void loop() {
    for (byte digit = 0; digit <= 9; digit++) {
        data_submit(seg_code[digit]);
        delay(500);
    }
}

