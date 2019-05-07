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

use UnitTester;

class GetPrefixCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: getPrefix()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function storageAdapterApcuGetPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - getPrefix()');

        $I->skipTest('Need implementation');
    }
}
