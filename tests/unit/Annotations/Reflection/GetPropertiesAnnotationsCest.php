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

class GetPropertiesAnnotationsCest
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

        $actual = $reflection->getPropertiesAnnotations();
        $I->assertIsArray($actual);
        $I->assertIsEmpty($actual);
    }

    /**
     * Tests Phalcon\Annotations\Reflection :: getPropertiesAnnotations()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-21
     */
    public function annotationsReflectionGetPropertiesAnnotations(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reflection - getPropertiesAnnotations()');

        $reader = new Reader();

        $reflection = new Reflection(
            $reader->parse('TestClass')
        );

        $propertiesAnnotations = $reflection->getPropertiesAnnotations();

        $I->assertIsArray($propertiesAnnotations);

        $number = 0;

        foreach ($propertiesAnnotations as $annotation) {
            $expected = Collection::class;
            $actual   = $annotation;
            $I->assertInstanceOf($expected, $actual);

            $number++;
        }

        $expected = 3;
        $actual   = $number;
        $I->assertSame($expected, $actual);

        $expected = 3;
        $actual   = $propertiesAnnotations;
        $I->assertCount($expected, $actual);
    }
}
