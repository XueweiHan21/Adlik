// Copyright 2019 ZTE corporation. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#ifndef ADLIK_SERVING_RUNTIME_ML_ALGORITHM_ALGORITHM_FACTORY_H
#define ADLIK_SERVING_RUNTIME_ML_ALGORITHM_ALGORITHM_FACTORY_H

#include <string>
#include <unordered_map>

#include "adlik_serving/runtime/ml/algorithm/algorithm_creator.h"
#include "cub/gof/singleton.h"

namespace ml_runtime {

DEF_SINGLETON(AlgorithmFactory) {
  cub::StatusWrapper create(const std::string& name, const std::string& model_dir, std::unique_ptr<Algorithm>*);
  void add(const std::string&, AlgoCreator);

private:
  std::unordered_map<std::string, AlgoCreator> creators;
};

}  // namespace ml_runtime

#endif
