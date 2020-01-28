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

class MessageCest
{
    /**
     * Tests Phalcon\Flash\Session :: message()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashSessionMessage(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - message()');

        $I->skipTest('Need implementation');
    }
}
