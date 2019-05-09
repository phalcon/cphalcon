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

namespace Phalcon\Test\Unit\Storage\Adapter\Apcu;

use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

/**
 * Class GetAdapterCest
 */
class GetAdapterCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: getAdapter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-14
     */
    public function storageAdapterApcuGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - getAdapter()');
        $adapter = new Apcu();

        $actual = $adapter->getAdapter();
        $I->assertNull($actual);
    }
}
