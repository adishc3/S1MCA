const con = require('./connect.js');

// SQL query to delete a record
const sql = "DELETE FROM STUDENTS WHERE ID=?";
 const rno=7;
    con.query(sql,[rno], (err, result) => {
  if (err) throw err;
  console.log('Deleted successfully!');
    con.end(); // close the connection
});