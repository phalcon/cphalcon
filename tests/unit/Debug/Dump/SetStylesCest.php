<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Debug\Dump;

use Phalcon\Debug\Dump;
use UnitTester;

/**
 * Class SetStylesCest
 */
class SetStylesCest
{
    /**
     * Tests Phalcon\Debug\Dump :: setStyles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @throws \ReflectionException
     */
    public function debugDumpSetStyles(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - setStyles()');
        $dump = new Dump([], true);

        $expected = 'color:blue';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'int');
        $I->assertEquals($expected, $actual);

        $dump->setStyles(['int' => 'color:indigo']);
        $expected = 'color:indigo';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'int');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Debug\Dump :: getStyle()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @throws \ReflectionException
     */
    public function debugDumpGetStyle(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - getStyle()');
        $dump = new Dump([], true);

        $expected = 'color:gray';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'unknown');
        $I->assertEquals($expected, $actual);

        $expected = 'color:blue';
        $actual   = $I->callProtectedMethod($dump, 'getStyle', 'int');
        $I->assertEquals($expected, $actual);
    }
}
