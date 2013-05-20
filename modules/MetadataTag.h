#ifndef METADATA_TAG_H_
#define METADATA_TAG_H_

#include <string>

namespace cards {

class MetadataTag
{
public:
    MetadataTag(std::string name);

    virtual bool
    lessThan ( MetadataTag const& r ) const = 0;

    friend bool operator< ( MetadataTag& l, MetadataTag& r )
    { return l.lessThan( r ); }
};

}

#endif /*METADATA_TAG_H_*/

