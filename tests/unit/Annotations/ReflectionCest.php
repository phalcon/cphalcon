<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations;

use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;
use UnitTester;

class ReflectionCest
{
    /**
     * Tests creating empty Reflection object
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-26
     */
    public function testEmptyReflection(UnitTester $I)
    {
        $reflection = new Reflection();

        $I->assertEquals(null, $reflection->getClassAnnotations());
        $I->assertEquals(null, $reflection->getMethodsAnnotations());
        $I->assertEquals(null, $reflection->getPropertiesAnnotations());
    }

    /**
     * Tests parsing a real class
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-26
     */
    public function testParsingARealClass(UnitTester $I)
    {
        $reader     = new Reader();
        $reflection = new Reflection($reader->parse('TestClass'));

        $classAnnotations = $reflection->getClassAnnotations();
        $I->assertEquals('Phalcon\Annotations\Collection', get_class($classAnnotations));

        $number = 0;
        foreach ($classAnnotations as $annotation) {
            $I->assertEquals('Phalcon\Annotations\Annotation', get_class($annotation));
            $number++;
        }

        $I->assertEquals(9, $number);
        $I->assertCount(9, $classAnnotations);
    }

    /**
     * Tests parsing class annotations
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-26
     */
    public function testClassAnnotations(UnitTester $I)
    {
        $reader     = new Reader();
        $reflection = new Reflection($reader->parse('TestClass'));

        $methodsAnnotations = $reflection->getMethodsAnnotations();

        $I->assertEquals('array', gettype($methodsAnnotations));
        $I->assertEquals('Phalcon\Annotations\Collection', get_class($methodsAnnotations['testMethod1']));

        $total = 0;
        foreach ($methodsAnnotations as $method => $annotations) {
            $I->assertEquals('string', gettype($method));

            $number = 0;
            foreach ($annotations as $annotation) {
                $I->assertEquals('Phalcon\Annotations\Annotation', get_class($annotation));
                $number++;
                $total++;
            }
            $I->assertGreaterThan(0, $number);
        }

        $I->assertEquals(14, $total);

        /** @var \Phalcon\Annotations\Collection $annotations */
        $annotations = $methodsAnnotations['testMethod1'];

        $I->assertTrue($annotations->has('Simple'));
        $I->assertFalse($annotations->has('NoSimple'));

        $annotation = $annotations->get('Simple');
        $I->assertEquals('Simple', $annotation->getName());
        $I->assertEquals(null, $annotation->getArguments());
        $I->assertEquals(0, $annotation->numberArguments());
        $I->assertFalse($annotation->hasArgument('none'));

        $annotation = $annotations->get('NamedMultipleParams');
        $I->assertEquals('NamedMultipleParams', $annotation->getName());
        $I->assertEquals(2, $annotation->numberArguments());
        $I->assertEquals(['first' => 'First', 'second' => 'Second'], $annotation->getArguments());
        $I->assertTrue($annotation->hasArgument('first'));
        $I->assertEquals('First', $annotation->getArgument('first'));
        $I->assertFalse($annotation->hasArgument('none'));

        $propertiesAnnotations = $reflection->getPropertiesAnnotations();
        $I->assertTrue(is_array($propertiesAnnotations));
        $I->assertEquals('Phalcon\Annotations\Collection', get_class($propertiesAnnotations['testProp1']));

        $total = 0;
        foreach ($propertiesAnnotations as $property => $annotations) {
            $I->assertEquals('Phalcon\Annotations\Collection', get_class($propertiesAnnotations['testProp1']));

            $number = 0;
            foreach ($annotations as $annotation) {
                $I->assertEquals('Phalcon\Annotations\Annotation', get_class($annotation));
                $number++;
                $total++;
            }

            $I->assertGreaterThan(0, $number);
        }

        $I->assertEquals(10, $total);
    }

    /**
     * executed before each test
     */
    protected function _before(UnitTester $I)
    {
        require_once dataFolder('fixtures/Annotations/TestClass.php');
    }
}
