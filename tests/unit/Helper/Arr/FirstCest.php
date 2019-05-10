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

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class FirstCest
{
    /**
     * Tests Phalcon\Helper\Arr :: first()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrFirst(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - first()');

        $collection = [
            'Phalcon',
            'Framework',
        ];

        $I->assertEquals(
            'Phalcon',
            Arr::first($collection)
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: first() - function
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function helperArrFirstFunction(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - first() - function');

        $collection = [
            'Phalcon',
            'Framework',
        ];

        $actual = Arr::first(
            $collection,
            function ($element) {
                return strlen($element) > 8;
            }
        );

        $I->assertEquals(
            'Framework',
            $actual
        );
    }
}
