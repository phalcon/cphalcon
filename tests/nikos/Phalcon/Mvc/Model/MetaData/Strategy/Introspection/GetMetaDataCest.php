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

namespace Phalcon\Test\Unit\Mvc\Model\MetaData\Strategy\Introspection;

use UnitTester;

/**
 * Class GetMetaDataCest
 */
class GetMetaDataCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Strategy\Introspection :: getMetaData()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelMetaDataStrategyIntrospectionGetMetaData(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Strategy\Introspection - getMetaData()');
        $I->skipTest('Need implementation');
    }
}
