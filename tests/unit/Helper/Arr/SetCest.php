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

namespace Phalcon\Tests\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class SetCest
{
    /**
     * Tests Phalcon\Helper\Arr :: set() - numeric
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function helperArrSetNumeric(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - numeric');

        $collection = [];

        $expected = [
            1 => 'Phalcon',
        ];

        $I->assertEquals(
            $expected,
            Arr::set($collection, 'Phalcon', 1)
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: set() - string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function helperArrSetString(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - string');

        $collection = [];

        $expected = [
            'suffix' => 'Framework',
        ];

        $I->assertEquals(
            $expected,
            Arr::set($collection, 'Framework', 'suffix')
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: set() - no index
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function helperArrSetNoIndex(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - no index');

        $collection = [];

        $expected = [
            0 => 'Phalcon',
        ];

        $I->assertEquals(
            $expected,
            Arr::set($collection, 'Phalcon')
        );
    }

    /**
     * Tests Phalcon\Helper\Arr :: set() - overwrite
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function helperArrSetOverwride(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - overwrite');

        $collection = [
            1 => 'Phalcon',
        ];

        $expected = [
            1 => 'Framework',
        ];

        $I->assertEquals(
            $expected,
            Arr::set($collection, 'Framework', 1)
        );
    }
}
