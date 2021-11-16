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
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
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

        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('/css/style1.css');
        $manager->addCss('/css/style2.css');

        $collection = $manager->get('css');

        foreach ($collection as $resource) {
            $I->assertEquals('css', $resource->getType());
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

        $manager = new Manager(new TagFactory(new Escaper()));

        for ($i = 0; $i < 10; $i++) {
            $manager
                ->addCss('css/style.css')
                ->addJs('script.js')
            ;
        }

        $I->assertCount(1, $manager->getCss());
        $I->assertCount(1, $manager->getJs());

        for ($i = 0; $i < 2; $i++) {
            $manager
                ->addCss('style_' . $i . '.css')
                ->addJs('script_' . $i . '.js')
            ;
        }

        $I->assertCount(3, $manager->getCss());
        $I->assertCount(3, $manager->getJs());
    }
}
