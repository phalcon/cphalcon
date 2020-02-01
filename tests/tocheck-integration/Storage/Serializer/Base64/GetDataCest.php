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

namespace Phalcon\Test\Integration\Storage\Serializer\Base64;

use Phalcon\Storage\Serializer\Base64;
use UnitTester;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: getData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerBase64GetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - getData()');

        $data       = ['Phalcon Framework'];
        $serializer = new Base64($data);

        $I->assertEquals(
            $data,
            $serializer->getData()
        );
    }
}
