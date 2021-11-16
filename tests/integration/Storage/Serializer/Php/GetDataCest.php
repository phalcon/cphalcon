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

namespace Phalcon\Tests\Integration\Storage\Serializer\Php;

use IntegrationTester;
use Phalcon\Storage\Serializer\Php;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Php :: getData()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerPhpGetData(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - getData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Php($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
