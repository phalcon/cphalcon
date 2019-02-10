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

namespace Phalcon\Test\Unit\Config\Adapter\Ini;

use UnitTester;

/**
 * Class OffsetExistsCest
 */
class OffsetExistsCest
{
    /**
     * Tests Phalcon\Config\Adapter\Ini :: offsetExists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function configAdapterIniOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - offsetExists()');
        $I->skipTest('Need implementation');
    }
}
