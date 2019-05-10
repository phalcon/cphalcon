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

namespace Phalcon\Test\Unit\Storage\Adapter\Memory;

use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class GetPrefixCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: getPrefix()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterMemoryGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - getPrefix()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer, ['prefix' => 'my-prefix']);

        $expected = 'my-prefix';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Memory :: getPrefix() - default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterMemoryGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - getPrefix() - default');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $expected = 'ph-memo-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
