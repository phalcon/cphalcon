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

namespace Phalcon\Test\Unit\Http\Message\UriFactory;

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

    /**
     * Tests Phalcon\Http\Message\UriFactory :: createUri() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpUriFactoryCreateUriException(UnitTester $I)
    {
        $I->wantToTest('Http\UriFactory - createUri() - exception');
        $message = 'Argument 1 passed to Phalcon\Http\Message\UriFactory::createUri() ' .
                   'must be of the type string, ';
        if (PHP_VERSION_ID >= 70300) {
            $message .= 'int given';
        } else {
            $message .= 'integer given';
        }

        $I->expectThrowable(
            new \TypeError($message),
            function () {
                $factory = new UriFactory();
                $factory->createUri(123);
            }
        );
    }
}
