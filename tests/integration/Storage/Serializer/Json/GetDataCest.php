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

namespace Phalcon\Test\Integration\Storage\Serializer\Json;

use Phalcon\Storage\Serializer\Json;
use IntegrationTester;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Json :: getData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerJsonGetData(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Json - getData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Json($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
