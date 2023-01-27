<?php
$i = 0;
$tmp = array();
// $tmp = [];
$rand;
while ($i < $argv[1]) {
	$rand = rand($argv[2], $argv[3]);
	if (!in_array($rand, $tmp))
	{
		$tmp[$i] = $rand;
		$i++;
	}
}
foreach ($tmp as $key) {
	# code...
	echo $key . " ";
}