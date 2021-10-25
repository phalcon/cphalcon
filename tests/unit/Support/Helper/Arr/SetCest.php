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

use Phalcon\Support\Helper\Arr\Set;
use UnitTester;

/**
 * Class SetCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class SetCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: set() - numeric
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrSetNumeric(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - set() - numeric');

        $object     = new Set();
        $collection = [];

        $expected = [
            1 => 'Phalcon',
        ];
        $actual   = $object($collection, 'Phalcon', 1);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: set() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrSetString(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - set() - string');

        $object     = new Set();
        $collection = [];

        $expected = [
            'suffix' => 'Framework',
        ];
        $actual   = $object($collection, 'Framework', 'suffix');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: set() - no index
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrSetNoIndex(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - set() - no index');

        $object     = new Set();
        $collection = [];

        $expected = [
            0 => 'Phalcon',
        ];
        $actual   = $object($collection, 'Phalcon');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Support\Helper\Arr :: set() - overwrite
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrSetOverwride(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - set() - overwrite');

        $object     = new Set();
        $collection = [
            1 => 'Phalcon',
        ];

        $expected = [
            1 => 'Framework',
        ];
        $actual   = $object($collection, 'Framework', 1);
        $I->assertEquals($expected, $actual);
    }
}
