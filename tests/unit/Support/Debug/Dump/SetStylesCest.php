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

namespace Phalcon\Test\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use ReflectionException;
use UnitTester;

class SetStylesCest
{
    /**
     * Tests Phalcon\Debug\Dump :: setStyles()
     *
     * @throws ReflectionException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function debugDumpSetStyles(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - setStyles()');

        $dump = new Dump(
            [],
            true
        );

        $I->assertEquals(
            'color:blue',
            $I->callProtectedMethod($dump, 'getStyle', 'int')
        );


        $dump->setStyles(
            [
                'int' => 'color:indigo',
            ]
        );

        $I->assertEquals(
            'color:indigo',
            $I->callProtectedMethod($dump, 'getStyle', 'int')
        );
    }

    /**
     * Tests Phalcon\Debug\Dump :: getStyle()
     *
     * @throws ReflectionException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function debugDumpGetStyle(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - getStyle()');

        $dump = new Dump(
            [],
            true
        );

        $I->assertEquals(
            'color:gray',
            $I->callProtectedMethod($dump, 'getStyle', 'unknown')
        );

        $I->assertEquals(
            'color:blue',
            $I->callProtectedMethod($dump, 'getStyle', 'int')
        );
    }
}
