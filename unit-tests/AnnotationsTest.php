<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

require_once 'annotations/TestClass.php';
require_once 'annotations/TestInvalid.php';

class AnnotationsTest extends PHPUnit_Framework_TestCase
{

	public function testParser()
	{

		$reader = new Phalcon\Annotations\Reader();

		$parsing = $reader->parse('TestClass');

		$this->assertTrue(isset($parsing['class']));
		$this->assertEquals(count($parsing['class']), 9);

		//Simple
		$this->assertEquals($parsing['class'][0]['name'], 'Simple');
		$this->assertFalse(isset($parsing['class'][0]['arguments']));

		//Single Param
		$this->assertEquals($parsing['class'][1]['name'], 'SingleParam');
		$this->assertTrue(isset($parsing['class'][1]['arguments']));
		$this->assertEquals(count($parsing['class'][1]['arguments']), 1);
		$this->assertEquals($parsing['class'][1]['arguments'][0]['expr']['value'], 'Param');

		//Multiple Params
		$this->assertEquals($parsing['class'][2]['name'], 'MultipleParams');
		$this->assertTrue(isset($parsing['class'][2]['arguments']));
		$this->assertEquals(count($parsing['class'][2]['arguments']), 8);
		$this->assertEquals($parsing['class'][2]['arguments'][0]['expr']['value'], 'First');
		$this->assertEquals($parsing['class'][2]['arguments'][1]['expr']['value'], 'Second');
		$this->assertEquals($parsing['class'][2]['arguments'][2]['expr']['value'], '1');
		$this->assertEquals($parsing['class'][2]['arguments'][3]['expr']['value'], '1.1');
		$this->assertEquals($parsing['class'][2]['arguments'][4]['expr']['value'], '-10');
		$this->assertEquals($parsing['class'][2]['arguments'][5]['expr']['type'], 305);
		$this->assertEquals($parsing['class'][2]['arguments'][6]['expr']['type'], 306);
		$this->assertEquals($parsing['class'][2]['arguments'][7]['expr']['type'], 304);

		//Single Array Param
		$this->assertEquals($parsing['class'][3]['name'], 'Params');
		$this->assertTrue(isset($parsing['class'][3]['arguments']));
		$this->assertEquals(count($parsing['class'][3]['arguments']), 1);
		$this->assertEquals($parsing['class'][3]['arguments'][0]['expr']['type'], 308);
		$this->assertEquals(count($parsing['class'][3]['arguments'][0]['expr']['items']), 3);
		$this->assertEquals($parsing['class'][3]['arguments'][0]['expr']['items'][0]['expr']['value'], 'key1');
		$this->assertEquals($parsing['class'][3]['arguments'][0]['expr']['items'][1]['expr']['value'], 'key2');
		$this->assertEquals($parsing['class'][3]['arguments'][0]['expr']['items'][2]['expr']['value'], 'key3');

		//Hash Params
		$this->assertEquals($parsing['class'][4]['name'], 'HashParams');
		$this->assertTrue(isset($parsing['class'][4]['arguments']));
		$this->assertEquals(count($parsing['class'][4]['arguments']), 1);
		$this->assertEquals($parsing['class'][4]['arguments'][0]['expr']['type'], 308);
		$this->assertEquals(count($parsing['class'][4]['arguments'][0]['expr']['items']), 3);
		$this->assertEquals($parsing['class'][4]['arguments'][0]['expr']['items'][0]['name'], 'key1');
		$this->assertEquals($parsing['class'][4]['arguments'][0]['expr']['items'][0]['expr']['value'], 'value');
		$this->assertEquals($parsing['class'][4]['arguments'][0]['expr']['items'][1]['name'], 'key2');
		$this->assertEquals($parsing['class'][4]['arguments'][0]['expr']['items'][1]['expr']['value'], 'value');
		$this->assertEquals($parsing['class'][4]['arguments'][0]['expr']['items'][2]['name'], 'key3');
		$this->assertEquals($parsing['class'][4]['arguments'][0]['expr']['items'][2]['expr']['value'], 'value');

		//Named Params
		$this->assertEquals($parsing['class'][5]['name'], 'NamedParams');
		$this->assertTrue(isset($parsing['class'][5]['arguments']));
		$this->assertEquals(count($parsing['class'][5]['arguments']), 2);
		$this->assertEquals($parsing['class'][5]['arguments'][0]['name'], 'first');
		$this->assertEquals($parsing['class'][5]['arguments'][0]['expr']['value'], 'some');
		$this->assertEquals($parsing['class'][5]['arguments'][1]['name'], 'second');
		$this->assertEquals($parsing['class'][5]['arguments'][1]['expr']['value'], 'other');

		//Alternative Named Params
		$this->assertEquals($parsing['class'][6]['name'], 'AlternativeNamedParams');
		$this->assertTrue(isset($parsing['class'][6]['arguments']));
		$this->assertEquals(count($parsing['class'][6]['arguments']), 2);
		$this->assertEquals($parsing['class'][6]['arguments'][0]['name'], 'first');
		$this->assertEquals($parsing['class'][6]['arguments'][0]['expr']['value'], 'some');
		$this->assertEquals($parsing['class'][6]['arguments'][1]['name'], 'second');
		$this->assertEquals($parsing['class'][6]['arguments'][1]['expr']['value'], 'other');

		//Alternative Hash Params
		$this->assertEquals($parsing['class'][7]['name'], 'AlternativeHashParams');
		$this->assertTrue(isset($parsing['class'][7]['arguments']));
		$this->assertEquals(count($parsing['class'][7]['arguments']), 1);
		$this->assertEquals($parsing['class'][7]['arguments'][0]['expr']['type'], 308);
		$this->assertEquals(count($parsing['class'][7]['arguments'][0]['expr']['items']), 3);
		$this->assertEquals($parsing['class'][7]['arguments'][0]['expr']['items'][0]['name'], 'key1');
		$this->assertEquals($parsing['class'][7]['arguments'][0]['expr']['items'][0]['expr']['value'], 'value');
		$this->assertEquals($parsing['class'][7]['arguments'][0]['expr']['items'][1]['name'], 'key2');
		$this->assertEquals($parsing['class'][7]['arguments'][0]['expr']['items'][1]['expr']['value'], 'value');
		$this->assertEquals($parsing['class'][7]['arguments'][0]['expr']['items'][2]['name'], 'key3');
		$this->assertEquals($parsing['class'][7]['arguments'][0]['expr']['items'][2]['expr']['value'], 'value');

		//Recursive Hash
		$this->assertEquals($parsing['class'][8]['name'], 'RecursiveHash');
		$this->assertTrue(isset($parsing['class'][8]['arguments']));
		$this->assertEquals(count($parsing['class'][8]['arguments']), 1);
		$this->assertEquals($parsing['class'][8]['arguments'][0]['expr']['type'], 308);
		$this->assertEquals(count($parsing['class'][8]['arguments'][0]['expr']['items']), 3);
		$this->assertEquals($parsing['class'][8]['arguments'][0]['expr']['items'][0]['name'], 'key1');
		$this->assertEquals($parsing['class'][8]['arguments'][0]['expr']['items'][0]['expr']['value'], 'value');
		$this->assertEquals($parsing['class'][8]['arguments'][0]['expr']['items'][1]['name'], 'key2');
		$this->assertEquals($parsing['class'][8]['arguments'][0]['expr']['items'][1]['expr']['value'], 'value');
		$this->assertEquals($parsing['class'][8]['arguments'][0]['expr']['items'][2]['name'], 'key3');
		$this->assertEquals($parsing['class'][8]['arguments'][0]['expr']['items'][2]['expr']['type'], 308);

		//Properties
		$this->assertTrue(isset($parsing['properties']));
		$this->assertEquals(count($parsing['properties']), 3);

		//Multiple well ordered annotations
		$this->assertTrue(isset($parsing['properties']['testProp1']));
		$this->assertEquals(count($parsing['properties']['testProp1']), 4);
		$this->assertEquals($parsing['properties']['testProp1'][0]['name'], 'var');
		$this->assertEquals($parsing['properties']['testProp1'][1]['name'], 'Simple');
		$this->assertEquals($parsing['properties']['testProp1'][2]['name'], 'SingleParam');
		$this->assertEquals($parsing['properties']['testProp1'][3]['name'], 'MultipleParams');

		//Comment without content
		$this->assertFalse(isset($parsing['properties']['testProp2']));

		//Same line annotations
		$this->assertEquals(count($parsing['properties']['testProp3']), 3);
		$this->assertEquals($parsing['properties']['testProp3'][0]['name'], 'Simple');
		$this->assertEquals($parsing['properties']['testProp3'][1]['name'], 'SingleParam');
		$this->assertEquals($parsing['properties']['testProp3'][2]['name'], 'MultipleParams');

		//Same line annotations
		$this->assertEquals(count($parsing['properties']['testProp4']), 3);
		$this->assertEquals($parsing['properties']['testProp4'][0]['name'], 'Simple');
		$this->assertEquals($parsing['properties']['testProp4'][1]['name'], 'SingleParam');
		$this->assertEquals($parsing['properties']['testProp4'][2]['name'], 'MultipleParams');

		//No docblock
		$this->assertFalse(isset($parsing['properties']['testProp5']));

		//No annotations
		$this->assertFalse(isset($parsing['properties']['testProp6']));

		//Properties
		$this->assertTrue(isset($parsing['methods']));
		$this->assertEquals(count($parsing['methods']), 4);

		//Multiple well ordered annotations
		$this->assertTrue(isset($parsing['methods']['testMethod1']));
		$this->assertEquals(count($parsing['methods']['testMethod1']), 5);
		$this->assertEquals($parsing['methods']['testMethod1'][0]['name'], 'return');
		$this->assertEquals($parsing['methods']['testMethod1'][1]['name'], 'Simple');
		$this->assertEquals($parsing['methods']['testMethod1'][2]['name'], 'SingleParam');
		$this->assertEquals($parsing['methods']['testMethod1'][3]['name'], 'MultipleParams');
		$this->assertEquals($parsing['methods']['testMethod1'][4]['name'], 'NamedMultipleParams');

		//Comment without content
		$this->assertFalse(isset($parsing['methods']['testMethod2']));

		//Same line annotations
		$this->assertEquals(count($parsing['methods']['testMethod3']), 3);
		$this->assertEquals($parsing['methods']['testMethod3'][0]['name'], 'Simple');
		$this->assertEquals($parsing['methods']['testMethod3'][1]['name'], 'SingleParam');
		$this->assertEquals($parsing['methods']['testMethod3'][2]['name'], 'MultipleParams');

		//Unordered annotations
		$this->assertEquals(count($parsing['methods']['testMethod4']), 3);
		$this->assertEquals($parsing['methods']['testMethod4'][0]['name'], 'Simple');
		$this->assertEquals($parsing['methods']['testMethod4'][1]['name'], 'SingleParam');
		$this->assertEquals($parsing['methods']['testMethod4'][2]['name'], 'MultipleParams');

		//Unordered annotations + extra content
		$this->assertEquals(count($parsing['methods']['testMethod5']), 3);
		$this->assertEquals($parsing['methods']['testMethod5'][0]['name'], 'Simple');
		$this->assertEquals($parsing['methods']['testMethod5'][1]['name'], 'SingleParam');
		$this->assertEquals($parsing['methods']['testMethod5'][2]['name'], 'MultipleParams');
	}

	public function testParserNoClass()
	{
		try {
			$reader = new Phalcon\Annotations\Reader();
			$parsing = $reader->parse('TestClass1');
			$this->assertTrue(false);
		} catch (Exception $e) {
			$this->assertEquals('Class TestClass1 does not exist', $e->getMessage());
		}
	}

	public function testReflection()
	{
		//Empty reflection
		$reflection = new Phalcon\Annotations\Reflection();

		$classAnnotations = $reflection->getClassAnnotations();
		$this->assertEquals($classAnnotations, null);

		$methodsAnnotations = $reflection->getMethodsAnnotations();
		$this->assertEquals($methodsAnnotations, null);

		$propertiesAnnotations = $reflection->getPropertiesAnnotations();
		$this->assertEquals($propertiesAnnotations, null);

		//Parsing a real class
		$reader = new Phalcon\Annotations\Reader();
		$parsing = $reader->parse('TestClass');

		$reflection = new Phalcon\Annotations\Reflection($parsing);

		//Annotations in the class' dockblock
		$classAnnotations = $reflection->getClassAnnotations();
		$this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Collection');

		$number = 0;
		foreach ($classAnnotations as $annotation) {
			$this->assertEquals(get_class($annotation), 'Phalcon\Annotations\Annotation');
			$number++;
		}
		$this->assertEquals($number, 9);

		$this->assertEquals(count($classAnnotations), 9);

		//Annotations in Methods
		$methodsAnnotations = $reflection->getMethodsAnnotations();
		$this->assertEquals(gettype($methodsAnnotations), 'array');
		$this->assertEquals(get_class($methodsAnnotations['testMethod1']), 'Phalcon\Annotations\Collection');

		$total = 0;
		foreach ($methodsAnnotations as $method => $annotations) {

			$this->assertEquals(gettype($method), 'string');

			$number = 0;
			foreach ($annotations as $annotation) {
				$this->assertEquals(get_class($annotation), 'Phalcon\Annotations\Annotation');
				$number++;
				$total++;
			}
			$this->assertTrue($number > 0);

		}
		$this->assertEquals($total, 14);

		$annotations = $methodsAnnotations['testMethod1'];
		$this->assertTrue($annotations->has('Simple'));
		$this->assertFalse($annotations->has('NoSimple'));

		$annotation = $annotations->get('Simple');
		$this->assertEquals($annotation->getName(), 'Simple');
		$this->assertEquals($annotation->numberArguments(), 0);
		$this->assertEquals($annotation->getArguments(), null);
		$this->assertFalse($annotation->hasArgument('none'));

		$annotation = $annotations->get('NamedMultipleParams');
		$this->assertEquals($annotation->getName(), 'NamedMultipleParams');
		$this->assertEquals($annotation->numberArguments(), 2);
		$this->assertEquals($annotation->getArguments(), array('first' => 'First', 'second' => 'Second'));
		$this->assertTrue($annotation->hasArgument('first'));
		$this->assertEquals($annotation->getArgument('first'), 'First');
		$this->assertFalse($annotation->hasArgument('none'));

		//Annotations in properties
		$propertiesAnnotations = $reflection->getPropertiesAnnotations();
		$this->assertEquals(gettype($propertiesAnnotations), 'array');
		$this->assertEquals(get_class($propertiesAnnotations['testProp1']), 'Phalcon\Annotations\Collection');

		$total = 0;
		foreach ($propertiesAnnotations as $property => $annotations) {

			$this->assertEquals(gettype($method), 'string');

			$number = 0;
			foreach ($annotations as $annotation) {
				$this->assertEquals(get_class($annotation), 'Phalcon\Annotations\Annotation');
				$number++;
				$total++;
			}
			$this->assertTrue($number > 0);

		}
		$this->assertEquals($total, 10);

	}

	public function testInvalidAnnotation()
	{
		$reader = new Phalcon\Annotations\Reader();

		try {
			$parsing = $reader->parse('TestInvalid');
			$this->assertFalse();
		}
		catch (\Exception $e) {
			$this->assertRegExp('/Syntax error, unexpected EOF in .*/', $e->getMessage());
		}
	}
}