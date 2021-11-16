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

namespace Phalcon\Tests\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use Phalcon\Http\Message\Uri;
use UnitTester;

class GetUriCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetUri(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getUri()');
        $query   = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri     = new Uri($query);
        $request = new ServerRequest('GET', $uri);

        $expected = $uri;
        $actual   = $request->getUri();
        $I->assertEquals($expected, $actual);
    }
}
