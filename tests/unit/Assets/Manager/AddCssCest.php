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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use UnitTester;

class AddCssCest
{
    /**
     * Tests Phalcon\Assets\Manager :: addCss()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function assetsManagerAddCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addCss()');

        $assets = new Manager();

        $assets->addCss('/css/style1.css');
        $assets->addCss('/css/style2.css');

        $collection = $assets->get('css');

        foreach ($collection as $resource) {
            $I->assertEquals(
                'css',
                $resource->getType()
            );
        }

        $I->assertCount(2, $collection);
    }

    /**
     * Tests Phalcon\Assets\Manager :: addCss() - duplicate
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10938
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-02
     */
    public function assetsManagerAddCssDuplicate(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - addCss() - duplicate');

        $assets = new Manager();

        for ($i = 0; $i < 10; $i++) {
            $assets
                ->addCss('css/style.css')
                ->addJs('script.js')
            ;
        }

        $I->assertCount(
            1,
            $assets->getCss()
        );

        $I->assertCount(
            1,
            $assets->getJs()
        );

        for ($i = 0; $i < 2; $i++) {
            $assets
                ->addCss('style_' . $i . '.css')
                ->addJs('script_' . $i . '.js')
            ;
        }

        $I->assertCount(
            3,
            $assets->getCss()
        );

        $I->assertCount(
            3,
            $assets->getJs()
        );
    }
}
