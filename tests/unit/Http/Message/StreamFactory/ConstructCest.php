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

namespace Phalcon\Tests\Unit\Http\Message\StreamFactory;

use Phalcon\Http\Message\StreamFactory;
use Psr\Http\Message\StreamFactoryInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpStreamFactoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\StreamFactory - __construct()');

        $factory = new StreamFactory();
        $class   = StreamFactoryInterface::class;
        $I->assertInstanceOf($class, $factory);
    }
}
