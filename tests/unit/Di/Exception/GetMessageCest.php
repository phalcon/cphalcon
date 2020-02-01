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

namespace Phalcon\Test\Unit\Di\Exception;

use UnitTester;

class GetMessageCest
{
    /**
     * Unit Tests Phalcon\Di\Exception :: getMessage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diExceptionGetMessage(UnitTester $I)
    {
        $I->wantToTest('Di\Exception - getMessage()');

        $I->skipTest('Need implementation');
    }
}
