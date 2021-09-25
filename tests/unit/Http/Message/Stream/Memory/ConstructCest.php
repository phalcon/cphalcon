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

namespace Phalcon\Tests\Unit\Http\Message\Stream\Memory;

use Phalcon\Http\Message\Stream\Memory;
use Psr\Http\Message\StreamInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Memory :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-19
     */
    public function httpMessageStreamMemoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Memory - __construct()');
        $request = new Memory();
        $class   = StreamInterface::class;
        $I->assertInstanceOf($class, $request);
    }
}
