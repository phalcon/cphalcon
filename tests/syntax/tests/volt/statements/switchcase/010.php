<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$template =<<<EOF
{% switch %}
  {% case foo %}
  {% break %}
{% endswitch %}
EOF;
$intermediate = parse_string($template);
var_dump($intermediate);
