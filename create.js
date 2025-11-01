const con = require('./connect.js');
 
const cr = `
    CREATE TABLE IF NOT EXISTS STUDENTS (
        ID INT PRIMARY KEY,
        Name VARCHAR(15),Age INT,Course VARCHAR(20)
    )
`;
 
// Run the query
con.query(cr, (err) => {
    if (err) throw err;
    console.log('Table students created');
});