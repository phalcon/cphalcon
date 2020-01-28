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

namespace Phalcon\Test\Unit\Http\Message\ResponseFactory;

use Phalcon\Http\Message\ResponseFactory;
use Psr\Http\Message\ResponseInterface;
use UnitTester;

class CreateResponseCest
{
    /**
     * Tests Phalcon\Http\Message\ResponseFactory :: createResponse()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageResponseFactoryCreateResponse(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ResponseFactory - createResponse()');
        $factory  = new ResponseFactory();
        $response = $factory->createResponse();
        $class    = ResponseInterface::class;
        $I->assertInstanceOf($class, $response);
    }
}
