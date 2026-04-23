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

use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class SetRawHeaderTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetRawHeader(): void
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();
        $response->setRawHeader(Http::HTTP_404_NOT_FOUND);

        $actual = $response->getHeaders();

        $expected = '';
        $actual   = $actual->get(Http::HTTP_304_NOT_MODIFIED);
        $this->assertEquals($expected, $actual);
    }
}
