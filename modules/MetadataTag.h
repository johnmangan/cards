#ifndef METADATA_TAG_H_
#define METADATA_TAG_H_

#include <string>

namespace cards {

class MetadataTag
{
public:
    virtual std::string
    getName( void ) const = 0;

    virtual bool
    lessThan( MetadataTag const& r ) const = 0;

    friend bool operator< ( MetadataTag const& l, MetadataTag const& r )
    { return l.lessThan( r ); }

    struct MetadataTagComparator
    {
        bool operator() (MetadataTag* const&  l, MetadataTag* const& r) const
        { return *l < *r; }
    };
};

}

#endif /*METADATA_TAG_H_*/

