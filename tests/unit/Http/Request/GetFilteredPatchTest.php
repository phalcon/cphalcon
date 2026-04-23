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

final class GetFilteredPatchTest extends AbstractHttpBase
{
    /**
     * @issue  16188
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-11-01
     */
    public function testHttpRequestGetFilteredPatch(): void
    {
        $this->registerStream();

        file_put_contents(Http::STREAM, 'no-id=24');

        $_SERVER['REQUEST_METHOD'] = Http::METHOD_PATCH;

        $request = $this->getRequestObject();
        $request
            ->setParameterFilters('id', ['absint'], ['patch'])
        ;

        $expected = 24;
        $actual   = $request->getFilteredPut('id', 24);
        $this->assertSame($expected, $actual);

        $this->unregisterStream();
    }
}
