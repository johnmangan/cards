#ifndef ASSET_TAG_H_
#define ASSET_TAG_H_

#include <string>

namespace cards {

class AssetTag
{
public:
    AssetTag(std::string name);

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

