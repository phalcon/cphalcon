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

namespace Phalcon\Test\Integration\Storage\Serializer\Igbinary;

use Phalcon\Storage\Serializer\Igbinary;
use IntegrationTester;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: getData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerIgbinaryGetData(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - getData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Igbinary($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
