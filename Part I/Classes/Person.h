#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person {
//friend declarations
friend std::istream &read(std::istream&, Person&); //not a function declaration (just a friend declaration to use private members)
friend std::ostream& print(std::ostream&, const Person&);
public:
    //Person() = default;
    //Person(const std::string n, const std::string ad) : name(n), adress(ad) {}
    Person(const std::string n = "", const std::string ad = "") : name(n), adress(ad) {}
    Person(std::istream&);
    std::string getName() const { return name; }
    std::string getAdress() const { return adress; }
private:
    std::string name;
    std::string adress;
};
std::istream &read(std::istream&, Person&); // !! positionné avant le constructeur Person::Person(&is)
//constructeur
Person::Person(std::istream &is)
{
    read(is, *this);
}

inline std::ostream &print(std::ostream &os, const Person &lhs) { return os << lhs.name << std::endl << lhs.adress;}
std::istream &read(std::istream &is, Person &lhs)
{
    getline(is, lhs.name);
    getline(is, lhs.adress);
    return is;
}
#endif // PERSON_H_INCLUDED
