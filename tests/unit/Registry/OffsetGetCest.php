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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

/**
 * Class OffsetGetCest
 *
 * @package Phalcon\Test\Unit\Registry
 */
class OffsetGetCest
{
    /**
     * Tests Phalcon\Registry :: offsetGet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryOffsetGet(UnitTester $I)
    {
        $I->wantToTest('Registry - offsetGet()');
        $registry = new Registry();
        $registry->offsetSet('one', 1);
        $registry->offsetSet('two', 2);
        $registry->offsetSet('three', 3);

        $expected = 3;
        $actual   = $registry->offsetGet('three');
        $I->assertEquals($expected, $actual);
    }
}
