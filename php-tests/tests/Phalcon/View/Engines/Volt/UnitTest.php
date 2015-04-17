<?php
/**
 * UnitTest.php
 * \Phalcon\View\Engines\Volt\Compiler\\UnitTest
 *
 * Tests the \Phalcon\View\Engines\Volt\Compiler component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\View\Engines\Volt;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Mvc\View\Engine\Volt\Compiler as PhVoltCompiler;

class UnitTest extends PhTestUnitTestCase
{
    public function testVoltParser()
    {

        $volt = new PhVoltCompiler();

        $intermediate = $volt->parse('');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 0);

        //Comments
        $intermediate = $volt->parse('{# hello #}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 0);

        $intermediate = $volt->parse('{# hello #}{# other comment #}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 0);

        //Common Expressions
        $intermediate = $volt->parse('hello');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ 1 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ 1.2 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ false }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ true }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ null }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ "hello" }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ "\'hello\'" }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ "hello" }}{{ "hello" }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 2);

        $intermediate = $volt->parse('{{ "hello" }}-{{ "hello" }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 3);

        $intermediate = $volt->parse('-{{ "hello" }}{{ "hello" }}-');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 4);

        $intermediate = $volt->parse('-{{ "hello" }}-{{ "hello" }}-');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 5);

        $intermediate = $volt->parse('Some = {{ 100+50 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 2);

        $intermediate = $volt->parse('Some = {{ 100-50 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 2);

        $intermediate = $volt->parse('Some = {{ 100*50 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 2);

        $intermediate = $volt->parse('Some = {{ 100/50 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 2);

        $intermediate = $volt->parse('Some = {{ 100%50 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 2);

        $intermediate = $volt->parse('Some = {{ 100~50 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 2);

        //Array acccess
        $intermediate = $volt->parse('{{ a[0 ]}}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ a[0 ][1]}}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ a[0]["hello"] }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ a[0][1.2][false][true] }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ a[0][1.2][false][true][b] }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Attribute access
        $intermediate = $volt->parse('{{ a.b }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ a.b.c }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ (a.b).c }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ a.(b.c) }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Ranges
        $intermediate = $volt->parse('{{ 1..100 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ "Z".."A" }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ 'a'..'z' }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ 'a' .. 'z' }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Unary operators
        $intermediate = $volt->parse('{{ -10 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ !10 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ !a }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ not a }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ -+10 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ !!10 }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Calling functions
        $intermediate = $volt->parse("{{ contents() }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ link_to('hello', 'some-link') }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ form('action': 'save/products', 'method': 'post') }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ form('action': 'save/products', 'method': other_func(1, 2, 3)) }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ partial('hello/x') }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ dump(a) }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ date('Y-m-d', time()) }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ flash.outputMessages() }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ session.get('hello') }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ user.session.get('hello') }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ user.session.get(request.getPost('token')) }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ a[0]('hello') }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ [a[0]('hello').name]|keys }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Arrays
        $intermediate = $volt->parse("{{ [1, 2, 3, 4] }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ ["hello", 2, 1.3, false, true, null] }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ ["hello", 2, 3, false, true, null, [1, 2, "hola"]] }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse("{{ ['first': 1, 'second': 2, 'third': 3] }}");
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Filters
        $intermediate = $volt->parse('{{ "hello"|e }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ ("hello" ~ "lol")|e|length }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ (("hello" ~ "lol")|e|length)|trim }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ "a".."z"|join(",") }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ "My real name is %s"|format(name) }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{{ robot.price|default(10.0) }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //if statement
        $intermediate = $volt->parse('{% if a==b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a!=b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a<b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a>b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a<=b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a>=b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a===b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a!==b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a and b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a or b %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a is defined %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a is not defined %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a in 100 %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a is 100 %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a is not 100 %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a==b and c==d %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a==b or c==d %} hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a==b %} hello {% else %} not hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //for statement
        $intermediate = $volt->parse('{% for a in b %} hello {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for a in b[0] %} hello {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for a in b.c %} hello {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for a in 1..10 %} hello {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for a in 1..10 if a < 5 and a > 7 %} hello {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for k, v in [1, 2, 3] %} hello {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for k, v in [1, 2, 3] if v is odd %} hello {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for v in [1, 2, 3] %} {% break %} {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% for v in [1, 2] %} {% continue %} {% endfor %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //set statement
        $intermediate = $volt->parse('{% set a = 1 %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% set a = b %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% set a = 1.2 %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% set a = 1.2+1*(20/b) and c %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% do 1 %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% do a + b %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% do a - 1.2 %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% do 1.2 + 1 * (20 / b) and c %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% do super()|e %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Autoescape
        $intermediate = $volt->parse('{% autoescape true %} {% endautoescape %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% autoescape false %} {% endautoescape %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Blocks
        $intermediate = $volt->parse('{% block hello %} {% endblock %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% block hello %}{% endblock %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Extends
        $intermediate = $volt->parse('{% extends "some/file.volt" %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Include
        $intermediate = $volt->parse('{% include "some/file.volt" %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Cache
        $intermediate = $volt->parse('{% cache sidebar %} hello {% endcache %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        $intermediate = $volt->parse('{% cache sidebar 500 %} hello {% endcache %}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

        //Mixed
        $intermediate = $volt->parse('{# some comment #}{{ "hello" }}{# other comment }}');
        $this->assertTrue(is_array($intermediate));
        $this->assertEquals(count($intermediate), 1);

    }
}
