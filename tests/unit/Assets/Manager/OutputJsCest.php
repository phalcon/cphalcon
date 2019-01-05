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

use Phalcon\Assets\Asset\Js;
use Phalcon\Assets\Manager;
use UnitTester;

/**
 * Class OutputJsCest
 */
class OutputJsCest
{
    /**
     * Tests Phalcon\Assets\Manager :: outputJs() - implicit
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputJs() - implicit');
        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');
        $assets->addAsset(new Js('/js/script3.js', false));

        $expected = '<script src="/js/script1.js"></script>' . PHP_EOL
            . '<script src="/js/script2.js"></script>' . PHP_EOL
            . '<script src="/js/script3.js"></script>' . PHP_EOL;

        $assets->useImplicitOutput(false);
        $actual = $assets->outputJs();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputJs() - not implicit
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-13
     */
    public function assetsManagerOutputJsNotImplicit(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - outputJs() - not implicit');
        $assets = new Manager();

        $assets->addJs('js/script1.js');
        $assets->addJs('js/script2.js');
        $assets->addAsset(new Js('/js/script3.js', false));

        $expected = '<script src="/js/script1.js"></script>' . PHP_EOL
            . '<script src="/js/script2.js"></script>' . PHP_EOL
            . '<script src="/js/script3.js"></script>' . PHP_EOL;

        ob_start();
        $assets->outputJs();
        $actual = ob_get_clean();
        $I->assertEquals($expected, $actual);
    }
}
