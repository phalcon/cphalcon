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

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use UnitTester;

class WasFreshInstanceCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault :: wasFreshInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diFactoryDefaultWasFreshInstance(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - wasFreshInstance()');

        $I->skipTest('Need implementation');
    }
}
