<?php require(dirname(dirname(dirname(__DIR__))) . "/../bootstrap.inc");

$template =<<<EOF
{% switch username %}
    {% case "Jim" %}
        Hello username
    {% case "Nik" %}
        {{ username }}!
        {% break %}
    {% default %}
        Who are you?
{% endswitch %}
EOF;
$intermediate = parse_string($template);
var_dump($intermediate);
