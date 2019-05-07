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

use UnitTester;

class SetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Base64 :: setData()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function storageSerializerBase64SetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Base64 - setData()');

        $I->skipTest('Need implementation');
    }
}
