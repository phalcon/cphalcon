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

use Phalcon\Support\Helper\Arr\First;
use UnitTester;

use function strlen;

/**
 * Class FirstCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class FirstCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: first()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrFirst(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - first()');

        $object     = new First();
        $collection = [
            'Phalcon',
            'Framework',
        ];
        $expected   = 'Phalcon';
        $actual     = $object($collection);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: first() - function
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrFirstFunction(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - first() - function');

        $object     = new First();
        $collection = [
            'Phalcon',
            'Framework',
        ];
        $expected   = 'Framework';
        $actual     = $object(
            $collection,
            function ($element) {
                return strlen($element) > 8;
            }
        );
        $I->assertEquals($expected, $actual);
    }
}
