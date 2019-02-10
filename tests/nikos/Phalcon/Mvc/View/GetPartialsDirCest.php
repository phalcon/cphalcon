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

namespace Phalcon\Test\Unit\Mvc\View;

use UnitTester;

/**
 * Class GetPartialsDirCest
 */
class GetPartialsDirCest
{
    /**
     * Tests Phalcon\Mvc\View :: getPartialsDir()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcViewGetPartialsDir(UnitTester $I)
    {
        $I->wantToTest('Mvc\View - getPartialsDir()');
        $I->skipTest('Need implementation');
    }
}
