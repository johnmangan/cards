#ifndef ASSET_METADATA_MAPPING_SQLLITE_DATABASE_PREPSTMTS_H_
#define ASSET_METADATA_MAPPING_SQLLITE_DATABASE_PREPSTMTS_H_

#include <string>

namespace cards
{

  const std::string stmt_create_asset_table = "CREATE TABLE Assets (MetaID INTEGER, Name STRING);";
  const std::string stmt_create_metadata_table = "CREATE TABLE Metadata (Name STRING, MetaID INTEGER);";

  const std::string stmt_delete_asset = "DELETE FROM Assets WHERE Name = ?;";
  const std::string stmt_delete_metadata_atable = "DELETE FROM Assets WHERE MetaID = ? AND Name = ?;";
  const std::string stmt_insert_atable = "INSERT INTO Assets VALUES(?,?);";

  const std::string stmt_select_metaID = "SELECT metaID FROM Metadata WHERE Name = ?;";
}

#endif

