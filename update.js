const con = require('./connect.js');
 
// SQL query to update
const sql = "UPDATE STUDENTS SET College='MACE' WHERE Course='MCA'";
 
    con.query(sql, (err, result) => {
  if (err) throw err;
  console.log('Record inserted successfully!');
    con.end(); // close the connection
});