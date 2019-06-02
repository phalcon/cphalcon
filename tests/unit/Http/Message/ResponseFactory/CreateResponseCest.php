<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ResponseFactory;

use Phalcon\Http\Message\ResponseFactory;
use Psr\Http\Message\ResponseInterface;
use UnitTester;

class CreateResponseCest
{
    /**
     * Tests Phalcon\Http\Message\ResponseFactory :: createResponse()
     *
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
