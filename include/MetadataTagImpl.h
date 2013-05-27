#ifndef METADATA_TAG_IMPL_H_
#define METADATA_TAG_IMPL_H_

#include <MetadataTag.h>

namespace cards {

class MetadataTagImpl : public MetadataTag
{
public:
    MetadataTagImpl( std::string name );

    virtual std::string
    getName( void ) const;

    virtual bool
    lessThan( MetadataTag const& r ) const;

private:
    std::string mName;
};

}

#endif /*METADATA_TAG_IMPL_H_*/

