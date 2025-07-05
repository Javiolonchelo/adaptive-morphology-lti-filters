#include "Parameters.h"

void Helpers::createSignal(std::vector<double>& result, Params::SignalType signal_type, const unsigned int L) {
  switch (signal_type) {
    case Params::SignalType::WHITE_NOISE:
      for (unsigned int i = 0; i < L; i++)
        result[i] = Helpers::randomDouble();
      break;

    default:  // SignalType::IMPULSE
      result[0] = 1;
      for (unsigned int i = 1; i < L; i++)
        result[i] = 0;
      break;
  }
}

void Helpers::filterUsingDifferenceEquation(std::vector<double>&      in,
                                            std::vector<double>&      out,
                                            const std::vector<double> b,
                                            const std::vector<double> a,
                                            const unsigned int        L) {
  const unsigned int nb = b.size();
  const unsigned int na = a.size();

  out.resize(L, 0);

  for (unsigned int n = 0; n < L; n++) {
    for (unsigned int j = 0; j < nb && j <= n; j++) {
      out[n] += b[j] * in[n - j];
    }
    for (unsigned int j = 1; j < na && j <= n; j++) {
      out[n] -= a[j] * out[n - j];
    }
    out[n] /= a[0];
  }
}

double Helpers::randomDouble(double min, double max) {
  std::uniform_real_distribution<double> dis(min, max);
  return dis(Helpers::gen);
}

double Helpers::randomDoubleNormal(double mean, double stddev) {
  std::normal_distribution<double> dis(mean, stddev);
  return dis(Helpers::gen);
}

int Helpers::randomInt(int min, int max) {
  std::uniform_int_distribution<unsigned int> dis(min, max);
  return dis(Helpers::gen);
}
