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

namespace Phalcon\Test\Unit\Http\Uri;

use Phalcon\Http\Message\Uri;
use UnitTester;

/**
 * Class GetPortCest
 */
class GetPortCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: getPort()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetPort(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getPort()');
        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $expected = 8080;
        $actual   = $uri->getPort();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: getPort() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetPortEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getPort() - empty');
        $query = 'https://phalcon:secret@dev.phalcon.ld/action?param=value';
        $uri   = new Uri($query);

        $actual = $uri->getPort();
        $I->assertNull($actual);
    }
}
