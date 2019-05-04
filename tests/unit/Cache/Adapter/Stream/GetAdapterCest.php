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

namespace Phalcon\Test\Unit\Cache\Adapter\Stream;

use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

/**
 * Class GetAdapterCest
 */
class GetAdapterCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getAdapter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getAdapter()');

        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => '/tmp']);

        $actual = $adapter->getAdapter();
        $I->assertNull($actual);
    }
}
