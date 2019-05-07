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

namespace Phalcon\Test\Unit\Storage\Adapter\Apcu;

use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

class GetPrefixCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: getPrefix()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterApcuGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - getPrefix()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer, ['prefix' => 'my-prefix']);

        $expected = 'my-prefix';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: getPrefix() - default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterApcuGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - getPrefix() - default');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $expected = 'ph-apcu-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
