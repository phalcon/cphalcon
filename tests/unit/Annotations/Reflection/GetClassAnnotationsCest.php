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

class GetClassAnnotationsCest
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

        $actual = $reflection->getClassAnnotations();
        $I->assertNull($actual);
    }

    /**
     * Tests parsing a real class
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-26
     */
    public function testParsingARealClass(UnitTester $I)
    {
        $reader = new Reader();

        $reflection = new Reflection(
            $reader->parse('TestClass')
        );

        $classAnnotations = $reflection->getClassAnnotations();

        $expected = Collection::class;
        $actual   = $classAnnotations;
        $I->assertInstanceOf($expected, $actual);

        $number = 0;

        foreach ($classAnnotations as $annotation) {
            $expected = Annotation::class;
            $actual   = $annotation;
            $I->assertInstanceOf($expected, $actual);

            $number++;
        }

        $expected = 9;
        $actual   = $number;
        $I->assertSame($expected, $actual);

        $expected = 9;
        $actual   = $classAnnotations;
        $I->assertCount($expected, $actual);
    }
}
