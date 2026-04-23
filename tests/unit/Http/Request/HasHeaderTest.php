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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class HasHeaderTest extends AbstractHttpBase
{
    /**
     * @author limx <715557344@qq.com>
     * @since  2017-10-26
     */
    public function testHttpRequestCustomHeaderHas(): void
    {
        $_SERVER['HTTP_FOO']     = 'Bar';
        $_SERVER['HTTP_BLA_BLA'] = 'boo';
        $_SERVER['HTTP_AUTH']    = true;

        $request = $this->getRequestObject();

        $actual = $request->hasHeader('HTTP_FOO');
        $this->assertTrue($actual);

        $actual = $request->hasHeader('AUTH');
        $this->assertTrue($actual);

        $actual = $request->hasHeader('HTTP_BLA_BLA');
        $this->assertTrue($actual);
    }
}
