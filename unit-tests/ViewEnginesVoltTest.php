<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\View\Engine\Volt\Compiler;

class SomeObject implements Iterator, Countable
{
	private $_data = array();

	private $_pointer = 0;

	public function __construct($data)
	{
		$this->_data = $data;
	}

	public function count()
	{
		return count($this->_data);
	}

	public function current()
	{
		return $this->_data[$this->_pointer];
	}

	public function key()
	{
		return $this->_pointer;
	}

	public function next()
	{
		++$this->_pointer;
	}

	public function rewind()
	{
		$this->_pointer = 0;
	}

	public function valid()
	{
		return $this->_pointer < count($this->_data);
	}
}

function phalcon_prepare_virtual_path($path, $separator) {
	$virtual_str = '';

	if (!is_string($path) || !is_string($separator)) {
		if (is_string($path)) {
			return $path;
		} else {
			return "";
		}
	}

	for ($i = 0; $i < strlen($path); $i++) {
		$ch = $path[$i];
		if ($ch == '\0') {
			break;
		}
		if ($ch == '/' || $ch == '\\' || $ch == ':') {
			$virtual_str .= $separator;
		} else {
			$virtual_str .= strtolower($ch);
		}
	}

	return $virtual_str;
}

class ViewEnginesVoltTest extends PHPUnit_Framework_TestCase
{

	public function testVoltParser()
	{

		$volt = new Compiler();

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

		$intermediate = $volt->parse('{{ 10-- }}');
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

	public function testVoltSyntaxError()
	{
		$volt = new Compiler();

		try {
			$volt->parse('{{');
			$this->assertTrue(false);
		} catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected EOF in eval code');
		}

		try {
			$volt->parse('{{ }}');
			$this->assertTrue(false);
		} catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected EOF in eval code');
		}

		try {
			$volt->parse('{{ ++v }}');
			$this->assertTrue(false);
		} catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected token ++ in eval code on line 1');
		}

		try {
			$volt->parse('{{
				++v }}');
			$this->assertTrue(false);
		} catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected token ++ in eval code on line 2');
		}

		try {
			$volt->parse('{{


				if
			for }}');
			$this->assertTrue(false);
		}
		catch(Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected token IF in eval code on line 4');
		}

		try {
			$i = $volt->parse('{% block some %}
				{% for x in y %}
					{{ ."hello".y }}
				{% endfor %}
			{% endblock %}');
			print_r($i);
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected token DOT in eval code on line 3');
		}

		try {
			$volt->parse('{#

				This is a multi-line comment

			#}{% block some %}
				{# This is a single-line comment #}
				{% for x in y %}
					{{ "hello"++y }}
				{% endfor %}
			{% endblock %}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected token IDENTIFIER(y) in eval code on line 8');
		}

		try {
			$volt->parse('{# Hello #}

			{% for robot in robots %}
				{{ link_to("hello", robot.id ~ ~ robot.name) }}
			{% endfor %}

			');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Syntax error, unexpected token ~ in eval code on line 4');
		}

		try {
			$volt->parse('{{ link_to("album/" ~ album.id ~ "/" ~ $album.uri, "<img src=\"" ~ album.url ~ "\" alt=\"" ~ album.name ~ "\"/>") }}');
			$this->assertTrue(false);
		}
		catch(Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), "Scanning error before 'album.uri, \"<img...' in eval code on line 1");
		}

	}

	public function testVoltRuntimeError()
	{
		$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler();

		try {
			$volt->compileString('{{ "hello"|unknown }}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Unknown filter "unknown" in eval code on line 1');
		}

		try {
			$volt->compileString('{{ "hello"|unknown(1, 2, 3) }}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Unknown filter "unknown" in eval code on line 1');
		}

		try {
			$volt->compileString('{{ "hello"|(a-1) }}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Unknown filter type in eval code on line 1');
		}

		try {
			$volt->compileString('{{ unknown() }}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), "Undefined function 'unknown' in eval code on line 1");
		}

		try {
			$volt->compileString('{{ dump(unknown()) }}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), "Undefined function 'unknown' in eval code on line 1");
		}
	}

	public function testVoltExtendsError()
	{

		$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler();

		try {
			$volt->parse('{{ "hello"}}{% extends "some/file.volt" %}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Extends statement must be placed at the first line in the template in eval code on line 1');
		}

		try {
			$volt->parse('<div>{% extends "some/file.volt" %}{% set a = 1 %}</div>');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Extends statement must be placed at the first line in the template in eval code on line 1');
		}

		try {
			$volt->parse('{% extends "some/file.volt" %}{{ "hello"}}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Child templates only may contain blocks in eval code on line 1');
		}

		try {
			$volt->parse('{% extends "some/file.volt" %}{{% if true %}} {%endif%}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Child templates only may contain blocks in eval code on line 1');
		}

		try {
			$volt->parse('{% extends "some/file.volt" %}{{% set a = 1 %}');
			$this->assertTrue(false);
		}
		catch(Phalcon\Mvc\View\Exception $e){
			$this->assertEquals($e->getMessage(), 'Child templates only may contain blocks in eval code on line 1');
		}

		try {
			$volt->parse('{% extends "some/file.volt" %}{{% set a = 1 %}');
			$this->assertTrue(false);
		}
		catch (Phalcon\Mvc\View\Exception $e) {
			$this->assertEquals($e->getMessage(), 'Child templates only may contain blocks in eval code on line 1');
		}

	}

	public function testVoltCompiler()
	{

		$volt = new Compiler();

		$compilation = $volt->compileString('');
		$this->assertEquals($compilation, '');

		//Comments
		$compilation = $volt->compileString('{# hello #}');
		$this->assertEquals($compilation, '');

		$compilation = $volt->compileString('{# hello #}{# other comment #}');
		$this->assertEquals($compilation, '');

		//Common Expressions
		$compilation = $volt->compileString('hello');
		$this->assertEquals($compilation, 'hello');

		$compilation = $volt->compileString('{{ "hello" }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?>");

		$compilation = $volt->compileString('{{ "hello" }}{{ "hello" }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?><?php echo 'hello'; ?>");

		$compilation = $volt->compileString('{{ "hello" }}-{{ "hello" }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?>-<?php echo 'hello'; ?>");

		$compilation = $volt->compileString('-{{ "hello" }}{{ "hello" }}-');
		$this->assertEquals($compilation, "-<?php echo 'hello'; ?><?php echo 'hello'; ?>-");

		$compilation = $volt->compileString('-{{ "hello" }}-{{ "hello" }}-');
		$this->assertEquals($compilation, "-<?php echo 'hello'; ?>-<?php echo 'hello'; ?>-");

		$compilation = $volt->compileString('Some = {{ 100+50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 + 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100-50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 - 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100*50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 * 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100/50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 / 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100%50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 % 50; ?>");

		$compilation = $volt->compileString('Some = {{ 100~50 }}');
		$this->assertEquals($compilation, "Some = <?php echo 100 . 50; ?>");

		//Unary operators
		$compilation = $volt->compileString('{{ -10 }}');
		$this->assertEquals($compilation, "<?php echo -10; ?>");

		$compilation = $volt->compileString('{{ !10 }}');
		$this->assertEquals($compilation, "<?php echo !10; ?>");

		$compilation = $volt->compileString('{{ !a }}');
		$this->assertEquals($compilation, '<?php echo !$a; ?>');

		$compilation = $volt->compileString('{{ not a }}');
		$this->assertEquals($compilation, '<?php echo !$a; ?>');

		//Arrays
		$compilation = $volt->compileString("{% set a = [1, 2, 3, 4] %}");
		$this->assertEquals($compilation, '<?php $a = array(1, 2, 3, 4); ?>');

		$compilation = $volt->compileString('{% set a = ["hello", 2, 1.3, false, true, null] %}');
		$this->assertEquals($compilation, '<?php $a = array(\'hello\', 2, 1.3, false, true, null); ?>');

		$compilation = $volt->compileString('{% set a = ["hello", 2, 3, false, true, null, [1, 2, "hola"]] %}');
		$this->assertEquals($compilation, '<?php $a = array(\'hello\', 2, 3, false, true, null, array(1, 2, \'hola\')); ?>');

		$compilation = $volt->compileString("{% set a = ['first': 1, 'second': 2, 'third': 3] %}");
		$this->assertEquals($compilation, '<?php $a = array(\'first\' => 1, \'second\' => 2, \'third\' => 3); ?>');

		//Array acccess
		$compilation = $volt->compileString('{{ a[0 ]}}');
		$this->assertEquals($compilation, '<?php echo $a[0]; ?>');

		$compilation = $volt->compileString('{{ a[0 ] [ 1]}}');
		$this->assertEquals($compilation, '<?php echo $a[0][1]; ?>');

		$compilation = $volt->compileString('{{ a[0]  [ "hello"] }}');
		$this->assertEquals($compilation, '<?php echo $a[0][\'hello\']; ?>');

		$compilation = $volt->compileString('{{ a[0] [1.2] [false] [true] }}');
		$this->assertEquals($compilation, '<?php echo $a[0][1.2][false][true]; ?>');

		//Attribute access
		$compilation = $volt->compileString('{{ a.b }}');
		$this->assertEquals($compilation, '<?php echo $a->b; ?>');

		$compilation = $volt->compileString('{{ a.b.c }}');
		$this->assertEquals($compilation, '<?php echo $a->b->c; ?>');

		//Ranges
		$compilation = $volt->compileString('{{ 1..100 }}');
		$this->assertEquals($compilation, '<?php echo range(1, 100); ?>');

		$compilation = $volt->compileString('{{ "Z".."A" }}');
		$this->assertEquals($compilation, '<?php echo range(\'Z\', \'A\'); ?>');

		$compilation = $volt->compileString("{{ 'a'..'z' }}");
		$this->assertEquals($compilation, '<?php echo range(\'a\', \'z\'); ?>');

		$compilation = $volt->compileString("{{ 'a' .. 'z' }}");
		$this->assertEquals($compilation, '<?php echo range(\'a\', \'z\'); ?>');

		//Calling functions
		$compilation = $volt->compileString("{{ content() }}");
		$this->assertEquals($compilation, '<?php echo $this->getContent(); ?>');

		$compilation = $volt->compileString("{{ get_content() }}");
		$this->assertEquals($compilation, '<?php echo $this->getContent(); ?>');

		$compilation = $volt->compileString("{{ partial('hello/x') }}");
		$this->assertEquals($compilation, '<?php echo $this->partial(\'hello/x\'); ?>');

		$compilation = $volt->compileString("{{ dump(a) }}");
		$this->assertEquals($compilation, '<?php echo var_dump($a); ?>');

		$compilation = $volt->compileString("{{ date('Y-m-d', time()) }}");
		$this->assertEquals($compilation, '<?php echo date(\'Y-m-d\', time()); ?>');

		$compilation = $volt->compileString("{{ robots.getPart(a) }}");
		$this->assertEquals($compilation, '<?php echo $robots->getPart($a); ?>');

		//Phalcon\Tag helpers
		$compilation = $volt->compileString("{{ link_to('hello', 'some-link') }}");
		$this->assertEquals($compilation, '<?php echo $this->tag->linkTo(array(\'hello\', \'some-link\')); ?>');

		$compilation = $volt->compileString("{{ form('action': 'save/products', 'method': 'post') }}");
		$this->assertEquals($compilation, '<?php echo $this->tag->form(array(\'action\' => \'save/products\', \'method\' => \'post\')); ?>');

		$compilation = $volt->compileString("{{ stylesheet_link(config.cdn.css.bootstrap, config.cdn.local) }}");
		$this->assertEquals($compilation, '<?php echo $this->tag->stylesheetLink($config->cdn->css->bootstrap, $config->cdn->local); ?>');

		$compilation = $volt->compileString("{{ javascript_include('js/some.js') }}");
		$this->assertEquals($compilation, '<?php echo $this->tag->javascriptInclude(\'js/some.js\'); ?>');

		$compilation = $volt->compileString("{{ image('img/logo.png', 'width': 80) }}");
		$this->assertEquals($compilation, "<?php echo \$this->tag->image(array('img/logo.png', 'width' => 80)); ?>");

		$compilation = $volt->compileString("{{ email_field('email', 'class': 'form-control', 'placeholder': 'Email Address') }}");
		$this->assertEquals($compilation, "<?php echo \$this->tag->emailField(array('email', 'class' => 'form-control', 'placeholder' => 'Email Address')); ?>");

		//Filters
		$compilation = $volt->compileString('{{ "hello"|e }}');
		$this->assertEquals($compilation, '<?php echo $this->escaper->escapeHtml(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "hello"|escape }}');
		$this->assertEquals($compilation, '<?php echo $this->escaper->escapeHtml(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "hello"|trim }}');
		$this->assertEquals($compilation, '<?php echo trim(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "hello"|striptags }}');
		$this->assertEquals($compilation, '<?php echo strip_tags(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "hello"|json_encode }}');
		$this->assertEquals($compilation, '<?php echo json_encode(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "hello"|url_encode }}');
		$this->assertEquals($compilation, '<?php echo urlencode(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "hello"|uppercase }}');
		$this->assertEquals($compilation, '<?php echo Phalcon\Text::upper(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "hello"|lowercase }}');
		$this->assertEquals($compilation, '<?php echo Phalcon\Text::lower(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ ("hello" ~ "lol")|e|length }}');
		$this->assertEquals($compilation, '<?php echo $this->length($this->escaper->escapeHtml((\'hello\' . \'lol\'))); ?>');

		//Filters with parameters
		$compilation = $volt->compileString('{{ "My name is %s, %s"|format(name, "thanks") }}');
		$this->assertEquals($compilation, "<?php echo sprintf('My name is %s, %s', \$name, 'thanks'); ?>");

		$compilation = $volt->compileString('{{ "some name"|convert_encoding("utf-8", "latin1") }}');
		$this->assertEquals($compilation, "<?php echo \$this->convertEncoding('some name', 'utf-8', 'latin1'); ?>");

		//if statement
		$compilation = $volt->compileString('{% if a==b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a == $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a!=b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a != $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is not b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a != $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a<b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a < $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a>b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a > $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a>=b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a >= $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a<=b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a <= $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a===b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a === $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a!==b %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a !== $b) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a==b and c==d %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a == $b && $c == $d) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a==b or c==d %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a == $b || $c == $d) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is odd %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (((($a) % 2) != 0)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is even %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (((($a) % 2) == 0)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is empty %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (empty($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is not empty %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (!empty($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is numeric %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (is_numeric($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is not numeric %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (!is_numeric($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is scalar %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (is_scalar($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is not scalar %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (!is_scalar($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is iterable %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ((is_array($a) || ($a) instanceof Traversable)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is not iterable %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (!(is_array($a) || ($a) instanceof Traversable)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is sameas(false) %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (($a) === (false)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is sameas(b) %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (($a) === ($b)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is divisibleby(3) %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (((($a) % (3)) == 0)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is divisibleby(b) %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (((($a) % ($b)) == 0)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is defined %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (isset($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is not defined %} hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (!isset($a)) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% if a==b %} hello {% else %} not hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a == $b) { ?> hello <?php } else { ?> not hello <?php } ?>');

		$compilation = $volt->compileString('{% if a==b %} {% if c==d %} hello {% endif %} {% else %} not hello {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a == $b) { ?> <?php if ($c == $d) { ?> hello <?php } ?> <?php } else { ?> not hello <?php } ?>');

		$compilation = $volt->compileString('{% if a==b %} {% if c==d %} hello {% else %} not hello {% endif %}{% endif %}');
		$this->assertEquals($compilation, '<?php if ($a == $b) { ?> <?php if ($c == $d) { ?> hello <?php } else { ?> not hello <?php } ?><?php } ?>');

		$compilation = $volt->compileString('{% if a==b %} hello {% else %} {% if c==d %} not hello {% endif %} {% endif %}');
		$this->assertEquals($compilation, '<?php if ($a == $b) { ?> hello <?php } else { ?> <?php if ($c == $d) { ?> not hello <?php } ?> <?php } ?>');

		$compilation = $volt->compileString('{% if a is empty or a is defined %} hello {% else %} not hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (empty($a) || isset($a)) { ?> hello <?php } else { ?> not hello <?php } ?>');

		$compilation = $volt->compileString('{% if a is even or b is odd %} hello {% else %} not hello {% endif %}');
		$this->assertEquals($compilation, '<?php if (((($a) % 2) == 0) || ((($b) % 2) != 0)) { ?> hello <?php } else { ?> not hello <?php } ?>');

		//for statement
		$compilation = $volt->compileString('{% for a in b %} hello {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach ($b as $a) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% for a in b[0] %} hello {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach ($b[0] as $a) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% for a in b.c %} hello {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach ($b->c as $a) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% for key, value in [0, 1, 3, 5, 4] %} hello {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach (array(0, 1, 3, 5, 4) as $key => $value) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% for key, value in [0, 1, 3, 5, 4] if key!=3 %} hello {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach (array(0, 1, 3, 5, 4) as $key => $value) { if ($key != 3) { ?> hello <?php } ?><?php } ?>');

		$compilation = $volt->compileString('{% for a in 1..10 %} hello {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach (range(1, 10) as $a) { ?> hello <?php } ?>');

		$compilation = $volt->compileString('{% for a in 1..10 if a is even %} hello {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach (range(1, 10) as $a) { if (((($a) % 2) == 0)) { ?> hello <?php } ?><?php } ?>');

		$compilation = $volt->compileString('{% for a in 1..10 %} {% for b in 1..10 %} hello {% endfor %} {% endfor %}');
		$this->assertEquals($compilation, '<?php foreach (range(1, 10) as $a) { ?> <?php foreach (range(1, 10) as $b) { ?> hello <?php } ?> <?php } ?>');

		$compilation = $volt->compileString('{% for a in 1..10 %}{% break %}{% endfor %}');
		$this->assertEquals($compilation, '<?php foreach (range(1, 10) as $a) { ?><?php break; ?><?php } ?>');

		$compilation = $volt->compileString('{% for a in 1..10 %}{% continue %}{% endfor %}');
		$this->assertEquals($compilation, '<?php foreach (range(1, 10) as $a) { ?><?php continue; ?><?php } ?>');

		//set statement
		$compilation = $volt->compileString('{% set a = 1 %}');
		$this->assertEquals($compilation, '<?php $a = 1; ?>');

		$compilation = $volt->compileString('{% set a = a-1 %}');
		$this->assertEquals($compilation, '<?php $a = $a - 1; ?>');

		$compilation = $volt->compileString('{% set a = 1.2 %}');
		$this->assertEquals($compilation, '<?php $a = 1.2; ?>');

		$compilation = $volt->compileString('{% set a = 1.2+1*(20/b) and c %}');
		$this->assertEquals($compilation, '<?php $a = 1.2 + 1 * (20 / $b) && $c; ?>');

		// Cache statement
		$compilation = $volt->compileString('{% cache somekey %} hello {% endcache %}');
		$this->assertEquals($compilation, '<?php $_cache[$somekey] = $this->di->get(\'viewCache\'); $_cacheKey[$somekey] = $_cache[$somekey]->start($somekey); if ($_cacheKey[$somekey] === null) { ?> hello <?php $_cache[$somekey]->save($somekey); } else { echo $_cacheKey[$somekey]; } ?>');

		$compilation = $volt->compileString('{% set lifetime = 500 %}{% cache somekey lifetime %} hello {% endcache %}');
		$this->assertEquals($compilation, '<?php $lifetime = 500; ?><?php $_cache[$somekey] = $this->di->get(\'viewCache\'); $_cacheKey[$somekey] = $_cache[$somekey]->start($somekey, $lifetime); if ($_cacheKey[$somekey] === null) { ?> hello <?php $_cache[$somekey]->save($somekey, null, $lifetime); } else { echo $_cacheKey[$somekey]; } ?>');

		$compilation = $volt->compileString('{% cache somekey 500 %} hello {% endcache %}');
		$this->assertEquals($compilation, '<?php $_cache[$somekey] = $this->di->get(\'viewCache\'); $_cacheKey[$somekey] = $_cache[$somekey]->start($somekey, 500); if ($_cacheKey[$somekey] === null) { ?> hello <?php $_cache[$somekey]->save($somekey, null, 500); } else { echo $_cacheKey[$somekey]; } ?>');

		//Autoescape mode
		$compilation = $volt->compileString('{{ "hello" }}{% autoescape true %}{{ "hello" }}{% autoescape false %}{{ "hello" }}{% endautoescape %}{{ "hello" }}{% endautoescape %}{{ "hello" }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?><?php echo \$this->escaper->escapeHtml('hello'); ?><?php echo 'hello'; ?><?php echo \$this->escaper->escapeHtml('hello'); ?><?php echo 'hello'; ?>");

		//Mixed
		$compilation = $volt->compileString('{# some comment #}{{ "hello" }}{# other comment }}');
		$this->assertEquals($compilation, "<?php echo 'hello'; ?>");

		//

	}

	public function testVoltUsersFunctions()
	{

		$volt = new Compiler();

		//Single string function
		$volt->addFunction('random', 'mt_rand');

		//Function with closure
		$volt->addFunction('shuffle', function($arguments, $exprArguments){
			return 'str_shuffle(' . $arguments . ')';
		});

		$compilation = $volt->compileString('{{ random() }}');
		$this->assertEquals($compilation, '<?php echo mt_rand(); ?>');

		$compilation = $volt->compileString('{{ shuffle("hello") }}');
		$this->assertEquals($compilation, '<?php echo str_shuffle(\'hello\'); ?>');

	}

	public function testVoltUsersFilters()
	{

		$volt = new Compiler();

		//Single string filter
		$volt->addFilter('reverse', 'strrev');

		//Filter with closure
		$volt->addFilter('separate', function($arguments, $exprArguments){
			return 'explode(",", '.$arguments.')';
		});

		$compilation = $volt->compileString('{{ "hello"|reverse }}');
		$this->assertEquals($compilation, '<?php echo strrev(\'hello\'); ?>');

		$compilation = $volt->compileString('{{ "1,2,3,4"|separate }}');
		$this->assertEquals($compilation, '<?php echo explode(",", \'1,2,3,4\'); ?>');

	}

	public function testVoltCompilerFile()
	{
		@unlink('unit-tests/views/layouts/test10.volt.php');

		$volt = new Compiler();

		//Simple file
		$volt->compileFile('unit-tests/views/layouts/test10.volt', 'unit-tests/views/layouts/test10.volt.php');

		$compilation = file_get_contents('unit-tests/views/layouts/test10.volt.php');
		$this->assertEquals($compilation, '<?php if ($some_eval) { ?>
Clearly, the song is: <?php echo $this->getContent(); ?>.
<?php } ?>');
	}

	public function testVoltCompileFileExtends()
	{
		@unlink('unit-tests/views/test10/children.volt.php');
		@unlink('unit-tests/views/test10/children2.volt.php');
		@unlink('unit-tests/views/test10/parent.volt%%e%%.php');

		$volt = new Compiler();

		//With blocks and extending
		$volt->compile('unit-tests/views/test10/children.volt');

		$compilation = file_get_contents('unit-tests/views/test10/children.volt.php');
		$this->assertEquals($compilation, '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; }</style><title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome on my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>');

		//with blocks and two-way blocks
		$volt->compile('unit-tests/views/test10/children2.volt');

		$compilation = file_get_contents('unit-tests/views/test10/children2.volt.php');
		$this->assertEquals($compilation, '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; } </style> <link rel="stylesheet" href="style.css" /> <title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome to my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>');

	}

	public function testVoltCompileFileExtendsMultiple()
	{

		@unlink('unit-tests/views/templates/a.volt%%e%%.php');
		@unlink('unit-tests/views/templates/b.volt%%e%%.php');
		@unlink('unit-tests/views/templates/c.volt.php');

		$volt = new Compiler();

		//With blocks and extending
		$volt->compile('unit-tests/views/templates/c.volt');

		$compilation = trim(file_get_contents('unit-tests/views/templates/c.volt.php'));
		$this->assertEquals($compilation, "[A[###[B]###]]");

	}

	public function testVoltCompilerExtendsFile()
	{

		@unlink('unit-tests/views/layouts/test10.volt.php');
		@unlink('unit-tests/views/test10/children.extends.volt.php');

		$view = new Phalcon\Mvc\View();
		$view->setViewsDir('unit-tests/views/');

		$volt = new Compiler($view);

		//extends
		$volt->compileFile('unit-tests/views/test10/children.extends.volt', 'unit-tests/views/test10/children.extends.volt.php');

		$compilation = file_get_contents('unit-tests/views/test10/children.extends.volt.php');
		$this->assertEquals($compilation, '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; }</style><title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome on my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>');

	}

	public function testVoltCompilerImportFile()
	{

		@unlink('unit-tests/views/partials/header.volt.php');
		@unlink('unit-tests/views/partials/footer.volt.php');
		@unlink('unit-tests/views/test10/import.volt.php');

		$view = new Phalcon\Mvc\View();
		$view->setViewsDir('unit-tests/views/');

		$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler($view);

		//extends
		$volt->compileFile('unit-tests/views/test10/import.volt', 'unit-tests/views/test10/import.volt.php');

		$compilation = file_get_contents('unit-tests/views/test10/import.volt.php');
		$this->assertEquals($compilation, '<div class="header"><h1>This is the header</h1></div><div class="footer"><p>This is the footer</p></div>');

	}

	public function testVoltCompilerImportRecursiveFile()
	{

		@unlink('unit-tests/views/partials/header3.volt.php');
		@unlink('unit-tests/views/partials/header2.volt.php');
		@unlink('unit-tests/views/test10/import2.volt.php');

		$view = new Phalcon\Mvc\View();
		$view->setViewsDir('unit-tests/views/');

		$volt = new \Phalcon\Mvc\View\Engine\Volt\Compiler($view);

		//extends
		$volt->compileFile('unit-tests/views/test10/import2.volt', 'unit-tests/views/test10/import2.volt.php');

		$compilation = file_get_contents('unit-tests/views/test10/import2.volt.php');
		$this->assertEquals($compilation, '<div class="header"><h1>This is the title</h1></div>');

	}

	public function testVoltCompilerFileOptions()
	{

		$di = new Phalcon\DI();
		$view = new Phalcon\Mvc\View();

		$volt = new Phalcon\Mvc\View\Engine\Volt($view, $di);

		$volt->setOptions(array(
			"compiledPath" => "unit-tests/cache/",
			"compiledSeparator" => ".",
			"compiledExtension" => ".compiled"
		));

		@unlink('unit-tests/views/test10/index.volt.php');
		@unlink('unit-tests/cache/unit-tests.views.test10.index.volt.compiled');

		//Render simple view
		$view->start();
		$volt->render('unit-tests/views/test10/index.volt', array('song' => 'Lights'), true);
		$view->finish();

		$path = 'unit-tests/cache/' . phalcon_prepare_virtual_path(realpath("unit-tests/"), ".") . '.views.test10.index.volt.compiled';

		$this->assertTrue(file_exists($path));
		$this->assertEquals(file_get_contents($path), 'Hello <?php echo $song; ?>!');
		$this->assertEquals($view->getContent(), 'Hello Lights!');

	}

	public function testVoltEngine()
	{

		@unlink('unit-tests/views/layouts/test10.volt.php');
		@unlink('unit-tests/views/test10/index.volt.php');
		@unlink('unit-tests/views/test10/other.volt.php');

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.volt' => 'Phalcon\Mvc\View\Engine\Volt'
		));

		$view->setParamToView('song', 'Rock n roll');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_ACTION_VIEW);
		$view->render('test10', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Hello Rock n roll!');

		$view->setParamToView('some_eval', true);

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test10', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Clearly, the song is: Hello Rock n roll!.'.PHP_EOL);

		//Refreshing generated view
		file_put_contents('unit-tests/views/test10/other.volt', '{{song}} {{song}}');

		$view->setParamToView('song', 'Le Song');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_ACTION_VIEW);
		$view->render('test10', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Le Song Le Song');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test10', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Clearly, the song is: Le Song Le Song.'.PHP_EOL);

		//Change the view
		file_put_contents('unit-tests/views/test10/other.volt', 'Two songs: {{song}} {{song}}');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test10', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Clearly, the song is: Two songs: Le Song Le Song.'.PHP_EOL);

	}

	public function testVoltEngineBuiltInFunctions()
	{

		@unlink('unit-tests/views/test11/index.volt.php');

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.volt' => 'Phalcon\Mvc\View\Engine\Volt'
		));

		$view->setVar('arr', array(1, 2, 3, 4));
		$view->setVar('obj', new SomeObject(array(1, 2, 3, 4)));
		$view->setVar('str', 'hello');
		$view->setVar('no_str', 1234);

		$view->start();
		$view->render('test11', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), 'Length Array: 4Length Object: 4Length String: 5Length No String: 4Slice Array: 1,2,3,4Slice Array: 2,3Slice Array: 1,2,3Slice Object: 2,3,4Slice Object: 2,3Slice Object: 1,2Slice String: helSlice String: elSlice String: lloSlice No String: 123Slice No String: 23Slice No String: 34');
	}
}
