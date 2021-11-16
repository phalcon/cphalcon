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

namespace Phalcon\Tests\Unit\Http\Message\Uri;

use Phalcon\Http\Message\Uri;
use UnitTester;

class GetQueryCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: getQuery()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageUriGetQuery(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Uri - getQuery()');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $expected = 'param=value';
        $actual   = $uri->getQuery();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: getQuery() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-07
     */
    public function httpUriGetQueryEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getQuery() - empty');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action';
        $uri   = new Uri($query);

        $actual = $uri->getQuery();
        $I->assertEmpty($actual);
    }
}
