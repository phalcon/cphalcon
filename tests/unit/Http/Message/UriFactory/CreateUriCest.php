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

namespace Phalcon\Test\Unit\Http\UriFactory;

use Phalcon\Http\Message\UriFactory;
use Psr\Http\Message\UriInterface;
use UnitTester;

/**
 * Class CreateUriCest
 */
class CreateUriCest
{
    /**
     * Tests Phalcon\Http\Message\UriFactory :: createUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpUriFactoryCreateUri(UnitTester $I)
    {
        $I->wantToTest('Http\UriFactory - createUri()');

        $factory = new UriFactory();
        $uri     = $factory->createUri();
        $class   = UriInterface::class;
        $I->assertInstanceOf($class, $uri);
    }
}
