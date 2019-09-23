<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class SetContentCest extends HttpBase
{
    /**
     * Tests setContent
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-08
     */
    public function testHttpResponseSetContent(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->setContent('<h1>Hello');

        $I->assertEquals(
            '<h1>Hello',
            $response->getContent()
        );
    }
}
