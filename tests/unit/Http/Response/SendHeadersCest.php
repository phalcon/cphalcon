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

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class SendHeadersCest
{
    /**
     * Tests Phalcon\Http\Response :: sendHeaders()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpResponseSendHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Response - sendHeaders()');

        $I->skipTest('Need implementation');
    }
}
