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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use ReflectionException;
use UnitTester;

/**
 * Class SetStylesCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug\Dump
 */
class SetStylesCest
{
    /**
     * Tests Phalcon\Support\Debug\Dump :: setStyles()
     *
     * @param UnitTester $I
     *
     * @throws ReflectionException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpSetStyles(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - setStyles()');

        $dump = new Dump(
            [],
            true
        );

        $expected = 'color:blue';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'int');
        $I->assertEquals($expected, $actual);

        $dump->setStyles(
            [
                'int' => 'color:indigo',
            ]
        );

        $expected = 'color:indigo';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'int');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Debug\Dump :: getStyle()
     *
     * @param UnitTester $I
     *
     * @throws ReflectionException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugDumpGetStyle(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - getStyle()');

        $dump = new Dump(
            [],
            true
        );

        $expected = 'color:gray';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'unknown');
        $I->assertEquals($expected, $actual);

        $expected = 'color:blue';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'int');
        $I->assertEquals($expected, $actual);
    }
}
