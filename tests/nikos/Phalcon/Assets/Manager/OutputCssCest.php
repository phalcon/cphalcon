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
 * Class OutputCssCest
 */
class OutputCssCest
{
    /**
     * Tests Phalcon\Assets\Manager :: outputCss()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsManagerOutputCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputCss()');
        $I->skipTest('Need implementation');
    }
}
