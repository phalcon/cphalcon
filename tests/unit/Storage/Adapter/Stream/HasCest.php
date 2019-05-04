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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use Exception;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function outputDir;
use function uniqid;

/**
 * Class HasCest
 */
class HasCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: has()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterStreamHas(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - has()');
        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => outputDir()]);

        $key = uniqid();

        $actual = $adapter->has($key);
        $I->assertFalse($actual);

        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);
    }
}
