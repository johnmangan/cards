#ifndef SQLLITE_DATABASE_PREPSTMTS_H_
#define SQLLITE_DATABASE_PREPSTMTS_H_

#include <string>

namespace cards
{

  const std::string stmt_create = "CREATE TABLE AssetLocator (Name STRING, LOD INTEGER, Location STRING);";
  const std::string stmt_delete_noid = "DELETE FROM AssetLocator WHERE Name = ?;";
  const std::string stmt_delete_id = "DELETE FROM AssetLocator WHERE Name = ? AND LOD = ?;";
  const std::string stmt_insert = "INSERT INTO AssetLocator VALUES(?,?,?);";
  const std::string stmt_select = "SELECT * FROM AssetLocator WHERE Name = ?;";
  const std::string stmt_update = "UPDATE AssetLocator SET Location = ? WHERE Name = ? AND LOD = ?;";

}

#endif
