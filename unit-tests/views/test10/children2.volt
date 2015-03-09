{% extends "unit-tests/views/test10/parent.volt" %}

{% block title %}Index{% endblock %}

{% block head %}<style type="text/css">.important { color: #336699; } </style> {{ super() }} {% endblock %}

{% block content %}<h1>Index</h1><p class="important">Welcome to my awesome homepage.</p>{% endblock %}

{% block footer %}{{ super() }}{% endblock %}