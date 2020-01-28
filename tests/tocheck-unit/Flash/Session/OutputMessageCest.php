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

class OutputMessageCest
{
    /**
     * Tests Phalcon\Flash\Session :: outputMessage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashSessionOutputMessage(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - outputMessage()');

        $I->skipTest('Need implementation');
    }
}
