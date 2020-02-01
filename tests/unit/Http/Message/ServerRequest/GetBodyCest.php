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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use Phalcon\Http\Message\Stream;
use UnitTester;

class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getBody()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getBody()');

        $fileName = dataDir('/assets/stream/mit.txt');

        $stream  = new Stream($fileName, 'rb');
        $request = new ServerRequest('GET', null, [], $stream);

        $I->openFile($fileName);

        $I->seeFileContentsEqual(
            $request->getBody()
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getBody() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getBody() - empty');

        $request = new ServerRequest();

        $I->assertInstanceOf(
            Stream\Input::class,
            $request->getBody()
        );
    }
}
