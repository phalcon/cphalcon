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
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionException;

use function dataDir;
use function str_replace;

use const DIRECTORY_SEPARATOR;
use const PHP_VERSION;

final class ParseTest extends AbstractUnitTestCase
{

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-25
     */
    public function testAnnotationsReaderParse(): void
    {
        $includeFile = supportDir('assets/Annotations/TestClass.php');

        $this->assertFileExists($includeFile);

        require_once $includeFile;

        $reader  = new Reader();
        $parsing = $reader->parse('TestClass');

        $this->assertTrue(isset($parsing['class']));
        $this->assertCount(9, $parsing['class']);

        // Simple
        $this->assertEquals('Simple', $parsing['class'][0]['name']);
        $this->assertFalse(isset($parsing['class'][0]['arguments']));

        // Single Param
        $this->assertEquals('SingleParam', $parsing['class'][1]['name']);
        $this->assertTrue(isset($parsing['class'][1]['arguments']));
        $this->assertCount(1, $parsing['class'][1]['arguments']);
        $this->assertEquals('Param', $parsing['class'][1]['arguments'][0]['expr']['value']);

        // Multiple Params
        $this->assertEquals('MultipleParams', $parsing['class'][2]['name']);
        $this->assertTrue(isset($parsing['class'][2]['arguments']));
        $this->assertCount(8, $parsing['class'][2]['arguments']);
        $this->assertEquals('First', $parsing['class'][2]['arguments'][0]['expr']['value']);
        $this->assertEquals('Second', $parsing['class'][2]['arguments'][1]['expr']['value']);
        $this->assertEquals('1', $parsing['class'][2]['arguments'][2]['expr']['value']);
        $this->assertEquals('1.1', $parsing['class'][2]['arguments'][3]['expr']['value']);
        $this->assertEquals('-10', $parsing['class'][2]['arguments'][4]['expr']['value']);
        $this->assertEquals(305, $parsing['class'][2]['arguments'][5]['expr']['type']);
        $this->assertEquals(306, $parsing['class'][2]['arguments'][6]['expr']['type']);
        $this->assertEquals(304, $parsing['class'][2]['arguments'][7]['expr']['type']);

        // Single Array Param
        $this->assertEquals('Params', $parsing['class'][3]['name']);
        $this->assertTrue(isset($parsing['class'][3]['arguments']));
        $this->assertCount(1, $parsing['class'][3]['arguments']);
        $this->assertEquals(308, $parsing['class'][3]['arguments'][0]['expr']['type']);
        $this->assertCount(3, $parsing['class'][3]['arguments'][0]['expr']['items']);
        $this->assertEquals('key1', $parsing['class'][3]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $this->assertEquals('key2', $parsing['class'][3]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $this->assertEquals('key3', $parsing['class'][3]['arguments'][0]['expr']['items'][2]['expr']['value']);

        // Hash Params
        $this->assertEquals('HashParams', $parsing['class'][4]['name']);
        $this->assertTrue(isset($parsing['class'][4]['arguments']));
        $this->assertCount(1, $parsing['class'][8]['arguments']);
        $this->assertEquals(308, $parsing['class'][4]['arguments'][0]['expr']['type']);
        $this->assertCount(3, $parsing['class'][4]['arguments'][0]['expr']['items']);
        $this->assertEquals('key1', $parsing['class'][4]['arguments'][0]['expr']['items'][0]['name']);
        $this->assertEquals('value', $parsing['class'][4]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $this->assertEquals('key2', $parsing['class'][4]['arguments'][0]['expr']['items'][1]['name']);
        $this->assertEquals('value', $parsing['class'][4]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $this->assertEquals('key3', $parsing['class'][4]['arguments'][0]['expr']['items'][2]['name']);
        $this->assertEquals('value', $parsing['class'][4]['arguments'][0]['expr']['items'][2]['expr']['value']);

        // Named Params
        $this->assertEquals('NamedParams', $parsing['class'][5]['name']);
        $this->assertTrue(isset($parsing['class'][5]['arguments']));
        $this->assertCount(2, $parsing['class'][5]['arguments']);
        $this->assertEquals('second', $parsing['class'][5]['arguments'][1]['name']);
        $this->assertEquals('other', $parsing['class'][5]['arguments'][1]['expr']['value']);

        // Alternative Named Params
        $this->assertEquals('AlternativeNamedParams', $parsing['class'][6]['name']);
        $this->assertTrue(isset($parsing['class'][6]['arguments']));
        $this->assertCount(2, $parsing['class'][6]['arguments']);
        $this->assertEquals('second', $parsing['class'][6]['arguments'][1]['name']);
        $this->assertEquals('other', $parsing['class'][6]['arguments'][1]['expr']['value']);

        // Alternative Hash Params
        $this->assertEquals('AlternativeHashParams', $parsing['class'][7]['name']);
        $this->assertTrue(isset($parsing['class'][7]['arguments']));
        $this->assertCount(1, $parsing['class'][7]['arguments']);
        $this->assertEquals(308, $parsing['class'][7]['arguments'][0]['expr']['type']);
        $this->assertCount(3, $parsing['class'][7]['arguments'][0]['expr']['items']);
        $this->assertEquals('key1', $parsing['class'][7]['arguments'][0]['expr']['items'][0]['name']);
        $this->assertEquals('value', $parsing['class'][7]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $this->assertEquals('key2', $parsing['class'][7]['arguments'][0]['expr']['items'][1]['name']);
        $this->assertEquals('value', $parsing['class'][7]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $this->assertEquals('key3', $parsing['class'][7]['arguments'][0]['expr']['items'][2]['name']);
        $this->assertEquals('value', $parsing['class'][7]['arguments'][0]['expr']['items'][2]['expr']['value']);

        // Recursive Hash
        $this->assertEquals('RecursiveHash', $parsing['class'][8]['name']);
        $this->assertTrue(isset($parsing['class'][8]['arguments']));
        $this->assertCount(1, $parsing['class'][8]['arguments']);
        $this->assertEquals(308, $parsing['class'][8]['arguments'][0]['expr']['type']);
        $this->assertCount(3, $parsing['class'][8]['arguments'][0]['expr']['items']);
        $this->assertEquals('key1', $parsing['class'][8]['arguments'][0]['expr']['items'][0]['name']);
        $this->assertEquals('value', $parsing['class'][8]['arguments'][0]['expr']['items'][0]['expr']['value']);
        $this->assertEquals('key2', $parsing['class'][8]['arguments'][0]['expr']['items'][1]['name']);
        $this->assertEquals('value', $parsing['class'][8]['arguments'][0]['expr']['items'][1]['expr']['value']);
        $this->assertEquals('key3', $parsing['class'][8]['arguments'][0]['expr']['items'][2]['name']);
        $this->assertEquals(308, $parsing['class'][8]['arguments'][0]['expr']['items'][2]['expr']['type']);

        // Constants
        $this->assertTrue(isset($parsing['constants']));
        $this->assertCount(1, $parsing['constants']);
        $this->assertFalse(isset($parsing['constants']['TEST_CONST2']));
        $this->assertEquals('Simple', $parsing['constants']['TEST_CONST1'][0]['name']);

        // Properties
        $this->assertTrue(isset($parsing['properties']));
        $this->assertCount(3, $parsing['properties']);

        $this->assertTrue(isset($parsing['properties']['testProp1']));
        $this->assertCount(4, $parsing['properties']['testProp1']);
        $this->assertEquals('var', $parsing['properties']['testProp1'][0]['name']);
        $this->assertEquals('Simple', $parsing['properties']['testProp1'][1]['name']);
        $this->assertEquals('SingleParam', $parsing['properties']['testProp1'][2]['name']);
        $this->assertEquals('MultipleParams', $parsing['properties']['testProp1'][3]['name']);

        $this->assertFalse(isset($parsing['properties']['testProp2']));

        $this->assertCount(3, $parsing['properties']['testProp3']);
        $this->assertEquals('Simple', $parsing['properties']['testProp3'][0]['name']);
        $this->assertEquals('SingleParam', $parsing['properties']['testProp3'][1]['name']);
        $this->assertEquals('MultipleParams', $parsing['properties']['testProp3'][2]['name']);

        $this->assertCount(3, $parsing['properties']['testProp4']);
        $this->assertEquals('Simple', $parsing['properties']['testProp4'][0]['name']);
        $this->assertEquals('SingleParam', $parsing['properties']['testProp4'][1]['name']);
        $this->assertEquals('MultipleParams', $parsing['properties']['testProp4'][2]['name']);

        $this->assertFalse(isset($parsing['properties']['testMethod5']));
        $this->assertFalse(isset($parsing['properties']['testMethod6']));

        // Methods
        $this->assertTrue(isset($parsing['methods']));
        $this->assertCount(4, $parsing['methods']);

        $this->assertTrue(isset($parsing['methods']['testMethod1']));
        $this->assertCount(5, $parsing['methods']['testMethod1']);
        $this->assertEquals('return', $parsing['methods']['testMethod1'][0]['name']);
        $this->assertEquals('Simple', $parsing['methods']['testMethod1'][1]['name']);
        $this->assertEquals('SingleParam', $parsing['methods']['testMethod1'][2]['name']);
        $this->assertEquals('MultipleParams', $parsing['methods']['testMethod1'][3]['name']);
        $this->assertEquals('NamedMultipleParams', $parsing['methods']['testMethod1'][4]['name']);

        $this->assertFalse(isset($parsing['methods']['testMethod2']));

        $this->assertCount(3, $parsing['methods']['testMethod3']);
        $this->assertEquals('Simple', $parsing['methods']['testMethod3'][0]['name']);
        $this->assertEquals('SingleParam', $parsing['methods']['testMethod3'][1]['name']);
        $this->assertEquals('MultipleParams', $parsing['methods']['testMethod3'][2]['name']);

        $this->assertCount(3, $parsing['methods']['testMethod4']);
        $this->assertEquals('Simple', $parsing['methods']['testMethod4'][0]['name']);
        $this->assertEquals('SingleParam', $parsing['methods']['testMethod4'][1]['name']);
        $this->assertEquals('MultipleParams', $parsing['methods']['testMethod4'][2]['name']);

        $this->assertCount(3, $parsing['methods']['testMethod5']);
        $this->assertEquals('Simple', $parsing['methods']['testMethod5'][0]['name']);
        $this->assertEquals('SingleParam', $parsing['methods']['testMethod5'][1]['name']);
        $this->assertEquals('MultipleParams', $parsing['methods']['testMethod5'][2]['name']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-25
     */
    public function testAnnotationsReaderParseInvalidAnnotation(): void
    {
        $includeFile = supportDir('assets/Annotations/TestInvalid.php');

        $this->assertFileExists($includeFile);

        require_once $includeFile;

        $file = $includeFile;

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Syntax error, unexpected EOF in ' . $file);

        $reader = new Reader();
        $reader->parse('TestInvalid');
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-25
     */
    public function testAnnotationsReaderParseNonExistentClass(): void
    {
        $message = 'Class "TestClass1" does not exist';

        $this->expectException(ReflectionException::class);
        $this->expectExceptionMessage($message);

        $reader = new Reader();
        $reader->parse('TestClass1');
    }
}
