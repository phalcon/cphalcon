{%- macro my_input(name, class="input-text") -%}
    {%- return input_text(name, ['class': class]) -%}
{%- endmacro -%}

{{- '<p>' ~ my_input('name') ~ '</p>' -}}
