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

namespace Phalcon\Test\Unit\Storage\Serializer\AbstractSerializer;

use UnitTester;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\AbstractSerializer :: getData()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function storageSerializerAbstractSerializerGetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\AbstractSerializer - getData()');

        $I->skipTest('Need implementation');
    }
}
