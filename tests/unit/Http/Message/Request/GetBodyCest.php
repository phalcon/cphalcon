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

namespace Phalcon\Tests\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use Phalcon\Http\Message\Stream;
use UnitTester;

class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getBody()');

        $fileName = dataDir('/assets/stream/mit.txt');

        $stream = new Stream($fileName, 'rb');

        $request = new Request('GET', null, $stream);

        $I->openFile($fileName);

        $I->assertStringEqualsFile($fileName, $request->getBody());
    }

    /**
     * Tests Phalcon\Http\Message\Request :: getBody() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getBody() - empty');

        $request = new Request();

        $I->assertInstanceOf(
            Stream::class,
            $request->getBody()
        );
    }
}
