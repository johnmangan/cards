#ifndef QUERY_INTERFACE_H_
#define QUERY_INTERFACE_H_

#include <vector>
#include <map>
#include <string>

namespace cards {

class IQuery
{
public:

    /* Funtion: getFilepath
     * Input: metadataWeights- Map of Metadata names (e.g, hash-tags) and an integer
     *                         weight for each.
     *        percent- Value from 0.0 to 1.0 representing how close to optimal is desired.
     *                 0.0 implies the desire for any asset that has some correlation to
     *                 the metadata given. 1.0 implies the desire for the highest ranked
     *                 asset calculated from the given metadata. 
     * Output: Ordered filepaths accessible via the local filesystem to the chosen asset.
     *         Filepaths will be ordered from lowest to highest level of detail.
     *
     * The weights are meant to be proportional to their sum,
     * thus all weights are relative to the others provided.
     */

    virtual std::vector< std::string >
    getFilepaths( std::map< std::string, int > metadataWeights, double percent = 1.0 ) = 0;
};

}

#endif /*QUERY_INTERFACE_H_*/

