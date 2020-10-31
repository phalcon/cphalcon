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
use Psr\Http\Message\UriFactoryInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\UriFactory :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-07
     */
    public function httpUriFactoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\UriFactory - __construct()');

        $factory = new UriFactory();
        $class   = UriFactoryInterface::class;
        $I->assertInstanceOf($class, $factory);
    }
}
