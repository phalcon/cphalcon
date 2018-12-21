<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$template =<<<EOF
{% switch foo %}
  {% switch %}
  {% endswitch %}
{% endswitch %}
EOF;
parse_string($template);
