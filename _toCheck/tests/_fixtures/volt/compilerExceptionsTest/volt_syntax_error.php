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
    ['{{', 'Syntax error, unexpected EOF in eval code'],
    ['{{ }}', 'Syntax error, unexpected EOF in eval code'],
    ['{{ ++v }}', 'Syntax error, unexpected token ++ in eval code on line 1'],
    [
        '{{
                    ++v }}',
        'Syntax error, unexpected token ++ in eval code on line 2'
    ],
    [
        '{{


                    if
                for }}',
        'Syntax error, unexpected token IF in eval code on line 4'
    ],
    [
        '{% block some %}
                    {% for x in y %}
                        {{ ."hello".y }}
                    {% endfor %}
                {% endblock %}',
        'Syntax error, unexpected token DOT in eval code on line 3'
    ],
    [
        '{#

                    This is a multi-line comment

                #}{% block some %}
                    {# This is a single-line comment #}
                    {% for x in y %}
                        {{ "hello"++y }}
                    {% endfor %}
                {% endblock %}',
        'Syntax error, unexpected token IDENTIFIER(y) in eval code on line 8'
    ],
    [
        '{# Hello #}

                {% for robot in robots %}
                    {{ link_to("hello", robot.id ~ ~ robot.name) }}
                {% endfor %}

                ',
        'Syntax error, unexpected token ~ in eval code on line 4'
    ],
    [
        '\'{{ link_to("album/" ~ album.id ~ "/" ~ $album.uri, "<img src=\"" ~ album.url ~ "\" alt=\"" ~ album.name ~ "\"/>") }}\'',
        "Scanning error before 'album.uri, \"<img...' in eval code on line 1"
    ],
];
