<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt\Compiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Exception;

use function is_array;

/**
 * Class ParseCest
 */
class ParseCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: parse()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-15
     *
     * @dataProvider getVoltParse
     */
    public function mvcViewEngineVoltCompilerParse(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - parse()");

        $param = $example[0];
        $count = $example[1];

        $volt   = new Compiler();
        $actual = $volt->parse($param);

        $I->assertTrue(is_array($actual));
        $I->assertCount($count, $actual);
    }

    /**
     * /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: parse() - syntax error
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-15
     *
     * @dataProvider getVoltSyntaxErrors
     */
    public function mvcViewEngineVoltCompilerParseSyntaxError(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - parse() - syntax error");

        $code    = $example[0];
        $message = $example[1];

        $volt = new Compiler();

        $I->expectThrowable(
            new Exception($message),
            function () use ($volt, $code) {
                $volt->parse($code);
            }
        );
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: parse() - extends with
     * error
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-01-15
     *
     * @dataProvider getVoltExtendsError
     */
    public function mvcViewEngineVoltCompilerParseExtendsWithError(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - parse() - extends with error");

        $code    = $example[0];
        $message = $example[1];

        $volt = new Compiler();

        $I->expectThrowable(
            new Exception($message),
            function () use ($volt, $code) {
                $volt->parse($code);
            }
        );
    }

    private function getVoltParse(): array
    {
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
            //Issue 14288 use set() & is()
            ['{{ cookie().set(\'key\', \'value\') }}', 1],
            ['{{ test.is() }}', 1],
            ['{{ test.is(true) }}', 1],
            ['{{ cookie().is(true) }}', 1],
        ];
    }


    private function getVoltSyntaxErrors(): array
    {
        return [
            [
                '{{',
                'Syntax error, unexpected EOF in eval code',
            ],
            [
                '{{ }}',
                'Syntax error, unexpected EOF in eval code',
            ],
            [
                '{{ ++v }}',
                'Syntax error, unexpected token ++ in eval code on line 1',
            ],
            [
                '{{
                    ++v }}',
                'Syntax error, unexpected token ++ in eval code on line 2',
            ],
            [
                '{{


                    if
                for }}',
                'Syntax error, unexpected token IF in eval code on line 4',
            ],
            [
                '{% block some %}
                    {% for x in y %}
                        {{ ."hello".y }}
                    {% endfor %}
                {% endblock %}',
                'Syntax error, unexpected token DOT in eval code on line 3',
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
                'Syntax error, unexpected token IDENTIFIER(y) in eval code on line 8',
            ],
            [
                '{# Hello #}

                {% for robot in robots %}
                    {{ link_to("hello", robot.id ~ ~ robot.name) }}
                {% endfor %}

                ',
                'Syntax error, unexpected token ~ in eval code on line 4',
            ],
            [
                '\'{{ link_to("album/" ~ album.id ~ "/" ~ $album.uri, ' .
                '"<img src=\"" ~ album.url ~ "\" alt=\"" ~ album.name ~ "\"/>") }}\'',
                "Scanning error before 'album.uri, \"<img...' in eval code on line 1",
            ],
        ];
    }


    private function getVoltExtendsError(): array
    {
        return [
            [
                '{{ "hello"}}{% extends "some/file.volt" %}',
                'Extends statement must be placed at the first line in the template in eval code on line 1',
            ],
            [
                '<div>{% extends "some/file.volt" %}{% set a = 1 %}</div>',
                'Extends statement must be placed at the first line in the template in eval code on line 1',
            ],
            [
                '{% extends "some/file.volt" %}{{ "hello"}}',
                'Child templates only may contain blocks in eval code on line 1',
            ],
            [
                '{% extends "some/file.volt" %}{{% if true %}} {%endif%}',
                'Child templates only may contain blocks in eval code on line 1',
            ],
            [
                '{% extends "some/file.volt" %}{{% set a = 1 %}',
                'Child templates only may contain blocks in eval code on line 1',
            ],
            [
                '{% extends "some/file.volt" %}{{% set a = 1 %}',
                'Child templates only may contain blocks in eval code on line 1',
            ],
        ];
    }
}
