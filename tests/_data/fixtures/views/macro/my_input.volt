{%- macro my_input(name, class="input-text") -%}
    {%- return text_field(name, 'class': class) -%}
{%- endmacro -%}

{{- '<p>' ~ my_input('name') ~ '</p>' -}}
