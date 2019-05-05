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

namespace Phalcon\Test\Unit\Cache\Frontend\Base64;

use UnitTester;

class BeforeStoreCest
{
    /**
     * Tests Phalcon\Cache\Frontend\Base64 :: beforeStore()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheFrontendBase64BeforeStore(UnitTester $I)
    {
        $I->wantToTest('Cache\Frontend\Base64 - beforeStore()');

        $I->skipTest('Need implementation');
    }
}
