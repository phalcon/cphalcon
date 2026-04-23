<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Http\Response;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

final class GetSetContentTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseGetSetContent(): void
    {
        $content = Http::TEST_CONTENT;

        $response = new Response();

        $expected = '';
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);

        $response->setContent($content);

        $expected = $content;
        $actual   = $response->getContent();
        $this->assertSame($expected, $actual);
    }
}
