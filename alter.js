const con = require('./connect.js');
 
// SQL query to alter table
const sql = "ALTER TABLE STUDENTS ADD College VARCHAR (20)";
 
    con.query(sql, (err, result) => {
  if (err) throw err;
  console.log('Column added successfully!');
    con.end(); // close the connection
});