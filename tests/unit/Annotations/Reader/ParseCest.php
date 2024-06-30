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

namespace Phalcon\Tests\Unit\Annotations\Reader;

use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Reader;
use ReflectionException;
use UnitTester;

use function dataDir;
use function str_replace;

use const DIRECTORY_SEPARATOR;

class ParseCest
{
    /**
     * Test throws ReflectionException when non-existent got class
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-25
     */
    public function testParseWithNonExistentClass(UnitTester $I)
    {
        if (version_compare(PHP_VERSION, '8.0.0', '>=')) {
            $message = 'Class "TestClass1" does not exist';
        } else {
            $message = 'Class TestClass1 does not exist';
        }

        $I->expectThrowable(
            new ReflectionException($message, -1),
            function () {
                $reader = new Reader();

                $reader->parse('TestClass1');
            }
        );
    }

    /**
     * Test throws Phalcon\Annotations\Exception when got class with invalid
     * annotation
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-25
     */
    public function testParseWithInvalidAnnotation(UnitTester $I)
    {
        $filename    = 'fixtures' . DIRECTORY_SEPARATOR . 'Annotations'
            . DIRECTORY_SEPARATOR . 'TestInvalid.php';
        $includeFile = str_replace("/", DIRECTORY_SEPARATOR, dataDir($filename));

        $I->seeFileFound($includeFile);

        require_once $includeFile;

        $file = dataDir($filename);

        //directory based on DIRECTORY_SEPARATOR
        $file = str_replace("/", DIRECTORY_SEPARATOR, $file);

        $I->expectThrowable(
            new Exception('Syntax error, unexpected EOF in ' . $file),
            function () {
                $reader = new Reader();

                $reader->parse('TestInvalid');
            }
        );
    }


    /**
     * Tests Reader::parse
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-25
     */
    public function testReaderParse(UnitTester $I)
    {
        $includeFile = dataDir('fixtures/Annotations/TestClass.php');

        $I->seeFileFound($includeFile);

        require_once $includeFile;

        $reader  = new Reader();
        $parsing = $reader->parse('TestClass');

        $actual = isset($parsing['class']);
        $I->assertTrue($actual);

        $expected = 9;
        $actual   = $parsing['class'];
        $I->assertCount($expected, $actual);

        // Simple
        $expected = 'Simple';
        $actual   = $parsing['class'][0]['name'];
        $I->assertSame($expected, $actual);

        $actual = isset($parsing['class'][0]['arguments']);
        $I->assertFalse($actual);

        // Single Param
        $expected = 'SingleParam';
        $actual   = $parsing['class'][1]['name'];
        $I->assertSame($expected, $actual);

        $actual = isset($parsing['class'][1]['arguments']);
        $I->assertTrue($actual);

        $expected = 1;
        $actual   = $parsing['class'][1]['arguments'];
        $I->assertCount($expected, $actual);

        $expected = 'Param';
        $actual   = $parsing['class'][1]['arguments'][0]['expr']['value'];
        $I->assertSame($expected, $actual);

        // Multiple Params
        $expected = 8;
        $actual   = $parsing['class'][2]['arguments'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['class'][2]['arguments']);
        $I->assertTrue($actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['class'][2]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'First';
        $actual   = $parsing['class'][2]['arguments'][0]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'Second';
        $actual   = $parsing['class'][2]['arguments'][1]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = '1';
        $actual   = $parsing['class'][2]['arguments'][2]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = '1.1';
        $actual   = $parsing['class'][2]['arguments'][3]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = '-10';
        $actual   = $parsing['class'][2]['arguments'][4]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 305;
        $actual   = $parsing['class'][2]['arguments'][5]['expr']['type'];
        $I->assertSame($expected, $actual);

        $expected = 306;
        $actual   = $parsing['class'][2]['arguments'][6]['expr']['type'];
        $I->assertSame($expected, $actual);

        $expected = 304;
        $actual   = $parsing['class'][2]['arguments'][7]['expr']['type'];
        $I->assertSame($expected, $actual);


        // Single Array Param
        $expected = 1;
        $actual   = $parsing['class'][3]['arguments'];
        $I->assertCount($expected, $actual);

        $expected = 3;
        $actual   = $parsing['class'][3]['arguments'][0]['expr']['items'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['class'][3]['arguments']);
        $I->assertTrue($actual);

        $expected = 'Params';
        $actual   = $parsing['class'][3]['name'];
        $I->assertSame($expected, $actual);

        $expected = 308;
        $actual   = $parsing['class'][3]['arguments'][0]['expr']['type'];
        $I->assertSame($expected, $actual);

        $expected = 'key1';
        $actual   = $parsing['class'][3]['arguments'][0]['expr']['items'][0]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key2';
        $actual   = $parsing['class'][3]['arguments'][0]['expr']['items'][1]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key3';
        $actual   = $parsing['class'][3]['arguments'][0]['expr']['items'][2]['expr']['value'];
        $I->assertSame($expected, $actual);


        // Hash Params
        $expected = 1;
        $actual   = $parsing['class'][8]['arguments'];
        $I->assertCount($expected, $actual);

        $expected = 3;
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['items'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['class'][4]['arguments']);
        $I->assertTrue($actual);

        $expected = 'HashParams';
        $actual   = $parsing['class'][4]['name'];
        $I->assertSame($expected, $actual);

        $expected = 308;
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['type'];
        $I->assertSame($expected, $actual);

        $expected = 'key1';
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['items'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['items'][0]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key2';
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['items'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['items'][1]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key3';
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['items'][2]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][4]['arguments'][0]['expr']['items'][2]['expr']['value'];
        $I->assertSame($expected, $actual);


        // Named Params
        $expected = 2;
        $actual   = $parsing['class'][5]['arguments'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['class'][5]['arguments']);
        $I->assertTrue($actual);

        $expected = 'NamedParams';
        $actual   = $parsing['class'][5]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'second';
        $actual   = $parsing['class'][5]['arguments'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'other';
        $actual   = $parsing['class'][5]['arguments'][1]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'second';
        $actual   = $parsing['class'][5]['arguments'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'other';
        $actual   = $parsing['class'][5]['arguments'][1]['expr']['value'];
        $I->assertSame($expected, $actual);


        // Alternative Named Params
        $expected = 2;
        $actual   = $parsing['class'][6]['arguments'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['class'][6]['arguments']);
        $I->assertTrue($actual);

        $expected = 'AlternativeNamedParams';
        $actual   = $parsing['class'][6]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'second';
        $actual   = $parsing['class'][6]['arguments'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'other';
        $actual   = $parsing['class'][6]['arguments'][1]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'second';
        $actual   = $parsing['class'][6]['arguments'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'other';
        $actual   = $parsing['class'][6]['arguments'][1]['expr']['value'];
        $I->assertSame($expected, $actual);


        // Alternative Hash Params
        $expected = 1;
        $actual   = $parsing['class'][7]['arguments'];
        $I->assertCount($expected, $actual);

        $expected = 3;
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['items'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['class'][7]['arguments']);
        $I->assertTrue($actual);

        $expected = 'AlternativeHashParams';
        $actual   = $parsing['class'][7]['name'];
        $I->assertSame($expected, $actual);

        $expected = 308;
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['type'];
        $I->assertSame($expected, $actual);

        $expected = 'key1';
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['items'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['items'][0]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key2';
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['items'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['items'][1]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key3';
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['items'][2]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][7]['arguments'][0]['expr']['items'][2]['expr']['value'];
        $I->assertSame($expected, $actual);

        // Recursive Hash
        $expected = 1;
        $actual   = $parsing['class'][8]['arguments'];
        $I->assertCount($expected, $actual);

        $expected = 3;
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['items'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['class'][8]['arguments']);
        $I->assertTrue($actual);

        $expected = 'RecursiveHash';
        $actual   = $parsing['class'][8]['name'];
        $I->assertSame($expected, $actual);

        $expected = 308;
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['type'];
        $I->assertSame($expected, $actual);

        $expected = 'key1';
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['items'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['items'][0]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key2';
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['items'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'value';
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['items'][1]['expr']['value'];
        $I->assertSame($expected, $actual);

        $expected = 'key3';
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['items'][2]['name'];
        $I->assertSame($expected, $actual);

        $expected = 308;
        $actual   = $parsing['class'][8]['arguments'][0]['expr']['items'][2]['expr']['type'];
        $I->assertSame($expected, $actual);


        // Constants
        $expected = 1;
        $actual   = $parsing['constants'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['constants']);
        $I->assertTrue($actual);

        $actual = isset($parsing['constants']['TEST_CONST2']);
        $I->assertFalse($actual);

        $expected = 'Simple';
        $actual   = $parsing['constants']['TEST_CONST1'][0]['name'];
        $I->assertSame($expected, $actual);

        // Properties
        $expected = 3;
        $actual   = $parsing['properties'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['properties']);
        $I->assertTrue($actual);

        // Multiple well-ordered annotations
        $expected = 4;
        $actual   = $parsing['properties']['testProp1'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['properties']['testProp1']);
        $I->assertTrue($actual);

        $expected = 'var';
        $actual   = $parsing['properties']['testProp1'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'Simple';
        $actual   = $parsing['properties']['testProp1'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'SingleParam';
        $actual   = $parsing['properties']['testProp1'][2]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['properties']['testProp1'][3]['name'];
        $I->assertSame($expected, $actual);

        // Comment without content
        $actual = isset($parsing['properties']['testProp2']);
        $I->assertFalse($actual);

        // Same line annotations
        $expected = 3;
        $actual   = $parsing['properties']['testProp3'];
        $I->assertCount($expected, $actual);

        $expected = 'Simple';
        $actual   = $parsing['properties']['testProp3'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'SingleParam';
        $actual   = $parsing['properties']['testProp3'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['properties']['testProp3'][2]['name'];
        $I->assertSame($expected, $actual);

        // Same line annotations
        $expected = 3;
        $actual   = $parsing['properties']['testProp4'];
        $I->assertCount($expected, $actual);

        $expected = 'Simple';
        $actual   = $parsing['properties']['testProp4'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'SingleParam';
        $actual   = $parsing['properties']['testProp4'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['properties']['testProp4'][2]['name'];
        $I->assertSame($expected, $actual);


        // No docblock
        $actual = isset($parsing['properties']['testMethod5']);
        $I->assertFalse($actual);

        // No annotations
        $actual = isset($parsing['properties']['testMethod6']);
        $I->assertFalse($actual);

        // Properties
        $expected = 4;
        $actual   = $parsing['methods'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['methods']);
        $I->assertTrue($actual);

        // Multiple well-ordered annotations
        $expected = 5;
        $actual   = $parsing['methods']['testMethod1'];
        $I->assertCount($expected, $actual);

        $actual = isset($parsing['methods']['testMethod1']);
        $I->assertTrue($actual);

        $expected = 'return';
        $actual   = $parsing['methods']['testMethod1'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'Simple';
        $actual   = $parsing['methods']['testMethod1'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'SingleParam';
        $actual   = $parsing['methods']['testMethod1'][2]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['methods']['testMethod1'][3]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'NamedMultipleParams';
        $actual   = $parsing['methods']['testMethod1'][4]['name'];
        $I->assertSame($expected, $actual);

        // Comment without content
        $actual = isset($parsing['methods']['testMethod2']);
        $I->assertFalse($actual);

        // Same line annotations
        $expected = 3;
        $actual   = $parsing['methods']['testMethod3'];
        $I->assertCount($expected, $actual);

        $expected = 'Simple';
        $actual   = $parsing['methods']['testMethod3'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'SingleParam';
        $actual   = $parsing['methods']['testMethod3'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['methods']['testMethod3'][2]['name'];
        $I->assertSame($expected, $actual);

        // Unordered annotations
        $expected = 3;
        $actual   = $parsing['methods']['testMethod4'];
        $I->assertCount($expected, $actual);

        $expected = 'Simple';
        $actual   = $parsing['methods']['testMethod4'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'SingleParam';
        $actual   = $parsing['methods']['testMethod4'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['methods']['testMethod4'][2]['name'];
        $I->assertSame($expected, $actual);


        // Unordered annotations + extra content
        $expected = 3;
        $actual   = $parsing['methods']['testMethod5'];
        $I->assertCount($expected, $actual);

        $expected = 'Simple';
        $actual   = $parsing['methods']['testMethod5'][0]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'SingleParam';
        $actual   = $parsing['methods']['testMethod5'][1]['name'];
        $I->assertSame($expected, $actual);

        $expected = 'MultipleParams';
        $actual   = $parsing['methods']['testMethod5'][2]['name'];
        $I->assertSame($expected, $actual);
    }
}
