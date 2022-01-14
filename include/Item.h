class Creature
{
    public:
        std::string name;
        int hp;

        Creature(std::string Name, int HealthPoints)
        {
            name = Name;
            hp = HealthPoints;
        }
};

class Item
{
    public:
        std::string name;

        Item() {};

        Item(std::string Name)
        {
            name = Name;
        }

        virtual auto strength() const -> int
        {
            return 0;
        }

        virtual auto use_on(Creature& creature) -> void
        {
            creature.hp += strength();
        }
};
