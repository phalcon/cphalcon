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

namespace Phalcon\Test\Unit\Http\Response\Headers;

use Phalcon\Http\Response\Headers;
use UnitTester;

class SetRawCest
{
    /**
     * Tests Phalcon\Http\Response\Headers :: setRaw()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-08
     */
    public function httpResponseHeadersSetRaw(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Headers - setRaw()');

        $headers = new Headers();
        $headers->setRaw('Content-Type: text/html');

        $I->assertTrue($headers->has('Content-Type: text/html'));
        $I->assertFalse($headers->has('Content-Type: text/plain'));
    }
}
