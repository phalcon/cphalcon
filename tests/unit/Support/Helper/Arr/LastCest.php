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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\Last;
use UnitTester;

use function strlen;

/**
 * Class LastCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class LastCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: last()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrLast(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - last()');

        $object     = new Last();
        $collection = [
            'Phalcon',
            'Framework',
        ];

        $expected = 'Framework';
        $actual   = $object($collection);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: last() - function
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrLastFunction(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - last() - function');

        $object     = new Last();
        $collection = [
            'Phalcon',
            'Framework',
        ];

        $expected = 'Phalcon';
        $actual   = $object(
            $collection,
            function ($element) {
                return strlen($element) < 8;
            }
        );
        $I->assertEquals($expected, $actual);
    }
}
