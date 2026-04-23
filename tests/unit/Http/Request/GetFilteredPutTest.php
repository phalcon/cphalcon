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

use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

use function file_put_contents;

final class GetFilteredPutTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetFilteredPut(): void
    {
        $this->registerStream();

        file_put_contents(Http::STREAM, 'no-id=24');

        $_SERVER['REQUEST_METHOD'] = Http::METHOD_PUT;

        $request = $this->getRequestObject();
        $request
            ->setParameterFilters('id', ['absint'], ['put'])
        ;

        $expected = 24;
        $actual   = $request->getFilteredPut('id', 24);
        $this->assertSame($expected, $actual);

        $this->unregisterStream();
    }
}
