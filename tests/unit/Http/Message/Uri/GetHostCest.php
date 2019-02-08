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
 * Class GetHostCest
 */
class GetHostCest
{
    /**
     * Tests Phalcon\Http\Message\Uri :: getHost()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetHost(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getHost()');

        $query = 'https://phalcon:secret@dev.phalcon.ld:8080/action?param=value#frag';
        $uri   = new Uri($query);

        $expected = 'dev.phalcon.ld';
        $actual   = $uri->getHost();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Uri :: getHost() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function httpUriGetHostEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Uri - getHost() - empty');

        $I->expectThrowable(
            new \InvalidArgumentException('The source URI string appears to be malformed'),
            function () {
                $query  = 'https://';
                $uri    = new Uri($query);
                $actual = $uri->getHost();
            }
        );
    }
}
