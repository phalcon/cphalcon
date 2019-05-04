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

use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function outputDir;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamConstruct(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - __construct()');
        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => outputDir()]);

        $class = Stream::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: __construct() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamConstructException(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - __construct() - exception');

        $I->expectThrowable(
            new Exception("The 'cacheDir' must be specified in the options"),
            function () {
                $factory = new SerializerFactory();
                $adapter = new Stream($factory);
            }
        );
    }
}
