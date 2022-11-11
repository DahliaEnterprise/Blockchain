<?php 
//generate the genesis hash
$keep_searching = 1;
while($keep_searching == 1)
{
$nonce = random_int(0, 9223372036854775806);
$complete_input = $nonce;
$complete_input .= "genesisblock";
$result = hash("sha256", $complete_input);
if($result[0] == "0")
{
$keep_searching = 0;
}
}
var_dump($result)
?>
