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

final class SetFileToSendTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetFileToSend(): void
    {
        $response = $this->getResponseObject();
        $filename = __FILE__;
        $response->setFileToSend($filename);

        ob_start();
        $response->send();

        $expected = file_get_contents($filename);
        $actual   = ob_get_clean();
        $this->assertSame($expected, $actual);

        $actual = $response->isSent();
        $this->assertTrue($actual);
    }
}
