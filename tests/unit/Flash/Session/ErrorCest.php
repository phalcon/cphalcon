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

namespace Phalcon\Test\Unit\Flash\Session;

use UnitTester;

class ErrorCest
{
    /**
     * Tests Phalcon\Flash\Session :: error()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashSessionError(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - error()');

        $I->skipTest('Need implementation');
    }
}
