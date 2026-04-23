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

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class AppendContentTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseAppendContent(): void
    {
        $response = $this->getResponseObject();

        $response->setContent('<h1>Hello');
        $response->appendContent('</h1>');

        $expected = '<h1>Hello</h1>';
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);
    }
}
