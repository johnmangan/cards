namespace cards {

#ifndef SEARCH_LOGIC_HANDLER_H_
#define SEARCH_LOGIC_HANDLER_H_

#include <map>
#include <string>

class SearchLogicHandler
{
public:

    /* Funtion: getFilepath
     * Input: Map of Metadata names (e.g, hash-tags) and an integer weight for each.
     * Output: Filepath accessible via the local filesystem to the chosen asset.
     *
     * The weights are meant to be proportional to their sum,
     * thus all weight are relative to the others provided.
     */

    // TODO: add in support for returning based on top percentile of hits,
    //       or based on a minimum total weight threshold, or both

    // TODO: add in support for LOD requirements... discuss with Andrew on Monday
    //       as he has a differing idea of how it may be used than we do

    virtual std::string
    getFilepath( std::map< std::string, int > metadataWeights ) = 0;
}

#endif /*SEARCH_LOGIC_HANDLER_H_*/

}

