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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function outputDir;

class GetPrefixCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getPrefix()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getPrefix()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
                'prefix'     => 'my-prefix',
            ]
        );

        $I->assertEquals(
            'my-prefix',
            $adapter->getPrefix()
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getPrefix() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getPrefix() - default');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $I->assertEquals(
            'phstrm-',
            $adapter->getPrefix()
        );
    }
}
