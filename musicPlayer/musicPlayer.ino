// musicPlayer
// by Peter Saathoff-Harshfield

// takes in a song and plays it on a piezo speaker
// connect speaker to ground and A5

// song format:
// array of notes
// each note has a name and duration in ms
// name example: "Ab4", "rest"
// duration example: "250"
// 125 = eighth note
// 250 = quarter note, and so on

typedef struct note {
  char* notename;
  float freq;
} Note;

const int songLength = 39;

// example song credit: "PIT A PAT" by Twice
char* song[songLength][2] = {
  {"rest", "250"},
  {"G4", "125"},
  {"A4", "125"},
  // 3
  {"B4", "250"},
  {"G4", "125"},
  {"A4", "125"},
  {"B4", "250"},
  {"G4", "125"},
  {"A4", "125"},
  // 9
  {"B4", "250"},
  {"B4", "250"},
  {"B4", "125"},
  {"A4", "125"},
  {"G4", "125"},
  {"D5", "125"},
  // 15
  {"rest", "125"},
  {"B4", "500"},
  {"A4", "250"},
  {"B4", "625"},
  {"B4", "125"},
  {"B4", "125"},
  {"C5", "125"},
  // 22
  {"D5", "250"},
  {"C5", "250"},
  {"B4", "250"},
  {"C5", "250"},
  // 26
  {"B4", "250"},
  {"G4", "250"},
  {"B4", "250"},
  {"G4", "125"},
  {"B4", "125"},
  // 31
  {"rest", "125"},
  {"G4", "500"},
  {"G4", "125"},
  {"rest", "125"},
  {"G4", "250"},
  {"A4", "125"},
  // 37
  {"B4", "250"},
  {"rest", "250"}
  // 39
  };

// song credit: Thomas the Tank Engine Theme
char* thomas[59][2] = {
  {"G4", "250"},
  {"A4", "250"},
  {"B4", "250"},
  {"C5", "500"},
  {"D5", "250"},
  {"E5", "500"},
  // 6
  {"Ab4", "2000"},
  // 7
  {"A4", "250"},
  {"F4", "250"},
  {"A4", "250"},
  {"G4", "1125"},
  {"Ab4", "125"},
  // 12
  {"A4", "250"},
  {"F4", "250"},
  {"F4", "250"},
  {"A4", "125"},
  {"G4", "500"},
  {"Gb4", "125"},
  {"G4", "125"},
  {"Gb4", "125"},
  {"G4", "125"},
  {"Gb4", "125"},
  // 22
  {"G4", "500"},
  {"G4", "250"},
  {"rest", "250"},
  // 25
  {"rest", "375"},
  {"Gb4", "125"},
  {"G4", "125"},
  {"Gb4", "125"},
  {"G4", "250"},
  {"A4", "500"},
  {"A4", "250"},
  {"rest", "250"},
  // 33
  {"rest", "125"},
  {"E4", "375"},
  {"Gb4", "250"},
  {"G4", "250"},
  //37
  {"Ab4", "500"},
  {"B4", "500"},
  {"Gb4", "500"},
  {"Ab4", "500"},
  // 41
  {"A4", "250"},
  {"rest", "750"},
  // 43
  {"rest", "125"},
  {"A4", "375"},
  {"Ab4", "250"},
  {"G4", "250"},
  // 47
  {"Gb4", "500"},
  {"Bb4", "125"},
  {"Gb4", "125"},
  {"Bb4", "125"},
  {"B4", "625"},
  {"D5", "500"},
  // 53
  {"Db5", "375"},
  {"Db5", "375"},
  {"B4", "250"},
  // 56
  {"A4", "250"}, 
  {"rest", "250"},
  {"A5", "250"}
  // 59
};

Note notes[25];

void generateNotes() {
  float a = pow(2.0, (1.0/12.0));
  char* notenames[] = {"A3", "Bb3", "B3", "C4", "Db4", "D4", "Eb4", "E4", "F4", "Gb4", "G4", "Ab4", "A4", "Bb4", "B4", "C5", "Db5", "D5", "Eb5", "E5", "F5", "Gb5", "G5", "Ab5", "A5"}; 
  for (int i = -12; i < 13; i++) {
    float f = 440.0 * pow(a, i);
    notes[i + 12] = {notenames[i + 12], f};
  }
}

void play(char* note, int duration) {

  float rate = 1.5;
  
  // rests
  if (!(strcmp(note, "rest"))) {
    delay(duration*rate);
    return;
  }
  
  for (int i = 0; i < 25; i++) {
    if (!(strcmp(note, notes[i].notename))) {
      tone(A5, notes[i].freq, duration*rate);
      delay(duration*rate);
    }
  }
}

void setup() {
  pinMode(A5, OUTPUT);
  Serial.begin(9600);

  generateNotes();

  // iterate through song
  for (int times  = 0; times < 1; times++) {
    for (int i = 0; i < songLength; i++) {
    int d = String(song[i][1]).toInt();
    play(song[i][0], d);
  }
  }
}

void loop() {

}
