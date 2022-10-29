#pragma once

#include <vector>

struct STRandomData
{
	unsigned int Rn;
	double X;
};

class CEvaluation
{
private:
  double AVG = 0;
  double Variant = 0;

public:

  CEvaluation() {}
  CEvaluation(const std::vector<STRandomData>& randomData)
  {
    SetVector(randomData);
  };

  void SetVector(const std::vector<STRandomData>& randomData)
  {
    int n = randomData.size();
    double avgVal = 0;

    for (const auto& rd : randomData)
      avgVal += rd.X;
    AVG = avgVal / n;

    double variantVal = 0;

    for (const auto& rd : randomData)
      variantVal += pow(rd.X - AVG, 2);
    Variant = variantVal / (n - 1);
  }

  double GetAVG() { return AVG; }
  double GetVariant() { return Variant; }
  double GetMSD() { return sqrt(Variant); }

};

class CIndirectSignsChek
{
public:
  CIndirectSignsChek(): K(0), N(0) {}
  ~CIndirectSignsChek() {}

  std::pair<int, int> GetKNVals(const std::vector<STRandomData>& data)
  {
    for (int i = 0; i < data.size()/2; i++)
    {
      if (pow(data[2*i].X, 2) + pow(data[2*i + 1].X, 2) < 1)
        K++;
      N++;
    }

    return std::make_pair(K, N);
  }

  
  std::pair<int, int> GetPLVals(const std::vector<STRandomData>& data)
  {
    int i[] = { 0, 0 };
    int j = 0;

    for (int n =0; n< data.size(); n++)
    {
      if (data[n].X == data[data.size() - 1].X)
        i[j++] = n;
      if (j > 1)
        break;
    }

    if (i[1] == 0)
      i[1] = data.size() - 1;

    int P = i[1] - i[0];
    int L = 0;

    for (int n = 0; n < data.size(); n++)
    {
      if (data[n].X == data[n + P].X)
      {
        L = n + P;
        break;
      }
    }

    return std::make_pair(P, L);
  }


public:
  const double pi_4 = 0.785398163397448309616;

private:
  int N;
  int K;
};

namespace my
{
  template<typename ValueType, typename MatchType1, typename MatchType2, typename... MatchTypes
    , typename = std::enable_if_t<   !std::is_floating_point_v<ValueType>
    && !std::is_floating_point_v<MatchType1>
    && !std::is_floating_point_v<ValueType>
    && !(std::is_floating_point_v<MatchTypes> || ...)>>
    bool in(const ValueType& value, const MatchType1& match1, const MatchType2& match2, const MatchTypes&... matches)
  {
    return value == match1 || value == match2 || ((value == matches) || ...);
  }
}
