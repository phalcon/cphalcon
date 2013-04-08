{% for item in [5, 6, 7, 8] %}
Index={{ loop.index }}
IndexO={{ loop.index0 }}
RevIndex={{ loop.revindex }}
RevIndexO={{ loop.revindex0 }}
{% endfor %}