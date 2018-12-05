<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$intermediate = parse_string('{% switch foo%} {% case foo %} {% endswitch%}');
var_dump($intermediate);
