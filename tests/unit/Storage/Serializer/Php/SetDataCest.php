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

namespace Phalcon\Test\Unit\Storage\Serializer\Php;

use Phalcon\Storage\Serializer\Php;
use UnitTester;

class SetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Php :: setData()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-12
     */
    public function storageSerializerPhpSetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - setData()');
        $data       = ["Phalcon Framework"];
        $serializer = new Php();

        $actual = $serializer->getData();
        $I->assertNull($actual);

        $serializer->setData($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
