<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Storage\Serializer\Php;

use Phalcon\Storage\Serializer\Php;
use UnitTester;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Php :: getData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-12
     */
    public function storageSerializerPhpGetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - getData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Php($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
