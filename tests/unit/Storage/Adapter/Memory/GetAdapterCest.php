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

namespace Phalcon\Test\Unit\Storage\Adapter\Memory;

use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

/**
 * Class GetAdapterCest
 */
class GetAdapterCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: getAdapter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-14
     */
    public function storageAdapterMemoryGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - getAdapter()');
        $factory = new SerializerFactory();
        $adapter = new Memory($factory);

        $actual = $adapter->getAdapter();
        $I->assertNull($actual);
    }
}
