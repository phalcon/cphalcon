<?php

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt;

use DateTime;
use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Form;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View;
use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\View\Engine\Volt\CompilerTest
 * Tests the Phalcon\Mvc\View\Engine\Volt\Compiler component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\View\Engine\Volt
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class CompilerTest extends UnitTest
{
    /**
     * executed after each test
     */
    protected function _after()
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    public function testVoltParser()
    {
        $this->specify(
            "Volt parser doesn't work as expected",
            function () {
                $volt = new Compiler();

                $intermediate = $volt->parse('');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(0);

                //Comments
                $intermediate = $volt->parse('{# hello #}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(0);

                $intermediate = $volt->parse('{# hello #}{# other comment #}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(0);

                //Common Expressions
                $intermediate = $volt->parse('hello');
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ 1 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ 1.2 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ false }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ true }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ null }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ "hello" }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ "\'hello\'" }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ "hello" }}{{ "hello" }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(2);

                $intermediate = $volt->parse('{{ "hello" }}-{{ "hello" }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(3);

                $intermediate = $volt->parse('-{{ "hello" }}{{ "hello" }}-');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(4);

                $intermediate = $volt->parse('-{{ "hello" }}-{{ "hello" }}-');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(5);

                $intermediate = $volt->parse('Some = {{ 100+50 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(2);

                $intermediate = $volt->parse('Some = {{ 100-50 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(2);

                $intermediate = $volt->parse('Some = {{ 100*50 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(2);

                $intermediate = $volt->parse('Some = {{ 100/50 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(2);

                $intermediate = $volt->parse('Some = {{ 100%50 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(2);

                $intermediate = $volt->parse('Some = {{ 100~50 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(2);

                //Array access
                $intermediate = $volt->parse('{{ a[0 ]}}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ a[0 ][1]}}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ a[0]["hello"] }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ a[0][1.2][false][true] }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ a[0][1.2][false][true][b] }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Attribute access
                $intermediate = $volt->parse('{{ a.b }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ a.b.c }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ (a.b).c }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ a.(b.c) }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Ranges
                $intermediate = $volt->parse('{{ 1..100 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ "Z".."A" }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ 'a'..'z' }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ 'a' .. 'z' }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Unary operators
                $intermediate = $volt->parse('{{ -10 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ !10 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ !a }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ not a }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ 10-- }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ !!10 }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Calling functions
                $intermediate = $volt->parse("{{ contents() }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ link_to('hello', 'some-link') }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ form('action': 'save/products', 'method': 'post') }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ form('action': 'save/products', 'method': other_func(1, 2, 3)) }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ partial('hello/x') }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ dump(a) }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ date('Y-m-d', time()) }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ flash.outputMessages() }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ session.get('hello') }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ user.session.get('hello') }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ user.session.get(request.getPost('token')) }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ a[0]('hello') }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ [a[0]('hello').name]|keys }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Arrays
                $intermediate = $volt->parse("{{ [1, 2, 3, 4] }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ ["hello", 2, 1.3, false, true, null] }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ ["hello", 2, 3, false, true, null, [1, 2, "hola"]] }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse("{{ ['first': 1, 'second': 2, 'third': 3] }}");
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Filters
                $intermediate = $volt->parse('{{ "hello"|e }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ ("hello" ~ "lol")|e|length }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ (("hello" ~ "lol")|e|length)|trim }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ "a".."z"|join(",") }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{{ "My real name is %s"|format(name) }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //if statement
                $intermediate = $volt->parse('{% if a==b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a!=b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a<b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a>b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a<=b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a>=b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a===b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a!==b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a and b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a or b %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a is defined %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a is not defined %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a is 100 %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a is not 100 %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a==b and c==d %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a==b or c==d %} hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% if a==b %} hello {% else %} not hello {% endif %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse(
                    '{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}'
                );
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse(
                    '{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}'
                );
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //for statement
                $intermediate = $volt->parse('{% for a in b %} hello {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for a in b[0] %} hello {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for a in b.c %} hello {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for a in 1..10 %} hello {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for a in 1..10 if a < 5 and a > 7 %} hello {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse(
                    '{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}'
                );
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for k, v in [1, 2, 3] %} hello {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for k, v in [1, 2, 3] if v is odd %} hello {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for v in [1, 2, 3] %} {% break %} {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% for v in [1, 2] %} {% continue %} {% endfor %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //set statement
                $intermediate = $volt->parse('{% set a = 1 %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% set a = b %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% set a = 1.2 %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% set a = 1.2+1*(20/b) and c %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% set a[0] = 1 %}');
                expect(is_array($intermediate))->true();

                $intermediate = $volt->parse('{% set a[0][1] = 1 %}');
                expect(is_array($intermediate))->true();

                $intermediate = $volt->parse('{% set a.y = 1 %}');
                expect(is_array($intermediate))->true();

                $intermediate = $volt->parse('{% set a.y.x = 1 %}');
                expect(is_array($intermediate))->true();

                $intermediate = $volt->parse('{% set a[0].y = 1 %}');
                expect(is_array($intermediate))->true();

                $intermediate = $volt->parse('{% set a.y[0] = 1 %}');
                expect(is_array($intermediate))->true();

                $intermediate = $volt->parse('{% do 1 %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% do a + b %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% do a - 1.2 %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% do 1.2 + 1 * (20 / b) and c %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% do super()|e %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Autoescape
                $intermediate = $volt->parse('{% autoescape true %} {% endautoescape %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% autoescape false %} {% endautoescape %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Blocks
                $intermediate = $volt->parse('{% block hello %} {% endblock %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% block hello %}{% endblock %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Extends
                $intermediate = $volt->parse('{% extends "some/file.volt" %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Include
                $intermediate = $volt->parse('{% include "some/file.volt" %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Cache
                $intermediate = $volt->parse('{% cache sidebar %} hello {% endcache %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                $intermediate = $volt->parse('{% cache sidebar 500 %} hello {% endcache %}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);

                //Mixed
                $intermediate = $volt->parse('{# some comment #}{{ "hello" }}{# other comment }}');
                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);
            }
        );
    }

    public function testVoltSyntaxError()
    {
        $this->specify(
            "Volt parser doesn't throw the proper syntax error",
            function () {
                $volt = new Compiler();

                $volt->parse('{{');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Syntax error, unexpected EOF in eval code"
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (2)",
            function () {
                $volt = new Compiler();

                $volt->parse('{{ }}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Syntax error, unexpected EOF in eval code"
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (3)",
            function () {
                $volt = new Compiler();

                $volt->parse('{{ ++v }}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Syntax error, unexpected token ++ in eval code on line 1"
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (4)",
            function () {
                $volt = new Compiler();

                $volt->parse('{{
                    ++v }}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Syntax error, unexpected token ++ in eval code on line 2"
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (5)",
            function () {
                $volt = new Compiler();

                $volt->parse('{{


                    if
                for }}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Syntax error, unexpected token IF in eval code on line 4"
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (6)",
            function () {
                $volt = new Compiler();

                $i = $volt->parse('{% block some %}
                    {% for x in y %}
                        {{ ."hello".y }}
                    {% endfor %}
                {% endblock %}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Syntax error, unexpected token DOT in eval code on line 3"
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (7)",
            function () {
                $volt = new Compiler();

                $volt->parse('{#

                    This is a multi-line comment

                #}{% block some %}
                    {# This is a single-line comment #}
                    {% for x in y %}
                        {{ "hello"++y }}
                    {% endfor %}
                {% endblock %}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Syntax error, unexpected token IDENTIFIER(y) in eval code on line 8"
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (8)",
            function () {
                $volt = new Compiler();

                $volt->parse('{# Hello #}

                {% for robot in robots %}
                    {{ link_to("hello", robot.id ~ ~ robot.name) }}
                {% endfor %}

                ');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    'Syntax error, unexpected token ~ in eval code on line 4'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper syntax error (9)",
            function () {
                $volt = new Compiler();

                $volt->parse(
                    '{{ link_to("album/" ~ album.id ~ "/" ~ $album.uri, "<img src=\"" ~ album.url ~ "\" alt=\"" ~ album.name ~ "\"/>") }}'
                );
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    "Scanning error before 'album.uri, \"<img...' in eval code on line 1"
                ]
            ]
        );
    }

    public function testVoltRuntimeError()
    {
        $this->specify(
            "Volt parser doesn't throw the proper runtime error",
            function () {
                $volt = new Compiler();

                $volt->compileString('{{ "hello"|unknown }}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Engine\Volt\Exception::class,
                    'Unknown filter "unknown" in eval code on line 1'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper runtime error (2)",
            function () {
                $volt = new Compiler();

                $volt->compileString('{{ "hello"|unknown(1, 2, 3) }}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Engine\Volt\Exception::class,
                    'Unknown filter "unknown" in eval code on line 1'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper runtime error (3)",
            function () {
                $volt = new Compiler();

                $volt->compileString('{{ "hello"|(a-1) }}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Engine\Volt\Exception::class,
                    'Unknown filter type in eval code on line 1'
                ]
            ]
        );
    }

    public function testVoltExtendsError()
    {
        $this->specify(
            "Volt parser doesn't throw the proper extends error",
            function () {
                $volt = new Compiler();

                $volt->parse('{{ "hello"}}{% extends "some/file.volt" %}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    'Extends statement must be placed at the first line in the template in eval code on line 1'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper extends error (2)",
            function () {
                $volt = new Compiler();

                $volt->parse('<div>{% extends "some/file.volt" %}{% set a = 1 %}</div>');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    'Extends statement must be placed at the first line in the template in eval code on line 1'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper extends error (3)",
            function () {
                $volt = new Compiler();

                $volt->parse('{% extends "some/file.volt" %}{{ "hello"}}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    'Child templates only may contain blocks in eval code on line 1'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper extends error (4)",
            function () {
                $volt = new Compiler();

                $volt->parse('{% extends "some/file.volt" %}{{% if true %}} {%endif%}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    'Child templates only may contain blocks in eval code on line 1'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper extends error (5)",
            function () {
                $volt = new Compiler();

                $volt->parse('{% extends "some/file.volt" %}{{% set a = 1 %}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    'Child templates only may contain blocks in eval code on line 1'
                ]
            ]
        );

        $this->specify(
            "Volt parser doesn't throw the proper extends error (6)",
            function () {
                $volt = new Compiler();

                $volt->parse('{% extends "some/file.volt" %}{{% set a = 1 %}');
            },
            [
                "throws" => [
                    \Phalcon\Mvc\View\Exception::class,
                    'Child templates only may contain blocks in eval code on line 1'
                ]
            ]
        );
    }

    public function testVoltCompiler()
    {
        $this->specify(
            "Volt parser doesn't work as expected",
            function () {
                $volt = new Compiler();

                $compilation = $volt->compileString('');
                expect($compilation)->equals('');

                //Comments
                $compilation = $volt->compileString('{# hello #}');
                expect($compilation)->equals('');

                $compilation = $volt->compileString('{# hello #}{# other comment #}');
                expect($compilation)->equals('');

                //Common Expressions
                $compilation = $volt->compileString('hello');
                expect($compilation)->equals('hello');

                $compilation = $volt->compileString('{{ "hello" }}');
                expect($compilation)->equals("<?= 'hello' ?>");

                $compilation = $volt->compileString('{{ "hello" }}{{ "hello" }}');
                expect($compilation)->equals("<?= 'hello' ?><?= 'hello' ?>");

                $compilation = $volt->compileString('{{ "hello" }}-{{ "hello" }}');
                expect($compilation)->equals("<?= 'hello' ?>-<?= 'hello' ?>");

                $compilation = $volt->compileString('-{{ "hello" }}{{ "hello" }}-');
                expect($compilation)->equals("-<?= 'hello' ?><?= 'hello' ?>-");

                $compilation = $volt->compileString('-{{ "hello" }}-{{ "hello" }}-');
                expect($compilation)->equals("-<?= 'hello' ?>-<?= 'hello' ?>-");

                $compilation = $volt->compileString('Some = {{ 100+50 }}');
                expect($compilation)->equals("Some = <?= 100 + 50 ?>");

                $compilation = $volt->compileString('Some = {{ 100-50 }}');
                expect($compilation)->equals("Some = <?= 100 - 50 ?>");

                $compilation = $volt->compileString('Some = {{ 100*50 }}');
                expect($compilation)->equals("Some = <?= 100 * 50 ?>");

                $compilation = $volt->compileString('Some = {{ 100/50 }}');
                expect($compilation)->equals("Some = <?= 100 / 50 ?>");

                $compilation = $volt->compileString('Some = {{ 100%50 }}');
                expect($compilation)->equals("Some = <?= 100 % 50 ?>");

                $compilation = $volt->compileString('Some = {{ 100~50 }}');
                expect($compilation)->equals("Some = <?= 100 . 50 ?>");

                //Unary operators
                $compilation = $volt->compileString('{{ -10 }}');
                expect($compilation)->equals("<?= -10 ?>");

                $compilation = $volt->compileString('{{ !10 }}');
                expect($compilation)->equals("<?= !10 ?>");

                $compilation = $volt->compileString('{{ !a }}');
                expect($compilation)->equals('<?= !$a ?>');

                $compilation = $volt->compileString('{{ not a }}');
                expect($compilation)->equals('<?= !$a ?>');

                //Arrays
                $compilation = $volt->compileString("{% set a = [1, 2, 3, 4] %}");
                expect($compilation)->equals('<?php $a = [1, 2, 3, 4]; ?>');

                $compilation = $volt->compileString(
                    '{% set a = ["hello", 2, 1.3, false, true, null] %}'
                );
                expect($compilation)->equals('<?php $a = [\'hello\', 2, 1.3, false, true, null]; ?>');

                $compilation = $volt->compileString(
                    '{% set a = ["hello", 2, 3, false, true, null, [1, 2, "hola"]] %}'
                );
                expect($compilation)->equals('<?php $a = [\'hello\', 2, 3, false, true, null, [1, 2, \'hola\']]; ?>');

                $compilation = $volt->compileString(
                    "{% set a = ['first': 1, 'second': 2, 'third': 3] %}"
                );
                expect($compilation)->equals('<?php $a = [\'first\' => 1, \'second\' => 2, \'third\' => 3]; ?>');

                //Array access
                $compilation = $volt->compileString('{{ a[0 ]}}');
                expect($compilation)->equals('<?= $a[0] ?>');

                $compilation = $volt->compileString('{{ a[0 ] [ 1]}}');
                expect($compilation)->equals('<?= $a[0][1] ?>');

                $compilation = $volt->compileString('{{ a[0]  [ "hello"] }}');
                expect($compilation)->equals('<?= $a[0][\'hello\'] ?>');

                $compilation = $volt->compileString('{{ a[0] [1.2] [false] [true] }}');
                expect($compilation)->equals('<?= $a[0][1.2][false][true] ?>');

                //Attribute access
                $compilation = $volt->compileString('{{ a.b }}');
                expect($compilation)->equals('<?= $a->b ?>');

                $compilation = $volt->compileString('{{ a.b.c }}');
                expect($compilation)->equals('<?= $a->b->c ?>');

                //Ranges
                $compilation = $volt->compileString('{{ 1..100 }}');
                expect($compilation)->equals('<?= range(1, 100) ?>');

                $compilation = $volt->compileString('{{ "Z".."A" }}');
                expect($compilation)->equals('<?= range(\'Z\', \'A\') ?>');

                $compilation = $volt->compileString("{{ 'a'..'z' }}");
                expect($compilation)->equals('<?= range(\'a\', \'z\') ?>');

                $compilation = $volt->compileString("{{ 'a' .. 'z' }}");
                expect($compilation)->equals('<?= range(\'a\', \'z\') ?>');

                //Calling functions
                $compilation = $volt->compileString("{{ content() }}");
                expect($compilation)->equals('<?= $this->getContent() ?>');

                $compilation = $volt->compileString("{{ get_content() }}");
                expect($compilation)->equals('<?= $this->getContent() ?>');

                $compilation = $volt->compileString("{{ partial('hello/x') }}");
                expect($compilation)->equals('<?= $this->partial(\'hello/x\') ?>');

                $compilation = $volt->compileString("{{ dump(a) }}");
                expect($compilation)->equals('<?= var_dump($a) ?>');

                $compilation = $volt->compileString("{{ date('Y-m-d', time()) }}");
                expect($compilation)->equals('<?= date(\'Y-m-d\', time()) ?>');

                $compilation = $volt->compileString("{{ robots.getPart(a) }}");
                expect($compilation)->equals('<?= $robots->getPart($a) ?>');

                //Phalcon\Tag helpers
                $compilation = $volt->compileString("{{ link_to('hello', 'some-link') }}");
                expect($compilation)->equals('<?= $this->tag->linkTo([\'hello\', \'some-link\']) ?>');

                $compilation = $volt->compileString(
                    "{{ form('action': 'save/products', 'method': 'post') }}"
                );
                expect($compilation)->equals('<?= $this->tag->form([\'action\' => \'save/products\', \'method\' => \'post\']) ?>');

                $compilation = $volt->compileString(
                    "{{ stylesheet_link(config.cdn.css.bootstrap, config.cdn.local) }}"
                );
                expect($compilation)->equals('<?= $this->tag->stylesheetLink($config->cdn->css->bootstrap, $config->cdn->local) ?>');

                $compilation = $volt->compileString("{{ javascript_include('js/some.js') }}");
                expect($compilation)->equals('<?= $this->tag->javascriptInclude(\'js/some.js\') ?>');

                $compilation = $volt->compileString("{{ image('img/logo.png', 'width': 80) }}");
                expect($compilation)->equals("<?= \$this->tag->image(['img/logo.png', 'width' => 80]) ?>");

                $compilation = $volt->compileString(
                    "{{ email_field('email', 'class': 'form-control', 'placeholder': 'Email Address') }}"
                );
                expect($compilation)->equals("<?= \$this->tag->emailField(['email', 'class' => 'form-control', 'placeholder' => 'Email Address']) ?>");

                //Filters
                $compilation = $volt->compileString('{{ "hello"|e }}');
                expect($compilation)->equals('<?= $this->escaper->escapeHtml(\'hello\') ?>');

                $compilation = $volt->compileString('{{ "hello"|escape }}');
                expect($compilation)->equals('<?= $this->escaper->escapeHtml(\'hello\') ?>');

                $compilation = $volt->compileString('{{ "hello"|trim }}');
                expect($compilation)->equals('<?= trim(\'hello\') ?>');

                $compilation = $volt->compileString('{{ "hello"|striptags }}');
                expect($compilation)->equals('<?= strip_tags(\'hello\') ?>');

                $compilation = $volt->compileString('{{ "hello"|json_encode }}');
                expect($compilation)->equals('<?= json_encode(\'hello\') ?>');

                $compilation = $volt->compileString('{{ "hello"|url_encode }}');
                expect($compilation)->equals('<?= urlencode(\'hello\') ?>');

                $compilation = $volt->compileString('{{ "hello"|uppercase }}');
                expect($compilation)->equals('<?= Phalcon\Text::upper(\'hello\') ?>');

                $compilation = $volt->compileString('{{ "hello"|lowercase }}');
                expect($compilation)->equals('<?= Phalcon\Text::lower(\'hello\') ?>');

                $compilation = $volt->compileString('{{ ("hello" ~ "lol")|e|length }}');
                expect($compilation)->equals('<?= $this->length($this->escaper->escapeHtml((\'hello\' . \'lol\'))) ?>');

                //Filters with parameters
                $compilation = $volt->compileString('{{ "My name is %s, %s"|format(name, "thanks") }}');
                expect($compilation)->equals("<?= sprintf('My name is %s, %s', \$name, 'thanks') ?>");

                $compilation = $volt->compileString('{{ "some name"|convert_encoding("utf-8", "latin1") }}');
                expect($compilation)->equals("<?= \$this->convertEncoding('some name', 'utf-8', 'latin1') ?>");

                //if statement
                $compilation = $volt->compileString('{% if a==b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a == $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a!=b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a != $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is not b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a != $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a<b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a < $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a>b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a > $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a>=b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a >= $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a<=b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a <= $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a===b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a === $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a!==b %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a !== $b) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a==b and c==d %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a == $b && $c == $d) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a==b or c==d %} hello {% endif %}');
                expect($compilation)->equals('<?php if ($a == $b || $c == $d) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is odd %} hello {% endif %}');
                expect($compilation)->equals('<?php if (((($a) % 2) != 0)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is even %} hello {% endif %}');
                expect($compilation)->equals('<?php if (((($a) % 2) == 0)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is empty %} hello {% endif %}');
                expect($compilation)->equals('<?php if (empty($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is not empty %} hello {% endif %}');
                expect($compilation)->equals('<?php if (!empty($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is numeric %} hello {% endif %}');
                expect($compilation)->equals('<?php if (is_numeric($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is not numeric %} hello {% endif %}');
                expect($compilation)->equals('<?php if (!is_numeric($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is scalar %} hello {% endif %}');
                expect($compilation)->equals('<?php if (is_scalar($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is not scalar %} hello {% endif %}');
                expect($compilation)->equals('<?php if (!is_scalar($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString(
                    '{% if a is iterable %} hello {% endif %}'
                );
                expect($compilation)->equals('<?php if ((is_array($a) || ($a) instanceof Traversable)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString(
                    '{% if a is not iterable %} hello {% endif %}'
                );
                expect($compilation)->equals('<?php if (!(is_array($a) || ($a) instanceof Traversable)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is sameas(false) %} hello {% endif %}');
                expect($compilation)->equals('<?php if (($a) === (false)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is sameas(b) %} hello {% endif %}');
                expect($compilation)->equals('<?php if (($a) === ($b)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is divisibleby(3) %} hello {% endif %}');
                expect($compilation)->equals('<?php if (((($a) % (3)) == 0)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is divisibleby(b) %} hello {% endif %}');
                expect($compilation)->equals('<?php if (((($a) % ($b)) == 0)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is defined %} hello {% endif %}');
                expect($compilation)->equals('<?php if (isset($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a is not defined %} hello {% endif %}');
                expect($compilation)->equals('<?php if (!isset($a)) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% if a==b %} hello {% else %} not hello {% endif %}');
                expect($compilation)->equals('<?php if ($a == $b) { ?> hello <?php } else { ?> not hello <?php } ?>');

                $compilation = $volt->compileString(
                    '{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}'
                );
                expect($compilation)->equals('<?php if ($a == $b) { ?> <?php if ($c == $d) { ?> hello <?php } ?> <?php } else { ?> not hello <?php } ?>');

                $compilation = $volt->compileString(
                    '{% if a==b %} {% if c==d %} hello {% else %} not hello {% endif %}{% endif %}'
                );
                expect($compilation)->equals('<?php if ($a == $b) { ?> <?php if ($c == $d) { ?> hello <?php } else { ?> not hello <?php } ?><?php } ?>');

                $compilation = $volt->compileString(
                    '{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}'
                );
                expect($compilation)->equals('<?php if ($a == $b) { ?> hello <?php } else { ?> <?php if ($c == $d) { ?> not hello <?php } ?> <?php } ?>');

                $compilation = $volt->compileString(
                    '{% if a is empty or a is defined %} hello {% else %} not hello {% endif %}'
                );
                expect($compilation)->equals('<?php if (empty($a) || isset($a)) { ?> hello <?php } else { ?> not hello <?php } ?>');

                $compilation = $volt->compileString(
                    '{% if a is even or b is odd %} hello {% else %} not hello {% endif %}'
                );
                expect($compilation)->equals('<?php if (((($a) % 2) == 0) || ((($b) % 2) != 0)) { ?> hello <?php } else { ?> not hello <?php } ?>');

                //for statement
                $compilation = $volt->compileString('{% for a in b %} hello {% endfor %}');
                expect($compilation)->equals('<?php foreach ($b as $a) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% for a in b[0] %} hello {% endfor %}');
                expect($compilation)->equals('<?php foreach ($b[0] as $a) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% for a in b.c %} hello {% endfor %}');
                expect($compilation)->equals('<?php foreach ($b->c as $a) { ?> hello <?php } ?>');

                $compilation = $volt->compileString('{% for key, value in [0, 1, 3, 5, 4] %} hello {% endfor %}');
                expect($compilation)->equals('<?php foreach ([0, 1, 3, 5, 4] as $key => $value) { ?> hello <?php } ?>');

                $compilation = $volt->compileString(
                    '{% for key, value in [0, 1, 3, 5, 4] if key!=3 %} hello {% endfor %}'
                );
                expect($compilation)->equals('<?php foreach ([0, 1, 3, 5, 4] as $key => $value) { if ($key != 3) { ?> hello <?php } ?><?php } ?>');

                $compilation = $volt->compileString('{% for a in 1..10 %} hello {% endfor %}');
                expect($compilation)->equals('<?php foreach (range(1, 10) as $a) { ?> hello <?php } ?>');

                $compilation = $volt->compileString(
                    '{% for a in 1..10 if a is even %} hello {% endfor %}'
                );
                expect($compilation)->equals('<?php foreach (range(1, 10) as $a) { if (((($a) % 2) == 0)) { ?> hello <?php } ?><?php } ?>');

                $compilation = $volt->compileString(
                    '{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}'
                );
                expect($compilation)->equals('<?php foreach (range(1, 10) as $a) { ?> <?php foreach (range(1, 10) as $b) { ?> hello <?php } ?> <?php } ?>');

                $compilation = $volt->compileString('{% for a in 1..10 %}{% break %}{% endfor %}');
                expect($compilation)->equals('<?php foreach (range(1, 10) as $a) { ?><?php break; ?><?php } ?>');

                $compilation = $volt->compileString('{% for a in 1..10 %}{% continue %}{% endfor %}');
                expect($compilation)->equals('<?php foreach (range(1, 10) as $a) { ?><?php continue; ?><?php } ?>');

                //set statement
                $compilation = $volt->compileString('{% set a = 1 %}');
                expect($compilation)->equals('<?php $a = 1; ?>');

                $compilation = $volt->compileString('{% set a = a-1 %}');
                expect($compilation)->equals('<?php $a = $a - 1; ?>');

                $compilation = $volt->compileString('{% set a = 1.2 %}');
                expect($compilation)->equals('<?php $a = 1.2; ?>');

                $compilation = $volt->compileString('{% set a = 1.2+1*(20/b) and c %}');
                expect($compilation)->equals('<?php $a = 1.2 + 1 * (20 / $b) && $c; ?>');

                // Cache statement
                $compilation = $volt->compileString('{% cache somekey %} hello {% endcache %}');
                expect($compilation)->equals('<?php $_cache[$somekey] = $this->di->get(\'viewCache\'); $_cacheKey[$somekey] = $_cache[$somekey]->start($somekey); if ($_cacheKey[$somekey] === null) { ?> hello <?php $_cache[$somekey]->save($somekey); } else { echo $_cacheKey[$somekey]; } ?>');

                $compilation = $volt->compileString(
                    '{% set lifetime = 500 %}{% cache somekey lifetime %} hello {% endcache %}'
                );
                expect($compilation)->equals('<?php $lifetime = 500; ?><?php $_cache[$somekey] = $this->di->get(\'viewCache\'); $_cacheKey[$somekey] = $_cache[$somekey]->start($somekey, $lifetime); if ($_cacheKey[$somekey] === null) { ?> hello <?php $_cache[$somekey]->save($somekey, null, $lifetime); } else { echo $_cacheKey[$somekey]; } ?>');

                $compilation = $volt->compileString('{% cache somekey 500 %} hello {% endcache %}');
                expect($compilation)->equals('<?php $_cache[$somekey] = $this->di->get(\'viewCache\'); $_cacheKey[$somekey] = $_cache[$somekey]->start($somekey, 500); if ($_cacheKey[$somekey] === null) { ?> hello <?php $_cache[$somekey]->save($somekey, null, 500); } else { echo $_cacheKey[$somekey]; } ?>');

                //Autoescape mode
                $compilation = $volt->compileString(
                    '{{ "hello" }}{% autoescape true %}{{ "hello" }}{% autoescape false %}{{ "hello" }}{% endautoescape %}{{ "hello" }}{% endautoescape %}{{ "hello" }}'
                );
                expect($compilation)->equals("<?= 'hello' ?><?= \$this->escaper->escapeHtml('hello') ?><?= 'hello' ?><?= \$this->escaper->escapeHtml('hello') ?><?= 'hello' ?>");

                //Mixed
                $compilation = $volt->compileString('{# some comment #}{{ "hello" }}{# other comment }}');
                expect($compilation)->equals("<?= 'hello' ?>");

                //Autoescape from options
                $volt->setOption("autoescape", true);
                $compilation = $volt->compileString(
                    '{{ "hello" }}{% autoescape true %}{{ "hello" }}{% autoescape false %}{{ "hello" }}{% endautoescape %}{{ "hello" }}{% endautoescape %}{{ "hello" }}'
                );
                expect($compilation)->equals("<?= \$this->escaper->escapeHtml('hello') ?><?= \$this->escaper->escapeHtml('hello') ?><?= 'hello' ?><?= \$this->escaper->escapeHtml('hello') ?><?= \$this->escaper->escapeHtml('hello') ?>");
            }
        );
    }

    public function testVoltUsersFunctions()
    {
        $this->specify(
            "Custom functions should work",
            function () {
                $volt = new Compiler();

                //Single string function
                $volt->addFunction('random', 'mt_rand');

                //Function with closure
                $volt->addFunction('shuffle', function ($arguments, $exprArguments) {
                    return 'str_shuffle(' . $arguments . ')';
                });

                $volt->addFunction('strtotime', 'strtotime');

                $compilation = $volt->compileString('{{ random() }}');
                expect($compilation)->equals('<?= mt_rand() ?>');

                $compilation = $volt->compileString('{{ shuffle("hello") }}');
                expect($compilation)->equals('<?= str_shuffle(\'hello\') ?>');

                $compilation = $volt->compileString('{{ strtotime("now") }}');
                expect($compilation)->equals("<?= strtotime('now') ?>");
            }
        );
    }

    public function testVoltUsersFilters()
    {
        $this->specify(
            "Custom filters should work",
            function () {
                $volt = new Compiler();

                //Single string filter
                $volt->addFilter('reverse', 'strrev');

                //Filter with closure
                $volt->addFilter('separate', function ($arguments, $exprArguments) {
                    return 'explode(",", '.$arguments.')';
                });



                $compilation = $volt->compileString('{{ "hello"|reverse }}');

                expect($compilation)->equals('<?= strrev(\'hello\') ?>');



                $compilation = $volt->compileString('{{ "1,2,3,4"|separate }}');

                expect($compilation)->equals('<?= explode(",", \'1,2,3,4\') ?>');
            }
        );
    }

    public function testVoltCompilerFile()
    {
        $this->specify(
            "Volt can't compile files properly",
            function () {
                @unlink(PATH_DATA . 'views/layouts/test10.volt.php');

                $volt = new Compiler();

                //Simple file
                $volt->compileFile(
                    PATH_DATA . 'views/layouts/test10.volt',
                    PATH_DATA . 'views/layouts/test10.volt.php'
                );

                $compilation = file_get_contents(PATH_DATA . 'views/layouts/test10.volt.php');

                expect($compilation)->equals('<?php if ($some_eval) { ?>
Clearly, the song is: <?= $this->getContent() ?>.
<?php } ?>');
            }
        );
    }

    public function testVoltCompilerExtendsFile()
    {
        $this->specify(
            "Volt files can't extend other files",
            function () {
                @unlink(PATH_DATA . 'views/layouts/test10.volt.php');
                @unlink(PATH_DATA . 'views/test10/children.extends.volt.php');

                $view = new View();
                $view->setViewsDir(PATH_DATA . 'views/');

                $volt = new Compiler($view);

                //extends
                $volt->compileFile(
                    PATH_DATA . 'views/test10/children.extends.volt',
                    PATH_DATA . 'views/test10/children.extends.volt.php'
                );

                $compilation = file_get_contents(PATH_DATA . 'views/test10/children.extends.volt.php');

                expect($compilation)->equals('<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; }</style><title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome on my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>');
            }
        );
    }

    public function testVoltCompilerImportFile()
    {
        $this->specify(
            "Volt files can't import other files",
            function () {
                @unlink(PATH_DATA . 'views/partials/header.volt.php');
                @unlink(PATH_DATA . 'views/partials/footer.volt.php');
                @unlink(PATH_DATA . 'views/test10/import.volt.php');

                $view = new View();
                $view->setViewsDir(PATH_DATA . 'views/');

                $volt = new Compiler($view);

                //extends
                $volt->compileFile(
                    PATH_DATA . 'views/test10/import.volt',
                    PATH_DATA . 'views/test10/import.volt.php'
                );

                $compilation = file_get_contents(PATH_DATA . 'views/test10/import.volt.php');

                expect($compilation)->equals('<div class="header"><h1>This is the header</h1></div><div class="footer"><p>This is the footer</p></div>');
            }
        );
    }

    public function testVoltCompilerImportRecursiveFile()
    {
        $this->specify(
            "Volt files can't recursively import files",
            function () {
                @unlink(PATH_DATA . 'views/partials/header3.volt.php');
                @unlink(PATH_DATA . 'views/partials/header2.volt.php');
                @unlink(PATH_DATA . 'views/test10/import2.volt.php');

                $view = new View();
                $view->setViewsDir(PATH_DATA . 'views/');

                $volt = new Compiler($view);

                //extends
                $volt->compileFile(
                    PATH_DATA . 'views/test10/import2.volt',
                    PATH_DATA . 'views/test10/import2.volt.php'
                );

                $compilation = file_get_contents(PATH_DATA . 'views/test10/import2.volt.php');

                expect($compilation)->equals('<div class="header"><h1>This is the title</h1></div>');
            }
        );
    }

    public function testVoltEngine()
    {
        $this->specify(
            "Volt engine doesn't work as expected",
            function () {
                @unlink(PATH_DATA . 'views/layouts/test10.volt.php');
                @unlink(PATH_DATA . 'views/test10/index.volt.php');
                @unlink(PATH_DATA . 'views/test10/other.volt.php');

                $di = new Di();

                $view = new View();
                $view->setDI($di);
                $view->setViewsDir(PATH_DATA . 'views/');

                $view->registerEngines(array(
                    '.volt' => 'Phalcon\Mvc\View\Engine\Volt'
                ));

                $view->setParamToView('song', 'Rock n roll');

                $view->start();
                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
                $view->render('test10', 'index');
                $view->finish();
                expect($view->getContent())->equals('Hello Rock n roll!');

                $view->setParamToView('some_eval', true);

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test10', 'index');
                $view->finish();
                expect($view->getContent())->equals('Clearly, the song is: Hello Rock n roll!.' . PHP_EOL);

                //Refreshing generated view
                file_put_contents(PATH_DATA . 'views/test10/other.volt', '{{song}} {{song}}');

                $view->setParamToView('song', 'Le Song');

                $view->start();
                $view->setRenderLevel(View::LEVEL_ACTION_VIEW);
                $view->render('test10', 'other');
                $view->finish();
                expect($view->getContent())->equals('Le Song Le Song');

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test10', 'other');
                $view->finish();
                expect($view->getContent())->equals('Clearly, the song is: Le Song Le Song.' . PHP_EOL);

                //Change the view
                file_put_contents(PATH_DATA . 'views/test10/other.volt', 'Two songs: {{song}} {{song}}');

                $view->start();
                $view->setRenderLevel(View::LEVEL_LAYOUT);
                $view->render('test10', 'other');
                $view->finish();
                expect($view->getContent())->equals('Clearly, the song is: Two songs: Le Song Le Song.' . PHP_EOL);
            }
        );
    }

    public function testVoltMacros()
    {
        $this->specify(
            "Volt macros don't work",
            function () {
                $this->removeFiles([
                    PATH_DATA . 'views/macro/hello.volt.php',
                    PATH_DATA . 'views/macro/conditionaldate.volt.php',
                    PATH_DATA . 'views/macro/my_input.volt.php',
                    PATH_DATA . 'views/macro/error_messages.volt.php',
                    PATH_DATA . 'views/macro/related_links.volt.php',
                    PATH_DATA . 'views/macro/strtotime.volt.php',
                ]);

                Di::reset();

                $view = new View;
                $di = new Di;
                $di->set('escaper', function () {
                    return new Escaper;
                });
                $di->set('tag', function () {
                    return new Tag;
                });
                $di->set('url', function () {
                    return (new Url)->setBaseUri('/');
                });

                $view->setDI($di);

                $view->setViewsDir(PATH_DATA . 'views/');

                $view->registerEngines(array(
                    '.volt' => function ($view, $di) {
                        $volt = new Volt($view, $di);
                        $compiler = $volt->getCompiler();
                        $compiler->addFunction('strtotime', 'strtotime');
                        return $volt;
                    }
                ));

                $view->start();
                $view->render('macro', 'hello');
                $view->finish();
                expect($view->getContent())->equals('Hello World');

                $view->start();
                $view->render('macro', 'conditionaldate');
                $view->finish();
                expect($view->getContent())->equals(sprintf('from <br/>%s, %s UTC', date('Y-m-d'), date('H:i')));

                $view->start();
                $view->render('macro', 'my_input');
                $view->finish();
                expect($view->getContent())->equals('<p><input type="text" id="name" name="name" class="input-text" /></p>');

                $view->start();
                $view->render('macro', 'error_messages');
                $view->finish();
                expect($view->getContent())->equals('<div><span class="error-type">Invalid</span><span class="error-field">name</span><span class="error-message">The name is invalid</span></div>');

                $view->setVar(
                    'links',
                    array(
                        (object) array(
                            'url' => 'localhost',
                            'text' => 'Menu item',
                            'title' => 'Menu title'
                        )
                    )
                );
                $view->start();
                $view->render('macro', 'related_links');
                $view->finish();
                expect($view->getContent())->equals('<ul><li><a href="/localhost" title="Menu title">Menu item</a></li></ul>');

                $view->setVar('date', new DateTime());
                $view->start();
                $view->render('macro', 'strtotime');
                $view->finish();

                $content = $view->getContent();
                $content = explode('%', $content);

                expect($content)->count(3);
                expect($content[0])->equals($content[1]);
                expect($content[1])->equals($content[2]);
                expect($content[2])->equals($content[0]);

                $this->removeFiles([
                    PATH_DATA . 'views/macro/hello.volt.php',
                    PATH_DATA . 'views/macro/conditionaldate.volt.php',
                    PATH_DATA . 'views/macro/my_input.volt.php',
                    PATH_DATA . 'views/macro/error_messages.volt.php',
                    PATH_DATA . 'views/macro/related_links.volt.php',
                    PATH_DATA . 'views/macro/strtotime.volt.php',
                ]);
            }
        );
    }

    public function testVoltMacrosIssue11771()
    {
        $this->specify(
            "Volt macros can't accept objects",
            function () {
                $this->removeFiles([
                    PATH_DATA . 'views/macro/list.volt.php',
                    PATH_DATA . 'views/macro/form_row.volt.php',
                ]);

                Di::reset();
                $view = new View;
                $di = new Di;
                $di->set('escaper', function () {
                    return new Escaper;
                });
                $di->set('tag', function () {
                    return new Tag;
                });
                $di->set('url', function () {
                    return (new Url)->setBaseUri('/');
                });

                $view->setDI($di);
                $view->setViewsDir(PATH_DATA . 'views/');
                $view->registerEngines(array(
                    '.volt' => function ($view, $di) {
                        return new Volt($view, $di);
                    }
                ));
                $object = new \stdClass();
                $object->foo = "bar";
                $object->baz = "buz";
                $object->pi  = 3.14;
                $object->ary = ["some array"];
                $object->obj = clone $object;
                $view->setVar('object', $object);
                $view->start();
                $view->render('macro', 'list');
                $view->finish();
                ob_start();
                var_dump($object);
                $actual = ob_get_clean();
                // Trim xdebug first line (file path)
                $actual   = substr($actual, strpos($actual, 'class'));
                $expected = substr($view->getContent(), strpos($view->getContent(), 'class'));

                expect($actual)->equals($expected);

                $form = new Form;
                $form->add(new Password('password'));
                $view->setVar('formLogin', $form);
                $view->start();
                $view->render('macro', 'form_row');
                $view->finish();
                $actual =<<<FORM
<div class="form-group">
    <label class="col-sm-2 control-label" for="password">password:</label>
    <div class="col-sm-6"><input type="password" id="password" name="password" class="form-control " /></div>
</div>
FORM;

                expect($actual)->equals($view->getContent());

                $this->removeFiles([
                    PATH_DATA . 'views/macro/list.volt.php',
                    PATH_DATA . 'views/macro/form_row.volt.php',
                ]);
            }
        );
    }

    public function testVoltEngineLoopContext()
    {
        $this->specify(
            "Volt loops don't work",
            function () {
                $volt = new Compiler();
                $compiled = $volt->compileString('{% for i in 1..5 %}{{ loop.self.index }}{% endfor %}');
                ob_start();
                eval('?>'.$compiled);

                $result = ob_get_clean();

                expect($result)->equals('12345');
            }
        );
    }

    protected function removeFiles($files)
    {
        if (!is_array($files)) {
            $files = array($files);
        }
        foreach ($files as $file) {
            if (file_exists($file) && is_readable($file)) {
                @unlink($file);
            }
        }
    }
}
