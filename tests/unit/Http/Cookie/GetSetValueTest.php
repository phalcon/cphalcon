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

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class GetSetValueTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpCookieGetValue(): void
    {
        $this->setDiService('sessionStream');

        $value  = 'phalcon';
        $cookie = $this->getCookieObject();

        $expected = $value;
        $actual   = $cookie->getValue();
        $this->assertSame($expected, $actual);

        $value = 'framework';
        $cookie->setValue($value);

        $expected = $value;
        $actual   = $cookie->getValue();
        $this->assertSame($expected, $actual);

        $value = 'encrypted';
        $cookie->useEncryption(true);
        $cookie->setValue($value);

        $expected = $value;
        $actual   = $cookie->getValue();
        $this->assertSame($expected, $actual);
    }
}
