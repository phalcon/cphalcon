<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\UriFactory;

use Phalcon\Http\Message\UriFactory;
use Psr\Http\Message\UriInterface;
use TypeError;
use UnitTester;

class CreateUriCest
{
    /**
     * Tests Phalcon\Http\Message\UriFactory :: createUri()
     *
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
