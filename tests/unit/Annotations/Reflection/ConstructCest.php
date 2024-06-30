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

namespace Phalcon\Tests\Unit\Annotations\Reflection;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;
use UnitTester;

use function dataDir;

class ConstructCest
{
    /**
     * Executed before each test.
     *
     * @param UnitTester $I
     */
    protected function _before(UnitTester $I)
    {
        require_once dataDir('fixtures/Annotations/TestClass.php');
    }

    /**
     * Tests Phalcon\Annotations\Reflection :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function annotationsReflectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reflection - __construct()');

        $reflection = new Reflection();

        $I->assertInstanceOf(Reflection::class, $reflection);
    }

    /**
     * Tests parsing class annotations
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-26
     */
    public function testClassAnnotations(UnitTester $I)
    {
        $reader = new Reader();

        $reflection = new Reflection(
            $reader->parse('TestClass')
        );

        $constantsAnnotations = $reflection->getConstantsAnnotations();
        $I->assertIsArray($constantsAnnotations);

        $annotations = $constantsAnnotations['TEST_CONST1'];

        $expected = Collection::class;
        $actual   = $annotations;
        $I->assertInstanceOf($expected, $actual);

        $actual = $annotations->has('Simple');
        $I->assertTrue($actual);

        $methodsAnnotations = $reflection->getMethodsAnnotations();

        $I->assertIsArray($methodsAnnotations);

        $expected = Collection::class;
        $actual   = $methodsAnnotations['testMethod1'];
        $I->assertInstanceOf($expected, $actual);

        $total = 0;

        foreach ($methodsAnnotations as $method => $annotations) {
            $I->assertIsString($method);

            $number = 0;

            foreach ($annotations as $annotation) {
                $expected = Annotation::class;
                $actual   = $annotation;
                $I->assertInstanceOf($expected, $actual);

                $number++;
                $total++;
            }

            $I->assertGreaterThan(0, $number);
        }

        $expected = 14;
        $actual   = $total;
        $I->assertSame($expected, $actual);

        /** @var Collection $annotations */
        $annotations = $methodsAnnotations['testMethod1'];

        $actual = $annotations->has('Simple');
        $I->assertTrue($actual);

        $actual = $annotations->has('NoSimple');
        $I->assertFalse($actual);

        $annotation = $annotations->get('Simple');

        $expected = 'Simple';
        $actual   = $annotation->getName();
        $I->assertSame($expected, $actual);

        $expected = [];
        $actual   = $annotation->getArguments();
        $I->assertSame($expected, $actual);

        $expected = 0;
        $actual   = $annotation->numberArguments();
        $I->assertSame($expected, $actual);


        $actual = $annotation->hasArgument('none');
        $I->assertFalse($actual);

        $annotation = $annotations->get('NamedMultipleParams');
        $expected   = 'NamedMultipleParams';
        $actual     = $annotation->getName();
        $I->assertSame($expected, $actual);

        $expected = 2;
        $actual   = $annotation->numberArguments();
        $I->assertSame($expected, $actual);

        $expected = ['first' => 'First', 'second' => 'Second'];
        $actual   = $annotation->getArguments();
        $I->assertSame($expected, $actual);

        $actual = $annotation->hasArgument('first');
        $I->assertTrue($actual);

        $I->assertSame('First', $annotation->getArgument('first'));

        $actual = $annotation->hasArgument('none');
        $I->assertFalse($actual);

        $propertiesAnnotations = $reflection->getPropertiesAnnotations();
        $I->assertIsArray($propertiesAnnotations);

        $expected = Collection::class;
        $actual   = $propertiesAnnotations['testProp1'];
        $I->assertInstanceOf($expected, $actual);

        $total = 0;

        foreach ($propertiesAnnotations as $annotations) {
            $expected = Collection::class;
            $actual   = $propertiesAnnotations['testProp1'];
            $I->assertInstanceOf($expected, $actual);

            $number = 0;

            foreach ($annotations as $annotation) {
                $expected = Annotation::class;
                $actual   = $annotation;
                $I->assertInstanceOf($expected, $actual);

                $number++;
                $total++;
            }

            $I->assertGreaterThan(0, $number);
        }

        $expected = 10;
        $actual   = $total;
        $I->assertSame($expected, $actual);
    }
}
