<html lang="ja">

   <head>
   <meta charset="utf-8">
   <link rel="stylesheet" href="school.css" type="text/css">
   <title>School_information</title>
   </head>

   <body>

   <div class="words">
   <h1>School information</h1>
   <div id="word">学校内のセンサ情報を確認できます</div>


<?php
   //user:indev pw:5inDevelop server:10.64.199.71に接続
   $link = mysql_connect('10.64.199.71','indev','5inDevelop');
mysql_set_charset('utf8',$link);

if(!$link){
  die('Could not connect:'.mysql_error());
}

//db:schoolout選択
if(!mysql_select_db('sensor_value',$link)){
  die('Could not select database:'.mysql_error());
}

//sqlでデータベースへの問い合わせ
$result = mysql_query("SELECT * FROM schoolout;");
if(!$result){
  die('Could not query:'.mysql_error());
}

//データ出力
echo '<table border="1">';
while($row = mysql_fetch_assoc($result)){
  echo '<tr>';
  echo '<th>'.$row['timestamp'].'</th>';
  echo '<th>'.$row['windspe'].'</th>';
  echo '<th>'.$row['winddet'].'</th>';
  echo '<th>'.$row['temp'].'</th>';
  echo '<th>'.$row['hum'].'</th>';
  echo '<th>'.$row['rain'].'</th>';
  echo '<th>'.$row['press'].'</th>';
  echo '<th>'.$row['plane'].'</th>';
  echo '<th>'.$row['i_temp'].'</th>';
  echo '<th>'.$row['t_rain'].'</th>';
  echo '<th>'.$row['a_wind'].'</th>';
}
echo '</table>';

//dbとの接続を切る
$con=mysql_close($link);
if($con){
  die('Could not close:'.mysql_error());

}
?>






</body>
</html>
