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

namespace Phalcon\Test\Unit\Http\Message\Uri;

use Phalcon\Http\Message\Uri;
use UnitTester;

class ToStringCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: __toString()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageUriToString(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - __toString()');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $I->assertEquals($query, (string) $uri);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: __toString() - path no lead slash
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-07
     */
    public function httpUriToStringPathNoLeadSlash(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - __toString() - path no lead slash');
        $uri = new Uri('https://dev.phalcon.ld');

        $newInstance = $uri->withPath('action/reaction');
        $expected    = 'https://dev.phalcon.ld/action/reaction';
        $actual      = $newInstance->__toString();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: __toString() - path many slashes
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-01
     */
    public function httpUriToStringPathManySlashes(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - __toString() - path many slashes');
        $uri = new Uri('https://dev.phalcon.ld');

        $newInstance = $uri->withPath('///action/reaction');
        $expected    = 'https://dev.phalcon.ld/action/reaction';
        $actual      = $newInstance->__toString();
        $I->assertEquals($expected, $actual);
    }
}
