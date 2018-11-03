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
    [
        '{{ "hello"}}{% extends "some/file.volt" %}', 
        'Extends statement must be placed at the first line in the template in eval code on line 1'
    ],
    [
        '<div>{% extends "some/file.volt" %}{% set a = 1 %}</div>', 
        'Extends statement must be placed at the first line in the template in eval code on line 1'
    ],
    ['{% extends "some/file.volt" %}{{ "hello"}}', 'Child templates only may contain blocks in eval code on line 1'],
    [
        '{% extends "some/file.volt" %}{{% if true %}} {%endif%}', 
        'Child templates only may contain blocks in eval code on line 1'
    ],
    ['{% extends "some/file.volt" %}{{% set a = 1 %}', 'Child templates only may contain blocks in eval code on line 1'],
    ['{% extends "some/file.volt" %}{{% set a = 1 %}', 'Child templates only may contain blocks in eval code on line 1'],
];
