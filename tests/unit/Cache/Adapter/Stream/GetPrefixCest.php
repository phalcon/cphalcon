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
use function outputDir;

/**
 * Class GetPrefixCest
 */
class GetPrefixCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getPrefix()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getPrefix()');
        $factory = new SerializerFactory();
        $adapter = new Stream(
            $factory,
            [
                'cacheDir' => outputDir(),
                'prefix'   => 'my-prefix',
            ]
        );

        $expected = 'my-prefix';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getPrefix() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getPrefix() - default');
        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => outputDir()]);

        $expected = 'phstrm-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
