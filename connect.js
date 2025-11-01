const mysql=require("mysql2");
const con=mysql.createConnection({
    host:'localhost',
    user:'root',
    password:'Root@1234',
    database:'CollegeDB'
    
});
con.connect((err)=>{
    if(err)
    {
        console.error('Error connecting:',err.stack);
        return;
    }
    console.log("connecting to mysql server");
    con.query("CREATE DATABASE IF NOT EXISTS CollegeDB",(err,result)=>{
        if(err)throw err;
        con.end();
    });
});
module.exports=con;