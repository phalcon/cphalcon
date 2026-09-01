{%- macro my_input(name, class="input-text") -%}
    {%- return inputText(name, null, ['class': class]) -%}
{%- endmacro -%}

{{- '<p>' ~ my_input('name') ~ '</p>' -}}
