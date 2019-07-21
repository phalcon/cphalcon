<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Response;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class AppendContentCest extends HttpBase
{
    /**
     * Tests appendContent
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-08
     */
    public function testHttpResponseAppendContent(UnitTester $I)
    {
        $response = $this->getResponseObject();

        $response->setContent('<h1>Hello');
        $response->appendContent('</h1>');

        $I->assertEquals(
            '<h1>Hello</h1>',
            $response->getContent()
        );
    }
}
