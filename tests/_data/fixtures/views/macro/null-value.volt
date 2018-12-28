{%- macro print(object) -%}
    {{- 'Not Null: ' ~ object.notNullValue ~ ' - Null: ' ~ object.nullValue -}}
{%- endmacro -%}

{{- print(object) -}}
