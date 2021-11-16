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

namespace Phalcon\Tests\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

class GetReasonPhraseCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getReasonPhrase()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetReasonPhrase(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getReasonPhrase()');

        $response = new Response();

        $I->assertEquals(
            'OK',
            $response->getReasonPhrase()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getReasonPhrase() - other port
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetReasonPhraseOtherPort(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getReasonPhrase() - other port');

        $response = new Response('php://memory', 420);

        $I->assertEquals(
            'Method Failure',
            $response->getReasonPhrase()
        );
    }
}
