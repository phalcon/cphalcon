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

namespace Phalcon\Test\Integration\Storage\Serializer\None;

use Phalcon\Storage\Serializer\None;
use UnitTester;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\None :: getData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerNoneGetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\None - getData()');
        $data       = ['Phalcon Framework'];
        $serializer = new None($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
