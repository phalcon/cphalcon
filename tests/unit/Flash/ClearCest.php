<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Flash;

use UnitTester;

class ClearCest
{
    /**
     * Tests Phalcon\Flash :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashClear(UnitTester $I)
    {
        $I->wantToTest('Flash - clear()');

        $I->skipTest('Need implementation');
    }
}
