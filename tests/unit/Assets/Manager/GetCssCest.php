<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use UnitTester;

class GetCssCest
{
    /**
     * Tests Phalcon\Assets\Manager :: getCss()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function assetsManagerGetCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - getCss()');

        $assets = new Manager();

        $assets->addCss('/css/style2.css');
        $assets->addCss('/css/style1.css');

        $collection = $assets->getCss();

        $I->assertCount(2, $collection);
    }
}
