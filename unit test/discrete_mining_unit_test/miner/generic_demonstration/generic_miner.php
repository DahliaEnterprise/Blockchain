<?php 
//generate the genesis hash
$keep_searching = 1;
while($keep_searching == 1)
{
	$nonce = random_int(0, 9223372036854775806);
	$complete_input = $nonce;
	$complete_input .= "genesisblock";
	$result = hash("sha256", $complete_input);
	$difficulty = 5;
	$compare_string = "";
	$compare_string_index = 0;
	while($compare_string_index < $difficulty)
	{
	$compare_string .= "0";
	$compare_string_index += 1;
	}
	
	$keep_searching_comparison = 1;
	$result_index = 0;
	while($keep_searching_comparison == 1)
	{
		if($result[$result_index] != "0")
		{
			$keep_searching_comparison = 0;
		}
		
		$result_index += 1;
		
		if($result_index > $difficulty)
		{
			$keep_searching_comparison = 2;
		}
	}
	
	if($keep_searching_comparison == 2)
	{
		$keep_searching = 0;
		echo "yup";
	}
}
var_dump($result)
?>
