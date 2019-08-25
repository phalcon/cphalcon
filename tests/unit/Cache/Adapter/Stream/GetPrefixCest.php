<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Adapter\Stream;

use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function outputDir;

class GetPrefixCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getPrefix()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function cacheAdapterStreamGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getPrefix()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function cacheAdapterStreamGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getPrefix() - default');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['cacheDir' => outputDir()]);

        $expected = 'phstrm-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
