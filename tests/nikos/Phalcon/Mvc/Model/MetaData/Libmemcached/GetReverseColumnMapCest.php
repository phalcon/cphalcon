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

namespace Phalcon\Test\Unit\Mvc\Model\MetaData\Libmemcached;

use UnitTester;

/**
 * Class GetReverseColumnMapCest
 */
class GetReverseColumnMapCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Libmemcached :: getReverseColumnMap()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelMetaDataLibmemcachedGetReverseColumnMap(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Libmemcached - getReverseColumnMap()');
        $I->skipTest('Need implementation');
    }
}
