<?php

/**
 * Fixture for Volt test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

return [
    ['', 0],
    //Comments
    ['{# hello #}', 0],
    ['{# hello #}{# other comment #}', 0],
    //Common Expressions
    ['hello', 1],
    ['{{ 1 }}', 1],
    ['{{ 1.2 }}', 1],
    ['{{ false }}', 1],
    ['{{ true }}', 1],
    ['{{ null }}', 1],
    ['{{ "hello" }}', 1],
    ['{{ "\'hello\'" }}', 1],
    ['{{ "hello" }}{{ "hello" }}', 2],
    ['{{ "hello" }}-{{ "hello" }}', 3],
    ['-{{ "hello" }}{{ "hello" }}-', 4],
    ['-{{ "hello" }}-{{ "hello" }}-', 5],
    ['Some = {{ 100+50 }}', 2],
    ['Some = {{ 100-50 }}', 2],
    ['Some = {{ 100*50 }}', 2],
    ['Some = {{ 100/50 }}', 2],
    ['Some = {{ 100%50 }}', 2],
    ['Some = {{ 100~50 }}', 2],
    ['{{ a[0 ]}}', 1],
    ['{{ a[0 ][1]}}', 1],
    ['{{ a[0]["hello"] }}', 1],
    ['{{ a[0][1.2][false][true] }}', 1],
    ['{{ a[0][1.2][false][true][b] }}', 1],
    //Attribute access
    ['{{ a.b }}', 1],
    ['{{ a.b.c }}', 1],
    ['{{ (a.b).c }}', 1],
    ['{{ a.(b.c) }}', 1],
    //Ranges
    ['{{ 1..100 }}', 1],
    ['{{ "Z".."A" }}', 1],
    ["{{ 'a'..'z' }}", 1],
    ["{{ 'a' .. 'z' }}", 1],
    //Unary operators
    ['{{ -10 }}', 1],
    ['{{ !10 }}', 1],
    ['{{ !a }}', 1],
    ['{{ not a }}', 1],
    ['{{ 10-- }}', 1],
    ['{{ !!10 }}', 1],
    //Calling functions
    ['{{ contents() }}', 1],
    ["{{ link_to('hello', 'some-link') }}", 1],
    ["{{ form('action': 'save/products', 'method': 'post') }}", 1],
    ["{{ form('action': 'save/products', 'method': other_func(1, 2, 3)) }}", 1],
    ["{{ partial('hello/x') }}", 1],
    ['{{ dump(a) }}', 1],
    ["{{ date('Y-m-d', time()) }}", 1],
    ['{{ flash.outputMessages() }}', 1],
    ["{{ session.get('hello') }}", 1],
    ["{{ user.session.get('hello') }}", 1],
    ["{{ user.session.get(request.getPost('token')) }}", 1],
    ["{{ a[0]('hello') }}", 1],
    ["{{ [a[0]('hello').name]|keys }}", 1],
    //Arrays
    ['{{ [1, 2, 3, 4] }}', 1],
    ['{{ ["hello", 2, 1.3, false, true, null] }}', 1],
    ['{{ ["hello", 2, 3, false, true, null, [1, 2, "hola"]] }}', 1],
    ["{{ ['first': 1, 'second': 2, 'third': 3] }}", 1],
    //Filters
    ['{{ "hello"|e }}', 1],
    ['{{ ("hello" ~ "lol")|e|length }}', 1],
    ['{{ (("hello" ~ "lol")|e|length)|trim }}', 1],
    ['{{ "a".."z"|join(",") }}', 1],
    ['{{ "My real name is %s"|format(name) }}', 1],
    ['{{ robot.price|default(10.0) }}', 1],
    //if statement
    ['{% if a==b %} hello {% endif %}', 1],
    ['{% if a!=b %} hello {% endif %}', 1],
    ['{% if a!=b %} hello {% endif %}', 1],
    ['{% if a<b %} hello {% endif %}', 1],
    ['{% if a>b %} hello {% endif %}', 1],
    ['{% if a<=b %} hello {% endif %}', 1],
    ['{% if a>=b %} hello {% endif %}', 1],
    ['{% if a===b %} hello {% endif %}', 1],
    ['{% if a!==b %} hello {% endif %}', 1],
    ['{% if a and b %} hello {% endif %}', 1],
    ['{% if a or b %} hello {% endif %}', 1],
    ['{% if a is defined %} hello {% endif %}', 1],
    ['{% if a is not defined %} hello {% endif %}', 1],
    ['{% if a is 100 %} hello {% endif %}', 1],
    ['{% if a is not 100 %} hello {% endif %}', 1],
    ['{% if a==b and c==d %} hello {% endif %}', 1],
    ['{% if a==b or c==d %} hello {% endif %}', 1],
    ['{% if a==b %} hello {% else %} not hello {% endif %}', 1],
    ['{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}', 1],
    ['{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}', 1],
    //for statement
    ['{% for a in b %} hello {% endfor %}', 1],
    ['{% for a in b[0] %} hello {% endfor %}', 1],
    ['{% for a in b.c %} hello {% endfor %}', 1],
    ['{% for a in 1..10 %} hello {% endfor %}', 1],
    ['{% for a in 1..10 if a < 5 and a > 7 %} hello {% endfor %}', 1],
    ['{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}', 1],
    ['{% for k, v in [1, 2, 3] %} hello {% endfor %}', 1],
    ['{% for k, v in [1, 2, 3] if v is odd %} hello {% endfor %}', 1],
    ['{% for v in [1, 2, 3] %} {% break %} {% endfor %}', 1],
    ['{% for v in [1, 2] %} {% continue %} {% endfor %}', 1],
    //set statement
    ['{% set a = 1 %}', 1],
    ['{% set a = b %}', 1],
    ['{% set a = 1.2 %}', 1],
    ['{% set a = 1.2+1*(20/b) and c %}', 1],
    ['{% set a[0] = 1 %}', 1],
    ['{% set a[0][1] = 1 %}', 1],
    ['{% set a.y = 1 %}', 1],
    ['{% set a.y.x = 1 %}', 1],
    ['{% set a[0].y = 1 %}', 1],
    ['{% set a.y[0] = 1 %}', 1],
    ['{% do 1 %}', 1],
    ['{% do a + b %}', 1],
    ['{% do a - 1.2 %}', 1],
    ['{% do 1.2 + 1 * (20 / b) and c %}', 1],
    ['{% do super()|e %}', 1],
    //Autoescape
    ['{% autoescape true %} {% endautoescape %}', 1],
    ['{% autoescape false %} {% endautoescape %}', 1],
    //Blocks
    ['{% block hello %} {% endblock %}', 1],
    ['{% block hello %}{% endblock %}', 1],
    //Extends
    ['{% extends "some/file.volt" %}', 1],
    //Include
    ['{% include "some/file.volt" %}', 1],
    //Cache
    ['{% cache sidebar %} hello {% endcache %}', 1],
    ['{% cache sidebar 500 %} hello {% endcache %}', 1],
    //Mixed
    ['{# some comment #}{{ "hello" }}{# other comment }}', 1],
];
