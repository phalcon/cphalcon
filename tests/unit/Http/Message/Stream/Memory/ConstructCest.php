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

namespace Phalcon\Test\Unit\Http\Message\Stream\Memory;

use Phalcon\Http\Message\Stream\Memory;
use Psr\Http\Message\StreamInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Memory :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
