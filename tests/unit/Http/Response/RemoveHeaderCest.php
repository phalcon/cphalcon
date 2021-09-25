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

class RemoveHeaderCest extends HttpBase
{
    /**
     * Test the removeHeader
     *
     * @author Mohamad Rostami <mb.rostami.h@gmail.com>
     */
    public function testHttpResponseRemoveHeaderContentType(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->resetHeaders();

        $response->setHeader('Content-Type', 'text/html');

        $headers = $response->getHeaders()->toArray();

        $I->assertArrayHasKey('Content-Type', $headers);

        $I->assertEquals(
            'text/html',
            $headers['Content-Type']
        );

        $response->removeHeader('Content-Type');

        $headers = $response->getHeaders()->toArray();

        $I->assertArrayNotHasKey('Content-Type', $headers);
    }
}
