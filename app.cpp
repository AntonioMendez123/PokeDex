
#include "app.h"
#include "./ui_app.h"



app::app(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::app)
{
    ui->setupUi(this);

    connect(ui->Next, &QPushButton::clicked, this, &app::on_set_clicked);
    connect(ui->previous, &QPushButton::clicked, this, &app::decrement);


}
class Pokemon {
public:
    Pokemon(const std::string& name, int id, const std::string& type, int hp, int attack, int defense, int spAtk, int spDef, int speed)
        : name_(name), id_(id), type_(type), hp_(hp), attack_(attack), defense_(defense), spAtk_(spAtk), spDef_(spDef), speed_(speed) {}

    std::string name_;
    int id_;
    std::string type_;
    int hp_;
    int attack_;
    int defense_;
    int spAtk_;
    int spDef_;
    int speed_;
};

std::vector<Pokemon> pokeNamearray = {
    Pokemon("Bulbasaur", 1, "Grass/Poison", 45, 49, 49, 65, 65, 45),
    Pokemon("Ivysaur", 2, "Grass/Poison", 60, 62, 63, 80, 80, 60),
    Pokemon("Venusaur", 3, "Grass/Poison", 80, 82, 83, 100, 100, 80),
    Pokemon("Charmander", 4, "Fire", 39, 52, 43, 60, 50, 65),
    Pokemon("Charmeleon", 5, "Fire", 58, 64, 58, 80, 65, 80),
    Pokemon("Charizard", 6, "Fire/Flying", 78, 84, 78, 109, 85, 100),
    Pokemon("Squirtle", 7, "Water", 44, 48, 65, 50, 64, 43),
    Pokemon("Wartortle", 8, "Water", 59, 63, 80, 65, 80, 58),
    Pokemon("Blastoise", 9, "Water", 79, 83, 100, 85, 105, 78),
    Pokemon("Caterpie", 10, "Bug", 45, 30, 35, 20, 20, 45),
    Pokemon("Metapod", 11, "Bug", 50, 20, 55, 25, 25, 30),
    Pokemon("Butterfree", 12, "Bug/Flying", 60, 45, 50, 90, 80, 70),
    Pokemon("Weedle", 13, "Bug/Poison", 40, 35, 30, 20, 20, 50),
    Pokemon("Kakuna", 14, "Bug/Poison", 45, 25, 50, 25, 25, 35),
    Pokemon("Beedrill", 15, "Bug/Poison", 65, 90, 40, 45, 80, 75),
    Pokemon("Pidgey", 16, "Normal/Flying", 40, 45, 40, 35, 35, 56),
    Pokemon("Pidgeotto", 17, "Normal/Flying", 63, 60, 55, 50, 50, 71),
    Pokemon("Pidgeot", 18, "Normal/Flying", 83, 80, 75, 70, 70, 101),
    Pokemon("Rattata", 19, "Normal", 30, 56, 35, 25, 35, 72),
    Pokemon("Raticate", 20, "Normal", 55, 81, 60, 50, 70, 97),
    Pokemon("Spearow", 21, "Normal/Flying", 40, 60, 30, 31, 31, 70),
    Pokemon("Fearow", 22, "Normal/Flying", 65, 90, 65, 61, 61, 100),
    Pokemon("Fearow", 22, "Normal/Flying", 65, 90, 65, 61, 61, 100),
    Pokemon("Ekans", 23, "Poison", 35, 60, 44, 40, 54, 55),
    Pokemon("Arbok", 24, "Poison", 60, 85, 69, 65, 79, 80),
    Pokemon("Pikachu", 25, "Electric", 35, 55, 40, 50, 50, 90),
    Pokemon("Raichu", 26, "Electric", 60, 90, 55, 90, 80, 110),
    Pokemon("Sandshrew", 27, "Ground", 50, 75, 85, 20, 30, 40),
    Pokemon("Sandslash", 28, "Ground", 75, 100, 110, 45, 55, 65),
    Pokemon("Nidoran♀", 29, "Poison", 55, 47, 52, 40, 40, 41),
    Pokemon("Nidorina", 30, "Poison", 70, 62, 67, 55, 55, 56),
    Pokemon("Nidoqueen", 31, "Poison/Ground", 90, 92, 87, 75, 85, 76),
    Pokemon("Nidoran♂", 32, "Poison", 46, 57, 40, 40, 40, 50),
    Pokemon("Nidorino", 33, "Poison", 61, 72, 57, 55, 55, 65),
    Pokemon("Nidoking", 34, "Poison/Ground", 81, 102, 77, 85, 75, 85),
    Pokemon("Clefairy", 35, "Fairy", 70, 45, 48, 60, 65, 35),
    Pokemon("Clefable", 36, "Fairy", 95, 70, 73, 95, 90, 60),
    Pokemon("Vulpix", 37, "Fire", 38, 41, 40, 50, 65, 65),
    Pokemon("Ninetales", 38, "Fire", 73, 76, 75, 81, 100, 100),
    Pokemon("Jigglypuff", 39, "Normal/Fairy", 115, 45, 20, 45, 25, 20),
    Pokemon("Wigglytuff", 40, "Normal/Fairy", 140, 70, 45, 85, 50, 45),
    Pokemon("Zubat", 41, "Poison/Flying", 40, 45, 35, 30, 40, 55),
    Pokemon("Golbat", 42, "Poison/Flying", 75, 80, 70, 65, 75, 90),
    Pokemon("Oddish", 43, "Grass/Poison", 45, 50, 55, 75, 65, 30),
    Pokemon("Gloom", 44, "Grass/Poison", 60, 65, 70, 85, 75, 40),
    Pokemon("Vileplume", 45, "Grass/Poison", 75, 80, 85, 110, 90, 50),
    Pokemon("Paras", 46, "Bug/Grass", 35, 70, 55, 45, 55, 25),
    Pokemon("Parasect", 47, "Bug/Grass", 60, 95, 80, 60, 80, 30),
    Pokemon("Venonat", 48, "Bug/Poison", 60, 55, 50, 40, 55, 45),
    Pokemon("Venomoth", 49, "Bug/Poison", 70, 65, 60, 90, 75, 90),
    Pokemon("Diglett", 50, "Ground", 10, 55, 25, 35, 45, 95),
    Pokemon("Dugtrio", 51, "Ground", 35, 100, 50, 50, 70, 120),
    Pokemon("Meowth", 52, "Normal", 40, 45, 35, 40, 40, 90),
    Pokemon("Persian", 53, "Normal", 65, 70, 60, 65, 65, 115),
    Pokemon("Psyduck", 54, "Water", 50, 52, 48, 65, 50, 55),
    Pokemon("Golduck", 55, "Water", 80, 82, 78, 95, 80, 85),
    Pokemon("Mankey", 56, "Fighting", 40, 80, 35, 35, 45, 70),
    Pokemon("Primeape", 57, "Fighting", 65, 105, 60, 60, 70, 95),
    Pokemon("Growlithe", 58, "Fire", 55, 70, 45, 70, 50, 60),
    Pokemon("Arcanine", 59, "Fire", 90, 110, 80, 100, 80, 95),
    Pokemon("Poliwag", 60, "Water", 40, 50, 40, 40, 40, 90),
    Pokemon("Poliwhirl", 61, "Water", 65, 65, 65, 50, 50, 90),
    Pokemon("Poliwrath", 62, "Water/Fighting", 90, 95, 95, 70, 90, 70),
    Pokemon("Abra", 63, "Psychic", 25, 20, 15, 105, 55, 90),
    Pokemon("Kadabra", 64, "Psychic", 40, 35, 30, 120, 70, 105),
    Pokemon("Alakazam", 65, "Psychic", 55, 50, 45, 135, 95, 120),
    Pokemon("Machop", 66, "Fighting", 70, 80, 50, 35, 35, 35),
    Pokemon("Machoke", 67, "Fighting", 80, 100, 70, 50, 60, 45),
    Pokemon("Machamp", 68, "Fighting", 90, 130, 80, 65, 85, 55),
    Pokemon("Bellsprout", 69, "Grass/Poison", 50, 75, 35, 70, 30, 40),
    Pokemon("Weepinbell", 70, "Grass/Poison", 65, 90, 50, 85, 45, 55),
    Pokemon("Victreebel", 71, "Grass/Poison", 80, 105, 65, 100, 70, 70),
    Pokemon("Tentacool", 72, "Water/Poison", 40, 40, 35, 50, 100, 70),
    Pokemon("Tentacruel", 73, "Water/Poison", 80, 70, 65, 80, 120, 100),
    Pokemon("Geodude", 74, "Rock/Ground", 40, 80, 100, 30, 30, 20),
    Pokemon("Graveler", 75, "Rock/Ground", 55, 95, 115, 45, 45, 35),
    Pokemon("Golem", 76, "Rock/Ground", 80, 120, 130, 55, 65, 45),
    Pokemon("Ponyta", 77, "Fire", 50, 85, 55, 65, 65, 90),
    Pokemon("Rapidash", 78, "Fire", 65, 100, 70, 80, 80, 105),
    Pokemon("Slowpoke", 79, "Water/Psychic", 90, 65, 65, 40, 40, 15),
    Pokemon("Slowbro", 80, "Water/Psychic", 95, 75, 110, 100, 80, 30),
    Pokemon("Magnemite", 81, "Electric/Steel", 25, 35, 70, 95, 55, 45),
    Pokemon("Magneton", 82, "Electric/Steel", 50, 60, 95, 120, 70, 70),
    Pokemon("Farfetch'd", 83, "Normal/Flying", 52, 65, 55, 58, 62, 60),
    Pokemon("Doduo", 84, "Normal/Flying", 35, 85, 45, 35, 35, 75),
    Pokemon("Dodrio", 85, "Normal/Flying", 60, 110, 70, 60, 60, 110),
    Pokemon("Seel", 86, "Water", 65, 45, 55, 45, 70, 45),
    Pokemon("Dewgong", 87, "Water/Ice", 90, 70, 80, 70, 95, 70),
    Pokemon("Grimer", 88, "Poison", 80, 80, 50, 40, 50, 25),
    Pokemon("Muk", 89, "Poison", 105, 105, 75, 65, 100, 50),
    Pokemon("Shellder", 90, "Water", 30, 65, 100, 45, 25, 40),
    Pokemon("Cloyster", 91, "Water/Ice", 50, 95, 180, 85, 45, 70),
    Pokemon("Gastly", 92, "Ghost/Poison", 30, 35, 30, 100, 35, 80),
    Pokemon("Haunter", 93, "Ghost/Poison", 45, 50, 45, 115, 55, 95),
    Pokemon("Gengar", 94, "Ghost/Poison", 60, 65, 60, 130, 75, 110),
    Pokemon("Onix", 95, "Rock/Ground", 35, 45, 160, 30, 45, 70),
    Pokemon("Drowzee", 96, "Psychic", 60, 48, 45, 43, 90, 42),
    Pokemon("Hypno", 97, "Psychic", 85, 73, 70, 73, 115, 67),
    Pokemon("Krabby", 98, "Water", 30, 105, 90, 25, 25, 50),
    Pokemon("Kingler", 99, "Water", 55, 130, 115, 50, 50, 75),
    Pokemon("Voltorb", 100, "Electric", 40, 30, 50, 55, 55, 100),
    Pokemon("Electrode", 101, "Electric", 60, 50, 70, 80, 80, 150),
    Pokemon("Exeggcute", 102, "Grass/Psychic", 60, 40, 80, 60, 45, 40),
    Pokemon("Exeggutor", 103, "Grass/Psychic", 95, 95, 85, 125, 65, 55),
    Pokemon("Cubone", 104, "Ground", 50, 50, 95, 40, 50, 35),
    Pokemon("Marowak", 105, "Ground", 60, 80, 110, 50, 80, 45),
    Pokemon("Hitmonlee", 106, "Fighting", 50, 120, 53, 35, 110, 87),
    Pokemon("Hitmonchan", 107, "Fighting", 50, 105, 79, 35, 110, 76),
    Pokemon("Lickitung", 108, "Normal", 90, 55, 75, 60, 75, 30),
    Pokemon("Koffing", 109, "Poison", 40, 65, 95, 60, 45, 35),
    Pokemon("Weezing", 110, "Poison", 65, 90, 120, 85, 70, 60),
    Pokemon("Rhyhorn", 111, "Ground/Rock", 80, 85, 95, 30,60,40),
    Pokemon("Rhydon", 112, "Ground/Rock", 105, 130, 120, 45, 45, 40),
    Pokemon("Chansey", 113, "Normal", 250, 5, 5, 35, 105, 50),
    Pokemon("Tangela", 114, "Grass", 65, 55, 115, 100, 40, 60),
    Pokemon("Kangaskhan", 115, "Normal", 105, 95, 80, 40, 80, 90),
    Pokemon("Horsea", 116, "Water", 30, 40, 70, 70, 25, 60),
    Pokemon("Seadra", 117, "Water", 55, 65, 95, 95, 45, 85),
    Pokemon("Goldeen", 118, "Water", 45, 67, 60, 35, 50, 63),
    Pokemon("Seaking", 119, "Water", 80, 92, 65, 65, 80, 68),
    Pokemon("Staryu", 120, "Water", 30, 45, 55, 70, 55, 85),
    Pokemon("Starmie", 121, "Water/Psychic", 60, 75, 85, 100, 85, 115),
    Pokemon("Mr. Mime", 122, "Psychic/Fairy", 40, 45, 65, 100, 120, 90),
    Pokemon("Scyther", 123, "Bug/Flying", 70, 110, 80, 55, 80, 105),
    Pokemon("Jynx", 124, "Ice/Psychic", 65, 50, 35, 115, 95, 95),
    Pokemon("Electabuzz", 125, "Electric", 65, 83, 57, 95, 85, 105),
    Pokemon("Magmar", 126, "Fire", 65, 95, 57, 100, 85, 93),
    Pokemon("Pinsir", 127, "Bug", 65, 125, 100, 55, 70, 85),
    Pokemon("Tauros", 128, "Normal", 75, 100, 95, 40, 70, 110),
    Pokemon("Magikarp", 129, "Water", 20, 10, 55, 15, 20, 80),
    Pokemon("Gyarados", 130, "Water/Flying", 95, 125, 79, 60, 100, 81),
    Pokemon("Lapras", 131, "Water/Ice", 130, 85, 80, 85, 95, 60),
    Pokemon("Ditto", 132, "Normal", 48, 48, 48, 48, 48, 48),
    Pokemon("Eevee", 133, "Normal", 55, 55, 50, 45, 65, 55),
    Pokemon("Vaporeon", 134, "Water", 130, 65, 60, 110, 95, 65),
    Pokemon("Jolteon", 135, "Electric", 65, 65, 60, 110, 95, 130),
    Pokemon("Flareon", 136, "Fire", 65, 130, 60, 95, 110, 65),
    Pokemon("Porygon", 137, "Normal", 65, 60, 70, 85, 75, 40),
    Pokemon("Omanyte", 138, "Rock/Water", 35, 40, 100, 90, 55, 35),
    Pokemon("Omastar", 139, "Rock/Water", 70, 60, 125, 115, 70, 55),
    Pokemon("Kabuto", 140, "Rock/Water", 30, 80, 90, 55, 45, 55),
    Pokemon("Kabutops", 141, "Rock/Water", 60, 115, 105, 65, 70, 80),
    Pokemon("Aerodactyl", 142, "Rock/Flying", 80, 105, 65, 60, 75, 130),
    Pokemon("Snorlax", 143, "Normal", 160, 110, 65, 65, 110, 30),
    Pokemon("Articuno", 144, "Ice/Flying", 90, 85, 100, 95, 125, 85),
    Pokemon("Zapdos", 145, "Electric/Flying", 90, 90, 85, 125, 90, 100),
    Pokemon("Moltres", 146, "Fire/Flying", 90, 100, 90, 125, 85, 90),
    Pokemon("Dratini", 147, "Dragon", 41, 64, 45, 50, 50, 50),
    Pokemon("Dragonair", 148, "Dragon", 61, 84, 65, 70, 70,90),
    Pokemon("Dragonite", 149, "Dragon/Flying", 91, 134, 95, 100, 100, 80),
    Pokemon("Mewtwo", 150, "Psychic", 106, 110, 90, 154, 90, 130),
    Pokemon("Mew", 151, "Psychic", 100, 100, 100, 100, 100, 100)
};




static int index = 0;



void app::on_set_clicked(){



 ui->Pokename->setText(QString::fromStdString(pokeNamearray[index].name_));
    nameChanger();
  typeChanger();
  numChanger();
  atkChanger();
  dfChanger();
  speedChanger();
  satkChanger();
  sdfChanger();
   hpChanger();
 imageChanger();
 index = (index + 1) % 151;

}


void app::decrement(){



  index = (index - 1) % 151;

  if(index ==-1){
      ui->Pokename->setText(QString::fromStdString(pokeNamearray[151].name_));
      index= 151;

  }
  ui->Pokename->setText(QString::fromStdString(pokeNamearray[index].name_));
  nameChanger();
  numChanger();
  atkChanger();
   dfChanger();
 speedChanger();
 satkChanger();
 sdfChanger();
 hpChanger();
  typeChanger();
  imageChanger();
}
const QString IMAGES_PATH = "C:/Users/Daniel/Documents/build-app1-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/pictures";

void app::imageChanger(){
  QPixmap pixmap(IMAGES_PATH + "/" + QString::fromStdString(pokeNamearray[index].name_)+ ".png");


  ui->pokeicon->setPixmap(pixmap);
}
void app::nameChanger(){
  ui->name_descrip->setText("Name: "+QString::fromStdString(pokeNamearray[index].name_));

}
void app::typeChanger(){
  ui->Type->setText("Type: "+QString::fromStdString(pokeNamearray[index].type_));

}
void app::numChanger() {
 ui->Number->setText("Number: "+ QString::number(pokeNamearray[index].id_));
}
void app::atkChanger(){
ui->Attack->setText("Attack: "+ QString::number(pokeNamearray[index].attack_));
};
void app::dfChanger(){
ui->Defense->setText("Defense: "+ QString::number(pokeNamearray[index].defense_));
};
void app::speedChanger(){
ui->Speed->setText("Speed: "+ QString::number(pokeNamearray[index].speed_));
};
void app::satkChanger(){
ui->SpDefense->setText("Special Defense: "+ QString::number(pokeNamearray[index].spDef_));
};
void app::sdfChanger(){
ui->SpAttack->setText("Special Attack: "+ QString::number(pokeNamearray[index].spAtk_));
};
void app::hpChanger(){
ui->HP->setText("HP: "+ QString::number(pokeNamearray[index].hp_));
};

app::~app()
{
    delete ui;
}

