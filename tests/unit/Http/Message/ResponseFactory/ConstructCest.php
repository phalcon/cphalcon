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

namespace Phalcon\Test\Unit\Http\Message\ResponseFactory;

use Phalcon\Http\Message\Response;
use Psr\Http\Message\ResponseInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-08
     */
    public function httpMessageResponseConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - __construct()');
        $response = new Response();
        $class   = ResponseInterface::class;
        $I->assertInstanceOf($class, $response);
    }
}
