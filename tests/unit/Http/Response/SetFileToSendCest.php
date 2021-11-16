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

use Phalcon\Tests\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetFileToSendCest extends HttpBase
{
    /**
     * Tests setFileToSend
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetFileToSend(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $filename = __FILE__;

        $response->setFileToSend($filename);

        ob_start();
        $response->send();

        $expected = file_get_contents($filename);
        $actual   = ob_get_clean();
        $I->assertEquals($expected, $actual);

        $I->assertTrue(
            $response->isSent()
        );
    }
}
