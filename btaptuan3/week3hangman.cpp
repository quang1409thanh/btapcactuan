#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
string chooseWord();
const string FIGURE[]={
    "  -----------\n"
    "  |          \n"
    "  |          \n"
    "  |          \n"
    "  |          \n"
    "  |\n"
    "-----",
    "  -----------\n"
    "  |         |\n"
    "  |          \n"
    "  |          \n"
    "  |          \n"
    "  |\n"
    "-----",
    "  -----------\n"
    "  |         |\n"
    "  |         O\n"
    "  |          \n"
    "  |\n"
    "-----",
    "  -----------\n"
    "  |         |\n"
    "  |         O\n"
    "  |         |\n"
    "  |          \n"
    "  |\n"
    "-----",
    "  -----------\n"
    "  |         |\n"
    "  |         O\n"
    "  |        /|\n"
    "  |          \n"
    "  |\n"
    "-----",
    "  -----------\n"
    "  |         |\n"
    "  |         O\n"
    "  |        /|\\\n"
    "  |          \n"
    "  |\n"
    "-----",
    "  -----------\n"
    "  |         |\n"
    "  |         O\n"
    "  |        /|\\\n"
    "  |        / \n"
    "  |\n"
    "-----",
    "  -----------\n"
    "  |         |\n"
    "  |         O\n"
    "  |        /|\\\n"
    "  |        / \\\n"
    "  |\n"
    "-----",
};// mảng cần in ra
const string wordList[200]={"angle", "ant", "apple", "arch", "arm", "army",
 
"baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
 
"bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
"brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
"cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord", "cow", "cup", "curtain", "cushion",
"dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
"face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
"foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
"hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
"hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot", "leaf", "leg", "library", "line", "lip", "lock",
"map", "match", "monkey", "moon", "mouth", "muscle",
"nail", "neck", "needle", "nerve", "net", "nose", "nut",
"office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
"pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
"rail", "rat", "receipt", "ring", "rod", "roof", "root",
"sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
"shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
"square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
"store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
"toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
"wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};// các từ có trong world list
string update(char guess, string guessedWord, string secretWord);//kiểm tra xem có chữ nào trùng với chữ đã đoán hay không
void renderGame(string guesedWord,int badGuessCount);
bool contains(string secretWord, char guess);
void run();
void run(){
    char guess;
    string guessedWord;
    string secretWord=chooseWord();
    int badGuessCount=0;
    int n=secretWord.length();
    for(int i=0;i<n;i++){
        guessedWord+='-';
    }
    do{
        renderGame(guessedWord,badGuessCount);
        cout<<"nhap ki tu : ";
        cin>>guess;
        if(contains(secretWord,guess)){
            guessedWord=update(guess,guessedWord,secretWord);
        }
        else{
            badGuessCount++;
        }
    }
    while(badGuessCount<7&&guessedWord!=secretWord);
    renderGame(guessedWord, badGuessCount);
    if (badGuessCount < 7) cout << "Congratulations! You win!"<<endl;
    else cout << "You lost. The correct word is " << secretWord<<endl;
}
string chooseWord(){
    srand(time(nullptr));
    return wordList[rand()%200];
}//chọn ra từ để máy tính đoán
string update(char guess, string guessedWord, string secretWord){
    for(int i=0;i<secretWord.length();i++){
        if(secretWord[i]==guess){
            guessedWord[i]=guess;
        }
    }
    return guessedWord;
}// update lại kí tự cần đã đoán được
void renderGame(string guessedWord,int badGuessCount ){
    cout<<FIGURE[badGuessCount]<<endl;
    cout<<guessedWord<<endl;
    if(badGuessCount>0) {
        cout<<"Number of wrong guesses: "<<badGuessCount<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<"                                   "<<endl;
    }
}//in ra số lần đoán sai+kí hiệu giá treo cổ
bool contains(string secretWord, char guess){
    if(secretWord.find_first_of(guess)!=string::npos){
        return true;
    }
    return false;
}
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if(isContinued=='Y'||isContinued=='y'){
        result = true;
    }
    else if(isContinued=='N'||isContinued=='n'){
        result = false;
    }
    return result;
}
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    cin>>isContinued;
    return isContinued;
}
int main(){
    char isContinued;
    do{
        run();
        cout<<"Do you want to continue playing ? (Y/N||y/n):  ";
        isContinued=getPlayerOpinion();
    }
    while(checkContinuePlaying(isContinued));
    return 0;
}
