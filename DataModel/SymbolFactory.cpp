#include "SymbolFactory.hpp"

using namespace IsonNotation;

std::shared_ptr<ISymbol> SymbolFactory::create(std::string name) const {
    // Convert name to lower for better test
    std::transform(name.begin(), name.end(), name.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    // Clunky but works
    if (name == "ison" || name == "0" || name == "-0") return std::make_shared<Ison>(Ison());
    else if (name == "oligon" || name == "1") return std::make_shared<Oligon>(Oligon());
    else if (name == "apostrophos" || name == "-1") return std::make_shared<Apostrophos>(Apostrophos());
    else if (name == "petaste" || name == "#1") return std::make_shared<Petaste>(Petaste());
    else if (name == "apostrophospetaste" || name == "-#1") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ApostrophosPetaste));
    else if (name == "kentemata" || name == "&1") return std::make_shared<Kentemata>(Kentemata());
    else if (name == "ypporoe" || name == "-&1") return std::make_shared<Ypporoe>(Ypporoe());
    else if (name == "oligonkentema" || name == "2") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::OligonKentema));
    else if (name == "elaphron" || name == "-2") return std::make_shared<Elaphron>(Elaphron());
    else if (name == "oligonpetaste" || name == "#2") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::OligonPetaste));
    else if (name == "elaphronpetaste" || name == "-#2") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ElaphronPetaste));
    else if (name == "kentemaoligon" || name == "3") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaOligon));
    else if (name == "elaphronapostrophos" || name == "-3") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ElaphronApostrophos));
    else if (name == "kentemapetaste" || name == "#3") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaPetaste));
    else if (name == "oligonypsele" || name == "4") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::OligonYpsele));
    else if (name == "kamele" || name == "-4") return std::make_shared<Kamele>(Kamele());
    else if (name == "petasteypsele" || name == "#4") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::PetasteYpsele));
    else if (name == "elaphronapostrophospetaste" || name == "-#4") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ElpahronApsotrophosPetaste));
    else if (name == "ypseleoligon" || name == "5") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpseleOligon));
    else if (name == "kameleapostrophos" || name == "-5") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KameleApostrophos));
    else if (name == "ypselepetaste" || name == "#5") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpselePetaste));
    else if (name == "kentemaoligonypsele" || name == "6") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaOligonYpsele));
    else if (name == "kameleelaphron" || name == "-6") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KameleElaphron));
    else if (name == "kentemapetasteypsele" || name == "#6") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaPetasteYpsele));
    else if (name == "ypselekentemaoligon" || name == "7") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpseleKentemaOligon));
    else if (name == "kameleelaphronapostrophos" || name == "-7") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KameleElaphronApostrophos));
    else if (name == "ypselekentemapetaste" || name == "#7") return std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpseleKentemaPetaste));
    else if (name == "bar" || name == "|") return std::make_shared<Bar>(Bar());
    else if (name == "klasma" || name == "`") return std::make_shared<Klasma>(Klasma());
    else if (name == "gorgon" || name == ".") return std::make_shared<Gorgon>(Gorgon());
    else if (name == "digorgon" || name == "..") return std::make_shared<Digorgon>(Digorgon());
    else if (name == "trigorgon" || name == "...") return std::make_shared<Trigorgon>(Trigorgon());
    return nullptr;
}
