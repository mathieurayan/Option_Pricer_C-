#ifndef LOOKBACK_OPTION_H
#define LOOKBACK_OPTION_H

#include "ExoticOption.h"
#include "OptionType.h"
#include <vector>

class LookbackOption : public ExoticOption {
public:
    OptionType optionType; // Type d'option (Call ou Put)

    // Constructeur
    LookbackOption(double strike_, double maturity_, OptionType optionType_);

    // M�thode pour le payoff bas� sur une trajectoire compl�te
    double payoff(const std::vector<double>& path) const;

    // Impl�mentation de la m�thode virtuelle pour le payoff (par d�faut inutilis�e)
    double payoff(double spot) const override;

    // M�thode de pricing Monte-Carlo que l'on va utiliser en cas de maturit� constante
    double price(const BlackScholesModel& model, int numPaths, int steps) const override;

    // Surcharge de la m�thode ci-dessus permettant de prendre en argument la maturit� (utile pour calculer le delta)
    double price(const BlackScholesModel& model, int numPaths, int steps, double adjustedMaturity) const;

    // Co�t de r�plication bas� sur la strat�gie de couverture dynamique
    double hedgeCost(const BlackScholesModel& model, int steps) const override;
};

#endif // LOOKBACK_OPTION_H