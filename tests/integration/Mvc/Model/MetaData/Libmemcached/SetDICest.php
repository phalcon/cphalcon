<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Libmemcached;

use IntegrationTester;

class SetDICest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Libmemcached :: setDI()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataLibmemcachedSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\MetaData\Libmemcached - setDI()");
        $I->skipTest("Need implementation");
    }
}
