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

namespace Phalcon\Test\Unit\Cache\Adapter\Apcu;

use UnitTester;

class GetDefaultSerializerCest
{
    /**
     * Unit Tests Phalcon\Cache\Adapter\Apcu :: getDefaultSerializer()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function cacheAdapterApcuGetDefaultSerializer(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - getDefaultSerializer()');

        $I->skipTest('Need implementation');
    }
}
