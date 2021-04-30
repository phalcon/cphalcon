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

class SendCest
{
    /**
     * Tests Phalcon\Http\Response\Headers :: send()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-08
     */
    public function httpResponseHeadersSend(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Headers - send()');

        $headers = new Headers();

        $headers->set('Content-Type', 'text/html; charset=UTF-8');
        $headers->set('Content-Encoding', 'gzip');

        $actual = $headers->send();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Http\Response\Headers :: send() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-22
     * @issue  15334
     */
    public function httpResponseHeadersSendTwice(UnitTester $I)
    {
        $I->wantToTest('Http\Response\Headers - send() - twice');

        $headers = new Headers();

        $headers->set('Content-Type', 'text/html; charset=UTF-8');
        $headers->set('Content-Encoding', 'gzip');

        $actual = $headers->isSent();
        $I->assertFalse($actual);

        $actual = $headers->send();
        $I->assertTrue($actual);

        $actual = $headers->isSent();
        $I->assertTrue($actual);

        $actual = $headers->send();
        $I->assertFalse($actual);
    }
}
