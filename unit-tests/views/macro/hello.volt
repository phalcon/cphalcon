{%- macro hello(name) -%}
    {%- return "Hello " ~ name -%}
{%- endmacro -%}

{{- hello('World') -}}
