<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config\Adapter\Grouped;

use UnitTester;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Config\Adapter\Grouped :: offsetUnset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterGroupedOffsetUnset(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Grouped - offsetUnset()");
        $I->skipTest("Need implementation");
    }
}
