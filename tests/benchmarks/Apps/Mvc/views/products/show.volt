<h1>{{ name|e }}</h1>
<p><a href="{{ url('products/show/' ~ id) }}">{{ title|e }}</a></p>
<ul>
{% for item in items %}
{{ partial('partials/item', ['item': item]) }}
{% endfor %}
</ul>
