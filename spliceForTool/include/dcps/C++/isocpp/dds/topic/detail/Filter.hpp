/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to  ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef OSPL_DDS_TOPIC_DETAIL_FILTER_HPP_
#define OSPL_DDS_TOPIC_DETAIL_FILTER_HPP_

/**
 * @file
 */

// Implementation

#include <vector>
#include <iterator>

namespace dds
{
namespace topic
{
namespace detail
{
class Filter;
}
}
}

class dds::topic::detail::Filter
{
public:
    typedef std::vector<std::string>::iterator iterator;
    typedef std::vector<std::string>::const_iterator const_iterator;

public:
    Filter() {}
    Filter(const std::string& query_expression)
        : expression_(query_expression) { }


    template <typename FWIterator>
    Filter(const std::string& query_expression,
           const FWIterator& params_begin, const FWIterator& params_end)
        : expression_(query_expression)
    {
        std::copy(params_begin, params_end, std::back_insert_iterator<std::vector<std::string> >(params_));
    }


    const std::string& expression() const
    {
        return expression_;
    }

    /**
    *  @internal Provides the begin iterator to the parameter list.
    */
    const_iterator begin() const
    {
        return params_.begin();
    }

    /**
     *  @internal The const end iterator to the parameter list.
     */
    const_iterator end() const
    {
        return params_.end();
    }

    /**
     *  @internal Provides the begin const iterator to the parameter list.
     */
    iterator begin()
    {
        return params_.begin();
    }

    /**
     *  @internal The end iterator to the parameter list.
     */
    iterator end()
    {
        return params_.end();
    }

    template <typename FWIterator>
    void parameters(const FWIterator& begin, const FWIterator end)
    {
        params_.erase(params_.begin(), params_.end());
        std::copy(begin, end, std::back_insert_iterator<std::vector<std::string> >(params_));
    }

    void add_parameter(const std::string& param)
    {
        params_.push_back(param);
    }

    uint32_t parameters_length() const
    {
        return static_cast<uint32_t>(params_.size());
    }

    bool operator ==(const Filter& other) const
    {
        return other.expression_ == expression_ && params_ == params_;
    }

private:
    std::string expression_;
    std::vector<std::string> params_;
};


// End of implementation

#endif /* OSPL_DDS_TOPIC_DETAIL_FILTER_HPP_ */
