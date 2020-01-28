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

namespace Phalcon\Test\Unit\Http\Message\UriFactory;

use Phalcon\Http\Message\UriFactory;
use Psr\Http\Message\UriInterface;
use UnitTester;

class CreateUriCest
{
    /**
     * Tests Phalcon\Http\Message\UriFactory :: createUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-09
     */
    public function httpMessageUriFactoryCreateUri(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UriFactory - createUri()');

        $factory = new UriFactory();
        $uri     = $factory->createUri();
        $class   = UriInterface::class;
        $I->assertInstanceOf($class, $uri);
    }
}
