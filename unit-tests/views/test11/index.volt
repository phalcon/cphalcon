Length Array: {{ arr|length }}
Length Object: {{ obj|length }}
Length String: {{ str|length }}
Length No String: {{ no_str|length }}
Slice Array: {{ arr[0:]|join(',') }}
Slice Array: {{ arr[1:2]|join(',') }}
Slice Array: {{ arr[:2]|join(',') }}
Slice Object: {{ obj[1:]|join(',') }}
Slice Object: {{ obj[1:2]|join(',') }}
Slice Object: {{ obj[:1]|join(',') }}
Slice String: {{ "hello"[:2] }}
Slice String: {{ "hello"[1:2] }}
Slice String: {{ "hello"[2:] }}
Slice No String: {{ 1234[:2] }}
Slice No String: {{ 1234[1:2] }}
Slice No String: {{ 1234[2:] }}