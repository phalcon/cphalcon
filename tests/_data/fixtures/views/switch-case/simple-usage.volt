{% switch username %}
    {% case "Jim" %}
        Hello username
    {% case "Nik" %}
        {{ username }}!
        {% break %}
    {% default %}
        Who are you?
{% endswitch %}
