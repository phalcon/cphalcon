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

use Phalcon\Http\Response;
use Phalcon\Http\Response\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

final class IsSentTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-08
     */
    public function testHttpResponseIsSent(): void
    {
        $content  = Http::TEST_CONTENT;
        $response = new Response($content);

        ob_start();

        $response->send();
        $result = ob_get_clean();

        $expected = $content;
        $actual   = $result;
        $this->assertSame($expected, $actual);

        $actual = $response->isSent();
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testHttpResponseSendAlreadySentThrows(): void
    {
        $response = new Response('test content');

        ob_start();
        $response->send();
        ob_end_clean();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Response was already sent');
        $response->send();
    }
}
