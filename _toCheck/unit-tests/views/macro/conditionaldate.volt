{%- macro conditionaldate(condition, tdate, ttime, tz) -%}
    {%- if condition -%} from <br/>{{ tdate }}, {{ ttime }} {{ tz }}{%- endif -%}
{%- endmacro -%}

{%- set tdate = date('Y-m-d') -%}
{%- set ttime = date('H:i') -%}
{%- set tz = 'UTC' -%}

{{- conditionaldate(true, tdate, ttime, tz) -}}
