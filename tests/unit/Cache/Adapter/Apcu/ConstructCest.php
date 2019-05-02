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

namespace Phalcon\Test\Unit\Cache\Adapter\Apcu;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-09
     */
    public function storageAdapterApcuConstruct(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - __construct()');
        $adapter = new Apcu();

        $class = Apcu::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
