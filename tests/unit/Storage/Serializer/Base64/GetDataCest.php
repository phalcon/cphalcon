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

namespace Phalcon\Test\Unit\Storage\Serializer\Base64;

use Phalcon\Storage\Serializer\Base64;
use UnitTester;

/**
 * Class GetDataCest
 */
class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: getData()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerBase64GetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - getData()');
        $data       = ["Phalcon Framework"];
        $serializer = new Base64($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
