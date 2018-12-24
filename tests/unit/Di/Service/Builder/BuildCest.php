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

namespace Phalcon\Test\Unit\Di\Service\Builder;

use UnitTester;

/**
 * Class BuildCest
 */
class BuildCest
{
    /**
     * Tests Phalcon\Di\Service\Builder :: build()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diServiceBuilderBuild(UnitTester $I)
    {
        $I->wantToTest('Di\Service\Builder - build()');
        $I->skipTest('Need implementation');
    }
}
