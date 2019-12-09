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

namespace Phalcon\Test\Unit\Flash\Direct;

use UnitTester;

class ClearCest
{
    /**
     * Tests Phalcon\Flash\Direct :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashDirectClear(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - clear()');

        $I->skipTest('Need implementation');
    }
}
