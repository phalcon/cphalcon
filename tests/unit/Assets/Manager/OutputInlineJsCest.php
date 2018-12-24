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

namespace Phalcon\Test\Unit\Assets\Manager;

use UnitTester;

/**
 * Class OutputInlineJsCest
 */
class OutputInlineJsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: outputInlineJs()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsManagerOutputInlineJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputInlineJs()');
        $I->skipTest('Need implementation');
    }
}
