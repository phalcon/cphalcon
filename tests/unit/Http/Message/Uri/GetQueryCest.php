<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Uri;

use Phalcon\Http\Message\Uri;
use UnitTester;

/**
 * Class GetQueryCest
 */
class GetQueryCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: getQuery()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
