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
use Phalcon\Http\Message\Uri;
use UnitTester;

class WithUriCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithUri(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withUri()');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $request     = new ServerRequest();
        $newInstance = $request->withUri($uri);
        $I->assertNotEquals($request, $newInstance);

        $expected = $uri;
        $actual   = $newInstance->getUri();
        $I->assertEquals($expected, $actual);
    }
}
