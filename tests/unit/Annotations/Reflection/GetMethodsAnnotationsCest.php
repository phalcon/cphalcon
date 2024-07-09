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

use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Reader;
use Phalcon\Annotations\Reflection;
use UnitTester;

use function dataDir;

class GetMethodsAnnotationsCest
{
    /**
     * executed before each test
     */
    protected function _before(UnitTester $I)
    {
        require_once dataDir('fixtures/Annotations/TestClass.php');
    }

    /**
     * Tests creating empty Reflection object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-26
     */
    public function testEmptyReflection(UnitTester $I)
    {
        $reflection = new Reflection();

        $actual = $reflection->getMethodsAnnotations();
        $I->assertIsArray($actual);
        $I->assertIsEmpty($actual);
    }

    /**
     * Tests Phalcon\Annotations\Reflection :: getMethodsAnnotations()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function annotationsReflectionGetMethodsAnnotations(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reflection - getMethodsAnnotations()');

        $reader = new Reader();

        $reflection = new Reflection(
            $reader->parse('TestClass')
        );

        $methodsAnnotations = $reflection->getMethodsAnnotations();
        $I->assertIsArray($methodsAnnotations);

        $number = 0;

        foreach ($methodsAnnotations as $annotation) {
            $expected = Collection::class;
            $actual   = $annotation;
            $I->assertInstanceOf($expected, $actual);

            $number++;
        }

        $expected = 4;
        $actual   = $number;
        $I->assertSame($expected, $actual);

        $expected = 4;
        $actual   = $methodsAnnotations;
        $I->assertCount($expected, $actual);
    }
}
