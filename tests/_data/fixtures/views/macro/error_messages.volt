{%- macro error_messages(message, field, type) -%}
    <div><span class="error-type">{{ type }}</span><span class="error-field">{{ field }}</span><span class="error-message">{{ message }}</span></div>
{%- endmacro -%}

{{- error_messages('type': 'Invalid', 'message': 'The name is invalid', 'field': 'name') -}}
