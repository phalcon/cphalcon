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

namespace Phalcon\Tests\Unit\Http\Cookie;

use Phalcon\Http\Cookie;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class GetSetValueCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Cookie :: getValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieGetValue(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - getValue()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');

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

        $I->assertSame($value, $cookie->getValue());

        $value = 'framework';
        $cookie->setValue($value);
        $I->assertSame($value, $cookie->getValue());
    }
}
