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

namespace Phalcon\Test\Integration\Storage\Serializer\Php;

use Phalcon\Storage\Serializer\Php;
use IntegrationTester;

class SetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Php :: setData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-12
     */
    public function storageSerializerPhpSetData(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - setData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Php();

        $actual = $serializer->getData();
        $I->assertNull($actual);

        $serializer->setData($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
