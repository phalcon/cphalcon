{%- macro formRow(form, tag, attributes = '', col = 6) -%}
    {%- set defaultClass = 'form-control ' -%}

    {%- if attributes is iterable -%}
        {%- for key, value in attributes -%}
            {%- set attr[key] = value -%}
        {%-endfor -%}
    {%- else -%}
        {%- set attr['class'] = defaultClass ~ attributes -%}
    {%-endif -%}

<div class="form-group">
    <label class="col-sm-2 control-label" for="{{ tag }}">{{ form.getLabel(tag) }}:</label>
    <div class="col-sm-{{ col }}">{{ form.render(tag, attr) }}</div>
</div>
{%- endmacro -%}


{{- formRow(formLogin, 'password') -}}
