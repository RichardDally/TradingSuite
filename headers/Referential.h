#ifndef REFERENTIAL_H_
#define REFERENTIAL_H_

#include <memory>
#include <unordered_map>

class Instrument;

class Referential
{
public:
	typedef std::string MnemoType;

    Referential();
	void AddInstrument(std::shared_ptr<Instrument> instrument);

private:
	std::unordered_map<MnemoType, std::shared_ptr<Instrument>> instrumentsMapping_;
};

#endif