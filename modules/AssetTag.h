#ifndef ASSET_TAG_H_
#define ASSET_TAG_H_

#include <string>

namespace cards {

class AssetTag
{
public:
    virtual std::string
    getName( void ) const = 0;

    virtual bool
    lessThan( AssetTag const& r ) const = 0;

    friend bool operator< ( AssetTag const& l, AssetTag const& r )
    { return l.lessThan( r ); }

    struct AssetTagComparator
    {
        bool operator() (AssetTag* const&  l, AssetTag* const& r) const
        { return *l < *r; }
    };
};

}

#endif /*ASSET_TAG_H_*/

