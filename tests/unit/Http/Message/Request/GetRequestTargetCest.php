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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use Phalcon\Http\Message\Uri;
use UnitTester;

class GetRequestTargetCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getRequestTarget()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetRequestTarget(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getRequestTarget()');

        $uri     = new Uri('https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag');
        $request = new Request('GET', $uri);

        $I->assertEquals(
            '/action?param=value',
            $request->getRequestTarget()
        );
    }
}
