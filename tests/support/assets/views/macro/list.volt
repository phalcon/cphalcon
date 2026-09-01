{%- macro list(var) -%}
    {{- dump(var) -}}
{%- endmacro -%}

{{- list(object) -}}
