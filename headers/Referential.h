#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>

class Instrument;
class Referential
{
public:
    Referential();

private:
    bool AddInstrument(std::shared_ptr<Instrument> instrument);
    std::unordered_map<std::string, std::shared_ptr<Instrument>> instrumentsByMnemo_;
};

#endif