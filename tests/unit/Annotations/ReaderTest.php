<?php

namespace Phalcon\Test\Unit\Annotations;

use Phalcon\Annotations\Reader;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Annotations\ReaderTest
 * Tests for \Phalcon\Annotations\Reader component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Annotations
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ReaderTest extends UnitTest
{
    /**
     * Test throws ReflectionException when non-existent got class
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-25
     */
    public function testParseWithNonExistentClass()
    {
        $this->specify(
            "Reader::parse does not throws ReflectionException when non-existent got class",
            function () {
                $reader = new Reader();
                $reader->parse('TestClass1');
            },
            ['throws' => ['ReflectionException', 'Class TestClass1 does not exist']]
        );
    }

    /**
     * Test throws Phalcon\Annotations\Exception when got class with invalid annotation
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-25
     */
    public function testParseWithInvalidAnnotation()
    {
        $this->specify(
            "Reader::parse does not throws Phalcon\\Annotations\\Exception when got class with invalid annotation",
            function () {
                require_once PATH_DATA . 'annotations/TestInvalid.php';

                $reader = new Reader();
                $reader->parse('TestInvalid');
            },
            [
                'throws' => [
                    'Phalcon\Annotations\Exception',
                    'Syntax error, unexpected EOF in ' . PATH_DATA . 'annotations/TestInvalid.php'
                ]
            ]
        );
    }

    /**
     * Tests Reader::parse
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-25
     */
    public function testReaderParse()
    {
        $this->specify(
            "Reader::parse parses the annotations incorrectly",
            function () {
                require_once PATH_DATA . 'annotations/TestClass.php';

                $reader = new Reader();
                $parsing = $reader->parse('TestClass');

                expect(isset($parsing['class']))->true();
                expect($parsing['class'])->count(9);

                // Simple
                expect($parsing['class'][0]['name'])->equals('Simple');
                expect(isset($parsing['class'][0]['arguments']))->false();

                // Single Param
                expect($parsing['class'][1]['name'])->equals('SingleParam');
                expect(isset($parsing['class'][1]['arguments']))->true();
                expect($parsing['class'][1]['arguments'])->count(1);
                expect($parsing['class'][1]['arguments'][0]['expr']['value'])->equals('Param');

                // Multiple Params
                expect($parsing['class'][2]['name'])->equals('MultipleParams');
                expect(isset($parsing['class'][2]['arguments']))->true();
                expect($parsing['class'][2]['arguments'])->count(8);
                expect($parsing['class'][2]['arguments'][0]['expr']['value'])->equals('First');
                expect($parsing['class'][2]['arguments'][1]['expr']['value'])->equals('Second');
                expect($parsing['class'][2]['arguments'][2]['expr']['value'])->equals('1');
                expect($parsing['class'][2]['arguments'][3]['expr']['value'])->equals('1.1');
                expect($parsing['class'][2]['arguments'][4]['expr']['value'])->equals('-10');
                expect($parsing['class'][2]['arguments'][5]['expr']['type'])->equals(305);
                expect($parsing['class'][2]['arguments'][6]['expr']['type'])->equals(306);
                expect($parsing['class'][2]['arguments'][7]['expr']['type'])->equals(304);

                // Single Array Param
                expect($parsing['class'][3]['name'])->equals('Params');
                expect(isset($parsing['class'][3]['arguments']))->true();
                expect($parsing['class'][3]['arguments'])->count(1);
                expect($parsing['class'][3]['arguments'][0]['expr']['type'])->equals(308);
                expect($parsing['class'][3]['arguments'][0]['expr']['items'])->count(3);
                expect($parsing['class'][3]['arguments'][0]['expr']['items'][0]['expr']['value'])->equals('key1');
                expect($parsing['class'][3]['arguments'][0]['expr']['items'][1]['expr']['value'])->equals('key2');
                expect($parsing['class'][3]['arguments'][0]['expr']['items'][2]['expr']['value'])->equals('key3');

                // Hash Params
                expect($parsing['class'][4]['name'])->equals('HashParams');
                expect(isset($parsing['class'][4]['arguments']))->true();
                expect($parsing['class'][4]['arguments'])->count(1);
                expect($parsing['class'][4]['arguments'][0]['expr']['type'])->equals(308);
                expect($parsing['class'][4]['arguments'][0]['expr']['items'])->count(3);
                expect($parsing['class'][4]['arguments'][0]['expr']['items'][0]['name'])->equals('key1');
                expect($parsing['class'][4]['arguments'][0]['expr']['items'][0]['expr']['value'])->equals('value');
                expect($parsing['class'][4]['arguments'][0]['expr']['items'][1]['name'])->equals('key2');
                expect($parsing['class'][4]['arguments'][0]['expr']['items'][1]['expr']['value'])->equals('value');
                expect($parsing['class'][4]['arguments'][0]['expr']['items'][2]['name'])->equals('key3');
                expect($parsing['class'][4]['arguments'][0]['expr']['items'][2]['expr']['value'])->equals('value');

                // Named Params
                expect($parsing['class'][5]['name'])->equals('NamedParams');
                expect(isset($parsing['class'][5]['arguments']))->true();
                expect($parsing['class'][5]['arguments'])->count(2);
                expect($parsing['class'][5]['arguments'][0]['name'])->equals('first');
                expect($parsing['class'][5]['arguments'][0]['expr']['value'])->equals('some');
                expect($parsing['class'][5]['arguments'][1]['name'])->equals('second');
                expect($parsing['class'][5]['arguments'][1]['expr']['value'])->equals('other');

                // Alternative Named Params
                expect($parsing['class'][6]['name'])->equals('AlternativeNamedParams');
                expect(isset($parsing['class'][6]['arguments']))->true();
                expect($parsing['class'][6]['arguments'])->count(2);
                expect($parsing['class'][6]['arguments'][0]['name'])->equals('first');
                expect($parsing['class'][6]['arguments'][0]['expr']['value'])->equals('some');
                expect($parsing['class'][6]['arguments'][1]['name'])->equals('second');
                expect($parsing['class'][6]['arguments'][1]['expr']['value'])->equals('other');

                // Alternative Hash Params
                expect($parsing['class'][7]['name'])->equals('AlternativeHashParams');
                expect(isset($parsing['class'][7]['arguments']))->true();
                expect($parsing['class'][7]['arguments'])->count(1);
                expect($parsing['class'][7]['arguments'][0]['expr']['type'])->equals(308);
                expect($parsing['class'][7]['arguments'][0]['expr']['items'])->count(3);
                expect($parsing['class'][7]['arguments'][0]['expr']['items'][0]['name'])->equals('key1');
                expect($parsing['class'][7]['arguments'][0]['expr']['items'][0]['expr']['value'])->equals('value');
                expect($parsing['class'][7]['arguments'][0]['expr']['items'][1]['name'])->equals('key2');
                expect($parsing['class'][7]['arguments'][0]['expr']['items'][1]['expr']['value'])->equals('value');
                expect($parsing['class'][7]['arguments'][0]['expr']['items'][2]['name'])->equals('key3');
                expect($parsing['class'][7]['arguments'][0]['expr']['items'][2]['expr']['value'])->equals('value');

                // Recursive Hash
                expect($parsing['class'][8]['name'])->equals('RecursiveHash');
                expect(isset($parsing['class'][8]['arguments']))->true();
                expect($parsing['class'][8]['arguments'])->count(1);
                expect($parsing['class'][8]['arguments'][0]['expr']['type'])->equals(308);
                expect($parsing['class'][8]['arguments'][0]['expr']['items'])->count(3);
                expect($parsing['class'][8]['arguments'][0]['expr']['items'][0]['name'])->equals('key1');
                expect($parsing['class'][8]['arguments'][0]['expr']['items'][0]['expr']['value'])->equals('value');
                expect($parsing['class'][8]['arguments'][0]['expr']['items'][1]['name'])->equals('key2');
                expect($parsing['class'][8]['arguments'][0]['expr']['items'][1]['expr']['value'])->equals('value');
                expect($parsing['class'][8]['arguments'][0]['expr']['items'][2]['name'])->equals('key3');
                expect($parsing['class'][8]['arguments'][0]['expr']['items'][2]['expr']['type'])->equals(308);

                // Properties
                expect(isset($parsing['properties']))->true();
                expect($parsing['properties'])->count(3);

                // Multiple well ordered annotations
                expect(isset($parsing['properties']['testProp1']))->true();
                expect($parsing['properties']['testProp1'])->count(4);
                expect($parsing['properties']['testProp1'][0]['name'])->equals('var');
                expect($parsing['properties']['testProp1'][1]['name'])->equals('Simple');
                expect($parsing['properties']['testProp1'][2]['name'])->equals('SingleParam');
                expect($parsing['properties']['testProp1'][3]['name'])->equals('MultipleParams');

                // Comment without content
                expect(isset($parsing['properties']['testProp2']))->false();

                // Same line annotations
                expect($parsing['properties']['testProp3'])->count(3);
                expect($parsing['properties']['testProp3'][0]['name'])->equals('Simple');
                expect($parsing['properties']['testProp3'][1]['name'])->equals('SingleParam');
                expect($parsing['properties']['testProp3'][2]['name'])->equals('MultipleParams');

                // Same line annotations
                expect($parsing['properties']['testProp4'])->count(3);
                expect($parsing['properties']['testProp4'][0]['name'])->equals('Simple');
                expect($parsing['properties']['testProp4'][1]['name'])->equals('SingleParam');
                expect($parsing['properties']['testProp4'][2]['name'])->equals('MultipleParams');

                // No docblock
                expect(isset($parsing['properties']['testProp5']))->false();

                // No annotations
                expect(isset($parsing['properties']['testProp6']))->false();

                // Properties
                expect(isset($parsing['methods']))->true();
                expect($parsing['methods'])->count(4);

                // Multiple well ordered annotations
                expect(isset($parsing['methods']['testMethod1']))->true();
                expect($parsing['methods']['testMethod1'])->count(5);
                expect($parsing['methods']['testMethod1'][0]['name'])->equals('return');

                expect($parsing['methods']['testMethod1'][1]['name'])->equals('Simple');
                expect($parsing['methods']['testMethod1'][2]['name'])->equals('SingleParam');
                expect($parsing['methods']['testMethod1'][3]['name'])->equals('MultipleParams');
                expect($parsing['methods']['testMethod1'][4]['name'])->equals('NamedMultipleParams');

                // Comment without content
                expect(isset($parsing['methods']['testMethod2']))->false();

                // Same line annotations
                expect($parsing['methods']['testMethod3'])->count(3);
                expect($parsing['methods']['testMethod3'][0]['name'])->equals('Simple');
                expect($parsing['methods']['testMethod3'][1]['name'])->equals('SingleParam');
                expect($parsing['methods']['testMethod3'][2]['name'])->equals('MultipleParams');

                // Unordered annotations
                expect($parsing['methods']['testMethod4'])->count(3);
                expect($parsing['methods']['testMethod4'][0]['name'])->equals('Simple');
                expect($parsing['methods']['testMethod4'][1]['name'])->equals('SingleParam');
                expect($parsing['methods']['testMethod4'][2]['name'])->equals('MultipleParams');

                // Unordered annotations + extra content
                expect($parsing['methods']['testMethod5'])->count(3);
                expect($parsing['methods']['testMethod5'][0]['name'])->equals('Simple');
                expect($parsing['methods']['testMethod5'][1]['name'])->equals('SingleParam');
                expect($parsing['methods']['testMethod5'][2]['name'])->equals('MultipleParams');
            }
        );
    }
}
