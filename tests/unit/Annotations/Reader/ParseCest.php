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

namespace Phalcon\Test\Unit\Annotations\Reader;

use Phalcon\Annotations\Exception;
use Phalcon\Annotations\Reader;
use ReflectionException;
use UnitTester;

use function dataDir;

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
        $I->expectThrowable(
            new ReflectionException('Class TestClass1 does not exist', -1),
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
        $filename = 'fixtures' . DIRECTORY_SEPARATOR . 'Annotations' . DIRECTORY_SEPARATOR . 'TestInvalid.php';
        $includeFile = dataDir($filename);

        $I->seeFileFound($includeFile);

        require_once $includeFile;

        $file = dataDir($filename);

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

        $I->assertTrue(
            isset($parsing['class'])
        );

        $I->assertCount(9, $parsing['class']);

        // Simple
        $I->assertEquals('Simple', $parsing['class'][0]['name']);
        $I->assertFalse(isset($parsing['class'][0]['arguments']));

        // Single Param
        $I->assertEquals('SingleParam', $parsing['class'][1]['name']);
        $I->assertTrue(isset($parsing['class'][1]['arguments']));
        $I->assertCount(1, $parsing['class'][1]['arguments']);
        $I->assertEquals('Param', $parsing['class'][1]['arguments'][0]['expr']['value']);

        // Multiple Params
        $I->assertEquals('MultipleParams', $parsing['class'][2]['name']);
        $I->assertTrue(isset($parsing['class'][2]['arguments']));
        $I->assertCount(8, $parsing['class'][2]['arguments']);
        $I->assertEquals('First', $parsing['class'][2]['arguments'][0]['expr']['value']);
        $I->assertEquals('Second', $parsing['class'][2]['arguments'][1]['expr']['value']);
        $I->assertEquals('1', $parsing['class'][2]['arguments'][2]['expr']['value']);
        $I->assertEquals('1.1', $parsing['class'][2]['arguments'][3]['expr']['value']);
        $I->assertEquals('-10', $parsing['class'][2]['arguments'][4]['expr']['value']);
        $I->assertEquals(305, $parsing['class'][2]['arguments'][5]['expr']['type']);
        $I->assertEquals(306, $parsing['class'][2]['arguments'][6]['expr']['type']);
        $I->assertEquals(304, $parsing['class'][2]['arguments'][7]['expr']['type']);

        // Single Array Param
        $I->assertEquals('Params', $parsing['class'][3]['name']);
        $I->assertTrue(isset($parsing['class'][3]['arguments']));
        $I->assertCount(1, $parsing['class'][3]['arguments']);
        $I->assertEquals(308, $parsing['class'][3]['arguments'][0]['expr']['type']);
        $I->assertCount(3, $parsing['class'][3]['arguments'][0]['expr']['items']);
        $I->assertEquals('key1', $parsing['class'][3]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $I->assertEquals('key2', $parsing['class'][3]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $I->assertEquals('key3', $parsing['class'][3]['arguments'][0]['expr']['items'][2]['expr']['value']);

        // Hash Params
        $I->assertEquals('HashParams', $parsing['class'][4]['name']);
        $I->assertTrue(isset($parsing['class'][4]['arguments']));
        $I->assertCount(1, $parsing['class'][8]['arguments']);
        $I->assertEquals(308, $parsing['class'][4]['arguments'][0]['expr']['type']);
        $I->assertCount(3, $parsing['class'][4]['arguments'][0]['expr']['items']);
        $I->assertEquals('key1', $parsing['class'][4]['arguments'][0]['expr']['items'][0]['name']);
        $I->assertEquals('value', $parsing['class'][4]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $I->assertEquals('key2', $parsing['class'][4]['arguments'][0]['expr']['items'][1]['name']);
        $I->assertEquals('value', $parsing['class'][4]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $I->assertEquals('key3', $parsing['class'][4]['arguments'][0]['expr']['items'][2]['name']);
        $I->assertEquals('value', $parsing['class'][4]['arguments'][0]['expr']['items'][2]['expr']['value']);

        // Named Params
        $I->assertEquals('NamedParams', $parsing['class'][5]['name']);
        $I->assertTrue(isset($parsing['class'][5]['arguments']));
        $I->assertCount(2, $parsing['class'][5]['arguments']);
        $I->assertEquals('second', $parsing['class'][5]['arguments'][1]['name']);
        $I->assertEquals('other', $parsing['class'][5]['arguments'][1]['expr']['value']);
        $I->assertEquals('second', $parsing['class'][5]['arguments'][1]['name']);
        $I->assertEquals('other', $parsing['class'][5]['arguments'][1]['expr']['value']);

        // Alternative Named Params
        $I->assertEquals('AlternativeNamedParams', $parsing['class'][6]['name']);
        $I->assertTrue(isset($parsing['class'][6]['arguments']));
        $I->assertCount(2, $parsing['class'][6]['arguments']);
        $I->assertEquals('second', $parsing['class'][6]['arguments'][1]['name']);
        $I->assertEquals('other', $parsing['class'][6]['arguments'][1]['expr']['value']);
        $I->assertEquals('second', $parsing['class'][6]['arguments'][1]['name']);
        $I->assertEquals('other', $parsing['class'][6]['arguments'][1]['expr']['value']);

        // Alternative Hash Params
        $I->assertEquals('AlternativeHashParams', $parsing['class'][7]['name']);
        $I->assertTrue(isset($parsing['class'][7]['arguments']));
        $I->assertCount(1, $parsing['class'][7]['arguments']);
        $I->assertEquals(308, $parsing['class'][7]['arguments'][0]['expr']['type']);
        $I->assertCount(3, $parsing['class'][7]['arguments'][0]['expr']['items']);
        $I->assertEquals('key1', $parsing['class'][7]['arguments'][0]['expr']['items'][0]['name']);
        $I->assertEquals('value', $parsing['class'][7]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $I->assertEquals('key2', $parsing['class'][7]['arguments'][0]['expr']['items'][1]['name']);
        $I->assertEquals('value', $parsing['class'][7]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $I->assertEquals('key3', $parsing['class'][7]['arguments'][0]['expr']['items'][2]['name']);
        $I->assertEquals('value', $parsing['class'][7]['arguments'][0]['expr']['items'][2]['expr']['value']);

        // Recursive Hash
        $I->assertEquals('RecursiveHash', $parsing['class'][8]['name']);
        $I->assertTrue(isset($parsing['class'][8]['arguments']));
        $I->assertCount(1, $parsing['class'][8]['arguments']);
        $I->assertEquals(308, $parsing['class'][8]['arguments'][0]['expr']['type']);
        $I->assertCount(3, $parsing['class'][8]['arguments'][0]['expr']['items']);
        $I->assertEquals('key1', $parsing['class'][8]['arguments'][0]['expr']['items'][0]['name']);
        $I->assertEquals('value', $parsing['class'][8]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $I->assertEquals('key2', $parsing['class'][8]['arguments'][0]['expr']['items'][1]['name']);
        $I->assertEquals('value', $parsing['class'][8]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $I->assertEquals('key3', $parsing['class'][8]['arguments'][0]['expr']['items'][2]['name']);
        $I->assertEquals(308, $parsing['class'][8]['arguments'][0]['expr']['items'][2]['expr']['type']);

        // Properties
        $I->assertTrue(isset($parsing['properties']));
        $I->assertCount(3, $parsing['properties']);

        // Multiple well ordered annotations
        $I->assertTrue(isset($parsing['properties']['testProp1']));
        $I->assertCount(4, $parsing['properties']['testProp1']);
        $I->assertEquals('var', $parsing['properties']['testProp1'][0]['name']);
        $I->assertEquals('Simple', $parsing['properties']['testProp1'][1]['name']);
        $I->assertEquals('SingleParam', $parsing['properties']['testProp1'][2]['name']);
        $I->assertEquals('MultipleParams', $parsing['properties']['testProp1'][3]['name']);

        // Comment without content
        $I->assertFalse(isset($parsing['properties']['testProp2']));

        // Same line annotations
        $I->assertCount(3, $parsing['properties']['testProp3']);
        $I->assertEquals('Simple', $parsing['properties']['testProp3'][0]['name']);
        $I->assertEquals('SingleParam', $parsing['properties']['testProp3'][1]['name']);
        $I->assertEquals('MultipleParams', $parsing['properties']['testProp3'][2]['name']);

        // Same line annotations
        $I->assertCount(3, $parsing['properties']['testProp4']);
        $I->assertEquals('Simple', $parsing['properties']['testProp4'][0]['name']);
        $I->assertEquals('SingleParam', $parsing['properties']['testProp4'][1]['name']);
        $I->assertEquals('MultipleParams', $parsing['properties']['testProp4'][2]['name']);

        // No docblock
        $I->assertFalse(isset($parsing['properties']['testMethod5']));

        // No annotations
        $I->assertFalse(isset($parsing['properties']['testMethod6']));

        // Properties
        $I->assertTrue(isset($parsing['methods']));
        $I->assertCount(4, $parsing['methods']);

        // Multiple well ordered annotations
        $I->assertTrue(isset($parsing['methods']['testMethod1']));
        $I->assertCount(5, $parsing['methods']['testMethod1']);
        $I->assertEquals('return', $parsing['methods']['testMethod1'][0]['name']);
        $I->assertEquals('Simple', $parsing['methods']['testMethod1'][1]['name']);
        $I->assertEquals('SingleParam', $parsing['methods']['testMethod1'][2]['name']);
        $I->assertEquals('MultipleParams', $parsing['methods']['testMethod1'][3]['name']);
        $I->assertEquals('NamedMultipleParams', $parsing['methods']['testMethod1'][4]['name']);

        // Comment without content
        $I->assertFalse(
            isset($parsing['methods']['testMethod2'])
        );

        // Same line annotations
        $I->assertCount(3, $parsing['methods']['testMethod3']);
        $I->assertEquals('Simple', $parsing['methods']['testMethod3'][0]['name']);
        $I->assertEquals('SingleParam', $parsing['methods']['testMethod3'][1]['name']);
        $I->assertEquals('MultipleParams', $parsing['methods']['testMethod3'][2]['name']);

        // Unordered annotations
        $I->assertCount(3, $parsing['methods']['testMethod4']);
        $I->assertEquals('Simple', $parsing['methods']['testMethod4'][0]['name']);
        $I->assertEquals('SingleParam', $parsing['methods']['testMethod4'][1]['name']);
        $I->assertEquals('MultipleParams', $parsing['methods']['testMethod4'][2]['name']);

        // Unordered annotations + extra content
        $I->assertCount(3, $parsing['methods']['testMethod5']);
        $I->assertEquals('Simple', $parsing['methods']['testMethod5'][0]['name']);
        $I->assertEquals('SingleParam', $parsing['methods']['testMethod5'][1]['name']);
        $I->assertEquals('MultipleParams', $parsing['methods']['testMethod5'][2]['name']);
    }
}
