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
use Phalcon\Http\Message\Stream;
use UnitTester;

class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetBody(UnitTester $I)
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $I->wantToTest('Http\Message\Response - getBody()');

        $fileName = dataDir('/assets/stream/mit.txt');

        $stream = new Stream($fileName, 'rb');

        $response = new Response($stream);

        $I->openFile($fileName);

        $I->seeFileContentsEqual(
            $response->getBody()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getBody() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getBody() - empty');

        $response = new Response();

        $I->assertInstanceOf(
            Stream::class,
            $response->getBody()
        );
    }
}
