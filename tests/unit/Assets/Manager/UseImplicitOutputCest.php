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

use function sprintf;

use const PHP_EOL;

class UseImplicitOutputCest
{
    /**
     * Tests Phalcon\Assets\Manager :: useImplicitOutput()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsManagerUseImplicitOutput(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - useImplicitOutput()');

        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->collection('footer')
                ->addCss('/css/style1.css')
        ;

        $footer = $manager->collection('footer');

        $footer->addCss('/css/style2.css');

        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<link rel="stylesheet" type="text/css" href="/css/style1.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style2.css" />'
        );

        $manager->useImplicitOutput(false);

        $I->assertEquals($expected, $manager->outputCss('footer'));
    }

    /**
     * Tests Phalcon\Assets\Manager :: useImplicitOutput() - remote
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsManagerUseImplicitOutputRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - useImplicitOutput() - remote');

        $manager = new Manager(new TagFactory(new Escaper()));
        $manager
            ->collection('header')
            ->setPrefix('http:://cdn.example.com/')
            ->setIsLocal(false)
            ->addJs('js/script1.js')
            ->addJs('js/script2.js')
        ;

        $manager->useImplicitOutput(false);

        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<script type="application/javascript" src="http:://cdn.example.com/js/script1.js"></script>',
            '<script type="application/javascript" src="http:://cdn.example.com/js/script2.js"></script>'
        );

        $I->assertEquals($expected, $manager->outputJs('header'));
    }
}
