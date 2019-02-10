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

namespace Phalcon\Test\Unit\Version;

use UnitTester;

/**
 * Class GetPartCest
 */
class GetPartCest
{
    /**
     * Tests Phalcon\Version :: getPart()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function versionGetPart(UnitTester $I)
    {
        $I->wantToTest('Version - getPart()');
        $I->skipTest('Need implementation');
    }
}
