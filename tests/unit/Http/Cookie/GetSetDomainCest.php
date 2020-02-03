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

namespace Phalcon\Test\Unit\Http\Cookie;

use Phalcon\Http\Cookie;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class GetSetDomainCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Cookie :: getDomain()/setDomain()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieGetSetDomain(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - getDomain()/setDomain()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');;

        $name     = 'test';
        $value    = "phalcon";
        $expire   = time() - 100;
        $path     = "/";
        $secure   = true;
        $domain   = "phalcon.ld";
        $httpOnly = true;
        $options  = ["samesite" => "Lax"];

        $cookie = new Cookie(
            $name,
            $value,
            $expire,
            $path,
            $secure,
            $domain,
            $httpOnly,
            $options
        );
        $cookie->setDI($this->container);

        $I->assertEquals($domain, $cookie->getDomain());

        $domain = 'phalcon.io';
        $cookie->setDomain($domain);
        $I->assertEquals($domain, $cookie->getDomain());
    }
}
