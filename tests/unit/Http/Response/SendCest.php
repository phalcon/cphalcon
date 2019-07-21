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

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class SendCest
{
    /**
     * Tests Phalcon\Http\Response :: send()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpResponseSend(UnitTester $I)
    {
        $I->wantToTest('Http\Response - send()');

        $I->skipTest('Need implementation');
    }
}
