namespace cards {

#ifndef SEARCH_LOGIC_HANDLER_H_
#define SEARCH_LOGIC_HANDLER_H_

#include <list>
#include <map>
#include <string>

class SearchLogicHandler
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

    // TODO: add in support for returning based on top percentile of hits,
    //       or based on a minimum total weight threshold, or both

    virtual std::list< std::string >
    getFilepaths( std::map< std::string, int > metadataWeights, double percent = 1.0 ) = 0;
}

#endif /*SEARCH_LOGIC_HANDLER_H_*/

}

