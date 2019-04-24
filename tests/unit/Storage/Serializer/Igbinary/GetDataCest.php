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

namespace Phalcon\Test\Unit\Storage\Serializer\Igbinary;

use Phalcon\Storage\Serializer\Igbinary;
use UnitTester;

/**
 * Class GetDataCest
 */
class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: getData()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerIgbinaryGetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - getData()');
        $data       = ["Phalcon Framework"];
        $serializer = new Igbinary($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
