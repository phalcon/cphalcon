<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\StreamFactory;

use Phalcon\Http\Message\StreamFactory;
use Psr\Http\Message\StreamFactoryInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: __construct()
     *
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
