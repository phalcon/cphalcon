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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use UnitTester;

class GetAdapterCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getAdapter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function storageAdapterStreamGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getAdapter()');

        $I->skipTest('Need implementation');
    }
}
