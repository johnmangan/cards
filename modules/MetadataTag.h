namespace cards {

#ifndef METADATA_TAG_H_
#define METADATA_TAG_H_

#include <string>

class MetadataTag
{
public:
    virtual
    MetadataTag(std::string name) = 0;
}

#endif /*METADATA_TAG_H_*/

}

