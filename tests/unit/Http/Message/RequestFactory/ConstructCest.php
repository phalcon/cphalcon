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

namespace Phalcon\Tests\Unit\Http\Message\RequestFactory;

use Phalcon\Http\Message\Request;
use Psr\Http\Message\RequestInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageRequestConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - __construct()');

        $request = new Request();

        $I->assertInstanceOf(
            RequestInterface::class,
            $request
        );
    }
}
