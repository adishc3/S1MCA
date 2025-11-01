const con = require('./connect.js');
 
// SQL query to insert one record
const sql = "INSERT INTO STUDENTS (ID, Name,Age,Course) VALUES (07, 'Abhijithh','21','MCA')";
 
    con.query(sql, (err, result) => {
  if (err) throw err;
  console.log('Record inserted successfully!');
    con.end(); // close the connection
});
