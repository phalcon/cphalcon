<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\MetaData\Redis;

use UnitTester;

class GetBindTypesCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Redis :: getBindTypes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataRedisGetBindTypes(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\MetaData\Redis - getBindTypes()");
        $I->skipTest("Need implementation");
    }
}
