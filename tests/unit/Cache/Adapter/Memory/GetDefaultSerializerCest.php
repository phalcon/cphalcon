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

namespace Phalcon\Test\Unit\Cache\Adapter\Memory;

use UnitTester;

class GetDefaultSerializerCest
{
    /**
     * Unit Tests Phalcon\Cache\Adapter\Memory :: getDefaultSerializer()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function cacheAdapterMemoryGetDefaultSerializer(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - getDefaultSerializer()');

        $I->skipTest('Need implementation');
    }
}
