<html>
<body>
<?php
$conn=mysqli_connect("localhost","root","cs288","stock_market");
if ($mysqli->connect_error) {
    die('Connect Error: ' . $mysqli->connect_error);
}
$table="yahoo_2020_12_07_15_12_58";
echo("<h2><font color=\"red\">Table: $table</font></h2>\n");
echo("<h3>Connected</h3>\n");

$result=$conn->query("select * from $table");
$ncol=mysqli_num_fields($result);
echo("number of columns = $ncol");
$table_attrs="border='1'";
echo("<table $table_attrs>");
    echo("<tr>");
        while($field=$result->fetch_field())
        {
            $field_name=$field->name;
            echo("<th>$field_name</th>");

            }
    echo("</tr>");    
    
    while($row=$result->fetch_array()){
        echo("<tr>");
        for($col=0;$col<$ncol;$col++){
            echo("<td>$row[$col]</td>");
        
        }
        echo("</tr>");
    
    }
echo("</table>");
?>
</body>
</html>

