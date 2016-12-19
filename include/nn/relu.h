#ifndef RELU_H
#define RELU_H

#include "util/gnn_macros.h"
#include "fmt/printf.h"
#include "nn/factor.h"
#include <memory>
#include "nn/variable.h"

namespace gnn
{

template<typename mode, typename Dtype>
class ReLU : public Factor
{
public:
	static std::string StrType()
	{
		return "ReLU";
	}

	using OutType = std::shared_ptr< DTensorVar<mode, Dtype> >;
	
	OutType CreateOutVar()
	{
		auto out_name = fmt::sprintf("%s:out_0", this->name);
		return std::make_shared< DTensorVar<mode, Dtype> >(out_name);
	}

	ReLU(std::string _name, PropErr _properr = PropErr::T);

};

}

#endif